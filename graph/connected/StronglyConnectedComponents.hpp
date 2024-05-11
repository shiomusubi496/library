#pragma once

#include "../../other/template.hpp"
#include "../Graph.hpp"

template<class T> class StronglyConnectedComponents {
private:
    int n, sz, cnt;
    Graph<T> G_;
    const Graph<T>& G;
    std::vector<int> ord, low;
    std::vector<int> st;
    std::vector<int> cmp;
    void dfs(int v) {
        low[v] = ord[v] = cnt++;
        st.push_back(v);
        for (const auto& e : G[v]) {
            if (ord[e.to] != -1) chmin(low[v], ord[e.to]);
            else {
                dfs(e.to);
                chmin(low[v], low[e.to]);
            }
        }
        if (low[v] == ord[v]) {
            while (1) {
                int u = st.back();
                st.pop_back();
                cmp[u] = sz;
                ord[u] = n;
                if (u == v) break;
            }
            sz++;
        }
    }
    void init() {
        n = G.size();
        sz = 0;
        cnt = 0;
        ord.assign(n, -1);
        low.assign(n, -1);
        cmp.assign(n, -1);
        st.reserve(n);
        rep (i, n) {
            if (ord[i] == -1) dfs(i);
        }
        for (auto&& i : cmp) i = sz - i - 1;
    }

public:
    StronglyConnectedComponents(const Graph<T>& G) : G(G) { init(); }
    StronglyConnectedComponents(Graph<T>&& G) : G_(std::move(G)), G(G_) {
        init();
    }
    int size() const { return sz; }
    int operator[](int k) const { return cmp[k]; }
    std::vector<std::vector<int>> groups() const {
        std::vector<std::vector<int>> res(sz);
        rep (i, n) res[cmp[i]].push_back(i);
        return res;
    }
    Graph<T> dag() const {
        Graph<T> res(sz);
        rep (i, n) {
            for (const auto& e : G[i]) {
                if (cmp[i] != cmp[e.to])
                    res.add_edge(cmp[i], cmp[e.to], e.cost, true);
            }
        }
        return res;
    }
};

/**
 * @brief StronglyConnectedComponents(強連結成分分解)
 * @docs docs/graph/connected/StronglyConnectedComponents.md
 */
