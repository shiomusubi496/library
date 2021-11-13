---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/static_range_sum-DisjointSparseTable.test.cpp
    title: test/yosupo/static_range_sum-DisjointSparseTable.test.cpp
  - icon: ':x:'
    path: test/yosupo/staticrmq-DisjointSparseTable.test.cpp
    title: test/yosupo/staticrmq-DisjointSparseTable.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: docs/DisjointSparseTable.md
    document_title: DisjointSparseTable
    links: []
  bundledCode: "#line 2 \"segment/DisjointSparseTable.hpp\"\n\n#line 2 \"template.hpp\"\
    \n\n#include<bits/stdc++.h>\n\n#ifndef __COUNTER__\n#define __COUNTER__ __LINE__\n\
    #endif\n\n#define REP_SELECTER(a, b, c, d, e, ...) e\n#define REP1_0(b, c) REP1_1(b,\
    \ c)\n#define REP1_1(b, c) for (ll REP_COUNTER_ ## c = 0; REP_COUNTER_ ## c <\
    \ (ll)(b); ++ REP_COUNTER_ ## c)\n#define REP1(b) REP1_0(b, __COUNTER__)\n#define\
    \ REP2(i, b) for (ll i = 0; i < (ll)(b); ++i)\n#define REP3(i, a, b) for (ll i\
    \ = (ll)(a); i < (ll)(b); ++i)\n#define REP4(i, a, b, c) for (ll i = (ll)(a);\
    \ i < (ll)(b); i += (ll)(c))\n#define rep(...) REP_SELECTER(__VA_ARGS__, REP4,\
    \ REP3, REP2, REP1) (__VA_ARGS__)\n#define RREP2(i, a) for (ll i = (ll)(a) - 1;\
    \ i >= 0; --i)\n#define RREP3(i, a, b) for (ll i = (ll)(a) - 1; i >= (ll)(b);\
    \ --i)\n#define RREP4(i, a, b, c) for (ll i = (ll)(a) - 1; i >= (ll)(b); i -=\
    \ (ll)(c))\n#define rrep(...) REP_SELECTER(__VA_ARGS__, RREP4, RREP3, RREP2) (__VA_ARGS__)\n\
    #define REPS2(i, b) for (ll i = 1; i <= (ll)(b); ++i)\n#define REPS3(i, a, b)\
    \ for (ll i = (ll)(a) + 1; i <= (ll)(b); ++i)\n#define REPS4(i, a, b, c) for (ll\
    \ i = (ll)(a) + 1; i <= (ll)(b); i += (ll)(c))\n#define reps(...) REP_SELECTER(__VA_ARGS__,\
    \ REPS4, REPS3, REPS2) (__VA_ARGS__)\n#define RREPS2(i, a) for (ll i = (ll)(a);\
    \ i > 0; --i)\n#define RREPS3(i, a, b) for (ll i = (ll)(a); i > (ll)(b); --i)\n\
    #define RREPS4(i, a, b, c) for (ll i = (ll)(a); i > (ll)(b); i -= (ll)(c))\n#define\
    \ rreps(...) REP_SELECTER(__VA_ARGS__, RREPS4, RREPS3, RREPS2) (__VA_ARGS__)\n\
    \n#define all(v) (v).begin(), (v).end()\n\nusing ll = long long;\nusing ull =\
    \ unsigned long long;\nusing ld = long double;\nusing PLL = std::pair<ll, ll>;\n\
    template<class T> using prique = std::priority_queue<T, std::vector<T>, std::greater<T>>;\n\
    \ntemplate<class T> constexpr T INF = std::numeric_limits<T>::max() / 2;\nconstexpr\
    \ ll inf = INF<ll>;\nconstexpr ld EPS = 1e-8;\nconstexpr ld PI = 3.1415926535897932384626;\n\
    \ntemplate<class T, class U> std::ostream& operator<<(std::ostream& ost, const\
    \ std::pair<T, U>& p) {\n    return ost << p.first << ' ' << p.second;\n}\ntemplate<class\
    \ T, class U> std::istream& operator<<(std::istream& ist, std::pair<T, U>& p)\
    \ {\n    return ist >> p.first >> p.second;\n}\n\ntemplate<class Container,\n\
    \        std::enable_if_t<!std::is_same<Container, std::string>::value>* = nullptr>\n\
    auto operator<<(std::ostream& ost, const Container& cont)\n        -> decltype(cont.begin(),\
    \ cont.end(), ost)\n{\n    for (auto itr = cont.begin(); itr != cont.end(); ++itr)\
    \ {\n        if (itr != cont.begin()) ost << ' ';\n        ost << *itr;\n    }\n\
    \    return ost;\n}\ntemplate<class Container,\n        std::enable_if_t<!std::is_same<Container,\
    \ std::string>::value>* = nullptr>\nauto operator>>(std::istream& ist, Container&\
    \ cont)\n        -> decltype(cont.begin(), cont.end(), ist)\n{\n    for (auto\
    \ itr = cont.begin(); itr != cont.end(); ++itr) ist >> *itr;\n    return ist;\n\
    }\n\ntemplate<class T, class U> inline constexpr bool chmin(T &a, const U &b)\
    \ noexcept {\n    if (a > b) {\n        a = b;\n        return true;\n    }\n\
    \    return false;\n}\ntemplate<class T, class U> inline constexpr bool chmax(T\
    \ &a, const U &b) noexcept {\n    if (a < b) {\n        a = b;\n        return\
    \ true;\n    }\n    return false;\n}\n\ninline constexpr ll gcd(ll a, ll b) noexcept\
    \ {\n    while (b) {\n        const ll c = a;\n        a = b;\n        b = c %\
    \ b;\n    }\n    return a;\n}\ninline constexpr ll lcm(ll a, ll b) noexcept {\n\
    \    return a / gcd(a, b) * b;\n}\n\ninline constexpr bool is_prime(ll N) noexcept\
    \ {\n    if (N <= 1) return false;\n    for (ll i = 2; i * i <= N; ++i) {\n  \
    \      if (N % i == 0) return false;\n    }\n    return true;\n}\ninline std::vector<ll>\
    \ prime_factor(ll N) noexcept {\n    std::vector<ll> res;\n    for (ll i = 2;\
    \ i * i <= N; ++i) {\n        while (N % i == 0) {\n            res.push_back(i);\n\
    \            N /= i;\n        }\n    }\n    if (N != 1) res.push_back(N);\n  \
    \  return res;\n}\n\ninline constexpr ll my_pow(ll a, ll b) noexcept {\n    ll\
    \ res = 1;\n    while (b) {\n        if (b & 1) res *= a;\n        b >>= 1;\n\
    \        a *= a;\n    }\n    return res;\n}\ninline constexpr ll mod_pow(ll a,\
    \ ll b, ll mod) noexcept {\n    a %= mod;\n    ll res = 1;\n    while (b) {\n\
    \        if (b & 1) (res *= a) %= mod;\n        b >>= 1;\n        (a *= a) %=\
    \ mod;\n    }\n    return res;\n}\n\nPLL extGCD(ll a, ll b) noexcept {\n    if\
    \ (b == 0) return PLL{1, 0};\n    PLL p = extGCD(b, a % b);\n    std::swap(p.first,\
    \ p.second);\n    p.second -= p.first * (a / b);\n    if (p.first < 0) {\n   \
    \     p.first += b;\n        p.second -= a;\n    }\n    return p;\n}\nll mod_inv(ll\
    \ a, ll mod) noexcept {\n    const PLL p = extGCD(a, mod);\n    assert(p.first\
    \ * a + p.second * mod == 1);\n    return p.first;\n}\nPLL ChineseRemainder(ll\
    \ b1, ll m1, ll b2, ll m2) noexcept {\n    const PLL p = extGCD(m1, m2);\n   \
    \ const ll g = p.first * m1 + p.second * m2;\n    const ll l = m1 / g * m2;\n\
    \    if((b2 - b1) % g != 0) return PLL{-1, -1};\n    const ll x = (b2 - b1) /\
    \ g * p.first % (m2 / g);\n    return {(x * m1 + b1 + l) % l, l};\n}\nPLL ChineseRemainders(const\
    \ std::vector<ll>& b, const std::vector<ll>& m) noexcept {\n    PLL res{0, 1};\n\
    \    rep (i, b.size()) {\n        res = ChineseRemainder(res.first, res.second,\
    \ b[i], m[i]);\n        if (res.first == -1) return res;\n    }\n    return res;\n\
    }\n\ntemplate<class F> class rec_lambda {\n  private:\n    F f;\n  public:\n \
    \   explicit constexpr rec_lambda(F&& f_) : f(std::forward<F>(f_)) {}\n    template<class...\
    \ Args> constexpr auto operator()(Args&&... args) const {\n        return f(*this,\
    \ std::forward<Args>(args)...);\n    }\n};\n\ntemplate<class T, class Arg> constexpr\
    \ std::vector<T> make_vec(int n, Arg&& arg) {\n    return std::vector<T>(n, arg);\n\
    }\ntemplate<class T, class... Args> constexpr auto make_vec(int n, Args&&... args)\
    \ {\n    return std::vector<decltype(make_vec<T>(args...))>\n               (n,\
    \ make_vec<T>(std::forward<Args>(args)...));\n}\n\ninline constexpr int popcnt(ull\
    \ x) {\n#if __cplusplus >= 202002L\n    return std::popcount(x);\n#endif\n   \
    \ x = (x & 0x5555555555555555) + ((x >> 1 ) & 0x5555555555555555);\n    x = (x\
    \ & 0x3333333333333333) + ((x >> 2 ) & 0x3333333333333333);\n    x = (x & 0x0f0f0f0f0f0f0f0f)\
    \ + ((x >> 4 ) & 0x0f0f0f0f0f0f0f0f);\n    x = (x & 0x00ff00ff00ff00ff) + ((x\
    \ >> 8 ) & 0x00ff00ff00ff00ff);\n    x = (x & 0x0000ffff0000ffff) + ((x >> 16)\
    \ & 0x0000ffff0000ffff);\n    return (x & 0x00000000ffffffff) + ((x >> 32) & 0x00000000ffffffff);\n\
    }\n\ntemplate<class T> class presser : public std::vector<T> {\n  private:\n \
    \   using Base = std::vector<T>;\n  public:\n    using Base::Base;\n    presser(const\
    \ std::vector<T>& vec) : Base(vec) {}\n    void push(const std::vector<T>& vec)\
    \ {\n        int n = this->size();\n        this->resize(n + vec.size());\n  \
    \      std::copy(vec.begin(), vec.end(), this->begin() + n);\n    }\n    int build()\
    \ {\n        std::sort(this->begin(), this->end());\n        this->erase(std::unique(this->begin(),\
    \ this->end()), this->end());\n        return this->size();\n    }\n    int get_index(const\
    \ T& val) const {\n        return static_cast<int>(std::lower_bound(this->begin(),\
    \ this->end(), val) - this->begin());\n    }\n    std::vector<int> pressed(const\
    \ std::vector<T>& vec) const {\n        std::vector<int> res(vec.size());\n  \
    \      rep (i, vec.size()) res[i] = this->get_index(vec[i]);\n        return res;\n\
    \    }\n    void press(std::vector<T>& vec) const {\n        static_assert(std::is_integral<T>::value,\
    \ \"cannot convert from int type\");\n        rep (i, vec.size()) vec[i] = this->get_index(vec[i]);\n\
    \    }\n};\n#line 4 \"segment/DisjointSparseTable.hpp\"\n\ntemplate<class T> class\
    \ DisjointSparseTable {\n  protected:\n    using F = std::function<T(T, T)>;\n\
    \    int h;\n    F op;\n    std::vector<int> logtable;\n    std::vector<std::vector<T>>\
    \ data;\n  public:\n    DisjointSparseTable() = default;\n    DisjointSparseTable(const\
    \ std::vector<T>& v, const F& op) : op(op) {\n        h = 1;\n        while ((1\
    \ << h) < (int)v.size()) ++h;\n        logtable.resize(1 << h, 0);\n        rep\
    \ (i, 2, 1 << h) logtable[i] = logtable[i >> 1] + 1;\n        data.resize(h, std::vector<T>(1\
    \ << h));\n        rep (i, v.size()) data[0][i] = v[i];\n        rep (i, 1, h)\
    \ {\n            int len = 1 << i;\n            rep (j, len, v.size(), len <<\
    \ 1) {\n                data[i][j - 1] = v[j - 1];\n                rep (k, 1,\
    \ len) data[i][j - k - 1] = op(v[j - k - 1], data[i][j - k]);\n              \
    \  data[i][j] = v[j];\n                rep (k, 1, len) {\n                   \
    \ if (j + k >= v.size()) break;\n                    data[i][j + k] = op(data[i][j\
    \ + k - 1], v[j + k]);\n                }\n            }\n        }\n    }\n \
    \   T query(int l, int r) {\n        assert(0 <= l && l < r && r <= (1 << h));\n\
    \        --r;\n        if (l == r) return data[0][l];\n        int d = logtable[l\
    \ ^ r];\n        return op(data[d][l], data[d][r]);\n    }\n};\n\n/**\n * @brief\
    \ DisjointSparseTable\n * @docs docs/DisjointSparseTable.md\n */\n"
  code: "#pragma once\n\n#include \"../template.hpp\"\n\ntemplate<class T> class DisjointSparseTable\
    \ {\n  protected:\n    using F = std::function<T(T, T)>;\n    int h;\n    F op;\n\
    \    std::vector<int> logtable;\n    std::vector<std::vector<T>> data;\n  public:\n\
    \    DisjointSparseTable() = default;\n    DisjointSparseTable(const std::vector<T>&\
    \ v, const F& op) : op(op) {\n        h = 1;\n        while ((1 << h) < (int)v.size())\
    \ ++h;\n        logtable.resize(1 << h, 0);\n        rep (i, 2, 1 << h) logtable[i]\
    \ = logtable[i >> 1] + 1;\n        data.resize(h, std::vector<T>(1 << h));\n \
    \       rep (i, v.size()) data[0][i] = v[i];\n        rep (i, 1, h) {\n      \
    \      int len = 1 << i;\n            rep (j, len, v.size(), len << 1) {\n   \
    \             data[i][j - 1] = v[j - 1];\n                rep (k, 1, len) data[i][j\
    \ - k - 1] = op(v[j - k - 1], data[i][j - k]);\n                data[i][j] = v[j];\n\
    \                rep (k, 1, len) {\n                    if (j + k >= v.size())\
    \ break;\n                    data[i][j + k] = op(data[i][j + k - 1], v[j + k]);\n\
    \                }\n            }\n        }\n    }\n    T query(int l, int r)\
    \ {\n        assert(0 <= l && l < r && r <= (1 << h));\n        --r;\n       \
    \ if (l == r) return data[0][l];\n        int d = logtable[l ^ r];\n        return\
    \ op(data[d][l], data[d][r]);\n    }\n};\n\n/**\n * @brief DisjointSparseTable\n\
    \ * @docs docs/DisjointSparseTable.md\n */\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: segment/DisjointSparseTable.hpp
  requiredBy: []
  timestamp: '2021-11-13 20:58:10+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/static_range_sum-DisjointSparseTable.test.cpp
  - test/yosupo/staticrmq-DisjointSparseTable.test.cpp
documentation_of: segment/DisjointSparseTable.hpp
layout: document
redirect_from:
- /library/segment/DisjointSparseTable.hpp
- /library/segment/DisjointSparseTable.hpp.html
title: DisjointSparseTable
---
## 概要

区間最小値などの区間に対するクエリを扱える。ただし、二項演算子 $\cdot$ は以下の条件を満たす必要がある。

- 結合則 : 任意の $A, B, C$ に対して $(A \cdot B) \cdot C = A \cdot (B \cdot C)$

`SparseTable` より制約が弱く、足し算など多くの演算が使える。

以下の計算量は `op` が定数時間で動くと仮定したもの。 `op` 内部の計算量が $O(f(n))$ の時、以下の計算量は全て $O(f(n))$ 倍になる。

- `DisjointSparseTable(vector<int> a, T op(T, T))` : リスト `a` と二項演算 `op` で初期化する。 $N=\mathrm{len}(a)$ として $O(N \log N)$ 。
- `T query(int l, int r)` : `op(a[l], a[l+1], ..., a[r-1])` を返す。 $O(1)$ 。
