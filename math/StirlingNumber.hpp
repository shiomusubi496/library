#pragma once

#include "../other/template.hpp"
#include "Combinatorics.hpp"
#include "convolution/Convolution.hpp"
#include "poly/FormalPowerSeries.hpp"
#include "poly/SparseFormalPowerSeries.hpp"
#include "poly/TaylorShift.hpp"

template<class T, class Comb = Combinatorics<T>>
std::vector<T> stirling_number_1st(int n) {
    if (n == 0) return {1};
    if (n == 1) return {0, 1};
    int lg = bitop::msb(n);
    FormalPowerSeries<T> f{0, 1};
    rrep (i, lg) {
        int m = n >> i;
        f *= taylor_shift<T, Comb>(f, -(m >> 1));
        if (m & 1) f = (f << 1) - f * (m - 1);
    }
    return std::vector<T>(f);
}

template<class T, class Comb = Combinatorics<T>>
std::vector<T> stirling_number_1st_fixed_k(int k, int n) {
    Comb::init(n);
    SparseFPS<T> f{1, -1};
    FormalPowerSeries<T> g = (f.log(n - k + 2) >> 1).pow(k) * Comb::finv(k);
    rep (i, n - k + 1) {
        g[i] *= Comb::fact(i + k);
        if ((i + k) & 1) g[i] = -g[i];
    }
    return std::vector<T>(g);
}

template<class T, class Comb = Combinatorics<T>>
std::vector<T> stirling_number_2nd(int n) {
    Comb::init(n);
    std::vector<T> a(n + 1), b(n + 1);
    rep (i, n + 1) {
        a[i] = i & 1 ? -Comb::finv(i) : Comb::finv(i);
        b[i] = T{i}.pow(n) * Comb::finv(i);
    }
    auto c = convolution(a, b);
    c.resize(n + 1);
    return c;
}

template<class T, class Comb = Combinatorics<T>>
std::vector<T> stirling_number_2nd_fixed_k(int k, int n) {
    Comb::init(n);
    SparseFPS<T> f{{1, 1}};
    FormalPowerSeries<T> g = (f.exp(n - k + 2) >> 1).pow(k) * Comb::finv(k);
    rep (i, n - k + 1) g[i] *= Comb::fact(i + k);
    return std::vector<T>(g);
}

template<class T, class Comb = Combinatorics<T>>
std::vector<T> bell_number(int n) {
    Comb::init(n);
    FormalPowerSeries<T> f(n + 1);
    reps (i, n) f[i] = Comb::finv(i);
    auto c = f.exp();
    rep (i, n + 1) c[i] *= Comb::fact(i);
    return std::vector<T>(c);
}

template<class T, class Comb = Combinatorics<T>>
std::vector<T> bell_number_fixed_n(int n) {
    auto a = stirling_number_2nd<T, Comb>(n);
    rep (i, n) a[i + 1] += a[i];
    return a;
}

template<class T, class Comb = Combinatorics<T>>
std::vector<T> bernoulli_number(int n) {
    Comb::init(n);
    FormalPowerSeries<T> f(n + 1);
    rep (i, n + 1) f[i] = Comb::finv(i + 1);
    auto res = f.inv(n + 1);
    rep (i, n + 1) res[i] *= Comb::fact(i);
    return std::vector<T>(res);
}

template<class T> std::vector<T> partition_number(int n) {
    FormalPowerSeries<T> f(n + 1);
    rep (i, n + 1) {
        ll s = i * (3 * i - 1) / 2;
        if (s > n) break;
        f[s] += i & 1 ? -1 : 1;
        if (i == 0) continue;
        s = i * (3 * i + 1) / 2;
        if (s > n) break;
        f[s] += i & 1 ? -1 : 1;
    }
    return std::vector<T>(f.inv());
}

/**
 * @brief StirlingNumber(スターリング数, ベル数, ベルヌーイ数, 分割数)
 * @docs docs/math/StirlingNumber.md
 */
