#pragma once

#include "../template.hpp"
#include "ModInt.hpp"

template<class T> class Combinatorics {
  protected:
    static std::vector<T> factorial;
  public:
    static void init(ll n) {
        factorial.reserve(n + 1);
        while ((ll)factorial.size() <= n) factorial.push_back(factorial.back() * factorial.size());
    }
    static T fact(ll x) {
        init(x);
        return factorial[x];
    }
    static T perm(ll n, ll r) {
        if (r < 0 || r > n) return T(0);
        init(n);
        return factorial[n] / factorial[n - r];
    }
    static T comb(ll n, ll r) {
        if (r < 0 || r > n) return T(0);
        init(n);
        return factorial[n] / factorial[n - r] / factorial[r];
    }
    static T homo(ll n, ll r) {
        return comb(n + r - 1, r);
    }
};

template<class T> std::vector<T> Combinatorics<T>::factorial = std::vector<T>(1, 1);

template<class T, std::enable_if_t<is_ModInt<T>::value>* = nullptr> class ModCombinatorics : Combinatorics<T> {};

template<class T> class ModCombinatorics<T> : public Combinatorics<T> {
  protected:
    using Combinatorics<T>::factorial;
    static std::vector<T> factinv;
  public:
    static void init(ll n) {
        int b = factorial.size();
        if (n < b) return;
        Combinatorics<T>::init(n);
        factinv.resize(n + 1);
        factinv[n] = factorial[n].inv();
        rreps (i, n, b) factinv[i - 1] = factinv[i] * i;
    }
    static T fact(ll x) {
        init(x);
        return factorial[x];
    }
    static T finv(ll x) {
        init(x);
        return factinv[x];
    }
    static T perm(ll n, ll r) {
        if (r < 0 || r > n) return 0;
        init(n);
        return factorial[n] * factinv[n - r];
    }
    static T comb(ll n, ll r) {
        if (r < 0 || r > n) return 0;
        init(n);
        return factorial[n] * factinv[n - r] * factinv[r];
    }
    static T homo(ll n, ll r) {
        return comb(n + r - 1, r);
    }
};

template<class T> std::vector<T> ModCombinatorics<T>::factinv = std::vector<T>(1, 1);

/**
 * @brief Combinatorics
 * @docs docs/Combinatorics
 */
