#pragma once

#include "../../other/template.hpp"

template<class T> class MaxFlow {
private:
    struct edge_ {
        int to, rev;
        T cap;
    };

    int n;
    std::vector<std::vector<edge_>> g;
    std::vector<std::pair<int, int>> pos;

public:
    struct edge {
        int from, to;
        T cap, flow;
    };

    MaxFlow() : n(0) {}
    explicit MaxFlow(int n) : n(n), g(n) {}

    int add_edge(int from, int to, T cap) {
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        assert(0 <= cap);
        pos.emplace_back(from, (int)(g[from].size()));
        g[from].push_back({to, (int)(g[to].size()), cap});
        g[to].push_back({from, (int)(g[from].size()) - 1, T{0}});
        return (int)(pos.size()) - 1;
    }
    edge get_edge(int i) {
        int m = (int)(pos.size());
        assert(0 <= i && i < m);
        const auto& e = g[pos[i].first][pos[i].second];
        const auto& re = g[e.to][e.rev];
        return edge{pos[i].first, e.to, e.cap + re.cap, re.cap};
    }
    std::vector<edge> edges() {
        int m = (int)(pos.size());
        std::vector<edge> res(m);
        for (int i = 0; i < m; i++) res[i] = get_edge(i);
        return res;
    }
    T flow(int s, int t) { return flow(s, t, infinity<T>::max); }
    T flow(int s, int t, T flow_limit) {
        assert(0 <= s && s < n);
        assert(0 <= t && t < n);
        assert(s != t);
        T res = T{0};
        while (res < flow_limit) {
            std::vector<int> dist(n, -1);
            {
                std::queue<int> que;
                que.push(s);
                dist[s] = 0;
                while (!que.empty()) {
                    int v = que.front();
                    que.pop();
                    for (const auto& e : g[v]) {
                        if (e.cap > T{0} && dist[e.to] == -1) {
                            dist[e.to] = dist[v] + 1;
                            que.push(e.to);
                        }
                    }
                }
            }
            std::vector<int> idx(n, 0);
            T f = rec_lambda([&](auto&& self, int v, T f) -> T {
                if (v == t) return f;
                T res = 0;
                for (int& i = idx[v]; i < (int)(g[v].size()); i++) {
                    auto& e = g[v][i];
                    if (e.cap > T{0} && dist[v] + 1 == dist[e.to]) {
                        T d = self(e.to, std::min(f - res, e.cap));
                        if (d == T{0}) continue;
                        e.cap -= d;
                        g[e.to][e.rev].cap += d;
                        res += d;
                        if (res == f) return res;
                    }
                }
                return res;
            })(s, flow_limit - res);
            if (f == T{0}) break;
            res += f;
        }
        return res;
    }
    std::vector<bool> min_cut(int s) const {
        assert(0 <= s && s < n);
        std::vector<bool> visited(n);
        std::queue<int> que;
        que.push(s);
        visited[s] = true;
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (const auto& e : g[v]) {
                if (e.cap > T{0} && !visited[e.to]) {
                    visited[e.to] = true;
                    que.push(e.to);
                }
            }
        }
        return visited;
    }
};

/**
 * @brief MaxFlow(最大流)
 * @docs docs/graph/flow/MaxFlow.md
 */
