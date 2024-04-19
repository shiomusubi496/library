#pragma once

#include "../other/template.hpp"
#include "SuffixArray.hpp"

template<class Cont>
std::vector<int> lcp_array(const Cont& str, const std::vector<int>& sa) {
    int n = str.size();
    std::vector<int> rank(n);
    rep (i, n) rank[sa[i]] = i;
    std::vector<int> lcp(n - 1);
    int h = 0;
    rep (i, n) {
        if (rank[i] == 0) continue;
        int j = sa[rank[i] - 1];
        while (i + h < n && j + h < n && str[i + h] == str[j + h]) ++h;
        lcp[rank[i] - 1] = h;
        chmax(--h, 0);
    }
    return lcp;
}

/**
 * @brief LCPArray
 * @docs docs/string/LCPArray.md
 */
