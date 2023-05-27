#pragma once

#include "../../other/template.hpp"
#include "../../other/monoid2.hpp"
#include "../../data-struct/segment/LazySegmentTree.hpp"

ll area_of_union_of_rectangles(const std::vector<std::array<ll, 4>>& A) {
    const int N = A.size();
    presser<ll> ps;
    rep (i, N) {
        ps.push_back(A[i][0]);
        ps.push_back(A[i][2]);
    }
    ps.build();
    std::vector<std::array<ll, 4>> B(2 * N);
    rep (i, N) {
        const ll l = ps.get(A[i][0]), r = ps.get(A[i][2]);
        B[2 * i] = {A[i][1], l, r, 1};
        B[2 * i + 1] = {A[i][3], l, r, -1};
    }
    std::sort(all(B));
    LazySegmentTree<Monoid::AddMinCount<ll>> seg([&] {
        std::vector<std::pair<ll, ll>> v(ps.size() - 1);
        rep (i, ps.size() - 1) v[i] = {0, ps[i + 1] - ps[i]};
        return v;
    }());
    const ll w = ps[ps.size() - 1] - ps[0];
    ll res = 0;
    rep (i, 2 * N - 1) {
        seg.apply(B[i][1], B[i][2], B[i][3]);
        const auto p = seg.all_prod();
        const ll t = p.first == 0 ? p.second : 0;
        res += (w - t) * (B[i + 1][0] - B[i][0]);
    }
    return res;
}