#pragma once

#include "../../other/template.hpp"
#include "../../data-struct/segment/SparseTable.hpp"
#include "../Graph.hpp"

namespace Monoid {
    struct PairMinForEulerTour {
        using value_type = std::pair<int, int>;
        static value_type op(const value_type& a, const value_type& b) {
            return a.first < b.first ? a : b;
        }
        static value_type id() {
            return {infinity<int>::value, -1};
        }
    };
}

template<class T, template<class> class StaticRMQ = SparseTable>
class EulerTour {
  protected:
    int n, root, cnt;
    const Graph<T>& G;
    std::vector<int> dep;
    std::vector<std::pair<int, int>> idx;
    std::vector<std::pair<int, int>> rmqvec;
    StaticRMQ<Monoid::PairMinForEulerTour> RMQ;
    void dfs(int v, int p) {
        idx[v].first = cnt++;
        rmqvec.emplace_back(dep[v], v);
        for (const edge<T>& e : G[v]) {
            if (e.to == p) continue;
            dep[e.to] = dep[v] + 1;
            dfs(e.to, v);
            rmqvec.emplace_back(dep[v], v);
        }
        idx[v].second = cnt++;
    }
    void init() {
        n = G.size();
        dep.resize(n); dep[root] = 0;
        idx.resize(n); rmqvec.reserve(n << 1);
        cnt = 0;
        dfs(root, -1);
        rmqvec.emplace_back(infinity<int>::value, -1);
        RMQ.init(rmqvec);
    }
  public:
    EulerTour(const Graph<T>& G, int root = 0) : G(G), root(root) { init(); }
    const std::pair<int, int>& get_idx(int k) const& { return idx[k]; }
    std::pair<int, int> get_idx(int k) && { return std::move(idx[k]); }
    int lca(int u, int v) const {
        return RMQ.prod(
            std::min(idx[u].first, idx[v].first),
            std::max(idx[u].second, idx[v].second)
        ).second;
    }
    template<class F> void each_vertex_subtree(int v, const F& f) const {
        f(idx[v].first, idx[v].second + 1);
    }
    template<class F> void each_edge_subtree(int v, const F& f) const {
        f(idx[v].first + 1, idx[v].second + 1);
    }
    template<class F, class G> void each_vertex(int u, int v, const F& f, const G& g) const {
        int l = lca(u, v);
        g(idx[l].first, idx[u].first + 1);
        f(idx[l].first + 1, idx[v].first + 1);
    }
    template<class F> void each_vertex(int u, int v, const F& f) const { each_vertex(u, v, f, f); }
    template<class F, class G> void each_edge(int u, int v, const F& f, const G& g) const {
        int l = lca(u, v);
        g(idx[l].first + 1, idx[u].first + 1);
        f(idx[l].first + 1, idx[v].first + 1);
    }
    template<class F> void each_edge(int u, int v, const F& f) const { each_edge(u, v, f, f); }
};
