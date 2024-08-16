#pragma once

#include "../other/template.hpp"

template<class F>
std::vector<typename function_traits<F>::result_type> simple_larsch(int n,
                                                                    F&& f) {
    using T = typename function_traits<F>::result_type;
    std::vector<T> dp(n, INF<T>);
    std::vector<int> argmin(n, 0);
    auto g = [&](int i, int j) {
        if (chmin(dp[i], dp[j] + f(j, i))) argmin[i] = j;
    };
    dp[0] = 0;
    g(n - 1, 0);
    rec_lambda([&](auto& self, int l, int r) -> void {
        if (l == r) return;
        if (l + 1 == r) return;
        int m = (l + r) / 2;
        rep (k, argmin[l], argmin[r] + 1) g(m, k);
        self(l, m);
        rep (k, l + 1, m + 1) g(r, k);
        self(m, r);
    })(0, n - 1);
    return dp;
}
