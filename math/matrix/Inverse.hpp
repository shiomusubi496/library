#pragma once

#include "../../other/template.hpp"
#include "Matrix.hpp"

template<class T> Matrix<T> inverse(Matrix<T> mat) {
    assert(mat.is_square());
    const int n = mat.height();
    Matrix<T> mat2(n, n * 2);
    rep (i, n) {
        rep (j, n) mat2[i][j] = mat[i][j];
        mat2[i][n + i] = T{1};
    }
    mat2.gauss();
    rep (i, n) {
        if (mat2[i][i] == T{0}) return Matrix<T>(0, 0);
    }
    Matrix<T> res(n, n);
    rep (i, n) {
        rep (j, n) res[i][j] = mat2[i][n + j];
    }
    return res;
}

/**
 * @brief Inverse(逆行列)
 * @docs docs/math/matrix/Inverse.md
 */
