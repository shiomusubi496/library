#pragma once

#include "../../other/template.hpp"

template<class T = ll> class DynamicUnionFind {
  protected:
    std::map<T, T> data;
  public:
    DynamicUnionFind() = default;
    T find(T x) {
        auto itr = data.find(x);
        return itr == data.end() || itr->second < 0 ? x : itr->second = find(itr->second);
    }
    std::pair<T, T> merge(T x, T y) {
        x = find(x);
        y = find(y);
        if (x == y) return {x, -1};
        auto itrx = data.find(x), itry = data.find(y);
        if (itrx == data.end()) itrx = data.insert({x, -1}).first;
        if (itry == data.end()) itry = data.insert({y, -1}).first;
        if (itrx->second > itry->second) std::swap(itrx, itry), std::swap(x, y);
        itrx->second += itry->second;
        itry->second = x;
        return {x, y};
    }
    bool same(T x, T y) {
        return find(x) == find(y);
    }
    int size(T x) {
        x = find(x);
        auto itr = data.find(x);
        if (itr == data.end()) return 1;
        else return -itr->second;
    }
    bool is_root(T x) {
        auto itr = data.find(x);
        if (itr == data.end() || itr->second < 0) return true;
        return false; 
    }
};

/**
 * @brief DynamicUnionFind(動的UnionFind)
 * @docs docs/DynamicUnionFind.md
 */
