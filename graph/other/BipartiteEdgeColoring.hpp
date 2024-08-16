#pragma once

#include "../../other/template.hpp"
#include "../../data-struct/unionfind/UnionFind.hpp"
#include "../Graph.hpp"
#include "EulerianTrail.hpp"

template<class T> class BipartiteEdgeColoring {
private:
    int color_number;
    std::vector<int> edge_color;

    template<class U> std::vector<int> get_trails(int N, const Edges<U>& es) {
        UnionFind uf(2 * N);
        for (const auto& e : es) uf.merge(e.from, N + e.to);
        std::vector<int> res;
        std::vector<int> idx(2 * N, -1);
        std::vector<Graph<int>> G(2 * N);
        rep (i, 2 * N) {
            if (uf.is_root(i)) G[i].reserve(uf.size(i));
        }
        rep (i, 2 * N) {
            int r = uf.find(i);
            idx[i] = G[r].size();
            G[r].emplace_back();
        }
        rep (i, es.size()) {
            const auto& e = es[i];
            G[uf.find(e.from)].add_edge(idx[e.from], idx[N + e.to], (int)i);
        }
        res.reserve(es.size());
        rep (i, 2 * N) {
            if (G[i].size() == 0) continue;
            auto trail = EulerianTrail<int>(G[i], false).get_trail();
            for (const auto& e : trail) res.push_back(e.cost);
        }
        return res;
    }
    std::vector<int> bipartite_regular_matching(int N, const Edges<T>& es) {
        if (N == 0) return {};
        int D = es.size() / N;
        int D2 = 1 << bitop::ceil_log2(D);
        Edges<int> es2(D2 * N);
        rep (i, D * N) es2[i] = {es[i].from, es[i].to, (int)i};
        rep (i, N) {
            rep (j, D2 - D) es2[D * N + j * N + i] = {(int)i, (int)i, -1};
        }
        std::vector<int> res;
        while (true) {
            res.resize(D2 * N);
            std::iota(all(res), 0);
            while ((int)res.size() > N) {
                Edges<int> es3(res.size());
                rep (i, res.size()) es3[i] = es2[res[i]];
                auto trail = get_trails(2 * N, es3);
                int cnt1 = 0, cnt2 = 0;
                rep (i, trail.size()) {
                    if (i % 2 == 0) cnt1 += es3[trail[i]].cost == -1;
                    else cnt2 += es3[trail[i]].cost == -1;
                }
                std::vector<bool> used(res.size());
                rep (i, cnt1 < cnt2 ? 0 : 1, trail.size(), 2) {
                    used[trail[i]] = true;
                }
                int p = 0;
                rep (i, res.size()) {
                    if (used[i]) res[p++] = res[i];
                }
                res.resize(p);
            }
            bool f = true;
            rep (i, N) {
                if (es2[res[i]].cost == -1) {
                    f = false;
                    break;
                }
            }
            if (f) break;
            Edges<T> tmp = es2;
            rep (i, N) {
                rep (j, D2 - D) es2[D * N + j * N + i] = tmp[res[i]];
            }
        }
        std::vector<bool> used(es.size());
        rep (i, N) {
            used[es2[res[i]].cost] = true;
        }
        std::vector<int> res2;
        res2.reserve(res.size());
        rep (i, es.size()) {
            if (used[i]) res2.push_back(i);
        }
        return res2;
    }
    void solve(int L, int R, Edges<T> es) {
        if (es.empty()) {
            color_number = 0;
            return;
        }
        std::vector<int> degL(L), degR(R);
        for (auto e : es) {
            ++degL[e.from];
            ++degR[e.to];
        }
        int D = 0;
        rep (i, L) chmax(D, degL[i]);
        rep (i, R) chmax(D, degR[i]);
        std::vector<std::vector<int>> ndeg(2);
        {
            UnionFind uf(L);
            std::queue<int> que;
            rep (i, L) {
                if (degL[i] * 2 <= D) que.push(i);
            }
            while (que.size() >= 2) {
                int a = que.front();
                que.pop();
                int b = que.front();
                que.pop();
                auto p = uf.merge(a, b);
                std::tie(a, b) = p;
                degL[a] += degL[b];
                if (degL[a] * 2 <= D) que.push(a);
            }
            std::vector<int> idx(L, -1);
            rep (i, L) {
                int r = uf.find(i);
                if (idx[r] == -1) {
                    idx[r] = ndeg[0].size();
                    ndeg[0].push_back(degL[r]);
                }
            }
            for (auto& e : es) e.from = idx[uf.find(e.from)];
            L = ndeg[0].size();
        }
        {
            UnionFind uf(R);
            std::queue<int> que;
            rep (i, R) {
                if (degR[i] * 2 <= D) que.push(i);
            }
            while (que.size() >= 2) {
                int a = que.front();
                que.pop();
                int b = que.front();
                que.pop();
                auto p = uf.merge(a, b);
                std::tie(a, b) = p;
                degR[a] += degR[b];
                if (degR[a] * 2 <= D) que.push(a);
            }
            std::vector<int> idx(R, -1);
            rep (i, R) {
                int r = uf.find(i);
                if (idx[r] == -1) {
                    idx[r] = ndeg[1].size();
                    ndeg[1].push_back(degR[r]);
                }
            }
            for (auto& e : es) e.to = idx[uf.find(e.to)];
            R = ndeg[1].size();
        }
        int N = std::max(L, R);
        rep (i, 2) ndeg[i].resize(N);
        int M = es.size();
        es.reserve(D * N);
        int i = 0, j = 0;
        while (true) {
            while (i < N && ndeg[0][i] == D) ++i;
            while (j < N && ndeg[1][j] == D) ++j;
            if (i == N) break;
            ++ndeg[0][i];
            ++ndeg[1][j];
            es.emplace_back(i, j, T{}, (int)es.size());
        }
        std::vector<int> res(es.size());
        std::vector<int> p(es.size());
        std::iota(all(p), 0);
        rec_lambda([&](auto&& self, std::vector<int> p, int d, int b) -> void {
            Edges<T> es2;
            for (int i : p) es2.push_back(es[i]);
            if (d == 1) {
                for (int i : p) res[i] = b;
            }
            else if (d & 1) {
                auto q = bipartite_regular_matching(N, es2);
                for (int i : q) res[p[i]] = b;
                int j = 0;
                rep (i, p.size()) {
                    if (j < (int)q.size() && i == q[j]) ++j;
                    else p[i - j] = p[i];
                }
                p.resize(p.size() - q.size());
                self(std::move(p), d - 1, b + 1);
            }
            else {
                auto trail = get_trails(N, es2);
                std::vector<bool> used(p.size());
                rep (i, trail.size()) {
                    if (i % 2 == 0) used[trail[i]] = true;
                }
                std::vector<int> q, r;
                rep (i, p.size()) {
                    if (used[i]) q.push_back(p[i]);
                    else r.push_back(p[i]);
                }
                self(std::move(q), d / 2, b);
                self(std::move(r), d / 2, b + d / 2);
            }
        })(std::move(p), D, 0);
        res.resize(M);
        color_number = D;
        edge_color = res;
    }

public:
    BipartiteEdgeColoring(int L, int R, const Edges<T>& es) { solve(L, R, es); }
    int edge_chromatic_number() const { return color_number; }
    const std::vector<int>& get() const& { return edge_color; }
    std::vector<int> get() && { return std::move(edge_color); }
    int operator[](int i) const { return edge_color[i]; }
};
