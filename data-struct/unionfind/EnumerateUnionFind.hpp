#pragma once

#include "../../other/template.hpp"
#include "UnionFind.hpp"

class EnumerateUnionFind {
private:
    int n;
    std::vector<int> link;
    UnionFind uf;

public:
    EnumerateUnionFind() : EnumerateUnionFind(0) {}
    EnumerateUnionFind(int n) : n(n), link(n, -1), uf(n) {}
    int find(int x) { return uf.find(x); }
    std::pair<int, int> merge(int x, int y) {
        auto res = uf.merge(x, y);
        if (res.second != -1) std::swap(link[res.first], link[res.second]);
        return res;
    }
    bool same(int x, int y) { return uf.same(x, y); }
    int size(int x) { return uf.size(x); }
    std::vector<std::vector<int>> groups() { return uf.groups(); }
    bool is_root(int x) const { return uf.is_root(x); }
    std::vector<int> enumerate(int x) const {
        assert(0 <= x && x < n);
        std::vector<int> res;
        do {
            res.push_back(x);
            x = link[x];
        } while (res[0] != x);
        return res;
    }
};
