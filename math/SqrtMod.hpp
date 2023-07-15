#pragma once

#include "../other/template.hpp"
#include "MontgomeryModInt.hpp"

template<class T> ll sqrt_mod(ll a) {
    const ll p = T::get_mod();
    if (p == 2) return a;
    if (a == 0) return 0;
    if (T{a}.pow((p - 1) >> 1) != 1) return -1;
    T b = 2;
    while (T{b}.pow((p - 1) >> 1) == 1) ++b;
    ll s = 0, t = p - 1;
    while ((t & 1) == 0) t >>= 1, ++s;
    T x = T{a}.pow((t + 1) >> 1);
    T w = T{a}.pow(t);
    T v = T{b}.pow(t);
    while (w != 1) {
        ll k = 0;
        T y = w;
        while (y != 1) {
            y *= y;
            ++k;
        }
        T z = v;
        rep (s - k - 1) z *= z;
        x *= z;
        w *= z * z;
    }
    return std::min<ll>(x.get(), p - x.get());
}

ll sqrt_mod(ll a, ll p) {
    if (p == 2) return a;
    using mint = MontgomeryModInt<unsigned int, 493174342>;
    mint::set_mod(p);
    return sqrt_mod<mint>(a);
}

/**
 * @brief SqrtMod(平方剰余)
 * @docs docs/math/SqrtMod.md
 * @see https://37zigen.com/tonelli-shanks-algorithm/
 */
