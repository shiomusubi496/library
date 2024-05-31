#pragma once

#include "../other/template.hpp"
#include "../random/Random.hpp"
#include "../math/ModInt.hpp"
#include "../math/convolution/Convolution.hpp"

namespace internal {

template<class T>
std::vector<bool> wildcard_mod(const std::vector<int>& a,
                               const std::vector<int>& b) {
    const int n = a.size(), m = b.size();
    const int lg = bitop::ceil_log2(n), N = 1 << lg;
    std::vector<T> A1(N), B1(N), A2(N), B2(N), A3(N), B3(N);
    std::vector<T> C1(N), C2(n - m + 1);
    rep (i, n) A1[i] = a[i] == 0 ? 0 : 1;
    rep (i, m) B1[i] = b[m - 1 - i] == 0 ? 0 : 1;
    rep (i, n) A2[i] = a[i] * A1[i];
    rep (i, m) B2[i] = b[m - 1 - i] * B1[i];
    rep (i, n) A3[i] = a[i] * A2[i];
    rep (i, m) B3[i] = b[m - 1 - i] * B2[i];
    if (find(all(a), 0) == a.end()) {
        T sm = 0;
        rep (i, m) sm += B3[i];
        rep (i, n - m + 1) C2[i] += sm;
    }
    else {
        number_theoretic_transform(A1);
        number_theoretic_transform(B3);
        rep (i, N) C1[i] += A1[i] * B3[i];
    }
    if (find(all(b), 0) == b.end()) {
        std::vector<T> cum(n + 1);
        rep (i, n) cum[i + 1] = cum[i] + A3[i];
        rep (i, n - m + 1) C2[i] += cum[i + m] - cum[i];
    }
    else {
        number_theoretic_transform(A3);
        number_theoretic_transform(B1);
        rep (i, N) C1[i] += A3[i] * B1[i];
    }
    number_theoretic_transform(A2);
    number_theoretic_transform(B2);
    rep (i, N) C1[i] -= 2 * A2[i] * B2[i];
    inverse_number_theoretic_transform(C1);
    std::vector<bool> c(n - m + 1);
    rep (i, n - m + 1) c[i] = (C1[i + m - 1] + C2[i] == 0);
    return c;
}

template<class T>
std::vector<bool> wildcard_random(const std::vector<int>& a,
                                  const std::vector<int>& b) {
    const int n = a.size(), m = b.size();
    const int lg = bitop::ceil_log2(n), N = 1 << lg;
    bool a0 = find(all(a), 0) == a.end();
    bool b0 = find(all(b), 0) == b.end();
    std::vector<T> A1(N), B1(N), A2(N), B2(N);
    std::vector<T> C1(N), C2(n - m + 1);
    if (a0) {
        rep (i, n) A1[i] = a[i] == 0 ? 0 : 1;
        rep (i, m) {
            B1[i] = b[m - 1 - i] == 0
                        ? 0
                        : rand32.uniform<int>(1, T::get_mod() - 1);
        }
    }
    else {
        rep (i, n) {
            A1[i] = a[i] == 0 ? 0 : rand32.uniform<int>(1, T::get_mod() - 1);
        }
        rep (i, m) B1[i] = b[m - 1 - i] == 0 ? 0 : 1;
    }
    rep (i, n) A2[i] = a[i] * A1[i];
    rep (i, m) B2[i] = b[m - 1 - i] * B1[i];
    if (a0) {
        T sm = 0;
        rep (i, m) sm += B2[i];
        rep (i, n - m + 1) C2[i] -= sm;
    }
    else {
        number_theoretic_transform(A1);
        number_theoretic_transform(B2);
        rep (i, N) C1[i] -= A1[i] * B2[i];
    }
    if (!a0 && b0) {
        std::vector<T> cum(n + 1);
        rep (i, n) cum[i + 1] = cum[i] + A2[i];
        rep (i, n - m + 1) C2[i] += cum[i + m] - cum[i];
    }
    else {
        number_theoretic_transform(A2);
        number_theoretic_transform(B1);
        rep (i, N) C1[i] += A2[i] * B1[i];
    }
    inverse_number_theoretic_transform(C1);
    std::vector<bool> c(n - m + 1);
    rep (i, n - m + 1) c[i] = (C1[i + m - 1] + C2[i] == 0);
    return c;
}

} // namespace internal

std::vector<bool> wildcard_pattern_matching(std::vector<int> a,
                                            std::vector<int> b, int MAX,
                                            bool deterministic = true) {
    const int n = a.size(), m = b.size();
    if (n < m) return {};
    i128 MAX_VAL = (i128)MAX * MAX * m;
    static constexpr int MOD1 = 2113929217, MOD2 = 2013265921,
                         MOD3 = 1811939329;
    if (!deterministic) {
        return internal::wildcard_random<static_modint<MOD1>>(a, b);
    }
    std::vector<bool> res = internal::wildcard_mod<static_modint<MOD1>>(a, b);
    if (MAX_VAL >= MOD1) {
        auto c = internal::wildcard_mod<static_modint<MOD2>>(a, b);
        rep (i, n - m + 1) res[i] = res[i] && c[i];
    }
    if (MAX_VAL >= (i128)MOD1 * MOD2) {
        auto c = internal::wildcard_mod<static_modint<MOD3>>(a, b);
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
