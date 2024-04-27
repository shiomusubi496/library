#pragma once

#include "../../other/template.hpp"
#include "../../other/monoid.hpp"
#include "WaveletMatrixStruct.hpp"
#include "../segment/SegmentTree.hpp"

template<class M> class SegmentTreeWM {
private:
    using T = typename M::value_type;
    std::vector<SegmentTree<M>> seg;
    WaveletMatrixStruct wms;

public:
    SegmentTreeWM(const std::vector<ll>& xs, const std::vector<ll>& ys) {
        wms.init([&](int h, int n) { seg.assign(h, SegmentTree<M>(n)); }, xs,
                 ys);
    }
    SegmentTreeWM(const std::vector<ll>& xs, const std::vector<ll>& ys,
                  const std::vector<typename M::value_type>& v) {
        auto f = [&](const std::vector<std::vector<T>>& dat) {
            seg.resize(dat.size());
            rep (i, dat.size()) seg[i] = SegmentTree<M>(dat[i]);
        };
        wms.init<decltype((f)), M>(f, xs, ys, v);
    }

    void apply(ll x, ll y, T v) {
        wms.apply(x, y, [&](int j, int k) { seg[j].apply(k, v); });
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
