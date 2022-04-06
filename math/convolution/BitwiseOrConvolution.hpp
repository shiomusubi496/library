#pragma once

#include "../../other/template.hpp"
#include "SubsetZetaMoebiusTransform.hpp"

template<class Sum, class Prod>
std::vector<typename Sum::value_type>
bitwise_or_convolution(std::vector<typename Sum::value_type> a,
                       std::vector<typename Sum::value_type> b) {
    subset_zeta_transform<Sum>(a);
    subset_zeta_transform<Sum>(b);
    rep (i, a.size()) a[i] = Prod::op(a[i], b[i]);
    subset_moebius_transform<Sum>(a);
    return a;
}

/**
 * @brief BitwiseOrConvolution
 * @docs docs/BitwiseOrConvolution.md
 */