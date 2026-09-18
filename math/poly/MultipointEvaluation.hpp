#pragma once

#include "../../other/template.hpp"
#include "FormalPowerSeries.hpp"
#include "../convolution/MiddleProduct.hpp"
#include "SubproductTree.hpp"

namespace internal {

template<class T, typename std::enable_if<
                      is_ntt_friendly_modint<T>::value>::type* = nullptr>
std::vector<T> multipoint_evaluation(FormalPowerSeries<T> a,
                                     const std::vector<T>& b,
                                     const SubproductTree<T>& c) {
    static constexpr internal::NthRoot<T> nth_root;
    auto get_high_dft = [&](std::vector<T>& a) -> void {
        int n = a.size() / 2;
        std::vector<T> b(n);
        rep (i, n) b[i] = a[i + n];
        inverse_number_theoretic_transform(b);
        const T z = nth_root.inv(bitop::msb(n) + 1);
        T r = 1;
        rep (i, n) {
            b[i] *= r;
            r *= z;
        }
        number_theoretic_transform(b);
        const T i2 = T{2}.inv();
        rep (i, n) a[i] = (a[i] - b[i]) * i2;
        a.resize(n);
    };
    int m = a.size(), n = b.size(), N = 1 << bitop::ceil_log2(n);
    std::vector<FormalPowerSeries<T>> num(2 * N);
    num[1] = middle_product(a.prefix(m + N - 1), c[1].rev().inv(m));
    number_theoretic_transform(num[1]);
    rep (i, 1, N) {
        int k = num[i].size();
        num[i * 2 + 0].resize(k);
        num[i * 2 + 1].resize(k);
        rep (j, k) num[i * 2 + 0][j] = num[i][j] * c.get_ntt(i * 2 + 1)[j];
        rep (j, k) num[i * 2 + 1][j] = num[i][j] * c.get_ntt(i * 2 + 0)[j];
        get_high_dft(num[i * 2 + 0]);
        get_high_dft(num[i * 2 + 1]);
    }
    std::vector<T> res(n);
    rep (i, n) res[i] = num[i + N][0];
    return res;
}

template<class T, typename std::enable_if<
                      !is_ntt_friendly_modint<T>::value>::type* = nullptr>
std::vector<T> multipoint_evaluation(const FormalPowerSeries<T>& a,
                                     const std::vector<T>& b,
                                     const SubproductTree<T>& c) {
    int m = a.size(), n = b.size(), N = 1 << bitop::ceil_log2(n);
    std::vector<FormalPowerSeries<T>> num(2 * N);
    num[1] = middle_product(a.prefix(m + N - 1), c[1].rev().inv(m));
    rep (i, 1, N) {
        num[i * 2 + 0] = middle_product(num[i], c[i * 2 + 1].rev());
        num[i * 2 + 1] = middle_product(num[i], c[i * 2 + 0].rev());
    }
    std::vector<T> res(n);
    rep (i, n) res[i] = num[i + N][0];
    return res;
}

template<class T, typename std::enable_if<
                      is_ntt_friendly_modint<T>::value>::type* = nullptr>
FormalPowerSeries<T>
sum_of_fractions(const std::vector<T>& a, const std::vector<T>& b, const SubproductTree<T>& c) {
    int m = a.size(), n = 1 << bitop::ceil_log2(m);
    std::vector<FormalPowerSeries<T>> num(2 * n);
    rep (i, m) num[i + n] = {a[i]};
    rep (i, m, n) num[i + n] = {0};
    rrep (i, 1, n) {
        ntt_doubling_(num[i * 2 + 0]);
        ntt_doubling_(num[i * 2 + 1]);
        int k = num[i * 2 + 0].size();
        num[i].resize(k);
        rep (j, k) {
            num[i][j] = num[i * 2 + 0][j] * c.get_ntt(i * 2 + 1)[j]
                      + num[i * 2 + 1][j] * c.get_ntt(i * 2 + 0)[j];
        }
    }
    inverse_number_theoretic_transform(num[1]);
    return num[1];
}

template<class T, typename std::enable_if<
                      !is_ntt_friendly_modint<T>::value>::type* = nullptr>
FormalPowerSeries<T>
sum_of_fractions(const std::vector<T>& a, const std::vector<T>& b, const SubproductTree<T>& c) {
    int m = a.size(), n = 1 << bitop::ceil_log2(m);
    std::vector<FormalPowerSeries<T>> num(2 * n);
    rep (i, m) num[i + n] = {a[i]};
    rep (i, m, n) num[i + n] = {0};
    rrep (i, 1, n) {
        num[i] = num[i * 2 + 0] * c[i * 2 + 1] + num[i * 2 + 1] * c[i * 2 + 0];
    }
    return num[1];
}

} // namespace internal

// sum[i] a[i]/(1-b[i]x)
template<class T>
std::vector<FormalPowerSeries<T>, FormalPowerSeries<T>>
sum_of_fractions(const std::vector<T>& a, const std::vector<T>& b) {
    assert(a.size() == b.size());
    int n = a.size(), m = 1 << bitop::ceil_log2(n);
    SubproductTree<T> spt(b);
    return {sum_of_fractions(a, b, spt) >> (m - n), spt[1] >> (m - n)};
}

template<class T>
std::vector<T> multipoint_evaluation(const FormalPowerSeries<T>& a,
                                     const std::vector<T>& b) {
    if (a.empty() || b.empty()) return std::vector<T>(b.size(), T{0});
    if (a.size() <= 32 || b.size() <= 32) {
        std::vector<T> res(b.size());
        rep (i, b.size()) res[i] = a.eval(b[i]);
        return res;
    }
    return internal::multipoint_evaluation(a, b, SubproductTree(b));
}

template<class T>
std::vector<T> multipoint_evaluation_geometric(const FormalPowerSeries<T>& f,
                                               T a, T r, int m) {
    if (f.empty() || m == 0) return std::vector<T>(m, T{0});
    if (a == 0 || r == 1) return std::vector<T>(m, f.eval(a));
    if (f.size() <= 32 || m <= 32) {
        std::vector<T> res(m);
        rep (i, m) {
            res[i] = f.eval(a);
            a *= r;
        }
        return res;
    }
    if (r == 0) {
        std::vector<T> res(m, f.eval(0));
        res[0] = f.eval(a);
        return res;
    }
    int n = f.size();
    std::vector<T> p(n), q(n + m - 1);
    T ir = T{1} / r, t = 1, t2 = 1;
    rep (i, n) {
        p[i] = f[i] * t;
        t *= a * t2;
        t2 *= ir;
    }
    t = t2 = 1;
    rep (i, n + m - 1) {
        q[i] = t;
        t *= t2;
        t2 *= r;
    }
    std::vector<T> ans = middle_product(q, p);
    t = t2 = 1;
    rep (i, m) {
        ans[i] *= t;
        t *= t2;
        t2 *= ir;
    }
    return ans;
}

/**
 * @brief MultipointEvaluation(多点評価)
 * @docs docs/math/poly/MultipointEvaluation.md
 */
