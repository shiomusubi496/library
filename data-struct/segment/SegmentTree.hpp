#pragma once

#include "../../other/template.hpp"
#include "../../other/bitop.hpp"
#include "../../other/monoid.hpp"

template<class M> class SegmentTree {
private:
    using T = typename M::value_type;
    int n, ori;
    std::vector<T> data;

public:
    SegmentTree() : SegmentTree(0) {}
    SegmentTree(int n) : SegmentTree(std::vector<T>(n, M::id())) {}
    SegmentTree(int n, const T& v) : SegmentTree(std::vector<T>(n, v)) {}
    SegmentTree(const std::vector<T>& v) { init(v); }
    void init(const std::vector<T>& v) {
        ori = v.size();
        n = 1 << bitop::ceil_log2(ori);
        data.assign(n << 1, M::id());
        rep (i, ori) data[n + i] = v[i];
        rrep (i, n, 1) data[i] = M::op(data[i << 1], data[i << 1 ^ 1]);
    }
    template<class Upd> void update(int k, const Upd& upd) {
        assert(0 <= k && k < ori);
        k += n;
        data[k] = upd(data[k]);
        while (k >>= 1) data[k] = M::op(data[k << 1], data[k << 1 ^ 1]);
    }
    void set(int k, T x) {
        update(k, [&](T) -> T { return x; });
    }
    void apply(int k, T x) {
        update(k, [&](T a) -> T { return M::op(a, x); });
    }
    T prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= ori);
        l += n;
        r += n;
        T lsm = M::id(), rsm = M::id();
        while (l < r) {
            if (l & 1) lsm = M::op(lsm, data[l++]);
            if (r & 1) rsm = M::op(data[--r], rsm);
            l >>= 1;
            r >>= 1;
        }
        return M::op(lsm, rsm);
    }
    T all_prod() const { return data[1]; }
    T get(int k) const { return data[k + n]; }
    template<class Cond> int max_right(int l, const Cond& cond) const {
        assert(0 <= l && l <= ori);
        assert(cond(M::id()));
        if (l == ori) return ori;
        l += n;
        T sm = M::id();
        do {
            while ((l & 1) == 0) l >>= 1;
            if (!cond(M::op(sm, data[l]))) {
                while (l < n) {
                    l <<= 1;
                    if (cond(M::op(sm, data[l]))) sm = M::op(sm, data[l++]);
                }
                return l - n;
            }
            sm = M::op(sm, data[l++]);
        } while ((l & -l) != l);
        return ori;
    }
    template<class Cond> int min_left(int r, const Cond& cond) const {
        assert(0 <= r && r <= ori);
        assert(cond(M::id()));
        if (r == 0) return 0;
        r += n;
        T sm = M::id();
        do {
            --r;
            while ((r & 1) && r > 1) r >>= 1;
            if (!cond(M::op(data[r], sm))) {
                while (r < n) {
                    r = r << 1 ^ 1;
                    if (cond(M::op(data[r], sm))) sm = M::op(data[r--], sm);
                }
                return r + 1 - n;
            }
            sm = M::op(data[r], sm);
        } while ((r & -r) != r);
        return 0;
    }
};

// verified with test/aoj/DSL/DSL_2_A-RMQ.test.cpp
template<class T, T max_value = infinity<T>::max>
using RangeMinimumQuery = SegmentTree<Monoid::Min<T, max_value>>;

template<class T, T min_value = infinity<T>::min>
using RangeMaximumQuery = SegmentTree<Monoid::Max<T, min_value>>;

// verified with test/aoj/DSL/DSL_2_B-RSQ.test.cpp
template<class T> using RangeSumQuery = SegmentTree<Monoid::Sum<T>>;

/**
 * @brief SegmentTree(セグメント木)
 * @docs docs/SegmentTree.md
 */
