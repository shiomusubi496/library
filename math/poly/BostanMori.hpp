#pragma once

#include "../../other/template.hpp"
#include "FormalPowerSeries.hpp"

template<class T, typename std::enable_if<is_ntt_friendly<T::get_mod()>::value>::type* = nullptr>
T bostan_mori(FormalPowerSeries<T> P, FormalPowerSeries<T> Q, ll n) {
    static constexpr internal::NthRoot<T> nth_root;
    T res = 0;
    if (P.size() >= Q.size()) {
        auto p = divmod(P, Q);
        if (n < (int)p.first.size()) res += p.first[n];
        P = std::move(p.second);
    }
    if (P.empty()) return res;
    int lg = bitop::ceil_log2(Q.size());
    int m = 1 << lg;
    P.resize(2 * m);
    Q.resize(2 * m);
    number_theoretic_transform(P);
    number_theoretic_transform(Q);
    while (n != 0) {
        T z = T{2}.inv();
        if (n & 1) {
            rep (i, m) {
                P[i] = (P[2 * i] * Q[2 * i + 1] - P[2 * i + 1] * Q[2 * i]) * z;
                z *= nth_root.get_inv_rate(popcnt(i & ~(i + 1)));
            }
        }
        else {
            rep (i, m) {
                P[i] = (P[2 * i] * Q[2 * i + 1] + P[2 * i + 1] * Q[2 * i]) * z;
            }
        }
        rep (i, m) Q[i] = Q[2 * i] * Q[2 * i + 1];
        P.resize(m);
        Q.resize(m);
        n >>= 1;
        if (n) {
            P.ntt_doubling();
            Q.ntt_doubling();
        }
    }
    T smp = 0, smq = 0;
    rep (i, m) smp += P[i];
    rep (i, m) smq += Q[i];
    return res + smp / smq;
}

template<class T, typename std::enable_if<!is_ntt_friendly<T::get_mod()>::value>::type* = nullptr>
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