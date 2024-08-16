#pragma once

#include "../../other/template.hpp"
#include "../other/PersistentArray.hpp"

class PersistentUnionFind {
private:
    int n;
    PersistentArray<int, 4> par;
    std::vector<int> tim;
    int last_time;
    int internal_find(int x, int t) const {
        int p = par.get(t, x);
        return p < 0 ? x : internal_find(p, t);
    }

public:
    PersistentUnionFind() : PersistentUnionFind(0) {}
    PersistentUnionFind(int n)
        : n(n), par(std::vector<int>(n, -1)), tim(1, -1), last_time(0) {}
    int now() const { return last_time - 1; }
    int find(int t, int x) const {
        assert(-1 <= t && t < last_time);
        assert(0 <= x && x < n);
        return internal_find(x, tim[t + 1]);
    }
    int find_last(int x) const { return find(last_time - 1, x); }
    std::pair<std::pair<int, int>, int> merge(int t, int x, int y) {
        x = find(t, x);
        y = find(t, y);
        if (x == y) {
            tim.push_back((int)tim[t + 1]);
            return {{x, -1}, last_time++};
        }
        int px = par.get(tim[t + 1], x), py = par.get(tim[t + 1], y);
        if (px > py) std::swap(x, y);
        par.set(tim[t + 1], x, px + py);
        par.set_last(y, x);
        tim.push_back(par.now());
        return {{x, y}, last_time++};
    }
    bool same(int t, int x, int y) const { return find(t, x) == find(t, y); }
    bool same_last(int x, int y) const { return same(last_time - 1, x, y); }
    int size(int t, int x) const { return -par.get(tim[t + 1], x); }
    int size_last(int x) const { return size(last_time - 1, x); }
    std::vector<std::vector<int>> groups(int t) const {
        assert(-1 <= t && t < last_time);
        std::vector<std::vector<int>> res(n);
        rep (i, n) res[find(t, i)].push_back(i);
        res.erase(
            remove_if(all(res),
                      [](const std::vector<int>& v) { return v.empty(); }),
            res.end());
        return res;
    }
    std::vector<std::vector<int>> groups_last() const {
        return groups(last_time - 1);
    }
    bool is_root(int t, int x) const {
        assert(-1 <= t && t < last_time);
        assert(0 <= x && x < n);
        return par.get(tim[t + 1], x) < 0;
    }
    bool is_root_last(int x) const { return is_root(last_time - 1, x); }
};

/**
 * @brief PersistentUnionFind(完全永続UF)
 * @docs docs/data-struct/unionfind/PersistentUnionFind.md
 */
