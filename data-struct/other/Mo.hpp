#pragma once

#include "../../other/template.hpp"

class Mo {
private:
    int n;
    std::vector<std::pair<int, int>> data;

public:
    Mo(int n) : n(n) {}
    Mo(int n, const std::vector<std::pair<int, int>>& a) : n(n), data(a) {}
    Mo(int n, std::vector<std::pair<int, int>>&& a)
        : n(n), data(std::move(a)) {}
    void push(int l, int r) { data.emplace_back(l, r); }
    template<class AL, class AR, class DL, class DR, class REM>
    void build(const AL& add_left, const AR& add_right, const DL& delete_left,
               const DR& delete_right, const REM& rem) const {
        if (data.empty()) return;
        int q = data.size();
        const int w = std::max<int>(1, 1.0 * n / sqrt(2.0 * q / 3.0));
        std::vector<int> idx(q);
        rep (i, q) idx[i] = i;
        std::sort(all(idx), [&](int a, int b) -> bool {
            const int ab = data[a].first / w, bb = data[b].first / w;
            if (ab != bb) return ab < bb;
            return ab & 1 ? data[a].second < data[b].second
                          : data[a].second > data[b].second;
        });
        int l = 0, r = 0;
        for (const auto& i : idx) {
            while (data[i].first < l) add_left(--l);
            while (data[i].second > r) add_right(r++);
            while (data[i].first > l) delete_left(l++);
            while (data[i].second < r) delete_right(--r);
            rem(i);
        }
    }
    template<class A, class D, class REM>
    void build(const A& add, const D& del, const REM& rem) const {
        build(add, add, del, del, rem);
    }
};

/**
 * @brief Mo's Algorithm
 * @docs docs/data-struct/other/Mo.md
 * @see https://nyaannyaan.github.io/library/misc/mo.hpp
 */
