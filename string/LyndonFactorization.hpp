#pragma once

#include "../other/template.hpp"

template<class Cont, class Comp>
std::vector<int> lyndon_factorization(const Cont &str, const Comp &cmp) {
    const int n = str.size();
    std::vector<int> res{0};
    while (res.back() != n) {
        int l = 1;
        rep (i, res.back() + 1, n + 1) {
            if (i == n || cmp(str[i], str[i - l])) {
                rep (j, res.back() + l, i + 1, l) res.push_back(j);
                break;
            }
            else if (cmp(str[i - l], str[i])) l = i - res.back() + 1;
        }
    }
    return res;
}

template<class Cont>
std::vector<int> lyndon_factorization(const Cont &str) {
    return lyndon_factorization(str, std::less<typename Cont::value_type>());
}

/**
 * @brief Lyndon Factorization
 * @docs docs/string/LyndonFactorization.md
 */
