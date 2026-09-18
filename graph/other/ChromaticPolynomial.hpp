#pragma once

#include "../../other/template.hpp"
#include "../Graph.hpp"
#include "../../math/poly/SetPowerSeries.hpp"
#include "../../math/poly/PolynomialInterpolation.hpp"

template<class T, class U> FormalPowerSeries<T> chromatic_polynomial(const Graph<U>& G) {
    int n = G.size();
    std::vector<int> adj(n);
    rep (i, n) {
        for (const auto& e : G[i]) adj[i] |= 1 << e.to;
    }
    std::vector<T> a(1 << n);
    rep (i, 1 << n) {
        bool f = true;
        rep (j, n) {
            if ((i >> j & 1) && (i & adj[j])) f = false;
        }
        if (f) a[i] = 1;
    }
    std::vector<T> b(1 << n);
    b[(1 << n) - 1] = 1;
    std::vector<T> c = power_projection_of_sps(a, b, n + 1);
    std::vector<T> d(n + 1);
    rep (i, n + 1) d[i] = i;
    return polynomial_interpolation(d, c);
}
