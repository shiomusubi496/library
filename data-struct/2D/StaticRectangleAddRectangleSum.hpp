#pragma once

#include "../../other/template.hpp"
#include "../../other/monoid2.hpp"
#include "../segment/RAQBIT.hpp"

template<class T>
std::vector<T> static_rectangle_add_rectangle_sum(
    const std::vector<std::pair<std::array<ll, 4>, T>>& A,
    const std::vector<std::array<ll, 4>>& B) {
    int N = A.size(), M = B.size();
    if (N == 0 || M == 0) return std::vector<T>(M, 0);
    compressor<ll> ps;
    ps.reserve(2 * N + 2 * M);
    rep (i, N) {
        ps.push_back(A[i].first[0]);
        ps.push_back(A[i].first[2]);
    }
    rep (i, M) {
        ps.push_back(B[i][0]);
        ps.push_back(B[i][2]);
    }
    ps.build();
    std::vector<std::tuple<ll, ll, ll, ll, T>> C(2 * N + 2 * M);
    rep (i, N) {
        ll l = ps.get(A[i].first[0]), r = ps.get(A[i].first[2]);
        C[2 * i] = {A[i].first[1], M, l, r, A[i].second};
        C[2 * i + 1] = {A[i].first[3], M, l, r, -A[i].second};
    }
    rep (i, M) {
        ll l = ps.get(B[i][0]), r = ps.get(B[i][2]);
        C[2 * N + 2 * i] = {B[i][1], i, l, r, -1};
        C[2 * N + 2 * i + 1] = {B[i][3], i, l, r, 1};
    }
    std::sort(all(C), [&](const auto& a, const auto& b) {
        if (std::get<0>(a) != std::get<0>(b))
            return std::get<0>(a) < std::get<0>(b);
        return std::get<1>(a) < std::get<1>(b);
    });
    std::vector<T> xs(ps.size() - 1);
    rep (i, ps.size() - 1) xs[i] = ps[i + 1] - ps[i];
    RAQRSQBIT<T> bit1(xs), bit2(xs);
    std::vector<T> ans(M);
    for (const auto& [x, i, l, r, v] : C) {
        if (i == M) {
            bit1.add(l, r, v);
            bit2.add(l, r, -v * x);
        }
        else {
            ans[i] += (bit1.prod(l, r) * x + bit2.prod(l, r)) * v;
        }
    }
    return ans;
}
