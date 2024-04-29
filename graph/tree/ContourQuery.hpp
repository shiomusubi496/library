#pragma once

#include "../../other/template.hpp"
#include "../Graph.hpp"
#include "TreeCentroid.hpp"

template<class T, bool weighted = false> class ContourQuery {
private:
    int n;
    const Graph<T>& G;
    UnweightedGraph H;
    int root;

    std::vector<int> par, dep;
    std::vector<std::vector<T>> dist;
    std::queue<std::pair<int, T>> que;
    std::vector<std::vector<std::pair<T, int>>> vt;
    std::vector<std::vector<std::vector<std::pair<T, int>>>> ct;
    std::vector<std::vector<int>> cpar, idx, rdx1, rdx2, ddx1;
    std::vector<std::vector<std::vector<int>>> ddx2, ddx3, ddx4;

    void build_dfs(int v, int p, int d) {
        par[v] = p;
        dep[v] = d;
        for (auto e : H[v]) build_dfs(e.to, v, d + 1);
    }

    void dfs(int v) {
        int d = dep[v];
        vt[v].emplace_back(0, v);
        ct[v].resize(G[v].size());
        cpar[v][d] = v;
        dist[v][d] = 0;
        rep (i, G[v].size()) {
            const auto& e = G[v][i];
            if (dep[e.to] < d) continue;
            cpar[e.to][d] = i;
            dist[e.to][d] = e.cost;
            que.emplace(e.to, e.cost);
        }
        while (!que.empty()) {
            auto [u, d2] = que.front();
            que.pop();
            int c = cpar[u][d];
            vt[v].emplace_back(d2, u);
            ct[v][c].emplace_back(d2, u);
            rep (i, G[u].size()) {
                const auto& e = G[u][i];
                if (dep[e.to] < d) continue;
                if (cpar[e.to][d] != -1) continue;
                cpar[e.to][d] = c;
                dist[e.to][d] = d2 + e.cost;
                que.emplace(e.to, d2 + e.cost);
            }
        }
        if IF_CONSTEXPR (weighted) {
            std::sort(all(vt[v]));
            for (auto& ctv : ct[v]) std::sort(all(ctv));
        }
        for (auto e : H[v]) dfs(e.to);
    }

public:
    template<class F> ContourQuery(const Graph<T>& G, F&& f) : G(G) {
        n = G.size();
        CentroidDecomposition<T> cd(G);
        root = cd.get_root();
        H = cd.get();

        par.assign(n, -1);
        dep.assign(n, -1);
        build_dfs(root, -1, 0);
        int h = *std::max_element(all(dep)) + 1;
        vt.assign(n, {});
        ct.assign(n, {});
        cpar.assign(n, std::vector<int>(h, -1));
        dist.assign(n, std::vector<T>(h, -1));
        dfs(root);

        rdx1.assign(n, std::vector<int>(h, -1));
        rdx2.assign(n, std::vector<int>(h, -1));
        std::vector<std::vector<int>> dat(2 * n);
        rep (i, n) {
            dat[i].resize(vt[i].size());
            rep (j, vt[i].size()) {
                dat[i][j] = vt[i][j].second;
                rdx1[vt[i][j].second][dep[i]] = j;
            }
        }
        idx.resize(n);
        int cnt = n;
        rep (i, n) {
            idx[i].resize(ct[i].size());
            rep (j, ct[i].size()) {
                if (ct[i][j].empty()) continue;
                dat[cnt].resize(ct[i][j].size());
                rep (k, ct[i][j].size()) {
                    dat[cnt][k] = ct[i][j][k].second;
                    rdx2[ct[i][j][k].second][dep[i]] = k;
                }
                idx[i][j] = cnt++;
            }
        }
        f(dat);
        if IF_CONSTEXPR (weighted) {
            ddx2.resize(n);
            rep (i, n) {
                ddx2[i].resize(ct[i].size());
                rep (j, 1, vt[i].size()) {
                    ddx2[i][cpar[vt[i][j].second][dep[i]]].push_back(j);
                }
            }
        }
        else {
            ddx1.resize(n);
            rep (i, n) {
                T m = vt[i].back().first;
                ddx1[i].assign(m + 1, -1);
                rep (j, vt[i].size()) {
                    if (ddx1[i][vt[i][j].first] == -1) {
                        ddx1[i][vt[i][j].first] = j;
                    }
                }
            }
            ddx2.resize(n);
            ddx3.resize(n);
            ddx4.resize(n);
            rep (i, n) {
                ddx2[i].resize(ct[i].size());
                ddx3[i].resize(ct[i].size());
                ddx4[i].resize(ct[i].size());
                rep (j, ct[i].size()) {
                    if (ct[i][j].empty()) continue;
                    T m = ct[i][j].back().first;
                    ddx2[i][j].assign(m + 1, -1);
                    ddx3[i][j].assign(m + 1, -1);
                    ddx4[i][j].assign(m + 1, -1);
                    rep (k, ct[i][j].size()) {
                        if (ddx4[i][j][ct[i][j][k].first] == -1) {
                            ddx4[i][j][ct[i][j][k].first] = k;
                        }
                    }
                }
                rep (j, 1, vt[i].size()) {
                    int cp = cpar[vt[i][j].second][dep[i]];
                    if (ddx2[i][cp][vt[i][j].first] == -1) {
                        ddx2[i][cp][vt[i][j].first] = j;
                    }
                    ddx3[i][cp][vt[i][j].first] = j;
                }
            }
        }
    }
    template<class F> void vertex(int v, F&& f) const {
        int d = dep[v];
        f(v, 0);
        int u = v;
        while (d > 0) {
            --d;
            int p = par[u];
            int cp = cpar[u][d];
            f(p, rdx1[v][d]);
            f(idx[p][cp], rdx2[v][d]);
            u = p;
        }
    }
    template<class F> void contour(int v, T k, F&& f) const {
        if IF_CONSTEXPR (weighted) {
            int itrl =
                std::lower_bound(all(vt[v]), std::pair(k, -1)) - vt[v].begin();
            int itrr =
                std::lower_bound(all(vt[v]), std::pair(k, n)) - vt[v].begin();
            f(v, itrl, itrr);
        }
        else {
            if (k < (T)ddx1[v].size()) {
                int l = ddx1[v][k];
                int r =
                    k + 1 < (T)ddx1[v].size() ? ddx1[v][k + 1] : vt[v].size();
                f(v, l, r);
            }
        }
        int d = dep[v];
        int u = v;
        while (d > 0) {
            --d;
            k -= dist[v][d];
            int p = par[u];
            int cp = cpar[u][d];
            if IF_CONSTEXPR (weighted) {
                if (0 <= k) {
                    int l = std::lower_bound(all(vt[p]), std::pair(k, -1)) -
                        vt[p].begin();
                    int r = std::lower_bound(all(vt[p]), std::pair(k, n)) -
                        vt[p].begin();
                    int l2 = std::lower_bound(all(ct[p][cp]), std::pair(k, -1)) -
                        ct[p][cp].begin();
                    int r2 = std::lower_bound(all(ct[p][cp]), std::pair(k, n)) -
                        ct[p][cp].begin();
                    if (l2 == r2) f(p, l, r);
                    else {
                        if (l2 < ct[p][cp].size()) f(p, l, ddx2[p][cp][l2]);
                        if (r2 < ct[p][cp].size()) f(p, ddx3[p][cp][r2], r);
                    }
                }
            }
            else {
                if (0 <= k && k < (T)ddx1[p].size()) {
                    int l = ddx1[p][k];
                    int r =
                        k + 1 < (T)ddx1[p].size() ? ddx1[p][k + 1] : vt[p].size();
                    if (k < (int)ddx2[p][cp].size()) {
                        int l2 = ddx2[p][cp][k];
                        int r2 = ddx3[p][cp][k] + 1;
                        f(p, l, l2);
                        f(p, r2, r);
                    }
                    else {
                        f(p, l, r);
                    }
                }
            }
            k += dist[v][d];
            u = p;
        }
    }
    template<class F, class G>
    void range_contour(int v, T k, F&& f, G&& g) const {
        if IF_CONSTEXPR (weighted) {
            int itrr = std::lower_bound(all(vt[v]), std::pair(k, -1)) - vt[v].begin();
            f(v, itrr);
        }
        else {
            int r = k < (T)ddx1[v].size() ? ddx1[v][k] : vt[v].size();
            f(v, r);
        }
        int d = dep[v];
        int u = v;
        while (d > 0) {
            --d;
            k -= dist[v][d];
            int p = par[u];
            int cp = cpar[u][d];
            if (0 < k) {
                if IF_CONSTEXPR (weighted) {
                    int r = std::lower_bound(all(vt[p]), std::pair(k, -1)) -
                        vt[p].begin();
                    f(p, r);
                    int r2 = std::lower_bound(all(ct[p][cp]), std::pair(k, -1)) -
                        ct[p][cp].begin();
                    g(idx[p][cp], r2);
                }
                else {
                    int r = k < (T)ddx1[p].size() ? ddx1[p][k] : vt[p].size();
                    f(p, r);
                    int r2 = k < (T)ddx4[p][cp].size() ? ddx4[p][cp][k]
                                                    : ct[p][cp].size();
                    g(idx[p][cp], r2);
                }
            }
            k += dist[v][d];
            u = p;
        }
    }
    template<class F, class G>
    void range_contour(int v, T l, T r, F&& f, G&& g) const {
        range_contour(v, l, g, f);
        range_contour(v, r, f, g);
    }
};
