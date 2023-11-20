#pragma once

#include "../other/template.hpp"

class PrimeFactor {
private:
    ll MAX;
    std::vector<ll> era, primes;

public:
    PrimeFactor(ll MAX) : MAX(MAX), era(MAX + 1, -1), primes() {
        rep (i, 2, MAX + 1) {
            if (era[i] == -1) {
                era[i] = i;
                primes.push_back(i);
            }
            each_const (p : primes) {
                if (i * p > MAX) break;
                era[i * p] = p;
            }
        }
    }
    bool is_prime(ll x) const { return era[x] == x; }
    std::vector<ll> factorize(ll x) const {
        std::vector<ll> res;
        for (; x > 1; x /= era[x]) res.push_back(era[x]);
        return res;
    }
    const std::vector<ll>& get_primes() const& { return primes; }
    std::vector<ll> get_primes() && { return std::move(primes); }
};

class IsPrime {
private:
    ll MAX;
    std::vector<bool> era;
    std::vector<ll> primes;

public:
    IsPrime(ll MAX) : MAX(MAX), era(MAX + 1, true), primes() {
        era[0] = era[1] = false;
        rep (i, 2, MAX + 1) {
            if (era[i]) primes.push_back(i);
            each_const (p : primes) {
                if (i * p > MAX) break;
                era[i * p] = false;
            }
        }
    }
    bool is_prime(ll x) { return era[x]; }
    const std::vector<ll>& get_primes() const& { return primes; }
    std::vector<ll> get_primes() && { return std::move(primes); }
};

/**
 * @brief PrimeFactor(エラトステネスの篩)
 * @docs docs/math/PrimeFactor.md
 */
