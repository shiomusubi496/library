#pragma once

#include "../Graph.hpp"

template<class T> class LowLink {
  protected:
    int n, cnt;
    const Graph<T>& G;
    std::vector<int> ord, low;
    std::vector<int> aps;
    Edges<T> brd;
    void dfs(int v, int p) {
        low[v] = ord[v] = cnt++;
        int deg = 0;
        bool is_ap = false, mul = false;
        for (const edge<T>& e : G[v]) {
            if (e.to == p && !mul) {
                mul = true;
                continue;
            }
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
    void init() {
        n = G.size();
        ord.assign(n, -1); low.assign(n, n + 1);
        cnt = 0;
        rep (i, n) {
            if (ord[i] == -1) dfs(i, -1);
        }
    }
  public:
    LowLink(const Graph<T>& G) : G(G) { init(); }
    const std::vector<int>& articulation_points() const& { return aps; }
    std::vector<int> articulation_points() && { return std::move(aps); }
    const Edges<T>& bridges() const& { return brd; }
    Edges<T> bridges() && { return std::move(brd); }
};

/**
 * @brief Lowlink(関節点・橋検出)
 * @docs docs/LowLink.md
 */
