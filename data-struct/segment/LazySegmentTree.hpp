#pragma once

#include "../../other/template.hpp"
#include "../../other/bitop.hpp"

template<class T, class U> class LazySegmentTree {
  protected:
    using F = std::function<T(T, T)>;
    using G = std::function<T(U, T)>;
    using H = std::function<U(U, U)>;
    F op;
    T e;
    G mapping;
    H composition;
    U id;
    int h, n, ori;
    std::vector<T> data;
    std::vector<U> lazy;
    void all_apply(int k, const U& x) {
        data[k] = mapping(x, data[k]);
        if (k < n) lazy[k] = composition(x, lazy[k]);
    }
    void eval(int k) {
        all_apply(k << 1, lazy[k]);
        all_apply(k << 1 ^ 1, lazy[k]);
        lazy[k] = id;
    }
    void dataup(int k) {
        data[k] = op(data[k << 1], data[k << 1 ^ 1]);
    }
  public:
    LazySegmentTree() = default;
    LazySegmentTree(const F& op, const T& e, const G& mapping, const H& composition, const U& id)
        : LazySegmentTree(0, op, e, mapping, composition, id) {}
    LazySegmentTree(int n_, const F& op, const T& e, const G& mapping, const H& composition, const U& id)
        : LazySegmentTree(std::vector<T>(n_, e), op, e, mapping, composition, id) {}
    LazySegmentTree(const std::vector<T>& v, const F& op, const T& e, const G& mapping, const H& composition, const U& id)
        : op(op), e(e), mapping(mapping), composition(composition), id(id) { init(v); }
    void init(const std::vector<T>& v) {
        ori = v.size();
        h = bitop::ceil_log2(ori);
        n = 1 << h;
        data.assign(n << 1, e);
        rep (i, ori) data[n + i] = v[i];
        rrep (i, n, 1) dataup(i);
        lazy.assign(n << 1, id);
    }
    T prod(int l, int r) {
        assert(0 <= l && l <= r && r <= ori);
        if (l == r) return e;

        l += n; r += n;
        rreps (i, h) {
            bool seen = false;
            if (((l >> i) << i) != l) eval(l >> i), seen = true;
            if (((r >> i) << i) != r) eval((r - 1) >> i), seen = true;
            if (!seen) break;
        }

        T lsm = e, rsm = e;
        while (l != r) {
            if (l & 1) lsm = op(lsm, data[l++]);
            if (r & 1) rsm = op(data[--r], rsm);
            l >>= 1; r >>= 1;
        }
        return op(lsm, rsm);
    }
    T get(int k) {
        assert(0 <= k && k < ori);
        
        k += n;
        rreps (i, h) eval(k >> i);
        return data[k];
    }
    T all_prod() { return data[1]; }
    template<class Upd> void update(int k, const Upd& upd) {
        assert(0 <= k && k < ori);

        k += n;
        rreps (i, h) eval(k >> i);
        data[k] = upd(data[k]);
        reps (i, h) dataup(k >> i);
    }
    void set(int k, T x) {
        update(k, [&](T a) -> T { return x; });
    }
    void apply(int k, U x) {
        update(k, [&](T a) -> T { return mapping(x, a); });
    }
    void apply(int l, int r, U x) {
        assert(0 <= l && l <= r && r <= ori);
        if (l == r) return;

        l += n; r += n;
        int lst = h + 1;
        rreps (i, h) {
            if (((l >> i) << i) != l) eval(l >> i), lst = i;
            if (((r >> i) << i) != r) eval((r - 1) >> i), lst = i;
            if (lst != i) break;
        }

        for (int l2 = l, r2 = r; l2 != r2; l2 >>= 1, r2 >>= 1) {
            if (l2 & 1) all_apply(l2++, x);
            if (r2 & 1) all_apply(--r2, x);
        }
        
        rep (i, lst, h + 1) {
            if (((l >> i) << i) != l) dataup(l >> i);
            if (((r >> i) << i) != r) dataup((r - 1) >> i);
        }
    }
    template<class C> int max_right(int l, const C& cond) {
        assert(0 <= l && l <= ori);
        assert(cond(e));
        if (l == ori) return ori;

        l += n;
        rreps (i, h) {
            if (((l >> i) << i) != l) eval(l >> i);
            else break;
        }

        T sm = e;
        do {
            while ((l & 1) == 0) l >>= 1;
            if (!cond(op(sm, data[l]))) {
                while (l < n) {
                    eval(l);
                    l <<= 1;
                    if (cond(op(sm, data[l]))) sm = op(sm, data[l++]);
                }
                return l - n;
            }
            sm = op(sm, data[l++]);
        } while ((l & -l) != l);
        return ori;
    }
    template<class C> int min_left(int r, const C& cond) {
        assert(0 <= r && r <= ori);
        assert(cond(e));
        if (r == 0) return 0;

        r += n;
        rreps (i, n) {
            if (((r >> i) << i) != r) eval((r - 1) >> i);
            else break;
        }

        T sm = e;
        do {
            --r;
            while ((r & 1) && r > 1) r >>= 1;
            if (!cond(op(data[r], sm))) {
                while (r < n) {
                    eval(r);
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

template<class T, class U> class MultiLazySegmentTree {
  protected:
    struct E {
        T val;
        int len;
        E() = default;
        E(T v, int l) : val(v), len(l) {}
        friend std::ostream& operator<<(std::ostream& ost, const E& e) { return ost << e.val << '*' << e.len; }
    };
    using F = std::function<T(T, T)>;
    using G = std::function<T(U, T)>;
    using H = std::function<U(U, U)>;
    using I = std::function<U(U, int)>;
    LazySegmentTree<E, U> seg;
    std::vector<E> Tvec_to_Evec(const std::vector<T>& v) {
        std::vector<E> res(v.size());
        rep (i, v.size()) res[i] = E{v[i], 1};
        return res;
    }
  public:
    MultiLazySegmentTree() = default;
    MultiLazySegmentTree(const F& op, const T& e, const G& mapping, const H& composition, const U& id, const I& mul)
        : seg(
            [&](E a, E b) -> E { return E{op(a.val, b.val), a.len + b.len}; }, E{e, 0},
            [&](U a, E b) -> E { return E{mapping(mul(a, b.len), b.val), b.len}; }, composition, id
        ) {}
    MultiLazySegmentTree(int n_, const F& op, const T& e, const G& mapping, const H& composition, const U& id, const I& mul)
        : seg(
            std::vector<E>(n_, E{e, 1}), [&](E a, E b) -> E { return E{op(a.val, b.val), a.len + b.len}; }, E{e, 0},
            [&](U a, E b) -> E { return E{mapping(mul(a, b.len), b.val), b.len}; }, composition, id
        ) {}
    MultiLazySegmentTree(const std::vector<T>& v, const F& op, const T& e, const G& mapping, const H& composition, const U& id, const I& mul)
        : seg(
            Tvec_to_Evec(v), [&](E a, E b) -> E { return E{op(a.val, b.val), a.len + b.len}; }, E{e, 0},
            [&](U a, E b) -> E { return E{mapping(mul(a, b.len), b.val), b.len}; }, composition, id
        ) {}
    void init(const std::vector<T>& v) { seg.init(v); }
    T prod(int l, int r) { return seg.prod(l, r).val; }
    T get(int k) { return seg.get(k).val; }
    T all_prod() { return seg.all_prod().val; }
    template<class Upd> void update(int k, const Upd& upd) { seg.update(k, [&](E a) -> E { return E{upd(a.val), a.len}; }); }
    void set(int k, T x) { seg.set(k, E{x, 1}); }
    void apply(int k, U x) { seg.apply(k, x); }
    void apply(int l, int r, U x) { seg.apply(l, r, x); }
    template<class C> int max_right(int l, const C& cond) { return seg.max_right(l, cond); }
    template<class C> int min_left(int r, const C& cond) { return seg.min_left(r, cond); }
};

/**
 * @brief LazySegmentTree(遅延セグメント木)
 */
