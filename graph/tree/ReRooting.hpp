#pragma once

#include "../Graph.hpp"

#include "../../other/monoid.hpp"

template<class M, class T, class F>
class ReRooting {
  protected:
    using U = typename M::value_type;
    const F& f;
    int n;
    const Graph<T>& G;
    std::vector<U> init_data;
    std::vector<std::vector<U>> dp;
    std::vector<U> res;
    std::vector<int> par;
    void dfs1(int v, int p) {
        rep (i, G[v].size()) {
            const auto& e = G[v][i];
            if (e.to == p) par[v] = i;
            else dfs1(e.to, v);
        }
        rep (i, G[v].size()) {
            const auto& e = G[v][i];
            if (e.to == p) continue;
            dp[v][par[v]] = M::op(dp[v][par[v]], f(dp[e.to][par[e.to]], edge<T>{e.to, v, e.cost, e.idx}));
        }
        if (p != -1 && G[v].size() == 1) {
            dp[v][par[v]] = init_data[v];
        }
    }
    void dfs2(int v, int p, int v_id) {
        std::vector<U> memo(G[v].size());
        rep (i, G[v].size()) {
            const auto& e = G[v][i];
            memo[i] = f(dp[e.to][e.to == p ? v_id : par[e.to]], edge<T>{e.to, v, e.cost, e.idx});
        }
        dp[v][G[v].size() - 1] = M::id();
        rrep (i, (int)G[v].size() - 1) {
            dp[v][i] = M::op(memo[i + 1], dp[v][i + 1]);
        }
        U sml = M::id();
        rep (i, G[v].size()) {
            dp[v][i] = M::op(sml, dp[v][i]);
            sml = M::op(sml, std::move(memo[i]));
        }
        dp[v].back() = std::move(sml);
        if (G[v].size() == 1) {
            dp[v][p == -1 ? 0 : par[v]] = std::move(init_data[v]);
        }
        rep (i, G[v].size()) {
            const auto& e = G[v][i];
            if (e.to != p) dfs2(e.to, v, i);
        }
    }
    void init() {
        n = G.size();
        if (n == 1) {
            res = std::move(init_data);
            dp.assign(1, std::vector<U>{});
            return;
        }
        dp.resize(n);
        rep (i, n) dp[i].assign(G[i].size() + 1, M::id());
        par.resize(n); par[0] = G[0].size();
        dfs1(0, -1);
        dfs2(0, -1, -1);
        res.resize(n);
        rep (i, n) {
            res[i] = std::move(dp[i].back());
            dp[i].pop_back();
        }
    }
  public:
    ReRooting(const Graph<T>& G, const F& f) : ReRooting(G, f, std::vector<U>(G.size(), M::id())) {}
    ReRooting(const Graph<T>& G, const F& f, const std::vector<U>& ind) : f(f), G(G), init_data(ind) { init(); }
    ReRooting(const Graph<T>& G, const F& f, std::vector<U>&& ind) : f(f), G(G), init_data(std::move(ind)) { init(); }
    const std::vector<U>& get_res() const& { return res; }
    std::vector<U> get_res() && { return std::move(res); }
    const U& operator[](int v) const& { return res[v]; }
    U operator[](int v) && { return std::move(res[v]); }
    const std::vector<std::vector<U>>& get_dp() const& { return dp; }
    std::vector<std::vector<U>> get_dp() && { return std::move(dp); }
    const U& get_dp(int v, int p_idx) const& { return dp[v][p_idx]; }
    U get_dp(int v, int p_idx) && { return std::move(dp[v][p_idx]); }
};

/**
 * @brief ReRooting(全方位木DP)
 * @docs docs/ReRooting.md
 */
