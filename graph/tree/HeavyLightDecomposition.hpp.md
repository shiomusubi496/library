---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/Graph.hpp
    title: Graph-template
  - icon: ':heavy_check_mark:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL/GRL_5_E-HLD.test.cpp
    title: test/aoj/GRL/GRL_5_E-HLD.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/lca-HLD.test.cpp
    title: test/yosupo/lca-HLD.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertex_add_subtree_sum-HLD.test.cpp
    title: test/yosupo/vertex_add_subtree_sum-HLD.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertex_set_path_composite-HLD.test.cpp
    title: test/yosupo/vertex_set_path_composite-HLD.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/HeavyLightDecomposition.md
    document_title: "HeavyLightDecomposition(HL\u5206\u89E3)"
    links: []
  bundledCode: "#line 2 \"graph/tree/HeavyLightDecomposition.hpp\"\n\n#line 2 \"other/template.hpp\"\
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
    \ }\n};\n#line 2 \"graph/Graph.hpp\"\n\n#line 4 \"graph/Graph.hpp\"\n\ntemplate<class\
    \ T = int> struct edge {\n    int from, to;\n    T cost;\n    int idx;\n    edge()\
    \ : from(-1), to(-1) {}\n    edge(int f, int t, const T& c = 1, int i = -1) :\
    \ from(f), to(t), cost(c), idx(i) {}\n    edge(int f, int t, T&& c, int i = -1)\
    \ : from(f), to(t), cost(std::move(c)), idx(i) {}\n    operator int() const {\
    \ return to; }\n    friend bool operator<(const edge<T>& lhs, const edge<T>& rhs)\
    \ {\n        return lhs.cost < rhs.cost;\n    }\n    friend bool operator>(const\
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
    \ * @docs docs/Graph.md\n */\n#line 5 \"graph/tree/HeavyLightDecomposition.hpp\"\
    \n\ntemplate<class T> class HeavyLightDecomposition {\n  protected:\n    int n,\
    \ root, cnt;\n    std::vector<int> ssz, head, vin, vout, par;\n    const Graph<T>&\
    \ G;\n    int szdfs(int v, int p) {\n        ssz[v] = 1;\n        each_const (e\
    \ : G[v]) {\n            if (e.to == p) continue;\n            ssz[v] += szdfs(e.to,\
    \ v);\n        }\n        return ssz[v];\n    }\n    void bldfs(int v, int p)\
    \ {\n        par[v] = p;\n        vin[v] = cnt++;\n        int idx = -1;\n   \
    \     each_const (e : G[v]) {\n            if (e.to != p) {\n                if\
    \ (idx == -1 || ssz[idx] < ssz[e.to]) idx = e.to;\n            }\n        }\n\
    \        if (idx != -1) {\n            head[idx] = head[v];\n            bldfs(idx,\
    \ v);\n        }\n        each_const (e : G[v]) {\n            if (e.to != p &&\
    \ e.to != idx) {\n                head[e.to] = e.to;\n                bldfs(e.to,\
    \ v);\n            }\n        }\n        vout[v] = cnt;\n    }\n    void init()\
    \ {\n        n = G.size();\n        ssz.assign(n, -1);\n        szdfs(root, -1);\n\
    \        rep (i, n) {\n            if (ssz[i] == -1) szdfs(i, -1);\n        }\n\
    \        cnt = 0;\n        head.assign(n, -1); head[root] = root;\n        vin.resize(n);\
    \ vout.resize(n);\n        par.resize(n);\n        bldfs(root, -1);\n        rep\
    \ (i, n) {\n            if (head[i] == -1) {\n                head[i] = i;\n \
    \               bldfs(i, -1);\n            }\n        }\n    }\n  public:\n  \
    \  HeavyLightDecomposition(const Graph<T>& G, int root = 0) : root(root), G(G)\
    \ { init(); }\n    int get_size(int k) const { return ssz[k]; }\n    std::pair<int,\
    \ int> get_idx(int k) const { return {vin[k], vout[k]}; }\n    std::pair<int,\
    \ int> get_pach(int a, int b) const {\n        if (vin[a] < vin[b]) return {a,\
    \ b};\n        return {b, a};\n    }\n    int lca(int u, int v) const {\n    \
    \    while (head[u] != head[v]) {\n            if (vin[u] > vin[v]) std::swap(u,\
    \ v);\n            v = par[head[v]];\n        }\n        return vin[u] < vin[v]\
    \ ? u : v;\n    }\n    std::vector<std::pair<int, int>> up_path(int u, int v)\
    \ const {\n        std::vector<std::pair<int, int>> res;\n        while (head[u]\
    \ != head[v]) {\n            res.emplace_back(vin[u], vin[head[u]]);\n       \
    \     u = par[head[u]];\n        }\n        if (u != v) res.emplace_back(vin[u],\
    \ vin[v] + 1);\n        return res;\n    }\n    std::vector<std::pair<int, int>>\
    \ down_path(int u, int v) const {\n        auto res = up_path(v, u);\n       \
    \ each_for (p : res) std::swap(p.first, p.second);\n        std::reverse(all(res));\n\
    \        return res;\n    }\n    template<class F> void each_vertex(int u, int\
    \ v, const F& f) const { return each_vertex(u, v, f, f); }\n    template<class\
    \ F, class G> void each_vertex(int u, int v, const F& f, const G& g) const {\n\
    \        int l = lca(u, v);\n        auto func = [&](int a, int b) {\n       \
    \     if (a <= b) f(a, b + 1);\n            else g(b, a + 1);\n        };\n  \
    \      each_const (p : up_path(u, l)) func(p.first, p.second);\n        func(vin[l],\
    \ vin[l]);\n        each_const (p : down_path(l, v)) func(p.first, p.second);\n\
    \    }\n    template<class F> void each_edge(int u, int v, const F& f) const {\
    \ return each_edge(u, v, f, f); }\n    template<class F, class G> void each_edge(int\
    \ u, int v, const F& f, const G& g) const {\n        int l = lca(u, v);\n    \
    \    auto func = [&](int a, int b) {\n            if (a <= b) f(a, b + 1);\n \
    \           else g(b, a + 1);\n        };\n        each_const (p : up_path(u,\
    \ l)) func(p.first, p.second);\n        each_const (p : down_path(l, v)) func(p.first,\
    \ p.second);\n    }\n    template<class F> void each_vertex_subtree(int u, const\
    \ F& f) const {\n        f(vin[u], vout[u]);\n    }\n    template<class F> void\
    \ each_edge_subtree(int u, const F& f) const {\n        f(vin[u] + 1, vout[u]);\n\
    \    }\n};\n\n/**\n * @brief HeavyLightDecomposition(HL\u5206\u89E3)\n * @docs\
    \ docs/HeavyLightDecomposition.md\n */\n"
  code: "#pragma once\n\n#include \"../../other/template.hpp\"\n#include \"../Graph.hpp\"\
    \n\ntemplate<class T> class HeavyLightDecomposition {\n  protected:\n    int n,\
    \ root, cnt;\n    std::vector<int> ssz, head, vin, vout, par;\n    const Graph<T>&\
    \ G;\n    int szdfs(int v, int p) {\n        ssz[v] = 1;\n        each_const (e\
    \ : G[v]) {\n            if (e.to == p) continue;\n            ssz[v] += szdfs(e.to,\
    \ v);\n        }\n        return ssz[v];\n    }\n    void bldfs(int v, int p)\
    \ {\n        par[v] = p;\n        vin[v] = cnt++;\n        int idx = -1;\n   \
    \     each_const (e : G[v]) {\n            if (e.to != p) {\n                if\
    \ (idx == -1 || ssz[idx] < ssz[e.to]) idx = e.to;\n            }\n        }\n\
    \        if (idx != -1) {\n            head[idx] = head[v];\n            bldfs(idx,\
    \ v);\n        }\n        each_const (e : G[v]) {\n            if (e.to != p &&\
    \ e.to != idx) {\n                head[e.to] = e.to;\n                bldfs(e.to,\
    \ v);\n            }\n        }\n        vout[v] = cnt;\n    }\n    void init()\
    \ {\n        n = G.size();\n        ssz.assign(n, -1);\n        szdfs(root, -1);\n\
    \        rep (i, n) {\n            if (ssz[i] == -1) szdfs(i, -1);\n        }\n\
    \        cnt = 0;\n        head.assign(n, -1); head[root] = root;\n        vin.resize(n);\
    \ vout.resize(n);\n        par.resize(n);\n        bldfs(root, -1);\n        rep\
    \ (i, n) {\n            if (head[i] == -1) {\n                head[i] = i;\n \
    \               bldfs(i, -1);\n            }\n        }\n    }\n  public:\n  \
    \  HeavyLightDecomposition(const Graph<T>& G, int root = 0) : root(root), G(G)\
    \ { init(); }\n    int get_size(int k) const { return ssz[k]; }\n    std::pair<int,\
    \ int> get_idx(int k) const { return {vin[k], vout[k]}; }\n    std::pair<int,\
    \ int> get_pach(int a, int b) const {\n        if (vin[a] < vin[b]) return {a,\
    \ b};\n        return {b, a};\n    }\n    int lca(int u, int v) const {\n    \
    \    while (head[u] != head[v]) {\n            if (vin[u] > vin[v]) std::swap(u,\
    \ v);\n            v = par[head[v]];\n        }\n        return vin[u] < vin[v]\
    \ ? u : v;\n    }\n    std::vector<std::pair<int, int>> up_path(int u, int v)\
    \ const {\n        std::vector<std::pair<int, int>> res;\n        while (head[u]\
    \ != head[v]) {\n            res.emplace_back(vin[u], vin[head[u]]);\n       \
    \     u = par[head[u]];\n        }\n        if (u != v) res.emplace_back(vin[u],\
    \ vin[v] + 1);\n        return res;\n    }\n    std::vector<std::pair<int, int>>\
    \ down_path(int u, int v) const {\n        auto res = up_path(v, u);\n       \
    \ each_for (p : res) std::swap(p.first, p.second);\n        std::reverse(all(res));\n\
    \        return res;\n    }\n    template<class F> void each_vertex(int u, int\
    \ v, const F& f) const { return each_vertex(u, v, f, f); }\n    template<class\
    \ F, class G> void each_vertex(int u, int v, const F& f, const G& g) const {\n\
    \        int l = lca(u, v);\n        auto func = [&](int a, int b) {\n       \
    \     if (a <= b) f(a, b + 1);\n            else g(b, a + 1);\n        };\n  \
    \      each_const (p : up_path(u, l)) func(p.first, p.second);\n        func(vin[l],\
    \ vin[l]);\n        each_const (p : down_path(l, v)) func(p.first, p.second);\n\
    \    }\n    template<class F> void each_edge(int u, int v, const F& f) const {\
    \ return each_edge(u, v, f, f); }\n    template<class F, class G> void each_edge(int\
    \ u, int v, const F& f, const G& g) const {\n        int l = lca(u, v);\n    \
    \    auto func = [&](int a, int b) {\n            if (a <= b) f(a, b + 1);\n \
    \           else g(b, a + 1);\n        };\n        each_const (p : up_path(u,\
    \ l)) func(p.first, p.second);\n        each_const (p : down_path(l, v)) func(p.first,\
    \ p.second);\n    }\n    template<class F> void each_vertex_subtree(int u, const\
    \ F& f) const {\n        f(vin[u], vout[u]);\n    }\n    template<class F> void\
    \ each_edge_subtree(int u, const F& f) const {\n        f(vin[u] + 1, vout[u]);\n\
    \    }\n};\n\n/**\n * @brief HeavyLightDecomposition(HL\u5206\u89E3)\n * @docs\
    \ docs/HeavyLightDecomposition.md\n */\n"
  dependsOn:
  - other/template.hpp
  - graph/Graph.hpp
  isVerificationFile: false
  path: graph/tree/HeavyLightDecomposition.hpp
  requiredBy: []
  timestamp: '2022-05-14 15:03:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL/GRL_5_E-HLD.test.cpp
  - test/yosupo/vertex_add_subtree_sum-HLD.test.cpp
  - test/yosupo/lca-HLD.test.cpp
  - test/yosupo/vertex_set_path_composite-HLD.test.cpp
documentation_of: graph/tree/HeavyLightDecomposition.hpp
layout: document
redirect_from:
- /library/graph/tree/HeavyLightDecomposition.hpp
- /library/graph/tree/HeavyLightDecomposition.hpp.html
title: "HeavyLightDecomposition(HL\u5206\u89E3)"
---
## 概要

木に対する様々なクエリを扱える。計算量はオイラーツアーより悪いが、パスに対するクエリや部分木に対するクエリを同時に扱える。

うまく木をいくつかの列に分解することで、パスを $O(\log N)$ 個の列に分割する。

- `HeavyLightDecomposition(Graph<T> G)` : グラフ `G` に大して HL 分解をする。 $\Theta(N)$ 。
- `pair<int, int> get_idx(int v)` : 頂点 `v` に入る index と出る index のペアを返す。 $\Theta(1)$ 。
- `int lca(int v, int u)` : 頂点 `v` と `u` の最小共通祖先(Lowest Common Ancestor)を返す。 StaticRMQ::prod が $\Theta(f(N))$ で動くとき、 $\Theta(f(N))$ 。
- `void each_vertex_subtree(int v, void f(int, int))` : `v` の部分木の頂点に対して `f` を適用する。計算量は `f` のそれに比例。
- `void each_edge_subtree(int v, void f(int, int))` : 同様に辺に対して適用する。
- `void each_vertex(int l, int r, void f(int, int), void g(int, int))` : `l` から `r` までのパスの頂点に対して `f` を適用する。可換でない演算を使う場合、 `g` は逆向きに演算をした場合の結果を返すべき。 `Monoid::ReverseMonoid` を活用する。 `f` が $\Theta(t)$ で動く場合、計算量 $\Theta(t \log N)$ 。
- `void each_edge(int l, int r, void f(int, int), void g(int, int))` : 同様に辺に対して適用する。
