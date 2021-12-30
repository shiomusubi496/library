---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/Graph.hpp
    title: Graph-template
  - icon: ':heavy_check_mark:'
    path: graph/shortest-path/Restore.hpp
    title: "Restore(\u7D4C\u8DEF\u5FA9\u5143)"
  - icon: ':question:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL/GRL_5_A-Diameter.test.cpp
    title: test/aoj/GRL/GRL_5_A-Diameter.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/tree_diameter.test.cpp
    title: test/yosupo/tree_diameter.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/TreeDiameter.md
    document_title: "TreeDiameter(\u6728\u306E\u76F4\u5F84)"
    links: []
  bundledCode: "#line 2 \"graph/tree/TreeDiameter.hpp\"\n\n#line 2 \"other/template.hpp\"\
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
    \ {\n    return std::vector<T>(n, arg);\n}\ntemplate<class T, class... Args>\n\
    constexpr typename multi_dim_vector<Args..., T>::type make_vec(int n, Args&&...\
    \ args) {\n    return typename multi_dim_vector<Args..., T>::type (n, make_vec<T>(std::forward<Args>(args)...));\n\
    }\n\ninline CONSTEXPR int popcnt(ull x) {\n#if __cplusplus >= 202002L\n    return\
    \ std::popcount(x);\n#endif\n    x = (x & 0x5555555555555555) + ((x >> 1 ) & 0x5555555555555555);\n\
    \    x = (x & 0x3333333333333333) + ((x >> 2 ) & 0x3333333333333333);\n    x =\
    \ (x & 0x0f0f0f0f0f0f0f0f) + ((x >> 4 ) & 0x0f0f0f0f0f0f0f0f);\n    x = (x & 0x00ff00ff00ff00ff)\
    \ + ((x >> 8 ) & 0x00ff00ff00ff00ff);\n    x = (x & 0x0000ffff0000ffff) + ((x\
    \ >> 16) & 0x0000ffff0000ffff);\n    return (x & 0x00000000ffffffff) + ((x >>\
    \ 32) & 0x00000000ffffffff);\n}\n\ntemplate<class T> class presser : public std::vector<T>\
    \ {\n  private:\n    using Base = std::vector<T>;\n  public:\n    using Base::Base;\n\
    \    presser(const std::vector<T>& vec) : Base(vec) {}\n    void push(const std::vector<T>&\
    \ vec) {\n        int n = this->size();\n        this->resize(n + vec.size());\n\
    \        std::copy(all(vec), this->begin() + n);\n    }\n    int build() {\n \
    \       std::sort(this->begin(), this->end());\n        this->erase(std::unique(this->begin(),\
    \ this->end()), this->end());\n        return this->size();\n    }\n    int get_index(const\
    \ T& val) const {\n        return static_cast<int>(std::lower_bound(this->begin(),\
    \ this->end(), val) - this->begin());\n    }\n    std::vector<int> pressed(const\
    \ std::vector<T>& vec) const {\n        std::vector<int> res(vec.size());\n  \
    \      rep (i, vec.size()) res[i] = this->get_index(vec[i]);\n        return res;\n\
    \    }\n    void press(std::vector<T>& vec) const {\n        static_assert(std::is_integral<T>::value,\
    \ \"cannot convert from int type\");\n        rep (i, vec.size()) vec[i] = this->get_index(vec[i]);\n\
    \    }\n};\n#line 2 \"graph/Graph.hpp\"\n\n#line 4 \"graph/Graph.hpp\"\n\ntemplate<class\
    \ T = int> struct edge {\n    int from, to;\n    T cost;\n    int idx;\n    edge()\
    \ : from(-1), to(-1) {}\n    edge(int f, int t, const T& c = 1, int i = -1) :\
    \ from(f), to(t), cost(c), idx(i) {}\n    operator int() const { return to; }\n\
    \    friend bool operator<(const edge<T>& lhs, const edge<T>& rhs) {\n       \
    \ return lhs.cost < rhs.cost;\n    }\n    friend bool operator>(const edge<T>&\
    \ lhs, const edge<T>& rhs) {\n        return lhs.cost > rhs.cost;\n    }\n};\n\
    \ntemplate<class T = int> using Edges = std::vector<edge<T>>;\ntemplate<class\
    \ T = int> using GMatrix = std::vector<std::vector<T>>;\n\ntemplate<class T =\
    \ int> class Graph : public std::vector<std::vector<edge<T>>> {\n  private:\n\
    \    using Base = std::vector<std::vector<edge<T>>>;\n  public:\n    int edge_id\
    \ = 0;\n    using Base::Base;\n    int edge_size() const { return edge_id; }\n\
    \    int add_edge(int a, int b, const T& c, bool is_directed = false) {\n    \
    \    assert(0 <= a && a < (int)this->size());\n        assert(0 <= b && b < (int)this->size());\n\
    \        (*this)[a].emplace_back(a, b, c, edge_id);\n        if (!is_directed)\
    \ (*this)[b].emplace_back(b, a, c, edge_id);\n        return edge_id++;\n    }\n\
    \    int add_edge(int a, int b, bool is_directed = false) {\n        assert(0\
    \ <= a && a < (int)this->size());\n        assert(0 <= b && b < (int)this->size());\n\
    \        (*this)[a].emplace_back(a, b, 1, edge_id);\n        if (!is_directed)\
    \ (*this)[b].emplace_back(b, a, 1, edge_id);\n        return edge_id++;\n    }\n\
    };\n\ntemplate<class T> GMatrix<T> ListToMatrix(const Graph<T>& G) {\n    const\
    \ int N = G.size();\n    auto res = make_vec<T>(N, N, infinity<T>::value);\n \
    \   rep (i, N) res[i][i] = 0;\n    rep (i, N) {\n        for (const edge<T>& e\
    \ : G[i]) res[i][e.to] = e.cost;\n    }\n    return res;\n}\n\ntemplate<class\
    \ T> Edges<T> UndirectedListToEdges(const Graph<T>& G) {\n    const int V = G.size();\n\
    \    const int E = G.edge_size();\n    Edges<T> Ed(E);\n    rep (i, V) {\n   \
    \     for (const edge<T>& e : G[i]) Ed[e.idx] = e;\n    }\n    return Ed;\n}\n\
    \ntemplate<class T> Edges<T> DirectedListToEdges(const Graph<T>& G) {\n    const\
    \ int V = G.size();\n    const int E = std::accumulate(\n        all(G), 0,\n\
    \        [](int a, const std::vector<edge<T>>& v) -> int { return a + v.size();\
    \ }\n    );\n    Edges<T> Ed(G.edge_size()); Ed.reserve(E);\n    rep (i, V) {\n\
    \        for (const edge<T>& e : G[i]) {\n            if (Ed[e.idx] == -1) Ed[e.idx]\
    \ = e;\n            else Ed.push_back(e);\n        }\n    }\n    return Ed;\n\
    }\n\ntemplate<class T> Graph<T> ReverseGraph(const Graph<T>& G) {\n    const int\
    \ V = G.size();\n    Graph<T> res(V);\n    rep (i, V) {\n        for (const auto&\
    \ e : G[i]) {\n            res[e.to].emplace_back(e.to, e.from, e.cost, e.idx);\n\
    \        }\n    }\n    res.edge_id = G.edge_size();\n    return res;\n}\n\n/**\n\
    \ * @brief Graph-template\n * @docs docs/Graph.md\n */\n#line 2 \"graph/shortest-path/Restore.hpp\"\
    \n\n#line 5 \"graph/shortest-path/Restore.hpp\"\n\ntemplate<class T> std::vector<int>\
    \ Restore(const Graph<T>& G, const std::vector<T>& dist, int start = 0) {\n  \
    \  const int N = G.size();\n    std::vector<int> bfr(N, -2); bfr[start] = -1;\n\
    \    std::queue<int> que; que.push(start);\n    while (!que.empty()) {\n     \
    \   int v = que.front(); que.pop();\n        for (const edge<T>& e : G[v]) {\n\
    \            if (bfr[e.to] == -2 && dist[e.to] == dist[v] + e.cost) {\n      \
    \          bfr[e.to] = v;\n                que.push(e.to);\n            }\n  \
    \      }\n    }\n    return bfr;\n}\n\ntemplate<class T> Edges<T> RestorePath(const\
    \ Graph<T>& G, const std::vector<T>& dist, int s, int t) {\n    const auto RG\
    \ = ReverseGraph(G);\n    std::vector<bool> seen(G.size(), false); seen[t] = true;\n\
    \    Edges<T> res;\n    while (s != t) {\n        bool flg = false;\n        for\
    \ (const edge<T>& e : RG[t]) {\n            if (!seen[e.to] && dist[e.to] + e.cost\
    \ == dist[t]) {\n                seen[e.to] = true;\n                res.push_back(e);\
    \ std::swap(res.back().from, res.back().to);\n                t = e.to;\n    \
    \            flg = true;\n                break;\n            }\n        }\n \
    \       assert(flg);\n    }\n    std::reverse(all(res));\n    return res;\n}\n\
    \n/**\n * @brief Restore(\u7D4C\u8DEF\u5FA9\u5143)\n * @docs docs/Restore.md\n\
    \ */\n#line 6 \"graph/tree/TreeDiameter.hpp\"\n\ntemplate<class T> class TreeDiameter\
    \ {\n  protected:\n    const Graph<T>& G;\n    int s, t;\n    std::vector<T> dist;\n\
    \    void dfs(int v, int p) {\n        for (const edge<T>& e : G[v]) {\n     \
    \       if (e.to == p) continue;\n            dist[e.to] = dist[v] + e.cost;\n\
    \            dfs(e.to, v);\n        }\n    }\n    void init() {\n        dist.resize(G.size());\
    \ dist[0] = 0;\n        dfs(0, -1);\n        s = std::max_element(all(dist)) -\
    \ dist.begin();\n        dist[s] = 0;\n        dfs(s, -1);\n        t = std::max_element(all(dist))\
    \ - dist.begin();\n    }\n  public:\n    TreeDiameter(const Graph<T>& G) : G(G)\
    \ { init(); }\n    T diameter() const { return dist[t]; }\n    std::pair<int,\
    \ int> get_pair() const { return {s, t}; }\n    Edges<T> get_path() const { return\
    \ RestorePath(G, dist, s, t); }\n};\n\n/**\n * @brief TreeDiameter(\u6728\u306E\
    \u76F4\u5F84)\n * @docs docs/TreeDiameter.md\n */\n"
  code: "#pragma once\n\n#include \"../../other/template.hpp\"\n#include \"../Graph.hpp\"\
    \n#include \"../shortest-path/Restore.hpp\"\n\ntemplate<class T> class TreeDiameter\
    \ {\n  protected:\n    const Graph<T>& G;\n    int s, t;\n    std::vector<T> dist;\n\
    \    void dfs(int v, int p) {\n        for (const edge<T>& e : G[v]) {\n     \
    \       if (e.to == p) continue;\n            dist[e.to] = dist[v] + e.cost;\n\
    \            dfs(e.to, v);\n        }\n    }\n    void init() {\n        dist.resize(G.size());\
    \ dist[0] = 0;\n        dfs(0, -1);\n        s = std::max_element(all(dist)) -\
    \ dist.begin();\n        dist[s] = 0;\n        dfs(s, -1);\n        t = std::max_element(all(dist))\
    \ - dist.begin();\n    }\n  public:\n    TreeDiameter(const Graph<T>& G) : G(G)\
    \ { init(); }\n    T diameter() const { return dist[t]; }\n    std::pair<int,\
    \ int> get_pair() const { return {s, t}; }\n    Edges<T> get_path() const { return\
    \ RestorePath(G, dist, s, t); }\n};\n\n/**\n * @brief TreeDiameter(\u6728\u306E\
    \u76F4\u5F84)\n * @docs docs/TreeDiameter.md\n */\n"
  dependsOn:
  - other/template.hpp
  - graph/Graph.hpp
  - graph/shortest-path/Restore.hpp
  isVerificationFile: false
  path: graph/tree/TreeDiameter.hpp
  requiredBy: []
  timestamp: '2021-12-20 15:01:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL/GRL_5_A-Diameter.test.cpp
  - test/yosupo/tree_diameter.test.cpp
documentation_of: graph/tree/TreeDiameter.hpp
layout: document
redirect_from:
- /library/graph/tree/TreeDiameter.hpp
- /library/graph/tree/TreeDiameter.hpp.html
title: "TreeDiameter(\u6728\u306E\u76F4\u5F84)"
---
## 概要

木の直径を計算するクラス。最短経路問題を $2$ 回解けば良いことで知られている。

- `TreeDiameter(Tree<T> T)` : 木 `T` で初期化する。
- `T diameter()` : 直径の重みの総和を返す。
- `pair<int, int> get_pair()` : 直径の両端を返す。
- `Edges<T> get_path()` : 直径の辺のリストを返す。
