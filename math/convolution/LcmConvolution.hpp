#pragma once

#include "../../other/template.hpp"
#include "DivisorZetaMoebiusTransform.hpp"

template<class Sum, class Prod>
std::vector<typename Sum::value_type>
lcm_convolution(std::vector<typename Sum::value_type> a,
                std::vector<typename Sum::value_type> b) {
    divisor_zeta_transform<Sum>(a);
    divisor_zeta_transform<Sum>(b);
    rep (i, a.size()) a[i] = Prod::op(a[i], b[i]);
    divisor_moebius_transform<Sum>(a);
    return a;
}

/**
 * @brief LCMConvolution
 * @docs docs/LcmConvolution.md
 */
