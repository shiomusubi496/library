#pragma once

#include "../../other/template.hpp"
#include "../Graph.hpp"

template<class T> class TopologicalSort {
  protected:
    int n;
    const Graph<T>& G;
    std::vector<int> ord;
    std::vector<bool> seen;
    void dfs(int v) {
        seen[v] = true;
        for (const edge<T>& e : G[v]) {
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
    TopologicalSort(const Graph<T>& G_) { init(); }
    const std::vector<int>& get() const& { return ord; }
    std::vector<int> get() && { return std::move(ord); }
};

/**
 * @brief TopologicalSort(トポロジカルソート)
 * @docs docs/TopologicalSort.md
 */
