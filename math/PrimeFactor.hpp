#pragma once

#include "../template.hpp"

class PrimeFactor {
  protected:
    ll MAX;
    std::vector<ll> era;
  public:
    PrimeFactor(ll _MAX) : MAX(_MAX), era(MAX + 1, -1) {
        for (ll i = 2; i <= MAX; ++i) {
            if (era[i] != -1) continue;
            for (ll j = i; j <= MAX; j += i) era[j] = i;
        }
    }
    bool is_prime(ll x) { return era[x] == x; }
    std::vector<ll> factorize(ll x) {
        std::vector<ll> res;
        for (; x > 1; x /= era[x]) res.push_back(x);
        reverse(res.begin(), res.end());
        return res;
    }
};

class IsPrime {
  protected:
    ll MAX;
    std::vector<bool> era;
  public:
    IsPrime(ll _MAX) : MAX(_MAX), era(MAX + 1, true) {
        era[0] = era[1] = false;
        for (ll i = 2; i <= MAX; ++i) {
            if (!era[i]) continue;
            for (ll j = i * 2; j <= MAX; j += i) era[j] = false;
        }
    }
    bool is_prime(ll x) { return era[x]; }
};

/**
 * @brief PrimeFactor(エラトステネスの篩)
 * @docs docs/PrimeFactor.md
 */
