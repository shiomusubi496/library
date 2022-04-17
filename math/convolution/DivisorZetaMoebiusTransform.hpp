#pragma once

#include "../../other/template.hpp"

template<class Sum>
void divisor_zeta_transform(std::vector<typename Sum::value_type>& v) {
    int n = v.size() - 1;
    std::vector<bool> is_prime(n + 1, true);
    for (ll i = 2; i <= n; ++i) {
        if (!is_prime[i]) continue;
        reps (j, n / i) {
            v[j * i] = Sum::op(v[j * i], v[j]);
            is_prime[j * i] = false;
        }
    }
}

template<class Sum>
void divisor_moebius_transform(std::vector<typename Sum::value_type>& v) {
    int n = v.size() - 1;
    std::vector<bool> is_prime(n + 1, true);
    for (ll i = 2; i <= n; ++i) {
        if (!is_prime[i]) continue;
        rreps (j, n / i) {
            v[j * i] = Sum::inv(v[j * i], v[j]);
            is_prime[j * i] = false;
        }
    }
}

/**
 * @brief DivisorZeta/MoebiusTransform(ゼータ変換/メビウス変換)
 * @docs docs/DivisorZetaMoebiusTransform.md
 */
