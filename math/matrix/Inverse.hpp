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

template<> Matrix<static_modint<2>> inverse(Matrix<static_modint<2>> mat) {
    assert(mat.is_square());
    using T = static_modint<2>;
    const int n = mat.height();
    T zero = T::raw(0), one = T::raw(1);
    rep (i, n) {
        mat[i].resize(n * 2, zero);
        mat[i][n + i] = one;
    }
    mat.gauss();
    rep (i, n) {
        if (mat[i][i] == zero) return Matrix<T>(0, 0);
    }
    Matrix<T> res(n, n);
    rep (i, n) {
        rep (j, n) res[i][j] = mat[i][n + j];
    }
    return res;
}

/**
 * @brief Inverse(逆行列)
 * @docs docs/math/matrix/Inverse.md
 */
