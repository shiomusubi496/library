#pragma once

#include "../../other/template.hpp"
#include "FullyIndexableDictionary.hpp"

using T = int;
class WaveletMatrix {
private:
    int n, m, h;
    presser<T> ps;
    std::vector<FullyIndexableDictionary> dat;
    std::vector<int> mid, start;

public:
    WaveletMatrix() = default;
    WaveletMatrix(const std::vector<T>& v) { init(v); }
    void init(std::vector<T> v_) {
        n = v_.size();
        ps.push(v_);
        ps.build();
        m = ps.size();
        std::vector<int> v = ps.pressed(v_);
        h = bitop::ceil_log2(m + 1);
        dat.assign(h, FullyIndexableDictionary(n));
        mid.resize(h);
        std::vector<T> lv(n), rv(n);
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
        start.resize(m);
        rep (i, n) {
            if (i == 0 || v[i - 1] != v[i]) start[v[i]] = i;
        }
    }
    T access(int k) const {
        assert(0 <= k && k < n);
        int res = 0;
        rrep (i, h) {
            if (dat[i][k]) {
                res |= (1ull << i);
                k = dat[i].rank(true, k) + mid[i];
            }
            else {
                k = dat[i].rank(false, k);
            }
        }
        return ps[res];
    }
    T operator[](int k) const { return access(k); }
    int rank(int k, const T& x) const {
        assert(0 <= k && k <= n);
        int v = ps.get(x);
        rrep (i, h) {
            if ((v >> i) & 1) k = dat[i].rank(true, k) + mid[i];
            else k = dat[i].rank(false, k);
        }
        return k - start[v];
    }
    int rank(const T& x) const { return rank(n, x); }
    int rank(int l, int r, const T& x) const {
        assert(0 <= l && l <= r && r <= n);
        int v = ps.get(x);
        rrep (i, h) {
            if ((v >> i) & 1) {
                l = dat[i].rank(true, l) + mid[i];
                r = dat[i].rank(true, r) + mid[i];
            }
            else {
                l = dat[i].rank(false, l);
                r = dat[i].rank(false, r);
            }
        }
        return r - l;
    }
    int select(const T& x, int k) const {
        assert(0 <= k && k < rank(x));
        int v = ps.get(x);
        k += start[v];
        rep (i, h) {
            if (mid[i] <= k) k = dat[i].select(true, k - mid[i]);
            else k = dat[i].select(false, k);
        }
        return k;
    }
    T quantile(int l, int r, int k) const {
        assert(0 <= l && l <= r && r <= n);
        assert(0 <= k && k < r - l);
        int res = 0;
        rrep (i, h) {
            int cnt = dat[i].rank(false, r) - dat[i].rank(false, l);
            if (cnt <= k) {
                res |= (1ull << i);
                l = dat[i].rank(true, l) + mid[i];
                r = dat[i].rank(true, r) + mid[i];
                k -= cnt;
            }
            else {
                l = dat[i].rank(false, l);
                r = dat[i].rank(false, r);
            }
        }
        return ps[res];
    }
    int count_le(int l, int r, const T& x) const {
        assert(0 <= l && l <= r && r <= n);
        int v = ps.upper_bound(x) - ps.contains(x);
        int res = 0;
        rrep (i, h) {
            if ((v >> i) & 1) {
                const int a = dat[i].rank(true, l);
                const int b = dat[i].rank(true, r);
                res += (r - l) - (b - a);
                l = a + mid[i];
                r = b + mid[i];
            }
            else {
                l = dat[i].rank(false, l);
                r = dat[i].rank(false, r);
            }
        }
        return res;
    }
    int count(int l, int r, const T& x, const T& y) const {
        return count_le(l, r, y) - count_le(l, r, x);
    }
};

/**
 * @brief WaveletMatrix
 * @docs docs/data-struct/wavelet/WaveletMatrix.md
 */
