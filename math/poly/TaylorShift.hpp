#pragma once

#include "../../other/template.hpp"
#include "../convolution/Convolution.hpp"
#include "../Combinatorics.hpp"
#include "FormalPowerSeries.hpp"

template<class T, class Comb = Combinatorics<T>>
FormalPowerSeries<T> taylor_shift(FormalPowerSeries<T> f, T a) {
    const int n = f.size();
    rep (i, n) f[i] *= Comb::fact(i);
    FormalPowerSeries<T> g(n);
    T p = 1;
    rep (i, n) {
        g[n - 1 - i] = p * Comb::finv(i);
        p *= a;
    }
    f *= g;
    f >>= n - 1;
    rep (i, n) f[i] *= Comb::finv(i);
    return f;
}

/**
 * @brief TaylorShift
 * @docs docs/math/poly/TaylorShift.md
 */
