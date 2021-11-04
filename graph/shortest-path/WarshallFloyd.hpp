#pragma once

#include "../../template.hpp"
#include "../Graph.hpp"

template<class T> void WarshallFloyd(GMatrix<T>& G){
    int N = G.size();
    rep (i, N) G[i][i] = 0;
    rep (k, N) {
        rep (i, N) {
            rep (j, N) {
                if (G[i][k] != INF<T> && G[k][j] != INF<T>) chmin(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }
}

/*
@brief Warshall-Floyd(ワーシャルフロイド法)
@docs docs/WarshallFloyd.md
*/
