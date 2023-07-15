#pragma once

#include "../../other/template.hpp"
#include "FormalPowerSeries.hpp"
#include "MultipointEvaluation.hpp"

template<class T>
FormalPowerSeries<T> polynomial_interpolation(const std::vector<T>& xs,
                                              const std::vector<T>& ys) {
    internal::ProductTree<T> pt(xs);
    std::vector<T> c = internal::multipoint_evaluation(pt[1].diff(), xs, pt);
    std::queue<FormalPowerSeries<T>> que1, que2;
    rep (i, xs.size()) {
        que1.emplace(FormalPowerSeries<T>{ys[i] / c[i]});
        que2.emplace(FormalPowerSeries<T>{-xs[i], 1});
    }
    while (que1.size() > 1) {
        auto f1 = que1.front();
        que1.pop();
        auto f2 = que2.front();
        que2.pop();
        auto g1 = que1.front();
        que1.pop();
        auto g2 = que2.front();
        que2.pop();
        que1.emplace(f1 * g2 + f2 * g1);
        que2.emplace(f2 * g2);
    }
    que1.front().resize(xs.size());
    return que1.front();
}

/**
 * @brief PolynomialInterpolation(多項式補間)
 * @docs docs/math/poly/PolynomialInterpolation.md
 */
