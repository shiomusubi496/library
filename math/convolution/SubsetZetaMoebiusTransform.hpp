#pragma once

#include "../../other/template.hpp"

template<class Sum>
void subset_zeta_transform(std::vector<typename Sum::value_type>& v) {
    int n = v.size();
    for (ll i = 1; i < n; i <<= 1) {
        rep (j, n) {
            if (j & i) v[j] = Sum::op(v[j], v[j ^ i]);
        }
    }
}

template<class Sum>
void subset_moebius_transform(std::vector<typename Sum::value_type>& v) {
    int n = v.size();
    for (ll i = 1; i < n; i <<= 1) {
        rep (j, n) {
            if (j & i) v[j] = Sum::inv(v[j], v[j ^ i]);
        }
    }
}

/**
 * @brief SubsetZeta/MoebiusTransform(ゼータ変換/メビウス変換)
 * @docs docs/math/convolution/SubsetZetaMoebiusTransform.md
 */
