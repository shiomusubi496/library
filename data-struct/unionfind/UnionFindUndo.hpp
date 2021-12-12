#pragma once

#include "../../other/template.hpp"

class UnionFindUndo {
  protected:
    int n;
    std::vector<int> par_vec;
    std::stack<std::pair<int, int>> hist;
  public:
    UnionFindUndo() : UnionFindUndo(0) {}
    UnionFindUndo(int n) : n(n), par_vec(n, -1) {}
    int find(int x) const {
        assert(0 <= x && x < n);
        return par_vec[x] < 0 ? x : find(par_vec[x]);
    }
    std::pair<int, int> merge(int x, int y) {
        x = find(x);
        y = find(y);
        hist.emplace(x, par_vec[x]);
        hist.emplace(y, par_vec[y]);
        if (x == y) return {x, -1};
        if (par_vec[x] > par_vec[y]) std::swap(x, y);
        par_vec[x] += par_vec[y];
        par_vec[y] = x;
        return {x, y};
    }
    bool same(int x, int y) const {
        return find(x) == find(y);
    }
    int size(int x) const {
        return -par_vec[find(x)];
    }
    std::vector<std::vector<int>> groups() const {
        std::vector<std::vector<int>> res(n);
        rep (i, n) res[find(i)].push_back(i);
        res.erase(
            remove_if(all(res), [](const std::vector<int>& v) { return v.empty(); }),
            res.end()
        );
        return res;
    }
    bool is_root(int x) const {
        assert(0 <= x && x < n);
        return par_vec[x] < 0;
    }
    void undo() {
        par_vec[hist.top().first] = hist.top().second; hist.pop();
        par_vec[hist.top().first] = hist.top().second; hist.pop();
    }
    void snapshot() {
        while (!hist.empty()) hist.pop();
    }
    void rollback() {
        while (!hist.empty()) undo();
    }
};

/**
 * @brief UnionFindUndo(Undo可能UnionFind)
 * @docs docs/UnionFindUndo.md
 */
