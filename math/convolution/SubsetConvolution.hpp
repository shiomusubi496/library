#pragma once

#include "../../other/template.hpp"

namespace internal {

template<class T, int L> std::vector<std::array<T, L>> ranked_zeta(const std::vector<T>& a) {
    int n = a.size();
    std::vector<std::array<T, L>> b(n);
    rep (i, n) b[i][popcnt(i)] = a[i];
    for (int i = 1; i < n; i <<= 1) {
        rep (j, 0, n, i << 1) {
            rep (k, j, j + i) {
                rep (l, L) b[k + i][l] += b[k][l];
            }
        }
    }
    return b;
}
template<class T, int L> std::vector<T> ranked_moebius(std::vector<std::array<T, L>> b) {
    int n = b.size();
    for (int i = 1; i < n; i <<= 1) {
        rep (j, 0, n, i << 1) {
            rep (k, j, j + i) {
                rep (l, L) b[k + i][l] -= b[k][l];
            }
        }
    }
    std::vector<T> a(n);
    rep (i, n) a[i] = b[i][popcnt(i)];
    return a;
}

} // namespace internal

template<class T, int L>
std::vector<T> subset_convolution_pow2(const std::vector<T>& a) {
    int n = a.size(), m = bitop::ceil_log2(n);
    std::vector<std::array<T, L + 1>> a2 = internal::ranked_zeta<T, L + 1>(a);
    rep (k, n) {
        auto& f = a2[k];
        const auto g = a2[k];
        rrep (i, m + 1) {
            T sm = 0;
            rep (j, i + 1) sm += f[j] * g[i - j];
            f[i] = sm;
        }
    }
    return internal::ranked_moebius<T, L + 1>(a2);
}

template<class T, int L = 0>
std::vector<T> subset_convolution(const std::vector<T>& a,
                                  const std::vector<T>& b) {
    if (a.size() > (1 << L)) {
        return subset_convolution<T, std::min<int>(L + 1, 30)>(a, b);
    }
    if (a == b) {
        return subset_convolution_pow2<T, L>(a);
    }
    int n = a.size(), m = bitop::ceil_log2(n);
    std::vector<std::array<T, L + 1>> a2 = internal::ranked_zeta<T, L + 1>(a);
    std::vector<std::array<T, L + 1>> b2 = internal::ranked_zeta<T, L + 1>(b);
    rep (k, n) {
        auto& f = a2[k];
        const auto& g = b2[k];
        int c = popcnt(k);
        rrep (i, std::min<int>(c * 2, m) + 1) {
            T sm = 0;
            rep (j, std::max<int>(i - c, 0), i + 1) sm += f[j] * g[i - j];
            f[i] = sm;
        }
    }
    return internal::ranked_moebius<T, L + 1>(a2);
}

/**
 * @brief SubsetConvolution
 * @docs docs/math/convolution/SubsetConvolution.md
 */
