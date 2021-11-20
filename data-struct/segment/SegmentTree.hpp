#pragma once

#include "../../other/template.hpp"
#include "../../other/bitop.hpp"

template<class T> class SegmentTree {
  protected:
    using F = std::function<T(T, T)>;
    using G = std::function<T()>;
    F op;
    G e;
    int n;
    std::vector<T> data;
  public:
    SegmentTree() = default;
    SegmentTree(const F& op, const G& e) : SegmentTree(0, op, e) {}
    SegmentTree(int n, const F& op, const G& e) : SegmentTree(std::vector<T>(n, e()), op, e) {}
    SegmentTree(const std::vector<T>& v, const F& op, const G& e) : op(op), e(e) { init(v); }
    void init(const std::vector<T>& v) {
        n = 1 << bitop::ceil_log2(v.size());
        data.assign(n << 1, e());
        rep (i, v.size()) data[n + i] = v[i];
        rrep (i, n, 1) data[i] = op(data[i << 1], data[i << 1 ^ 1]);
    }
    template<class U> void update(int k, const U& upd) {
        assert(0 <= k && k < n);
        k += n;
        data[k] = upd(data[k]);
        while (k >>= 1) data[k] = op(data[k << 1], data[k << 1 ^ 1]);
    }
    void set(int k, T x) {
        update(k, [&](T a) -> T { return x; });
    }
    void apply(int k, T x) {
        update(k, [&](T a) -> T { return op(a, x); });
    }
    T prod(int l, int r) {
        assert(0 <= l && l <= r && r <= n);
        l += n; r += n;
        T lsm = e(), rsm = e();
        while (l < r) {
            if (l & 1) lsm = op(lsm, data[l++]);
            if (r & 1) rsm = op(rsm, data[--r]);
            l >>= 1; r >>= 1;
        }
        return op(lsm, rsm);
    }
    T get(int k) { return data[k + n]; }
    template<class C> int max_right(int l, const C& cond) {
        assert(0 <= l && l <= n);
        assert(cond(e()));
        if (l == n) return n;
        l += n;
        T sm = e();
        do {
            while ((l & 1) != 0) l >>= 1;
            if (!cond(op(sm, data[l]))) {
                while (l < n) {
                    l <<= 1;
                    if (cond(op(sm, data[l]))) sm = op(sm, data[l++]);
                }
                return l - n;
            }
            sm = op(sm, data[l++]);
        } while ((l & -l) != l);
        return n;
    }
    template<class C> int min_left(int r, const C& cond) {
        assert(0 <= r && r <= n);
        assert(cond(e()));
        if (r == 0) return 0;
        r += n;
        T sm = e();
        do {
            while ((r & 1) != 0 && r > 1) r >>= 1;
            if (!cond(op(data[r - 1], sm))) {
                while (r < n) {
                    r <<= 1;
                    if (cond(op(data[r - 1], sm))) sm = op(data[--r], sm);
                }
                return r - n;
            }
            sm = op(data[--r], sm);
        } while ((r & -r) != r);
        return 0;
    }
};

/**
 * @brief
 * @docs docs/SegmentTree.md
 */
