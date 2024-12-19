#pragma once

#include "../other/template.hpp"

ull kth_root(ull n, ull k) {
    if (n <= 1 || k == 1) return n;
    if (k >= 65) return 1;
    auto is_over = [&](ull x) -> bool {
        u128 res = 1, a = x;
        for (int b = k; b; b >>= 1, a *= a) {
            if (b & 1) res *= a;
        }
        return res > n;
    };
    ll res = pow(n, 1.0 / k);
    while (!is_over(res + 1)) ++res;
    while (is_over(res)) --res;
    return res;
}

/**
 * @brief KthRoot(k乗根)
 * @docs docs/math/num/KthRoot.md
 */
