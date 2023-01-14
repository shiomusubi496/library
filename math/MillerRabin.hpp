#pragma once

#include "../other/template.hpp"
#include "MontgomeryModInt.hpp"

constexpr ull base_miller_rabin_int[3] = {2, 7, 61};
constexpr ull base_miller_rabin_ll[7] = {2,      325,     9375,      28178,
                                         450775, 9780504, 1795265022};

template<class T> CONSTEXPR bool miller_rabin(ull n, const ull base[], int s) {
    if (T::get_mod() != n) T::set_mod(n);
    ull d = n - 1;
    while (~d & 1) d >>= 1;
    T e{1}, re{n - 1};
    rep (i, s) {
        ull a = base[i];
        if (a >= n) return true;
        ull t = d;
        T y = T(a).pow(t);
        while (t != n - 1 && y != e && y != re) {
            y *= y;
            t <<= 1;
        }
        if (y != re && !(t & 1)) return false;
    }
    return true;
}

CONSTEXPR bool is_prime_mr(ll n) {
    if (n == 2) return true;
    if (n < 2 || n % 2 == 0) return false;
    if (n < (1u << 31))
        return miller_rabin<MontgomeryModInt<unsigned int, -2>>(
            n, base_miller_rabin_int, 3);
    return miller_rabin<MontgomeryModInt<ull, -2>>(n, base_miller_rabin_ll, 7);
}

#if __cpp_variable_templates >= 201304L && __cpp_constexpr >= 201304L
template<ull n> constexpr bool is_prime_v = is_prime_mr(n);
#endif

/**
 * @brief MillerRabin(ミラーラビン素数判定)
 * @docs docs/math/MillerRabin.md
 */
