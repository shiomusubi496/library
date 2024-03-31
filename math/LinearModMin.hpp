#pragma once

#include "../other/template.hpp"
#include "SternBrocotTree.hpp"

std::vector<std::tuple<ll, ll, ll>>
linear_mod_min_arithmetic_progressions(ll a, ll b, ll m) {
    using SBT = SternBrocotTree<ll>;
    std::vector<std::tuple<ll, ll, ll>> res;
    a = -a % m;
    if (a < 0) a += m;
    b = b % m;
    if (b < 0) b += m;
    if (a == 0 || b == 0) return res;
    auto path = SBT::encode_path({a, m});
    path.insert(path.begin(), {'R', 0});
    ll x = 0, y = b;
    ll p = 0, q = 1, r = 1, s = 0;
    rep (i, path.size()) {
        if (y == 0) return res;
        auto [d, k] = path[i];
        if (d == 'L') {
            r += p * k;
            s += q * k;
        }
        else {
            ll np = p + r * k, nq = q + s * k;
            if (a * nq - m * np <= y) {
                ll t = a * q - m * p - y, u = m * r - a * s;
                ll k2 = std::max((t + u - 1) / u, 0ll);
                np = p + r * k2;
                nq = q + s * k2;
                ll c = a * nq - m * np;
                res.emplace_back(x, nq, y / c);
                x += nq * (y / c);
                y %= c;
                path[i--].second -= k2;
            }
            p = np;
            q = nq;
        }
    }
    return res;
}

PLL linear_mod_min(ll a, ll b, ll m, ll n) {
    auto ap = linear_mod_min_arithmetic_progressions(a, b, m);
    if (ap.empty()) return {0, b};
    for (auto [x, y, z] : ap) {
        if (x + y * z >= n) {
            ll k = (n - x - 1) / y;
            ll t = x + y * k;
            return {t, (b + a * t) % m};
        }
    }
    auto [x, y, z] = ap.back();
    ll t = x + y * z;
    return {t, (b + a * t) % m};
}

/**
 * @brief LinearModMin
 * @docs docs/math/LinearModMin.md
 * @see https://maspypy.com/library-checker-min-of-mod-of-linear
 */
