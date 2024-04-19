#pragma once

#include "../../other/template.hpp"
#include "../../other/monoid.hpp"

template<class M, bool = Monoid::is_monoid<M>::value> class WeightedUnionFind {
private:
    using T = typename M::value_type;
    int n;
    std::vector<int> par;
    std::vector<T> wei;

public:
    WeightedUnionFind() : WeightedUnionFind(0) {}
    WeightedUnionFind(int n) : n(n), par(n, -1), wei(n, M::id()) {}
    int find(int x) {
        assert(0 <= x && x < n);
        if (par[x] < 0) return x;
        int r = find(par[x]);
        wei[x] = M::op(wei[x], wei[par[x]]);
        return par[x] = r;
    }
    T weight(int x) { return find(x), wei[x]; }
    T diff(int x, int y) {
        assert(find(x) == find(y));
        return M::inv(wei[y], wei[x]);
    }
    std::pair<int, int> merge(int x, int y, T w) {
        w = M::inv(M::op(weight(x), w), weight(y));
        x = find(x);
        y = find(y);
        if (x == y) {
            if (w == M::id()) return {x, -1};
            else return {x, -2};
        }
        if (par[x] > par[y]) std::swap(x, y), w = M::get_inv(w);
        par[x] += par[y];
        par[y] = x;
        wei[y] = w;
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

template<class T>
class WeightedUnionFind<T, false> : public WeightedUnionFind<Monoid::Sum<T>> {
private:
    using Base = WeightedUnionFind<Monoid::Sum<T>>;

public:
    using Base::Base;
};

/**
 * @brief WeightedUnionFind(重み付きUF)
 * @docs docs/data-struct/unionfind/WeightedUnionFind.md
 */
