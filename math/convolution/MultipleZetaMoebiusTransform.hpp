#pragma once

#include "../../other/template.hpp"

template<class Sum>
void multiple_zeta_transform(std::vector<typename Sum::value_type>& v) {
    int n = v.size() - 1;
    std::vector<bool> is_prime(n + 1, true);
    for (ll i = 2; i <= n; ++i) {
        if (!is_prime[i]) continue;
        rreps (j, n / i) {
            v[j] = Sum::op(v[j], v[j * i]);
            is_prime[j * i] = false;
        }
    }
}

template<class Sum>
void multiple_moebius_transform(std::vector<typename Sum::value_type>& v) {
    int n = v.size() - 1;
    std::vector<bool> is_prime(n + 1, true);
    for (ll i = 2; i <= n; ++i) {
        if (!is_prime[i]) continue;
        reps (j, n / i) {
            v[j] = Sum::inv(v[j], v[j * i]);
            is_prime[j * i] = false;
        }
    }
}

/**
 * @brief MultipleZeta/MoebiusTransform(ゼータ変換/メビウス変換)
 * @docs docs/math/convolution/MultipleZetaMoebiusTransform.md
 */
