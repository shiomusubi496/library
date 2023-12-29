#pragma once

#include "../../other/template.hpp"
#include "../Graph.hpp"
#include "../other/LowLink.hpp"

template<class T> class BiConnectedComponents : public LowLink<T> {
private:
    int sz;
    std::vector<int> cmp;
    std::vector<std::vector<int>> grp;
    std::vector<int> tmp, tmp2;
    std::vector<bool> seen;
    void dfs(int v, int id) {
        seen[v] = true;
        tmp2.push_back(v);
        for (const auto& e : this->G[v]) {
            if (e.idx == id) continue;
            if (this->ord[e.to] < this->ord[v]) tmp.push_back(e.idx);
            if (!seen[e.to]) {
                tmp.push_back(e.idx);
                dfs(e.to, e.idx);
                if (this->low[e.to] >= this->ord[v]) {
                    while (true) {
                        int i = tmp.back();
                        tmp.pop_back();
                        cmp[i] = sz;
                        if (i == e.idx) break;
                    }
                    grp.emplace_back(1, v);
                    while (true) {
                        int i = tmp2.back();
                        grp.back().push_back(i);
                        tmp2.pop_back();
                        if (i == e.to) break;
                    }
                    ++sz;
                }
            }
        }
    }

public:
    BiConnectedComponents(const Graph<T>& G, bool allow_isolated = false)
        : LowLink<T>(G) {
        sz = 0;
        cmp.assign(this->G.edge_size(), -1);
        seen.assign(this->n, false);
        tmp.reserve(this->G.edge_size());
        tmp2.reserve(this->n);
        rep (i, this->n) {
            if (!seen[i]) {
                dfs(i, -1);
                if (allow_isolated && G[i].empty()) {
                    grp.emplace_back(1, i);
                    ++sz;
                }
            }
        }
    }
    int size() const { return sz; }
    int operator[](int k) const { return cmp[k]; }
    std::vector<std::vector<int>> groups() const { return grp; }
    UnweightedGraph bct() const {
        UnweightedGraph res(this->n + sz);
        rep (i, sz) {
            for (auto v : grp[i]) res.add_edge(this->n + i, v);
        }
        return res;
    }
};

/**
 * @brief BiConnectedComponents(二重頂点連結成分分解)
 * @docs docs/graph/connected/BiConnectedComponents.md
 */
