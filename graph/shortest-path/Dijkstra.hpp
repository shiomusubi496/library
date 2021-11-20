#pragma once

#include "../../other/template.hpp"
#include "../Graph.hpp"

template<class T> std::vector<T> Dijkstra(const Graph<T>& G, int start = 0) {
    assert(0 <= start && start < (int)G.size());
    std::vector<T> dist(G.size(), infinity<T>::value); dist[start] = 0;
    prique<std::pair<T, int>> que; que.emplace(0, start);
    while (!que.empty()) {
        T c = que.top().first;
        int v = que.top().second;
        que.pop();
        if (dist[v] != c) continue;
        for (const edge<T>& e : G[v]) {
            if (chmin(dist[e.to], c + e.cost)) que.emplace(dist[e.to], e.to);
        }
    }
    return dist;
}

/**
 * @brief Dijkstra(ダイクストラ法)
 * @docs docs/Dijkstra.md
 */
