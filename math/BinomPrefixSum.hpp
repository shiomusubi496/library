#pragma once

#include "../other/template.hpp"
#include "Combinatorics.hpp"

template<class T, class Comb = Combinatorics<T>> class BinomPrefixSum {
    int n, k;
    T val;

public:
    BinomPrefixSum() : BinomPrefixSum(0, 0) {}
    BinomPrefixSum(int n_, int k_) : n(n_), k(k_), val(0) {
        Comb::init(n);
        rep (i, k) val += Comb::comb(n, i);
    }
    T k_inc() { return val += Comb::comb(n, k++); }
    T k_dec() { return val -= Comb::comb(n, --k); }
    T n_inc() { return val += val - Comb::comb(n++, k - 1); }
    T n_dec() { return val = (val + Comb::comb(--n, k - 1)) / 2; }
    T get() const { return val; }
};

/**
 * @brief BinomPrefixSum
 */
