#pragma once

#include "../../other/template.hpp"
#include "../../data-struct/unionfind/UnionFind.hpp"
#include "../Graph.hpp"
#include "../../other/monoid.hpp"
#include "../../data-struct/heap/SkewHeap.hpp"

template<class T> class DirectedMST {
private:
    struct Act {
        struct M {
            using value_type = edge<T>;
        };
        using E = Monoid::Sum<T>;
        static edge<T> op(const T& x, const edge<T>& y) {
            return {y.from, y.to, x + y.cost, y.idx};
        }
    };
    using heap = SkewHeap<edge<T>, std::greater<edge<T>>, Act>;

    T res;
    bool exist;
    Edges<T> edges_;

public:
    DirectedMST(int n, const Edges<T>& es, int root) {
        std::vector<heap> heaps(n);
        for (const auto& e : es) heaps[e.to].push(e);
        UnionFind uf(n);
        res = 0;
        exist = true;
        std::vector<int> seen(n, -1);
        seen[root] = root;
        std::vector<int> par_e(es.size(), -1), memo(es.size(), -1);
        std::vector<edge<T>> par(n);
        std::vector<int> idx;
        std::vector<int> st;
        int sz = 0;
        st.reserve(n);
        rep (s, n) {
            if (seen[s] != -1) continue;
            int v = s;
            while (seen[v] == -1 || seen[v] == s) {
                seen[v] = s;
                if (heaps[v].empty()) {
                    exist = false;
                    return;
                }
                auto e = heaps[v].top();
                heaps[v].pop();
                int u = uf.find(e.from);
                if (u == v) continue;

                par[v] = e;
                if (memo[v] == -1) memo[v] = e.idx;
                res += e.cost;
                idx.push_back(e.idx);
                while (sz) {
                    par_e[st.back()] = e.idx;
                    st.pop_back();
                    --sz;
                }
                st.push_back(e.idx);

                if (seen[u] == s) {
                    int w = v;
                    do {
                        heaps[w].apply(-par[w].cost);
                        if (w != v) {
                            int x, y;
                            std::tie(x, y) = uf.merge(v, w);
                            heaps[x].meld(std::move(heaps[y]));
                            v = x;
                        }
                        w = uf.find(par[w].from);
                        ++sz;
                    } while (w != v);
                }
                else v = u;
            }
        }
        std::reverse(all(idx));
        std::vector<bool> used(es.size(), false);
        edges_.reserve(n - 1);
        for (int i : idx) {
            if (used[i]) continue;
            auto e = es[i];
            edges_.push_back(e);
            int x = memo[e.to];
            while (x != i) {
                used[x] = true;
                x = par_e[x];
            }
        }
    }
    bool has_mst() const { return exist; }
    T cost() const { return res; }
    const Edges<T>& edges() const& { return edges_; }
    Edges<T> edges() && { return std::move(edges_); }
};

/**
 * @brief DirectedMST(最小有向全域木)
 * @docs docs/graph/mst/DirectedMST.md
 */
