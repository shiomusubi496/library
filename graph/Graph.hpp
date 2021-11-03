#pragma once

#include "../template.hpp"

template<class T = int> struct edge {
    int from, to;
    T cost;
    int idx;
    edge() = default;
    edge(int t) : from(-1), to(t), cost(1) {}
    edge(int t, T c) : from(-1), to(t), cost(c) {}
    edge(int f, int t, T c) : from(f), to(t), cost(c) {}
    edge(int f, int t, T c, int i): from(f), to(t), cost(c), idx(i) {}
    operator int() { return to; }
};

template<typename T = int> using Edges = std::vector<edge<T>>;

template<typename T = int> class Graph : public std::vector<std::vector<edge<T>>> {
  private:
    using Base = std::vector<std::vector<edge<T>>>;
  public:
    using Base::Base;
    int edge_id = 0;
    int add_edge(int a, int b, T c, bool is_directed = false){
        assert(0 <= a && a < this->size());
        assert(0 <= b && b < this->size());
        (*this)[a].emplace_back(a, b, c, edge_id);
        if (!is_directed) (*this)[b].emplace_back(b, a, c, edge_id);
        return edge_id++;
    }
    int add_edge(int a, int b, bool is_directed = false){
        assert(0 <= a && a < this->size());
        assert(0 <= b && b < this->size());
        (*this)[a].emplace_back(a, b, 1, edge_id);
        if (!is_directed) (*this)[b].emplace_back(b, a, 1, edge_id);
        return edge_id++;
    }
};

/*
@brief Graph-template
@docs docs/Graph.md
*/
