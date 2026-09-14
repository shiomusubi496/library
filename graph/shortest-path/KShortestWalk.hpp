#pragma once

#include "../../other/template.hpp"
#include "../../data-struct/heap/LeftistHeap.hpp"
#include "Dijkstra.hpp"

template<class T>
class KShortestWalk {
private:
    using heap = LeftistHeap<edge<T>, std::greater<edge<T>>>;

    const Graph<T>& G, RG;
    int n, s, t, K;
    std::vector<heap> H;
    std::vector<T> ans;

public:
    KShortestWalk(const Graph<T>& G_, int s_, int t_, int k_) : G(G_), RG(ReverseGraph(G_)), n(G_.size()), s(s_), t(t_), K(k_) {
        std::vector<T> dist = Dijkstra(RG, t);
        std::vector<int> prv(n, -1);
        std::queue<int> que;
        prv[t] = -2;
        que.push(t);
        H.resize(n);
        while (!que.empty()) {
            int v = que.front(); que.pop();
            for (const auto& e : G[v]) {
                if (prv[v] != e.idx && dist[e.to] != infinity<T>::value) {
                    H[v].emplace(v, e.to, e.cost + dist[e.to] - dist[v], e.idx);
                }
            }
            for (const auto& e : RG[v]) {
                if (dist[e.to] == dist[v] + e.cost && prv[e.to] == -1) {
                    prv[e.to] = e.idx;
                    que.push(e.to);
                    H[e.to].meld(H[v]);
                }
            }
        }
        using PTN = std::pair<T, typename heap::node_ptr>;
        auto cmp = [](const PTN& a, const PTN& b) { return a.first > b.first; };
        std::priority_queue<PTN, std::vector<PTN>, decltype(cmp)> pq(cmp);
        ans.clear();
        heap h;
        if (dist[s] != infinity<T>::value) {
            h.emplace(-1, s, dist[s], -1);
            pq.emplace(dist[s], h.get_root());
        }
        while (!pq.empty() && (int)ans.size() < K) {
            T c = pq.top().first;
            auto nd = pq.top().second;
            pq.pop();
            ans.push_back(c);
            if (nd->l) pq.emplace(c + nd->l->val.cost - nd->val.cost, nd->l);
            if (nd->r) pq.emplace(c + nd->r->val.cost - nd->val.cost, nd->r);
            if (!H[nd->val.to].empty()) {
                pq.emplace(c + H[nd->val.to].get_root()->val.cost, H[nd->val.to].get_root());
            }
        }
        ans.resize(K, -1);
    }
    std::vector<T> get() const { return ans; }
};
