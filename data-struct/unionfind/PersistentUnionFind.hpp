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
        int p = par.get(x, t);
        return p < 0 ? x : internal_find(p, t);
    }

public:
    PersistentUnionFind() : PersistentUnionFind(0) {}
    PersistentUnionFind(int n)
        : n(n), par(std::vector<int>(n, -1)), tim(1, -1), last_time(0) {}
    int now() const { return last_time - 1; }
    int find(int x, int t) const {
        assert(-1 <= t && t < last_time);
        assert(0 <= x && x < n);
        return internal_find(x, tim[t + 1]);
    }
    int find_last(int x) const { return find(x, last_time - 1); }
    std::pair<std::pair<int, int>, int> merge(int x, int y, int t) {
        x = find(x, t);
        y = find(y, t);
        if (x == y) {
            tim.push_back((int)tim[t + 1]);
            return {{x, -1}, last_time++};
        }
        int px = par.get(x, tim[t + 1]), py = par.get(y, tim[t + 1]);
        if (px > py) std::swap(x, y);
        par.set(x, px + py, tim[t + 1]);
        par.set_last(y, x);
        tim.push_back(par.now());
        return {{x, y}, last_time++};
    }
    bool same(int x, int y, int t) const { return find(x, t) == find(y, t); }
    bool same_last(int x, int y) const { return same(x, y, last_time - 1); }
    int size(int x, int t) const { return -par.get(x, tim[t + 1]); }
    int size_last(int x) const { return size(x, last_time - 1); }
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
        return par.get(x, tim[t + 1]) < 0;
    }
    bool is_root_last(int x) const { return is_root(x, last_time - 1); }
};

/**
 * @brief PersistentUnionFind(完全永続UF)
 * @docs docs/data-struct/unionfind/PersistentUnionFind.md
 */
