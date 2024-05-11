#pragma once

#include "../other/template.hpp"

template<class T = int> struct edge {
    int from, to;
    T cost;
    int idx;
    edge() : from(-1), to(-1) {}
    edge(int f, int t, const T& c = 1, int i = -1)
        : from(f), to(t), cost(c), idx(i) {}
    edge(int f, int t, T&& c, int i = -1)
        : from(f), to(t), cost(std::move(c)), idx(i) {}
    operator int() const { return to; }
    friend bool operator<(const edge<T>& lhs, const edge<T>& rhs) {
        return lhs.cost < rhs.cost;
    }
    friend bool operator>(const edge<T>& lhs, const edge<T>& rhs) {
        return lhs.cost > rhs.cost;
    }
};

template<class T = int> using Edges = std::vector<edge<T>>;
template<class T = int> using GMatrix = std::vector<std::vector<T>>;

template<class T = int> class Graph : public std::vector<std::vector<edge<T>>> {
private:
    using Base = std::vector<std::vector<edge<T>>>;

public:
    int edge_id = 0;
    using Base::Base;
    int edge_size() const { return edge_id; }
    int add_edge(int a, int b, const T& c, bool is_directed = false) {
        assert(0 <= a && a < (int)this->size());
        assert(0 <= b && b < (int)this->size());
        (*this)[a].emplace_back(a, b, c, edge_id);
        if (!is_directed) (*this)[b].emplace_back(b, a, c, edge_id);
        return edge_id++;
    }
    int add_edge(int a, int b, bool is_directed = false) {
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
        for (const auto& e : G[i]) res[i][e.to] = e.cost;
    }
    return res;
}

template<class T> Edges<T> UndirectedListToEdges(const Graph<T>& G) {
    const int V = G.size();
    const int E = G.edge_size();
    Edges<T> Ed(E);
    rep (i, V) {
        for (const auto& e : G[i]) Ed[e.idx] = e;
    }
    return Ed;
}

template<class T> Edges<T> DirectedListToEdges(const Graph<T>& G) {
    const int V = G.size();
    const int E = std::accumulate(
        all(G), 0, [](int a, const std::vector<edge<T>>& v) -> int {
            return a + v.size();
        });
    Edges<T> Ed(G.edge_size());
    Ed.reserve(E);
    rep (i, V) {
        for (const auto& e : G[i]) {
            if (Ed[e.idx] == -1) Ed[e.idx] = e;
            else Ed.push_back(e);
        }
    }
    return Ed;
}

template<class T> Graph<T> ReverseGraph(const Graph<T>& G) {
    const int V = G.size();
    Graph<T> res(V);
    rep (i, V) {
        for (const auto& e : G[i]) {
            res[e.to].emplace_back(e.to, e.from, e.cost, e.idx);
        }
    }
    res.edge_id = G.edge_size();
    return res;
}


struct unweighted_edge {
    template<class... Args> unweighted_edge(const Args&...) {}
    operator int() { return 1; }
};

using UnweightedGraph = Graph<unweighted_edge>;

/**
 * @brief Graph-template
 * @docs docs/graph/Graph.md
 */
