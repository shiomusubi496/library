#pragma once

#include "../Graph.hpp"
#include "../../math/matrix/Matrix.hpp"
#include "../../math/matrix/Determinant.hpp"

template<class T, class U> T count_spanning_tree(const Graph<U>& G, int v = 0) {
    const int N = G.size();
    Matrix<T> A(N - 1, N - 1);
    rep (i, N) {
        if (i == v) continue;
        T cnt = 0;
        for (const auto& e : G[i]) {
            if (e.to != i) cnt += e.cost;
        }
        A[i < v ? i : i - 1][i < v ? i : i - 1] = cnt;
    }
    rep (i, N) {
        if (i == v) continue;
        for (const auto& e : G[i]) {
            if (e.to == v || e.to == i) continue;
            A[i < v ? i : i - 1][e.to < v ? e.to : e.to - 1] -= e.cost;
        }
    }
    return determinant(A);
}

/**
 * @brief CountSpanningTree(行列木定理)
 * @docs docs/graph/mst/CountSpanningTree.md
 */
