---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/Graph.hpp
    title: Graph-template
  - icon: ':question:'
    path: other/bitop.hpp
    title: other/bitop.hpp
  - icon: ':question:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/GRL/GRL_5_C-LCA.test.cpp
    title: test/aoj/GRL/GRL_5_C-LCA.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/DoublingLowestCommonAncestor.md
    document_title: "DoublingLowestCommonAncestor(\u30C0\u30D6\u30EA\u30F3\u30B0\u306B\
      \u3088\u308BLCA)"
    links: []
  bundledCode: "#line 2 \"graph/tree/DoublingLowestCommonAncestor.hpp\"\n\n#line 2\
    \ \"other/template.hpp\"\n\n#include<bits/stdc++.h>\n\n#ifndef __COUNTER__\n#define\
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
    }\n\ntemplate<class T> class presser {\n  private:\n    using Cont = std::vector<T>;\n\
    \    Cont data;\n    bool sorted = false;\n  public:\n    presser() = default;\n\
    \    presser(const std::vector<T>& vec) : data(vec) {}\n    presser(std::vector<T>&&\
    \ vec) : data(std::move(vec)) {}\n    void reserve(int n) {\n        assert(!sorted);\n\
    \        data.reserve(n);\n    }\n    void push_back(const T& v) {\n        assert(!sorted);\n\
    \        data.push_back(v);\n    }\n    void push_back(T&& v) {\n        assert(!sorted);\n\
    \        data.push_back(std::move(v));\n    }\n    void push(const std::vector<T>&\
    \ vec) {\n        assert(!sorted);\n        data.reserve(data.size() + vec.size());\n\
    \        std::copy(all(vec), std::back_inserter(data));\n    }\n    int build()\
    \ {\n        assert(!sorted);\n        sorted = true;\n        std::sort(all(data));\n\
    \        data.erase(std::unique(all(data)), data.end());\n        return data.size();\n\
    \    }\n    int get_index(const T& val) const {\n        assert(sorted);\n   \
    \     return static_cast<int>(std::lower_bound(all(data), val) - data.begin());\n\
    \    }\n    std::vector<int> pressed(const std::vector<T>& vec) const {\n    \
    \    assert(sorted);\n        std::vector<int> res(vec.size());\n        rep (i,\
    \ vec.size()) res[i] = get_index(vec[i]);\n        return res;\n    }\n    void\
    \ press(std::vector<T>& vec) const {\n        assert(sorted);\n        static_assert(std::is_integral<T>::value,\
    \ \"cannot convert from int type\");\n        rep (i, vec.size()) vec[i] = get_index(vec[i]);\n\
    \    }\n    int size() const {\n        assert(sorted);\n        return data.size();\n\
    \    }\n};\n#line 2 \"other/bitop.hpp\"\n\n#line 4 \"other/bitop.hpp\"\n\nnamespace\
    \ bitop {\n\n#define KTH_BIT(b, k) (((b) >> (k)) & 1)\n#define POW2(k) (1ull <<\
    \ (k))\n\n    inline ull next_combination(int n, ull x) {\n        if (n == 0)\
    \ return 1;\n        ull a = x & -x;\n        ull b = x + a;\n        return (x\
    \ & ~b) / a >> 1 | b;\n    }\n\n#define rep_comb(i, n, k) for (ull i = (1ull <<\
    \ (k)) - 1; i < (1ull << (n)); i = bitop::next_combination((n), i))\n\n    inline\
    \ CONSTEXPR int msb(ull x) {\n        int res = x ? 0 : -1;\n        if (x & 0xFFFFFFFF00000000)\
    \ x &= 0xFFFFFFFF00000000, res += 32;\n        if (x & 0xFFFF0000FFFF0000) x &=\
    \ 0xFFFF0000FFFF0000, res += 16;\n        if (x & 0xFF00FF00FF00FF00) x &= 0xFF00FF00FF00FF00,\
    \ res +=  8;\n        if (x & 0xF0F0F0F0F0F0F0F0) x &= 0xF0F0F0F0F0F0F0F0, res\
    \ +=  4;\n        if (x & 0xCCCCCCCCCCCCCCCC) x &= 0xCCCCCCCCCCCCCCCC, res +=\
    \  2;\n        return res + ((x & 0xAAAAAAAAAAAAAAAA) ? 1 : 0);\n    }\n\n   \
    \ inline CONSTEXPR int ceil_log2(ull x) {\n        return x ? msb(x - 1) + 1 :\
    \ 0;\n    }\n}\n#line 2 \"graph/Graph.hpp\"\n\n#line 4 \"graph/Graph.hpp\"\n\n\
    template<class T = int> struct edge {\n    int from, to;\n    T cost;\n    int\
    \ idx;\n    edge() : from(-1), to(-1) {}\n    edge(int f, int t, const T& c =\
    \ 1, int i = -1) : from(f), to(t), cost(c), idx(i) {}\n    operator int() const\
    \ { return to; }\n    friend bool operator<(const edge<T>& lhs, const edge<T>&\
    \ rhs) {\n        return lhs.cost < rhs.cost;\n    }\n    friend bool operator>(const\
    \ edge<T>& lhs, const edge<T>& rhs) {\n        return lhs.cost > rhs.cost;\n \
    \   }\n};\n\ntemplate<class T = int> using Edges = std::vector<edge<T>>;\ntemplate<class\
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
    \        }\n    }\n    res.edge_id = G.edge_size();\n    return res;\n}\n\n\n\
    struct unweighted_edge {\n    template<class... Args> unweighted_edge(const Args&...)\
    \ {}\n    operator int() { return 1; }\n};\n\nusing UnweightedGraph = Graph<unweighted_edge>;\n\
    \n/**\n * @brief Graph-template\n * @docs docs/Graph.md\n */\n#line 6 \"graph/tree/DoublingLowestCommonAncestor.hpp\"\
    \n\ntemplate<class T> class DoublingLCA {\n  protected:\n    int root, n, h;\n\
    \    Graph<T> G_;\n    const Graph<T>& G;\n    std::vector<edge<T>> par;\n   \
    \ std::vector<int> dep;\n    std::vector<std::vector<int>> dbl;\n    void dfs_build(int\
    \ v, int p) {\n        for (const edge<T>& e : G[v]) {\n            if (e.to !=\
    \ p) {\n                par[e.to] = edge<T>(e.to, e.from, e.cost, e.idx);\n  \
    \              dep[e.to] = dep[v] + 1;\n                dfs_build(e.to, v);\n\
    \            }\n        }\n    }\n    void init() {\n        n = G.size();\n \
    \       h = bitop::ceil_log2(n) + 1;\n        par.resize(n); par[root] = edge<T>{};\n\
    \        dep.resize(n); dep[root] = 0;\n        dfs_build(root, -1);\n       \
    \ dbl.assign(n, std::vector<int>(h, -1));\n        rep (i, n) dbl[i][0] = par[i].to;\n\
    \        rep (i, h - 1) {\n            rep (j, n) dbl[j][i + 1] = dbl[j][i] ==\
    \ -1 ? -1 : dbl[ dbl[j][i] ][i];\n        }\n    }\n  public:\n    DoublingLCA(const\
    \ Graph<T>& G, int r = 0) : root(r), G(G)  { init(); }\n    DoublingLCA(Graph<T>&&\
    \ G, int r = 0) : root(r), G_(std::move(G)), G(G_) { init(); }\n    int depth(int\
    \ v) const { return dep[v]; }\n    int parent(int v) const { return par[v].to;\
    \ }\n    int kth_ancestor(int v, int k) const {\n        if (dep[v] < k) return\
    \ -1;\n        rrep (i, h) {\n            if ((k >> i) & 1) v = dbl[v][i];\n \
    \       }\n        return v;\n    }\n    Edges<T> path(int s, int t) const {\n\
    \        Edges<T> pre, suf;\n        while (dep[s] > dep[t]) pre.push_back(par[s]),\
    \ s = par[s].to;\n        while (dep[t] > dep[s]) suf.push_back(par[t]), t = par[t].to;\n\
    \        while (s != t) {\n            pre.push_back(par[s]), s = par[s].to;\n\
    \            suf.push_back(par[t]), t = par[t].to;\n        }\n        rrep (i,\
    \ suf.size()) pre.emplace_back(suf[i].to, suf[i].from, suf[i].cost, suf[i].idx);\n\
    \        return pre;\n    }\n    int lca(int u, int v) const {\n        if (dep[u]\
    \ > dep[v]) u = kth_ancestor(u, dep[u] - dep[v]);\n        if (dep[u] < dep[v])\
    \ v = kth_ancestor(v, dep[v] - dep[u]);\n        if (u == v) return u;\n     \
    \   rrep (i, h) {\n            if (dbl[u][i] != dbl[v][i]) {\n               \
    \ u = dbl[u][i];\n                v = dbl[v][i];\n            }\n        }\n \
    \       return parent(u);\n    }\n};\n\n/**\n * @brief DoublingLowestCommonAncestor(\u30C0\
    \u30D6\u30EA\u30F3\u30B0\u306B\u3088\u308BLCA)\n * @docs docs/DoublingLowestCommonAncestor.md\n\
    \ */\n"
  code: "#pragma once\n\n#include \"../../other/template.hpp\"\n#include \"../../other/bitop.hpp\"\
    \n#include \"../Graph.hpp\"\n\ntemplate<class T> class DoublingLCA {\n  protected:\n\
    \    int root, n, h;\n    Graph<T> G_;\n    const Graph<T>& G;\n    std::vector<edge<T>>\
    \ par;\n    std::vector<int> dep;\n    std::vector<std::vector<int>> dbl;\n  \
    \  void dfs_build(int v, int p) {\n        for (const edge<T>& e : G[v]) {\n \
    \           if (e.to != p) {\n                par[e.to] = edge<T>(e.to, e.from,\
    \ e.cost, e.idx);\n                dep[e.to] = dep[v] + 1;\n                dfs_build(e.to,\
    \ v);\n            }\n        }\n    }\n    void init() {\n        n = G.size();\n\
    \        h = bitop::ceil_log2(n) + 1;\n        par.resize(n); par[root] = edge<T>{};\n\
    \        dep.resize(n); dep[root] = 0;\n        dfs_build(root, -1);\n       \
    \ dbl.assign(n, std::vector<int>(h, -1));\n        rep (i, n) dbl[i][0] = par[i].to;\n\
    \        rep (i, h - 1) {\n            rep (j, n) dbl[j][i + 1] = dbl[j][i] ==\
    \ -1 ? -1 : dbl[ dbl[j][i] ][i];\n        }\n    }\n  public:\n    DoublingLCA(const\
    \ Graph<T>& G, int r = 0) : root(r), G(G)  { init(); }\n    DoublingLCA(Graph<T>&&\
    \ G, int r = 0) : root(r), G_(std::move(G)), G(G_) { init(); }\n    int depth(int\
    \ v) const { return dep[v]; }\n    int parent(int v) const { return par[v].to;\
    \ }\n    int kth_ancestor(int v, int k) const {\n        if (dep[v] < k) return\
    \ -1;\n        rrep (i, h) {\n            if ((k >> i) & 1) v = dbl[v][i];\n \
    \       }\n        return v;\n    }\n    Edges<T> path(int s, int t) const {\n\
    \        Edges<T> pre, suf;\n        while (dep[s] > dep[t]) pre.push_back(par[s]),\
    \ s = par[s].to;\n        while (dep[t] > dep[s]) suf.push_back(par[t]), t = par[t].to;\n\
    \        while (s != t) {\n            pre.push_back(par[s]), s = par[s].to;\n\
    \            suf.push_back(par[t]), t = par[t].to;\n        }\n        rrep (i,\
    \ suf.size()) pre.emplace_back(suf[i].to, suf[i].from, suf[i].cost, suf[i].idx);\n\
    \        return pre;\n    }\n    int lca(int u, int v) const {\n        if (dep[u]\
    \ > dep[v]) u = kth_ancestor(u, dep[u] - dep[v]);\n        if (dep[u] < dep[v])\
    \ v = kth_ancestor(v, dep[v] - dep[u]);\n        if (u == v) return u;\n     \
    \   rrep (i, h) {\n            if (dbl[u][i] != dbl[v][i]) {\n               \
    \ u = dbl[u][i];\n                v = dbl[v][i];\n            }\n        }\n \
    \       return parent(u);\n    }\n};\n\n/**\n * @brief DoublingLowestCommonAncestor(\u30C0\
    \u30D6\u30EA\u30F3\u30B0\u306B\u3088\u308BLCA)\n * @docs docs/DoublingLowestCommonAncestor.md\n\
    \ */\n"
  dependsOn:
  - other/template.hpp
  - other/bitop.hpp
  - graph/Graph.hpp
  isVerificationFile: false
  path: graph/tree/DoublingLowestCommonAncestor.hpp
  requiredBy: []
  timestamp: '2022-02-02 23:52:46+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/GRL/GRL_5_C-LCA.test.cpp
