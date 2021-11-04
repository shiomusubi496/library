#pragma once

#include "../../template.hpp"
#include "../Graph.hpp"

template<class T> std::vector<int> Restore(const Graph<T>& G, const std::vector<T>& dist, int start = 0) {
    int N = G.size();
    std::vector<int> bfr(N, -2); bfr[start] = -1;
    std::queue<int> que; que.push(start);
    while (!que.empty()) {
        int v = que.front(); que.pop();
        for (const edge<T>& e : G[v]) {
            if (bfr[e.to] == -2 && dist[e.to] == dist[v] + e.cost) {
                bfr[e.to] = v;
                que.push(e.to);
            }
        }
    }
    return bfr;
}

/**
 * @brief Restore(経路復元)
 * @docs docs/Restore.md
 */
