#pragma once

#include "../other/template.hpp"

#ifdef GEOMETRY_EPS
constexpr ld geom_eps = GEOMETRY_EPS;
#else
constexpr ld geom_eps = EPS;
#endif

#ifdef GEOMETRY_REAL_TYPE
using Real = GEOMETRY_REAL_TYPE;
// a <=> b  :  cmp(a, b) <=> 0
inline int cmp(Real a, Real b) {
    if (a > b) return 1;
    if (a < b) return -1;
    return 0;
}
#else
using Real = ld;
// a <=> b  :  cmp(a, b) <=> 0
inline int cmp(ld a, ld b) {
    if (a > b + geom_eps) return 1;
    if (a < b - geom_eps) return -1;
    return 0;
}
#endif
