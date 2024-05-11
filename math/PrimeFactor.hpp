#pragma once

#include "../other/template.hpp"

class PrimeFactor {
private:
    int MAX;
    std::vector<int> era, primes;

public:
    PrimeFactor(int MAX) : MAX(MAX), era(MAX + 1, -1), primes() {
        rep (i, 2, MAX + 1) {
            if (era[i] == -1) {
                era[i] = i;
                primes.push_back(i);
            }
            for (const auto& p : primes) {
                if (i * p > MAX) break;
                era[i * p] = p;
            }
        }
    }
    bool is_prime(int x) const { return era[x] == x; }
    int get_factor(int x) const { return era[x]; }
    std::vector<int> factorize(int x) const {
        std::vector<int> res;
        for (; x > 1; x /= era[x]) res.push_back(era[x]);
        return res;
    }
    const std::vector<int>& get_primes() const& { return primes; }
    std::vector<int> get_primes() && { return std::move(primes); }
};

class IsPrime {
private:
    int MAX;
    std::vector<bool> era;
    std::vector<int> primes;

public:
    IsPrime(int MAX) : MAX(MAX), era(MAX + 1, true), primes() {
        era[0] = era[1] = false;
        rep (i, 2, MAX + 1) {
            if (era[i]) primes.push_back(i);
            for (const auto& p : primes) {
                if (i * p > MAX) break;
                era[i * p] = false;
            }
        }
    }
    bool is_prime(int x) { return era[x]; }
    const std::vector<int>& get_primes() const& { return primes; }
    std::vector<int> get_primes() && { return std::move(primes); }
};

/**
 * @brief PrimeFactor(エラトステネスの篩)
 * @docs docs/math/PrimeFactor.md
 */
