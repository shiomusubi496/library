#pragma once

#include "../other/template.hpp"
#include "../random/Random.hpp"
#include "../math/ModInt.hpp"
#include "../math/convolution/Convolution.hpp"

namespace internal {

template<class T>
std::vector<bool> wildcard_mod(const std::vector<int>& a,
                               const std::vector<int>& b, bool a0, bool b0) {
    const int n = a.size(), m = b.size();
    const int lg = bitop::ceil_log2(n), N = 1 << lg;
    std::vector<T> A1(N), B1(N), A2(N), B2(N), A3(N), B3(N);
    rep (i, n) A1[i] = a0 ? a[i] : 1;
    rep (i, m) B1[i] = b0 ? b[m - 1 - i] : 1;
    rep (i, n) A2[i] = A1[i] * A1[i];
    rep (i, m) B2[i] = B1[i] * B1[i];
    rep (i, n) A3[i] = A1[i] * A2[i];
    rep (i, m) B3[i] = B1[i] * B2[i];
    number_theoretic_transform(A1);
    number_theoretic_transform(B1);
    number_theoretic_transform(A2);
    number_theoretic_transform(B2);
    number_theoretic_transform(A3);
    number_theoretic_transform(B3);
    rep (i, N) A1[i] = A1[i] * B3[i] - 2 * A2[i] * B2[i] + A3[i] * B1[i];
    inverse_number_theoretic_transform(A1);
    std::vector<bool> c(n - m + 1);
    rep (i, n - m + 1) c[i] = A1[i + m - 1] == 0;
    return c;
}

} // namespace internal

std::vector<bool> wildcard_pattern_matching(std::vector<int> a,
                                            std::vector<int> b, int MAX,
                                            bool deterministic = true) {
    const int n = a.size(), m = b.size();
    if (n < m) return {};
    bool a0 = find(all(a), 0) != a.end(), b0 = find(all(b), 0) != b.end();
    i128 MAX_VAL = (i128)MAX * MAX * m;
    if (a0) MAX_VAL *= MAX;
    if (b0) MAX_VAL *= MAX;
    static constexpr int MOD1 = 2113929217, MOD2 = 2013265921,
                         MOD3 = 1811939329, MOD4 = 1711276033;
    if (!deterministic) {
        MAX_VAL = 1;
        std::vector<int> val(MAX + 1);
        rep (i, 1, MAX + 1) val[i] = rand32() % (MOD1 - 1) + 1;
        rep (i, n) a[i] = val[a[i]];
        rep (i, m) b[i] = val[b[i]];
    }
    std::vector<bool> res =
        internal::wildcard_mod<static_modint<MOD1>>(a, b, a0, b0);
    if (MAX_VAL >= MOD1) {
        auto c = internal::wildcard_mod<static_modint<MOD2>>(a, b, a0, b0);
        rep (i, n - m + 1) res[i] = res[i] && c[i];
    }
    if (MAX_VAL >= (i128)MOD1 * MOD2) {
        auto c = internal::wildcard_mod<static_modint<MOD3>>(a, b, a0, b0);
        rep (i, n - m + 1) res[i] = res[i] && c[i];
    }
    if (MAX_VAL >= (i128)MOD1 * MOD2 * MOD3) {
        auto c = internal::wildcard_mod<static_modint<MOD4>>(a, b, a0, b0);
        rep (i, n - m + 1) res[i] = res[i] && c[i];
    }
    return res;
}

std::vector<bool> wildcard_pattern_matching(const std::vector<int>& a,
                                            const std::vector<int>& b,
                                            bool deterministic = true) {
    compressor<int> comp{0};
    comp.push(a);
    comp.push(b);
    comp.build();
    return wildcard_pattern_matching(comp.pressed(a), comp.pressed(b),
                                     comp.size() - 1, deterministic);
}

std::vector<bool> wildcard_pattern_matching(const std::string& a,
                                            const std::string& b,
                                            char wildcard = '*',
                                            bool deterministic = true) {
    static std::vector<int> idx(128, -1);
    std::vector<int> A(a.size()), B(b.size());
    int cnt = 1;
    rep (i, a.size()) {
        A[i] = a[i] == wildcard  ? 0
               : idx[a[i]] == -1 ? idx[a[i]] = cnt++
                                 : idx[a[i]];
    }
    rep (i, b.size()) {
        B[i] = b[i] == wildcard  ? 0
               : idx[b[i]] == -1 ? idx[b[i]] = cnt++
                                 : idx[b[i]];
    }
    rep (i, a.size()) idx[a[i]] = -1;
    rep (i, b.size()) idx[b[i]] = -1;
    return wildcard_pattern_matching(A, B, cnt - 1, deterministic);
}

/**
 * @brief WildcardPatternMatching
 * @docs docs/string/WildcardPatternMatching.md
 */