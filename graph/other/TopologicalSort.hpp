#pragma once

#include "../../template.hpp"
#include "../Graph.hpp"

template<class T> class TopologicalSort {
  protected:
    int n;
    Graph<T> G;
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
  public:
    TopologicalSort() = default;
    TopologicalSort(const Graph<T>& G_) { init(G_); }
    void init(const Graph<T>& G_) {
        G = G_;
        n = G.size();
        //ord.reserve(n);
        seen.assign(n, false);
        rep (i, n) {
            if (seen[i]) continue;
            dfs(i);
        }
        std::reverse(ord.begin(), ord.end());
    }
    std::vector<int> get() const { return ord; }
};

/**
 * @brief TopologicalSort(トポロジカルソート)
 * @docs docs/TopologicalSort.md
 */
