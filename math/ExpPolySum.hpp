#pragma once

#include "../other/template.hpp"
#include "Combinatorics.hpp"
#include "poly/SamplingPointsShift.hpp"
#include "PowEnumerate.hpp"

template<class T, class Comb = Combinatorics<T>>
T exp_poly_sum(T r, int d, ll n = -1) {
    if (n == -1) assert(r != 1);
    auto cum = pow_enumerate<T>(d + 1, d);
    Comb::init(d + 1);
    T c = 0;
    {
        T sm = 0, cur = 1;
        rep (i, d + 2) {
            sm += cur * cum[i];
            cur *= r;
            cum[i] = sm;
        }
    }
    {
        T t = 1;
        rep (i, d + 1) {
            c += t * Comb::comb(d + 1, i) * cum[d - i];
            t *= -r;
        }
        c /= (1 - r).pow(d + 1);
    }
    if (n == -1) return c;
    if (n == 0) return 0;
    if (r == 1) return sampling_points_shift<T, Comb>(cum, n - 1);
    cum.pop_back();
    T iv = 1 / r, cur = 1;
    rep (i, d + 1) {
        cum[i] = (c - cum[i]) * cur;
        cur *= iv;
    }
    return c - r.pow(n - 1) * sampling_points_shift<T, Comb>(cum, n - 1);
}

/**
 * @brief ExpPolySum($\sum_{i=0}^{\infty}r^ii^d$)
 * @docs docs/math/ExpPolySum.md
 * @see https://kyopro-friends.hatenablog.com/entry/2020/03/11/073122
 */
