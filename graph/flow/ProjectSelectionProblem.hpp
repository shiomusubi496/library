#pragma once

#include "../../other/template.hpp"
#include "MaxFlow.hpp"

template<class T> class ProjectSelectionProblem {
private:
    int n, naux;
    int source, sink;

public:
    using Cost0 = T;
    using Cost1 = std::array<Cost0, 2>;
    using Cost2 = std::array<Cost1, 2>;
    using Cost3 = std::array<Cost2, 2>;

private:
    Cost0 c0;
    std::vector<Cost1> c1;
    std::vector<std::tuple<int, int, Cost0>> edges;

    static constexpr Cost0 neg(Cost0 c) { return -c; }
    template<class U>
    static constexpr std::array<U, 2> neg(const std::array<U, 2>& c) {
        return {{neg(c[0]), neg(c[1])}};
    }

public:
    ProjectSelectionProblem() : ProjectSelectionProblem(0) {}
    ProjectSelectionProblem(int n)
        : n(n), naux(0), source(-1), sink(-2), c0(0), c1(n, {0, 0}) {}

    void add_cost(Cost0 c) { c0 += c; }
    void add_profit(Cost0 c) { c0 -= c; }
    void add_cost_0(int i, Cost0 c) { add_cost(i, Cost1{{c, 0}}); }
    void add_cost_1(int i, Cost0 c) { add_cost(i, Cost1{{0, c}}); }
    void add_profit_0(int i, Cost0 c) { add_cost(i, Cost1{{-c, 0}}); }
    void add_profit_1(int i, Cost0 c) { add_cost(i, Cost1{{0, -c}}); }
    void add_cost(int i, Cost1 c) {
        assert(0 <= i && i < n);
        c1[i][0] += c[0];
        c1[i][1] += c[1];
    }
    void add_profit(int i, Cost1 c) { add_cost(i, neg(c)); }

    void add_cost_01(int i, int j, Cost0 c) {
        assert(0 <= i && i < n);
        assert(0 <= j && j < n);
        assert(i != j);
        assert(c >= 0);
        edges.emplace_back(i, j, c);
    }
    // c must be submodular (c[0][0] + c[1][1] <= c[0][1] + c[1][0])
    void add_cost(int i, int j, Cost2 c) {
        assert(0 <= i && i < n);
        assert(0 <= j && j < n);
        assert(i != j);
        assert(c[0][0] + c[1][1] <= c[0][1] + c[1][0]);
        add_cost(c[0][0]);
        add_cost_1(i, c[1][0] - c[0][0]);
        add_cost_1(j, c[1][1] - c[1][0]);
        add_cost_01(i, j, c[0][1] + c[1][0] - c[0][0] - c[1][1]);
    }
    void add_profit(int i, int j, Cost2 c) { add_cost(i, j, neg(c)); }

    void add_cost_10(int i, int j, Cost0 c) { add_cost_01(j, i, c); }
    void add_cost_neq(int i, int j, Cost0 c) {
        add_cost(i, j, Cost2{{{0, c}, {c, 0}}});
    }
    void add_profit_00(int i, int j, Cost0 c) {
        add_cost(i, j, Cost2{{{-c, 0}, {0, 0}}});
    }
    void add_profit_11(int i, int j, Cost0 c) {
        add_cost(i, j, Cost2{{{0, 0}, {0, -c}}});
    }
    void add_profit_eq(int i, int j, Cost0 c) {
        add_cost(i, j, Cost2{{{-c, 0}, {0, -c}}});
    }

    template<class Cont> void add_profit_all_1(const Cont& cont, Cost0 c) {
        assert(c >= 0);
        if (cont.empty()) return add_profit(c);
        if (cont.size() == 1) return add_profit_1(cont[0], c);
        if (cont.size() == 2) return add_profit_11(cont[0], cont[1], c);
        int aux = n + naux++;
        add_profit(c);
        edges.emplace_back(aux, sink, c);
        for (int i : cont) edges.emplace_back(i, aux, c + 1);
    }
    template<class Cont> void add_profit_all_0(const Cont& cont, Cost0 c) {
        assert(c >= 0);
        if (cont.empty()) return add_profit(c);
        if (cont.size() == 1) return add_profit_0(cont[0], c);
        if (cont.size() == 2) return add_profit_00(cont[0], cont[1], c);
        int aux = n + naux++;
        add_profit(c);
        edges.emplace_back(source, aux, c);
        for (int i : cont) edges.emplace_back(aux, i, c + 1);
    }

    // c must be submodular (c[S&T] + c[S|T] <= c[S] + c[T])
    void add_cost(int i, int j, int k, Cost3 c) {
        assert(0 <= i && i < n);
        assert(0 <= j && j < n);
        assert(0 <= k && k < n);
        assert(i != j && j != k && k != i);
        const Cost0 A = c[0][0][0], B = c[0][0][1], C = c[0][1][0],
                    D = c[0][1][1], E = c[1][0][0], F = c[1][0][1],
                    G = c[1][1][0], H = c[1][1][1];
        const Cost0 P = (A + D + F + G) - (B + C + E + H);
        if (P >= 0) {
            const Cost0 P1 = F - B, P2 = G - E, P3 = D - C,
                        P12 = (C + E) - (A + G), P23 = (B + C) - (A + D),
                        P31 = (B + E) - (A + F);
            add_cost(A);
            add_cost_1(i, P1);
            add_cost_1(j, P2);
            add_cost_1(k, P3);
            add_cost_01(i, j, P12);
            add_cost_01(j, k, P23);
            add_cost_01(k, i, P31);
            add_profit_all_1(std::array<int, 3>{i, j, k}, P);
        }
        else {
            const Cost0 P1 = C - G, P2 = B - D, P3 = E - F,
                        P21 = (D + F) - (B + H), P32 = (F + G) - (E + H),
                        P13 = (D + G) - (C + H);
            add_cost(H);
            add_cost_0(i, P1);
            add_cost_0(j, P2);
            add_cost_0(k, P3);
            add_cost_01(j, i, P21);
            add_cost_01(k, j, P32);
            add_cost_01(i, k, P13);
            add_profit_all_0(std::array<int, 3>{i, j, k}, -P);
        }
    }

    std::pair<Cost0, std::vector<bool>> min_cost() {
        MaxFlow<Cost0> g(n + naux + 2);
        int s = n + naux, t = n + naux + 1;
        for (int i = 0; i < n; i++) {
            if (c1[i][0] == c1[i][1]) {
                add_cost(c1[i][0]);
            }
            else if (c1[i][0] < c1[i][1]) {
                add_cost(c1[i][0]);
                edges.emplace_back(s, i, c1[i][1] - c1[i][0]);
            }
            else {
                add_cost(c1[i][1]);
                edges.emplace_back(i, t, c1[i][0] - c1[i][1]);
            }
            c1[i][0] = c1[i][1] = 0;
        }
        for (const auto& [i, j, c] : edges) {
            int u = i == source ? s : i == sink ? t : i;
            int v = j == source ? s : j == sink ? t : j;
            g.add_edge(u, v, c);
        }
        auto f = g.flow(s, t) + c0;
        auto x = g.min_cut(s);
        x.resize(n);
        for (int i = 0; i < n; ++i) x[i] = !x[i];
        return {f, x};
    }
    std::pair<Cost0, std::vector<bool>> max_profit() {
        auto res = min_cost();
        res.first = -res.first;
        return res;
    }
};

/**
 * @brief ProjectSelectionProblem(燃やす埋める)
 * @docs docs/graph/flow/ProjectSelectionProblem.md
 */