documentation_of: graph/tree/DoublingLowestCommonAncestor.hpp
layout: document
redirect_from:
- /library/graph/tree/DoublingLowestCommonAncestor.hpp
- /library/graph/tree/DoublingLowestCommonAncestor.hpp.html
title: "DoublingLowestCommonAncestor(\u30C0\u30D6\u30EA\u30F3\u30B0\u306B\u3088\u308B\
  LCA)"
---
## 概要

木に対してダブリングによって LCA などを求める。空間計算量は $\Theta(E + V \log V)$ であるため注意。

- `DoublingLCA(Graph<T> G, int r = 0)` : 頂点 `r` を根としてグラフ `G` で初期化する。ここで、 `G` は木である必要がある。 $\Theta(V \log V)$ 。
- `int depth(int v)` : 頂点 `v` の深さ(根からの距離)を返す。 $\Theta(1)$ 。
- `int parent(int v)` : 頂点 `v` の親を返す。ただし頂点 `v` が根である場合 $-1$ が返る。 $\Theta(1)$ 。
- `int lca(int s, int t)` : 頂点 `s` と頂点 `t` の最小共通祖先(Lowest Common Ancestor)を返す。 $\Theta(\log V)$ 。
- `int kth_parent(int v, int k)` : 頂点 `v` の `k` 番目に近い祖先を返す。存在しない場合 $-1$ が返る。 $\Theta(\log V)$ 。
- `Edges<T> path(int s, int t)` : 頂点 `s` から頂点 `t` へのパスに含まれる辺を返す。パスの長さを $P$ として $\Theta(P)$ 。
