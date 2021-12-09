---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/Graph.hpp
    title: Graph-template
  - icon: ':heavy_check_mark:'
    path: graph/other/LowLink.hpp
    title: "Lowlink(\u95A2\u7BC0\u70B9\u30FB\u6A4B\u691C\u51FA)"
  - icon: ':heavy_check_mark:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/two_edge_connected_components.test.cpp
    title: test/yosupo/two_edge_connected_components.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/connected/TwoEdgeConnectedComponents.hpp\"\n\n#line\
    \ 2 \"other/template.hpp\"\n\n#include<bits/stdc++.h>\n\n#ifndef __COUNTER__\n\
    #define __COUNTER__ __LINE__\n#endif\n\n#define REP_SELECTER(a, b, c, d, e, ...)\
    \ e\n#define REP1_0(b, c) REP1_1(b, c)\n#define REP1_1(b, c) for (ll REP_COUNTER_\
    \ ## c = 0; REP_COUNTER_ ## c < (ll)(b); ++ REP_COUNTER_ ## c)\n#define REP1(b)\
    \ REP1_0(b, __COUNTER__)\n#define REP2(i, b) for (ll i = 0; i < (ll)(b); ++i)\n\
    #define REP3(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)\n#define REP4(i,\
    \ a, b, c) for (ll i = (ll)(a); i < (ll)(b); i += (ll)(c))\n#define rep(...) REP_SELECTER(__VA_ARGS__,\
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
    };\n\n#if __cplusplus >= 201402L\ntemplate<class T> constexpr T INF = infinity<T>::value;\n\
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
    \ {\n    return RecLambda<F>(std::forward<F>(f));\n}\n\ntemplate<class T, class\
    \ Arg> constexpr std::vector<T> make_vec(int n, Arg&& arg) {\n    return std::vector<T>(n,\
    \ arg);\n}\ntemplate<class T, class... Args> constexpr auto make_vec(int n, Args&&...\
    \ args)\n        -> std::vector<decltype(make_vec<T>(args...))> {\n    return\
    \ std::vector<decltype(make_vec<T>(args...))>\n               (n, make_vec<T>(std::forward<Args>(args)...));\n\
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
    \ : from(-1), to(-1) {}\n    edge(int t) : from(-1), to(t), cost(1) {}\n    edge(int\
    \ t, T c) : from(-1), to(t), cost(c) {}\n    edge(int f, int t, T c) : from(f),\
    \ to(t), cost(c) {}\n    edge(int f, int t, T c, int i): from(f), to(t), cost(c),\
    \ idx(i) {}\n    operator int() { return to; }\n    friend bool operator<(const\
    \ edge<T>& lhs, const edge<T>& rhs) {\n        return lhs.cost < rhs.cost;\n \
    \   }\n    friend bool operator>(const edge<T>& lhs, const edge<T>& rhs) {\n \
    \       return lhs.cost > rhs.cost;\n    }\n};\n\ntemplate<class T = int> using\
    \ Edges = std::vector<edge<T>>;\ntemplate<class T = int> using GMatrix = std::vector<std::vector<T>>;\n\
    \ntemplate<class T = int> class Graph : public std::vector<std::vector<edge<T>>>\
    \ {\n  protected:\n    int edge_id = 0;\n    using Base = std::vector<std::vector<edge<T>>>;\n\
    \  public:\n    using Base::Base;\n    int edge_size() const { return edge_id;\
    \ }\n    int add_edge(int a, int b, T c, bool is_directed = false){\n        assert(0\
    \ <= a && a < (int)this->size());\n        assert(0 <= b && b < (int)this->size());\n\
    \        (*this)[a].emplace_back(a, b, c, edge_id);\n        if (!is_directed)\
    \ (*this)[b].emplace_back(b, a, c, edge_id);\n        return edge_id++;\n    }\n\
    \    int add_edge(int a, int b, bool is_directed = false){\n        assert(0 <=\
    \ a && a < (int)this->size());\n        assert(0 <= b && b < (int)this->size());\n\
    \        (*this)[a].emplace_back(a, b, 1, edge_id);\n        if (!is_directed)\
    \ (*this)[b].emplace_back(b, a, 1, edge_id);\n        return edge_id++;\n    }\n\
    };\n\ntemplate<class T> GMatrix<T> ListToMatrix(const Graph<T>& G) {\n    const\
    \ int N = G.size();\n    auto res = make_vec<T>(N, N, infinity<T>::value);\n \
    \   rep (i, N) res[i][i] = 0;\n    rep (i, N) {\n        for (const edge<T>& e\
    \ : G[i]) res[i][e.to] = e.cost;\n    }\n    return res;\n}\n\ntemplate<class\
    \ T> Edges<T> ListToUndirectedEdges(const Graph<T>& G) {\n    const int V = G.size();\n\
    \    const int E = G.edge_size();\n    Edges<T> Ed(E);\n    rep (i, V) {\n   \
    \     for (const edge<T>& e : G[i]) Ed[e.idx] = e;\n    }\n    return Ed;\n}\n\
    template<class T> Edges<T> ListToDirectedEdges(const Graph<T>& G) {\n    const\
    \ int V = G.size();\n    const int E = std::accumulate(all(G), 0, [](int a, const\
    \ Edges<T>& b) -> int { return a + b.size(); });\n    Edges<T> Ed(G.edge_size());\n\
    \    Ed.reserve(E);\n    rep (i, V) {\n        for (const edge<T>& e : G[i]) {\n\
    \            if (Ed[e.idx].to == -1) Ed[e.idx] = e;\n            else Ed.push_back(e);\n\
    \        }\n    }\n    return Ed;\n}\n\ntemplate<class T> Graph<T> ReverseGraph(const\
    \ Graph<T>& G) {\n    const int V = G.size();\n    Graph<T> RG(V);\n    for (const\
    \ edge<T>& e : ListToUndirectedEdges(G)) {\n        RG.add_edge(e.to, e.from,\
    \ e.cost, true);\n    }\n    return RG;\n}\n\n/**\n * @brief Graph-template\n\
    \ * @docs docs/Graph.md\n */\n#line 2 \"graph/other/LowLink.hpp\"\n\n#line 4 \"\
    graph/other/LowLink.hpp\"\n\ntemplate<class T> class LowLink {\n  protected:\n\
    \    int n, cnt;\n    Graph<T> G;\n    std::vector<int> ord, low;\n    std::vector<int>\
    \ aps;\n    Edges<T> brd;\n    void dfs(int v, int p) {\n        low[v] = ord[v]\
    \ = cnt++;\n        int deg = 0;\n        bool is_ap = false, mul = false;\n \
    \       for (const edge<T>& e : G[v]) {\n            if (e.to == p && !mul) {\n\
    \                mul = true;\n                continue;\n            }\n     \
    \       if (ord[e.to] != -1) chmin(low[v], ord[e.to]);\n            else {\n \
    \               dfs(e.to, v);\n                chmin(low[v], low[e.to]);\n   \
    \             if (p != -1 && ord[v] <= low[e.to]) is_ap = true;\n            \
    \    if (ord[v] < low[e.to]) brd.push_back(e);\n                ++deg;\n     \
    \       }\n        }\n        if (p == -1 && deg > 1) is_ap = true;\n        if\
    \ (is_ap) aps.push_back(v);\n    }\n  public:\n    LowLink() = default;\n    LowLink(const\
    \ Graph<T>& G_) { init(G_); }\n    void init(const Graph<T>& G_) {\n        G\
    \ = G_;\n        n = G.size();\n        ord.assign(n, -1); low.assign(n, n + 1);\n\
    \        cnt = 0;\n        rep (i, n) {\n            if (ord[i] == -1) dfs(i,\
    \ -1);\n        }\n    }\n    std::vector<int> articulation_points() const { return\
    \ aps; }\n    Edges<T> bridges() const { return brd; }\n};\n\n/**\n * @brief Lowlink(\u95A2\
    \u7BC0\u70B9\u30FB\u6A4B\u691C\u51FA)\n * @docs docs/LowLink.md\n */\n#line 6\
    \ \"graph/connected/TwoEdgeConnectedComponents.hpp\"\n\ntemplate<class T> class\
    \ TwoEdgeConnectedComponents : protected LowLink<T> {\n  protected:\n    int sz;\n\
    \    std::vector<int> cmp;\n    void dcmp(int v) {\n        for (const edge<T>&\
    \ e : this->G[v]) {\n            if (cmp[e.to] != -1) continue;\n            if\
    \ (this->ord[v] < this->low[e.to] || this->ord[e.to] < this->low[v]) continue;\n\
    \            cmp[e.to] = cmp[v];\n            dcmp(e.to);\n        }\n    }\n\
    \  public:\n    TwoEdgeConnectedComponents() = default;\n    TwoEdgeConnectedComponents(const\
    \ Graph<T>& G_) { init(G_); }\n    void init(const Graph<T>& G_) {\n        LowLink<T>::init(G_);\n\
    \        sz = 0;\n        cmp.assign(this->n, -1);\n        rep (i, this->n) {\n\
    \            if (cmp[i] == -1) {\n                cmp[i] = sz++;\n           \
    \     dcmp(i);\n            }\n        }\n    }\n    int size() const { return\
    \ sz; }\n    int operator[](int k) const { return cmp[k]; }\n    std::vector<std::vector<int>>\
    \ groups() const {\n        std::vector<std::vector<int>> res(sz);\n        rep\
    \ (i, this->n) res[cmp[i]].push_back(i);\n        return res;\n    }\n    Graph<T>\
    \ tree() const {\n        Graph<T> res(sz);\n        for (const edge<T>& e : this->brd)\
    \ {\n            res.add_edge(cmp[e.from], cmp[e.to], e.cost);\n        }\n  \
    \      return res;\n    }\n};\n"
  code: "#pragma once\n\n#include \"../../other/template.hpp\"\n#include \"../Graph.hpp\"\
    \n#include \"../other/LowLink.hpp\"\n\ntemplate<class T> class TwoEdgeConnectedComponents\
    \ : protected LowLink<T> {\n  protected:\n    int sz;\n    std::vector<int> cmp;\n\
    \    void dcmp(int v) {\n        for (const edge<T>& e : this->G[v]) {\n     \
    \       if (cmp[e.to] != -1) continue;\n            if (this->ord[v] < this->low[e.to]\
    \ || this->ord[e.to] < this->low[v]) continue;\n            cmp[e.to] = cmp[v];\n\
    \            dcmp(e.to);\n        }\n    }\n  public:\n    TwoEdgeConnectedComponents()\
    \ = default;\n    TwoEdgeConnectedComponents(const Graph<T>& G_) { init(G_); }\n\
    \    void init(const Graph<T>& G_) {\n        LowLink<T>::init(G_);\n        sz\
    \ = 0;\n        cmp.assign(this->n, -1);\n        rep (i, this->n) {\n       \
    \     if (cmp[i] == -1) {\n                cmp[i] = sz++;\n                dcmp(i);\n\
    \            }\n        }\n    }\n    int size() const { return sz; }\n    int\
    \ operator[](int k) const { return cmp[k]; }\n    std::vector<std::vector<int>>\
    \ groups() const {\n        std::vector<std::vector<int>> res(sz);\n        rep\
    \ (i, this->n) res[cmp[i]].push_back(i);\n        return res;\n    }\n    Graph<T>\
    \ tree() const {\n        Graph<T> res(sz);\n        for (const edge<T>& e : this->brd)\
    \ {\n            res.add_edge(cmp[e.from], cmp[e.to], e.cost);\n        }\n  \
    \      return res;\n    }\n};\n"
  dependsOn:
  - other/template.hpp
  - graph/Graph.hpp
  - graph/other/LowLink.hpp
  isVerificationFile: false
  path: graph/connected/TwoEdgeConnectedComponents.hpp
  requiredBy: []
  timestamp: '2021-12-09 12:12:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/two_edge_connected_components.test.cpp
documentation_of: graph/connected/TwoEdgeConnectedComponents.hpp
layout: document
redirect_from:
- /library/graph/connected/TwoEdgeConnectedComponents.hpp
- /library/graph/connected/TwoEdgeConnectedComponents.hpp.html
title: graph/connected/TwoEdgeConnectedComponents.hpp
---
