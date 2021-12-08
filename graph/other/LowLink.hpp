#pragma once

#include "../Graph.hpp"

template<class T> class LowLink {
  protected:
    int n, cnt;
    Graph<T> G;
    std::vector<int> ord, low;
    std::vector<int> aps;
    Edges<T> brd;
    void dfs(int v, int p) {
        low[v] = ord[v] = cnt++;
        int deg = 0;
        bool is_ap = false;
        for (const edge<T>& e : G[v]) {
            if (e.to == p) continue;
            if (ord[e.to] != -1) chmin(low[v], ord[e.to]);
            else {
                dfs(e.to, v);
                chmin(low[v], low[e.to]);
                if (p != -1 && ord[v] <= low[e.to]) is_ap = true;
                if (ord[v] < low[e.to]) brd.push_back(e);
                ++deg;
            }
        }
        if (p == -1 && deg > 1) is_ap = true;
        if (is_ap) aps.push_back(v);
    }
  public:
    LowLink() = default;
    LowLink(const Graph<T>& G_) { init(G_); }
    void init(const Graph<T>& G_) {
        G = G_;
        n = G.size();
        ord.assign(n, -1); low.assign(n, n + 1);
        cnt = 0;
        rep (i, n) {
            if (ord[i] == -1) dfs(i, -1);
        }
    }
    std::vector<int> articulation_points() const { return aps; }
    Edges<T> bridges() const { return brd; }
};

/**
 * @brief Lowlink(関節点・橋検出)
 */
