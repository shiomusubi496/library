#pragma once

#include "../../other/template.hpp"
#include "FormalPowerSeries.hpp"

namespace internal {

template<class T> class ProductTree {
private:
    int n;
    std::vector<FormalPowerSeries<T>> dat;

public:
    ProductTree(const std::vector<T>& xs) {
        n = xs.size();
        dat.resize(n << 1);
        rep (i, n) dat[i + n] = FormalPowerSeries<T>{-xs[i], 1};
        rrep (i, n, 1) dat[i] = dat[i << 1] * dat[i << 1 | 1];
    }
    const FormalPowerSeries<T>& operator[](int k) const& { return dat[k]; }
    FormalPowerSeries<T> operator[](int k) && { return std::move(dat[k]); }
};

template<class T>
std::vector<T> multipoint_evaluation(const FormalPowerSeries<T>& a,
                                     const std::vector<T>& b,
                                     const ProductTree<T>& c) {
    int m = b.size();
    std::vector<FormalPowerSeries<T>> d(m << 1);
    d[1] = a % c[1];
    rep (i, 2, m << 1) d[i] = d[i >> 1] % c[i];
    std::vector<T> e(m);
    rep (i, m) e[i] = d[m + i].empty() ? T{0} : d[m + i][0];
    return e;
}

} // namespace internal

template<class T>
std::vector<T> multipoint_evaluation(const FormalPowerSeries<T>& a,
                                     const std::vector<T>& b) {
    if (a.empty() || b.empty()) return std::vector<T>(b.size(), T{0});
    if (a.size() <= 32 || b.size() <= 32) {
        std::vector<T> res(b.size());
        rep (i, b.size()) res[i] = a.eval(b[i]);
        return res;
    }
    return internal::multipoint_evaluation(a, b, internal::ProductTree<T>(b));
}

template<class T>
std::vector<T> multipoint_evaluation_geometric(const FormalPowerSeries<T>& f,
                                               T a, T r, int m) {
    if (f.empty() || m == 0) return std::vector<T>(m, T{0});
    if (a == 0 || r == 1) return std::vector<T>(m, f.eval(a));
    if (f.size() <= 32 || m <= 32) {
        std::vector<T> res(m);
        rep (i, m) {
            res[i] = f.eval(a);
            a *= r;
        }
        return res;
    }
    if (r == 0) {
        std::vector<T> res(m, f.eval(0));
        res[0] = f.eval(a);
        return res;
    }
    int n = f.size();
    int l = 1 << bitop::ceil_log2(n + m - 1);
    std::vector<T> p(l), q(l);
    T ir = T{1} / r, t = 1, t2 = 1;
    rep (i, n) {
        p[n - i - 1] = f[i] * t;
        t *= a * t2;
        t2 *= ir;
    }
    t = t2 = 1;
    rep (i, n + m - 1) {
        q[i] = t;
        t *= t2;
        t2 *= r;
    }
    number_theoretic_transform(p);
    number_theoretic_transform(q);
    rep (i, l) p[i] *= q[i];
    inverse_number_theoretic_transform(p);
    std::vector<T> ans(p.begin() + (n - 1), p.begin() + (n + m - 1));
    t = t2 = 1;
    rep (i, m) {
        ans[i] *= t;
        t *= t2;
        t2 *= ir;
    }
    return ans;
}

/**
 * @brief MultipointEvaluation(多点評価)
 * @docs docs/math/poly/MultipointEvaluation.md
 */
