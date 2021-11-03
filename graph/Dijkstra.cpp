#pragma once

#include "../template.cpp"
#include "Graph.cpp"

template<class T> std::vector<T> Dijkstra(const Graph<T>& G, int s = 0) {
    assert(0 <= s && s < G.size());
    std::vector<T> dist(G.size(), -1);
    dist[s] = 0;
    std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>, std::greater<std::pair<T, int>>> que;
    que.emplace(0, s);
    while (!que.empty()) {
        T c = que.top().first;
        int v = que.top().second;
        que.pop();
        if (dist[v] != c) continue;
        for (const edge<T>& e : G[v]) {
            if (dist[e.to] == -1 || dist[e.to] > c + e.cost) {
                dist[e.to] = c + e.cost;
                que.emplace(dist[e.to], e.to);
            }
        }
    }
    return dist;
}

/*
@brief Dijkstra(ダイクストラ法)
@docs docs/Dijkstra.md
*/