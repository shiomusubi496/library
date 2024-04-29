#pragma once

#include "../../other/template.hpp"
#include "../../other/monoid.hpp"
#include "BinaryIndexedTree.hpp"
#include "CumulativeSum.hpp"

template<class M, bool = Monoid::is_monoid<M>::value> class RAQBIT {
private:
    using T = typename M::value_type;
    int n;
    BinaryIndexedTree<M> bit;

public:
    RAQBIT(int n_) : n(n_), bit(n_) {}
    void apply(int l, int r, T x) {
        assert(0 <= l && l <= r && r <= n);
        if (l == r) return;
        bit.apply(l, x);
        if (r != n) bit.apply(r, M::get_inv(x));
    }
    void apply(int k, T x) { apply(k, k + 1, x); }
    T get(int k) const {
        assert(0 <= k && k < n);
        return bit.prod(k + 1);
    }
    void set(int k, T x) { apply(k, M::inv(x, get(k))); }
};

template<class T> class RAQBIT<T, false> : public RAQBIT<Monoid::Sum<T>> {
private:
    using Base = RAQBIT<Monoid::Sum<T>>;

public:
    using Base::Base;
    void add(int l, int r, T x) { this->apply(l, r, x); }
    void add(int k, T x) { this->apply(k, x); }
    T sum(int k) const { return this->get(k); }
};


template<class T> class RAQRSQBIT {
private:
    int n;
    BinaryIndexedTree<T> bit1, bit2;
    CumulativeSum<T> cs;

public:
    RAQRSQBIT(int n_) : n(n_), bit1(n), bit2(n), cs(std::vector<T>(n, 1)) {}
    RAQRSQBIT(const std::vector<T>& v) : n(v.size()), bit1(n), bit2(n), cs(v) {}
    void apply(int l, int r, T x) {
        assert(0 <= l && l <= r && r <= n);
        bit1.apply(l, x);
        bit2.apply(l, -x * cs.prod(0, l));
        if (r != n) {
            bit1.apply(r, -x);
            bit2.apply(r, x * cs.prod(0, r));
        }
    }
    void apply(int k, T x) { apply(k, k + 1, x); }
    T prod(int k) const { return bit1.prod(k) * cs.prod(0, k) + bit2.prod(k); }
    T prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= n);
        return prod(r) - prod(l);
    }
    T get(int k) const { return prod(k, k + 1); }
    void set(int k, T x) { apply(k, x - get(k)); }

    void add(int l, int r, T x) { apply(l, r, x); }
    void add(int k, T x) { apply(k, x); }
    T sum(int k) const { return get(k); }
};

/**
 * @brief BinaryIndexedTree(FenwickTree, BIT)
 * @docs docs/data-struct/segment/BinaryIndexedTree.md
 */
