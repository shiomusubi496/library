#pragma once

#include "../../other/template.hpp"
#include "../../other/monoid.hpp"

class Struct2D {
private:
    int ori, n, h;
    compressor<ll> psx;
    std::vector<std::vector<ll>> idx;

public:
    template<class F> void init(F&& f, std::vector<ll> xs, std::vector<ll> ys) {
        psx.push(xs);
        psx.build();
        psx.press(xs);
        ori = psx.size();
        h = bitop::ceil_log2(ori);
        n = 1 << h;
        idx.resize(n << 1);
        rep (i, xs.size()) idx[xs[i] + n].push_back(ys[i]);
        rep (i, ori) {
            std::sort(all(idx[i + n]));
            idx[i + n].erase(std::unique(all(idx[i + n])), idx[i + n].end());
        }
        rrep (i, n, 1) {
            std::merge(all(idx[i << 1]), all(idx[i << 1 | 1]),
                       std::back_inserter(idx[i]));
            idx[i].erase(std::unique(all(idx[i])), idx[i].end());
        }
        std::vector<int> sz(n << 1);
        rep (i, n << 1) sz[i] = idx[i].size();
        f(sz);
    }
    template<class F, class M>
    void init(F&& f, std::vector<ll> xs, std::vector<ll> ys,
              std::vector<typename M::value_type> v) {
        psx.push(xs);
        psx.build();
        psx.press(xs);
        ori = psx.size();
        h = bitop::ceil_log2(ori);
        n = 1 << h;
        std::vector<std::vector<std::pair<ll, typename M::value_type>>> tmp(
            n << 1);
        rep (i, xs.size()) tmp[xs[i] + n].emplace_back(ys[i], v[i]);
        rep (i, ori) {
            std::stable_sort(all(tmp[i + n]), [](const auto& a, const auto& b) {
                return a.first < b.first;
            });
            int k = 0;
            rep (j, 1, tmp[i + n].size()) {
                if (tmp[i + n][k].first == tmp[i + n][j].first) {
                    tmp[i + n][k].second =
                        M::op(tmp[i + n][k].second, tmp[i + n][j].second);
                }
                else {
                    tmp[i + n][++k] = tmp[i + n][j];
                }
            }
            tmp[i + n].resize(k + 1);
        }
        rrep (i, n, 1) {
            tmp[i].reserve(tmp[i << 1].size() + tmp[i << 1 | 1].size());
            std::merge(
                all(tmp[i << 1]), all(tmp[i << 1 | 1]),
                std::back_inserter(tmp[i]),
                [](const auto& a, const auto& b) { return a.first < b.first; });
            int k = 0;
            rep (j, 1, tmp[i].size()) {
                if (tmp[i][k].first == tmp[i][j].first) {
                    tmp[i][k].second =
                        M::op(tmp[i][k].second, tmp[i][j].second);
                }
                else {
                    tmp[i][++k] = tmp[i][j];
                }
            }
            tmp[i].resize(k + 1);
        }
        idx.resize(n << 1);
        std::vector<std::vector<typename M::value_type>> dat(n << 1);
        rep (i, n << 1) {
            idx[i].resize(tmp[i].size());
            dat[i].resize(tmp[i].size());
            rep (j, tmp[i].size()) {
                idx[i][j] = tmp[i][j].first;
                dat[i][j] = tmp[i][j].second;
            }
        }
        f(dat);
    }
    template<class Upd> void apply(ll x, ll y, Upd&& upd) const {
        int k = psx.get(x) + n;
        auto itr = std::lower_bound(all(idx[k]), y);
        assert(itr != idx[k].end() && *itr == y);
        upd(k, itr - idx[k].begin());
        while (k > 1) {
            k >>= 1;
            upd(k, std::lower_bound(all(idx[k]), y) - idx[k].begin());
        }
    }
    template<class Upd, class Upd2, class Mrg>
    void update(ll x, ll y, Upd&& upd, Upd2&& upd2, Mrg&& mrg) const {
        int k = psx.get(x) + n;
        auto itr = std::lower_bound(all(idx[k]), y);
        assert(itr != idx[k].end() && *itr == y);
        upd(k, itr - idx[k].begin());
        while (k > 1) {
            int l = k ^ 1;
            auto itr2 = std::lower_bound(all(idx[l]), y);
            if (itr2 != idx[l].end() && *itr2 == y) {
                if (k < l) mrg(l, itr2 - idx[l].begin(), false);
                else mrg(l, itr2 - idx[l].begin(), true);
            }
            k >>= 1;
            upd2(k, std::lower_bound(all(idx[k]), y) - idx[k].begin());
        }
    }
    template<class Mrg> void prod(ll l, ll r, ll u, ll d, Mrg&& mrg) const {
        assert(l <= r && u <= d);
        l = psx.lower_bound(l) + n;
        r = psx.lower_bound(r) + n;
        while (l != r) {
            if (l & 1) {
                int a = std::lower_bound(all(idx[l]), u) - idx[l].begin();
                int b = std::lower_bound(all(idx[l]), d) - idx[l].begin();
                mrg(l, a, b, true);
                ++l;
            }
            if (r & 1) {
                --r;
                int a = std::lower_bound(all(idx[r]), u) - idx[r].begin();
                int b = std::lower_bound(all(idx[r]), d) - idx[r].begin();
                mrg(r, a, b, false);
            }
            l >>= 1;
            r >>= 1;
        }
    }
    template<class Mrg> void get(ll x, ll y, Mrg&& mrg) const {
        int k = psx.get(x) + n;
        auto itr = std::lower_bound(all(idx[k]), y);
        assert(itr != idx[k].end() && *itr == y);
        mrg(k, itr - idx[k].begin());
    }
};
