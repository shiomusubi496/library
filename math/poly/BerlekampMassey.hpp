#pragma once

#include "../../other/template.hpp"
#include "FormalPowerSeries.hpp"

template<class T>
FormalPowerSeries<T> berlekamp_massey(std::vector<T> S) {
    int N = S.size();
    FormalPowerSeries<T> Q{1}, B{1};
    int L = 0, p = -1;
    T b = 1;
    rep (i, N) {
        T d = 0;
        rep (j, Q.size()) d += Q[j] * S[i - j];
        if (d == 0) continue;
        FormalPowerSeries<T> R = Q - ((B * d / b) << (i - p));
        if (2 * L <= i) {
            L = i + 1 - L;
            B = std::move(Q);
            p = i;
            b = d;
        }
        Q = std::move(R);
    }
    return Q.prefix(L + 1);
}
