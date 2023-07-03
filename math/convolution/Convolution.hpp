#pragma once

#include "../../other/template.hpp"
#include "../ModInt.hpp"
#include "../PrimitiveRoot.hpp"

namespace internal {

template<unsigned int p> class NthRoot {
private:
    static constexpr unsigned int lg = bitop::msb((p - 1) & (1 - p));
    unsigned int root[lg + 1];
    unsigned int inv_root[lg + 1];
    unsigned int rate[lg - 1];
    unsigned int inv_rate[lg - 1];

public:
    constexpr NthRoot() : root{}, inv_root{}, rate{}, inv_rate{} {
        root[lg] = mod_pow(primitive_root_for_convolution(p), (p - 1) >> lg, p);
        inv_root[lg] = mod_pow(root[lg], p - 2, p);
        rrep (i, lg) {
            root[i] = (ull)root[i + 1] * root[i + 1] % p;
            inv_root[i] = (ull)inv_root[i + 1] * inv_root[i + 1] % p;
        }
        ull r = 1;
        rep (i, 2, lg + 1) {
            rate[i - 2] = r * root[i] % p;
            r = r * inv_root[i] % p;
        }
        r = 1;
        rep (i, 2, lg + 1) {
            inv_rate[i - 2] = r * inv_root[i] % p;
            r = r * root[i] % p;
        }
    }
    static constexpr unsigned int get_lg() { return lg; }
    constexpr unsigned int get(int n) const { return root[n]; }
    constexpr unsigned int inv(int n) const { return inv_root[n]; }
    constexpr unsigned int get_rate(int n) const { return rate[n]; }
    constexpr unsigned int get_inv_rate(int n) const { return inv_rate[n]; }
};

template<unsigned int p> constexpr NthRoot<p> nth_root;

template<class T>
void number_theoretic_transform(std::vector<T>& a) {
    int n = a.size();
    int lg = bitop::msb(n - 1) + 1;
    rrep (i, lg) {
        T z = T(1);
        rep (j, 1 << (lg - i - 1)) {
            int offset = j << (i + 1);
            rep (k, 1 << i) {
                T x = a[offset + k];
                T y = a[offset + k + (1 << i)] * z;
                a[offset + k] = x + y;
                a[offset + k + (1 << i)] = x - y;
            }
            z *= nth_root<T::get_mod()>.get_rate(popcnt(j & ~(j + 1)));
        }
    }
}
template<class T>
void inverse_number_theoretic_transform(std::vector<T>& a) {
    int n = a.size();
    int lg = bitop::msb(n - 1) + 1;
    rep (i, lg) {
        T z = T(1);
        rep (j, 1 << (lg - i - 1)) {
            int offset = j << (i + 1);
            rep (k, 1 << i) {
                T x = a[offset + k];
                T y = a[offset + k + (1 << i)];
                a[offset + k] = x + y;
                a[offset + k + (1 << i)] = (x - y) * z;
            }
            z *= nth_root<T::get_mod()>.get_inv_rate(popcnt(j & ~(j + 1)));
        }
    }
    T inv_n = T(1) / n;
    each_for (x : a) x *= inv_n;
}

template<class T>
std::vector<T> convolution(std::vector<T> a, std::vector<T> b) {
    int n = a.size() + b.size() - 1;
    int lg = bitop::msb(n - 1) + 1;
    int m = 1 << lg;
    if (a.size() == b.size() && a == b) {
        a.resize(m);
        number_theoretic_transform(a);
        rep (i, m) a[i] *= a[i];
        inverse_number_theoretic_transform(a);
        a.resize(n);
        return a;
    }
    a.resize(m);
    b.resize(m);
    number_theoretic_transform(a);
    number_theoretic_transform(b);
    rep (i, m) a[i] *= b[i];
    inverse_number_theoretic_transform(a);
    a.resize(n);
    return a;
}


template<class T>
std::vector<T> convolution_naive(const std::vector<T>& a,
                                 const std::vector<T>& b) {
    int n = a.size(), m = b.size();
    std::vector<T> c(n + m - 1);
    rep (i, n)
        rep (j, m) c[i + j] += a[i] * b[j];
    return c;
}

} // namespace internal

using internal::number_theoretic_transform;
using internal::inverse_number_theoretic_transform;

template<unsigned int p>
std::vector<static_modint<p>>
convolution_for_any_mod(const std::vector<static_modint<p>>& a,
                        const std::vector<static_modint<p>>& b);

template<unsigned int p>
std::vector<static_modint<p>>
convolution(const std::vector<static_modint<p>>& a,
            const std::vector<static_modint<p>>& b) {
    unsigned int n = a.size(), m = b.size();
    if (n == 0 || m == 0) return {};
    if (n <= 60 || m <= 60) return internal::convolution_naive(a, b);
    if (n + m - 1 > ((1 - p) & (p - 1))) return convolution_for_any_mod(a, b);
    return internal::convolution(a, b);
}

template<unsigned int p>
std::vector<ll> convolution(const std::vector<ll>& a,
                            const std::vector<ll>& b) {
    int n = a.size(), m = b.size();
    std::vector<static_modint<p>> a2(n), b2(m);
    rep (i, n) a2[i] = a[i];
    rep (i, m) b2[i] = b[i];
    auto c2 = convolution(a2, b2);
    std::vector<ll> c(n + m - 1);
    rep (i, n + m - 1) c[i] = c2[i].get();
    return c;
}

template<unsigned int p>
std::vector<static_modint<p>>
convolution_for_any_mod(const std::vector<static_modint<p>>& a,
                        const std::vector<static_modint<p>>& b) {
    int n = a.size(), m = b.size();
    assert(n + m - 1 <= (1 << 26));
    std::vector<ll> a2(n), b2(m);
    rep (i, n) a2[i] = a[i].get();
    rep (i, m) b2[i] = b[i].get();
    static constexpr ull MOD1 = 469762049;
    static constexpr ull MOD2 = 1811939329;
    static constexpr ull MOD3 = 2013265921;
    static constexpr ull INV1_2 = mod_pow(MOD1, MOD2 - 2, MOD2);
    static constexpr ull INV1_3 = mod_pow(MOD1, MOD3 - 2, MOD3);
    static constexpr ull INV2_3 = mod_pow(MOD2, MOD3 - 2, MOD3);
    auto c1 = convolution<MOD1>(a2, b2);
    auto c2 = convolution<MOD2>(a2, b2);
    auto c3 = convolution<MOD3>(a2, b2);
    std::vector<static_modint<p>> res(n + m - 1);
    rep (i, n + m - 1) {
        ull t1 = c1[i];
        ull t2 = (c2[i] - t1 + MOD2) * INV1_2 % MOD2;
        if (t2 < 0) t2 += MOD2;
        ull t3 =
            ((c3[i] - t1 + MOD3) * INV1_3 % MOD3 - t2 + MOD3) * INV2_3 % MOD3;
        if (t3 < 0) t3 += MOD3;
        assert(0 <= t1 && t1 < MOD1);
        assert(0 <= t2 && t2 < MOD2);
        assert(0 <= t3 && t3 < MOD3);
        res[i] = static_modint<p>(t1 + (t2 + t3 * MOD2) % p * MOD1);
    }
    return res;
}

/**
 * @brief Convolution(畳み込み)
 * @docs docs/math/convolution.md
 */
