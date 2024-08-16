#pragma once

#include "../../other/template.hpp"
#include "../Graph.hpp"

template<class T> class BipartiteGraph {
private:
    int n;
    bool is_bip;
    const Graph<T>& G;
    std::vector<bool> used, label;
    int sz1, sz2;
    void dfs(int v) {
        used[v] = true;
        for (const auto& e : G[v]) {
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
        sz1 = sz2 = 0;
        rep (i, n) {
            if (!label[i]) ++sz1;
            else ++sz2;
        }
    }
    bool is_bipartite() const { return is_bip; }
    int size1() const { return sz1; }
    int size2() const { return sz2; }
    bool get_label(int k) const { return label[k]; }
    const std::vector<bool>& labels() const& { return label; }
    std::vector<bool> labels() && { return std::move(label); }
};

/**
 * @brief BipartiteGraph(二部グラフ判定)
 * @docs docs/graph/other/BipartiteGraph.md
 */
