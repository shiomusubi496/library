#pragma once

#include "../../other/template.hpp"
#include "Matrix.hpp"
#include "Determinant.hpp"
#include "Inverse.hpp"
#include "LinearEquations.hpp"

template<class T>
T cofactor(Matrix<T> mat, int a, int b) {
    assert(mat.is_square());
    const int n = mat.height();
    Matrix<T> sub(n - 1, n - 1);
    rep (i, a) rep (j, b) sub[i][j] = mat[i][j];
    rep (i, a + 1, n) rep (j, b) sub[i - 1][j] = mat[i][j];
    rep (i, a) rep (j, b + 1, n) sub[i][j - 1] = mat[i][j];
    rep (i, a + 1, n) rep (j, b + 1, n) sub[i - 1][j - 1] = mat[i][j];
    T res = determinant(sub);
    if ((a + b) % 2 == 0) return res;
    return -res;
}

template<class T>
Matrix<T> adjugate_matrix(Matrix<T> mat) {
    assert(mat.is_square());
    const int n = mat.height();
    const int r = mat.rank();
    if (r == n) return inverse(mat) * determinant(mat);
    if (r < n - 1) return Matrix<T>(n, n, 0);
    auto x = LinearEquations(mat, std::vector<T>(n, 0)).get_solution_space()[0];
    auto y = LinearEquations(mat.transpose(), std::vector<T>(n, 0)).get_solution_space()[0];
    Matrix<T> res(n, n, 0);
    rep (i, n) rep (j, n) res[i][j] = x[i] * y[j];
    rep (i, n) rep (j, n) {
        if (res[i][j] != 0) {
            res *= cofactor(mat, j, i) / res[i][j];
            return res;
        }
    }
    return res;
}
