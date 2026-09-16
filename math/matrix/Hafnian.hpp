#pragma once

#include "../../other/template.hpp"
#include "../poly/SetPowerSeries.hpp"
#include "Matrix.hpp"

template<class T> T hafnian(Matrix<T> mat) {
    const int N = mat.height();
    assert(N % 2 == 0);
    rep (i, N) rep (j, i) assert(mat[i][j] == mat[j][i]);
    rep (i, N) assert(mat[i][i] == 0);

    const int n = N / 2;
    std::vector<T> cyc(1 << n);
    rep (i, n) {
        cyc[1 << i] = mat[i * 2][i * 2 + 1];
        auto dp = make_vec<T>(1 << i, i * 2, 0);
        rep (j, i * 2) dp[1 << (j / 2)][j ^ 1] = mat[i * 2][j];
        rep (j, 1 << i) rep (k, 2 * i) {
            if (dp[j][k] == 0) continue;
            cyc[j | 1 << i] += dp[j][k] * mat[i * 2 + 1][k];
            rep (l, 2 * i) {
                int m = j | 1 << (l / 2);
                if (j == m) continue;
                dp[m][l ^ 1] += dp[j][k] * mat[k][l];
            }
        }
    }
    return exp_of_sps(cyc)[(1 << n) - 1];
}
