#pragma once

#include "../../other/template.hpp"
#include "../../other/bitop.hpp"
#include "../Graph.hpp"

template<class T> class Tree {
  protected:
    int root, n, h;
    Graph<T> G_;
    const Graph<T>& G;
    std::vector<edge<T>> par;
    std::vector<int> dep;
    std::vector<std::vector<int>> dbl;
    void dfs_build(int v, int p) {
        for (const edge<T>& e : G[v]) {
            if (e.to != p) {
                par[e.to] = edge<T>(e.to, e.from, e.cost, e.idx);
                dep[e.to] = dep[v] + 1;
                dfs_build(e.to, v);
            }
        }
    }
    void init() {
        n = G.size();
        h = bitop::ceil_log2(n);
        par.resize(n); par[root] = edge<T>{};
        dep.resize(n); dep[root] = 0;
        dfs_build(root, -1);
        dbl.assign(n, std::vector<int>(h, -1));
        rep (i, n) dbl[i][0] = par[i].to;
        rep (i, h - 1) {
            rep (j, n) dbl[j][i + 1] = dbl[j][i] == -1 ? -1 : dbl[ dbl[j][i] ][i];
        }
    }
  public:
    Tree(const Graph<T>& G, int r = 0) : G(G), root(r) { init(); }
    Tree(Graph<T>&& G, int r = 0) : G_(std::move(G)), G(G_), root(r) { init(); }
    int depth(int v) const { return dep[v]; }
    int parent(int v) const { return par[v].to; }
    int kth_ancestor(int v, int k) const {
        if (dep[v] < k) return -1;
        rrep (i, h) {
            if ((k >> i) & 1) v = dbl[v][i];
        }
        return v;
    }
    int nxt(int s, int t) const {
        assert(s != t);
        if (dep[s] >= dep[t]) return parent(s);
        int v = kth_ancestor(t, dep[t] - dep[s] - 1);
        return parent(v) == s ? v : parent(s);
    }
    Edges<T> path(int s, int t) const {
        Edges<T> pre, suf;
        while (dep[s] > dep[t]) pre.push_back(par[s]), s = par[s].to;
        while (dep[t] > dep[s]) suf.push_back(par[t]), t = par[t].to;
        while (s != t) {
            pre.push_back(par[s]), s = par[s].to;
            suf.push_back(par[t]), t = par[t].to;
        }
        rrep (i, suf.size()) pre.emplace_back(suf[i].to, suf[i].from, suf[i].cost, suf[i].idx);
        return pre;
    }
    int lca(int u, int v) const {
        if (dep[u] > dep[v]) u = kth_ancestor(u, dep[u] - dep[v]);
        if (dep[u] < dep[v]) v = kth_ancestor(v, dep[v] - dep[u]);
        if (u == v) return u;
        rrep (i, h) {
            if (dbl[u][i] != dbl[v][i]) {
                u = dbl[u][i];
                v = dbl[v][i];
            }
        }
        return parent(u);
    }
    Graph<T> rooted() const {
        Graph<T> res(G.size());
        rep (i, G.size()) {
            if (i == root) res[i].reserve(G[i].size());
            else res[i].reserve(G[i].size() - 1);
            for (const edge<T>& e : G[i]) {
                if (e.to != par[i].to) res[i].push_back(e);
            }
        }
        res.edge_id = G.edge_size();
        return res;
    }
};

/**
 * @brief Tree(木のクエリ詰め合わせ)
 * @docs docs/Tree.md
 */
