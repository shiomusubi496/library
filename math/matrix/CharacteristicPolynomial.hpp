#pragma once

#include "../../other/template.hpp"
#include "Matrix.hpp"
#include "../poly/FormalPowerSeries.hpp"

template<class T>
FormalPowerSeries<T> characteristic_polynomial(Matrix<T> mat) {
    assert(mat.is_square());
    const int n = mat.height();
    rep (i, n - 1) {
        if (mat[i + 1][i] == 0) {
            rep (j, i + 2, n) {
                if (mat[j][i] != 0) {
                    std::swap(mat[j], mat[i + 1]);
                    rep (k, n) std::swap(mat[k][j], mat[k][i + 1]);
                    break;
                }
            }
        }
        if (mat[i + 1][i] == 0) continue;
        rep (j, i + 2, n) {
            if (mat[j][i] != 0) {
                const T x = mat[j][i] / mat[i + 1][i];
                rep (k, i, n) mat[j][k] -= mat[i + 1][k] * x;
                rep (k, n) mat[k][i + 1] += mat[k][j] * x;
            }
        }
    }
    std::vector<FormalPowerSeries<T>> dp(n + 1);
    dp[0] = {1};
    rep (i, n) {
        dp[i + 1] = -mat[i][i] * dp[i] + (dp[i] << 1);
        T p = 1;
        rrep (j, i) {
            p *= mat[j + 1][j];
            dp[i + 1] += dp[j] * (p * -mat[j][i]);
        }
    }
    return dp[n];
}
