#pragma once

#include "../../other/template.hpp"
#include "Matrix.hpp"

template<class T> T determinant(Matrix<T> mat) {
    assert(mat.is_square());
    const int n = mat.height();
    if (n == 0) return 1;
    T res = 1;
    rep (i, n) {
        if (mat[i][i] == 0) {
            rep (j, i + 1, n) {
                if (mat[j][i] != 0) {
                    swap(mat[i], mat[j]);
                    res = -res;
                    break;
                }
            }
        }
        if (mat[i][i] == 0) {
            return T{0};
        }
        {
            const T s = mat[i][i];
            res *= s;
            rep (j, n) mat[i][j] /= s;
        }
        rep (j, n) {
            if (j == i) continue;
            const T s = mat[j][i];
            rep (k, n) mat[j][k] -= mat[i][k] * s;
        }
    }
    rep (i, n) res *= mat[i][i];
    return res;
}

/**
 * @brief Determinant(行列式)
 * @docs docs/math/matrix/Determinant.md
 */
