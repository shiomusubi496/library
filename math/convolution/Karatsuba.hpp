#pragma once

#include "../../other/template.hpp"

template<class T>
std::vector<T> karatsuba(std::vector<T> a, std::vector<T> b) {
    int n = a.size(), m = b.size();
    if (n <= 100 || m <= 100) {
        std::vector<T> c(n + m - 1);
        rep (i, n) rep (j, m) c[i + j] += a[i] * b[j];
        return c;
    }
    int k = std::max<int>(n, m) / 2 + 1;
    std::vector<T> a0(k), a1(k), b0(k), b1(k);
    rep (i, n) {
        if (i < k) a0[i] = a[i];
        else a1[i - k] = a[i];
    }
    rep (i, m) {
        if (i < k) b0[i] = b[i];
        else b1[i - k] = b[i];
    }
    std::vector<T> a2(k), b2(k);
    rep (i, k) a2[i] = a0[i] + a1[i];
    rep (i, k) b2[i] = b0[i] + b1[i];
    std::vector<T> c0 = karatsuba(a0, b0);
    std::vector<T> c1 = karatsuba(a2, b2);
    std::vector<T> c2 = karatsuba(a1, b1);
    std::vector<T> c(4 * k - 1);
    rep (i, 2 * k - 1) c[i] += c0[i];
    rep (i, 2 * k - 1) c[i + k] += c1[i] - c0[i] - c2[i];
    rep (i, 2 * k - 1) c[i + k * 2] += c2[i];
    c.resize(n + m - 1);
    return c;
}
