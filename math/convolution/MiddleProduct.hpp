#pragma once

#include "../../other/template.hpp"
#include "../ModInt.hpp"
#include "Convolution.hpp"

template<class T, typename std::enable_if<
                      is_ntt_friendly_modint<T>::value>::type* = nullptr>
std::vector<T> middle_product(std::vector<T> a, std::vector<T> b) {
    int n = a.size(), m = b.size();
    assert(n >= m);
    std::reverse(all(b));
    int N = 1 << bitop::ceil_log2(n);
    a.resize(N);
    b.resize(N);
    number_theoretic_transform(a);
    number_theoretic_transform(b);
    rep (i, N) a[i] *= b[i];
    inverse_number_theoretic_transform(a);
    std::vector<T> res(a.begin() + (m - 1), a.begin() + n);
    return res;
}

template<class T, typename std::enable_if<
                      !is_ntt_friendly_modint<T>::value>::type* = nullptr>
std::vector<T> middle_product(std::vector<T> a, std::vector<T> b) {
    int n = a.size(), m = b.size();
    static constexpr ll MOD1 = 469762049;
    static constexpr ll MOD2 = 1811939329;
    static constexpr ll MOD3 = 2013265921;
    static constexpr ll INV1_2 = mod_pow(MOD1, MOD2 - 2, MOD2);
    static constexpr ll INV1_3 = mod_pow(MOD1, MOD3 - 2, MOD3);
    static constexpr ll INV2_3 = mod_pow(MOD2, MOD3 - 2, MOD3);
    using mint1 = static_modint<MOD1>;
    using mint2 = static_modint<MOD1>;
    using mint3 = static_modint<MOD1>;
    std::vector<mint1> a1(n), b1(n);
    std::vector<mint2> a2(n), b2(n);
    std::vector<mint3> a3(n), b3(n);
    rep (i, n) {
        a1[i] = a[i].get(); b1[i] = b[i].get();
        a2[i] = a[i].get(); b2[i] = b[i].get();
        a3[i] = a[i].get(); b3[i] = b[i].get();
    }
    auto c1 = middle_product(a1, b1);
    auto c2 = middle_product(a2, b2);
    auto c3 = middle_product(a3, b3);
    std::vector<T> res(n - m + 1);
    rep (i, n - m + 1) {
        ll t1 = (ll)c1[i].get();
        ll t2 = ((ll)c2[i].get() - t1 + MOD2) * INV1_2 % MOD2;
        if (t2 < 0) t2 += MOD2;
        ll t3 =
            (((ll)c3[i].get() - t1 + MOD3) * INV1_3 % MOD3 - t2 + MOD3) * INV2_3 % MOD3;
        if (t3 < 0) t3 += MOD3;
        res[i] = t1 + (t2 + t3 * MOD2) * MOD1;
    }
    return res;
}
