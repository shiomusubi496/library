#pragma once

#include "../../other/template.hpp"
#include "../../random/Random.hpp"
#include "../poly/BerlekampMassey.hpp"
#include "../poly/ConsecutiveTermsOfLinearRecurrence.hpp"

template<class T, class F> FormalPowerSeries<T> minimum_polynomial_blackbox(int n, F&& A) {
    std::vector<T> a(2 * n), b(n), c(n);
    rep (i, n) b[i] = rand32.uniform<unsigned int>(1, T::get_mod() - 1);
    rep (i, n) c[i] = rand32.uniform<unsigned int>(1, T::get_mod() - 1);
    rep (i, 2 * n) {
        rep (j, n) a[i] += b[j] * c[j];
        if (i < 2 * n - 1) b = A(b);
    }
    return berlekamp_massey(a).rev();
}

template<class T, class F> T determinant_blackbox(int n, F&& A) {
    std::vector<T> D(n);
    rep (i, n) D[i] = rand32.uniform<unsigned int>(1, T::get_mod() - 1);
    FormalPowerSeries<T> chr = minimum_polynomial_blackbox<T>(n, [&](std::vector<T> b) {
        rep (i, n) b[i] *= D[i];
        return A(b);
    });
    T detd = 1;
    rep (i, n) detd *= D[i];
    return chr[0] / detd * (n & 1 ? -1 : 1);
}

template<class T, class F> std::vector<T> matrix_pow_blackbox(int n, F&& A, ll K, std::vector<T> b) {
    std::vector<T> a(2 * n), c(n);
    std::vector<std::vector<T>> bs(2 * n);
    bs[0] = b;
    rep (i, n) c[i] = rand32.uniform<unsigned int>(1, T::get_mod() - 1);
    rep (i, 2 * n) {
        rep (j, n) a[i] += bs[i][j] * c[j];
        if (i < 2 * n - 1) bs[i + 1] = A(bs[i]);
    }
    FormalPowerSeries<T> r = x_pow_k_mod_F(berlekamp_massey(a).rev(), K);
    std::vector<T> d(n);
    rep (i, r.size()) {
        rep (j, n) d[j] += bs[i][j] * r[i];
    }
    return d;
}
