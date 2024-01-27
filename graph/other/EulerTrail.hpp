#pragma once

#include "../../other/template.hpp"
#include "../Graph.hpp"

template<class T>
class EulerTrail {
private:
    int n;
    const Graph<T>& G;
    bool flag = false;
    Edges<T> trail;
    std::vector<int> idx;
    std::vector<bool> used;

    void build(int s) {
        if (s == -1) {
            s = 0;
            rep (i, n) {
                if (!G[i].empty()) {
                    s = i;
                    break;
                }
            }
        }
        idx.assign(n, 0);
        used.assign(G.edge_size(), false);
        trail.resize(G.edge_size());
        int l = 0, r = G.edge_size();
        while (l < r) {
            if (idx[s] < (int)G[s].size()) {
                const auto& e = G[s][idx[s]++];
                if (used[e.idx]) continue;
                used[e.idx] = true;
                trail[l++] = e;
                s = e.to;
            }
            else {
                if (l == 0) return;
                trail[--r] = std::move(trail[--l]);
                s = trail[r].from;
            }
        }
        rep (i, n) {
            const int S = G[i].size();
            while (idx[i] < S && used[G[i][idx[i]].idx]) ++idx[i];
            if (idx[i] != S) return;
        }
        flag = true;
        return;
    }

public:
    EulerTrail(const Graph<T>& G, bool directed) : G(G) {
        n = G.size();
        if (directed) build_directed();
        else build_undirected();
    }

    void build_undirected() {
        std::vector<int> odds;
        rep (i, G.size()) {
            if (G[i].size() & 1) odds.push_back(i);
        }
        if (odds.size() > 2) return;
        build(odds.empty() ? -1 : odds[0]);
    }
    void build_directed() {
        std::vector<int> deg(n);
        std::vector<int> s, g;
        rep (i, n) {
            for (auto e : G[i]) {
                ++deg[e.from];
                --deg[e.to];
            }
        }
        rep (i, n) {
            if (deg[i] == 1) s.push_back(i);
            else if (deg[i] == -1) g.push_back(i);
            else if (deg[i] != 0) return;
        }
        if (s.size() != g.size() || s.size() > 1) return;
        build(s.empty() ? -1 : s[0]);
    }

    bool has_trail() const { return flag; }
    const Edges<T>& get_trail() const& { return trail; }
    Edges<T> get_trail() && { return std::move(trail); }
};
