#pragma once

#include "../other/template.hpp"
#include "../random/Random.hpp"
#include "ModInt.hpp"
#include "MontgomeryModInt.hpp"
#include "MillerRabin.hpp"
#include "PollardRho.hpp"

template<class T = MontgomeryModInt<ull, -4>> ull primitive_root(ull p) {
    assert(is_prime_mr(p));
    if (p == 2) return 1;
    if (T::get_mod() != p) T::set_mod(p);
    auto pf = factorize(p - 1);
    pf.erase(std::unique(all(pf)), pf.end());
    for (auto&& x : pf) x = (p - 1) / x;
    T one = 1;
    while (1) {
        ull g = rand64.uniform(2ull, p - 1);
        bool ok = true;
        for (const auto& x : pf) {
            if (T(g).pow(x) == one) {
                ok = false;
                break;
            }
        }
        if (ok) return g;
    }
}

/**
 * @brief PrimitiveRoot(原始根)
 * @docs docs/math/PrimitiveRoot.md
 */
