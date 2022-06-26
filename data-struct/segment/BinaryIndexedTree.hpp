#pragma once

#include "../../other/template.hpp"
#include "../../other/monoid.hpp"

template<class M, bool is_monoid = Monoid::is_monoid<M>::value> class BinaryIndexedTree {
  protected:
    using T = typename M::value_type;
    int n;
    std::vector<T> data;
  public:
    BinaryIndexedTree() : BinaryIndexedTree(0) {}
    BinaryIndexedTree(int n_) { init(n_); }
    void init(int n_) {
        n = n_;
        data.assign(n + 1, M::id());
    }
    void apply(int k, T x) {
        ++k;
        while (k <= n) {
            data[k] = M::op(data[k], x);
            k += k & -k;
        }
    }
    T prod(int k) const {
        assert(0 <= k && k <= n);
        T res = M::id();
        while (k) {
            res = M::op(res, data[k]);
            k -= k & -k;
        }
        return res;
    }
    template<bool AlwaysTrue = true, typename std::enable_if<Monoid::has_inv<M>::value && AlwaysTrue>::type* = nullptr>
    T prod(int l, int r) const {
        assert(l <= r);
        return M::inv(prod(r), prod(l));
    }
    T get(int k) const {
        return prod(k, k + 1);
    }
    void set(int k, T x) {
        apply(k, M::inv(x, prod(k)));
    }
};

template<class T> class BinaryIndexedTree<T, false> : public BinaryIndexedTree<Monoid::Sum<T>> {
  protected:
    using Base = BinaryIndexedTree<Monoid::Sum<T>>;
  public:
    using Base::Base;
    void add(int k, T x) { this->apply(k, x); }
    T sum(int k) const { return this->prod(k); }
    T sum(int l, int r) const { return this->prod(l, r); }
};

/**
 * @brief BinaryIndexedTree(FenwickTree, BIT)
 * @docs docs/BinaryIndexedTree.md
 */
