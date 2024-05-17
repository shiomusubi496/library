#pragma once

#include "../../other/template.hpp"
#include "../../other/monoid.hpp"
#include "../segment/SegmentTree.hpp"
#include "Struct2D.hpp"

template<class M> class SegmentTree2D {
private:
    using T = typename M::value_type;
    int n;
    std::vector<SegmentTree<M>> seg;
    Struct2D str;

public:
    SegmentTree2D(const std::vector<ll>& xs, const std::vector<ll>& ys) {
        str.init(
            [&](const auto& sz) {
                n = sz.size() >> 1;
                seg.resize(n << 1);
                rep (i, n << 1) seg[i] = SegmentTree<M>(sz[i]);
            },
            xs, ys);
    }
    SegmentTree2D(const std::vector<ll>& xs, const std::vector<ll>& ys,
                  const std::vector<T>& v) {
        auto f = [&](const auto& dat) {
            n = dat.size() >> 1;
            seg.resize(n << 1);
            rep (i, n << 1) seg[i] = SegmentTree<M>(dat[i]);
        };
        str.init<decltype((f)), M>(f, xs, ys, v);
    }

    template<class Upd> void update(ll x, ll y, Upd&& upd) {
        T cur = M::id();
        str.update(
            x, y,
            [&](int k, int i) {
                seg[k].update(i, upd);
                cur = seg[k].get(i);
            },
            [&](int k, int i) { seg[k].set(i, cur); },
            [&](int k, int i, bool f) {
                if (f) cur = M::op(cur, seg[k].get(i));
                else cur = M::op(seg[k].get(i), cur);
            });
    }
    void set(ll x, ll y, const T& v) {
        update(x, y, [&](const T&) { return v; });
    }
    void apply(ll x, ll y, const T& v) {
        str.apply(x, y, [&](int k, int i) { seg[k].apply(i, v); });
    }
    T prod(ll l, ll r, ll u, ll d) const {
        T lsm = M::id(), rsm = M::id();
        str.prod(l, r, u, d, [&](int k, int a, int b, bool f) {
            if (f) lsm = M::op(lsm, seg[k].prod(a, b));
            else rsm = M::op(seg[k].prod(a, b), rsm);
        });
        return M::op(lsm, rsm);
    }
    T get(ll x, ll y) {
        T res = M::id();
        str.get(x, y, [&](int k, int i) { res = seg[k].get(i); });
        return res;
    }
    T all_prod() const { return seg[1].all_prod(); }
};

/**
 * @brief SegmentTree2D
 */
