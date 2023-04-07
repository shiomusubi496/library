#pragma once

#include "../other/template.hpp"
#include "../other/monoid2.hpp"
#include "KthRoot.hpp"
#include "BarrettReduction.hpp"

template<class A,
         class Container = std::unordered_map<typename A::M::value_type, ll>>
ll baby_step_giant_step(const typename A::M::value_type& a,
                        const typename A::M::value_type& b,
                        const typename A::E::value_type& f, ll MAX) {
    using T = typename A::M::value_type;
    using U = typename A::E::value_type;
    ll s = kth_root(MAX, 2) + 1;
    Container mp;
    {
        const U g = A::E::get_inv(f);
        T x = b;
        rep (i, s) {
            if (mp.count(x) == 0) mp[x] = i;
            x = A::op(g, x);
        }
    }
    {
        U g = A::E::id();
        rep (s) g = A::E::op(g, f);
        T x = a;
        rep (i, s) {
            if (mp.count(x)) return i * s + mp[x];
            x = A::op(g, x);
        }
    }
    return -1;
}

namespace Monoid {

template<class T> struct ProductAction {
    using M = Product<T>;
    using E = Product<T>;
    static T op(T a, T b) { return a * b; }
};

} // namespace Monoid

template<class T> struct hash_mint_for_discrete_logarithm {
    std::size_t operator()(const T& x) const {
        return std::hash<unsigned int>()(x.get());
    }
};

// min k (a*x^k=b)
template<class T> ll discrete_logarithm_mint(T a, T x, T b) {
    return baby_step_giant_step<
        Monoid::ProductAction<T>,
        std::unordered_map<T, ll, hash_mint_for_discrete_logarithm<T>>>(
        a, b, x, T::get_mod());
}

template<class T> ll discrete_logarithm_mint(T x, T b) {
    return discrete_logarithm_mint<T>(T{1}, x, b);
}

// min k (a*x^k = b (mod m))
ll discrete_logarithm(ll a, ll x, ll b, ll m) {
    if (a == b) return 0;

    ll g = 1, tmp = x;
    int cnt = 0;
    ll cur = a;
    while ((tmp = gcd(tmp, m / g)) != 1) {
        g *= tmp;
        ++cnt;
        (cur *= x) %= m;
        if (cur == b) return cnt;
    }
    if (g != 1) {
        if (b % g != 0) return -1;
        b /= g;
        cur /= g;
        m /= g;
    }

    using mint = bmodint;
    mint::set_mod(m);

    const ll ans = discrete_logarithm_mint<mint>(mint{cur}, mint{x}, mint{b});
    if (ans == -1) return -1;
    return ans + cnt;
}

ll discrete_logarithm(ll x, ll b, ll m) {
    return discrete_logarithm(m == 1 ? 0 : 1, x, b, m);
}

/**
 * @brief Discrete Logarithm(離散対数)
 * @docs docs/math/DiscreteLogarithm.md
 */
