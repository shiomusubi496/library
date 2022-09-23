#pragma once

#include "../other/template.hpp"

ull floor_sum_unsigned(ull n, ull m, ull a, ull b) {
    ull ans = 0;
    while (true) {
        if (a >= m) {
            ans += n * (n - 1) / 2 * (a / m);
            a %= m;
        }
        if (b >= m) {
            ans += n * (b / m);
            b %= m;
        }
        ull y = a * n + b;
        if (y < m) break;
        n = y / m;
        b = y % m;
        std::swap(m, a);
    }
    return ans;
}

ll floor_sum(ll n, ll m, ll a, ll b) {
    assert(0 <= n);
    assert(1 <= m);
    ll ans = 0;
    if (a < 0) {
        ll a1 = a % m;
        if (a1 < 0) a1 += m;
        ans -= (ull)(n - 1) * n / 2 * ((a1 - a) / m);
        a = a1;
    }
    if (b < 0) {
        ll b1 = b % m;
        if (b1 < 0) b1 += m;
        ans -= (ull)n * ((b1 - b) / m);
        b = b1;
    }
    return ans + floor_sum_unsigned(n, m, a, b);
}

/**
 * @brief FloorSum
 * @docs docs/math/FloorSum.md
 * @see https://rsk0315.hatenablog.com/entry/2020/12/13/231307
 */
