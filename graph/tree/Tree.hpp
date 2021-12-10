#pragma once

#include "../Graph.hpp"

template<class T> class Tree : public Graph<T> {
  private:
    using Base = Graph<T>;
  protected:
    void dfs_build(int v, int p) {
        par[v] = p;
        for (const edge<T>& e : (*this)[v]) {
            if (e.to != p) dfs_build(e.to, v);
        }
    }
  public:
    int root;
    std::vector<int> par;
    using Base::Base;
    Tree(const Base& G) : Base(G) {}
    Tree(Base&& G) : Base(std::move(G)) {}
    void build(int r = 0) {
        assert(this->edge_size() + 1 == (int)this->size());
        assert(0 <= r && r < (int)this->size());
        par.resize(this->size());
        dfs_build(r, -1);
        root = r;
    }
    Graph<T> child() const {
        Graph<T> res(this->size());
        rep (i, this->size()) {
            if (i == root) res[i].reserve(this->size());
            else res[i].reserve(this->size() - 1);
            for (const edge<T>& e : (*this)[i]) {
                if (e.to != par[i]) res.add_edge(i, e.to, e.cost, true);
            }
        }
        return res;
    }
};
