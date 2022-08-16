#pragma once

#include "../../other/template.hpp"
#include "../Graph.hpp"
#include "../../data-struct/unionfind/UnionFind.hpp"

template<class T> T Prim(const Graph<T>& G) {
    const int N = G.size();
    std::vector<bool> seen(N, false);
    seen[0] = true;
    prique<edge<T>> que;
    each_const (e : G[0]) que.emplace(e);
    T res = 0;
    while (!que.empty()) {
        const edge<T> cre = que.top();
        que.pop();
        if (seen[cre.to]) continue;
        res += cre.cost;
        seen[cre.to] = true;
        each_const (e : G[cre.to]) {
            if (seen[e.to]) continue;
            que.emplace(e);
        }
    }
    return res;
}

template<class T> Edges<T> Prim_vec(const Graph<T>& G) {
    const int N = G.size();
    std::vector<bool> seen(N, false);
    seen[0] = true;
    prique<edge<T>> que;
    each_const (e : G[0]) que.emplace(e);
    Edges<T> res;
    while (!que.empty()) {
        const edge<T> cre = que.top();
        que.pop();
        if (seen[cre.to]) continue;
        res.emplace(cre);
        seen[cre.to] = true;
        each_const (e : G[cre.to]) {
            if (seen[e.to]) continue;
            que.emplace(e);
        }
    }
    return res;
}

/**
 * @brief Prim(プリム法)
 * @docs docs/Prim.md
 */
