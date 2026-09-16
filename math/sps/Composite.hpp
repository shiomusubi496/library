#pragma once

#include "../../other/template.hpp"
#include "../Combinatorics.hpp"
#include "../convolution/SubsetConvolution.hpp"
#include "../poly/FormalPowerSeries.hpp"

template<class T, class Comb = Combinatorics<T>>
std::vector<T> fps_composite_of_sps(FormalPowerSeries<T> f, std::vector<T> s) {
    int n = s.size(), m = bitop::ceil_log2(n);
    assert(s[0] == 0);
    assert(n == (1 << m));
    f.resize(m + 1);
    Comb::init(m + 1);
    rep (i, m + 1) f[i] *= Comb::fact(i);
    std::vector<T> a(1 << m, f[m]);
    rrep (i, m) {
        rrep (j, m - i) {
            std::vector<T> b(1 << j), c(1 << j);
            rep (k, 1 << j) b[k] = a[k];
            rep (k, 1 << j) c[k] = s[k + (1 << j)];
            std::vector<T> d = subset_convolution(b, c);
            rep (k, 1 << j) a[k + (1 << j)] = d[k];
        }
        a[0] = f[i];
    }
    return a;
}

template<class T>
std::vector<T> exp_of_sps(std::vector<T> s) {
    int n = s.size(), m = bitop::ceil_log2(n);
    assert(s[0] == 0);
    assert(n == (1 << m));
    std::vector<T> a(1 << m, 1);
    rrep (i, m) {
        int j = m - i - 1;
        std::vector<T> b(1 << j), c(1 << j);
        rep (k, 1 << j) b[k] = a[k];
        rep (k, 1 << j) c[k] = s[k + (1 << j)];
        std::vector<T> d = subset_convolution(b, c);
        rep (k, 1 << j) a[k + (1 << j)] = d[k];
    }
    return a;
}

template<class T, class Comb = Combinatorics<T>>
std::vector<T> polynomial_composite_of_sps(FormalPowerSeries<T> f, std::vector<T> s) {
    Comb::init(f.size());
    int n = s.size(), m = bitop::ceil_log2(n);
    FormalPowerSeries<T> g(m + 1);
    T c = s[0];
    rep (i, m + 1) {
        T d = 1;
        rep (j, i, f.size()) {
            g[i] += f[j] * Comb::comb(j, i) * d;
            d *= c;
        }
    }
    s[0] = 0;
    return fps_composite_of_sps(g, s);
}

template<class T, class Comb = Combinatorics<T>>
std::vector<T> power_projection_of_sps(std::vector<T> s, std::vector<T> w, int M) {
    int n = s.size(), m = bitop::ceil_log2(n);
    assert(n == (1 << m));
    assert(s.size() == w.size());
    T c = s[0];
    s[0] = 0;
    FormalPowerSeries<T> f(m + 1);
    rep (i, m) {
        f[i] = w[0];
        FormalPowerSeries<T> a(1 << (m - 1 - i));
        rep (j, m - i) {
            std::vector<T> c(1 << j), d(1 << j);
            rep (k, 1 << j) c[k] = s[k + (1 << j)];
            rep (k, 1 << j) d[k] = w[(2 << j) - 1 - k];
            std::vector<T> b = subset_convolution(d, c);
            rep (k, 1 << j) a[k] += b[(1 << j) - 1 - k];
        }
        w = a;
    }
    f[m] = w[0];
    Comb::init(M);
    FormalPowerSeries<T> g(M);
    rep (i, m + 1) {
        T d = 1;
        rep (j, i, M) {
            g[j] += f[i] * Comb::perm(j, i) * d;
            d *= c;
        }
    }
    return g;
}
