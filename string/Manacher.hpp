#pragma once

#include "../other/template.hpp"


template<class Cont, class Comp>
std::vector<int> Manacher(const Cont& str, const Comp& cmp) {
    const int n = str.size();
    std::vector<int> res(n);
    res[0] = 1;
    int mid = 0;
    rep (i, 1, n) {
        if (mid + res[mid] > i) {
            res[i] = std::min(res[mid - (i - mid)], mid + res[mid] - (int)i);
        }
        while (0 <= i - res[i] && i + res[i] < n && cmp(str[i - res[i]], str[i + res[i]])) {
            ++res[i];
        }
        if (mid + res[mid] < i + res[i]) mid = i;
    }
    return res;
}

template<class Cont>
std::vector<int> Manacher(const Cont& str) {
    return Manacher(str, std::equal_to<typename Cont::value_type>());
}

template<class Cont, class Comp>
std::vector<int> ManacherEven(const Cont& str, const Comp& cmp, const typename Cont::value_type dummy = '$') {
    const int n = str.size();
    Cont str2(n * 2 + 1, dummy);
    rep (i, n) str2[i * 2 + 1] = str[i];
    const std::vector<int> mana = Manacher(str2, cmp);
    std::vector<int> res(n * 2 - 1);
    rep (i, n * 2 - 1) res[i] = mana[i + 1] - 1;
    return res;
}

template<class Cont>
std::vector<int> ManacherEven(const Cont& str, const typename Cont::value_type dummy = '$') {
    return ManacherEven(str, std::equal_to<typename Cont::value_type>(), dummy);
}

/**
 * @brief Manacher's Algortihm(最長回文長検出)
 * @docs docs/Manacher.md
 */
