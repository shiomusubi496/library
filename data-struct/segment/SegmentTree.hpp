#pragma once

#include "../../other/template.hpp"
#include "../../other/bitop.hpp"

template<class T, class F = std::function<T(T, T)>> class SegmentTree {
  protected:
    F op;
    T e;
    int n, ori;
    std::vector<T> data;
  public:
    SegmentTree() = default;
    SegmentTree(const F& op, const T& e) : SegmentTree(0, op, e) {}
    SegmentTree(int n, const F& op, const T& e) : SegmentTree(std::vector<T>(n, e), op, e) {}
    SegmentTree(const std::vector<T>& v, const F& op, const T& e) : op(op), e(e) { init(v); }
    void init(const std::vector<T>& v) {
        ori = v.size();
        n = 1 << bitop::ceil_log2(ori);
        data.assign(n << 1, e);
        rep (i, ori) data[n + i] = v[i];
        rrep (i, n, 1) data[i] = op(data[i << 1], data[i << 1 ^ 1]);
    }
    template<class Upd> void update(int k, const Upd& upd) {
        assert(0 <= k && k < ori);
        k += n;
        data[k] = upd(data[k]);
        while (k >>= 1) data[k] = op(data[k << 1], data[k << 1 ^ 1]);
    }
    void set(int k, T x) {
        update(k, [&](T) -> T { return x; });
    }
    void apply(int k, T x) {
        update(k, [&](T a) -> T { return op(a, x); });
    }
    T prod(int l, int r) {
        assert(0 <= l && l <= r && r <= ori);
        l += n; r += n;
        T lsm = e, rsm = e;
        while (l < r) {
            if (l & 1) lsm = op(lsm, data[l++]);
            if (r & 1) rsm = op(data[--r], rsm);
            l >>= 1; r >>= 1;
        }
        return op(lsm, rsm);
    }
    T all_prod() { return data[1]; }
    T get(int k) { return data[k + n]; }
    template<class Cond> int max_right(int l, const Cond& cond) {
        assert(0 <= l && l <= ori);
        assert(cond(e));
        if (l == ori) return ori;
        l += n;
        T sm = e;
        do {
            while ((l & 1) == 0) l >>= 1;
            if (!cond(op(sm, data[l]))) {
                while (l < n) {
                    l <<= 1;
                    if (cond(op(sm, data[l]))) sm = op(sm, data[l++]);
                }
                return l - n;
            }
            sm = op(sm, data[l++]);
        } while ((l & -l) != l);
        return ori;
    }
    template<class Cond> int min_left(int r, const Cond& cond) {
        assert(0 <= r && r <= ori);
        assert(cond(e));
        if (r == 0) return 0;
        r += n;
        T sm = e;
        do {
            --r;
            while ((r & 1) && r > 1) r >>= 1;
            if (!cond(op(data[r], sm))) {
                while (r < n) {
                    r = r << 1 ^ 1;
                    if (cond(op(data[r], sm))) sm = op(data[r--], sm);
                }
                return r + 1 - n;
            }
            sm = op(data[r], sm);
        } while ((r & -r) != r);
        return 0;
    }
};

// verified with test/aoj/DSL/DSL_2_A-RMQ.test.cpp
template<class T, T max_value = infinity<T>::max> class RangeMinimumQuery : public SegmentTree<T> {
  protected:
    using Base = SegmentTree<T>;
  public:
    template<class... Args> RangeMinimumQuery(Args&&... args)
        : Base(
            std::forward<Args>(args)...,
            [](T a, T b) -> T { return std::min(a, b); },
            max_value
        ) {}
};

template<class T, T min_value = infinity<T>::min> class RangeMaximumQuery : public SegmentTree<T> {
  protected:
    using Base = SegmentTree<T>;
  public:
    template<class... Args> RangeMaximumQuery(Args&&... args)
        : Base(
            std::forward<Args>(args)...,
            [](T a, T b) -> T { return std::max(a, b); },
            min_value
        ) {}
};

// verified with test/aoj/DSL/DSL_2_B-RSQ.test.cpp
template<class T> class RangeSumQuery : public SegmentTree<T> {
  protected:
    using Base = SegmentTree<T>;
  public:
    template<class... Args> RangeSumQuery(Args&&... args)
        : Base(
            std::forward<Args>(args)...,
            [](T a, T b) -> T { return a + b; },
            T(0)
        ) {}
};

/**
 * @brief SegmentTree(セグメント木)
 * @docs docs/SegmentTree.md
 */
