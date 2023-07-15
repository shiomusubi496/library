#pragma once

#include "../../other/template.hpp"
#include "FormalPowerSeries.hpp"

namespace internal {

template<class T> class ProductTree {
private:
    int n;
    std::vector<FormalPowerSeries<T>> dat;

public:
    ProductTree(const std::vector<T>& xs) {
        n = xs.size();
        dat.resize(n << 1);
        rep (i, n) dat[i + n] = FormalPowerSeries<T>{-xs[i], 1};
        rrep (i, n, 1) dat[i] = dat[i << 1] * dat[i << 1 | 1];
    }
    const FormalPowerSeries<T>& operator[](int k) const { return dat[k]; }
};

template<class T>
std::vector<T> multipoint_evaluation(const FormalPowerSeries<T>& a,
                                     const std::vector<T>& b,
                                     const ProductTree<T>& c) {
    int m = b.size();
    std::vector<FormalPowerSeries<T>> d(m << 1);
    d[1] = a % c[1];
    rep (i, 2, m << 1) d[i] = d[i >> 1] % c[i];
    std::vector<T> e(m);
    rep (i, m) e[i] = d[m + i].empty() ? T{0} : d[m + i][0];
    return e;
}

} // namespace internal

template<class T>
std::vector<T> multipoint_evaluation(const FormalPowerSeries<T>& a,
                                     const std::vector<T>& b) {
    if (a.empty() || b.empty()) return std::vector<T>(b.size(), T{0});
    if (a.size() <= 32 || b.size() <= 32) {
        std::vector<T> res(b.size());
        rep (i, b.size()) res[i] = a.eval(b[i]);
        return res;
    }
    return internal::multipoint_evaluation(a, b, internal::ProductTree<T>(b));
}

/**
 * @brief MultipointEvaluation(多点評価)
 * @docs docs/math/poly/MultipointEvaluation.md
 */
