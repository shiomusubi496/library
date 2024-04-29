#pragma once

#include "../../other/template.hpp"
#include "BinaryIndexedTree.hpp"

template<class T>
std::vector<int>
static_range_count_distinct(std::vector<T> v,
                            const std::vector<std::pair<int, int>>& qs) {
    int n = v.size();
    compressor<T> ps(v, true);
    ps.press(v);
    int m = ps.size();
    std::vector<int> lst(m, -1);
    BinaryIndexedTree<int> bit(n);
    std::vector<int> res(qs.size());
    std::vector<std::vector<std::pair<int, int>>> qs2(n);
    for (int i = 0; i < (int)qs.size(); ++i) {
        int l, r;
        std::tie(l, r) = qs[i];
        assert(0 <= l && l <= r && r <= n);
        if (l != r) qs2[r - 1].emplace_back(l, i);
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (lst[v[i]] != -1) bit.add(lst[v[i]], -1);
        else ++cnt;
        bit.add(i, 1);
        lst[v[i]] = i;
        for (auto [l, i] : qs2[i]) res[i] = cnt - bit.sum(l);
    }
    return res;
}
