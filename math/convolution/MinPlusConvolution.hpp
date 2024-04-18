#pragma once

#include "../../other/template.hpp"
#include "../../dp/SMAWK.hpp"

template<class T>
std::vector<T> min_plus_convolution(const std::vector<T> &a, const std::vector<T> &b) {
    int n = a.size(), m = b.size();
    // b must be convex
    rep (i, m - 2) assert(b[i + 1] - b[i] <= b[i + 2] - b[i + 1]);
    auto idx = smawk_comp(n + m - 1, n, [&](int i, int j, int k) {
        if (i - j < 0 || i - j >= m || i - k < 0 || i - k >= m) {
            return std::max(j - i - 1, i - j - m) < std::max(k - i - 1, i - k - m);
        }
        return a[j] + b[i - j] < a[k] + b[i - k];
    });
    std::vector<T> res(n + m - 1);
    rep (i, n + m - 1) res[i] = a[idx[i]] + b[i - idx[i]];
    return res;
}

/**
 * @brief Min Plus Convolution
 * @docs docs/convolution/MinPlusConvolution.md
 */
