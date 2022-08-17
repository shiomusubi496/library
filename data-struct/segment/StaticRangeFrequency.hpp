#pragma once

#include "../../other/template.hpp"

template<class T, class Map = std::map<T, std::vector<int>>>
class StaticRangeFrequency {
private:
    int n;
    Map mp;

public:
    StaticRangeFrequency(const std::vector<T>& v) {
        n = v.size();
        for (int i = 0; i < n; i++) {
            mp[v[i]].push_back(i);
        }
    }
    int count(T x) {
        auto itr = mp.find(x);
        if (itr == mp.end()) {
            return 0;
        }
        return itr->second.size();
    }
    int count(int l, int r, T x) {
        assert(0 <= l && l <= r && r <= n);
        auto itr = mp.find(x);
        if (itr == mp.end()) {
            return 0;
        }
        return std::lower_bound(all(itr->second), r) -
               std::lower_bound(all(itr->second), l);
    }
};

/**
 * @brief StaticRangeFrequency
 * @docs docs/data-struct/segment/StaticRangeFrequency.md
 */
