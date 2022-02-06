#pragma once

#include "../../other/template.hpp"
#include "../Graph.hpp"

template<class T> class HeavyLightDecomposition {
  protected:
    int n, root, cnt;
    std::vector<int> ssz, head, vin, vout, par;
    const Graph<T>& G;
    int szdfs(int v, int p) {
        ssz[v] = 1;
        each_const (e : G[v]) {
            if (e.to == p) continue;
            ssz[v] += szdfs(e.to, v);
        }
        return ssz[v];
    }
    void bldfs(int v, int p) {
        par[v] = p;
        vin[v] = cnt++;
        int idx = -1;
        each_const (e : G[v]) {
            if (e.to != p) {
                if (idx == -1 || ssz[idx] < ssz[e.to]) idx = e.to;
            }
        }
        if (idx != -1) {
            head[idx] = head[v];
            bldfs(idx, v);
        }
        each_const (e : G[v]) {
            if (e.to != p && e.to != idx) {
                head[e.to] = e.to;
                bldfs(e.to, v);
            }
        }
        vout[v] = cnt;
    }
    void init() {
        n = G.size();
        ssz.resize(n);
        szdfs(root, -1);
        cnt = 0;
        head.resize(n); head[root] = root;
        vin.resize(n); vout.resize(n);
        par.resize(n);
        bldfs(root, -1);
    }
  public:
    HeavyLightDecomposition(const Graph<T>& G, int root = 0) : root(root), G(G) { init(); }
    std::pair<int, int> get_idx(int k) const { return {vin[k], vout[k]}; }
    std::pair<int, int> get_pach(int a, int b) const {
        if (vin[a] < vin[b]) return {a, b};
        return {b, a};
    }
    int lca(int u, int v) const {
        while (head[u] != head[v]) {
            if (vin[u] > vin[v]) std::swap(u, v);
            v = par[head[v]];
        }
        return vin[u] < vin[v] ? u : v;
    }
    std::vector<std::pair<int, int>> up_path(int u, int v) const {
        std::vector<std::pair<int, int>> res;
        while (head[u] != head[v]) {
            res.emplace_back(vin[u], vin[head[u]]);
            u = par[head[u]];
        }
        if (u != v) res.emplace_back(vin[u], vin[v] + 1);
        return res;
    }
    std::vector<std::pair<int, int>> down_path(int u, int v) const {
        auto res = up_path(v, u);
        each_for (p : res) std::swap(p.first, p.second);
        std::reverse(all(res));
        return res;
    }
    template<class F> void each_vertex(int u, int v, const F& f) const { return each_vertex(u, v, f, f); }
    template<class F, class G> void each_vertex(int u, int v, const F& f, const G& g) const {
        int l = lca(u, v);
        auto func = [&](int a, int b) {
            if (a <= b) f(a, b + 1);
            else g(b, a + 1);
        };
        each_const (p : up_path(u, l)) func(p.first, p.second);
        func(l, l);
        each_const (p : down_path(l, v)) func(p.first, p.second);
    }
    template<class F> void each_edge(int u, int v, const F& f) const { return each_edge(u, v, f, f); }
    template<class F, class G> void each_edge(int u, int v, const F& f, const G& g) const {
        int l = lca(u, v);
        auto func = [&](int a, int b) {
            if (a <= b) f(a, b + 1);
            else g(b, a + 1);
        };
        each_const (p : up_path(u, l)) func(p.first, p.second);
        each_const (p : down_path(l, v)) func(p.first, p.second);
    }
    template<class F> void each_vertex_subtree(int u, const F& f) const {
        f(vin[u], vout[u]);
    }
    template<class F> void each_edge_subtree(int u, const F& f) const {
        f(vin[u] + 1, vout[u]);
    }
};
