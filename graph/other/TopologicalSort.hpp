#pragma once

#include "../../other/template.hpp"
#include "../Graph.hpp"

template<class T> class TopologicalSort {
private:
    int n;
    const Graph<T>& G;
    std::vector<int> ord;
    std::vector<bool> seen;
    void dfs(int v) {
        seen[v] = true;
        for (const auto& e : G[v]) {
            if (seen[e.to]) continue;
            dfs(e.to);
        }
        ord.push_back(v);
    }
    void init() {
        n = G.size();
        ord.reserve(n);
        seen.assign(n, false);
        rep (i, n) {
            if (seen[i]) continue;
            dfs(i);
        }
        std::reverse(all(ord));
    }

public:
    TopologicalSort(const Graph<T>& G) : G(G) { init(); }
    const std::vector<int>& get() const& { return ord; }
    std::vector<int> get() && { return std::move(ord); }
};

/**
 * @brief TopologicalSort(トポロジカルソート)
 * @docs docs/graph/other/TopologicalSort.md
 */
