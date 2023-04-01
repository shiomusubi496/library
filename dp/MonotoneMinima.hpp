#pragma once

#include "../other/template.hpp"

template<class F> std::vector<int> monotone_minima(int H, int W, F&& f) {
    std::vector<int> res(H);
    int x = 1;
    while (x <= H) x <<= 1;
    while (x >>= 1) {
        rep (i, x - 1, H, x << 1) {
            const int l = i - x < 0 ? 0 : res[i - x];
            const int r = i + x >= H ? W : res[i + x] + 1;
            res[i] = l;
            for (int j = l + 1; j < r; ++j) {
                if (f(i, res[i]) > f(i, j)) res[i] = j;
            }
        }
    }
    return res;
}

/**
 * @brief MonotoneMinima
 * @docs docs/dp/MonotoneMinima.md
 */
