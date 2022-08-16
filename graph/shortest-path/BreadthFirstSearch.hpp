#pragma once

#include "../../other/template.hpp"
#include "../Graph.hpp"

template<class T> std::vector<T> BFS(const Graph<T>& G, int start = 0) {
    assert(0 <= start && start < (int)G.size());
    std::vector<T> dist(G.size(), -1);
    dist[start] = 0;
    std::queue<int> que;
    que.push(start);
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        each_const (e : G[v]) {
            if (dist[e.to] == -1) {
                dist[e.to] = dist[v] + e.cost;
                que.push(e.to);
            }
        }
    }
    return dist;
}

template<class T> std::vector<T> BFSedge(const Graph<T>& G, int start = 0) {
    assert(0 <= start && start < (int)G.size());
    std::vector<T> dist(G.size(), -1);
    dist[start] = 0;
    std::queue<int> que;
    que.push(start);
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        each_const (e : G[v]) {
            if (dist[e.to] == -1) {
                dist[e.to] = dist[v] + 1;
                que.push(e.to);
            }
        }
    }
    return dist;
}

/**
 * @brief BFS(幅優先探索)
 * @docs docs/graph/shortest-path/BreadthFirstSearch.md
 */
