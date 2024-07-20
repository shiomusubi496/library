#pragma once

#include "../../other/template.hpp"
#include "UnionFind.hpp"

UnionFind static_range_parallel_union_find(int n,
                                           std::vector<std::array<int, 3>> qs) {
    UnionFind uf(n);
    std::vector<std::vector<std::pair<int, int>>> es(n);
    for (const auto& [l, r, w] : qs) {
        assert(0 <= w);
        assert(0 <= l && l + w <= n);
        assert(0 <= r && r + w <= n);
        if (l == r || w == 0) continue;
        es[w - 1].emplace_back(l + w - 1, r + w - 1);
    }
    rrep (i, n) {
        for (const auto& [l, r] : es[i]) {
            if (uf.merge(l, r).second != -1 && i != 0) {
                es[i - 1].emplace_back(l - 1, r - 1);
            }
        }
    }
    return uf;
}

class RangeParallelUnionFind {
private:
    int h, n;
    std::vector<UnionFind> uf;
    void internal_merge(int l, int r, int k,
                        std::vector<std::pair<int, int>>& res) {
        auto p = uf[k].merge(l, r);
        if (p.second != -1) {
            if (k == 0) res.push_back(p);
            else {
                internal_merge(l, r, k - 1, res);
                internal_merge(l + (1 << (k - 1)), r + (1 << (k - 1)), k - 1,
                               res);
            }
        }
    }

public:
    RangeParallelUnionFind() : RangeParallelUnionFind(0) {}
    RangeParallelUnionFind(int n_) {
        n = n_;
        h = bitop::ceil_log2(n + 1);
        uf.assign(h, UnionFind(n));
    }
    std::vector<std::pair<int, int>> merge(int l, int r, int w) {
        assert(0 <= w);
        assert(0 <= l && l + w <= n);
        assert(0 <= r && r + w <= n);
        std::vector<std::pair<int, int>> res;
        if (l == r || w == 0) return res;
        int s = bitop::msb(w);
        internal_merge(l, r, s, res);
        internal_merge(l + w - (1 << s), r + w - (1 << s), s, res);
        return res;
    }
    int find(int x) { return uf[0].find(x); }
    bool same(int x, int y) { return uf[0].same(x, y); }
    int size(int x) { return uf[0].size(x); }
    std::vector<std::vector<int>> groups() { return uf[0].groups(); }
    bool is_root(int x) const { return uf[0].is_root(x); }
    UnionFind get_uf() const { return uf[0]; }
};

/**
 * @brief RangeParallelUnionFind
 * @docs docs/data-struct/unionfind/RangeParallelUnionFind.md
 */