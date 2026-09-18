#pragma once

#include "../../other/template.hpp"
#include "../num/PrimitiveRoot.hpp"
#include "Convolution.hpp"
#include "../poly/MultipointEvaluation.hpp"

template<class T>
std::vector<T> multidimensional_convolution_truncated(
        const std::vector<T>& a,
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
    rep (i, K + 1)
        rep (j, K + 1) {
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

template<class T>
std::vector<T> multidimensional_convolution_circular(
        std::vector<T> a,
        std::vector<T> b,
        const std::vector<int>& base) {
    int p = T::get_mod();
    for (int n : base) assert((p - 1) % n == 0);
    int K = base.size();
    int N = 1;
    rep (i, K) N *= base[i];
    assert((int)a.size() == N && (int)b.size() == N);
    T r = primitive_root(p);
    T ir = r.inv();
    std::vector<T> root(K), iroot(K);
    rep (i, K) root[i] = r.pow((p - 1) / base[i]);
    rep (i, K) iroot[i] = ir.pow((p - 1) / base[i]);
    int s = 1;
    rep (i, K) {
        int n = base[i];
        rep (j, N) if (j % (s * n) < s) {
            std::vector<T> p(n), q(n);
            rep (k, n) p[k] = a[s * k + j];
            rep (k, n) q[k] = b[s * k + j];
            p = multipoint_evaluation_geometric<T>(p, T{1}, root[i], n);
            q = multipoint_evaluation_geometric<T>(q, T{1}, root[i], n);
            rep (k, n) a[s * k + j] = p[k];
            rep (k, n) b[s * k + j] = q[k];
        }
        s *= n;
    }
    rep (i, N) a[i] *= b[i];
    s = 1;
    rep (i, K) {
        int n = base[i];
        rep (j, N) if (j % (s * n) < s) {
            std::vector<T> p(n), q(n);
            rep (k, n) p[k] = a[s * k + j];
            p = multipoint_evaluation_geometric<T>(p, T{1}, iroot[i], n);
            rep (k, n) a[s * k + j] = p[k];
        }
        s *= n;
    }
    T ninv = 1 / T{N};
    rep (i, N) a[i] *= ninv;
    return a;
}

/**
 * @brief MultidimensionalConvolution
 * @docs docs/math/convolution/MultidimensionalConvolution.md
 */