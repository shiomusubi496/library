#pragma once

#include "../../other/template.hpp"
#include "../Graph.hpp"

template<class T> class DoublingLCA {
private:
    int n, h;
    std::vector<int> root;
    Graph<T> G_;
    const Graph<T>& G;
    std::vector<edge<T>> par;
    std::vector<int> dep;
    std::vector<std::vector<int>> dbl;
    void dfs_build(int v, int p) {
        for (const auto& e : G[v]) {
            if (e.to != p) {
                par[e.to] = edge<T>(e.to, e.from, e.cost, e.idx);
                dep[e.to] = dep[v] + 1;
                dfs_build(e.to, v);
            }
        }
    }
    void init() {
        n = G.size();
        h = bitop::ceil_log2(n) + 1;
        par.resize(n);
        dep.assign(n, -1);
        for (int r : root) {
            par[r] = edge<T>{};
            dep[r] = 0;
            dfs_build(r, -1);
        }
        rep (i, n) {
            if (dep[i] != -1) continue;
            par[i] = edge<T>{};
            dep[i] = 0;
            dfs_build(i, -1);
        }
        dbl.assign(n, std::vector<int>(h, -1));
        rep (i, n) dbl[i][0] = par[i].to;
        rep (i, h - 1) {
            rep (j, n) dbl[j][i + 1] = dbl[j][i] == -1 ? -1 : dbl[dbl[j][i]][i];
        }
    }

public:
    DoublingLCA(const Graph<T>& G, int r = 0) : root({r}), G(G) { init(); }
    DoublingLCA(Graph<T>&& G, int r = 0) : root({r}), G_(std::move(G)), G(G_) {
        init();
    }
    DoublingLCA(const Graph<T>& G, const std::vector<int>& r) : root(r), G(G) {
        init();
    }
    DoublingLCA(Graph<T>&& G, const std::vector<int>& r)
        : root(r), G_(std::move(G)), G(G_) {
        init();
    }
    int depth(int v) const { return dep[v]; }
    int parent(int v) const { return par[v].to; }
    int kth_ancestor(int v, int k) const {
        if (dep[v] < k) return -1;
        rrep (i, h) {
            if ((k >> i) & 1) v = dbl[v][i];
        }
        return v;
    }
    int kth_pow_of_2_ancestor(int v, int k) const {
        if (k >= h) return -1;
        return dbl[v][k];
    }
    int next_vertex(int s, int t) const {
        assert(s != t);
        if (dep[s] >= dep[t]) return parent(s);
        int u = kth_ancestor(t, dep[t] - dep[s] - 1);
        return parent(u) == s ? u : parent(s);
    }
    int kth_next_vertex(int s, int t, int k) const {
        int l = lca(s, t);
        int d = dep[s] + dep[t] - 2 * dep[l];
        if (d < k) return -1;
        if (dep[s] - dep[l] >= k) return kth_ancestor(s, k);
        return kth_ancestor(t, d - k);
    }
    Edges<T> path(int s, int t) const {
        Edges<T> pre, suf;
        while (dep[s] > dep[t]) pre.push_back(par[s]), s = par[s].to;
        while (dep[t] > dep[s]) suf.push_back(par[t]), t = par[t].to;
        while (s != t) {
            pre.push_back(par[s]), s = par[s].to;
            suf.push_back(par[t]), t = par[t].to;
        }
        rrep (i, suf.size())
            pre.emplace_back(suf[i].to, suf[i].from, suf[i].cost, suf[i].idx);
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
    int dist(int u, int v) const {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }
};

/**
 * @brief DoublingLowestCommonAncestor(ダブリングによるLCA)
 * @docs docs/graph/tree/DoublingLowestCommonAncestor.md
 */
