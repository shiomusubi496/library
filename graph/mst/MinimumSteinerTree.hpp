#pragma once

#include "../../other/template.hpp"
#include "../Graph.hpp"
#include "../../data-struct/unionfind/UnionFind.hpp"

template<class T> std::pair<T, Edges<T>> minimum_steiner_tree(Graph<T> G, std::vector<int> X) {
    int N = G.size(), K = X.size();
    std::vector<std::vector<T>> dp(1 << K, std::vector<T>(N, infinity<T>::value));
    std::vector<Edges<T>> prv1(1 << K, Edges<T>(N));
    std::vector<std::vector<int>> prv2(1 << K, std::vector<int>(N, -1));
    rep (i, N) {
        dp[0][i] = 0;
        prv2[0][i] = -2;
    }
    rep (i, K) {
        dp[1 << i][X[i]] = 0;
        prv2[1 << i][X[i]] = -2;
    }
    prique<std::pair<T, int>> que;
    rep (S, 1, 1 << K) {
        for (ll U = (S - 1) & S; U > (S ^ U); U = (U - 1) & S) {
            rep (i, N) {
                if (chmin(dp[S][i], dp[U][i] + dp[S ^ U][i])) {
                    prv2[S][i] = U;
                }
            }
        }
        rep (i, N) que.emplace(dp[S][i], i);
        while (!que.empty()) {
            T c = std::move(que.top().first);
            int v = que.top().second;
            que.pop();
            if (dp[S][v] != c) continue;
            for (const auto& e : G[v]) {
                if (chmin(dp[S][e.to], c + e.cost)) {
                    prv1[S][e.to] = e;
                    prv2[S][e.to] = -1;
                    que.emplace(dp[S][e.to], e.to);
                }
            }
        }
    }
    std::queue<std::pair<int, int>> que2;
    Edges<T> res;
    int v = std::min_element(all(dp.back())) - dp.back().begin();
    que2.emplace((1 << K) - 1, v);
    while (!que2.empty()) {
        auto [S, v] = que2.front();
        que2.pop();
        if (prv2[S][v] >= 0) {
            que2.emplace(prv2[S][v], v);
            que2.emplace(S ^ prv2[S][v], v);
        }
        else if (prv2[S][v] == -1) {
            res.push_back(prv1[S][v]);
            que2.emplace(S, prv1[S][v].from);
        }
    }
    return {*std::min_element(all(dp.back())), res};
}
