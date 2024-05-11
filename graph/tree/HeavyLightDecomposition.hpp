#pragma once

#include "../../other/template.hpp"
#include "../Graph.hpp"

template<class T> class HeavyLightDecomposition {
private:
    int n, cnt;
    std::vector<int> root;
    std::vector<int> ssz, head, vin, vout, par;
    const Graph<T>& G;
    int szdfs(int v, int p) {
        ssz[v] = 1;
        for (const auto& e : G[v]) {
            if (e.to == p) continue;
            ssz[v] += szdfs(e.to, v);
        }
        return ssz[v];
    }
    void bldfs(int v, int p) {
        par[v] = p;
        vin[v] = cnt++;
        int idx = -1;
        for (const auto& e : G[v]) {
            if (e.to != p) {
                if (idx == -1 || ssz[idx] < ssz[e.to]) idx = e.to;
            }
        }
        if (idx != -1) {
            head[idx] = head[v];
            bldfs(idx, v);
        }
        for (const auto& e : G[v]) {
            if (e.to != p && e.to != idx) {
                head[e.to] = e.to;
                bldfs(e.to, v);
            }
        }
        vout[v] = cnt;
    }
    void init() {
        n = G.size();
        ssz.assign(n, -1);
        for (int r : root) szdfs(r, -1);
        rep (i, n) {
            if (ssz[i] == -1) szdfs(i, -1);
        }
        cnt = 0;
        head.assign(n, -1);
        vin.resize(n);
        vout.resize(n);
        par.resize(n);
        for (int r : root) {
            head[r] = r;
            bldfs(r, -1);
        }
        rep (i, n) {
            if (head[i] == -1) {
                head[i] = i;
                bldfs(i, -1);
            }
        }
    }

public:
    HeavyLightDecomposition(const Graph<T>& G, int root = 0)
        : root({root}), G(G) {
        init();
    }
    HeavyLightDecomposition(const Graph<T>& G, const std::vector<int>& root)
        : root(root), G(G) {
        init();
    }
    int get_size(int k) const { return ssz[k]; }
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
        for (auto&& p : res) std::swap(p.first, p.second);
        std::reverse(all(res));
        return res;
    }
    template<class F> void each_vertex(int u, int v, const F& f) const {
        return each_vertex(u, v, f, f);
    }
    template<class F, class G>
    void each_vertex(int u, int v, const F& f, const G& g) const {
        int l = lca(u, v);
        auto func = [&](int a, int b) {
            if (a <= b) f(a, b + 1);
            else g(b, a + 1);
        };
        for (const auto& p : up_path(u, l)) func(p.first, p.second);
        func(vin[l], vin[l]);
        for (const auto& p : down_path(l, v)) func(p.first, p.second);
    }
    template<class F> void each_edge(int u, int v, const F& f) const {
        return each_edge(u, v, f, f);
    }
    template<class F, class G>
    void each_edge(int u, int v, const F& f, const G& g) const {
        int l = lca(u, v);
        auto func = [&](int a, int b) {
            if (a <= b) f(a, b + 1);
            else g(b, a + 1);
        };
        for (const auto& p : up_path(u, l)) func(p.first, p.second);
        for (const auto& p : down_path(l, v)) func(p.first, p.second);
    }
    template<class F> void each_vertex_subtree(int u, const F& f) const {
        f(vin[u], vout[u]);
    }
    template<class F> void each_edge_subtree(int u, const F& f) const {
        f(vin[u] + 1, vout[u]);
    }
};

/**
 * @brief HeavyLightDecomposition(HL分解)
 * @docs docs/graph/tree/HeavyLightDecomposition.md
 */
