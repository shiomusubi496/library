#pragma once

#include "../../template.hpp"
#include "../Graph.hpp"

template<class T> std::vector<T> BellmanFord(int V, const Edges<T>& Ed, int start = 0) {
    assert(0 <= start && start <= V);
    std::vector<T> dist(V, INF<T>); dist[start] = 0;
    rep (i, V) {
        bool changed = false;
        for (const edge<T>& e : Ed) {
            if (dist[e.from] != INF<T> && chmin(dist[e.to], dist[e.from] + e.cost)) changed = true;
        }
        if (!changed) return dist;
    }
    for (const edge<T>& e : Ed) {
        if (dist[e.from] != INF<T> && dist[e.to] > dist[e.from] + e.cost) dist[e.to] = -INF<T>;
    }
    rep (i, V - 1) {
        bool changed = false;
        for (const edge<T>& e : Ed) {
            if (dist[e.from] == -INF<T>){
                dist[e.to] = -INF<T>;
                changed = true;
            }
        }
        if (!changed) break;
    }
    return dist;
}

/**
 * @brief Bellman-Ford(ベルマンフォード法)
 * @docs docs/BellmanFord.md
 */
