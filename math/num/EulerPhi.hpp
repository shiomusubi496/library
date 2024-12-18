#pragma once

#include "../../other/template.hpp"
#include "PollardRho.hpp"

ll euler_phi(ll n) {
    ll res = n;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            res = res / i * (i - 1);
            while (n % i == 0) n /= i;
        }
    }
    if (n != 1) res = res / n * (n - 1);
    return res;
}

ll euler_phi_pollardrho(ll n) {
    for (auto p : expfactorize(n)) n = n / p.first * (p.first - 1);
    return n;
}

class EulerPhi {
private:
    ll MAX;
    std::vector<ll> data;

public:
    EulerPhi(ll MAX) : MAX(MAX), data(MAX + 1, 0) {
        rep (i, MAX + 1) data[i] = i;
        rep (i, 2, MAX + 1) {
            if (data[i] != i) continue;
            rep (j, i, MAX + 1, i) {
                data[j] = data[j] / i * (i - 1);
            }
        }
    }
    ll phi(ll x) { return data[x]; }
};

/**
 * @brief Euler's-Phi(オイラーのφ関数)
 * @docs docs/math/num/EulerPhi.md
 */
