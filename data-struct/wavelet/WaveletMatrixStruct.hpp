#pragma once

#include "../../other/template.hpp"
#include "../../other/monoid.hpp"
#include "FullyIndexableDictionary.hpp"

class WaveletMatrixStruct {
private:
    int n, m, h;
    compressor<PLL> points;
    compressor<ll> ps;
    std::vector<FullyIndexableDictionary> dat;
    std::vector<int> mid;

public:
    template<class F>
    void init(F&& f, const std::vector<ll>& xs, const std::vector<ll>& ys) {
        rep (i, xs.size()) points.emplace_back(xs[i], ys[i]);
        points.build();
        ps.push(ys);
        ps.build();
        n = points.size();
        m = ps.size();
        h = bitop::ceil_log2(m + 1);
        std::vector<int> v(n);
        rep (i, n) v[i] = ps.get(points[i].second);
        dat.assign(h, FullyIndexableDictionary(n));
        mid.resize(h);
        std::vector<int> lv(n), rv(n);
        rrep (i, h) {
            int l = 0, r = 0;
            rep (j, n) {
                if ((v[j] >> i) & 1) {
                    dat[i].set(j);
                    rv[r++] = v[j];
                }
                else {
                    lv[l++] = v[j];
                }
            }
            dat[i].build();
            mid[i] = l;
            v.swap(lv);
            rep (j, r) v[l + j] = rv[j];
        }
        f(h, n);
    }
    template<class F, class M>
    void init(F&& f, const std::vector<ll>& xs, const std::vector<ll>& ys,
              const std::vector<typename M::value_type>& zs) {
        using T = typename M::value_type;
        init([](int, int) {}, xs, ys);
        std::vector<std::vector<T>> v(h, std::vector<T>(n, M::id()));
        rep (i, xs.size()) {
            apply(xs[i], ys[i],
                  [&](int j, int k) { v[j][k] = M::op(v[j][k], zs[i]); });
        }
        f(v);
    }
    template<class Upd> void apply(ll x, ll y, Upd&& upd) {
        int k = points.get(PLL{x, y});
        int v = ps.get(y);
        rrep (i, h) {
            if ((v >> i) & 1) k = dat[i].rank(true, k) + mid[i];
            else k = dat[i].rank(false, k);
            upd(i, k);
        }
    }

private:
    template<class Mrg> void prod(int l, int r, int upper, Mrg&& mrg) const {
        rrep (i, h) {
            const int l0 = dat[i].rank(false, l);
            const int r0 = dat[i].rank(false, r);
            if ((upper >> i) & 1) {
                mrg(i, l0, r0);
                l = l - l0 + mid[i];
                r = r - r0 + mid[i];
            }
            else {
                l = l0;
                r = r0;
            }
        }
    }

public:
    template<class Mrg, class Mrg2>
    void prod(ll xl, ll xr, ll yl, ll yr, Mrg&& mrg, Mrg2&& mrg2) const {
        int l = points.lower_bound(PLL{xl, infinity<ll>::mvalue});
        int r = points.lower_bound(PLL{xr, infinity<ll>::mvalue});
        int y = ps.lower_bound(yl);
        int z = ps.lower_bound(yr);
        prod(l, r, z, mrg);
        prod(l, r, y, mrg2);
    }
};
