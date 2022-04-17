#pragma once

#include "../../other/template.hpp"
#include "SupersetZetaMoebiusTransform.hpp"

template<class Sum, class Prod>
std::vector<typename Sum::value_type>
bitwise_and_convolution(std::vector<typename Sum::value_type> a,
                        std::vector<typename Sum::value_type> b) {
    superset_zeta_transform<Sum>(a);
    superset_zeta_transform<Sum>(b);
    rep (i, a.size()) a[i] = Prod::op(a[i], b[i]);
    superset_moebius_transform<Sum>(a);
    return a;
}

/**
 * @brief BitwiseAndConvolution
 * @docs docs/BitwiseAndConvolution.md
 */
