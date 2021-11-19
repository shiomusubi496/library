#pragma once

#include "../template.hpp"

template<class T = int> struct edge {
    int from, to;
    T cost;
    int idx;
    edge() : from(-1), to(-1) {}
    edge(int t) : from(-1), to(t), cost(1) {}
    edge(int t, T c) : from(-1), to(t), cost(c) {}
    edge(int f, int t, T c) : from(f), to(t), cost(c) {}
    edge(int f, int t, T c, int i): from(f), to(t), cost(c), idx(i) {}
    operator int() { return to; }
};

template<class T = int> using Edges = std::vector<edge<T>>;
template<class T = int> using GMatrix = std::vector<std::vector<T>>;

template<class T = int> class Graph : public std::vector<std::vector<edge<T>>> {
  protected:
    int edge_id = 0;
    using Base = std::vector<std::vector<edge<T>>>;
  public:
    using Base::Base;
    int edge_size() const { return edge_id; }
    int add_edge(int a, int b, T c, bool is_directed = false){
        assert(0 <= a && a < (int)this->size());
        assert(0 <= b && b < (int)this->size());
        (*this)[a].emplace_back(a, b, c, edge_id);
        if (!is_directed) (*this)[b].emplace_back(b, a, c, edge_id);
        return edge_id++;
    }
    int add_edge(int a, int b, bool is_directed = false){
        assert(0 <= a && a < (int)this->size());
        assert(0 <= b && b < (int)this->size());
        (*this)[a].emplace_back(a, b, 1, edge_id);
        if (!is_directed) (*this)[b].emplace_back(b, a, 1, edge_id);
        return edge_id++;
    }
};

template<class T> GMatrix<T> ListToMatrix(const Graph<T>& G) {
    const int N = G.size();
    auto res = make_vec<T>(N, N, infinity<T>::value);
    rep (i, N) res[i][i] = 0;
    rep (i, N) {
        for (const edge<T>& e : G[i]) res[i][e.to] = e.cost;
    }
    return res;
}

template<class T> Edges<T> ListToUndirectedEdges(const Graph<T>& G) {
    const int V = G.size();
    const int E = G.edge_size();
    Edges<T> Ed(E);
    rep (i, V) {
        for (const edge<T>& e : G[i]) Ed[e.idx] = e;
    }
    return Ed;
}
template<class T> Edges<T> ListToDirectedEdges(const Graph<T>& G) {
    const int V = G.size();
    const int E = std::accumulate(all(G), 0, [](int a, const Edges<T>& b) -> int { return a + b.size(); });
    Edges<T> Ed(G.edge_size());
    Ed.reserve(E);
    rep (i, V) {
        for (const edge<T>& e : G[i]) {
            if (Ed[e.idx].to == -1) Ed[e.idx] = e;
            else Ed.push_back(e);
        }
    }
    return Ed;
}

template<class T> Graph<T> ReverseGraph(const Graph<T>& G) {
    const int V = G.size();
    Graph<T> RG(V);
    for (const edge<T>& e : ListToUndirectedEdges(G)) {
        RG.add_edge(e.to, e.from, e.cost, true);
    }
    return RG;
}

/**
 * @brief Graph-template
 * @docs docs/Graph.md
 */
