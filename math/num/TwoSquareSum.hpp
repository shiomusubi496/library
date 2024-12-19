#pragma once

#include "../other/template.hpp"
#include "num/PollardRho.hpp"
#include "GaussianInteger.hpp"

std::pair<ll, ll> two_square_sum_prime(ll p) {
    assert(p == 2 || p % 4 == 1);
    if (p == 2) return {1, 1};
    auto mod_pow_ll = [&](i128 x, ll e) -> i128 {
        i128 res = 1;
        while (e) {
            if (e & 1) (res *= x) %= p;
            (x *= x) %= p;
            e /= 2;
        }
        return res;
    };
    ll x = 1;
    while (1) {
        ++x;
        ll t = mod_pow_ll(x, (p - 1) / 4);
        if (i128{t} * t % p == p - 1) {
            x = t;
            break;
        }
    }
    GaussianInteger<i128> a(p, 0), b(x, 1);
    a = gcd(a, b);
    assert(a.norm() == p);
    return {a.real, a.imag};
}

template<class T> std::vector<std::pair<T, T>> two_square_sum(T a) {
    if (a < 0) return {};
    if (a == 0) return {{0, 0}};
    using G = GaussianInteger<T>;
    const auto& pfs = expfactorize(a);
    for (const auto& [p, e] : pfs) {
        if (p % 4 == 3 && e % 2 == 1) return {};
    }
    std::vector<G> res{{1, 0}};
    for (const auto& [p, e] : pfs) {
        if (p % 4 == 3) {
            const T x = my_pow(p, e / 2);
            for (auto& g : res) {
                g.real *= x;
                g.imag *= x;
            }
            continue;
        }
        auto [px, py] = two_square_sum_prime(p);
        G pg(px, py);
        std::vector<G> gpows(e + 1);
        gpows[0] = 1;
        rep (i, e) gpows[i + 1] = gpows[i] * pg;
        if (p == 2) {
            for (auto&& g : res) g *= gpows[e];
            continue;
        }
        std::vector<G> gs(e + 1);
        rep (i, e + 1) gs[i] = gpows[i] * gpows[e - i].conj();
        std::vector<G> nres;
        for (auto g : gs) for (auto i : res) nres.push_back(g * i);
        res = std::move(nres);
    }
    for (auto&& g : res) {
        while (g.real <= 0 || g.imag < 0) g = {-g.imag, g.real};
    }
    std::vector<std::pair<T, T>> ans(res.size());
    rep (i, res.size()) ans[i] = {res[i].real, res[i].imag};
    return ans;
}
