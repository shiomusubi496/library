#pragma once

#include "../../other/template.hpp"
#include "MultipleZetaMoebiusTransform.hpp"

template<class Sum, class Prod>
std::vector<typename Sum::value_type>
gcd_convolution(std::vector<typename Sum::value_type> a,
                std::vector<typename Sum::value_type> b) {
    multiple_zeta_transform<Sum>(a);
    multiple_zeta_transform<Sum>(b);
    rep (i, a.size()) a[i] = Prod::op(a[i], b[i]);
    multiple_moebius_transform<Sum>(a);
    return a;
}

/**
 * @brief GCDConvolution
 * @docs docs/GcdConvolution.md
 */
