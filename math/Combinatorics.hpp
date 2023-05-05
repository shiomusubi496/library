#pragma once

#include "../other/template.hpp"
#include "ModInt.hpp"

template<class T> class IntCombinatorics {
private:
    static std::vector<T> factorial;

public:
    static void init(ll n) {
        const int b = factorial.size();
        if (n < b) return;
        factorial.resize(n + 1);
        rep (i, b, n + 1) factorial[i] = factorial[i - 1] * i;
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
        if (n < 0) return T(0);
        if (r < 0 || r > n) return T(0);
        init(n);
        return factorial[n] / factorial[n - r] / factorial[r];
    }
    static T homo(ll n, ll r) { return comb(n + r - 1, r); }
    static T small_perm(ll n, ll r) {
        if (r < 0 || r > n) return 0;
        chmin(r, n - r);
        T res = 1;
        reps (i, r) res *= n - r + i;
        return res;
    }
    static T small_comb(ll n, ll r) {
        if (r < 0 || r > n) return 0;
        chmin(r, n - r);
        init(r);
        T res = 1;
        reps (i, r) res *= n - r + i;
        return res / factorial[r];
    }
    static T small_homo(ll n, ll r) { return small_comb(n + r - 1, r); }
};

template<class T>
std::vector<T> IntCombinatorics<T>::factorial = std::vector<T>(1, 1);

template<class T> class Combinatorics {
private:
    static std::vector<T> factorial;
    static std::vector<T> factinv;

public:
    static void init(ll n) {
        chmax(n, 1000000);
        const int b = factorial.size();
        if (n < b) return;
        factorial.resize(n + 1);
        rep (i, b, n + 1) factorial[i] = factorial[i - 1] * i;
        factinv.resize(n + 1);
        factinv[n] = T(1) / factorial[n];
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
        if (n < 0) return 0;
        if (r < 0 || r > n) return 0;
        init(n);
        return factorial[n] * factinv[n - r] * factinv[r];
    }
    static T homo(ll n, ll r) { return comb(n + r - 1, r); }
    static T small_perm(ll n, ll r) {
        if (r < 0 || r > n) return 0;
        T res = 1;
        reps (i, r) res *= n - r + i;
        return res;
    }
    static T small_comb(ll n, ll r) {
        if (r < 0 || r > n) return 0;
        chmin(r, n - r);
        init(r);
        T res = factinv[r];
        reps (i, r) res *= n - r + i;
        return res;
    }
    static T small_homo(ll n, ll r) { return small_comb(n + r - 1, r); }
};

template<class T>
std::vector<T> Combinatorics<T>::factorial = std::vector<T>(1, 1);
template<class T>
std::vector<T> Combinatorics<T>::factinv = std::vector<T>(1, 1);

/**
 * @brief Combinatorics
 * @docs docs/math/Combinatorics.md
 */
