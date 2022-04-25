---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/Graph.hpp
    title: Graph-template
  - icon: ':heavy_check_mark:'
    path: graph/shortest-path/BellmanFord.hpp
    title: "Bellman-Ford(\u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\u6CD5)"
  - icon: ':question:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_B
  bundledCode: "#line 1 \"test/aoj/GRL/GRL_1_B-BellmanFord.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_B\"\n#line 2 \"other/template.hpp\"\
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
    \ Tail> struct multi_dim_vector {\n    using type = std::vector<typename multi_dim_vector<Tail...>::type>;\n\
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
    }\n\ntemplate<class T, class Comp = std::less<T>> class presser {\n  protected:\n\
    \    std::vector<T> dat;\n    Comp cmp;\n    bool sorted = false;\n  public:\n\
    \    presser() : presser(Comp()) {}\n    presser(const Comp& cmp) : cmp(cmp) {}\n\
    \    presser(const std::vector<T>& vec, const Comp& cmp = Comp()) : dat(vec),\
    \ cmp(cmp) {}\n    presser(std::vector<T>&& vec, const Comp& cmp = Comp()) : dat(std::move(vec)),\
    \ cmp(cmp) {}\n    presser(std::initializer_list<T> il, const Comp& cmp = Comp())\
    \ : dat(il.begin(), il.end()), cmp(cmp) {}\n    void reserve(int n) {\n      \
    \  assert(!sorted);\n        dat.reserve(n);\n    }\n    void push_back(const\
    \ T& v) {\n        assert(!sorted);\n        dat.push_back(v);\n    }\n    void\
    \ push_back(T&& v) {\n        assert(!sorted);\n        dat.push_back(std::move(v));\n\
    \    }\n    void push(const std::vector<T>& vec) {\n        assert(!sorted);\n\
    \        dat.reserve(dat.size() + vec.size());\n        std::copy(all(vec), std::back_inserter(dat));\n\
    \    }\n    int build() {\n        assert(!sorted); sorted = true;\n        std::sort(all(dat),\
    \ cmp);\n        dat.erase(std::unique(all(dat), [&](const T& a, const T& b) ->\
    \ bool {\n            return !cmp(a, b) && !cmp(b, a);\n        }), dat.end());\n\
    \        return dat.size();\n    }\n    const T& operator[](int k) const& {\n\
    \        assert(sorted);\n        assert(0 <= k && k < (int)dat.size());\n   \
    \     return dat[k];\n    }\n    T operator[](int k) && {\n        assert(sorted);\n\
    \        assert(0 <= k && k < (int)dat.size());\n        return std::move(dat[k]);\n\
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
    \ }\n};\n#line 2 \"graph/Graph.hpp\"\n\n#line 4 \"graph/Graph.hpp\"\n\ntemplate<class\
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
    \   rep (i, N) res[i][i] = 0;\n    rep (i, N) {\n        each_const (e : G[i])\
    \ res[i][e.to] = e.cost;\n    }\n    return res;\n}\n\ntemplate<class T> Edges<T>\
    \ UndirectedListToEdges(const Graph<T>& G) {\n    const int V = G.size();\n  \
    \  const int E = G.edge_size();\n    Edges<T> Ed(E);\n    rep (i, V) {\n     \
    \   each_const (e : G[i]) Ed[e.idx] = e;\n    }\n    return Ed;\n}\n\ntemplate<class\
    \ T> Edges<T> DirectedListToEdges(const Graph<T>& G) {\n    const int V = G.size();\n\
    \    const int E = std::accumulate(\n        all(G), 0,\n        [](int a, const\
    \ std::vector<edge<T>>& v) -> int { return a + v.size(); }\n    );\n    Edges<T>\
    \ Ed(G.edge_size()); Ed.reserve(E);\n    rep (i, V) {\n        each_const (e :\
    \ G[i]) {\n            if (Ed[e.idx] == -1) Ed[e.idx] = e;\n            else Ed.push_back(e);\n\
    \        }\n    }\n    return Ed;\n}\n\ntemplate<class T> Graph<T> ReverseGraph(const\
    \ Graph<T>& G) {\n    const int V = G.size();\n    Graph<T> res(V);\n    rep (i,\
    \ V) {\n        each_const (e : G[i]) {\n            res[e.to].emplace_back(e.to,\
    \ e.from, e.cost, e.idx);\n        }\n    }\n    res.edge_id = G.edge_size();\n\
    \    return res;\n}\n\n\nstruct unweighted_edge {\n    template<class... Args>\
    \ unweighted_edge(const Args&...) {}\n    operator int() { return 1; }\n};\n\n\
    using UnweightedGraph = Graph<unweighted_edge>;\n\n/**\n * @brief Graph-template\n\
    \ * @docs docs/Graph.md\n */\n#line 2 \"graph/shortest-path/BellmanFord.hpp\"\n\
    \n#line 5 \"graph/shortest-path/BellmanFord.hpp\"\n\ntemplate<class T> std::vector<T>\
    \ BellmanFord(int V, const Edges<T>& Ed, int start = 0) {\n    assert(0 <= start\
    \ && start <= V);\n    std::vector<T> dist(V, infinity<T>::value); dist[start]\
    \ = 0;\n    rep (i, V) {\n        bool changed = false;\n        each_const (e\
    \ : Ed) {\n            if (dist[e.from] != infinity<T>::value && chmin(dist[e.to],\
    \ dist[e.from] + e.cost)) changed = true;\n        }\n        if (!changed) return\
    \ dist;\n    }\n    each_const (e : Ed) {\n        if (dist[e.from] != infinity<T>::value\
    \ && dist[e.to] > dist[e.from] + e.cost) dist[e.to] = -infinity<T>::value;\n \
    \   }\n    rep (i, V - 1) {\n        bool changed = false;\n        each_const\
    \ (e : Ed) {\n            if (dist[e.from] == -infinity<T>::value) {\n       \
    \         dist[e.to] = -infinity<T>::value;\n                changed = true;\n\
    \            }\n        }\n        if (!changed) break;\n    }\n    return dist;\n\
    }\n\n/**\n * @brief Bellman-Ford(\u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\
    \u6CD5)\n * @docs docs/BellmanFord.md\n */\n#line 5 \"test/aoj/GRL/GRL_1_B-BellmanFord.test.cpp\"\
    \nusing namespace std;\nint main() {\n    int V, E, r; cin >> V >> E >> r;\n \
    \   Edges<int> Ed(E);\n    each_for (e : Ed) cin >> e.from >> e.to >> e.cost;\n\
    \    auto dist = BellmanFord(V, Ed, r);\n    if (count(all(dist), -infinity<int>::value))\
    \ {\n        puts(\"NEGATIVE CYCLE\");\n        return 0;\n    }\n    rep (i,\
    \ V) {\n        if (dist[i] == infinity<int>::value) puts(\"INF\");\n        else\
    \ cout << dist[i] << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_B\"\n#include\
    \ \"../../../other/template.hpp\"\n#include \"../../../graph/Graph.hpp\"\n#include\
    \ \"../../../graph/shortest-path/BellmanFord.hpp\"\nusing namespace std;\nint\
    \ main() {\n    int V, E, r; cin >> V >> E >> r;\n    Edges<int> Ed(E);\n    each_for\
    \ (e : Ed) cin >> e.from >> e.to >> e.cost;\n    auto dist = BellmanFord(V, Ed,\
    \ r);\n    if (count(all(dist), -infinity<int>::value)) {\n        puts(\"NEGATIVE\
    \ CYCLE\");\n        return 0;\n    }\n    rep (i, V) {\n        if (dist[i] ==\
    \ infinity<int>::value) puts(\"INF\");\n        else cout << dist[i] << endl;\n\
    \    }\n}"
  dependsOn:
  - other/template.hpp
  - graph/Graph.hpp
  - graph/shortest-path/BellmanFord.hpp
  isVerificationFile: true
  path: test/aoj/GRL/GRL_1_B-BellmanFord.test.cpp
  requiredBy: []
  timestamp: '2022-02-27 15:19:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL/GRL_1_B-BellmanFord.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL/GRL_1_B-BellmanFord.test.cpp
- /verify/test/aoj/GRL/GRL_1_B-BellmanFord.test.cpp.html
title: test/aoj/GRL/GRL_1_B-BellmanFord.test.cpp
---
