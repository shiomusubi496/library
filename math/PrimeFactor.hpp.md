---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_1_C-PrimeEra.test.cpp
    title: test/aoj/ALDS1_1_C-PrimeEra.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/PrimeFactor.md
    document_title: "PrimeFactor(\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\
      )"
    links: []
  bundledCode: "#line 2 \"math/PrimeFactor.hpp\"\n\n#line 2 \"template.hpp\"\n\n#include<bits/stdc++.h>\n\
    \n#define rep(i, n) for (int i = 0; i < (int)(n); ++i)\n#define rrep(i, n) for\
    \ (int i = (int)(n) - 1; i >= 0; --i)\n#define all(v) (v).begin(), (v).end()\n\
    \nusing ll = long long;\nusing ull = unsigned long long;\nusing ld = long double;\n\
    using PLL = std::pair<ll, ll>;\ntemplate<class T> using prique = std::priority_queue<T,\
    \ std::vector<T>, std::greater<T>>;\n\ntemplate<class T> constexpr T INF = std::numeric_limits<T>::max()\
    \ / 2;\nconstexpr ll inf = INF<ll>;\nconstexpr ld EPS = 1e-8;\nconstexpr ld PI\
    \ = 3.1415926535897932384626;\n\ntemplate<class T, class U> inline constexpr bool\
    \ chmin(T &a, const U &b) noexcept {\n    if (a > b) {\n        a = b;\n     \
    \   return true;\n    }\n    return false;\n}\ntemplate<class T, class U> inline\
    \ constexpr bool chmax(T &a, const U &b) noexcept {\n    if (a < b) {\n      \
    \  a = b;\n        return true;\n    }\n    return false;\n}\n\ninline constexpr\
    \ ll gcd(ll a, ll b) noexcept {\n    while (b) {\n        const ll c = a;\n  \
    \      a = b;\n        b = c % b;\n    }\n    return a;\n}\ninline constexpr ll\
    \ lcm(ll a, ll b) noexcept {\n    return a / gcd(a, b) * b;\n}\n\ninline constexpr\
    \ bool is_prime(ll N) noexcept {\n    if (N <= 1) return false;\n    for (ll i\
    \ = 2; i * i <= N; ++i) {\n        if (N % i == 0) return false;\n    }\n    return\
    \ true;\n}\ninline std::vector<ll> prime_factor(ll N) noexcept {\n    std::vector<ll>\
    \ res;\n    for (ll i = 2; i * i <= N; ++i) {\n        while (N % i == 0) {\n\
    \            res.push_back(i);\n            N /= i;\n        }\n    }\n    if\
    \ (N != 1) res.push_back(N);\n    return res;\n}\n\ninline constexpr ll my_pow(ll\
    \ a, ll b) noexcept {\n    ll res = 1;\n    while (b) {\n        if (b & 1) res\
    \ *= a;\n        b >>= 1;\n        a *= a;\n    }\n    return res;\n}\ninline\
    \ constexpr ll mod_pow(ll a, ll b, ll mod) noexcept {\n    a %= mod;\n    ll res\
    \ = 1;\n    while (b) {\n        if (b & 1) (res *= a) %= mod;\n        b >>=\
    \ 1;\n        (a *= a) %= mod;\n    }\n    return res;\n}\n\ntemplate<class F>\
    \ class rec_lambda {\n  private:\n    F f;\n  public:\n    explicit constexpr\
    \ rec_lambda(F&& f_) : f(std::forward<F>(f_)) {}\n    template<class... Args>\
    \ constexpr auto operator()(Args&&... args) const {\n        return f(*this, std::forward<Args>(args)...);\n\
    \    }\n};\n\ntemplate<class T, class Arg> constexpr std::vector<T> make_vec(int\
    \ n, Arg&& arg) {\n    return std::vector<T>(n, arg);\n}\ntemplate<class T, class...\
    \ Args> constexpr auto make_vec(int n, Args&&... args) {\n    return std::vector<decltype(make_vec<T>(args...))>\n\
    \               (n, make_vec<T>(std::forward<Args>(args)...));\n}\n\ninline constexpr\
    \ int popcnt(ull x) {\n#if __cplusplus >= 202002L\n    return std::popcount(x);\n\
    #endif\n    x = (x & 0x5555555555555555) + ((x >> 1 ) & 0x5555555555555555);\n\
    \    x = (x & 0x3333333333333333) + ((x >> 2 ) & 0x3333333333333333);\n    x =\
    \ (x & 0x0f0f0f0f0f0f0f0f) + ((x >> 4 ) & 0x0f0f0f0f0f0f0f0f);\n    x = (x & 0x00ff00ff00ff00ff)\
    \ + ((x >> 8 ) & 0x00ff00ff00ff00ff);\n    x = (x & 0x0000ffff0000ffff) + ((x\
    \ >> 16) & 0x0000ffff0000ffff);\n    return (x & 0x00000000ffffffff) + ((x >>\
    \ 32) & 0x00000000ffffffff);\n}\n\ntemplate<class T> class presser : public std::vector<T>\
    \ {\n  private:\n    using Base = std::vector<T>;\n  public:\n    using Base::Base;\n\
    \    presser(const std::vector<T>& vec) : Base(vec) {}\n    void push(const std::vector<T>&\
    \ vec) {\n        int n = this->size();\n        this->resize(n + vec.size());\n\
    \        std::copy(vec.begin(), vec.end(), this->begin() + n);\n    }\n    int\
    \ build() {\n        std::sort(this->begin(), this->end());\n        this->erase(std::unique(this->begin(),\
    \ this->end()), this->end());\n        return this->size();\n    }\n    int get_index(const\
    \ T& val) const {\n        return static_cast<int>(std::lower_bound(this->begin(),\
    \ this->end(), val) - this->begin());\n    }\n    std::vector<int> pressed(const\
    \ std::vector<T>& vec) const {\n        std::vector<int> res(vec.size());\n  \
    \      rep (i, vec.size()) res[i] = this->get_index(vec[i]);\n        return res;\n\
    \    }\n    void press(std::vector<T>& vec) const {\n        static_assert(std::is_integral<T>::value);\n\
    \        rep (i, vec.size()) vec[i] = this->get_index(vec[i]);\n    }\n};\n#line\
    \ 4 \"math/PrimeFactor.hpp\"\n\nclass PrimeFactor {\n  protected:\n    ll MAX;\n\
    \    std::vector<ll> era;\n  public:\n    PrimeFactor(ll _MAX) : MAX(_MAX), era(MAX\
    \ + 1, -1) {\n        for (ll i = 2; i <= MAX; ++i) {\n            if (era[i]\
    \ != -1) continue;\n            for (ll j = i; j <= MAX; j += i) era[j] = i;\n\
    \        }\n    }\n    bool is_prime(ll x) { return era[x] == x; }\n    std::vector<ll>\
    \ factorize(ll x) {\n        std::vector<ll> res;\n        for (; x > 1; x /=\
    \ era[x]) res.push_back(x);\n        reverse(res.begin(), res.end());\n      \
    \  return res;\n    }\n};\n\nclass IsPrime {\n  protected:\n    ll MAX;\n    std::vector<bool>\
    \ era;\n  public:\n    IsPrime(ll _MAX) : MAX(_MAX), era(MAX + 1, true) {\n  \
    \      era[0] = era[1] = false;\n        for (ll i = 2; i <= MAX; ++i) {\n   \
    \         if (!era[i]) continue;\n            for (ll j = i * 2; j <= MAX; j +=\
    \ i) era[j] = false;\n        }\n    }\n    bool is_prime(ll x) { return era[x];\
    \ }\n};\n\n/**\n * @brief PrimeFactor(\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\
    \u306E\u7BE9)\n * @docs docs/PrimeFactor.md\n */\n"
  code: "#pragma once\n\n#include \"../template.hpp\"\n\nclass PrimeFactor {\n  protected:\n\
    \    ll MAX;\n    std::vector<ll> era;\n  public:\n    PrimeFactor(ll _MAX) :\
    \ MAX(_MAX), era(MAX + 1, -1) {\n        for (ll i = 2; i <= MAX; ++i) {\n   \
    \         if (era[i] != -1) continue;\n            for (ll j = i; j <= MAX; j\
    \ += i) era[j] = i;\n        }\n    }\n    bool is_prime(ll x) { return era[x]\
    \ == x; }\n    std::vector<ll> factorize(ll x) {\n        std::vector<ll> res;\n\
    \        for (; x > 1; x /= era[x]) res.push_back(x);\n        reverse(res.begin(),\
    \ res.end());\n        return res;\n    }\n};\n\nclass IsPrime {\n  protected:\n\
    \    ll MAX;\n    std::vector<bool> era;\n  public:\n    IsPrime(ll _MAX) : MAX(_MAX),\
    \ era(MAX + 1, true) {\n        era[0] = era[1] = false;\n        for (ll i =\
    \ 2; i <= MAX; ++i) {\n            if (!era[i]) continue;\n            for (ll\
    \ j = i * 2; j <= MAX; j += i) era[j] = false;\n        }\n    }\n    bool is_prime(ll\
    \ x) { return era[x]; }\n};\n\n/**\n * @brief PrimeFactor(\u30A8\u30E9\u30C8\u30B9\
    \u30C6\u30CD\u30B9\u306E\u7BE9)\n * @docs docs/PrimeFactor.md\n */\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: math/PrimeFactor.hpp
  requiredBy: []
  timestamp: '2021-11-04 22:17:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_1_C-PrimeEra.test.cpp
documentation_of: math/PrimeFactor.hpp
layout: document
redirect_from:
- /library/math/PrimeFactor.hpp
- /library/math/PrimeFactor.hpp.html
title: "PrimeFactor(\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9)"
---
## 概要

エラトステネスの篩を使った $O(\log N)$ の素因数分解。ただし、前処理は $O(N\log\log N)$ 。

- `PrimeFactor(ll N)` : `N` 以下の値に対してエラトステネスの篩のテーブルを作成する。$O(N\log\log N)$。
- `bool is_prime(ll x)` : `x` が素数かどうか判定する。$O(1)$。
- `vector<ll> factor(ll x)` : `x` を素因数分解する。返る値は昇順。$O(\log N)$。

素数判定のみしたい場合は `IsPrime` を使う。計算量は `PrimeFactor` と同様。
