#pragma once

#include "../other/template.hpp"
#include "SMAWK.hpp"

template<class F>
std::vector<typename function_traits<F>::result_type> online_offline_dp(int n,
                                                                        F&& f) {
    using T = typename function_traits<F>::result_type;
    std::vector<T> dp(n, INF<T>);
    dp[0] = 0;
    rec_lambda([&](auto& self, int l, int r) -> void {
        if (l == r) return;
        if (l + 1 == r) return;
        int m = (l + r) / 2;
        self(l, m);
        auto g = [&](int i, int j) { return dp[j + l] + f(j + l, i + m); };
        auto res = smawk(r - m, m - l, g);
        rep (i, m, r) chmin(dp[i], g(i - m, res[i - m]));
        self(m, r);
    })(0, n);
    return dp;
}

/**
 * @brief Online Offline DP
 * @docs docs/dp/OnlineOfflineDP.md
 */
