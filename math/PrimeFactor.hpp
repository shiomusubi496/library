#pragma once

#include "../other/template.hpp"

class PrimeFactor {
  protected:
    ll MAX;
    std::vector<ll> era;
  public:
    PrimeFactor(ll MAX) : MAX(MAX), era(MAX + 1, -1) {
        rep (i, 2, MAX + 1) {
            if (era[i] != -1) continue;
            rep (j, i, MAX + 1, i) era[j] = i;
        }
    }
    bool is_prime(ll x) {
        return era[x] == x;
    }
    std::vector<ll> factorize(ll x) {
        std::vector<ll> res;
        for (; x > 1; x /= era[x]) res.push_back(era[x]);
        reverse(all(res));
        return res;
    }
    std::vector<ll> get_primes(ll m) {
        std::vector<ll> res;
        reps (i, MAX) {
            if (era[i] == i) res.push_back(i);
        }
        return res;
    }
};

class IsPrime {
  protected:
    ll MAX;
    std::vector<bool> era;
  public:
    IsPrime(ll MAX) : MAX(MAX), era(MAX + 1, true) {
        era[0] = era[1] = false;
        rep (i, 2, MAX + 1) {
            if (!era[i]) continue;
            rep (j, i * 2, MAX + 1, i) era[j] = false;
        }
    }
    bool is_prime(ll x) {
        return era[x];
    }
    std::vector<ll> get_primes(ll m) {
        std::vector<ll> res;
        reps (i, MAX) {
            if (era[i]) res.push_back(i);
        }
        return res;
    }
};

/**
 * @brief PrimeFactor(エラトステネスの篩)
 * @docs docs/PrimeFactor.md
 */
