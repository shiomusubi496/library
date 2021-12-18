#pragma once

#include "../../other/template.hpp"
#include "../Graph.hpp"
#include "../other/LowLink.hpp"

template<class T> class TwoEdgeConnectedComponents : public LowLink<T> {
  protected:
    int sz;
    std::vector<int> cmp;
    void dcmp(int v) {
        for (const edge<T>& e : this->G[v]) {
            if (cmp[e.to] != -1) continue;
            if (this->ord[v] < this->low[e.to] || this->ord[e.to] < this->low[v]) continue;
            cmp[e.to] = cmp[v];
            dcmp(e.to);
        }
    }
    void init() {
        sz = 0;
        cmp.assign(this->n, -1);
        rep (i, this->n) {
            if (cmp[i] == -1) {
                cmp[i] = sz++;
                dcmp(i);
            }
        }
    }
  public:
    TwoEdgeConnectedComponents(const Graph<T>& G) : LowLink<T>(G) { init(); }
    int size() const { return sz; }
    int operator[](int k) const { return cmp[k]; }
    std::vector<std::vector<int>> groups() const {
        std::vector<std::vector<int>> res(sz);
        rep (i, this->n) res[cmp[i]].push_back(i);
        return res;
    }
    Graph<T> tree() const {
        Graph<T> res(sz);
        for (const edge<T>& e : this->brd) {
            res.add_edge(cmp[e.from], cmp[e.to], e.cost);
        }
        return res;
    }
};

/**
 * @brief TwoEdgeConnectedComponents(二辺連結成分分解)
 * @docs docs/TwoEdgeConnectedComponents.md
 */
