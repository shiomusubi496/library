#pragma once

#include "../other/template.hpp"
#include "SimpleLARSCH.hpp"
#include "FibonacciSearch.hpp"

// 下に凸な関数 f に対し、 g(p)=min_x(f(x)-px)
template<class F, class T>
function_result_type<F> alien_dp_convex(function_result_type<F> low,
                                        function_result_type<F> high, T x,
                                        F&& g) {
    using U = function_result_type<F>;
    return FibonacciSearch<U>::maximize(low, high,
                                        [&](U p) { return g(p) + p * x; })
        .second;
}
// 上に凸な関数 f に対し、 g(p)=max_x(f(x)-px)
template<class F, class T>
function_result_type<F> alien_dp_concave(function_result_type<F> low,
                                         function_result_type<F> high, T x,
                                         F&& g) {
    using U = function_result_type<F>;
    return FibonacciSearch<U>::minimize(low, high,
                                        [&](U p) { return g(p) + p * x; })
        .second;
}


template<class F>
function_result_type<F>
k_edge_shortest_path(int n, int k, function_result_type<F> mx, F&& f) {
    return alien_dp_convex(-3 * mx, 3 * mx, k, [&](ll p) {
        return simple_larsch(n, [&](int i, int j) { return f(i, j) - p; })
            .back();
    });
}

/**
 * @brief AlienDP
 * @docs docs/dp/AlienDP.md
 * @see
 * https://noshi91.github.io/algorithm-encyclopedia/d-edge-shortest-path-monge
 */
