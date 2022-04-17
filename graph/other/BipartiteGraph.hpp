#pragma once

#include "../../other/template.hpp"
#include "../Graph.hpp"

template<class T> class BipartiteGraph {
  private:
    int n;
    bool is_bip;
    const Graph<T>& G;
    std::vector<bool> used, label;
    void dfs(int v) {
        used[v] = true;
        each_const (e : G[v]) {
            if (!used[e.to]) {
                used[e.to] = true;
                label[e.to] = !label[v];
                dfs(e.to);
            }
            else if (label[e.to] == label[v]) {
                is_bip = false;
            }
        }
    }
  public:
    BipartiteGraph(const Graph<T>& G) : G(G) {
        n = G.size();
        is_bip = true;
        label.assign(n, false);
        used.assign(n, false);
        rep (i, n) {
            if (!used[i]) dfs(i, -1);
        }
    }
    bool is_bipartite() const { return is_bip; }
    const std::vector<bool>& get_label() const& { return label; }
    std::vector<bool> get_label() && { return std::move(label); }
};

/**
 * @brief BipartiteGraph(二部グラフ判定)
 * @docs docs/BipartiteGraph.md
 */
