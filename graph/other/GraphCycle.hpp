#pragma once

#include "../../other/template.hpp"
#include "../Graph.hpp"

template<class T> class GraphCycle {
  protected:
    const Graph<T>& G;
    std::vector<bool> visited, seen;
    Edges<T> cycle;
    int dfs(int v, int k) {
        if (seen[v]) return v;
        if (visited[v]) return -1;
        visited[v] = seen[v] = true;
        each_const (e : G[v]) {
            int d = dfs(e.to, v);
            if (d != -1) {
                if (d == -2) return -2;
                cycle.push_back(e);
                if (d == v) return -2;
                return d;
            }
        }
        seen[v] = false;
        return -1;
    }
    void init() {
        const int N = G.size();
        visited.assign(N, false);
        seen.assign(N, false);
        rep (i, N) {
            if (dfs(i, -1) == -2) {
                std::reverse(all(cycle));
                break;
            }
        }
    }
  public:
    GraphCycle(const Graph<T>& G) : G(G) { init(); }
    bool has_cycle() const { return !cycle.empty(); }
    const Edges<T>& get_cycle() const& { return cycle; }
    Edges<T> get_cycle() && { return std::move(cycle); }
};

/**
 * @brief GraphCycle(閉路検出)
 * @docs docs/GraphCycle.md
 */
