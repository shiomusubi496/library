#pragma once

#include "../../other/template.hpp"
#include "../Graph.hpp"

template<class T>
int chromatic_number(const Graph<T>& G) {
    const int n = G.size();
    if (n == 0) return 0;
    if (n == 1) return 1;
    std::vector<int> adj(n, 0);
    rep (i, n) {
        for (const auto& e : G[i]) adj[i] |= 1 << e.to;
    }
    std::vector<ll> I(1 << n, 0);
    I[0] = 1;
    rep (i, 1, 1 << n) {
        int k = 0;
        rep (j, n) {
            if ((i >> j) & 1) k = j;
        }
        I[i] = I[i ^ (1 << k)] + I[(i ^ (1 << k)) & ~adj[k]];
    }
    static constexpr ll MOD = 998244353;
    std::vector<ll> p(1 << n, 1);
    rep (i, n - 1) {
        ll sm = 0;
        rep (j, 1 << n) {
            (p[j] *= I[j]) %= MOD;
            if (popcnt(j) & 1) {
                sm += p[j];
                if (sm >= MOD) sm -= MOD;
            }
            else {
                sm -= p[j];
                if (sm < 0) sm += MOD;
            }
        }
        if (sm != 0) return i + 1;
    }
    return n;
}

/**
 * @brief ChromaticNumber(彩色数)
 * @docs docs/graph/other/ChromaticNumber.md
 */
