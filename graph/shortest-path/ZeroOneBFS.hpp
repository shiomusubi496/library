#pragma once

#include "../../other/template.hpp"
#include "../Graph.hpp"

template<class T> std::vector<T> ZeroOneBFS(const Graph<T>& G, int start = 0) {
    assert(0 <= start && start < (int)G.size());
    std::vector<T> dist(G.size(), infinity<T>::value); dist[start] = 0;
    std::deque<std::pair<T, int>> que; que.emplace_front(0, start);
    while (!que.empty()) {
        T c = std::move(que.front().first);
        int v = std::move(que.front().second);
        que.pop_front();
        if (dist[v] != c) continue;
        each_const (e : G[v]) {
            if (e.cost == 0) {
                if (chmin(dist[e.to], c + e.cost)) que.emplace_front(dist[e.to], e.to);
            }
            else {
                if (chmin(dist[e.to], c + e.cost)) que.emplace_back(dist[e.to], e.to);
            }
        }
    }
    return dist;
}

/**
 * @brief ZeroOneBFS(01-BFS)
 * @docs docs/ZeroOneBFS.md
 */