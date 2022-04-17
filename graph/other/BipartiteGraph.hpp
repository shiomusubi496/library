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
            if (!used[i]) dfs(i);
        }
    }
    bool is_bipartite() const { return is_bip; }
    bool get_label(int k) const { return label[k]; }
    const std::vector<bool>& labels() const& { return label; }
    std::vector<bool> labels() && { return std::move(label); }
};

/**
 * @brief BipartiteGraph(二部グラフ判定)
 * @docs docs/BipartiteGraph.md
 */
