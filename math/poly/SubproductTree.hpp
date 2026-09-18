#pragma once

#include "../../other/template.hpp"
#include "FormalPowerSeries.hpp"

template<class T>
class SubproductTree {
private:
    int n, N;
    std::vector<FormalPowerSeries<T>> dat, ntts;

public:
    SubproductTree(const std::vector<T>& xs) { init(xs); }
    template<bool AlwaysTrue = true,
             typename std::enable_if<
                 AlwaysTrue && is_ntt_friendly_modint<T>::value>::type* =
                 nullptr>
    void init(const std::vector<T>& xs) {
        n = xs.size(), N = 1 << bitop::ceil_log2(n);
        dat.resize(2 * N);
        ntts.resize(2 * N);
        rep (i, n) dat[i + N] = {-xs[i], 1};
        rep (i, n, N) dat[i + N] = {0, 1};
        rep (i, N, 2 * N) ntts[i] = {dat[i][0] + dat[i][1], dat[i][0] - dat[i][1]};
        rrep (i, 1, N) {
            int m = dat[i * 2 + 0].size() * 2 - 2;
            ntts[i].assign(m, -1);
            rep (j, m) ntts[i][j] += ntts[i * 2 + 0][j] * ntts[i * 2 + 1][j];
            dat[i] = ntts[i];
            inverse_number_theoretic_transform(dat[i]);
            ntt_doubling_(ntts[i], dat[i]);
            rep (j, m) ++ntts[i][j];
            rep (j, m, 2 * m) --ntts[i][j];
            dat[i].push_back(1);
        }
    }
    template<bool AlwaysTrue = true,
             typename std::enable_if<
                 AlwaysTrue && !is_ntt_friendly_modint<T>::value>::type* =
                 nullptr>
    void init(const std::vector<T>& xs) {
        n = xs.size(), N = 1 << bitop::ceil_log2(n);
        dat.resize(2 * N);
        rep (i, n) dat[i + N] = {-xs[i], 1};
        rep (i, n, N) dat[i + N] = {0, 1};
        rrep (i, 1, N) dat[i] = dat[i * 2 + 0] * dat[i * 2 + 1];
    }
    const FormalPowerSeries<T>& operator[](int i) const { return dat[i]; }
    const FormalPowerSeries<T>& get_ntt(int i) const { return ntts[i]; }
};
