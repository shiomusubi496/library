#pragma once

#include "../../other/template.hpp"
#include "../convolution/Convolution.hpp"
#include "../Combinatorics.hpp"
#include "FormalPowerSeries.hpp"
#include "TaylorShift.hpp"

template<class T, class Comb = Combinatorics<T>>
std::vector<T> sampling_points_shift(std::vector<T> a, int m, T t) {
    const int n = a.size();
    Comb::init(std::max(n, m));
    FormalPowerSeries<T> f(n), g(n);
    rep (i, n) f[i] = i & 1 ? -Comb::finv(i) : Comb::finv(i);
    rep (i, n) g[i] = a[i] * Comb::finv(i);
    f = (f * g).prefix(n);
    rep (i, n) f[i] *= Comb::fact(i);
    T p = 1;
    rep (i, n) {
        g[n - 1 - i] = p * Comb::finv(i);
        p *= t--;
    }
    f = (f * g) >> (n - 1);
    rep (i, n) f[i] *= Comb::finv(i);
    g.resize(m);
    rep (i, m) g[i] = Comb::finv(i);
    f = (f * g).prefix(m);
    rep (i, m) f[i] *= Comb::fact(i);
    return std::vector<T>(f);
}

template<class T, class Comb = Combinatorics<T>>
T sampling_points_shift(std::vector<T> a, T t) {
    const int n = a.size();
    Comb::init(n - 1);
    std::vector<T> cum(n, 1);
    rep (i, n - 1) cum[i + 1] = cum[i] * (i - t);
    T res = 0, cur = 1;
    rrep (i, n) {
        res += a[i] * cum[i] * cur * (i & 1 ? -Comb::finv(i) : Comb::finv(i)) * Comb::finv(n - i - 1);
        cur *= i - t;
    }
    return res;
}

/**
 * @brief SamplingPointsShift(標本点シフト)
 * @docs docs/math/poly/SamplingPointsShift.md
 */
