#pragma once

#include "../../other/template.hpp"
#include "../Graph.hpp"
#include "../../data-struct/unionfind/UnionFind.hpp"

template<class T> std::pair<T, Edges<T>> Kruskal(int N, Edges<T> Ed) {
    std::sort(all(Ed));
    UnionFind UF(N);
    T res = 0;
    Edges<T> es;
    for (const auto& e : Ed) {
        if (UF.merge(e.from, e.to).second >= 0) {
            res += e.cost;
            es.push_back(e);
        }
    }
    return {res, es};
}

/**
 * @brief Kruskal(クラスカル法)
 * @docs docs/graph/mst/Kruskal.md
 */
