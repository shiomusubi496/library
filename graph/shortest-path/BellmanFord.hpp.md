---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/Graph.hpp
    title: Graph-template
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_B-BellmanFord.test.cpp
    title: test/aoj/GRL_1_B-BellmanFord.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/BellmanFord.md
    document_title: "Bellman-Ford(\u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\
      \u6CD5)"
    links: []
  bundledCode: "#line 2 \"graph/shortest-path/BellmanFord.hpp\"\n\n#line 2 \"template.hpp\"\
    \n\n#include<bits/stdc++.h>\n\n#define rep(i, n) for (int i = 0; i < (int)(n);\
    \ ++i)\n#define rrep(i, n) for (int i = (int)(n) - 1; i >= 0; --i)\n#define all(v)\
    \ (v).begin(), (v).end()\n\nusing ll = long long;\nusing ull = unsigned long long;\n\
    using ld = long double;\nusing PLL = std::pair<ll, ll>;\ntemplate<class T> using\
    \ prique = std::priority_queue<T, std::vector<T>, std::greater<T>>;\n\ntemplate<class\
    \ T> constexpr T INF = std::numeric_limits<T>::max() / 2;\nconstexpr ll inf =\
    \ INF<ll>;\nconstexpr ld EPS = 1e-8;\nconstexpr ld PI = 3.1415926535897932384626;\n\
    \ntemplate<class T, class U> inline constexpr bool chmin(T &a, const U &b) noexcept\
    \ {\n    if (a > b) {\n        a = b;\n        return true;\n    }\n    return\
    \ false;\n}\ntemplate<class T, class U> inline constexpr bool chmax(T &a, const\
    \ U &b) noexcept {\n    if (a < b) {\n        a = b;\n        return true;\n \
    \   }\n    return false;\n}\n\ninline constexpr ll gcd(ll a, ll b) noexcept {\n\
    \    while (b) {\n        const ll c = a;\n        a = b;\n        b = c % b;\n\
    \    }\n    return a;\n}\ninline constexpr ll lcm(ll a, ll b) noexcept {\n   \
    \ return a / gcd(a, b) * b;\n}\n\ninline constexpr bool is_prime(ll N) noexcept\
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
    \ mod;\n    }\n    return res;\n}\n\ntemplate<class F> class rec_lambda {\n  private:\n\
    \    F f;\n  public:\n    explicit constexpr rec_lambda(F&& f_) : f(std::forward<F>(f_))\
    \ {}\n    template<class... Args> constexpr auto operator()(Args&&... args) const\
    \ {\n        return f(*this, std::forward<Args>(args)...);\n    }\n};\n\ntemplate<class\
    \ T, class Arg> constexpr std::vector<T> make_vec(int n, Arg&& arg) {\n    return\
    \ std::vector<T>(n, arg);\n}\ntemplate<class T, class... Args> constexpr auto\
    \ make_vec(int n, Args&&... args) {\n    return std::vector<decltype(make_vec<T>(args...))>\n\
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
    \ 2 \"graph/Graph.hpp\"\n\n#line 4 \"graph/Graph.hpp\"\n\ntemplate<class T = int>\
    \ struct edge {\n    int from, to;\n    T cost;\n    int idx;\n    edge() : from(-1),\
    \ to(-1) {}\n    edge(int t) : from(-1), to(t), cost(1) {}\n    edge(int t, T\
    \ c) : from(-1), to(t), cost(c) {}\n    edge(int f, int t, T c) : from(f), to(t),\
    \ cost(c) {}\n    edge(int f, int t, T c, int i): from(f), to(t), cost(c), idx(i)\
    \ {}\n    operator int() { return to; }\n};\n\ntemplate<class T = int> using Edges\
    \ = std::vector<edge<T>>;\ntemplate<class T = int> using GMatrix = std::vector<std::vector<T>>;\n\
    \ntemplate<class T = int> class Graph : public std::vector<std::vector<edge<T>>>\
    \ {\n  protected:\n    int edge_id = 0;\n    using Base = std::vector<std::vector<edge<T>>>;\n\
    \  public:\n    using Base::Base;\n    int edge_size() { return edge_id; }\n \
    \   int add_edge(int a, int b, T c, bool is_directed = false){\n        assert(0\
    \ <= a && a < this->size());\n        assert(0 <= b && b < this->size());\n  \
    \      (*this)[a].emplace_back(a, b, c, edge_id);\n        if (!is_directed) (*this)[b].emplace_back(b,\
    \ a, c, edge_id);\n        return edge_id++;\n    }\n    int add_edge(int a, int\
    \ b, bool is_directed = false){\n        assert(0 <= a && a < this->size());\n\
    \        assert(0 <= b && b < this->size());\n        (*this)[a].emplace_back(a,\
    \ b, 1, edge_id);\n        if (!is_directed) (*this)[b].emplace_back(b, a, 1,\
    \ edge_id);\n        return edge_id++;\n    }\n};\n\ntemplate<class T> GMatrix<T>\
    \ ListToMatrix(const Graph<T>& G) {\n    const int N = G.size();\n    auto res\
    \ = make_vec<T>(N, N, INF<T>);\n    rep (i, N) {\n        for (const edge<T>&\
    \ e : G[i]) res[i][e.to] = e.cost;\n    }\n    rep (i, N) res[i][i] = 0;\n   \
    \ return res;\n}\n\ntemplate<class T> Edges<T> ListToUndirectedEdges(const Graph<T>&\
    \ G) {\n    const int V = G.size();\n    const int E = G.edge_size();\n    Edges<T>\
    \ Ed(E);\n    rep (i, V) {\n        for (const edge<T>& e : G[i]) Ed[e.idx] =\
    \ e;\n    }\n    return Ed;\n}\ntemplate<class T> Edges<T> ListToDirectedEdges(const\
    \ Graph<T>& G) {\n    const int V = G.size();\n    const int E = std::accumulate(G.begin(),\
    \ G.end(), 0, [](int a, const std::vector<edge<T>>& b) -> int { return a + b.size();\
    \ });\n    Edges<T> Ed(G.edge_size());\n    Ed.reserve(E);\n    rep (i, V) {\n\
    \        for (const edge<T>& e : G[i]) {\n            if (Ed[e.idx].to == -1)\
    \ Ed[e.idx] = e;\n            else Ed.push_back(e);\n        }\n    }\n    return\
    \ Ed;\n}\n\n/*\n@brief Graph-template\n@docs docs/Graph.md\n*/\n#line 5 \"graph/shortest-path/BellmanFord.hpp\"\
    \n\ntemplate<class T> std::vector<T> BellmanFord(int V, const Edges<T>& Ed, int\
    \ start = 0) {\n    assert(0 <= start && start <= V);\n    const int E = Ed.size();\n\
    \    std::vector<T> dist(V, INF<T>); dist[start] = 0;\n    rep (i, V) {\n    \
    \    bool changed = false;\n        for (const edge<T>& e : Ed) {\n          \
    \  if (dist[e.from] != INF<T> && chmin(dist[e.to], dist[e.from] + e.cost)) changed\
    \ = true;\n        }\n        if (!changed) return dist;\n    }\n    for (const\
    \ edge<T>& e : Ed) {\n        if (dist[e.from] != INF<T> && dist[e.to] > dist[e.from]\
    \ + e.cost) dist[e.to] = -INF<T>;\n    }\n    rep (i, V - 1) {\n        bool changed\
    \ = false;\n        for (const edge<T>& e : Ed) {\n            if (dist[e.from]\
    \ == -INF<T>){\n                dist[e.to] = -INF<T>;\n                changed\
    \ = true;\n            }\n        }\n        if (!changed) break;\n    }\n   \
    \ return dist;\n}\n\n/*\n@brief Bellman-Ford(\u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\
    \u30FC\u30C9\u6CD5)\n@docs docs/BellmanFord.md\n*/\n"
  code: "#pragma once\n\n#include \"../../template.hpp\"\n#include \"../Graph.hpp\"\
    \n\ntemplate<class T> std::vector<T> BellmanFord(int V, const Edges<T>& Ed, int\
    \ start = 0) {\n    assert(0 <= start && start <= V);\n    const int E = Ed.size();\n\
    \    std::vector<T> dist(V, INF<T>); dist[start] = 0;\n    rep (i, V) {\n    \
    \    bool changed = false;\n        for (const edge<T>& e : Ed) {\n          \
    \  if (dist[e.from] != INF<T> && chmin(dist[e.to], dist[e.from] + e.cost)) changed\
    \ = true;\n        }\n        if (!changed) return dist;\n    }\n    for (const\
    \ edge<T>& e : Ed) {\n        if (dist[e.from] != INF<T> && dist[e.to] > dist[e.from]\
    \ + e.cost) dist[e.to] = -INF<T>;\n    }\n    rep (i, V - 1) {\n        bool changed\
    \ = false;\n        for (const edge<T>& e : Ed) {\n            if (dist[e.from]\
    \ == -INF<T>){\n                dist[e.to] = -INF<T>;\n                changed\
    \ = true;\n            }\n        }\n        if (!changed) break;\n    }\n   \
    \ return dist;\n}\n\n/*\n@brief Bellman-Ford(\u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\
    \u30FC\u30C9\u6CD5)\n@docs docs/BellmanFord.md\n*/\n"
  dependsOn:
  - template.hpp
  - graph/Graph.hpp
  isVerificationFile: false
  path: graph/shortest-path/BellmanFord.hpp
  requiredBy: []
  timestamp: '2021-11-04 12:47:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_1_B-BellmanFord.test.cpp
documentation_of: graph/shortest-path/BellmanFord.hpp
layout: document
redirect_from:
- /library/graph/shortest-path/BellmanFord.hpp
- /library/graph/shortest-path/BellmanFord.hpp.html
title: "Bellman-Ford(\u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\u6CD5)"
---
## 概要

負辺のあるグラフに対して単一始点最短経路問題を解く。負閉路の検出もする。

- `vector<T> BellmanFord(int N, Edges<T> E, int s = 0)` :  
辺のリスト `E` で表される頂点数 `N` のグラフに対して、各頂点の `s` からの距離を求める。  
`INF` の場合 `s` から到達不可能、 `-INF` の場合 `s` から到達可能な負閉路から到達可能。  
$O(|V| \times |E|)$。