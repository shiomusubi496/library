#pragma once

#include "../../other/template.hpp"
#include "../Graph.hpp"
#include "../shortest-path/Restore.hpp"
#include "Tree.hpp"

template<class T> class TreeDiameter {
  protected:
    Tree<T> G;
    int s, t;
    std::vector<T> dist;
    void dfs(int v, int p) {
        for (const edge<T>& e : G[v]) {
            if (e.to == p) continue;
            dist[e.to] = dist[v] + e.cost;
            dfs(e.to, v);
        }
    }
  public:
    TreeDiameter() = default;
    TreeDiameter(const Tree<T>& G_) { init(G_); }
    void init(const Tree<T>& G_) {
        G = G_;
        dist.resize(G.size()); dist[0] = 0;
        dfs(0, -1);
        s = std::max_element(all(dist)) - dist.begin();
        dist[s] = 0;
        dfs(s, -1);
        t = std::max_element(all(dist)) - dist.begin();
    }
    T diameter() const {
        return dist[t];
    }
    std::pair<int, int> get_pair() const {
        return {s, t};
    }
    Edges<T> get_path() const {
        return RestorePath(G, dist, s, t);
    }
};

/**
 * @brief TreeDiameter(木の直径)
 * @docs docs/TreeDiameter.md
 */
