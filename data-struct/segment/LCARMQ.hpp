#pragma once

#include "../../other/template.hpp"
#include "../../graph/tree/CartesianTree.hpp"
#include "../../graph/tree/PMORMQLCA.hpp"

template<class T> class LCARMQ {
private:
    int n;
    std::vector<T> v;
    std::pair<Graph<int>, int> G;
    PMORMQLCA<int> LCA;

public:
    LCARMQ(const std::vector<T>& v)
        : v(v), G(CartesianTree<T>(v).get_graph()), LCA(G.first, G.second) {
        n = v.size();
    }
    T prod(int l, int r) {
        assert(0 <= l && l < r && r <= n);
        return v[LCA.lca(l, r - 1)];
    }
};

/**
 * @brief LCARMQ
 * @docs docs/LCARMQ.md
 */
