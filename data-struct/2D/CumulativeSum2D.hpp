#pragma once

#include "../../other/template.hpp"
#include "../../other/monoid.hpp"
#include "../segment/CumulativeSum.hpp"
#include "Struct2D.hpp"

template<class M> class CumulativeSum2D {
private:
    using T = typename M::value_type;
    int n;
    std::vector<CumulativeSum<M>> seg;
    Struct2D str;

public:
    CumulativeSum2D(const std::vector<ll>& xs, const std::vector<ll>& ys,
                    const std::vector<T>& v) {
        auto f = [&](const auto& dat) {
            n = dat.size() >> 1;
            seg.resize(n << 1);
            rep (i, 1, n << 1) seg[i] = CumulativeSum<M>(dat[i]);
        };
        str.init<decltype((f)), M>(f, xs, ys, v);
    }

    T prod(ll l, ll r, ll u, ll d) {
        T res = M::id();
        str.prod(l, r, u, d, [&](int k, int a, int b, bool) {
            res = M::op(res, seg[k].prod(a, b));
        });
        return res;
    }

    T get(ll x, ll y) {
        T res = M::id();
        str.get(x, y, [&](int k, int a) { res = M::op(res, seg[k].get(a)); });
        return res;
    }
};
