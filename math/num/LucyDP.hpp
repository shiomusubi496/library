#pragma once

#include "../../other/template.hpp"

ll LucyDP(ll n) {
    ll m = 1;
    while (m * m <= n) ++m;
    --m;
    ll m2 = n / m;
    std::vector<ll> dpL(m2 + 1), dpR(m + 1);
    rep (i, 1, m2 + 1) dpL[i] = i - 1;
    rep (i, 1, m + 1) dpR[i] = n / i - 1;
    rep (i, 2, m + 1) {
        if (dpL[i] <= dpL[i - 1]) continue;
        ll p = dpL[i - 1];
        rep (j, 1, m + 1) {
            if (n / j < i * i) break;
            (n / j <= m2 ? dpL[n / j] : dpR[j]) -=
                (n / (i * j) <= m2 ? dpL[n / (i * j)] : dpR[i * j]) - p;
        }
        rrep (j, 1, m2) {
            if (j < i * i) break;
            dpL[j] -= dpL[j / i] - p;
        }
    }
    return dpR[1];
}
