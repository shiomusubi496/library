#pragma once

#include "../other/template.hpp"
#include "Combinatorics.hpp"
#include "../data-struct/other/Mo.hpp"

template<class T, class Comb = Combinatorics<T>> class BinomPrefixSum {
public:
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

template<class T, class Comb = Combinatorics<T>> class OfflineBinomPrefixSum {
    int mx;
    std::vector<std::pair<int, int>> qs;
    std::vector<T> res, memo;
    std::vector<int> idx;

public:
    OfflineBinomPrefixSum() : OfflineBinomPrefixSum(0) {}
    OfflineBinomPrefixSum(int n) : mx(n), memo(n + 1, 1) {
        rep (i, n) memo[i + 1] = memo[i] * 2;
    }
    void push(int n, int k) {
        if (n < k) {
            while ((int)memo.size() <= n) memo.push_back(memo.back() * 2);
            res.push_back(memo[n]);
            return;
        }
        res.push_back(0);
        chmax(mx, n);
        qs.emplace_back(k, n);
        idx.push_back(res.size() - 1);
    }
    std::vector<T> build() {
        Comb::init(mx);
        Mo mo(mx, qs);
        BinomPrefixSum<T, Comb> bps;
        mo.build(
            [&](int) { bps.k_dec(); },
            [&](int) { bps.n_inc(); },
            [&](int) { bps.k_inc(); },
            [&](int) { bps.n_dec(); },
            [&](int i) { res[idx[i]] = bps.get(); }
        );
        return res;
    }
    T operator[](int k) const { return res[k]; }
};

/**
 * @brief BinomPrefixSum
 */
