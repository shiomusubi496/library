#pragma once

#include "../../other/template.hpp"
#include "../Graph.hpp"

template<class T, class Comp = std::less<T>> class CartesianTree {
private:
    int n;
    const std::vector<T>& v;
    std::vector<int> par;
    Comp cmp;
    void init() {
        n = v.size();
        par.assign(n, -1);
        rep (i, 1, n) {
            int p = i - 1;
            int lst = -1;
            while (p != -1 && cmp(v[i], v[p])) {
                lst = p;
                p = par[p];
            }
            if (lst != -1) par[lst] = i;
            par[i] = p;
        }
    }

public:
    CartesianTree(const std::vector<T>& v) : v(v), cmp(Comp()) { init(); }
    CartesianTree(const std::vector<T>& v, const Comp& cmp) : v(v), cmp(cmp) {
        init();
    }
    const std::vector<int>& get_vec() const& { return par; }
    std::vector<int> get_vec() && { return std::move(par); }
    template<class U = int> std::pair<Graph<U>, int> get_graph() {
        Graph<U> res(n);
        int root = 0;
        rep (i, n) {
            if (par[i] == -1) root = i;
            else res.add_edge(i, par[i]);
        }
        return {res, root};
    }
};

/**
 * @brief CartesianTree
 * @docs docs/graph/tree/CartesianTree.md
 */