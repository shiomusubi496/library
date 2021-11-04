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