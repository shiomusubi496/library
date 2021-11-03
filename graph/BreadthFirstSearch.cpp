#pragma once

#include "../template.cpp"
#include "Graph.cpp"

template<class T> std::vector<T> BFS(const Graph<T>& G, int s = 0) {
    std::vector<T> dist(G.size(), -1);
    dist[s] = 0;
    std::queue<int> que;
    que.push(s);
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (const edge<T>& e : G[v]) {
            if (dist[e.to] == -1) {
                dist[e.to] = dist[v] + e.cost;
                que.push(e.to);
            }
        }
    }
    return dist;
}

/*
@brief BFS(幅優先探索)
@docs docs/BreadthFirstSearch.md
*/