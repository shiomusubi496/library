#pragma once

#include "../../other/template.hpp"
#include "../Graph.hpp"
#include "../connected/StronglyConnectedComponents.hpp"

class TwoSatisfiability {
  protected:
    int n;
    UnweightedGraph G;
  public:
    TwoSatisfiability() : TwoSatisfiability(0) {}
    TwoSatisfiability(int n) : n(n), G(2 * n) {}
    int neg(int t) const {
        return t < n ? t + n : t - n;
    }
    void add_clause(int i, bool f, int j, bool g) {
        assert(0 <= i && i < n);
        assert(0 <= j && j < n);
        if (!f) i = neg(i);
        if (!g) j = neg(j);
        G.add_edge(neg(i), j, true);
        G.add_edge(neg(j), i, true);
    }
    void add_or  (int a, int b) { add_clause(a, true , b, true ); }
    void add_if  (int a, int b) { add_clause(a, false, b, true ); }
    void add_nand(int a, int b) { add_clause(a, false, b, false); }
    void add_eq(int a, int b) {
        add_clause(a, true , b, false);
        add_clause(a, false, b, true );
    }
    void add_neq(int a, int b) {
        add_clause(a, true , b, true );
        add_clause(a, false, b, false);
    }
    void add_true(int a) {
        assert(0 <= a && a < n);
        G.add_edge(neg(a), a, true);
    }
    void add_false(int a) {
        assert(0 <= a && a < n);
        G.add_edge(a, neg(a), true);
    }
    std::vector<bool> sat() const {
        StronglyConnectedComponents<unweighted_edge> SCC(G);
        std::vector<bool> res(n);
        rep (i, n) {
            if (SCC[i] == SCC[neg(i)]) return {};
            res[i] = SCC[neg(i)] < SCC[i];
        }
        return res;
    }
};

/**
 * @brief TwoSatisfiability(2-SAT)
 * @docs docs/TwoSatisfiability.md
 */
