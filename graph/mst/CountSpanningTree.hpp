#pragma once

#include "../Graph.hpp"
#include "../../math/matrix/Matrix.hpp"
#include "../../math/matrix/Determinant.hpp"

template<class T, class U> T CountSpanningTree(const Graph<U>& G) {
    const int N = G.size();
    Matrix<T> A(N - 1, N - 1);
    rep (i, N - 1) A[i][i] += G[i + 1].size();
    rep (i, 1, N) {
        each_const (e : G[i]) {
            if (e.to == 0) continue;
            --A[i - 1][e.to - 1];
        }
    }
    return determinant(A);
}
