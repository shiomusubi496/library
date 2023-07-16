#pragma once

#include "../../other/template.hpp"
#include "FormalPowerSeries.hpp"

template<class T>
T bostan_mori(FormalPowerSeries<T> P, FormalPowerSeries<T> Q, ll n) {
    T res = 0;
    if (P.size() >= Q.size()) {
        auto p = divmod(P, Q);
        if (n < p.first.size()) res += p.first[n];
        P = p.second;
    }
    if (P.empty()) return res;
    P.resize(Q.size() - 1);
    while (n != 0) {
        FormalPowerSeries<T> Q2(Q);
        rep (i, Q.size()) {
            if (i & 1) Q2[i] = -Q2[i];
        }
        auto A = P * Q2;
        auto B = Q * Q2;
        if (n & 1) {
            rep (i, 1, A.size(), 2) P[i >> 1] = A[i];
            rep (i, 0, B.size(), 2) Q[i >> 1] = B[i];
        }
        else {
            rep (i, 0, A.size(), 2) P[i >> 1] = A[i];
            rep (i, 0, B.size(), 2) Q[i >> 1] = B[i];
        }
        n >>= 1;
    }
    return res + P[0] / Q[0];
}

template<class T>
T kth_term(FormalPowerSeries<T> C, FormalPowerSeries<T> A, ll n) {
    assert(!C.empty() && C[0] != 0);
    assert(A.size() == C.size() - 1);
    if (n < (ll)A.size()) return A[n];
    return bostan_mori((A * C).prefix(A.size()), C, n);
}

/**
 * @brief Bostan-Mori(線形漸化式のn項目)
 * @docs docs/math/poly/BostanMori.md
 */