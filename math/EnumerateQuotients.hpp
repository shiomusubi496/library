#pragma once

#include "../other/template.hpp"

std::vector<ll> enumerate_quotients(ll n) {
    std::vector<ll> res{1};
    while (res.back() <= n) res.push_back(n / (n / res.back()) + 1);
    return res;
}

/**
 * @brief Enumerate Quotients(商列挙)
 * @docs docs/math/EnumerateQuotients.md
 */
