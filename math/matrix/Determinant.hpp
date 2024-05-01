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
                    std::swap(mat[i], mat[j]);
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
        rep (j, i + 1, n) {
            const T s = mat[j][i];
            rep (k, n) mat[j][k] -= mat[i][k] * s;
        }
    }
    rep (i, n) res *= mat[i][i];
    return res;
}

template<> static_modint<2> determinant(Matrix<static_modint<2>> mat) {
    assert(mat.is_square());
    return mat.rank() == mat.height() ? 1 : 0;
}

template<class T> T determinant_arbitrary_mod(Matrix<T> mat) {
    assert(mat.is_square());
    const int n = mat.height();
    if (n == 0) return 1;
    T res = 1;
    rep (i, n) {
        if (mat[i][i] == 0) {
            rep (j, i + 1, n) {
                if (mat[j][i] != 0) {
                    std::swap(mat[i], mat[j]);
                    res = -res;
                    break;
                }
            }
        }
        if (mat[i][i] == 0) {
            return T{0};
        }
        rep (j, i + 1, n) {
            T a = 1, b = 0, c = 0, d = 1;
            ll x = mat[i][i].get(), y = mat[j][i].get();
            while (y != 0) {
                ll q = x / y;
                std::swap(x -= q * y, y);
                std::swap(a -= q * c, c);
                std::swap(b -= q * d, d);
                res = -res;
            }
            rep (k, i, n) {
                T ni = a * mat[i][k] + b * mat[j][k];
                T nj = c * mat[i][k] + d * mat[j][k];
                mat[i][k] = ni;
                mat[j][k] = nj;
            }
        }
    }
    rep (i, n) res *= mat[i][i];
    return res;
}

/**
 * @brief Determinant(行列式)
 * @docs docs/math/matrix/Determinant.md
 */
