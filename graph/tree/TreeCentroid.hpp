#pragma once

#include "../../other/template.hpp"
#include "../Graph.hpp"

template<class T> class TreeCentroids {
private:
    int n;
    const Graph<T>& G;
    std::vector<int> sz;
    std::vector<int> cent;
    int dfs(int v, int p) {
        for (const auto& e : G[v]) {
            if (e.to == p) continue;
            sz[v] += dfs(e.to, v);
        }
        return sz[v];
    }
    void init() {
        n = G.size();
        sz.assign(n, 1);
        int s = dfs(0, -1);
        int v = 0, p = -1;
        while (true) {
            bool ok = true;
            for (const auto& e : G[v]) {
                if (e.to == p) continue;
                if (sz[e.to] * 2 > s) {
                    p = v;
                    v = e.to;
                    ok = false;
                    break;
                }
                if (sz[e.to] * 2 == s) {
                    cent = {v, e.to};
                    return;
                }
            }
            if (ok) {
                cent = {v};
                return;
            }
        }
    }

public:
    TreeCentroids(const Graph<T>& G) : G(G) { init(); }
    bool has_one_centroid() const { return cent.size() == 1; }
    std::vector<int> get() { return cent; }
};

template<class T> class CentroidDecomposition {
private:
    int n;
    const Graph<T>& G;
    std::vector<bool> seen;
    std::vector<int> sz;
    int root;
    UnweightedGraph C;
    int dfs(int v, int p) {
        sz[v] = 1;
        for (const auto& e : G[v]) {
            if (e.to == p) continue;
            if (seen[e.to]) continue;
            sz[v] += dfs(e.to, v);
        }
        return sz[v];
    }
    void init() {
        n = G.size();
        seen.assign(n, false);
        sz.assign(n, 1);
        std::vector<std::pair<int, int>> st = {{0, -1}};
        st.reserve(n);
        C = UnweightedGraph(n);
        while (!st.empty()) {
            int v = st.back().first, vp = st.back().second;
            st.pop_back();
            int s = dfs(v, -1);
            int p = -1;
            while (true) {
                bool ok = true;
                for (const auto& e : G[v]) {
                    if (e.to == p) continue;
                    if (seen[e.to]) continue;
                    if (sz[e.to] * 2 > s) {
                        p = v;
                        v = e.to;
                        ok = false;
                        break;
                    }
                }
                if (ok) break;
            }
            seen[v] = true;
            if (vp != -1) C.add_edge(vp, v, true);
            else root = v;
            for (const auto& e : G[v]) {
                if (seen[e.to]) continue;
                st.emplace_back(e.to, v);
            }
        }
    }

public:
    CentroidDecomposition(const Graph<T>& G) : G(G) { init(); }
    int get_root() { return root; }
    const UnweightedGraph& get() const& { return C; }
    UnweightedGraph get() && { return std::move(C); }
};

/**
 * @brief TreeCentroid(木の重心)
 * @docs docs/graph/tree/TreeCentroid.md
 */
