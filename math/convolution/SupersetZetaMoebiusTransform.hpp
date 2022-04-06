#pragma once

#include "../../other/template.hpp"

template<class Sum>
void superset_zeta_transform(std::vector<typename Sum::value_type>& v) {
    int n = v.size();
    for (ll i = 1; i < n; i <<= 1) {
        rep (j, n) {
            if (j & i) v[j ^ i] = Sum::op(v[j ^ i], v[j]);
        }
    }
}

template<class Sum>
void superset_moebius_transform(std::vector<typename Sum::value_type>& v) {
    int n = v.size();
    for (ll i = 1; i < n; i <<= 1) {
        rep (j, n) {
            if (j & i) v[j ^ i] = Sum::inv(v[j ^ i], v[j]);
        }
    }
}

/**
 * @brief SupersetZeta/MoebiusTransform(ゼータ変換/メビウス変換)
 * @docs docs/SupersetZetaMoebiusTransform.md
 */
