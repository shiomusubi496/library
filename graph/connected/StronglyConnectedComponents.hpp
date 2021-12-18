#pragma once

#include "../../other/template.hpp"
#include "../Graph.hpp"

template<class T> class StronglyConnectedComponents {
  protected:
    int n, sz;
    Graph<T> G_;
    const Graph<T>& G;
    std::vector<std::vector<int>> RG;
    std::vector<int> ord;
    std::vector<bool> seen;
    std::vector<int> cmp;
    void dfs(int v) {
        seen[v] = true;
        for (const edge<T>& e : G[v]) {
            if (seen[e.to]) continue;
            dfs(e.to);
        }
        ord.push_back(v);
    }
    void dfs2(int v) {
        for (const int& e : RG[v]) {
            if (cmp[e] != -1) continue;
            cmp[e] = cmp[v];
            dfs2(e);
        }
    }
    void init() {
        n = G.size();
        ord.clear(); ord.reserve(n);
        seen.assign(n, false);
        rep (i, n) {
            if (seen[i]) continue;
            dfs(i);
        }
        std::reverse(all(ord));

        RG.assign(n, std::vector<int>());
        rep (i, n) {
            for (const edge<T>& e : G[i]) RG[e.to].push_back(i);
        }

        sz = 0;
        cmp.assign(n, -1);
        for (const int& i : ord) {
            if (cmp[i] != -1) continue;
            cmp[i] = sz++;
            dfs2(i);
        }
    }
  public:
    StronglyConnectedComponents(const Graph<T>& G) : G(G) { init(); }
    StronglyConnectedComponents(Graph<T>&& G) : G_(std::move(G)), G(G_) { init(); }
    int size() const { return sz; }
    int operator[](int k) const { return cmp[k]; }
    std::vector<std::vector<int>> groups() const {
        std::vector<std::vector<int>> res(sz);
        rep (i, n) res[cmp[i]].push_back(i);
        return res;
    }
    Graph<T> dag() const {
        Graph<T> res(n);
        rep (i, n) {
            for (const auto& e : G[i]) {
                if (cmp[i] != cmp[e.to]) res.add_edge(cmp[i], cmp[e.to], e.cost, true);
            }
        }
        return res;
    }
};

/**
 * @brief StronglyConnectedComponents(強連結成分分解)
 * @docs docs/StronglyConnectedComponents.md
 */
