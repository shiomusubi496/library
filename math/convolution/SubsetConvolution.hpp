#pragma once

#include "../../other/template.hpp"

namespace internal {

template<class T, int L> void ranked_zeta(std::vector<std::array<T, L>>& a) {
    int n = a.size();
    for (int i = 1; i < n; i <<= 1) {
        rep (j, 0, n, i << 1) {
            rep (k, j, j + i) {
                rep (l, L) a[k + i][l] += a[k][l];
            }
        }
    }
}
template<class T, int L> void ranked_moebius(std::vector<std::array<T, L>>& a) {
    int n = a.size();
    for (int i = 1; i < n; i <<= 1) {
        rep (j, 0, n, i << 1) {
            rep (k, j, j + i) {
                rep (l, L) a[k + i][l] -= a[k][l];
            }
        }
    }
}

} // namespace internal

template<class T, int L = 20>
std::vector<T> subset_convolution(const std::vector<T>& a,
                                  const std::vector<T>& b) {
    int n = a.size(), m = bitop::ceil_log2(n);
    std::vector<std::array<T, L + 1>> a2(n), b2(n);
    rep (i, n) a2[i][popcnt(i)] = a[i];
    rep (i, n) b2[i][popcnt(i)] = b[i];
    internal::ranked_zeta<T, L + 1>(a2);
    internal::ranked_zeta<T, L + 1>(b2);
    rep (k, n) {
        auto& f = a2[k];
        const auto& g = b2[k];
        rrep (i, m + 1) {
            T sm = 0;
            rep (j, i + 1) sm += f[j] * g[i - j];
            f[i] = sm;
        }
    }
    internal::ranked_moebius<T, L + 1>(a2);
    std::vector<T> c(n);
    rep (i, n) c[i] = a2[i][popcnt(i)];
    return c;
}

/**
 * @brief SubsetConvolution
 * @docs docs/math/convolution/SubsetConvolution.md
 */
