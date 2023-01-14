#pragma once

#include "../other/template.hpp"
#include "BarrettReduction.hpp"

template<class barrett> class PrimePowerModCombinatorics {
private:
    unsigned int p, e;
    barrett bar, bar2;
    std::vector<unsigned int> factorial, factinv;

public:
    PrimePowerModCombinatorics(unsigned int p_, unsigned int e_)
        : p(p_), e(e_), bar(my_pow(p, e)), bar2(p), factorial(1, 1),
          factinv(1, 1) {}

    unsigned int get_mod() const { return bar.get_mod(); }
    unsigned int get_prime() const { return p; }
    unsigned int get_power() const { return e; }

    void init(int n) {
        const int b = factorial.size();
        if (n < b) return;
        factorial.resize(n + 1);
        rep (i, b, n + 1) {
            if (i % p != 0) factorial[i] = bar.mul(factorial[i - 1], i);
            else factorial[i] = factorial[i - 1];
        }
        factinv.resize(n + 1);
        factinv[n] = mod_inv(factorial[n], bar.get_mod());
        rreps (i, n, b) {
            if (i % p != 0) factinv[i - 1] = bar.mul(factinv[i], i);
            else factinv[i - 1] = factinv[i];
        }
    }
    unsigned int comb(ll n, ll r) {
        if (r < 0 || r > n) return 0;
        if (n < 0) return 0;
        ll k = n - r;
        unsigned int res = 1;
        unsigned int e1 = 1, e2 = 0;
        for (unsigned int i = 0; n; ++i) {
            const int n1 = bar.rem(n), r1 = bar.rem(r), k1 = bar.rem(k);
            init(std::max({n1, r1, k1}));
            res = bar.mul(res, factorial[n1]);
            res = bar.mul(res, factinv[r1]);
            res = bar.mul(res, factinv[k1]);
            n = bar2.quo(n);
            r = bar2.quo(r);
            k = bar2.quo(k);
            if (n - r - k) {
                e1 *= p;
                if (e1 == bar.get_mod()) return 0;
                if (i + 1 >= e) ++e2;
            }
        }
        if ((e2 & 1) && (p != 2 || e == 2)) res = bar.get_mod() - res;
        return bar.mul(res, e1);
    }
};

template<class barrett = BarrettReduction> class ArbitraryModCombinatorics {
private:
    static std::vector<PrimePowerModCombinatorics<barrett>> ppmc;

    static std::vector<PLL> extgcds;

    static ll CRT(ll b1, ll m1, ll b2, ll m2, int k) {
        const PLL p = extgcds[k];
        const ll l = m1 * m2;
        const ll x = (b2 - b1) * p.first % m2;
        return (x * m1 + b1 + l) % l;
    }

public:
    static void set_mod(unsigned int m) {
        ppmc.clear();
        for (unsigned int i = 2; i * i <= m; ++i) {
            if (m % i == 0) {
                unsigned int e = 0;
                while (m % i == 0) {
                    m /= i;
                    ++e;
                }
                ppmc.emplace_back(i, e);
            }
        }
        if (m != 1) ppmc.emplace_back(m, 1);

        if (ppmc.empty()) return;
        extgcds.resize(ppmc.size() - 1);
        unsigned int prod = 1;
        rep (i, ppmc.size() - 1) {
            prod *= ppmc[i].get_mod();
            extgcds[i] = extGCD(prod, ppmc[i + 1].get_mod());
        }
    }

    static int comb(ll n, ll r) {
        if (r < 0 || r > n) return 0;
        if (n < 0) return 0;
        if (ppmc.empty()) return 0;
        unsigned int res = ppmc[0].comb(n, r), prod = ppmc[0].get_mod();
        rep (i, 1, ppmc.size()) {
            const unsigned int m = ppmc[i].comb(n, r);
            res = CRT(res, prod, m, ppmc[i].get_mod(), i - 1);
            prod *= ppmc[i].get_mod();
        }
        return res;
    }
};

template<class barrett>
std::vector<PrimePowerModCombinatorics<barrett>>
    ArbitraryModCombinatorics<barrett>::ppmc;

template<class barrett>
std::vector<PLL> ArbitraryModCombinatorics<barrett>::extgcds;

/**
 * @brief ArbitraryModCombinatorics(任意modCombination)
 * @docs docs/math/ArbitraryModCombinatorics.md
 * @see https://nyaannyaan.github.io/library/modulo/arbitrary-mod-binomial.hpp
 */
