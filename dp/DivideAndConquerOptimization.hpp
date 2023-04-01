#pragma once

#include "../other/template.hpp"
#include "MonotoneMinima.hpp"
#include "SMAWK.hpp"

template<class F>
std::vector<std::vector<typename function_traits<F>::result_type>>
divide_and_conquer_optimization(int m, int n, F&& f) {
    using T = typename function_traits<F>::result_type;
    std::vector<std::vector<T>> dp(m + 1, std::vector<T>(n, INF<T>));
    dp[0][0] = 0;
    rep (i, m) {
        auto g = [&](int x, int y) {
            if (x < y) return INF<T>;
            return dp[i][y] + f(y, x);
        };
        std::vector<int> res = smawk(n, n, g);
        rep (j, n) dp[i + 1][j] = g(j, res[j]);
    }
    return dp;
}

template<class F>
std::vector<std::vector<typename function_traits<F>::result_type>>
divide_and_conquer_optimization_monotone(int m, int n, F&& f) {
    using T = typename function_traits<F>::result_type;
    std::vector<std::vector<T>> dp(m + 1, std::vector<T>(n, INF<T>));
    dp[0][0] = 0;
    rep (i, m) {
        auto g = [&](int x, int y) {
            if (x < y) return INF<T>;
            return dp[i][y] + f(y, x);
        };
        std::vector<int> res = monotone_minima(n, n, g);
        rep (j, n) dp[i + 1][j] = g(j, res[j]);
    }
    return dp;
}

/**
 * @brief Divide and Conquer Optimization
 * @docs docs/dp/DivideAndConquerOptimization.md
 */
