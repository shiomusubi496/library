#pragma once

#include "../../other/template.hpp"
#include "../Graph.hpp"

template<class T>
Edges<T> Restore(const Graph<T>& G, const std::vector<T>& dist, int start = 0) {
    const int N = G.size();
    Edges<T> res(N, edge<T>{-2, -2});
    res[start] = {-1, start};
    std::queue<int> que;
    que.push(start);
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        each_const (e : G[v]) {
            if (res[e.to].to == -2 && dist[e.to] == dist[v] + e.cost) {
                res[e.to] = e;
                que.push(e.to);
            }
        }
    }
    return res;
}

template<class T>
Edges<T> RestorePath(const Graph<T>& G, const std::vector<T>& dist, int s,
                     int t) {
    const Graph<T> RG = ReverseGraph(G);
    std::vector<bool> seen(G.size(), false);
    seen[t] = true;
    Edges<T> res;
    while (s != t) {
        bool flg = false;
        each_const (e : RG[t]) {
            if (!seen[e.to] && dist[e.to] + e.cost == dist[t]) {
                seen[e.to] = true;
                res.emplace_back(e.to, e.from, std::move(e.cost), e.idx);
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
