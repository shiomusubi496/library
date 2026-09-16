#pragma once

#include "../../other/template.hpp"
#include "Convolution.hpp"
#include "../num/PrimitiveRoot.hpp"

template<class T>
std::vector<T> multiplication_convolution(const std::vector<T>& a, const std::vector<T>& b) {
    const int n = a.size();
    assert(a.size() == b.size());
    ll g = primitive_root(n);
    std::vector<T> c(n - 1), d(n - 1);
    ll t = 1;
    rep (i, n - 1) {
        c[i] = a[t];
        d[i] = b[t];
        t = (t * g) % n;
    }
    std::vector<T> e = convolution(c, d);
    e.push_back(0);
    T sma = 0, smb = 0;
    rep (i, 1, n) {
        sma += a[i];
        smb += b[i];
    }
    std::vector<T> res(n);
    res[0] = a[0] * smb + b[0] * sma + a[0] * b[0];
    t = 1;
    rep (i, n - 1) {
        res[t] += e[i] + e[i + n - 1];
        t = (t * g) % n;
    }
    return res;
}
