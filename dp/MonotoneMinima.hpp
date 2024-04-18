#pragma once

#include "../other/template.hpp"

template<class F> std::vector<int> monotone_minima_cmp(int H, int W, F&& cmp) {
    std::vector<int> res(H);
    int x = 1;
    while (x <= H) x <<= 1;
    while (x >>= 1) {
        rep (i, x - 1, H, x << 1) {
            const int l = i - x < 0 ? 0 : res[i - x];
            const int r = i + x >= H ? W : res[i + x] + 1;
            res[i] = l;
            for (int j = l + 1; j < r; ++j) {
                if (cmp(i, j, res[i])) res[i] = j;
            }
        }
    }
    return res;
}

template<class F> std::vector<int> monotone_minima(int H, int W, F&& f) {
    return monotone_minima_cmp(
        H, W, [&](int i, int j, int k) { return f(i, j) < f(i, k); });
}

/**
 * @brief MonotoneMinima
 * @docs docs/dp/MonotoneMinima.md
 */
