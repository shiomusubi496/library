#pragma once

#include "../../other/template.hpp"

template<class Sum>
void hadamard_transform(std::vector<typename Sum::value_type>& v) {
    const int n = v.size();
    for (ll i = 1; i < n; i <<= 1) {
        rep (j, n) {
            if (i & ~j) {
                auto x = v[j], y = v[j | i];
                v[j] = Sum::op(x, y);
                v[j | i] = Sum::inv(x, y);
            }
        }
    }
}

template<class Sum>
void inv_hadamard_transform(std::vector<typename Sum::value_type>& v) {
    const int n = v.size();
    hadamard_transform<Sum>(v);
    each_for (x : v) x /= n;
}

/**
 * @brief HadmardTransform
 * @docs docs/math/convolution/HadamardTransform.md
 */