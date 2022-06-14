#pragma once

#include "../../other/template.hpp"
#include "../../other/bitop.hpp"
#include "../../other/monoid.hpp"

template<class A> class LazySegmentTree {
  protected:
    using M = typename A::M;
    using E = typename A::E;
    using T = typename M::value_type;
    using U = typename E::value_type;
    int h, n, ori;
    std::vector<T> data;
    std::vector<U> lazy;
    std::vector<bool> lazyflag;
    void all_apply(int k, const U& x) {
        data[k] = A::op(x, data[k]);
        if (k < n) {
            if (lazyflag[k]) {
                lazy[k] = E::op(lazy[k], x);
            }
            else {
                lazy[k] = x;
                lazyflag[k] = true;
            }
        }
    }
    void eval(int k) {
        if (lazyflag[k]) {
            all_apply(k << 1, lazy[k]);
            all_apply(k << 1 ^ 1, lazy[k]);
            lazyflag[k] = false;
        }
    }
    void calc(int k) {
        data[k] = M::op(data[k << 1], data[k << 1 ^ 1]);
    }
  public:
    LazySegmentTree() : LazySegmentTree(0) {}
    LazySegmentTree(int n) : LazySegmentTree(std::vector<T>(n, M::id())) {}
    LazySegmentTree(int n, const T& v) : LazySegmentTree(std::vector<T>(n, v)) {}
    LazySegmentTree(const std::vector<T>& v) { init(v); }
    void init(const std::vector<T>& v) {
        ori = v.size();
        h = bitop::ceil_log2(ori);
        n = 1 << h;
        data.assign(n << 1, M::id());
        rep (i, ori) data[n + i] = v[i];
        rrep (i, n, 1) calc(i);
        lazy.resize(n); lazyflag.assign(n, false);
    }
    T prod(int l, int r) {
        assert(0 <= l && l <= r && r <= ori);
        if (l == r) return M::id();

        l += n; r += n;
        rreps (i, h) {
            bool seen = false;
            if (((l >> i) << i) != l) eval(l >> i), seen = true;
            if (((r >> i) << i) != r) eval((r - 1) >> i), seen = true;
            if (!seen) break;
        }

        T lsm = M::id(), rsm = M::id();
        while (l != r) {
            if (l & 1) lsm = M::op(lsm, data[l++]);
            if (r & 1) rsm = M::op(data[--r], rsm);
            l >>= 1; r >>= 1;
        }
        return M::op(lsm, rsm);
    }
    T get(int k) {
        assert(0 <= k && k < ori);
        
        k += n;
        rreps (i, h) eval(k >> i);
        return data[k];
    }
    T all_prod() const { return data[1]; }
    template<class Upd> void update(int k, const Upd& upd) {
        assert(0 <= k && k < ori);

        k += n;
        rreps (i, h) eval(k >> i);
        data[k] = upd(data[k]);
        reps (i, h) calc(k >> i);
    }
    void set(int k, T x) {
        update(k, [&](const T&) -> T { return x; });
    }
    void apply(int k, U x) {
        update(k, [&](const T& a) -> T { return A::op(x, a); });
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
            if (((l >> i) << i) != l) calc(l >> i);
            if (((r >> i) << i) != r) calc((r - 1) >> i);
        }
    }
    template<class C> int max_right(int l, const C& cond) {
        assert(0 <= l && l <= ori);
        assert(cond(M::id()));
        if (l == ori) return ori;

        l += n;
        rreps (i, h) {
            if (((l >> i) << i) != l) eval(l >> i);
            else break;
        }

        T sm = M::id();
        do {
            while ((l & 1) == 0) l >>= 1;
            if (!cond(M::op(sm, data[l]))) {
                while (l < n) {
                    eval(l);
                    l <<= 1;
                    if (cond(M::op(sm, data[l]))) sm = M::op(sm, data[l++]);
                }
                return l - n;
            }
            sm = M::op(sm, data[l++]);
        } while ((l & -l) != l);
        return ori;
    }
    template<class C> int min_left(int r, const C& cond) {
        assert(0 <= r && r <= ori);
        assert(cond(M::id()));
        if (r == 0) return 0;

        r += n;
        rreps (i, n) {
            if (((r >> i) << i) != r) eval((r - 1) >> i);
            else break;
        }

        T sm = M::id();
        do {
            --r;
            while ((r & 1) && r > 1) r >>= 1;
            if (!cond(M::op(data[r], sm))) {
                while (r < n) {
                    eval(r);
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

template<class A> class MultiLazySegmentTree {
  protected:
    using M_ = typename A::M;
    using E_ = typename A::E;
    using T_ = typename M_::value_type;
    using U_ = typename E_::value_type;
    struct MultiA {
        struct M {
            struct value_type {
                T_ val;
                int len;
                value_type() = default;
                value_type(T_ v, int l) : val(v), len(l) {}
                friend std::ostream& operator<<(std::ostream& ost, const value_type& e) { return ost << e.val << '*' << e.len; }
            };
            static value_type op(const value_type& a, const value_type& b) { return {M_::op(a.val, b.val), a.len + b.len}; }
            static value_type id() { return {M_::id(), 0}; }
        };
        using E = E_;
        using T = typename M::value_type;
        using U = typename E::value_type;
        template<bool AlwaysTrue = true, typename std::enable_if< Monoid::has_mul_op<A>::value && AlwaysTrue>::type* = nullptr>
        static T op(const U& a, const T& b) { return {A::mul_op(a, b.len, b.val), b.len}; }
        template<bool AlwaysTrue = true, typename std::enable_if<!Monoid::has_mul_op<A>::value && AlwaysTrue>::type* = nullptr>
        static T op(const U& a, const T& b) { return {A::op(A::mul(a, b.len), b.val), b.len}; }
    };
    using elm = typename MultiA::M::value_type;
    static std::vector<elm> get_elm_vec(const std::vector<T_>& v) {
        const int n = v.size();
        std::vector<elm> res(n);
        rep (i, n) res[i] = elm{v[i], 1};
        return res;
    }
    LazySegmentTree<MultiA> seg;
  public:
    MultiLazySegmentTree() : MultiLazySegmentTree(0) {}
    MultiLazySegmentTree(int n_) : seg(n_, {M_::id(), 1}) {}
    MultiLazySegmentTree(const std::vector<T_>& v) : seg(get_elm_vec(v)) {}
    void init(const std::vector<T_>& v) { seg.init(get_elm_vec(v)); }
    T_ prod(int l, int r) { return seg.prod(l, r).val; }
    T_ get(int k) { return seg.get(k).val; }
    T_ all_prod() const { return seg.all_prod().val; }
    template<class Upd> void update(int k, const Upd& upd) { seg.update(k, [&](const elm& a) -> elm { return {upd(a.val), a.len}; }); }
    void set(int k, T_ x) { seg.set(k, elm{x, 1}); }
    void apply(int k, U_ x) { seg.apply(k, x); }
    void apply(int l, int r, U_ x) { seg.apply(l, r, x); }
    template<class C> int max_right(int l, const C& cond) { return seg.max_right(l, [&](const elm& a) -> bool { return cond(a.val); }); }
    template<class C> int min_left(int r, const C& cond) { return seg.min_left(r, [&](const elm& a) -> bool { return cond(a.val); }); }
};

//verified with test/aoj/DSL/DSL_2_F-RUQRMQ.test.cpp
template<class T, T max_value = infinity<T>::max> using RangeUpdateQueryRangeMinimumQuery = LazySegmentTree<Monoid::AssignMin<T, max_value>>;

template<class T, T min_value = infinity<T>::min> using RangeUpdateQueryRangeMaximumQuery = LazySegmentTree<Monoid::AssignMax<T, min_value>>;

//verified with test/aoj/DSL/DSL_2_I-RUQRSQ.test.cpp
template<class T> using RangeUpdateQueryRangeSumQuery = MultiLazySegmentTree<Monoid::AssignSum<T>>;

//verified with test/aoj/DSL/DSL_2_H-RAQRMQ.test.cpp
template<class T, T max_value = infinity<T>::max> using RangeAddQueryRangeMinimumQuery = LazySegmentTree<Monoid::AddMin<T, max_value>>;

template<class T, T min_value = infinity<T>::min> using RangeAddQueryRangeMaximumQuery = LazySegmentTree<Monoid::AddMax<T, min_value>>;

//verified with test/aoj/DSL/DSL_2_G-RAQRSQ.test.cpp
template<class T> using RangeAddQueryRangeSumQuery = MultiLazySegmentTree<Monoid::AddSum<T>>;

template<class T, T max_value = infinity<T>::max> using RangeChminQueryRangeMinimumQuery = LazySegmentTree<Monoid::ChminMin<T, max_value>>;

template<class T, T min_value = infinity<T>::min> using RangeChminQueryRangeMaximumQuery = LazySegmentTree<Monoid::ChminMax<T, min_value>>;

template<class T, T max_value = infinity<T>::max> using RangeChmaxQueryRangeMinimumQuery = LazySegmentTree<Monoid::ChmaxMin<T, max_value>>;

template<class T, T min_value = infinity<T>::min> using RangeChmaxQueryRangeMaximumQuery = LazySegmentTree<Monoid::ChmaxMax<T, min_value>>;

/**
 * @brief LazySegmentTree(遅延セグメント木)
 * @docs docs/LazySegmentTree.md
 */
