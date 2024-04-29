#pragma once

#include "../Graph.hpp"
#include "../mst/CountSpanningTree.hpp"
#include "../../math/Combinatorics.hpp"

template<class T, class U, class Comb = Combinatorics<T>> T count_eulerian_trail(const Graph<U>& G) {
    int N = G.size();
    std::vector<int> degi(N), dego(N);
    rep (i, N) {
        for (const auto& e : G[i]) {
            degi[e.to] += e.cost;
            dego[i] += e.cost;
        }
    }
    rep (i, N) {
        if (degi[i] != dego[i]) return 0;
    }
    std::vector<bool> used(N);
    rep (i, N) {
        for (const auto& e : G[i]) {
            if (e.cost) used[i] = used[e.to] = true;
        }
    }
    std::vector<int> idx(N, -1);
    int M = 0;
    rep (i, N) {
        if (used[i]) idx[i] = M++;
    }
    Graph<U> H(M);
    rep (i, N) {
        for (auto& e : G[i]) {
            if (e.cost) H.add_edge(idx[i], idx[e.to], e.cost, true);
        }
    }
    T res = count_spanning_tree<T>(H);
    rep (i, N) {
        if (dego[i] != 0) res *= Comb::fact(dego[i] - 1);
    }
    return res;
}

/**
 * @brief CountEulerianTrail(BEST Theorem)
 * @docs docs/graph/mst/CountEulerianTrail.md
 */
