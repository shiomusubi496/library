#pragma once

#include "../../other/template.hpp"
#include "../../other/monoid.hpp"
#include "../../other/monoid2.hpp"
#include "SubsetZetaMoebiusTransform.hpp"

template<class T, class Sum = Monoid::Sum<T>, class Prod = Monoid::Product<T>>
std::vector<T> bitwise_or_convolution(std::vector<T> a, std::vector<T> b) {
    static_assert(std::is_same<typename Sum::value_type, T>::value,
                  "Sum::value_type must be T");
    static_assert(std::is_same<typename Prod::value_type, T>::value,
                  "Prod::value_type must be T");
    subset_zeta_transform<Sum>(a);
    subset_zeta_transform<Sum>(b);
    rep (i, a.size()) a[i] = Prod::op(a[i], b[i]);
    subset_moebius_transform<Sum>(a);
    return a;
}

/**
 * @brief BitwiseOrConvolution
 * @docs docs/math/convolution/BitwiseOrConvolution.md
 */
