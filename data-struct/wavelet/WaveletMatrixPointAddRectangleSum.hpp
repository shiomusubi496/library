#pragma once

#include "../../other/template.hpp"
#include "../../other/monoid.hpp"
#include "../segment/SegmentTree.hpp"
#include "FullyIndexableDictionary.hpp"

template<class T, class M = Monoid::Sum<ll>, class BIT = SegmentTree<M>>
class WaveletMatrixPointAddRectangleSum {
private:
    using U = typename M::value_type;
    int n, m, h;
    presser<std::pair<T, T>> points;
    presser<T> ps;
    std::vector<FullyIndexableDictionary> dat;
    std::vector<BIT> bit;
    std::vector<int> mid;

public:
    WaveletMatrixPointAddRectangleSum() = default;
    void add_point(const T& x, const T& y) {
        points.emplace_back(x, y);
        ps.push_back(y);
    }
    void build() {
        points.build();
        ps.build();
        n = points.size();
        m = ps.size();
        h = bitop::ceil_log2(m);
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
        bit.assign(h, BIT(n));
    }
    void apply(const T& x, const T& y, const U& z) {
        int k = points.get(std::pair<T, T>(x, y));
        int v = ps.get(y);
        rrep (i, h) {
            if ((v >> i) & 1) k = dat[i].rank(true, k) + mid[i];
            else k = dat[i].rank(false, k);
            bit[i].apply(k, z);
        }
    }
    void set(const T& x, const T& y, const U& z) {
        int k = points.get(std::pair<T, T>(x, y));
        int v = ps.get(y);
        rrep (i, h) {
            if ((v >> i) & 1) k = dat[i].rank(true, k) + mid[i];
            else k = dat[i].rank(false, k);
            bit[i].set(k, z);
        }
    }

private:
    U prod(int l, int r, int upper) const {
        T res = M::id();
        rrep (i, h) {
            const int l0 = dat[i].rank(false, l);
            const int r0 = dat[i].rank(false, r);
            if ((upper >> i) & 1) {
                res = M::op(res, bit[i].prod(l0, r0));
                l = l - l0 + mid[i];
                r = r - r0 + mid[i];
            }
            else {
                l = l0;
                r = r0;
            }
        }
        return res;
    }

public:
    U prod(const T& xl, const T& xr, const T& yl, const T& yr) const {
        int l = points.lower_bound(std::pair<T, T>(xl, infinity<T>::mvalue));
        int r = points.lower_bound(std::pair<T, T>(xr, infinity<T>::mvalue));
        int y = ps.lower_bound(yl);
        int z = ps.lower_bound(yr);
        return M::inv(prod(l, r, z), prod(l, r, y));
    }
};

/**
 * @brief WaveletMatrixPointAddRectangleSum.hpp
 * @docs docs/data-struct/wavelet/WaveletMatrixPointAddRectangleSum.md
 */
