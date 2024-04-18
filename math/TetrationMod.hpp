#pragma once

#include "../other/template.hpp"
#include "ModInt.hpp"
#include "EulerPhi.hpp"

ll tetration(ll a, ll b, ll m) {
    assert(m >= 1);
    if (m == 1) return 0;
    if (a == 0) return (b & 1) ^ 1;
    if (b == 0) return 1;
    if (b == 1) return a % m;
    if (b == 2) return mod_pow(a, a, m);
    ll phi = euler_phi(m);
    ll x = tetration(a, b - 1, phi);
    if (x == 0) x += phi;
    return mod_pow(a, x, m);
}

/**
 * @brief TetrationMod
 * @docs docs/math/TetrationMod.md
 */
