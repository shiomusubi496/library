#pragma once

#include "../../other/template.hpp"

class PartialPersistentUnionFind {
private:
    int n;
    std::vector<int> par, tim;
    std::vector<std::vector<std::pair<int, int>>> sz_hist;
    int last_time;

public:
    PartialPersistentUnionFind() : PartialPersistentUnionFind(0) {}
    PartialPersistentUnionFind(int n)
        : n(n), par(n, -1), tim(n, infinity<int>::value), sz_hist(n, {{-1, 1}}),
          last_time(0) {}
    int now() const { return last_time - 1; }
    int find(int x, int t) const {
        assert(-1 <= t && t < last_time);
        assert(0 <= x && x < n);
        return tim[x] <= t ? find(par[x], t) : x;
    }
    int find_last(int x) const { return find(x, last_time - 1); }
    std::pair<std::pair<int, int>, int> merge(int x, int y) {
        x = find_last(x);
        y = find_last(y);
        if (x == y) return {{x, -1}, last_time++};
        if (par[x] > par[y]) std::swap(x, y);
        par[x] += par[y];
        par[y] = x;
        tim[y] = last_time;
        sz_hist[x].push_back({last_time, -par[x]});
        return {{x, y}, last_time++};
    }
    bool same(int x, int y, int t) const { return find(x, t) == find(y, t); }
    bool same_last(int x, int y) const { return same(x, y, last_time - 1); }
    int size(int x, int t) const {
        const auto& h = sz_hist[find(x, t)];
        return std::prev(
                   std::lower_bound(all(h), std::pair<int, int>{t + 1, -1}))
            ->second;
    }
    int size_last(int x) const {
        const auto& h = sz_hist[find_last(x)];
        return h.back().second;
    }
    std::vector<std::vector<int>> groups(int t) const {
        assert(-1 <= t && t < last_time);
        std::vector<std::vector<int>> res(n);
        rep (i, n) res[find(i, t)].push_back(i);
        res.erase(
            remove_if(all(res),
                      [](const std::vector<int>& v) { return v.empty(); }),
            res.end());
        return res;
    }
    std::vector<std::vector<int>> groups_last() const {
        return groups(last_time - 1);
    }
    bool is_root(int x, int t) const {
        assert(-1 <= t && t < last_time);
        assert(0 <= x && x < n);
        return tim[x] <= t;
    }
    bool is_root_last(int x) const { return is_root(x, last_time - 1); }
};

/**
 * @brief PartialPersistentUnionFind(部分永続UF)
 * @docs docs/data-struct/unionfind/PartialPersistentUnionFind.md
 */
