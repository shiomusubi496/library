#pragma once

#include "../../other/template.hpp"
#include "ProjectSelectionProblem.hpp"

template<class T> class KProjectSelectionProblem {
private:
    int n;
    std::vector<int> sz;
    std::vector<std::vector<int>> xs;
    ProjectSelectionProblem<T> psp;

public:
    using Cost0 = T;
    using Cost1 = std::vector<Cost0>;
    using Cost2 = std::vector<Cost1>;

public:
    KProjectSelectionProblem(std::vector<int> sz)
        : n(sz.size()), sz(sz), xs(n) {
        int m = 0;
        rep (i, n) {
            assert(sz[i] >= 1);
            xs[i].resize(sz[i] - 1);
            rep (j, sz[i] - 1) xs[i][j] = m++;
        }
        psp = ProjectSelectionProblem<T>(m);
        rep (i, n) {
            rep (j, sz[i] - 2) {
                psp.add_cost_10(xs[i][j], xs[i][j + 1], infinity<T>::value);
            }
        }
    }
    KProjectSelectionProblem(int n, int m)
        : KProjectSelectionProblem(std::vector<int>(n, m)) {}

    void add_cost(Cost0 c) { psp.add_cost(c); }
    void add_profit(Cost0 c) { psp.add_profit(c); }

    void add_cost(int i, Cost1 c) {
        assert(0 <= i && i < n);
        assert((int)c.size() == sz[i]);
        psp.add_cost(c.back());
        rep (j, sz[i] - 1) psp.add_cost_1(xs[i][j], c[j] - c[j + 1]);
    }
    void add_profit(int i, Cost1 c) {
        for (Cost0& x : c) x = -x;
        add_cost(i, c);
    }

    // c must be monge
    void add_cost(int i, int j, Cost2 c) {
        assert(0 <= i && i < n);
        assert(0 <= j && j < n);
        assert(i != j);
        assert((int)c.size() == sz[i]);
        rep (k, sz[i]) assert((int)c[k].size() == sz[j]);

        Cost1 ci(sz[i]), cj(sz[j]);
        rep (k, sz[i]) {
            ci[k] = c[k][0];
            rep (l, sz[j]) c[k][l] -= ci[k];
        }
        rep (l, sz[j]) {
            cj[l] = c[0][l];
            rep (k, sz[i]) c[k][l] -= cj[l];
        }
        add_cost(i, ci);
        add_cost(j, cj);
        rep (k, sz[i] - 1)
            rep (l, sz[j] - 1) {
                Cost0 cij =
                    c[k][l] + c[k + 1][l + 1] - c[k][l + 1] - c[k + 1][l];
                assert(cij <= 0); // monge
                psp.add_profit_00(xs[i][k], xs[j][l], -cij);
            }
    }
    void add_profit(int i, int j, Cost2 c) {
        for (Cost1& x : c)
            for (Cost0& y : x) y = -y;
        add_cost(i, j, c);
    }

    std::pair<Cost0, std::vector<int>> min_cost() {
        auto [c, x] = psp.min_cost();
        std::vector<int> res(n);
        rep (i, n) {
            rep (j, sz[i] - 1) {
                if (!x[xs[i][j]]) ++res[i];
            }
        }
        return {c, res};
    }
    std::pair<Cost0, std::vector<int>> max_profit() {
        auto res = min_cost();
        res.first = -res.first;
        return res;
    }
};

/**
 * @brief KProjectSelectionProblem(K値燃やす埋める)
 * @docs docs/graph/flow/KProjectSelectionProblem.md
 */
