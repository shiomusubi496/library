#pragma once

#include "../../other/template.hpp"
#include "../Graph.hpp"
#include "../shortest-path/Restore.hpp"

template<class T> class TreeDiameter {
  protected:
    const Graph<T>& G;
    int s, t;
    std::vector<T> dist;
    void dfs(int v, int p) {
        each_const (e : G[v]) {
            if (e.to == p) continue;
            dist[e.to] = dist[v] + e.cost;
            dfs(e.to, v);
        }
    }
    void init() {
        dist.resize(G.size()); dist[0] = 0;
        dfs(0, -1);
        s = std::max_element(all(dist)) - dist.begin();
        dist[s] = 0;
        dfs(s, -1);
        t = std::max_element(all(dist)) - dist.begin();
    }
  public:
    TreeDiameter(const Graph<T>& G) : G(G) { init(); }
    T diameter() const { return dist[t]; }
    std::pair<int, int> get_pair() const { return {s, t}; }
    Edges<T> get_path() const { return RestorePath(G, dist, s, t); }
};

/**
 * @brief TreeDiameter(木の直径)
 * @docs docs/TreeDiameter.md
 */
