#pragma once

#include "../../other/template.hpp"
#include "../../random/Random.hpp"
#include "../../string/RollingHash.hpp"
#include "../tree/ReRooting.hpp"
#include "../Graph.hpp"

class TreeHash {
private:
    static constexpr ull MASK31 = (1ull << 31) - 1;
    using mint = modint61;
    std::vector<mint> base;
    void init(int n) {
        int m = base.size();
        if (m >= n) return;
        base.resize(n);
        rep (i, m, n) base[i] = mint::raw((1ull << 31) + (rand32() & MASK31));
    }

    template<class T>
    int dfs(const Graph<T>& G, std::vector<mint>& ans, int v, int p) {
        mint res = 1;
        int dep = 0;
        for (const auto& e : G[v]) {
            if (e.to == p) continue;
            int d = dfs(G, ans, e.to, v);
            chmax(dep, d);
            res *= ans[e.to] + base[d];
        }
        if ((int)base.size() == dep) {
            base.push_back(mint::raw((1ull << 31) + (rand32() & MASK31)));
        }
        ans[v] = res;
        return dep + 1;
    }

    struct M {
        using value_type = std::pair<mint, int>;
        static value_type id() { return {1, 0}; }
        static value_type op(const value_type& a, const value_type& b) {
            return {a.first * b.first, std::max(a.second, b.second)};
        }
    };
    template<class T>
    std::pair<mint, int> f(const std::pair<mint, int>& a, const edge<T>& b) {
        if ((int)base.size() == a.second) {
            base.push_back(mint::raw((1ull << 31) + (rand32() & MASK31)));
        }
        return {a.first + base[a.second], a.second + 1};
    }

public:
    template<class T>
    std::vector<mint> get_hash(const Graph<T>& G, int root = 0) {
        int n = G.size();
        std::vector<mint> ans(n);
        dfs(G, ans, root, -1);
        return ans;
    }
    template<class T>
    std::pair<std::vector<std::vector<mint>>, std::vector<mint>>
    get_hash_rerooting(const Graph<T>& G) {
        auto f = [&](const std::pair<mint, int>& a,
                     const edge<T>&) -> std::pair<mint, int> {
            if ((int)base.size() == a.second) {
                base.push_back(mint::raw((1ull << 31) + (rand32() & MASK31)));
            }
            return {a.first + base[a.second], a.second + 1};
        };
        auto rr = ReRooting<M, T, decltype(f)>(G, f);
        std::vector<std::vector<mint>> dp(G.size());
        std::vector<mint> res(G.size());
        rep (i, G.size()) {
            dp[i].resize(G[i].size());
            rep (j, G[i].size()) dp[i][j] = rr.get_dp(i, j).first;
            res[i] = rr[i].first;
        }
        return {dp, res};
    }
};

/**
 * @brief TreeHash
 * @docs docs/graph/tree/TreeHash.md
 */
