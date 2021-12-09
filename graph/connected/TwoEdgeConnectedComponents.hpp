#pragma once

#include "../../other/template.hpp"
#include "../Graph.hpp"
#include "../other/LowLink.hpp"

template<class T> class TwoEdgeConnectedComponents : protected LowLink<T> {
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
  public:
    TwoEdgeConnectedComponents() = default;
    TwoEdgeConnectedComponents(const Graph<T>& G_) { init(G_); }
    void init(const Graph<T>& G_) {
        LowLink<T>::init(G_);
        sz = 0;
        cmp.assign(this->n, -1);
        rep (i, this->n) {
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
