#pragma once

#include "../../other/template.hpp"
#include "../ModInt.hpp"
#include "Convolution.hpp"

template<class T>
std::vector<T> convolution_large(const std::vector<T>& a, const std::vector<T>& b) {
    int n = a.size(), m = b.size();
    int p = T::get_mod();
    if (n + m - 1 <= ((p - 1) & (1 - p))) return convolution(a, b);
    int lg = bitop::ceil_log2((p - 1) & (1 - p)) - 1;
    int mask = (1 << lg) - 1;
    int d1 = (n + mask) >> lg, d2 = (m + mask) >> lg;
    std::vector<std::vector<T>> c(d1, std::vector<T>(2 << lg));
    std::vector<std::vector<T>> d(d2, std::vector<T>(2 << lg));
    rep (i, n) c[i >> lg][i & mask] = a[i];
    rep (i, m) d[i >> lg][i & mask] = b[i];
    rep (i, d1) number_theoretic_transform(c[i]);
    rep (i, d2) number_theoretic_transform(d[i]);
    std::vector<T> ans((d1 + d2) << lg);
    rep (i, d1 + d2 - 1) {
        std::vector<T> e(2 << lg);
        rep (j, d1) {
            int k = i - j;
            if (k < 0 || k >= d2) continue;
            rep (l, 2 << lg) e[l] += c[j][l] * d[k][l];
        }
        inverse_number_theoretic_transform(e);
        rep (j, 2 << lg) ans[(i << lg) + j] += e[j];
    }
    ans.resize(n + m - 1);
    return ans;
}
