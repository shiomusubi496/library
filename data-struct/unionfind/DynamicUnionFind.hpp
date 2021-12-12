#pragma once

#include "../../other/template.hpp"

class DynamicUnionFind {
  protected:
    std::map<ll, ll> st;
  public:
    DynamicUnionFind() = default;
    ll find(ll x) {
        auto itr = st.find(x);
        return itr == st.end() || itr->second < 0 ? x : itr->second = find(itr->second);
    }
    std::pair<ll, ll> merge(ll x, ll y) {
        x = find(x);
        y = find(y);
        if (x == y) return {x, -1};
        auto itrx = st.find(x), itry = st.find(y);
        if (itrx == st.end()) itrx = st.insert({x, -1}).first;
        if (itry == st.end()) itry = st.insert({y, -1}).first;
        if (itrx->second > itry->second) std::swap(itrx, itry), std::swap(x, y);
        itrx->second += itry->second;
        itry->second = x;
        return {x, y};
    }
    bool same(ll x, ll y) {
        return find(x) == find(y);
    }
    int size(ll x) {
        x = find(x);
        auto itr = st.find(x);
        if (itr == st.end()) return 1;
        else return -itr->second;
    }
    bool is_root(ll x) {
        auto itr = st.find(x);
        if (itr == st.end() || itr->second < 0) return true;
        return false; 
    }
};

/**
 * @brief DynamicUnionFind(動的UnionFind)
 * @docs docs/DynamicUnionFind.md
 */
