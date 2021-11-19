#pragma once

#include "../../template.hpp"

template<class T> class BinaryIndexedTree {
  protected:
    using F = std::function<T(T, T)>;
    using G = std::function<T()>;
    using H = std::function<T(T)>;
    F op;
    G e;
    H inv;
    bool inv_exits;
    int n;
    std::vector<T> data;
  public:
    BinaryIndexedTree() = default;
    BinaryIndexedTree(int n_) : BinaryIndexedTree(n_, [](T a, T b) -> T { return a + b; }, []() -> T { return 0; }, [](T a) -> T { return -a; }) {}
    BinaryIndexedTree(int n_, const F& op, const G& e) : op(op), e(e), inv_exits(false) { init(n_); }
    BinaryIndexedTree(int n_, const F& op, const G& e, const H& inv) : op(op), e(e), inv(inv), inv_exits(true) { init(n_); }
    void init(int n_) {
        n = 1;
        while (n < n_) n <<= 1;
        data.assign(n + 1, e());
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
        T res = e();
        while (k) {
            res = op(res, data[k]);
            k -= k & -k;
        }
        return res;
    }
    T sum(int l, int r) const {
        assert(l <= r);
        assert(inv_exits);
        return op(sum(r), inv(sum(l)));
    }
    T get(int k) const {
        return sum(k, k + 1);
    }
    void set(int k, T x) {
        add(k, op(x, inv(get(k))));
    }
    template<class C> int max_right(int l, const C& cond) {
        assert(0 <= l && l <= n);
        assert(cond(e()));
        if (l == n) return n;
        T sm = e();
        ++l;
        while (l <= n) {
            if (!cond(op(sm, data[l]))) {
                int ln = l & -l;
                while (ln >>= 1) {
                    if (cond(op(sm, data[l - ln]))) sm = op(sm, data[l - ln]);
                    else l -= ln;
                }
                return l;
            }
            sm = op(sm, data[l]);
            l += l & -l;
        }
        return n;
    }
};

/**
 * @brief BinaryIndexedTree(FenwickTree, BIT)
 * @docs docs/BinaryIndexedTree.md
 */
