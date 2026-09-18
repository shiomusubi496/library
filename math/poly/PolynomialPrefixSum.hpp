#pragma once

#include "../../other/template.hpp"
#include "../convolution/Convolution.hpp"
#include "../Combinatorics.hpp"
#include "../StirlingNumber.hpp"

template<class T, class Comb = Combinatorics<T>>
FormalPowerSeries<T> polynomial_prefix_sum(FormalPowerSeries<T> f) {
    int n = f.size();
    if (n == 0) return {0};
    Comb::init(n);
    rep (i, n) f[i] *= Comb::fact(i);
    FormalPowerSeries<T> g = bernoulli_number<T, Comb>(n - 1);
    rep (i, n) g[i] *= Comb::finv(i);
    std::reverse(all(g));
    f *= g;
    FormalPowerSeries<T> res(n + 1);
    reps (i, n) res[i] = f[i + n - 2] * Comb::finv(i);
    return res;
}
