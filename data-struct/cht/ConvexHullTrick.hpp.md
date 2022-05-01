---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/line_add_get_min.test.cpp
    title: test/yosupo/line_add_get_min.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/ConvexHullTrick.md
    document_title: ConvexHullTrick
    links: []
  bundledCode: "#line 2 \"data-struct/cht/ConvexHullTrick.hpp\"\n\n#line 2 \"other/template.hpp\"\
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
    \n#define each_for(...) for (auto&& __VA_ARGS__)\n#define each_const(...) for\
    \ (const auto& __VA_ARGS__)\n\n#define all(v) std::begin(v), std::end(v)\n#define\
    \ rall(v) std::rbegin(v), std::rend(v)\n\n#if __cplusplus >= 201402L\n#define\
    \ CONSTEXPR constexpr\n#else\n#define CONSTEXPR\n#endif\n\n#ifdef __cpp_if_constexpr\n\
    #define IF_CONSTEXPR constexpr\n#else\n#define IF_CONSTEXPR\n#endif\n\nusing ll\
    \ = long long;\nusing ull = unsigned long long;\nusing ld = long double;\nusing\
    \ PLL = std::pair<ll, ll>;\ntemplate<class T> using prique = std::priority_queue<T,\
    \ std::vector<T>, std::greater<T>>;\n\ntemplate<class T> class infinity {\n  public:\n\
    \    static constexpr T value = std::numeric_limits<T>::max() / 2;\n    static\
    \ constexpr T mvalue = std::numeric_limits<T>::min() / 2;\n    static constexpr\
    \ T max = std::numeric_limits<T>::max();\n    static constexpr T min = std::numeric_limits<T>::min();\n\
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
    \ res;\n}\n\ninline PLL extGCD(ll a, ll b) noexcept {\n    const ll n = a, m =\
    \ b;\n    ll x = 1, y = 0, u = 0, v = 1;\n    ll t;\n    while (b) {\n       \
    \ t = a / b;\n        std::swap(a -= t * b, b);\n        std::swap(x -= t * u,\
    \ u);\n        std::swap(y -= t * v, v);\n    }\n    if (x < 0) {\n        x +=\
    \ m;\n        y -= n;\n    }\n    return {x, y};\n}\ninline ll mod_inv(ll a, ll\
    \ mod) noexcept {\n    ll b = mod;\n    ll x = 1, u = 0;\n    ll t;\n    while\
    \ (b) {\n        t = a / b;\n        std::swap(a -= t * b, b);\n        std::swap(x\
    \ -= t * u, u);\n    }\n    if (x < 0) x += mod;\n    assert(a == 1);\n    return\
    \ x;\n}\ninline PLL ChineseRemainder(ll b1, ll m1, ll b2, ll m2) noexcept {\n\
    \    const PLL p = extGCD(m1, m2);\n    const ll g = p.first * m1 + p.second *\
    \ m2;\n    const ll l = m1 / g * m2;\n    if ((b2 - b1) % g != 0) return PLL{-1,\
    \ -1};\n    const ll x = (b2 - b1) / g * p.first % (m2 / g);\n    return {(x *\
    \ m1 + b1 + l) % l, l};\n}\nPLL ChineseRemainders(const std::vector<ll>& b, const\
    \ std::vector<ll>& m) noexcept {\n    PLL res{0, 1};\n    rep (i, b.size()) {\n\
    \        res = ChineseRemainder(res.first, res.second, b[i], m[i]);\n        if\
    \ (res.first == -1) return res;\n    }\n    return res;\n}\n\ntemplate<class F>\
    \ class RecLambda {\n  private:\n    F f;\n  public:\n    explicit constexpr RecLambda(F&&\
    \ f_) : f(std::forward<F>(f_)) {}\n    template<class... Args> constexpr auto\
    \ operator()(Args&&... args) const\n            -> decltype(f(*this, std::forward<Args>(args)...))\
    \ {\n        return f(*this, std::forward<Args>(args)...);\n    }\n};\n\ntemplate<class\
    \ F> inline constexpr RecLambda<F> rec_lambda(F&& f) {\n    return RecLambda<F>(std::forward<F>(f));\n\
    }\n\ntemplate<class Head, class... Tail> struct multi_dim_vector {\n    using\
    \ type = std::vector<typename multi_dim_vector<Tail...>::type>;\n};\ntemplate<class\
    \ T> struct multi_dim_vector<T> {\n    using type = T;\n};\n\ntemplate<class T,\
    \ class Arg> constexpr std::vector<T> make_vec(int n, Arg&& arg) {\n    return\
    \ std::vector<T>(n, std::forward<Arg>(arg));\n}\ntemplate<class T, class... Args>\n\
    constexpr typename multi_dim_vector<Args..., T>::type make_vec(int n, Args&&...\
    \ args) {\n    return typename multi_dim_vector<Args..., T>::type (n, make_vec<T>(std::forward<Args>(args)...));\n\
    }\n\ninline CONSTEXPR int popcnt(ull x) {\n#if __cplusplus >= 202002L\n    return\
    \ std::popcount(x);\n#endif\n    x = (x & 0x5555555555555555) + ((x >> 1 ) & 0x5555555555555555);\n\
    \    x = (x & 0x3333333333333333) + ((x >> 2 ) & 0x3333333333333333);\n    x =\
    \ (x & 0x0f0f0f0f0f0f0f0f) + ((x >> 4 ) & 0x0f0f0f0f0f0f0f0f);\n    x = (x & 0x00ff00ff00ff00ff)\
    \ + ((x >> 8 ) & 0x00ff00ff00ff00ff);\n    x = (x & 0x0000ffff0000ffff) + ((x\
    \ >> 16) & 0x0000ffff0000ffff);\n    return (x & 0x00000000ffffffff) + ((x >>\
    \ 32) & 0x00000000ffffffff);\n}\n\ntemplate<class T, class Comp = std::less<T>>\
    \ class presser {\n  protected:\n    std::vector<T> dat;\n    Comp cmp;\n    bool\
    \ sorted = false;\n  public:\n    presser() : presser(Comp()) {}\n    presser(const\
    \ Comp& cmp) : cmp(cmp) {}\n    presser(const std::vector<T>& vec, const Comp&\
    \ cmp = Comp()) : dat(vec), cmp(cmp) {}\n    presser(std::vector<T>&& vec, const\
    \ Comp& cmp = Comp()) : dat(std::move(vec)), cmp(cmp) {}\n    presser(std::initializer_list<T>\
    \ il, const Comp& cmp = Comp()) : dat(il.begin(), il.end()), cmp(cmp) {}\n   \
    \ void reserve(int n) {\n        assert(!sorted);\n        dat.reserve(n);\n \
    \   }\n    void push_back(const T& v) {\n        assert(!sorted);\n        dat.push_back(v);\n\
    \    }\n    void push_back(T&& v) {\n        assert(!sorted);\n        dat.push_back(std::move(v));\n\
    \    }\n    void push(const std::vector<T>& vec) {\n        assert(!sorted);\n\
    \        const int n = dat.size();\n        dat.resize(n + vec.size());\n    \
    \    rep (i, vec.size()) dat[n + i] = vec[i];\n    }\n    int build() {\n    \
    \    assert(!sorted); sorted = true;\n        std::sort(all(dat), cmp);\n    \
    \    dat.erase(std::unique(all(dat), [&](const T& a, const T& b) -> bool {\n \
    \           return !cmp(a, b) && !cmp(b, a);\n        }), dat.end());\n      \
    \  return dat.size();\n    }\n    const T& operator[](int k) const& {\n      \
    \  assert(sorted);\n        assert(0 <= k && k < (int)dat.size());\n        return\
    \ dat[k];\n    }\n    T operator[](int k) && {\n        assert(sorted);\n    \
    \    assert(0 <= k && k < (int)dat.size());\n        return std::move(dat[k]);\n\
    \    }\n    int get_index(const T& val) const {\n        assert(sorted);\n   \
    \     return static_cast<int>(std::lower_bound(all(dat), val, cmp) - dat.begin());\n\
    \    }\n    std::vector<int> pressed(const std::vector<T>& vec) const {\n    \
    \    assert(sorted);\n        std::vector<int> res(vec.size());\n        rep (i,\
    \ vec.size()) res[i] = get_index(vec[i]);\n        return res;\n    }\n    void\
    \ press(std::vector<T>& vec) const {\n        static_assert(std::is_integral<T>::value,\
    \ \"template argument must be convertible from int type\");\n        assert(sorted);\n\
    \        each_for (i : vec) i = get_index(i);\n    }\n    int size() const {\n\
    \        assert(sorted);\n        return dat.size();\n    }\n    const std::vector<T>&\
    \ data() const& { return dat; }\n    std::vector<T> data() && { return std::move(dat);\
    \ }\n};\n#line 4 \"data-struct/cht/ConvexHullTrick.hpp\"\n\ntemplate<class T =\
    \ ll, bool is_max = false, class LargeT = __int128_t> class ConvexHullTrick {\n\
    \  protected:\n    struct Line {\n        T a, b;\n        bool is_query;\n  \
    \      mutable ll nxt_a, nxt_b;\n        mutable bool has_nxt;\n        T get(T\
    \ x) const { return a * x + b; }\n        T get_nxt(T x) const { return nxt_a\
    \ * x + nxt_b; }\n        Line() = default;\n        Line(T a, T b, bool i = false)\
    \ : a(a), b(b), is_query(i), has_nxt(false) {}\n        friend bool operator<(const\
    \ Line& lhs, const Line& rhs) {\n            assert(!lhs.is_query || !rhs.is_query);\n\
    \            if (lhs.is_query) {\n                if (!rhs.has_nxt) return true;\n\
    \                return rhs.get(lhs.a) < rhs.get_nxt(lhs.a);\n            }\n\
    \            if (rhs.is_query) {\n                if (!lhs.has_nxt) return false;\n\
    \                return lhs.get(rhs.a) > lhs.get_nxt(rhs.a);\n            }\n\
    \            return lhs.a == rhs.a ? lhs.b < rhs.b : lhs.a < rhs.a;\n        }\n\
    \    };\n    std::set<Line> st;\n    bool is_necessary(const typename std::set<Line>::iterator&\
    \ itr) {\n        if (itr != st.begin()     && itr->a == prev(itr)->a) return\
    \ itr->b < prev(itr)->b;\n        if (itr != prev(st.end()) && itr->a == next(itr)->a)\
    \ return itr->b < next(itr)->b;\n        if (itr == st.begin() || itr == prev(st.end()))\
    \ return true;\n        return (LargeT)(itr->b - prev(itr)->b) * (next(itr)->a\
    \ - itr->a)\n            <  (LargeT)(itr->b - next(itr)->b) * (prev(itr)->a -\
    \ itr->a);\n    }\n  public:\n    ConvexHullTrick() = default;\n    void add_line(T\
    \ a, T b) {\n        if IF_CONSTEXPR (is_max) a = - a, b = - b;\n        typename\
    \ std::set<Line>::iterator itr = st.insert(Line{a, b}).first;\n        if (!is_necessary(itr))\
    \ {\n            st.erase(itr);\n            return;\n        }\n        while\
    \ (itr != st.begin()     && !is_necessary(prev(itr))) st.erase(prev(itr));\n \
    \       while (itr != prev(st.end()) && !is_necessary(next(itr))) st.erase(next(itr));\n\
    \        if (itr != st.begin()) {\n            prev(itr)->has_nxt = true;\n  \
    \          prev(itr)->nxt_a = itr->a; prev(itr)->nxt_b = itr->b;\n        }\n\
    \        if (itr != prev(st.end())) {\n            itr->has_nxt = true;\n    \
    \        itr->nxt_a = next(itr)->a; itr->nxt_b = next(itr)->b;\n        }\n  \
    \      else itr->has_nxt = false;\n    }\n    T get_min(T x) const {\n       \
    \ auto itr = st.lower_bound(Line{x, 0, true});\n        if IF_CONSTEXPR (is_max)\
    \ return - itr->get(x);\n        return itr->get(x);\n    }\n    bool empty()\
    \ const {\n        return st.empty();\n    }\n};\n\n/**\n * @brief ConvexHullTrick\n\
    \ * @docs docs/ConvexHullTrick.md\n */\n"
  code: "#pragma once\n\n#include \"../../other/template.hpp\"\n\ntemplate<class T\
    \ = ll, bool is_max = false, class LargeT = __int128_t> class ConvexHullTrick\
    \ {\n  protected:\n    struct Line {\n        T a, b;\n        bool is_query;\n\
    \        mutable ll nxt_a, nxt_b;\n        mutable bool has_nxt;\n        T get(T\
    \ x) const { return a * x + b; }\n        T get_nxt(T x) const { return nxt_a\
    \ * x + nxt_b; }\n        Line() = default;\n        Line(T a, T b, bool i = false)\
    \ : a(a), b(b), is_query(i), has_nxt(false) {}\n        friend bool operator<(const\
    \ Line& lhs, const Line& rhs) {\n            assert(!lhs.is_query || !rhs.is_query);\n\
    \            if (lhs.is_query) {\n                if (!rhs.has_nxt) return true;\n\
    \                return rhs.get(lhs.a) < rhs.get_nxt(lhs.a);\n            }\n\
    \            if (rhs.is_query) {\n                if (!lhs.has_nxt) return false;\n\
    \                return lhs.get(rhs.a) > lhs.get_nxt(rhs.a);\n            }\n\
    \            return lhs.a == rhs.a ? lhs.b < rhs.b : lhs.a < rhs.a;\n        }\n\
    \    };\n    std::set<Line> st;\n    bool is_necessary(const typename std::set<Line>::iterator&\
    \ itr) {\n        if (itr != st.begin()     && itr->a == prev(itr)->a) return\
    \ itr->b < prev(itr)->b;\n        if (itr != prev(st.end()) && itr->a == next(itr)->a)\
    \ return itr->b < next(itr)->b;\n        if (itr == st.begin() || itr == prev(st.end()))\
    \ return true;\n        return (LargeT)(itr->b - prev(itr)->b) * (next(itr)->a\
    \ - itr->a)\n            <  (LargeT)(itr->b - next(itr)->b) * (prev(itr)->a -\
    \ itr->a);\n    }\n  public:\n    ConvexHullTrick() = default;\n    void add_line(T\
    \ a, T b) {\n        if IF_CONSTEXPR (is_max) a = - a, b = - b;\n        typename\
    \ std::set<Line>::iterator itr = st.insert(Line{a, b}).first;\n        if (!is_necessary(itr))\
    \ {\n            st.erase(itr);\n            return;\n        }\n        while\
    \ (itr != st.begin()     && !is_necessary(prev(itr))) st.erase(prev(itr));\n \
    \       while (itr != prev(st.end()) && !is_necessary(next(itr))) st.erase(next(itr));\n\
    \        if (itr != st.begin()) {\n            prev(itr)->has_nxt = true;\n  \
    \          prev(itr)->nxt_a = itr->a; prev(itr)->nxt_b = itr->b;\n        }\n\
    \        if (itr != prev(st.end())) {\n            itr->has_nxt = true;\n    \
    \        itr->nxt_a = next(itr)->a; itr->nxt_b = next(itr)->b;\n        }\n  \
    \      else itr->has_nxt = false;\n    }\n    T get_min(T x) const {\n       \
    \ auto itr = st.lower_bound(Line{x, 0, true});\n        if IF_CONSTEXPR (is_max)\
    \ return - itr->get(x);\n        return itr->get(x);\n    }\n    bool empty()\
    \ const {\n        return st.empty();\n    }\n};\n\n/**\n * @brief ConvexHullTrick\n\
    \ * @docs docs/ConvexHullTrick.md\n */\n"
  dependsOn:
  - other/template.hpp
  isVerificationFile: false
  path: data-struct/cht/ConvexHullTrick.hpp
  requiredBy: []
  timestamp: '2022-05-01 19:37:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/line_add_get_min.test.cpp
documentation_of: data-struct/cht/ConvexHullTrick.hpp
layout: document
redirect_from:
- /library/data-struct/cht/ConvexHullTrick.hpp
- /library/data-struct/cht/ConvexHullTrick.hpp.html
title: ConvexHullTrick
---
## 概要

`y = ax + b` の形の `x` の一次関数に関するクエリを扱える。具体的には、一次関数を追加するクエリと、ある `x` に対して最小値を取る一次関数を求めるクエリ。

- `ConvexHullTrick()` : `ConvexHullTrick` を作成する。ここで、関数集合を $s$ と表す。 $\Theta(1)$ 。
- `void add_line(T a, T b)` : $s$ に `f(x) = ax + b` を追加する。 $\Theta(\log N)$ 。
- `T get_min(T x)` : $\min_{f \in s} f(x)$ を返す。 $\Theta(\log N)$ 。
- `bool empty()` : $s = \emptyset$ であるかを返す。 $\Theta(1)$ 。
