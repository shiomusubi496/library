#pragma once

#include "../../other/template.hpp"
#include "../../other/monoid.hpp"
#include "../segment/DualSegmentTree.hpp"
#include "Struct2D.hpp"

template<class A, bool = Monoid::is_action<A>::value> class DualSegmentTree2D {
private:
    using M = typename A::M;
    using E = typename A::E;
    using T = typename M::value_type;
    using U = typename E::value_type;
    int n;
    std::vector<DualSegmentTree<A>> seg;
    Struct2D str;

public:
    DualSegmentTree2D(const std::vector<ll>& xs, const std::vector<ll>& ys) {
        str.init(
            [&](const auto& sz) {
                n = sz.size() >> 1;
                seg.resize(n << 1);
                rep (i, 1, n << 1) seg[i] = DualSegmentTree<M>(sz[i]);
            },
            xs, ys);
    }
    DualSegmentTree2D(const std::vector<ll>& xs, const std::vector<ll>& ys,
                      const std::vector<T>& v) {
        auto f = [&](const auto& dat) {
            n = dat.size() >> 1;
            seg.resize(n << 1);
            rep (i, 1, n << 1) seg[i] = DualSegmentTree<M>(dat[i]);
        };
        str.init<decltype((f)), M>(f, xs, ys, v);
    }

    void apply(ll l, ll r, ll u, ll d, const U& x) {
        str.prod(l, r, u, d,
                 [&](int k, int a, int b, bool) { seg[k].apply(a, b, x); });
    }

    T get(ll x, ll y) {
        T res = M::id();
        str.apply(x, y, [&](int k, int a) { res = M::op(res, seg[k].get(a)); });
        return res;
    }
};

template<class M>
class DualSegmentTree2D<M, false>
    : public DualSegmentTree2D<Monoid::MakeAction<M>> {
private:
    using Base = DualSegmentTree2D<Monoid::MakeAction<M>>;

public:
    using Base::Base;
};
