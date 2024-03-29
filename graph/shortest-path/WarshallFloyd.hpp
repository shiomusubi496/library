#pragma once

#include "../../other/template.hpp"
#include "../Graph.hpp"

template<class T> void WarshallFloyd(GMatrix<T>& G) {
    const int N = G.size();
    rep (i, N) G[i][i] = 0;
    rep (k, N) {
        rep (i, N) {
            rep (j, N) {
                if (G[i][k] != infinity<T>::value &&
                    G[k][j] != infinity<T>::value) {
                    chmin(G[i][j], G[i][k] + G[k][j]);
                }
            }
        }
    }
}

/**
 * @brief Warshall-Floyd(ワーシャルフロイド法)
 * @docs docs/graph/shortest-path/WarshallFloyd.md
 */
