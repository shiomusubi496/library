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
    template<class U = int> std::pair<Graph<U>, int> get_graph() const {
        Graph<U> res(n);
        int root = 0;
        rep (i, n) {
            if (par[i] == -1) root = i;
            else res.add_edge(i, par[i]);
        }
        return {res, root};
    }
    template<class F>
    ll count_range(F&& f) const {
        auto [G, root] = get_graph();
        ll ans = 0;
        rec_lambda([&](auto&& self, int m, int l, int r) -> void {
            if (m - l < r - m) {
                rep (i, l, m + 1) {
                    int ok = m, ng = r + 1;
                    while (ng - ok > 1) {
                        int mid = (ok + ng) / 2;
                        (f(m, i, mid) ? ok : ng) = mid;
                    }
                    ans += ok - m;
                }
            }
            else {
                rep (i, m + 1, r + 1) {
                    int ok = m + 1, ng = l - 1;
                    while (ok - ng > 1) {
                        int mid = (ok + ng) / 2;
                        (f(m, mid, i) ? ok : ng) = mid;
                    }
                    ans += m + 1 - ok;
                }
            }
            for (auto e : G[m]) {
                if (l <= e.to && e.to < m) self(e.to, l, m);
                else if (m < e.to && e.to < r) self(e.to, m + 1, r);
            }
        })(root, 0, n);
        return ans;
    }
};

/**
 * @brief CartesianTree
 * @docs docs/graph/tree/CartesianTree.md
 */