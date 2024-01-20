#pragma once

#include "../other/template.hpp"
#include "poly/FormalPowerSeries.hpp"
#include "poly/MultipointEvaluation.hpp"

template<class T>
T factorial(ll n) {
    assert(n >= 0);
    if (n >= T::get_mod()) return 0;
    if (n * 2 > T::get_mod()) {
        T res = factorial<T>(T::get_mod() - 1 - n);
        if ((T::get_mod() - n) & 1) res = -res;
        return 1 / res;
    }
    if (n <= 1000) {
        T res = 1;
        reps (i, n) res *= i;
        return res;
    }
    const ll bs = sqrt(n), bn = n / bs;
    std::vector<T> v1(bs), v2(bn);
    rep (i, bs) v1[i] = -1 - i;
    rep (i, bn) v2[i] = i * bs;
    auto f = internal::ProductTree<T>(v1)[1];
    T res = 1;
    for (const auto& x : multipoint_evaluation(f, v2)) res *= x;
    rep (i, bn * bs + 1, n + 1) res *= i;
    return res;
}

/**
 * @brief Factorial(階乗)
 * @docs docs/math/Factorial.md
 */
