#pragma once

#include "../../other/template.hpp"

template<class T, class F = std::function<T(T, T)>, class G = std::function<T(T, T)>> class BinaryIndexedTree {
  protected:
    F op;
    T e;
    G inv;
    bool inv_exits;
    int n;
    std::vector<T> data;
  public:
    BinaryIndexedTree() = default;
    BinaryIndexedTree(int n_)
        : BinaryIndexedTree(n_  , [](const T& a, const T& b) -> T { return a + b; },
                            T(0), [](const T& a, const T& b) -> T { return a - b; }) {}
    BinaryIndexedTree(const F& op, const T& e) : BinaryIndexedTree(0, op, e) {}
    BinaryIndexedTree(int n_, const F& op, const T& e) : op(op), e(e), inv_exits(false) { init(n_); }
    BinaryIndexedTree(int n_, const F& op, const T& e, const G& inv) : op(op), e(e), inv(inv), inv_exits(true) { init(n_); }
    void init(int n_) {
        n = n_;
        data.assign(n + 1, e);
    }
    void add(int k, T x) {
        ++k;
        while (k <= n) {
            data[k] = op(data[k], x);
            k += k & -k;
        }
    }
    T sum(int k) const {
        assert(0 <= k && k <= n);
        T res = e;
        while (k) {
            res = op(res, data[k]);
            k -= k & -k;
        }
        return res;
    }
    T sum(int l, int r) const {
        assert(l <= r);
        assert(inv_exits);
        return inv(sum(r), sum(l));
    }
    T get(int k) const {
        return sum(k, k + 1);
    }
    void set(int k, T x) {
        add(k, inv(x, get(k)));
    }
};

/**
 * @brief BinaryIndexedTree(FenwickTree, BIT)
 * @docs docs/BinaryIndexedTree.md
 */
