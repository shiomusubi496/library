#pragma once

#include "../other/template.hpp"
#include "PrimeFactor.hpp"

// 1/a[i]   O(n + log p)
template<class T> std::vector<T> inv_enumerate(std::vector<T> a) {
    int n = a.size();
    std::vector<T> res(n + 1);
    res[0] = 1;
    rep (i, n) res[i + 1] = res[i] * a[i];
    T iv = 1 / res[n];
    res.pop_back();
    rrep (i, n) {
        res[i] *= iv;
        iv *= a[i];
    }
    return res;
}

// 0^m, 1^m, ..., n^m   O(n log m / log n)
template<class T> std::vector<T> pow_enumerate(int n, ll m) {
    if (m == 0) return std::vector<T>(n + 1, 1);
    std::vector<T> res(n + 1);
    res[0] = 0;
    res[1] = 1;
    PrimeFactor pf(n);
    rep (i, 2, n + 1) {
        if (pf.is_prime(i)) res[i] = T{i}.pow(m);
        else {
            ll x = pf.get_factor(i);
            res[i] = res[x] * res[i / x];
        }
    }
    return res;
}

/**
 * @brief PowEnumerate
 * @docs docs/math/PowEnumerate.md
 */