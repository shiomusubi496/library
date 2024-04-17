#pragma once

#include "../../other/template.hpp"
#include "../Graph.hpp"
#include "../../data-struct/unionfind/UnionFind.hpp"

template<class T> std::pair<T, Edges<T>> Prim(const Graph<T>& G) {
    const int N = G.size();
    std::vector<bool> seen(N, false);
    seen[0] = true;
    prique<edge<T>> que;
    each_const (e : G[0]) que.emplace(e);
    T res = 0;
    Edges<T> es;
    while (!que.empty()) {
        const edge<T> cre = que.top();
        que.pop();
        if (seen[cre.to]) continue;
        res += cre.cost;
        es.push_back(cre);
        seen[cre.to] = true;
        each_const (e : G[cre.to]) {
            if (seen[e.to]) continue;
            que.emplace(e);
        }
    }
    return {res, es};
}

/**
 * @brief Prim(プリム法)
 * @docs docs/graph/mst/Prim.md
 */
