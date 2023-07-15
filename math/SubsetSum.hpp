#pragma once

#include "../other/template.hpp"
#include "../string/RunLength.hpp"
#include "Combinatorics.hpp"
#include "poly/FormalPowerSeries.hpp"

template<class T, class Comb = Combinatorics<T>>
std::vector<T> subset_sum(std::vector<int> a, int n) {
    if (a.empty()) {
        FormalPowerSeries<T> f(n + 1);
        f[0] = 1;
        return f;
    }
    std::sort(all(a));
    assert(a[0] > 0);
    FormalPowerSeries<T> f(n + 1);
    for (auto p : RunLength(a)) {
        int x = p.first;
        T y = p.second;
        rep (i, 1, n / x + 1) {
            f[i * x] += i & 1 ? y * Comb::inv(i) : -y * Comb::inv(i);
        }
    }
    return std::vector<T>(f.exp(n + 1));
}

/**
 * @brief SubsetSum
 * @docs docs/math/SubsetSum.md
 */
