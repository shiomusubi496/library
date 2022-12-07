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
    rep (i, n) {
        if (mat[i][i] == 0) {
            rep (j, i + 1, n) {
                if (mat[j][i] != 0) {
                    swap(mat[i], mat[j]);
                    break;
                }
            }
        }
        if (mat[i][i] == 0) {
            return Matrix<T>{};
        }
        {
            const T s = mat[i][i];
            rep (j, n * 2) mat[i][j] /= s;
        }
        rep (j, i + 1, n) {
            const T s = mat[j][i];
            rep (k, n * 2) mat[j][k] -= mat[i][k] * s;
        }
    }
    rrep (i, n) {
        rep (j, i) {
            const T s = mat[j][i];
            rep (k, n, n * 2) mat[j][k] -= mat[i][k] * s;
        }
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
