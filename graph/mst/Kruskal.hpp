#pragma once

#include "../../other/template.hpp"
#include "../Graph.hpp"
#include "../../data-struct/unionfind/UnionFind.hpp"

template<class T> T Kruskal(int N, Edges<T> Ed) {
    std::sort(all(Ed));
    UnionFind UF(N);
    T res = 0;
    each_const (e : Ed) {
        if (UF.merge(e.from, e.to).second >= 0) res += e.cost;
    }
    return res;
}

template<class T> Edges<T> Kruskal_vec(int N, Edges<T> Ed) {
    std::sort(all(Ed));
    UnionFind UF(N);
    Edges<T> res;
    each_const (e : Ed) {
        if (UF.merge(e.from, e.to).second >= 0) res.push_back(e);
    }
    return res;
}

/**
 * @brief Kruskal(クラスカル法)
 * @docs docs/graph/mst/Kruskal.md
 */
