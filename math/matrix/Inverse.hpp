#pragma once

#include "../../other/template.hpp"
#include "Matrix.hpp"

template<class T> Matrix<T> inverse(Matrix<T> mat) {
    assert(mat.is_square());
    const int n = mat.height();
    rep (i, n) {
        mat[i].resize(n * 2, T{0});
        mat[i][n + i] = T{1};
    }
    mat.gauss();
    rep (i, n) {
        if (mat[i][i] == T{0}) return Matrix<T>(0, 0);
    }
    Matrix<T> res(n, n);
    rep (i, n) {
        rep (j, n) res[i][j] = mat[i][n + j];
    }
    return res;
}

template<> Matrix<bool> inverse(Matrix<bool> mat) {
    assert(mat.is_square());
    const int n = mat.height();
    Matrix<bool> mat2(n, n * 2);
    rep (i, n) {
        rep (j, n) mat2.get(i, j) = mat.get(i, j);
        mat2.get(i, n + i) = true;
    }
    mat2.gauss();
    rep (i, n) {
        if (!mat2.get(i, i)) return Matrix<bool>(0, 0);
    }
    Matrix<bool> res(n, n);
    rep (i, n) {
        rep (j, n) res.get(i, j) = mat2.get(i, n + j);
    }
    return res;
}

/**
 * @brief Inverse(逆行列)
 * @docs docs/math/matrix/Inverse.md
 */
