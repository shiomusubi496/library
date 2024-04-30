#pragma once

#include "../../other/template.hpp"
#include "Convolution.hpp"

template<class T>
std::vector<T> multidimensional_convolution(const std::vector<T>& a,
                                            const std::vector<T>& b,
                                            const std::vector<int>& base) {
    int n = 1;
    while (n < (int)a.size() + (int)b.size() - 1) n *= 2;
    int K = base.size();
    auto f = [&](int i) -> int {
        int res = 0;
        for (int j : base) {
            res += i / j;
            i /= j;
        }
        return res % (K + 1);
    };
    std::vector<std::vector<T>> A(K + 1, std::vector<T>(n, 0));
    std::vector<std::vector<T>> B(K + 1, std::vector<T>(n, 0));
    std::vector<std::vector<T>> C(K + 1, std::vector<T>(n, 0));
    rep (i, a.size()) A[f(i)][i] = a[i];
    rep (i, b.size()) B[f(i)][i] = b[i];
    rep (i, K + 1) {
        number_theoretic_transform(A[i]);
        number_theoretic_transform(B[i]);
    }
    rep (i, K + 1) rep (j, K + 1) {
        int k = (i + j) % (K + 1);
        rep (l, n) C[k][l] += A[i][l] * B[j][l];
    }
    rep (i, K + 1) {
        inverse_number_theoretic_transform(C[i]);
    }
    std::vector<T> res(a.size(), 0);
    rep (i, a.size()) res[i] = C[f(i)][i];
    return res;
}

/**
 * @brief MultidimensionalConvolution
 * @docs docs/math/convolution/MultidimensionalConvolution.md
 */