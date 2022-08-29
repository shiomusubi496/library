#pragma once

#include "../../other/template.hpp"
#include "../../other/monoid.hpp"
#include "SegmentTree.hpp"

template<class M> class SegmentTree2D {
private:
    using T = typename M::value_type;
    int ori, n, h;
    bool built;
    std::vector<ll> xs, ys;
    presser<ll> psx;
    std::vector<std::vector<ll>> idx;
    std::vector<SegmentTree<M>> seg;

public:
    SegmentTree2D() : built(false) {}
    void add_point(ll x, ll y) {
        assert(!built);
        xs.push_back(x);
        ys.push_back(y);
    }
    void build() {
        assert(!built);
        built = true;
        psx.push(xs);
        psx.build();
        psx.press(xs);
        ori = psx.size();
        h = bitop::ceil_log2(ori);
        n = 1 << h;
        idx.resize(n << 1);
        rep (i, xs.size()) idx[xs[i] + n].push_back(ys[i]);
        rep (i, ori) sort(all(idx[i + n]));
        rrep (i, n, 1) {
            std::merge(all(idx[i << 1]), all(idx[i << 1 | 1]),
                       std::back_inserter(idx[i]));
            idx[i].erase(std::unique(all(idx[i])), idx[i].end());
        }
        seg.resize(1);
        seg.reserve(n << 1);
        rep (i, 1, n << 1) seg.emplace_back(idx[i].size());
    }
    template<class Upd> void update(ll x, ll y, const Upd& upd) {
        assert(built);
        int k = psx.get(x) + n;
        auto itr = std::lower_bound(all(idx[k]), y);
        assert(itr != idx[k].end() && *itr == y);
        seg[k].update(itr - idx[k].begin(), upd);
        while (k >>= 1) {
            seg[k].update(std::lower_bound(all(idx[k]), y) - idx[k].begin(),
                          upd);
        }
    }
    void set(ll x, ll y, const T& v) {
        update(x, y, [&](const T&) { return v; });
    }
    void apply(ll x, ll y, const T& a) {
        update(x, y, [&](const T& y) { return M::op(y, a); });
    }
    T prod(ll l, ll r, ll u, ll d) const {
        assert(built);
        l = psx.lower_bound(l);
        r = psx.lower_bound(r);
        l += n;
        r += n;
        T lsm = M::id(), rsm = M::id();
        while (l != r) {
            if (l & 1) {
                int a = std::lower_bound(all(idx[l]), u) - idx[l].begin();
                int b = std::lower_bound(all(idx[l]), d) - idx[l].begin();
                lsm = M::op(lsm, seg[l].prod(a, b));
                ++l;
            }
            if (r & 1) {
                --r;
                int a = std::lower_bound(all(idx[r]), u) - idx[r].begin();
                int b = std::lower_bound(all(idx[r]), d) - idx[r].begin();
                rsm = M::op(seg[r].prod(a, b), rsm);
            }
            l >>= 1;
            r >>= 1;
        }
        return M::op(lsm, rsm);
    }
    T all_prod() const {
        assert(built);
        return seg[1].all_prod();
    }
    T get(ll x, ll y) const {
        assert(built);
        x = psx.get(x);
        auto itr = std::lower_bound(all(idx[x + n]), y);
        assert(itr != idx[x + n].end() && *itr == y);
        return seg[x + n].get(itr - idx[x + n].begin());
    }
};

/**
 * @brief SegmentTree2D
 * @docs docs/data-struct/segment/SegmentTree2D.md
 */
