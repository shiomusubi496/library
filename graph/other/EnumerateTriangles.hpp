#pragma once

#include "../../other/template.hpp"
#include "../Graph.hpp"

template<class T>
std::vector<std::array<int, 3>> enumerate_triangles(const Graph<T>& G) {
    int n = G.size();
    std::vector<int> ord(n); std::iota(all(ord), 0);
    std::sort(all(ord), [&](int a, int b) { return G[a].size() < G[b].size(); });
    UnweightedGraph H(n);
    {
        std::vector<bool> used(n, false);
        each_const (i : ord) {
            each_const (e : G[i]) {
                if (!used[e.to]) H.add_edge(i, e.to, true);
            }
            used[i] = true;
        }
    }
    std::vector<std::array<int, 3>> res;
    std::vector<bool> used(n, false);
    rep (i, n) {
        each_const (e : H[i]) used[e.to] = true;
        each_const (e : H[i]) {
            each_const (f : H[e.to]) {
                if (used[f.to]) res.push_back({(int)i, e.to, f.to});
            }
        }
        each_const (e : H[i]) used[e.to] = false;
    }
    return res;
}

/**
 * @brief EnumerateTriangles
 * @docs docs/graph/other/EnumerateTriangles.md
 */
