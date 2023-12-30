#pragma once

#include "../../other/template.hpp"

template<class F>
void max_rectangle_of_histogram(const std::vector<int>& A, const F& f) {
    const int N = A.size();
    std::stack<int> st;
    rep (i, N) {
        while (!st.empty() && A[st.top()] >= A[i]) {
            int j = st.top();
            st.pop();
            int k = st.empty() ? 0 : st.top() + 1;
            f(k, i, A[j]);
        }
        st.push(i);
    }
    while (!st.empty()) {
        int j = st.top();
        st.pop();
        int k = st.empty() ? 0 : st.top() + 1;
        f(k, N, A[j]);
    }
}

template<class F>
void max_rectangle(const std::vector<std::vector<bool>>& A, const F& f) {
    if (A.empty() || A[0].empty()) return;
    int H = A.size(), W = A[0].size();
    std::vector<std::vector<int>> B(H, std::vector<int>(W));
    rrep (i, H)
        rep (j, W) {
            B[i][j] = i == H - 1 ? 1 : B[i + 1][j] + 1;
            if (A[i][j]) B[i][j] = 0;
        }
    rep (i, H) {
        max_rectangle_of_histogram(
            B[i], [&](int l, int r, int h) { f(i, l, i + h, r); });
    }
}

/**
 * @brief MaxRectangle(最大長方形)
 * @docs docs/data-struct/other/MaxRectangle.md
 */
