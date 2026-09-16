#pragma once

#include "../../other/template.hpp"
#include "FormalPowerSeries.hpp"

template<class T>
FormalPowerSeries<T> transposed_bostan_mori(FormalPowerSeries<T> Q, ll n) {
    static constexpr internal::NthRoot<T> nth_root;
    int d = Q.size();
    if (d == 1) {
        if (n == 0) return {1};
        return {0};
    }
    auto transposed_ntt_doubling_ = [&](std::vector<T>& a) -> void {
        int n = a.size() / 2;
        std::vector<T> b(n);
        rep (i, n) b[i] = a[i + n];
        inverse_number_theoretic_transform(b);
        const T z = nth_root.inv(bitop::msb(n) + 1);
        T r = -1;
        rep (i, 1, n) {
            r *= z;
            b[i] *= r;
        }
        number_theoretic_transform(b);
        rep (i, n) a[i] += b[i];
        a.resize(n);
    };
    int m = 1 << bitop::ceil_log2(d);
    FormalPowerSeries<T> R = Q;
    R.resize(2 * m);
    number_theoretic_transform(R);
    auto P = rec_lambda([&](auto&& self, FormalPowerSeries<T> Q, ll n) -> FormalPowerSeries<T> {
        if (n == 0) {
            T smq = 0;
            rep (i, m) smq += Q[i];
            return FormalPowerSeries<T>(m, 1 / smq);
        }
        FormalPowerSeries<T> R(m);
        rep (i, m) R[i] = Q[2 * i] * Q[2 * i + 1];
        if (n != 1) ntt_doubling_(R);
        FormalPowerSeries<T> P = self(R, n / 2);
        if (n != 1) transposed_ntt_doubling_(P);
        FormalPowerSeries<T> S(2 * m);
        T z = T{2}.inv();
        if (n & 1) {
            rep (i, m) {
                S[2 * i] = P[i] * Q[2 * i + 1] * z;
                S[2 * i + 1] = -P[i] * Q[2 * i] * z;
                z *= nth_root.get_inv_rate(popcnt(i & ~(i + 1)));
            }
        }
        else {
            rep (i, m) {
                S[2 * i] = P[i] * Q[2 * i + 1] * z;
                S[2 * i + 1] = P[i] * Q[2 * i] * z;
            }
        }
        return S;
    })(R, n + m - 1);
    inverse_number_theoretic_transform(P);
    std::reverse(1 + all(P));
    P *= P.size();
    P.resize(m);
    std::reverse(all(P));
    return P;
}

template<class T>
FormalPowerSeries<T> range_coefs(FormalPowerSeries<T> P, FormalPowerSeries<T> Q, ll n, int m) {
    while (Q.back() == 0) Q.pop_back();
    FormalPowerSeries<T> f = transposed_bostan_mori(Q, n);
    auto [p, q] = divmod(P, Q);
    f = (f * Q).prefix(Q.size() - 1);
    f = (f * q) % Q;
    FormalPowerSeries<T> res = (f * Q.inv(m)).prefix(m);
    rep (i, n, p.size()) if (i < n + m) res[i - n] += p[i];
    return res;
}

template<class T>
FormalPowerSeries<T> range_terms(FormalPowerSeries<T> C, FormalPowerSeries<T> A, ll n, int m) {
    assert(!C.empty() && C[0] != 0);
    assert(A.size() == C.size() - 1);
    return range_coefs((A * C).prefix(A.size()), C, n, m);
}
