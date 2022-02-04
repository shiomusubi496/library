#pragma once

#include "../../other/template.hpp"
#include "../Graph.hpp"

template<class T> class ConnectedComponents {
  protected:
    int n, sz;
    const Graph<T>& G;
    std::vector<int> cmp;
    void dfs(int v) {
        each_const (e : G[v]) {
            if (cmp[e.to] != -1) continue;
            cmp[e.to] = cmp[v];
            dfs(e.to);
        }
    }
    void init() {
        n = G.size();
        cmp.assign(n, -1);
        sz = 0;
        rep (i, n) {
            if (cmp[i] != -1) continue;
            cmp[i] = sz++;
            dfs(i);
        }
    }
  public:
    ConnectedComponents(const Graph<T>& G) : G(G) { init(); }
    int size() const { return sz; }
    int operator[](int k) const { return cmp[k]; }
    std::vector<std::vector<int>> groups() const {
        std::vector<std::vector<int>> res(sz);
        rep (i, n) res[cmp[i]].push_back(i);
        return res;
    }
};

/**
 * @brief ConnectedComponents(連結成分分解)
 * @docs docs/ConnectedComponents.md
 */
