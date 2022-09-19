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
    void init(std::vector<T> v) {
        n = v.size();
        ps.push(v);
        ps.build();
        m = ps.size();
        ps.press(v);
        h = bitop::ceil_log2(m);
        dat.assign(h, FullyIndexableDictionary(n));
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
    int rank(int l, int r, const T& x) const { return rank(r, x) - rank(l, x); }
    int select(int k, const T& x) const {
        assert(0 <= k && k < rank(x));
        int v = ps.get(x);
        k += start[v];
        rep (i, h) {
            if (mid[i] <= k) k = dat[i].select(true, k - mid[i]);
            else k = dat[i].select(false, k);
        }
        return k;
    }
    
};

/**
 * @brief
 *
 */
