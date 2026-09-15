#pragma once

#include "../../other/template.hpp"
#include "FormalPowerSeries.hpp"
#include "../SqrtMod.hpp"

template<class T, typename std::enable_if<
                      is_ntt_friendly_modint<T>::value>::type* = nullptr>
FormalPowerSeries<T> sqrt(FormalPowerSeries<T> t, int deg = -1) {
    if (deg == -1) deg = t.size();
    T a;
    int d = -1;
    rep (i, t.size()) {
        if (t[i] != 0) {
            a = t[i];
            d = i;
            break;
        }
    }
    if (d == -1) {
        FormalPowerSeries<T> res(deg);
        return res;
    }
    if (d & 1) return {};
    deg -= (d >> 1);
    if (deg <= 0) {
        FormalPowerSeries<T> res(deg + (d >> 1));
        return res;
    }
    t >>= d;
    T sq = sqrt_mod<T>(a.get());
    if (sq == -1) return {};
    FormalPowerSeries<T> f(1, sq), g(1, 1 / sq), dft_f = f;
    number_theoretic_transform(dft_f);
    for (int m = 1; m < deg; m <<= 1) {
        dft_f.ntt_doubling(f);
        f.resize(2 * m);
        g.resize(2 * m);
        FormalPowerSeries<T> dft_g = g;
        number_theoretic_transform(dft_g);
        FormalPowerSeries<T> u = dft_f;
        rep (i, 2 * m) u[i] *= dft_f[i];
        FormalPowerSeries<T> tx = t.prefix(2 * m);
        number_theoretic_transform(tx);
        rep (i, 2 * m) u[i] = (tx[i] - u[i]) * dft_g[i];
        inverse_number_theoretic_transform(u);
        rep (i, m, 2 * m) f[i] = u[i] / 2;
        if (2 * m < deg) {
            dft_f = f;
            number_theoretic_transform(dft_f);
            FormalPowerSeries<T> u = dft_g;
            rep (i, 2 * m) u[i] *= dft_f[i];
            inverse_number_theoretic_transform(u);
            std::fill(u.begin(), u.begin() + m, T{0});
            number_theoretic_transform(u);
            rep (i, 2 * m) u[i] *= dft_g[i];
            inverse_number_theoretic_transform(u);
            rep (i, m, 2 * m) g[i] = -u[i];
        }
    }
    return f.prefix(deg) << (d >> 1);
}
template<class T, typename std::enable_if<
                      !is_ntt_friendly_modint<T>::value>::type* = nullptr>
FormalPowerSeries<T> sqrt(FormalPowerSeries<T> t, int deg = -1) {
    if (deg == -1) deg = tsize();
    T a;
    int d = -1;
    rep (i, t.size()) {
        if (t[i] != 0) {
            a = t[i];
            d = i;
            break;
        }
    }
    if (d == -1) {
        FormalPowerSeries res(deg);
        return res;
    }
    if (d & 1) return {};
    deg -= (d >> 1);
    if (deg <= 0) {
        FormalPowerSeries res(deg + (d >> 1));
        return res;
    }
    t >>= d;
    T sq = sqrt_mod<T>(a.get());
    if (sq == -1) return {};
    FormalPowerSeries f(1, sq);
    for (int m = 1; m < deg; m <<= 1) {
        f = (f + t * f.inv(2 * m)).prefix(2 * m) / 2;
    }
    return f.prefix(deg) << (d >> 1);
}
