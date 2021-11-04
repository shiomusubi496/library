---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_1_A-UF.test.cpp
    title: test/aoj/DSL_1_A-UF.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/unionfind.test.cpp
    title: test/yosupo/unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/UnionFind.md
    document_title: UnionFind
    links: []
  bundledCode: "#line 2 \"graph/UnionFind.hpp\"\n\n#line 2 \"template.hpp\"\n\n#include<bits/stdc++.h>\n\
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
    \ 4 \"graph/UnionFind.hpp\"\n\nclass UnionFind {\n  protected:\n    int _n;\n\
    \    std::vector<int> par_vec;\n  public:\n    UnionFind() : UnionFind(0) {}\n\
    \    UnionFind(int n) : _n(n), par_vec(n, -1) {}\n    int find(int x) {\n    \
    \    assert(0 <= x && x < _n);\n        return par_vec[x] < 0 ? x : par_vec[x]\
    \ = find(par_vec[x]);\n    }\n    bool merge(int x, int y) {\n        x = find(x);\n\
    \        y = find(y);\n        if (x == y) return false;\n        if (par_vec[x]\
    \ > par_vec[y]) std::swap(x, y);\n        par_vec[x] += par_vec[y];\n        par_vec[y]\
    \ = x;\n        return true;\n    }\n    bool same(int x, int y) {\n        return\
    \ find(x) == find(y);\n    }\n    int size(int x) {\n        return -par_vec[find(x)];\n\
    \    }\n    std::vector<std::vector<int>> groups() {\n        std::vector<std::vector<int>>\
    \ res(_n);\n        rep(i, _n) res[find(i)].push_back(i);\n        res.erase(\n\
    \            remove_if(res.begin(), res.end(),\n                      [](const\
    \ std::vector<int>& v) { return v.empty(); }),\n            res.end());\n    \
    \    return res;\n    }\n    bool is_root(int x) const {\n        assert(0 <=\
    \ x && x < _n);\n        return par_vec[x] < 0;\n    }\n};\n\n/**\n * @brief UnionFind\n\
    \ * @docs docs/UnionFind.md\n */\n"
  code: "#pragma once\n\n#include \"../template.hpp\"\n\nclass UnionFind {\n  protected:\n\
    \    int _n;\n    std::vector<int> par_vec;\n  public:\n    UnionFind() : UnionFind(0)\
    \ {}\n    UnionFind(int n) : _n(n), par_vec(n, -1) {}\n    int find(int x) {\n\
    \        assert(0 <= x && x < _n);\n        return par_vec[x] < 0 ? x : par_vec[x]\
    \ = find(par_vec[x]);\n    }\n    bool merge(int x, int y) {\n        x = find(x);\n\
    \        y = find(y);\n        if (x == y) return false;\n        if (par_vec[x]\
    \ > par_vec[y]) std::swap(x, y);\n        par_vec[x] += par_vec[y];\n        par_vec[y]\
    \ = x;\n        return true;\n    }\n    bool same(int x, int y) {\n        return\
    \ find(x) == find(y);\n    }\n    int size(int x) {\n        return -par_vec[find(x)];\n\
    \    }\n    std::vector<std::vector<int>> groups() {\n        std::vector<std::vector<int>>\
    \ res(_n);\n        rep(i, _n) res[find(i)].push_back(i);\n        res.erase(\n\
    \            remove_if(res.begin(), res.end(),\n                      [](const\
    \ std::vector<int>& v) { return v.empty(); }),\n            res.end());\n    \
    \    return res;\n    }\n    bool is_root(int x) const {\n        assert(0 <=\
    \ x && x < _n);\n        return par_vec[x] < 0;\n    }\n};\n\n/**\n * @brief UnionFind\n\
    \ * @docs docs/UnionFind.md\n */\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: graph/UnionFind.hpp
  requiredBy: []
  timestamp: '2021-11-04 22:17:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_1_A-UF.test.cpp
  - test/yosupo/unionfind.test.cpp
documentation_of: graph/UnionFind.hpp
layout: document
redirect_from:
- /library/graph/UnionFind.hpp
- /library/graph/UnionFind.hpp.html
title: UnionFind
---
## 概要

集合を併合する操作や、ある要素が属する集合の代表元を問い合わせる操作を行える。

- `bool merge(int x, int y)` :  
要素 `x` の属する集合と要素 `y` の属する集合を併合する。もともと同じ集合に属していたなら `false` を、そうでないなら `true` を返す。ならし$O(\alpha(N))$。

- `int find(int x)` :  
要素 `x` の属する集合の代表元を返す。ならし$O(\alpha(N))$。

- `bool same(int x, int y)`  
要素 `x` と要素 `y` が同じ集合に属するかを判定する。ならし$O(\alpha(N))$。

- `int size(int x)`  
要素 `x` の属する集合の要素数を返す。ならし$O(\alpha(N))$。

- `bool is_root(int x)`  
要素 `x` が属する集合の代表元が `x` であるかを返す。$O(1)$。

- `vector<vector<int>> groups()`  
「「集合に属する要素のリスト」のリスト」を返す。ならし$O(N\alpha(N))$。
