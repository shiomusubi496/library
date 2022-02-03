#pragma once

#include "../other/template.hpp"

template<class Cont> std::vector<std::pair<typename Cont::value_type, int>> RunLength(const Cont& str) {
    std::vector<std::pair<typename Cont::value_type, int>> res;
    if (str.size() == 0) return res;
    res.emplace_back(str[0], 1);
    rep (i, 1, str.size()) {
        if (res.back().first == str[i]) ++res.back().second;
        else res.emplace_back(str[i], 1);
    }
    return res;
}
