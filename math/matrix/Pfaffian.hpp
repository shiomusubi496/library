#pragma once

#include "../../other/template.hpp"
#include "Matrix.hpp"

template<class T> T pfaffian(Matrix<T> mat) {
    const int n = mat.height();
    assert(mat.is_square());
    assert(n % 2 == 0);
    T ans = 1;
    rep (i, 0, n, 2) {
        if (mat[i][i + 1] == 0) {
            rep (j, i + 2, n) {
                if (mat[i][j] != 0) {
                    std::swap(mat[i + 1], mat[j]);
                    rep (k, i, n) std::swap(mat[k][i + 1], mat[k][j]);
                    ans = -ans;
                    break;
                }
            }
        }
        if (mat[i][i + 1] == 0) return 0;
        ans *= mat[i][i + 1];
        T v = 1 / mat[i][i + 1];
        rep (j, i + 2, n) mat[i][j] *= v;
        rep (j, i + 2, n) mat[j][i] *= v;
        rep (j, i + 2, n) rep (k, i + 2, n) mat[j][k] += mat[i][k] * mat[i + 1][j];
        rep (j, i + 2, n) rep (k, i + 2, n) mat[j][k] -= mat[i][j] * mat[i + 1][k];
    }
    return ans;
}
