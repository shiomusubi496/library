#pragma once

#include "../../other/template.hpp"

template<class T> class StaticRangeMode {
private:
    int n, bs, bn;
    compressor<T> ps;
    std::vector<int> v;
    std::vector<std::vector<std::pair<int, int>>> mds;
    std::vector<std::vector<int>> idx;
    std::vector<int> ridx;

public:
    StaticRangeMode() = default;
    StaticRangeMode(const std::vector<T>& v_) { init(v_); }

    void init(const std::vector<T>& v_) {
        if (v_.empty()) return;
        ps.push(v_);
        ps.build();
        v = ps.pressed(v_);
        n = v.size();
        bs = sqrt(n);
        bn = (n + bs - 1) / bs;
        mds.assign(bn, std::vector<std::pair<int, int>>(bn + 1));
        std::vector<int> cnt(ps.size());
        int md = 0;
        rep (i, bn) {
            rep (j, i, bn) {
                rep (k, j * bs, std::min<int>(n, (j + 1) * bs)) {
                    ++cnt[v[k]];
                    if (cnt[v[k]] > cnt[md]) md = v[k];
                }
                mds[i][j + 1] = {md, cnt[md]};
            }
            rep (j, i * bs, n) cnt[v[j]] = 0;
        }
        idx.assign(ps.size(), std::vector<int>());
        ridx.resize(n);
        rep (i, n) {
            ridx[i] = idx[v[i]].size();
            idx[v[i]].push_back(i);
        }
    }

    std::pair<T, int> prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= n);
        assert(l < r);
        int lb = l / bs, rb = r / bs;
        int md = -1, cnt = -1;
        if (lb == rb) {
            rep (i, l, r) {
                int x = v[i];
                const int k = ridx[i];
                while (k + cnt < (int)idx[x].size() && idx[x][k + cnt] < r) {
                    ++cnt;
                    md = x;
                }
            }
        }
        else {
            if (lb + 1 < rb) std::tie(md, cnt) = mds[lb + 1][rb];
            rep (i, l, (lb + 1) * bs) {
                int x = v[i];
                const int k = ridx[i];
                while (k + cnt < (int)idx[x].size() && idx[x][k + cnt] < r) {
                    ++cnt;
                    md = x;
                }
            }
            rep (i, rb * bs, r) {
                int x = v[i];
                const int k = ridx[i];
                while (k - cnt >= 0 && idx[x][k - cnt] >= l) {
                    ++cnt;
                    md = x;
                }
            }
        }
        return {ps[md], cnt};
    }
};

/**
 * @brief StaticRangeMode(区間最頻値)
 * @docs docs/data-struct/segment/StaticRangeMode.md
 * @see https://noshi91.hatenablog.com/entry/2020/10/26/140105
 */
