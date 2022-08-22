#pragma once

#include "../../other/template.hpp"

class UnionFind {
private:
    int n;
    std::vector<int> par;

public:
    UnionFind() : UnionFind(0) {}
    UnionFind(int n) : n(n), par(n, -1) {}
    int find(int x) {
        assert(0 <= x && x < n);
        return par[x] < 0 ? x : par[x] = find(par[x]);
    }
    std::pair<int, int> merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return {x, -1};
        if (par[x] > par[y]) std::swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return {x, y};
    }
    bool same(int x, int y) { return find(x) == find(y); }
    int size(int x) { return -par[find(x)]; }
    std::vector<std::vector<int>> groups() {
        std::vector<std::vector<int>> res(n);
        rep (i, n) res[find(i)].push_back(i);
        res.erase(
            remove_if(all(res),
                      [](const std::vector<int>& v) { return v.empty(); }),
            res.end());
        return res;
    }
    bool is_root(int x) const {
        assert(0 <= x && x < n);
        return par[x] < 0;
    }
};

/**
 * @brief UnionFind
 * @docs docs/data-struct/unionfind/UnionFind.md
 */
