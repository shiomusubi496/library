#pragma once

#include "../other/template.hpp"

std::vector<ll> divisors(ll n) {
    std::vector<ll> res1, res2;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            res1.push_back(i);
            if (i * i != n) res2.push_back(n / i);
        }
    }
    res1.reserve(res1.size() + res2.size());
    std::copy(res2.rbegin(), res2.rend(), std::back_inserter(res1));
    return res1;
}

/**
 * @brief Divisors(約数列挙)
 * @docs docs/math/Divisor.md
 */
