---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/persistent_unionfind-Undo.test.cpp
    title: test/yosupo/persistent_unionfind-Undo.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/UnionFindUndo.md
    document_title: "UnionFindUndo(Undo\u53EF\u80FDUnionFind)"
    links: []
  bundledCode: "#line 2 \"data-struct/unionfind/UnionFindUndo.hpp\"\n\n#line 2 \"\
    other/template.hpp\"\n\n#include<bits/stdc++.h>\n\n#ifndef __COUNTER__\n#define\
    \ __COUNTER__ __LINE__\n#endif\n\n#define REP_SELECTER(a, b, c, d, e, ...) e\n\
    #define REP1_0(b, c) REP1_1(b, c)\n#define REP1_1(b, c) for (ll REP_COUNTER_ ##\
    \ c = 0; REP_COUNTER_ ## c < (ll)(b); ++ REP_COUNTER_ ## c)\n#define REP1(b) REP1_0(b,\
    \ __COUNTER__)\n#define REP2(i, b) for (ll i = 0; i < (ll)(b); ++i)\n#define REP3(i,\
    \ a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)\n#define REP4(i, a, b, c) for (ll\
    \ i = (ll)(a); i < (ll)(b); i += (ll)(c))\n#define rep(...) REP_SELECTER(__VA_ARGS__,\
    \ REP4, REP3, REP2, REP1) (__VA_ARGS__)\n#define RREP2(i, a) for (ll i = (ll)(a)\
    \ - 1; i >= 0; --i)\n#define RREP3(i, a, b) for (ll i = (ll)(a) - 1; i >= (ll)(b);\
    \ --i)\n#define RREP4(i, a, b, c) for (ll i = (ll)(a) - 1; i >= (ll)(b); i -=\
    \ (ll)(c))\n#define rrep(...) REP_SELECTER(__VA_ARGS__, RREP4, RREP3, RREP2) (__VA_ARGS__)\n\
    #define REPS2(i, b) for (ll i = 1; i <= (ll)(b); ++i)\n#define REPS3(i, a, b)\
    \ for (ll i = (ll)(a) + 1; i <= (ll)(b); ++i)\n#define REPS4(i, a, b, c) for (ll\
    \ i = (ll)(a) + 1; i <= (ll)(b); i += (ll)(c))\n#define reps(...) REP_SELECTER(__VA_ARGS__,\
    \ REPS4, REPS3, REPS2) (__VA_ARGS__)\n#define RREPS2(i, a) for (ll i = (ll)(a);\
    \ i > 0; --i)\n#define RREPS3(i, a, b) for (ll i = (ll)(a); i > (ll)(b); --i)\n\
    #define RREPS4(i, a, b, c) for (ll i = (ll)(a); i > (ll)(b); i -= (ll)(c))\n#define\
    \ rreps(...) REP_SELECTER(__VA_ARGS__, RREPS4, RREPS3, RREPS2) (__VA_ARGS__)\n\
    \n#define all(v) (v).begin(), (v).end()\n\n#if __cplusplus >= 201402L\n#define\
    \ CONSTEXPR constexpr\n#else\n#define CONSTEXPR\n#endif\n\nusing ll = long long;\n\
    using ull = unsigned long long;\nusing ld = long double;\nusing PLL = std::pair<ll,\
    \ ll>;\ntemplate<class T> using prique = std::priority_queue<T, std::vector<T>,\
    \ std::greater<T>>;\n\ntemplate<class T> class infinity {\n  public:\n    static\
    \ constexpr T value = std::numeric_limits<T>::max() / 2;\n    static constexpr\
    \ T mvalue = std::numeric_limits<T>::min() / 2;\n    static constexpr T max =\
    \ std::numeric_limits<T>::max();\n    static constexpr T min = std::numeric_limits<T>::min();\n\
    };\n\n#if __cplusplus <= 201402L\ntemplate<class T> constexpr T infinity<T>::value;\n\
    template<class T> constexpr T infinity<T>::mvalue;\ntemplate<class T> constexpr\
    \ T infinity<T>::max;\ntemplate<class T> constexpr T infinity<T>::min;\n#endif\n\
    \n#if __cplusplus >= 201402L\ntemplate<class T> constexpr T INF = infinity<T>::value;\n\
    #endif\n\nconstexpr ll inf = infinity<ll>::value;\nconstexpr ld EPS = 1e-8;\n\
    constexpr ld PI = 3.1415926535897932384626;\n\ntemplate<class T, class U> std::ostream&\
    \ operator<<(std::ostream& ost, const std::pair<T, U>& p) {\n    return ost <<\
    \ p.first << ' ' << p.second;\n}\ntemplate<class T, class U> std::istream& operator>>(std::istream&\
    \ ist, std::pair<T, U>& p) {\n    return ist >> p.first >> p.second;\n}\n\ntemplate<class\
    \ Container,\n        typename std::enable_if<!std::is_same<Container, std::string>::value>::type*\
    \ = nullptr>\nauto operator<<(std::ostream& ost, const Container& cont)\n    \
    \    -> decltype(cont.begin(), cont.end(), ost)\n{\n    for (auto itr = cont.begin();\
    \ itr != cont.end(); ++itr) {\n        if (itr != cont.begin()) ost << ' ';\n\
    \        ost << *itr;\n    }\n    return ost;\n}\ntemplate<class Container,\n\
    \        typename std::enable_if<!std::is_same<Container, std::string>::value>::type*\
    \ = nullptr>\nauto operator>>(std::istream& ist, Container& cont)\n        ->\
    \ decltype(cont.begin(), cont.end(), ist)\n{\n    for (auto itr = cont.begin();\
    \ itr != cont.end(); ++itr) ist >> *itr;\n    return ist;\n}\n\ntemplate<class\
    \ T, class U> inline constexpr bool chmin(T &a, const U &b) noexcept {\n    return\
    \ a > b ? a = b, true : false;\n}\ntemplate<class T, class U> inline constexpr\
    \ bool chmax(T &a, const U &b) noexcept {\n    return a < b ? a = b, true : false;\n\
    }\n\ninline CONSTEXPR ll gcd(ll a, ll b) noexcept {\n    while (b) {\n       \
    \ const ll c = a;\n        a = b;\n        b = c % b;\n    }\n    return a;\n\
    }\ninline CONSTEXPR ll lcm(ll a, ll b) noexcept {\n    return a / gcd(a, b) *\
    \ b;\n}\n\ninline CONSTEXPR bool is_prime(ll N) noexcept {\n    if (N <= 1) return\
    \ false;\n    for (ll i = 2; i * i <= N; ++i) {\n        if (N % i == 0) return\
    \ false;\n    }\n    return true;\n}\ninline std::vector<ll> prime_factor(ll N)\
    \ noexcept {\n    std::vector<ll> res;\n    for (ll i = 2; i * i <= N; ++i) {\n\
    \        while (N % i == 0) {\n            res.push_back(i);\n            N /=\
    \ i;\n        }\n    }\n    if (N != 1) res.push_back(N);\n    return res;\n}\n\
    \ninline CONSTEXPR ll my_pow(ll a, ll b) noexcept {\n    ll res = 1;\n    while\
    \ (b) {\n        if (b & 1) res *= a;\n        b >>= 1;\n        a *= a;\n   \
    \ }\n    return res;\n}\ninline CONSTEXPR ll mod_pow(ll a, ll b, ll mod) noexcept\
    \ {\n    a %= mod;\n    ll res = 1;\n    while (b) {\n        if (b & 1) (res\
    \ *= a) %= mod;\n        b >>= 1;\n        (a *= a) %= mod;\n    }\n    return\
    \ res;\n}\n\nPLL extGCD(ll a, ll b) noexcept {\n    if (b == 0) return PLL{1,\
    \ 0};\n    PLL p = extGCD(b, a % b);\n    std::swap(p.first, p.second);\n    p.second\
    \ -= p.first * (a / b);\n    if (p.first < 0) {\n        p.first += b;\n     \
    \   p.second -= a;\n    }\n    return p;\n}\nll mod_inv(ll a, ll mod) noexcept\
    \ {\n    const PLL p = extGCD(a, mod);\n    assert(p.first * a + p.second * mod\
    \ == 1);\n    return p.first;\n}\nPLL ChineseRemainder(ll b1, ll m1, ll b2, ll\
    \ m2) noexcept {\n    const PLL p = extGCD(m1, m2);\n    const ll g = p.first\
    \ * m1 + p.second * m2;\n    const ll l = m1 / g * m2;\n    if ((b2 - b1) % g\
    \ != 0) return PLL{-1, -1};\n    const ll x = (b2 - b1) / g * p.first % (m2 /\
    \ g);\n    return {(x * m1 + b1 + l) % l, l};\n}\nPLL ChineseRemainders(const\
    \ std::vector<ll>& b, const std::vector<ll>& m) noexcept {\n    PLL res{0, 1};\n\
    \    rep (i, b.size()) {\n        res = ChineseRemainder(res.first, res.second,\
    \ b[i], m[i]);\n        if (res.first == -1) return res;\n    }\n    return res;\n\
    }\n\ntemplate<class F> class RecLambda {\n  private:\n    F f;\n  public:\n  \
    \  explicit constexpr RecLambda(F&& f_) : f(std::forward<F>(f_)) {}\n    template<class...\
    \ Args> constexpr auto operator()(Args&&... args) const\n            -> decltype(f(*this,\
    \ std::forward<Args>(args)...)) {\n        return f(*this, std::forward<Args>(args)...);\n\
    \    }\n};\n\ntemplate<class F> inline constexpr RecLambda<F> rec_lambda(F&& f)\
    \ {\n    return RecLambda<F>(std::forward<F>(f));\n}\n\ntemplate<class Head, class...\
    \ Tails> struct multi_dim_vector {\n    using type = std::vector<typename multi_dim_vector<Tails...>::type>;\n\
    };\ntemplate<class T> struct multi_dim_vector<T> {\n    using type = T;\n};\n\n\
    template<class T, class Arg> constexpr std::vector<T> make_vec(int n, Arg&& arg)\
    \ {\n    return std::vector<T>(n, std::forward<Arg>(arg));\n}\ntemplate<class\
    \ T, class... Args>\nconstexpr typename multi_dim_vector<Args..., T>::type make_vec(int\
    \ n, Args&&... args) {\n    return typename multi_dim_vector<Args..., T>::type\
    \ (n, make_vec<T>(std::forward<Args>(args)...));\n}\n\ninline CONSTEXPR int popcnt(ull\
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
    \      std::copy(all(vec), this->begin() + n);\n    }\n    int build() {\n   \
    \     std::sort(this->begin(), this->end());\n        this->erase(std::unique(this->begin(),\
    \ this->end()), this->end());\n        return this->size();\n    }\n    int get_index(const\
    \ T& val) const {\n        return static_cast<int>(std::lower_bound(this->begin(),\
    \ this->end(), val) - this->begin());\n    }\n    std::vector<int> pressed(const\
    \ std::vector<T>& vec) const {\n        std::vector<int> res(vec.size());\n  \
    \      rep (i, vec.size()) res[i] = this->get_index(vec[i]);\n        return res;\n\
    \    }\n    void press(std::vector<T>& vec) const {\n        static_assert(std::is_integral<T>::value,\
    \ \"cannot convert from int type\");\n        rep (i, vec.size()) vec[i] = this->get_index(vec[i]);\n\
    \    }\n};\n#line 4 \"data-struct/unionfind/UnionFindUndo.hpp\"\n\nclass UnionFindUndo\
    \ {\n  protected:\n    int n;\n    std::vector<int> par_vec;\n    std::stack<std::pair<int,\
    \ int>> hist;\n  public:\n    UnionFindUndo() : UnionFindUndo(0) {}\n    UnionFindUndo(int\
    \ n) : n(n), par_vec(n, -1) {}\n    int find(int x) const {\n        assert(0\
    \ <= x && x < n);\n        return par_vec[x] < 0 ? x : find(par_vec[x]);\n   \
    \ }\n    std::pair<int, int> merge(int x, int y) {\n        x = find(x);\n   \
    \     y = find(y);\n        hist.emplace(x, par_vec[x]);\n        hist.emplace(y,\
    \ par_vec[y]);\n        if (x == y) return {x, -1};\n        if (par_vec[x] >\
    \ par_vec[y]) std::swap(x, y);\n        par_vec[x] += par_vec[y];\n        par_vec[y]\
    \ = x;\n        return {x, y};\n    }\n    bool same(int x, int y) const {\n \
    \       return find(x) == find(y);\n    }\n    int size(int x) const {\n     \
    \   return -par_vec[find(x)];\n    }\n    std::vector<std::vector<int>> groups()\
    \ const {\n        std::vector<std::vector<int>> res(n);\n        rep (i, n) res[find(i)].push_back(i);\n\
    \        res.erase(\n            remove_if(all(res), [](const std::vector<int>&\
    \ v) { return v.empty(); }),\n            res.end()\n        );\n        return\
    \ res;\n    }\n    bool is_root(int x) const {\n        assert(0 <= x && x < n);\n\
    \        return par_vec[x] < 0;\n    }\n    void undo() {\n        par_vec[hist.top().first]\
    \ = hist.top().second; hist.pop();\n        par_vec[hist.top().first] = hist.top().second;\
    \ hist.pop();\n    }\n    void snapshot() {\n        while (!hist.empty()) hist.pop();\n\
    \    }\n    void rollback() {\n        while (!hist.empty()) undo();\n    }\n\
    };\n\n/**\n * @brief UnionFindUndo(Undo\u53EF\u80FDUnionFind)\n * @docs docs/UnionFindUndo.md\n\
    \ */\n"
  code: "#pragma once\n\n#include \"../../other/template.hpp\"\n\nclass UnionFindUndo\
    \ {\n  protected:\n    int n;\n    std::vector<int> par_vec;\n    std::stack<std::pair<int,\
    \ int>> hist;\n  public:\n    UnionFindUndo() : UnionFindUndo(0) {}\n    UnionFindUndo(int\
    \ n) : n(n), par_vec(n, -1) {}\n    int find(int x) const {\n        assert(0\
    \ <= x && x < n);\n        return par_vec[x] < 0 ? x : find(par_vec[x]);\n   \
    \ }\n    std::pair<int, int> merge(int x, int y) {\n        x = find(x);\n   \
    \     y = find(y);\n        hist.emplace(x, par_vec[x]);\n        hist.emplace(y,\
    \ par_vec[y]);\n        if (x == y) return {x, -1};\n        if (par_vec[x] >\
    \ par_vec[y]) std::swap(x, y);\n        par_vec[x] += par_vec[y];\n        par_vec[y]\
    \ = x;\n        return {x, y};\n    }\n    bool same(int x, int y) const {\n \
    \       return find(x) == find(y);\n    }\n    int size(int x) const {\n     \
    \   return -par_vec[find(x)];\n    }\n    std::vector<std::vector<int>> groups()\
    \ const {\n        std::vector<std::vector<int>> res(n);\n        rep (i, n) res[find(i)].push_back(i);\n\
    \        res.erase(\n            remove_if(all(res), [](const std::vector<int>&\
    \ v) { return v.empty(); }),\n            res.end()\n        );\n        return\
    \ res;\n    }\n    bool is_root(int x) const {\n        assert(0 <= x && x < n);\n\
    \        return par_vec[x] < 0;\n    }\n    void undo() {\n        par_vec[hist.top().first]\
    \ = hist.top().second; hist.pop();\n        par_vec[hist.top().first] = hist.top().second;\
    \ hist.pop();\n    }\n    void snapshot() {\n        while (!hist.empty()) hist.pop();\n\
    \    }\n    void rollback() {\n        while (!hist.empty()) undo();\n    }\n\
    };\n\n/**\n * @brief UnionFindUndo(Undo\u53EF\u80FDUnionFind)\n * @docs docs/UnionFindUndo.md\n\
    \ */\n"
  dependsOn:
  - other/template.hpp
  isVerificationFile: false
  path: data-struct/unionfind/UnionFindUndo.hpp
  requiredBy: []
  timestamp: '2022-01-15 11:26:25+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/persistent_unionfind-Undo.test.cpp
documentation_of: data-struct/unionfind/UnionFindUndo.hpp
layout: document
redirect_from:
- /library/data-struct/unionfind/UnionFindUndo.hpp
- /library/data-struct/unionfind/UnionFindUndo.hpp.html
title: "UnionFindUndo(Undo\u53EF\u80FDUnionFind)"
---
## 概要

経路圧縮をしない場合、 merge 一回で変化する配列の値はたかだか $2$ つであるため、これを保存しておくことで undo 可能にした UnionFind 。

- `UnionFind(int N)` : サイズ `N` の UnionFind を作成する。 $\Theta(N)$ 。
- `pair<int, int> merge(int x, int y)` : 要素 `x` の属する集合と要素 `y` の属する集合を併合する。併合後の根とそうでない方の pair を返す。ただし、もともと同じ集合に属する場合は根と -1 の pair を返す。ならし $\Theta(\log N)$ 。
- `int find(int x)` : 要素 `x` の属する集合の代表元を返す。ならし $\Theta(\log N)$ 。
- `bool same(int x, int y)` : 要素 `x` と要素 `y` が同じ集合に属するかを判定する。ならし $\Theta(\log N)$ 。
- `int size(int x)` : 要素 `x` の属する集合の要素数を返す。ならし $\Theta(\log N)$ 。
- `bool is_root(int x)` : 要素 `x` が属する集合の代表元が `x` であるかを返す。 $\Theta(1)$ 。
- `vector<vector<int>> groups()` : 「「集合に属する要素のリスト」のリスト」を返す。ならし $\Theta(N\log N)$ 。
- `void undo()` : 直前の `unite` 操作を取り消す。 $\Theta(1)$ 。
- `void snapshot()` : 現在の状態を保存する。これ以前に `undo` することはできなくなるので注意。全体の合計での計算量は `merge` した回数に比例。
- `void rollback()` : 最初の状態、または最後に `snapshot` をした状態に戻す。計算量は `snapshot` と同様。
