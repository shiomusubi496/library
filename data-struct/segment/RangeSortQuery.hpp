#pragma once

#include "../../other/template.hpp"
#include "DynamicSegmentTree.hpp"
#include "SegmentTree.hpp"

template<class M> class RangeSortQuery {
private:
    using T = typename M::value_type;
    class M2 {
    public:
        using value_type = std::pair<std::array<T, 2>, int>;
        static value_type id() { return {{M::id(), M::id()}, 0}; }
        static value_type op(const value_type& a, const value_type& b) {
            return {
                {M::op(a.first[0], b.first[0]), M::op(b.first[1], a.first[1])},
                a.second + b.second};
        }
    };
    int n;
    ll mx;
    std::vector<DynamicSegmentTree<M2>> seg;
    std::vector<bool> flag;
    SegmentTree<M> dat;
    RangeSumQuery<int> bit;

    void split_l(int k) {
        if (k == n) return;
        int l = bit.min_left(k + 1, [&](int x) { return x == 0; }) - 1;
        if (l == k) return;
        if (!flag[l]) {
            ll t = seg[l].max_right(
                0, [&](const auto& x) { return x.second <= k - l; });
            std::tie(seg[l], seg[k]) = split(std::move(seg[l]), t);
        }
        else {
            ll t = seg[l].min_left(
                mx, [&](const auto& x) { return x.second <= k - l; });
            std::tie(seg[k], seg[l]) = split(std::move(seg[l]), t);
        }
        bit.apply(k, 1);
        flag[k] = flag[l];
        dat.set(l, seg[l].all_prod().first[flag[l]]);
        dat.set(k, seg[k].all_prod().first[flag[k]]);
    }

public:
    RangeSortQuery() : RangeSortQuery(0) {}
    RangeSortQuery(int n, ll mx = inf)
        : RangeSortQuery(std::vector<T>(n, M::id()), std::vector<ll>(n, 0),
                         mx) {}
    RangeSortQuery(const std::vector<T>& v, const std::vector<ll>& key,
                   ll mx = inf)
        : n(v.size()), mx(mx), seg(n, DynamicSegmentTree<M2>(mx + 1)),
          flag(n, false), dat(n), bit(n, 1) {
        rep (i, n) {
            assert(0 <= key[i] && key[i] <= mx);
            seg[i].set(key[i], {{v[i], v[i]}, 1});
            dat.set(i, v[i]);
        }
    }
    void set(int k, ll key, const T& val) {
        assert(0 <= k && k < n);
        assert(0 <= key && key <= mx);
        int l = bit.min_left(k + 1, [&](int x) { return x == 0; }) - 1;
        int r = bit.max_right(k + 1, [&](int x) { return x == 0; });
        if (!flag[l]) {
            ll t = seg[l].max_right(
                0, [&](const auto& x) { return x.second <= k - l; });
            if (l != k) {
                std::tie(seg[l], seg[k]) = split(std::move(seg[l]), t);
                bit.apply(k, 1);
                dat.set(l, seg[l].all_prod().first[flag[l]]);
                flag[k] = flag[l];
            }
            if (k != r - 1) {
                std::tie(seg[k], seg[k + 1]) = split(std::move(seg[k]), t + 1);
                bit.apply(k + 1, 1);
                dat.set(k + 1, seg[k + 1].all_prod().first[flag[k]]);
                flag[k + 1] = flag[k];
            }
        }
        else {
            ll t = seg[l].min_left(mx, [&](const auto& x) {
                return x.second <= k - l;
            }) - 1;
            if (l != k) {
                std::tie(seg[k], seg[l]) = split(std::move(seg[l]), t + 1);
                bit.apply(k, 1);
                dat.set(l, seg[l].all_prod().first[flag[l]]);
                flag[k] = flag[l];
            }
            if (k != r - 1) {
                std::tie(seg[k + 1], seg[k]) = split(std::move(seg[k]), t);
                bit.apply(k + 1, 1);
                dat.set(k + 1, seg[k + 1].all_prod().first[flag[k]]);
                flag[k + 1] = flag[k];
            }
        }
        seg[k].reset();
        seg[k].set(key, {{val, val}, 1});
        dat.set(k, val);
    }
    void sort(int l, int r, bool reverse = false) {
        assert(0 <= l && l <= r && r <= n);
        split_l(l);
        split_l(r);
        ll t = l;
        while (t < r) {
            if (t != l) {
                seg[l].merge(std::move(seg[t]));
                bit.apply(t, -1);
                dat.set(t, M::id());
            }
            t = bit.max_right(t + 1, [&](int x) { return x == 0; });
        }
        flag[l] = reverse;
        dat.set(l, seg[l].all_prod().first[reverse]);
    }
    T get(int k) const {
        assert(0 <= k && k < n);
        int l = bit.min_left(k + 1, [&](int x) { return x == 0; }) - 1;
        ll t;
        if (!flag[l]) {
            t = seg[l].max_right(
                0, [&](const auto& x) { return x.second <= k - l; });
        }
        else {
            t = seg[l].min_left(mx, [&](const auto& x) {
                return x.second <= k - l;
            }) - 1;
        }
        return seg[l].get(t).first[0];
    }
    T prod(int l, int r) {
        assert(0 <= l && l <= r && r <= n);
        T res = M::id();
        int l2 = bit.min_left(l + 1, [&](int x) { return x == 0; }) - 1;
        int r2 = bit.min_left(r, [&](int x) { return x == 0; }) - 1;
        if (l2 == r2) {
            if (!flag[l2]) {
                ll tl = seg[l2].max_right(
                    0, [&](const auto& x) { return x.second <= l - l2; });
                ll tr = seg[l2].max_right(
                    0, [&](const auto& x) { return x.second <= r - l2; });
                return seg[l2].prod(tl, tr).first[0];
            }
            else {
                ll tl = seg[l2].min_left(
                    mx, [&](const auto& x) { return x.second <= l - l2; });
                ll tr = seg[l2].min_left(
                    mx, [&](const auto& x) { return x.second <= r - l2; });
                return seg[l2].prod(tr, tl).first[1];
            }
        }
        if (!flag[l2]) {
            ll t = seg[l2].max_right(
                0, [&](const auto& x) { return x.second <= l - l2; });
            res = seg[l2].prod(t, mx + 1).first[0];
        }
        else {
            ll t = seg[l2].min_left(mx, [&](const auto& x) {
                return x.second <= l - l2;
            }) - 1;
            res = seg[l2].prod(0, t + 1).first[1];
        }
        res = M::op(res, dat.prod(l2 + 1, r2));
        if (!flag[r2]) {
            ll t = seg[r2].max_right(
                0, [&](const auto& x) { return x.second <= r - r2; });
            res = M::op(res, seg[r2].prod(0, t).first[0]);
        }
        else {
            ll t = seg[r2].min_left(mx, [&](const auto& x) {
                return x.second <= r - r2;
            }) - 1;
            res = M::op(res, seg[r2].prod(t + 1, mx + 1).first[1]);
        }
        return res;
    }
};

/**
 * @brief RangeSortQuery
 * @docs RangeSortQuery.md
 */
