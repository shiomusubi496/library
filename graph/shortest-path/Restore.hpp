#pragma once

#include "../../other/template.hpp"
#include "../Graph.hpp"

template<class T> std::vector<int> Restore(const Graph<T>& G, const std::vector<T>& dist, int start = 0) {
    const int N = G.size();
    std::vector<int> bfr(N, -2); bfr[start] = -1;
    std::queue<int> que; que.push(start);
    while (!que.empty()) {
        int v = std::move(que.front()); que.pop();
        each_const (e : G[v]) {
            if (bfr[e.to] == -2 && dist[e.to] == dist[v] + e.cost) {
                bfr[e.to] = v;
                que.push(e.to);
            }
        }
    }
    return bfr;
}

template<class T> Edges<T> RestorePath(const Graph<T>& G, const std::vector<T>& dist, int s, int t) {
    const auto RG = ReverseGraph(G);
    std::vector<bool> seen(G.size(), false); seen[t] = true;
    Edges<T> res;
    while (s != t) {
        bool flg = false;
        each_const (e : RG[t]) {
            if (!seen[e.to] && dist[e.to] + e.cost == dist[t]) {
                seen[e.to] = true;
                res.push_back(e); std::swap(res.back().from, res.back().to);
                t = e.to;
                flg = true;
                break;
            }
        }
        assert(flg);
    }
    std::reverse(all(res));
    return res;
}

/**
 * @brief Restore(経路復元)
 * @docs docs/Restore.md
 */
