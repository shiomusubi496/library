#pragma once

#include "../../template.hpp"
#include "../Graph.hpp"

template<class T> class ConnectedComponents {
  private:
    int n, sz;
    Graph<T> G;
    std::vector<int> id;
    void dfs(int v, int p) {
        for (const edge<T>& e : G[v]) {
            if (e.to == p) continue;
            if (id[e.to] != -1) continue;
            id[e.to] = id[v];
            dfs(e.to, v);
        }
    }
  public:
    ConnectedComponents() = default;
    ConnectedComponents(const Graph<T>& G_) { init(G_); }
    void init(const Graph<T>& G_) {
        G = G_;
        n = G.size();
        id.assign(n, -1);
        sz = 0;
        rep (i, n) {
            if (id[i] != -1) continue;
            id[i] = sz++;
            dfs(i, -1);
        }
    }
    int size() const { return sz; }
    int operator[](int k) const { return id[k]; }
    std::vector<std::vector<int>> groups() const {
        std::vector<std::vector<int>> res(sz);
        rep (i, n) res[id[i]].push_back(i);
        return res;
    }
};
