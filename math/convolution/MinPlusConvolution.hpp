#pragma once

#include "../../other/template.hpp"
#include "../../dp/MonotoneMinima.hpp"

template<class T>
std::vector<T> min_plus_convolution_convex_convex(const std::vector<T>& a,  std::vector<T>& b) {
    int n = a.size(), m = b.size();
    if (n == 0 || m == 0) return {};
    rep (i, n - 2) assert(a[i + 1] - a[i] <= a[i + 2] - a[i + 1]);
    rep (i, m - 2) assert(b[i + 1] - b[i] <= b[i + 2] - b[i + 1]);
    std::vector<T> res(n + m - 1);
    int j = 0, k = 0;
    rep (i, n + m - 1) {
        res[i] = a[j] + b[k];
        if (j == n - 1) ++k;
        else if (k == m - 1) ++j;
        else if (a[j + 1] - a[j] <= b[k + 1] - b[k]) ++j;
        else ++k;
    }
    return res;
}

template<class T>
std::vector<T> min_plus_convolution(std::vector<T> a, std::vector<T> b) {
    int n = a.size(), m = b.size();
    if (n == 0 || m == 0) return {};
    // b must be convex
    bool is_a_convex = true;
    bool is_b_convex = true;
    rep (i, n - 2) if (a[i + 1] - a[i] > a[i + 2] - a[i + 1]) is_a_convex = false;
    rep (i, m - 2) if (b[i + 1] - b[i] > b[i + 2] - b[i + 1]) is_b_convex = false;
    assert(is_a_convex || is_b_convex);
    if (is_a_convex && is_b_convex) {
        return min_plus_convolution_convex_convex(a, b);
    }
    if (is_a_convex) {
        std::swap(a, b);
        std::swap(n, m);
    }
    auto idx = monotone_minima_comp(n + m - 1, n, [&](int i, int j, int k) {
        if (i - j < 0 || i - j >= m || i - k < 0 || i - k >= m) {
            return std::max(j - i - 1, i - j - m) <
                   std::max(k - i - 1, i - k - m);
        }
        return a[j] + b[i - j] < a[k] + b[i - k];
    });
    std::vector<T> res(n + m - 1);
    rep (i, n + m - 1) res[i] = a[idx[i]] + b[i - idx[i]];
    return res;
}

/**
 * @brief Min Plus Convolution
 * @docs docs/math/convolution/MinPlusConvolution.md
 */
