#pragma once

#include "../../other/template.hpp"
#include "../ModInt.hpp"

CONSTEXPR ull primitive_root_for_convolution(ull p) {
    if (p == 2) return 1;
    if (p == 998244353) return 3;
    if (p == 469762049) return 3;
    if (p == 1811939329) return 11;
    if (p == 2013265921) return 11;
    rep (g, 2, p) {
        if (mod_pow(g, (p - 1) >> 1, p) != 1) return g;
    }
    return -1;
}

namespace internal {

template<unsigned int p> class NthRoot {
private:
    static constexpr unsigned int lg = bitop::msb((p - 1) & (1 - p));
    unsigned int root[lg + 1];
    unsigned int inv_root[lg + 1];
    unsigned int rate[lg + 1];
    unsigned int inv_rate[lg + 1];

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

template<class T> void number_theoretic_transform(std::vector<T>& a) {
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
            if (j != (1 << (lg - i - 1)) - 1) {
                z *= nth_root<T::get_mod()>.get_rate(popcnt(j & ~(j + 1)));
            }
        }
    }
}
template<class T> void inverse_number_theoretic_transform(std::vector<T>& a) {
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
            if (j != (1 << (lg - i - 1)) - 1) {
                z *= nth_root<T::get_mod()>.get_inv_rate(popcnt(j & ~(j + 1)));
            }
        }
    }
    T inv_n = T(1) / n;
    each_for (x : a) x *= inv_n;
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

template<class T> std::vector<T> convolution_pow2(std::vector<T> a) {
    int n = a.size() * 2 - 1;
    int lg = bitop::msb(n - 1) + 1;
    if (n - (1 << (lg - 1)) <= 5) {
        --lg;
        int m = a.size() - (1 << (lg - 1));
        std::vector<T> a1(a.begin(), a.begin() + m), a2(a.begin() + m, a.end());
        std::vector<T> c(n);
        std::vector<T> c1 = convolution_naive(a1, a1);
        std::vector<T> c2 = convolution_naive(a1, a2);
        std::vector<T> c3 = convolution_pow2(a2);
        rep (i, c1.size()) c[i] += c1[i];
        rep (i, c2.size()) c[i + m] += c2[i] * 2;
        rep (i, c3.size()) c[i + m * 2] += c3[i];
        return c;
    }
    int m = 1 << lg;
    a.resize(m);
    number_theoretic_transform(a);
    rep (i, m) a[i] *= a[i];
    inverse_number_theoretic_transform(a);
    a.resize(n);
    return a;
}

template<class T>
std::vector<T> convolution(std::vector<T> a, std::vector<T> b) {
    int n = a.size() + b.size() - 1;
    int lg = bitop::ceil_log2(n);
    int m = 1 << lg;
    if (n - (1 << (lg - 1)) <= 5) {
        --lg;
        if (a.size() < b.size()) std::swap(a, b);
        int m = n - (1 << lg);
        std::vector<T> a1(a.begin(), a.begin() + m), a2(a.begin() + m, a.end());
        std::vector<T> c(n);
        std::vector<T> c1 = convolution_naive(a1, b);
        std::vector<T> c2 = convolution(a2, b);
        rep (i, c1.size()) c[i] += c1[i];
        rep (i, c2.size()) c[i + m] += c2[i];
        return c;
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

} // namespace internal

using internal::inverse_number_theoretic_transform;
using internal::number_theoretic_transform;

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
    if (n == m && a == b) return internal::convolution_pow2(a);
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
    static constexpr ll MOD1 = 469762049;
    static constexpr ll MOD2 = 1811939329;
    static constexpr ll MOD3 = 2013265921;
    static constexpr ll INV1_2 = mod_pow(MOD1, MOD2 - 2, MOD2);
    static constexpr ll INV1_3 = mod_pow(MOD1, MOD3 - 2, MOD3);
    static constexpr ll INV2_3 = mod_pow(MOD2, MOD3 - 2, MOD3);
    auto c1 = convolution<MOD1>(a2, b2);
    auto c2 = convolution<MOD2>(a2, b2);
    auto c3 = convolution<MOD3>(a2, b2);
    std::vector<static_modint<p>> res(n + m - 1);
    rep (i, n + m - 1) {
        ll t1 = c1[i];
        ll t2 = (c2[i] - t1 + MOD2) * INV1_2 % MOD2;
        if (t2 < 0) t2 += MOD2;
        ll t3 =
            ((c3[i] - t1 + MOD3) * INV1_3 % MOD3 - t2 + MOD3) * INV2_3 % MOD3;
        if (t3 < 0) t3 += MOD3;
        res[i] = static_modint<p>(t1 + (t2 + t3 * MOD2) % p * MOD1);
    }
    return res;
}

template<class T> void ntt_doubling_(std::vector<T>& a) {
    int n = a.size();
    auto b = a;
    inverse_number_theoretic_transform(b);
    const T z = internal::nth_root<T::get_mod()>.get(bitop::msb(n) + 1);
    T r = 1;
    rep (i, n) {
        b[i] *= r;
        r *= z;
    }
    number_theoretic_transform(b);
    std::copy(all(b), std::back_inserter(a));
}

template<unsigned int p> struct is_ntt_friendly : std::false_type {};

template<> struct is_ntt_friendly<998244353> : std::true_type {};

/**
 * @brief Convolution(畳み込み)
 * @docs docs/math/convolution/Convolution.md
 */
