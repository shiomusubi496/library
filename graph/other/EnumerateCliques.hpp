#pragma once

#include "../../other/template.hpp"
#include "../Graph.hpp"

template<class T>
std::vector<std::vector<int>> enumerate_cliques(const Graph<T>& G) {
    int n = G.size();
    std::vector<std::vector<bool>> adj(n, std::vector<bool>(n, false));
    rep (i, n) {
        each_const (e : G[i]) adj[i][e.to] = true;
    }
    std::vector<int> vert(n); std::iota(all(vert), 0);
    std::vector<std::vector<int>> res;
    while (!vert.empty()) {
        int v = -1, mn_d = n + 1;
        each_const (i : vert) {
            int d = 0;
            each_const (j : vert) {
                if (adj[i][j]) ++d;
            }
            if (chmin(mn_d, d)) v = i;
        }
        std::vector<int> clique{v};
        rec_lambda([&](auto&& self, int i) -> void {
            if (i == (int)vert.size()) {
                res.push_back(clique);
                return;
            }
            if (vert[i] == v) {
                self(i + 1);
                return;
            }
            self(i + 1);
            bool f = true;
            each_const (j : clique) {
                if (!adj[vert[i]][j]) {
                    f = false;
                    break;
                }
            }
            if (f) {
                clique.push_back(vert[i]);
                self(i + 1);
                clique.pop_back();
            }
        })(0);
        vert.erase(std::find(all(vert), v));
    }
    return res;
}

/**
 * @brief EnumerateCliques
 * @docs docs/graph/other/EnumerateCliques.md
 */
