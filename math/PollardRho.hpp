#pragma once

#include "../other/template.hpp"
#include "../random/Random.hpp"
#include "MontgomeryModInt.hpp"
#include "MillerRabin.hpp"
#include "../string/RunLength.hpp"

template<class T, class Rnd> ull pollard_rho(ull n, Rnd& rnd) {
    if (~n & 1) return 2;
    if (T::get_mod() != n) T::set_mod(n);
    T c, one = 1;
    auto f = [&](T x) -> T { return x * x + c; };
    constexpr int M = 128;
    while (1) {
        c = rnd.uniform(1ull, n - 1);
        T x = rnd.uniform(2ull, n - 1), y = x;
        ull g = 1;
        while (g == 1) {
            T p = one, tx = x, ty = y;
            rep (M) {
                x = f(x);
                y = f(f(y));
                p *= x - y;
            }
            g = gcd(p.get(), n);
            if (g == 1) continue;
            rep (M) {
                tx = f(tx);
                ty = f(f(ty));
                g = gcd((tx - ty).get(), n);
                if (g != 1) {
                    if (g != n) return g;
                    break;
                }
            }
        }
    }
    return -1;
}

template<class T = MontgomeryModInt<ull, -3>, class Rnd = Random64>
std::vector<ull> factorize(ull n, Rnd& rnd = rand64) {
    if (n == 1) return {};
    std::vector<ull> res;
    std::vector<ull> st = {n};
    while (!st.empty()) {
        ull t = st.back();
        st.pop_back();
        if (t == 1) continue;
        if (is_prime_mr(t)) {
            res.push_back(t);
            continue;
        }
        ull f = pollard_rho<T>(t, rnd);
        st.push_back(f);
        st.push_back(t / f);
    }
    std::sort(all(res));
    return res;
}

template<class T = MontgomeryModInt<ull, -3>, class Rnd = Random64>
std::vector<std::pair<ull, int>> expfactorize(ull n, Rnd& rnd = rand64) {
    auto f = factorize<T, Rnd>(n, rnd);
    return RunLength(f);
}

std::vector<ll> divisors_pr(ll n) {
    std::vector<ll> res;
    auto r = expfactorize(n);
    int m = r.size();
    rec_lambda([&](auto&& self, int k, ll d) -> void {
        if (k == m) {
            res.push_back(d);
            return;
        }
        ll t = d;
        rep (r[k].second) {
            self(k + 1, d);
            d *= r[k].first;
        }
        self(k + 1, d);
        d = t;
    })(0, 1);
    std::sort(all(res));
    return res;
}

/**
 * @brief PollardRho(素因数分解)
 * @docs docs/math/PollardRho.md
 */
