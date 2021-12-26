#pragma once

#include "../../other/template.hpp"
#include "../../other/monoid.hpp"

template<class M> class BinaryIndexedTreeAnyOperation {
  protected:
    using T = typename M::value_type;
    int n;
    std::vector<T> data;
  public:
    BinaryIndexedTreeAnyOperation() : BinaryIndexedTreeAnyOperation(0) {}
    BinaryIndexedTreeAnyOperation(int n_) { init(n_); }
    void init(int n_) {
        n = n_;
        data.assign(n + 1, M::id());
    }
    void add(int k, T x) {
        ++k;
        while (k <= n) {
            data[k] = M::op(data[k], x);
            k += k & -k;
        }
    }
    T sum(int k) const {
        assert(0 <= k && k <= n);
        T res = M::id();
        while (k) {
            res = M::op(res, data[k]);
            k -= k & -k;
        }
        return res;
    }
    template<bool AlwaysTrue = true, typename std::enable_if<Monoid::has_inv<M>::value && AlwaysTrue>::type* = nullptr>
    T sum(int l, int r) const {
        assert(l <= r);
        return M::inv(sum(r), sum(l));
    }
    T get(int k) const {
        return sum(k, k + 1);
    }
    void set(int k, T x) {
        add(k, M::inv(x, get(k)));
    }
};

template<class T> using BinaryIndexedTree = BinaryIndexedTreeAnyOperation<Monoid::Sum<T>>;

/**
 * @brief BinaryIndexedTree(FenwickTree, BIT)
 * @docs docs/BinaryIndexedTree.md
 */
