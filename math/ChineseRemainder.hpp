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

PLL Garner(std::vector<ll> b, std::vector<ll> m, ll MOD) {
    const int n = b.size();
    rep (i, n) rep (j, i) {
        ll g = gcd(m[i], m[j]);
        if ((b[i] - b[j]) % g != 0) return PLL{-1, -1};
        m[i] /= g; m[j] /= g;
        ll gi = gcd(m[i], g), gj = g / gi;
        for (g = gcd(gi, gj); g != 1; g = gcd(gi, gj)) {
            gi *= g; gj /= g;
        }
        m[i] *= gi; m[j] *= gj;
        b[i] %= m[i]; b[j] %= m[j];
    }
    m.push_back(MOD);
    std::vector<ll> ans(n + 1), pr(n + 1, 1);
    rep (i, n) {
        ll t = (b[i] - ans[i]) * mod_inv(pr[i], m[i]) % m[i];
        if (t < 0) t += m[i];
        rep (j, i + 1, n + 1) {
            (ans[j] += t * pr[j]) %= m[j];
            (pr[j] *= m[i]) %= m[j];
        }
    }
    return {ans[n], pr[n]};
}

/**
 * @brief Chinese Remainder(中国剰余定理)
 * @see https://qiita.com/drken/items/ae02240cd1f8edfc86fd
 * @docs docs/math/ChineseRemainder.md
 */
