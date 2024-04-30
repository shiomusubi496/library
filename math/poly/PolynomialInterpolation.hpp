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

template<class T>
FormalPowerSeries<T> polynomial_interpolation_geometric(T a, T r, std::vector<T> ys) {
    int n = ys.size();
    if (n == 0) return {};
    if (n == 1) return {ys[0]};
    assert(a != 0 && r != 1);
    if (r == 0) {
        assert(n == 2);
        return {ys[1], (ys[0] - ys[1]) / a};
    }
    std::vector<T> p(n + 1), q(n + 1);
    p[0] = q[0] = 1;
    reps (i, n) {
        p[i] = p[i - 1] * r;
        q[i] = q[i - 1] * (1 - p[i]);
    }
    T v = 1;
    rep (i, n) {
        ys[i] /= v * q[i] * q[n - 1 - i];
        if (i % 2) ys[i] = -ys[i];
        if (i != n - 1) v *= p[n - 2 - i];
    }
    FormalPowerSeries<T> res1(n + 1);
    v = 1;
    rep (i, n + 1) {
        if (i == 0 || i == n) res1[i] = v * q[0];
        else res1[i] = v * q[n] / (q[i] * q[n - i]);
        if (i % 2) res1[i] = -res1[i];
        if (i != n) v *= p[i];
    }
    FormalPowerSeries<T> res2 = multipoint_evaluation_geometric(FormalPowerSeries<T>(ys), T{1}, r, n);
    auto res = (res1 * res2).prefix(n);
    reverse(all(res));
    T ainv = 1 / a;
    v = 1;
    rep (i, n) {
        res[i] *= v;
        v *= ainv;
    }
    return res;
}

/**
 * @brief PolynomialInterpolation(多項式補間)
 * @docs docs/math/poly/PolynomialInterpolation.md
 */
