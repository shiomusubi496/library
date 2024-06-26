#pragma once

#include "../../other/template.hpp"
#include "../Graph.hpp"
#include "Kruskal.hpp"

template<class T> class ManhattanMST {
private:
    std::vector<std::pair<T, T>> ps;
    T res;
    Edges<T> es;

public:
    ManhattanMST(const std::vector<std::pair<T, T>>& ps_) : ps(ps_) {
        int n = ps.size();
        std::vector<T> xs(n), ys(n);
        rep (i, n) {
            xs[i] = ps[i].first;
            ys[i] = ps[i].second;
        }
        std::vector<int> ord(n);
        std::iota(all(ord), 0);
        rep (s, 2) {
            rep (t, 2) {
                std::sort(all(ord), [&](int i, int j) {
                    return xs[i] + ys[i] < xs[j] + ys[j];
                });
                std::map<T, int> mp;
                for (int i : ord) {
                    for (auto it = mp.lower_bound(-ys[i]); it != mp.end();
                         it = mp.erase(it)) {
                        int j = it->second;
                        if (xs[i] - ys[i] < xs[j] - ys[j]) break;
                        es.emplace_back(i, j,
                                        std::abs(xs[i] - xs[j]) +
                                            std::abs(ys[i] - ys[j]));
                    }
                    mp[-ys[i]] = i;
                }
                swap(xs, ys);
            }
            rep (i, n) xs[i] = -xs[i];
        }
        std::tie(res, es) = Kruskal(n, es);
    }
    T cost() const { return res; }
    const Edges<T>& edges() const& { return es; }
    Edges<T> edges() && { return std::move(es); }
};

/**
 * @brief Manhattan Minimum Spanning Tree
 * @docs docs/graph/mst/ManhattanMST.md
 */
