#pragma once

#include "../other/template.hpp"
#include "ModInt.hpp"

template<class T> std::vector<T> montmort_number(int n) {
    std::vector<T> res(n + 1);
    res[0] = 1;
    if (n == 0) return res;
    res[1] = 0;
    rep (i, 1, n) res[i + 1] = (res[i] + res[i - 1]) * i;
    return res;
}

/**
 * @brief MontmortNumber(攪乱順列)
 * @docs docs/math/MontmortNumber.md
 */