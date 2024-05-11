#pragma once

#include "../../other/template.hpp"
#include "../../data-struct/segment/SegmentTree.hpp"
#include "../Graph.hpp"

namespace Monoid {
struct PairMinForEulerTour {
    using value_type = std::pair<int, int>;
    static value_type op(const value_type& a, const value_type& b) {
        return a.first < b.first ? a : b;
    }
    static value_type id() { return {infinity<int>::value, -1}; }
};
} // namespace Monoid

template<class T, class StaticRMQ = SegmentTree<Monoid::PairMinForEulerTour>>
class EulerTour {
private:
    int n, cnt;
    std::vector<int> root;
    const Graph<T>& G;
    std::vector<int> dep;
    std::vector<std::pair<int, int>> idx;
    std::vector<std::pair<int, int>> rmqvec;
    StaticRMQ RMQ;
    void dfs(int v, int p) {
        idx[v].first = cnt++;
        rmqvec.emplace_back(dep[v], v);
        for (const auto& e : G[v]) {
            if (e.to == p) continue;
            dep[e.to] = dep[v] + 1;
            dfs(e.to, v);
            rmqvec.emplace_back(dep[v], v);
        }
        idx[v].second = cnt++;
    }
    void init() {
        n = G.size();
        dep.assign(n, 0);
        idx.assign(n, {-1, -1});
        rmqvec.reserve(n << 1);
        cnt = 0;
        for (const auto& r : root) {
            dfs(r, -1);
            rmqvec.emplace_back(-1, -1);
        }
        rep (i, n) {
            if (idx[i].first != -1) continue;
            dfs(i, -1);
            rmqvec.emplace_back(-1, -1);
        }
        RMQ.init(rmqvec);
    }

public:
    EulerTour(const Graph<T>& G, int root = 0) : root({root}), G(G) { init(); }
    EulerTour(const Graph<T>& G, const std::vector<int>& root)
        : root(root), G(G) {
        init();
    }
    const std::pair<int, int>& get_idx(int k) const& { return idx[k]; }
    std::pair<int, int> get_idx(int k) && { return std::move(idx[k]); }
    int get_par(int a, int b) const { return dep[a] < dep[b] ? a : b; }
    int lca(int u, int v) const {
        return RMQ
            .prod(std::min(idx[u].first, idx[v].first),
                  std::max(idx[u].second, idx[v].second))
            .second;
    }
    template<class F> void each_vertex_subtree(int v, const F& f) const {
        f(idx[v].first, idx[v].second + 1);
    }
    template<class F> void each_edge_subtree(int v, const F& f) const {
        f(idx[v].first + 1, idx[v].second + 1);
    }
    template<class F> void each_vertex(int u, int v, const F& f) const {
        each_vertex(u, v, f, f);
    }
    template<class F, class G>
    void each_vertex(int u, int v, const F& f, const G& g) const {
        int l = lca(u, v);
        g(idx[l].first, idx[u].first + 1);
        f(idx[l].first + 1, idx[v].first + 1);
    }
    template<class F> void each_edge(int u, int v, const F& f) const {
        each_edge(u, v, f, f);
    }
    template<class F, class G>
    void each_edge(int u, int v, const F& f, const G& g) const {
        int l = lca(u, v);
        g(idx[l].first + 1, idx[u].first + 1);
        f(idx[l].first + 1, idx[v].first + 1);
    }
};

/**
 * @brief EulerTour(オイラーツアー)
 * @docs docs/graph/tree/EulerTour.md
 */
