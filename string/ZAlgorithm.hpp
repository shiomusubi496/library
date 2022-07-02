#pragma once

#include "../other/template.hpp"


template<class Cont, class Comp>
std::vector<int> ZAlgorithm(const Cont& str, const Comp& cmp) {
    const int n = str.size();
    std::vector<int> res(n);
    int frm = 0, lst = 0;
    rep (i, 1, str.size()) {
        int &cur = res[i];
        if (frm != 0) {
            cur = std::max(std::min(res[i - frm], lst - (int)i), 0);
        }
        while (i + cur < n && cmp(str[i + cur], str[cur])) ++cur;
        if (i + cur > lst) {
            frm = i; lst = i + cur;
        }
    }
    res[0] = n;
    return res;
}

template<class Cont>
std::vector<int> ZAlgorithm(const Cont& str) {
    return ZAlgorithm(str, std::equal_to<typename Cont::value_type>());
}

/**
 * @brief Z-Algorithm
 * @docs docs/ZAlgorithm.md
 */
