#pragma once

#include "../other/template.hpp"

template<class F> std::vector<int> smawk_comp(int H, int W, F&& cmp) {
    std::vector<int> row(H), col(W);
    std::iota(all(row), 0);
    std::iota(all(col), 0);
    return rec_lambda([&](auto&& self, const std::vector<int>& row,
                          const std::vector<int>& col) -> std::vector<int> {
        const int n = row.size();
        if (n == 0) return {};
        std::vector<int> ncol;
        ncol.reserve(n);
        for (int i : col) {
            while (!ncol.empty() && cmp(row[ncol.size() - 1], i, ncol.back()))
                ncol.pop_back();
            if ((int)ncol.size() < n) ncol.push_back(i);
        }
        std::vector<int> row_odd;
        row_odd.reserve(n / 2 + 1);
        rep (i, 1, n, 2) row_odd.push_back(row[i]);
        const std::vector<int> ans = self(row_odd, ncol);
        std::vector<int> res(n);
        rep (i, row_odd.size()) res[i * 2 + 1] = ans[i];
        int j = 0;
        rep (i, 0, n, 2) {
            const int last = i == n - 1 ? ncol.back() : res[i + 1];
            res[i] = ncol[j];
            while (ncol[j] < last) {
                ++j;
                if (cmp(row[i], ncol[j], res[i])) res[i] = ncol[j];
            }
        }
        return res;
    })(row, col);
}

template<class F> std::vector<int> smawk(int H, int W, F&& f) {
    return smawk_comp(H, W,
                      [&](int i, int j, int k) { return f(i, j) < f(i, k); });
}

/**
 * @brief SMAWK
 * @docs docs/dp/SMAWK.md
 */
