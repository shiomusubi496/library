#pragma once

#include "../../other/template.hpp"
#include "../Graph.hpp"

template<class T> class EulerTourSubtree {
private:
    int n, cnt;
    std::vector<int> root;
    const Graph<T>& G;
    std::vector<std::pair<int, int>> idx;
    void dfs(int v, int p) {
        idx[v].first = cnt++;
        each_const (e : G[v]) {
            if (e.to != p) dfs(e.to, v);
        }
        idx[v].second = cnt;
    }
    void init() {
        n = G.size();
        idx.assign(n, {-1, -1});
        cnt = 0;
        each_const (r : root) dfs(r, -1);
        rep (i, n) {
            if (idx[i].first == -1) dfs(i, -1);
        }
    }

public:
    EulerTourSubtree(const Graph<T>& G, int root = 0) : root({root}), G(G) {
        init();
    }
    EulerTourSubtree(const Graph<T>& G, const std::vector<int>& root)
        : root(root), G(G) {
        init();
    }
    const std::pair<int, int>& get_idx(int k) const& { return idx[k]; }
    std::pair<int, int> get_idx(int k) && { return std::move(idx[k]); }
    int get_par(int a, int b) const {
        return idx[a].first < idx[b].first ? a : b;
    }
    template<class F> void each_vertex_subtree(int v, const F& f) const {
        f(idx[v].first, idx[v].second);
    }
    template<class F> void each_edge_subtree(int v, const F& f) const {
        f(idx[v].first + 1, idx[v].second);
    }
};

/**
 * @brief EulerTourSubtree(オイラーツアー部分木クエリ)
 * @docs docs/graph/tree/EulerTourSubtree.md
 */
