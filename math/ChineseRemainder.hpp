#pragma once

#include "../other/template.hpp"

PLL ChineseRemainder(ll b1, ll m1, ll b2, ll m2) {
    const PLL p = extGCD(m1, m2);
    const ll g = p.first * m1 + p.second * m2;
    const ll l = m1 / g * m2;
    if ((b2 - b1) % g != 0) return PLL{-1, -1};
    const ll x = (b2 - b1) / g * p.first % (m2 / g);
    return {(x * m1 + b1 + l) % l, l};
}
PLL ChineseRemainder(const std::vector<ll>& b, const std::vector<ll>& m) {
    PLL res{0, 1};
    rep (i, b.size()) {
        res = ChineseRemainder(res.first, res.second, b[i], m[i]);
        if (res.first == -1) return res;
    }
    return res;
}

/**
 * @brief Chinese Remainder(中国剰余定理)
 * @docs docs/math/ChineseRemainder.md
 */
