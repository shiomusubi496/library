#pragma once

#include "../../other/template.hpp"
#include "FormalPowerSeries.hpp"

template<class T, typename std::enable_if<
                      is_ntt_friendly_modint<T>::value>::type* = nullptr>
FormalPowerSeries<T> power_projection(FormalPowerSeries<T> f, FormalPowerSeries<T> g) {
    static constexpr internal::NthRoot<T> nth_root;
    assert(!f.empty() && f[0] == 0);
    assert(f.size() == g.size());
    int n = 1 << bitop::ceil_log2(f.size()), k = 1;
    FormalPowerSeries<T> W(n * 4);
    W[0] = 1 / T{2};
    rep (i, n * 4) W[i + 1] = W[i] * nth_root.get_inv_rate(popcnt(i & ~(i + 1)));
    FormalPowerSeries<T> P(n * 4), Q(n * 4);
    rep (i, f.size()) P[n - f.size() + i] = g[i];
    rep (i, f.size()) Q[i] = -f[i];
    while (n > 1) {
        P.resize(n * k * 4);
        Q.resize(n * k * 4);
        ++Q[n * k * 2];
        number_theoretic_transform(P);
        number_theoretic_transform(Q);
        rep (i, n * k * 2) {
            P[i] = (P[2 * i] * Q[2 * i + 1] - P[2 * i + 1] * Q[2 * i]) * W[i];
            Q[i] = Q[i * 2] * Q[i * 2 + 1];
        }
        P.resize(n * k * 2);
        Q.resize(n * k * 2);
        inverse_number_theoretic_transform(P);
        inverse_number_theoretic_transform(Q);
        --Q[0];
        rep (i, k * 2) rep (j, n / 2, n) P[i * n + j] = 0;
        rep (i, k * 2) rep (j, n / 2, n) Q[i * n + j] = 0;
        n /= 2; k *= 2;
    }
    rep (i, f.size()) f[i] = P[(k - 1 - i) * 2];
    return f;
}

template<class T, typename std::enable_if<
                      !is_ntt_friendly_modint<T>::value>::type* = nullptr>
FormalPowerSeries<T> power_projection(FormalPowerSeries<T> f, FormalPowerSeries<T> g) {
    assert(!f.empty() && f[0] == 0);
    assert(f.size() == g.size());
    int n = 1 << bitop::ceil_log2(f.size()), k = 1;
    FormalPowerSeries<T> P(n * 2), Q(n * 2);
    rep (i, f.size()) P[n - f.size() + i] = g[i];
    rep (i, f.size()) Q[i] = -f[i];
    while (n > 1) {
        FormalPowerSeries<T> R = Q;
        rep (i, 1, n * k * 2, 2) R[i] = -R[i];
        P = P * R + (P << (n * k * 2));
        Q = Q * R + ((Q + R) << (n * k * 2));
        FormalPowerSeries<T> U(n * k * 2), V(n * k * 2);
        rep (i, k * 2) rep (j, n / 2) {
            U[i * n + j] = P[i * n * 2 + j * 2 + 1];
            V[i * n + j] = Q[i * n * 2 + j * 2];
        }
        P = U; Q = V;
        n /= 2; k *= 2;
    }
    rep (i, f.size()) f[i] = P[(k - 1 - i) * 2];
    return f;
}

template<class T>
FormalPowerSeries<T> composition(FormalPowerSeries<T> f, FormalPowerSeries<T> g) {
    static constexpr internal::NthRoot<T> nth_root;
    assert(f.size() == g.size());
    assert(!g.empty() && g[0] == 0);

    int n = 1 << bitop::ceil_log2(f.size()), k = 1;
    FormalPowerSeries<T> Q(n * 4);
    rep (i, f.size()) Q[i] = -g[i];

    FormalPowerSeries<T> W(n * 4);
    W[0] = 1 / T{2};
    rep (i, n * 4) W[i + 1] = W[i] * nth_root.get_inv_rate(popcnt(i & ~(i + 1)));

    FormalPowerSeries<T> res = rec_lambda([&](auto&& self, int n, int k, FormalPowerSeries<T> Q) -> FormalPowerSeries<T> {
        if (n == 1) {
            FormalPowerSeries<T> res(k * 2);
            rep (i, f.size()) res[(k - 1 - i) * 2] = f[i];
            return res;
        }
        Q.resize(n * k * 4);
        ++Q[n * k * 2];
        number_theoretic_transform(Q);
        FormalPowerSeries<T> R(n * k * 2);
        rep (i, n * k * 2) R[i] = Q[i * 2] * Q[i * 2 + 1];
        inverse_number_theoretic_transform(R);
        --R[0];
        rep (i, k * 2) rep (j, n / 2, n) R[i * n + j] = 0;
        R = self(n / 2, k * 2, R);
        rep (i, k * 2) rep (j, n / 2, n) R[i * n + j] = 0;
        std::reverse(1 + all(R));
        number_theoretic_transform(R);
        FormalPowerSeries<T> P(n * k * 4);
        rrep (i, n * k * 2) {
            P[2 * i] = Q[2 * i + 1] * R[i] * W[i];
            P[2 * i + 1] = -Q[2 * i] * R[i] * W[i];
        }
        inverse_number_theoretic_transform(P);
        std::reverse(1 + all(P));
        P.resize(n * k * 2);
        return P;
    })(n, k, Q) * n;

    FormalPowerSeries<T> ans(f.size());
    rep (i, f.size()) ans[i] = res[n - 1 - i];
    return ans;
}

template<class T, class Comb = Combinatorics<T>>
FormalPowerSeries<T> compositional_inverse(FormalPowerSeries<T> f, int deg = -1) {
    assert(f.size() >= 2 && f[0] == 0 && f[1] != 0);
    if (deg == -1) deg = f.size();
    const T c = f[1].inv();
    f *= c;
    FormalPowerSeries<T> g(deg);
    g[0] = 1;
    g = power_projection(f.prefix(deg), g) * (deg - 1);
    Comb::init(deg);
    rep (i, 1, deg) g[i] *= Comb::inv(i);
    std::reverse(all(g));
    g.pop_back();
    g = (g.log() / (1 - deg)).exp() << 1;
    T v = 1;
    rep (i, deg) {
        g[i] *= v;
        v *= c;
    }
    return g;
}
