#pragma once

#include "../../other/template.hpp"
#include "../../other/monoid.hpp"

template<class A, bool = Monoid::is_semigroup<A>::value> class DualSegmentTree {
    static_assert(Monoid::has_value_type<typename A::M>::value,
                  "M must have value_type");
    static_assert(Monoid::is_semigroup<typename A::E>::value,
                  "E must be semigroup");
    static_assert(Monoid::has_op<A>::value || Monoid::has_mul_op<A>::value,
                  "A must have op");

private:
    using M = typename A::M;
    using E = typename A::E;
    using T = typename M::value_type;
    using U = typename E::value_type;
    int n, h, ori;
    std::vector<T> data;
    std::vector<U> lazy;
    std::vector<bool> lazyflag;


    template<bool AlwaysTrue = true,
             typename std::enable_if<!Monoid::has_mul_op<A>::value &&
                                     AlwaysTrue>::type* = nullptr>
    static inline T Aop(const U& a, const T& b, int) {
        return A::op(a, b);
    }
    template<bool AlwaysTrue = true,
             typename std::enable_if<Monoid::has_mul_op<A>::value &&
                                     AlwaysTrue>::type* = nullptr>
    static inline T Aop(const U& a, const T& b, int c) {
        return A::mul_op(a, c, b);
    }

    void all_apply(int k, U x) {
        if (k < n) {
            if (lazyflag[k]) {
                lazy[k] = E::op(lazy[k], x);
            }
            else {
                lazy[k] = x;
                lazyflag[k] = true;
            }
        }
        else if (k < n + ori) {
            data[k - n] = Aop(x, data[k - n], 1);
        }
    }
    void eval(int k) {
        if (lazyflag[k]) {
            all_apply(k << 1, lazy[k]);
            all_apply(k << 1 ^ 1, lazy[k]);
            lazyflag[k] = false;
        }
    }

public:
    DualSegmentTree() : DualSegmentTree(0) {}
    DualSegmentTree(int n) : DualSegmentTree(n, T{}) {}
    DualSegmentTree(int n_, const T& v)
        : DualSegmentTree(std::vector<T>(n_, v)) {}
    DualSegmentTree(const std::vector<T>& v) { init(v); }
    void init(const std::vector<T>& v) {
        ori = v.size();
        h = bitop::ceil_log2(ori);
        n = 1 << h;
        data = v;
        lazy.resize(n);
        lazyflag.assign(n, false);
    }
    T get(int k) {
        assert(0 <= k && k < ori);

        k += n;
        rreps (i, h) eval(k >> i);
        return data[k - n];
    }
    template<class Upd> void update(int k, const Upd& upd) {
        assert(0 <= k && k < ori);

        k += n;
        rreps (i, h) eval(k >> i);
        data[k - n] = upd(data[k - n]);
    }
    void set(int k, T x) {
        update(k, [&](T) -> T { return x; });
    }
    void apply(int k, U x) {
        update(k, [&](T a) -> T { return A::op(x, a); });
    }
    void apply(int l, int r, U x) {
        assert(0 <= l && l <= r && r <= ori);

        l += n;
        r += n;
        rreps (i, h) {
            bool seen = false;
            if (((l >> i) << i) != l) eval(l >> i), seen = true;
            if (((r >> i) << i) != r) eval((r - 1) >> i), seen = true;
            if (!seen) break;
        }

        while (l != r) {
            if (l & 1) all_apply(l++, x);
            if (r & 1) all_apply(--r, x);
            l >>= 1;
            r >>= 1;
        }
    }
};

template<class E>
class DualSegmentTree<E, true> : public DualSegmentTree<Monoid::MakeAction<E>> {
private:
    using Base = DualSegmentTree<Monoid::MakeAction<E>>;

public:
    using Base::Base;
};

// verified with test/aoj/DSL/DSL_2_D-RUQ.test.cpp
template<class T> using RangeUpdateQuery = DualSegmentTree<Monoid::Assign<T>>;

// verified with test/aoj/DSL/DSL_2_E-RAQ.test.cpp
template<class T> using RangeAddQuery = DualSegmentTree<Monoid::Sum<T>>;

template<class T, int id = -1>
using RangeChminQuery = DualSegmentTree<Monoid::Min<T, id>>;

template<class T, int id = -1>
using RangeChmaxQuery = DualSegmentTree<Monoid::Max<T, id>>;

/**
 * @brief DualSegmentTree(双対セグメント木)
 * @docs docs/data-struct/segment/DualSegmentTree.md
 */
