#pragma once

#include "../../other/template.hpp"
#include "../Graph.hpp"

template<class T> class ThreeEdgeConnectedComponents {
private:
    int n, cnt;
    const Graph<T>& G;
    std::vector<int> ord, low, lowv, low2, lowv2, nd;
    std::vector<bool> is_cut;
    std::vector<std::stack<std::tuple<int, int, bool, int, int>>> st;
    std::vector<int> link;

    void dfs(int v, int pid) {
        ord[v] = low[v] = low2[v] = cnt++;
        lowv[v] = lowv2[v] = v;
        std::vector<int> tes;
        int tl = -1, tv = -1;
        for (const auto& e : G[v]) {
            if (e.idx == pid) continue;
            if (ord[e.to] == -1) {
                dfs(e.to, e.idx);
                nd[v] += nd[e.to];
                tes.push_back(e.idx);
                if (ord[v] < low[e.to]) {
                    is_cut[e.idx] = true;
                    continue;
                }
                if (!st[e.to].empty() && std::get<4>(st[e.to].top()) == e.to) {
                    const auto [i, y, b, p, _] = st[e.to].top();
                    st[e.to].pop();
                    is_cut[i] = is_cut[e.idx] = true;
                    link[y] = v;
                    if (p != v) st[e.to].emplace(i, y, b, p, v);
                }
                if (low[e.to] < low[v]) {
                    low2[v] = low[v];
                    lowv2[v] = lowv[v];
                    low[v] = low[e.to];
                    lowv[v] = lowv[e.to];
                    st[v] = std::move(st[e.to]);
                    tl = e.idx;
                    tv = e.to;
                }
                else if (low[e.to] < low2[v]) {
                    low2[v] = low[e.to];
                    lowv2[v] = lowv[e.to];
                }
            }
            else if (ord[e.to] < ord[v]) {
                if (ord[e.to] <= low[v]) {
                    low2[v] = low[v];
                    lowv2[v] = lowv[v];
                    low[v] = ord[e.to];
                    lowv[v] = e.to;
                    while (!st[v].empty()) st[v].pop();
                    tl = e.idx;
                    tv = e.to;
                }
                else if (ord[e.to] < low2[v]) {
                    low2[v] = ord[e.to];
                    lowv2[v] = e.to;
                }
            }
        }
        if (st[v].empty()) {
            if (low[v] < low2[v])
                st[v].emplace(tl, tv, ord[tv] < ord[v], lowv[v], lowv2[v]);
        }
        else {
            const auto [i, y, b, p, q] = st[v].top();
            if (ord[q] < low2[v])
                st[v].emplace(tl, tv, ord[tv] < ord[v], q, lowv2[v]);
            else {
                while (!st[v].empty() &&
                       low2[v] <= ord[std::get<3>(st[v].top())])
                    st[v].pop();
                if (!st[v].empty()) {
                    const auto [i, y, b, p, q] = st[v].top();
                    if (low2[v] < ord[q]) {
                        st[v].pop();
                        st[v].emplace(i, y, b, p, lowv2[v]);
                    }
                }
            }
        }
        int k = 0;
        for (const auto& e : G[v]) {
            if (ord[e.to] <= ord[v]) continue;
            if (k < (int)tes.size() && tes[k] == e.idx) {
                ++k;
                continue;
            }
            while (!st[v].empty()) {
                const auto [i, y, b, p, q] = st[v].top();
                if (!b && ord[y] <= ord[e.to] && ord[e.to] < ord[y] + nd[y])
                    st[v].pop();
                else break;
            }
        }
    }

    int sz;
    std::vector<int> cmp;
    std::vector<std::vector<int>> G2;

    void dcmp(int v) {
        for (const auto& e : G[v]) {
            if (cmp[e.to] != -1) continue;
            if (is_cut[e.idx]) continue;
            cmp[e.to] = cmp[v];
            dcmp(e.to);
        }
        for (const auto& e : G2[v]) {
            if (cmp[e] != -1) continue;
            cmp[e] = cmp[v];
            dcmp(e);
        }
    }

public:
    ThreeEdgeConnectedComponents(const Graph<T>& G) : n(G.size()), G(G) {
        ord.assign(n, -1);
        low.assign(n, n + 1);
        lowv.assign(n, -1);
        low2.assign(n, n + 1);
        lowv2.assign(n, -1);
        nd.assign(n, 1);
        is_cut.assign(G.edge_size(), false);
        st.resize(n);
        link.assign(n, -1);
        cnt = 0;
        rep (i, n) {
            if (ord[i] == -1) dfs(i, -1);
        }
        G2.resize(n);
        rep (i, n) {
            if (link[i] != -1) {
                G2[i].push_back(link[i]);
                G2[link[i]].push_back(i);
            }
        }
        sz = 0;
        cmp.assign(n, -1);
        rep (i, n) {
            if (cmp[i] == -1) {
                cmp[i] = sz++;
                dcmp(i);
            }
        }
    }
    int size() const { return sz; }
    int operator[](int k) const { return cmp[k]; }
    std::vector<std::vector<int>> groups() const {
        std::vector<std::vector<int>> res(sz);
        rep (i, n) res[cmp[i]].push_back(i);
        return res;
    }
    bool is_cut_edge(int k) const { return is_cut[k]; }
};

/**
 * @brief ThreeEdgeConnectedComponents(三辺連結成分分解)
 * @docs docs/graph/connected/ThreeEdgeConnectedComponents.md
 */
