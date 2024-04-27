#pragma once

#include "../../other/template.hpp"
#include "../../other/monoid.hpp"
#include "WaveletMatrixStruct.hpp"
#include "../segment/CumulativeSum.hpp"

template<class M> class CumulativeSumWM {
private:
    using T = typename M::value_type;
    std::vector<CumulativeSum<M>> seg;
    WaveletMatrixStruct wms;

public:
    CumulativeSumWM(const std::vector<ll>& xs, const std::vector<ll>& ys,
                    const std::vector<typename M::value_type>& v) {
        auto f = [&](const std::vector<std::vector<T>>& dat) {
            seg.resize(dat.size());
            rep (i, dat.size()) seg[i] = CumulativeSum<M>(dat[i]);
        };
        wms.init<decltype((f)), M>(f, xs, ys, v);
    }

    T prod(ll l, ll r, ll u, ll d) {
        T res = M::id();
        wms.prod(
            l, r, u, d,
            [&](int k, int a, int b) { res = M::op(res, seg[k].prod(a, b)); },
            [&](int k, int a, int b) { res = M::inv(res, seg[k].prod(a, b)); });
        return res;
    }
};

/**
 * @brief WaveletMatrixPointAddRectangleSum.hpp
 * @docs docs/data-struct/wavelet/WaveletMatrixPointAddRectangleSum.md
 */
