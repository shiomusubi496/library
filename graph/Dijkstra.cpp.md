---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/Graph.cpp
    title: Graph-template
  - icon: ':heavy_check_mark:'
    path: template.cpp
    title: template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_A-dijkstra.test.cpp
    title: test/aoj/GRL_1_A-dijkstra.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/Dijkstra.md
    document_title: "Dijkstra(\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5)"
    links: []
  bundledCode: "#line 2 \"graph/Dijkstra.cpp\"\n\n#line 2 \"template.cpp\"\n\n#include<bits/stdc++.h>\n\
    \n#define rep(i, n) for(int i = 0; i < (int)(n); ++i)\n#define rrep(i, n) for(int\
    \ i = (int)(n) - 1; i >= 0; --i)\n#define all(v) (v).begin(), (v).end()\n\nusing\
    \ ll = long long;\nusing ull = unsigned long long;\nusing ld = long double;\n\
    using PLL = std::pair<ll, ll>;\n\nconstexpr int inf = 1e9;\nconstexpr ll INF =\
    \ 1e18;\nconstexpr ld EPS = 1e-8;\nconstexpr ld PI = 3.1415926535897932384626;\n\
    \ntemplate<class T, class U> inline constexpr bool chmin(T &a, const U &b) noexcept\
    \ {\n    if (a > b) {\n        a = b;\n        return true;\n    }\n    return\
    \ false;\n}\ntemplate<class T, class U> inline constexpr bool chmax(T &a, const\
    \ U &b) noexcept {\n    if (a < b) {\n        a = b;\n        return true;\n \
    \   }\n    return false;\n}\n\ninline constexpr ll gcd(ll a, ll b) noexcept {\n\
    \    while (b) {\n        const ll c = a;\n        a = b;\n        b = c % b;\n\
    \    }\n    return a;\n}\ninline constexpr ll lcm(ll a, ll b) noexcept {\n   \
    \ return a / gcd(a, b) * b;\n}\n\ninline constexpr ll my_pow(ll a, ll b) noexcept\
    \ {\n    ll res = 1;\n    while (b) {\n        if (b & 1) res *= a;\n        b\
    \ >>= 1;\n        a *= a;\n    }\n    return res;\n}\ninline constexpr ll mod_pow(ll\
    \ a, ll b, ll mod) noexcept {\n    a %= mod;\n    ll res = 1;\n    while (b) {\n\
    \        if (b & 1) (res *= a) %= mod;\n        b >>= 1;\n        (a *= a) %=\
    \ mod;\n    }\n    return res;\n}\n\ntemplate<class F> class rec_lambda {\n  private:\n\
    \    F f;\n  public:\n    explicit constexpr rec_lambda(F&& f_) : f(std::forward<F>(f_))\
    \ {}\n    template<class... Args> constexpr auto operator()(Args&&... args) const\
    \ {\n        return f(*this, std::forward<Args>(args)...);\n    }\n};\n\ntemplate<class\
    \ T, class Arg> constexpr std::vector<T> make_vec(size_t n, Arg&& arg) {\n   \
    \ return std::vector<T>(n, arg);\n}\ntemplate<class T, class... Args> constexpr\
    \ auto make_vec(size_t n, Args&&... args) {\n    return std::vector<decltype(make_vec<T>(args...))>\n\
    \               (n, make_vec<T>(std::forward<Args>(args)...));\n}\n\ninline constexpr\
    \ int popcnt(ull x) {\n#if __cplusplus >= 202002L\n    return std::popcount(x);\n\
    #endif\n    x = (x & 0x5555555555555555) + ((x >> 1 ) & 0x5555555555555555);\n\
    \    x = (x & 0x3333333333333333) + ((x >> 2 ) & 0x3333333333333333);\n    x =\
    \ (x & 0x0f0f0f0f0f0f0f0f) + ((x >> 4 ) & 0x0f0f0f0f0f0f0f0f);\n    x = (x & 0x00ff00ff00ff00ff)\
    \ + ((x >> 8 ) & 0x00ff00ff00ff00ff);\n    x = (x & 0x0000ffff0000ffff) + ((x\
    \ >> 16) & 0x0000ffff0000ffff);\n    return (x & 0x00000000ffffffff) + ((x >>\
    \ 32) & 0x00000000ffffffff);\n}\n\ntemplate<class T> class presser : public std::vector<T>\
    \ {\n  private:\n    using size_type = size_t;\n    using Base = std::vector<T>;\n\
    \  public:\n    using Base::Base;\n    presser(const std::vector<T>& vec) : Base(vec)\
    \ {}\n    void push(const std::vector<T>& vec) {\n        size_type n = this->size();\n\
    \        this->resize(n + vec.size());\n        std::copy(vec.begin(), vec.end(),\
    \ this->begin() + n);\n    }\n    size_type build() {\n        std::sort(this->begin(),\
    \ this->end());\n        this->erase(std::unique(this->begin(), this->end()),\
    \ this->end());\n        return this->size();\n    }\n    size_type get_index(const\
    \ T& val) const {\n        return std::lower_bound(this->begin(), this->end(),\
    \ val) - this->begin();\n    }\n    std::vector<size_type> pressed(const std::vector<T>&\
    \ vec) const {\n        std::vector<size_type> res(vec.size());\n        rep(i,\
    \ vec.size()) res[i] = this->get_index(vec[i]);\n        return res;\n    }\n\
    \    void press(std::vector<T>& vec) const {\n        static_assert(std::is_integral<T>::value);\n\
    \        rep(i, vec.size()) vec[i] = this->get_index(vec[i]);\n    }\n};\n#line\
    \ 2 \"graph/Graph.cpp\"\n\n#line 4 \"graph/Graph.cpp\"\n\ntemplate<class T = int>\
    \ struct edge {\n    int from, to;\n    T cost;\n    size_t idx;\n    edge() =\
    \ default;\n    edge(int t) : from(-1), to(t), cost(1) {}\n    edge(int t, T c)\
    \ : from(-1), to(t), cost(c) {}\n    edge(int f, int t, T c) : from(f), to(t),\
    \ cost(c) {}\n    edge(int f, int t, T c, size_t i): from(f), to(t), cost(c),\
    \ idx(i) {}\n    operator int() { return to; }\n};\n\ntemplate<typename T = int>\
    \ using Edges = std::vector<edge<T>>;\n\ntemplate<typename T = int> class Graph\
    \ : public std::vector<std::vector<edge<T>>> {\n  private:\n    using Base = std::vector<std::vector<edge<T>>>;\n\
    \  public:\n    using Base::Base;\n    size_t edge_id = 0;\n    size_t add_edge(int\
    \ a, int b, T c, bool is_directed = false){\n        (*this)[a].emplace_back(a,\
    \ b, c, edge_id);\n        if(!is_directed) (*this)[b].emplace_back(b, a, c, edge_id);\n\
    \        return edge_id++;\n    }\n    size_t add_edge(int a, int b, bool is_directed\
    \ = false){\n        (*this)[a].emplace_back(a, b, 1, edge_id);\n        if(!is_directed)\
    \ (*this)[b].emplace_back(b, a, 1, edge_id);\n        return edge_id++;\n    }\n\
    };\n\n/*\n@brief Graph-template\n@docs docs/Graph.md\n*/\n#line 5 \"graph/Dijkstra.cpp\"\
    \n\ntemplate<class T> std::vector<T> Dijkstra(const Graph<T>& G, int s = 0) {\n\
    \    std::vector<T> dist(G.size(), -1);\n    dist[s] = 0;\n    std::priority_queue<std::pair<T,\
    \ int>, std::vector<std::pair<T, int>>, std::greater<std::pair<T, int>>> que;\n\
    \    que.emplace(0, s);\n    while (!que.empty()) {\n        T c = que.top().first;\n\
    \        int v = que.top().second;\n        que.pop();\n        if (dist[v] !=\
    \ c) continue;\n        for (const edge<T>& e : G[v]) {\n            if (dist[e.to]\
    \ == -1 || dist[e.to] > c + e.cost) {\n                dist[e.to] = c + e.cost;\n\
    \                que.emplace(dist[e.to], e.to);\n            }\n        }\n  \
    \  }\n    return dist;\n}\n\n/*\n@brief Dijkstra(\u30C0\u30A4\u30AF\u30B9\u30C8\
    \u30E9\u6CD5)\n@docs docs/Dijkstra.md\n*/\n"
  code: "#pragma once\n\n#include \"../template.cpp\"\n#include \"Graph.cpp\"\n\n\
    template<class T> std::vector<T> Dijkstra(const Graph<T>& G, int s = 0) {\n  \
    \  std::vector<T> dist(G.size(), -1);\n    dist[s] = 0;\n    std::priority_queue<std::pair<T,\
    \ int>, std::vector<std::pair<T, int>>, std::greater<std::pair<T, int>>> que;\n\
    \    que.emplace(0, s);\n    while (!que.empty()) {\n        T c = que.top().first;\n\
    \        int v = que.top().second;\n        que.pop();\n        if (dist[v] !=\
    \ c) continue;\n        for (const edge<T>& e : G[v]) {\n            if (dist[e.to]\
    \ == -1 || dist[e.to] > c + e.cost) {\n                dist[e.to] = c + e.cost;\n\
    \                que.emplace(dist[e.to], e.to);\n            }\n        }\n  \
    \  }\n    return dist;\n}\n\n/*\n@brief Dijkstra(\u30C0\u30A4\u30AF\u30B9\u30C8\
    \u30E9\u6CD5)\n@docs docs/Dijkstra.md\n*/"
  dependsOn:
  - template.cpp
  - graph/Graph.cpp
  isVerificationFile: false
  path: graph/Dijkstra.cpp
  requiredBy: []
  timestamp: '2021-11-03 11:15:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_1_A-dijkstra.test.cpp
documentation_of: graph/Dijkstra.cpp
layout: document
redirect_from:
- /library/graph/Dijkstra.cpp
- /library/graph/Dijkstra.cpp.html
title: "Dijkstra(\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5)"
---
## 概要

重み付きグラフに対して単一始点最短経路問題を解くアルゴリズム。

- `vector<T> Dijkstra(Graph<T> G, int s = 0)` :  
重み付きグラフ `G` において、各頂点の `s` からの距離を求める。$O(|E|\log|V|)$。
