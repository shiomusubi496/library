---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/Graph.hpp
    title: Graph-template
  - icon: ':x:'
    path: graph/tree/DoublingLowestCommonAncestor.hpp
    title: "DoublingLowestCommonAncestor(\u30C0\u30D6\u30EA\u30F3\u30B0\u306B\u3088\
      \u308BLCA)"
  - icon: ':question:'
    path: other/bitop.hpp
    title: other/bitop.hpp
  - icon: ':question:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C
  bundledCode: "#line 1 \"test/aoj/GRL/GRL_5_C-LCA.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C\"\n#line 2 \"other/template.hpp\"\
    \n\n#include <bits/stdc++.h>\n\n#ifndef __COUNTER__\n#define __COUNTER__ __LINE__\n\
    #endif\n\n#define REP_SELECTER(a, b, c, d, e, ...) e\n#define REP1_0(b, c) REP1_1(b,\
    \ c)\n#define REP1_1(b, c)                                                   \
    \        \\\n    for (ll REP_COUNTER_##c = 0; REP_COUNTER_##c < (ll)(b); ++REP_COUNTER_##c)\n\
    #define REP1(b) REP1_0(b, __COUNTER__)\n#define REP2(i, b) for (ll i = 0; i <\
    \ (ll)(b); ++i)\n#define REP3(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)\n\
    #define REP4(i, a, b, c) for (ll i = (ll)(a); i < (ll)(b); i += (ll)(c))\n#define\
    \ rep(...) REP_SELECTER(__VA_ARGS__, REP4, REP3, REP2, REP1)(__VA_ARGS__)\n#define\
    \ RREP2(i, a) for (ll i = (ll)(a)-1; i >= 0; --i)\n#define RREP3(i, a, b) for\
    \ (ll i = (ll)(a)-1; i >= (ll)(b); --i)\n#define RREP4(i, a, b, c) for (ll i =\
    \ (ll)(a)-1; i >= (ll)(b); i -= (ll)(c))\n#define rrep(...) REP_SELECTER(__VA_ARGS__,\
    \ RREP4, RREP3, RREP2)(__VA_ARGS__)\n#define REPS2(i, b) for (ll i = 1; i <= (ll)(b);\
    \ ++i)\n#define REPS3(i, a, b) for (ll i = (ll)(a) + 1; i <= (ll)(b); ++i)\n#define\
    \ REPS4(i, a, b, c) for (ll i = (ll)(a) + 1; i <= (ll)(b); i += (ll)(c))\n#define\
    \ reps(...) REP_SELECTER(__VA_ARGS__, REPS4, REPS3, REPS2)(__VA_ARGS__)\n#define\
    \ RREPS2(i, a) for (ll i = (ll)(a); i > 0; --i)\n#define RREPS3(i, a, b) for (ll\
    \ i = (ll)(a); i > (ll)(b); --i)\n#define RREPS4(i, a, b, c) for (ll i = (ll)(a);\
    \ i > (ll)(b); i -= (ll)(c))\n#define rreps(...)                             \
    \                                \\\n    REP_SELECTER(__VA_ARGS__, RREPS4, RREPS3,\
    \ RREPS2)(__VA_ARGS__)\n\n#define each_for(...) for (auto&& __VA_ARGS__)\n#define\
    \ each_const(...) for (const auto& __VA_ARGS__)\n\n#define all(v) std::begin(v),\
    \ std::end(v)\n#define rall(v) std::rbegin(v), std::rend(v)\n\n#if __cpp_constexpr\
    \ >= 201304L\n#define CONSTEXPR constexpr\n#else\n#define CONSTEXPR\n#endif\n\n\
    #if __cpp_if_constexpr >= 201606L\n#define IF_CONSTEXPR constexpr\n#else\n#define\
    \ IF_CONSTEXPR\n#endif\n\nusing ll = long long;\nusing ull = unsigned long long;\n\
    using ld = long double;\nusing PLL = std::pair<ll, ll>;\ntemplate<class T>\nusing\
    \ prique = std::priority_queue<T, std::vector<T>, std::greater<T>>;\n\ntemplate<class\
    \ T> class infinity {\npublic:\n    static constexpr T value = std::numeric_limits<T>::max()\
    \ / 2;\n    static constexpr T mvalue = std::numeric_limits<T>::min() / 2;\n \
    \   static constexpr T max = std::numeric_limits<T>::max();\n    static constexpr\
    \ T min = std::numeric_limits<T>::min();\n};\n\n#if __cplusplus <= 201402L\ntemplate<class\
    \ T> constexpr T infinity<T>::value;\ntemplate<class T> constexpr T infinity<T>::mvalue;\n\
    template<class T> constexpr T infinity<T>::max;\ntemplate<class T> constexpr T\
    \ infinity<T>::min;\n#endif\n\n#if __cpp_variable_templates >= 201304L\ntemplate<class\
    \ T> constexpr T INF = infinity<T>::value;\n#endif\n\nconstexpr ll inf = infinity<ll>::value;\n\
    constexpr ld EPS = 1e-8;\nconstexpr ld PI = 3.1415926535897932384626;\n\ntemplate<class\
    \ T, class U>\nstd::ostream& operator<<(std::ostream& ost, const std::pair<T,\
    \ U>& p) {\n    return ost << p.first << ' ' << p.second;\n}\ntemplate<class T,\
    \ class U>\nstd::istream& operator>>(std::istream& ist, std::pair<T, U>& p) {\n\
    \    return ist >> p.first >> p.second;\n}\n\ntemplate<class Container, typename\
    \ std::enable_if<!std::is_same<\n                              Container, std::string>::value>::type*\
    \ = nullptr>\nauto operator<<(std::ostream& ost, const Container& cont)\n    ->\
    \ decltype(cont.begin(), cont.end(), ost) {\n    for (auto itr = cont.begin();\
    \ itr != cont.end(); ++itr) {\n        if (itr != cont.begin()) ost << ' ';\n\
    \        ost << *itr;\n    }\n    return ost;\n}\ntemplate<class Container, typename\
    \ std::enable_if<!std::is_same<\n                              Container, std::string>::value>::type*\
    \ = nullptr>\nauto operator>>(std::istream& ist, Container& cont)\n    -> decltype(cont.begin(),\
    \ cont.end(), ist) {\n    for (auto itr = cont.begin(); itr != cont.end(); ++itr)\
    \ ist >> *itr;\n    return ist;\n}\n\ntemplate<class T, class U>\ninline constexpr\
    \ bool chmin(T& a, const U& b) noexcept {\n    return a > b ? a = b, true : false;\n\
    }\ntemplate<class T, class U>\ninline constexpr bool chmax(T& a, const U& b) noexcept\
    \ {\n    return a < b ? a = b, true : false;\n}\n\ninline CONSTEXPR ll gcd(ll\
    \ a, ll b) noexcept {\n    while (b) {\n        const ll c = a;\n        a = b;\n\
    \        b = c % b;\n    }\n    return a;\n}\ninline CONSTEXPR ll lcm(ll a, ll\
    \ b) noexcept { return a / gcd(a, b) * b; }\n\ninline CONSTEXPR bool is_prime(ll\
    \ N) noexcept {\n    if (N <= 1) return false;\n    for (ll i = 2; i * i <= N;\
    \ ++i) {\n        if (N % i == 0) return false;\n    }\n    return true;\n}\n\
    inline std::vector<ll> prime_factor(ll N) {\n    std::vector<ll> res;\n    for\
    \ (ll i = 2; i * i <= N; ++i) {\n        while (N % i == 0) {\n            res.push_back(i);\n\
    \            N /= i;\n        }\n    }\n    if (N != 1) res.push_back(N);\n  \
    \  return res;\n}\n\ninline CONSTEXPR ll my_pow(ll a, ll b) noexcept {\n    ll\
    \ res = 1;\n    while (b) {\n        if (b & 1) res *= a;\n        b >>= 1;\n\
    \        a *= a;\n    }\n    return res;\n}\ninline CONSTEXPR ll mod_pow(ll a,\
    \ ll b, ll mod) {\n    assert(mod > 0);\n    if (mod == 1) return 0;\n    a %=\
    \ mod;\n    ll res = 1;\n    while (b) {\n        if (b & 1) (res *= a) %= mod;\n\
    \        b >>= 1;\n        (a *= a) %= mod;\n    }\n    return res;\n}\n\ninline\
    \ PLL extGCD(ll a, ll b) noexcept {\n    const ll n = a, m = b;\n    ll x = 1,\
    \ y = 0, u = 0, v = 1;\n    ll t;\n    while (b) {\n        t = a / b;\n     \
    \   std::swap(a -= t * b, b);\n        std::swap(x -= t * u, u);\n        std::swap(y\
    \ -= t * v, v);\n    }\n    if (x < 0) {\n        x += m;\n        y -= n;\n \
    \   }\n    return {x, y};\n}\ninline ll mod_inv(ll a, ll mod) {\n    ll b = mod;\n\
    \    ll x = 1, u = 0;\n    ll t;\n    while (b) {\n        t = a / b;\n      \
    \  std::swap(a -= t * b, b);\n        std::swap(x -= t * u, u);\n    }\n    if\
    \ (x < 0) x += mod;\n    assert(a == 1);\n    return x;\n}\ninline PLL ChineseRemainder(ll\
    \ b1, ll m1, ll b2, ll m2) {\n    const PLL p = extGCD(m1, m2);\n    const ll\
    \ g = p.first * m1 + p.second * m2;\n    const ll l = m1 / g * m2;\n    if ((b2\
    \ - b1) % g != 0) return PLL{-1, -1};\n    const ll x = (b2 - b1) / g * p.first\
    \ % (m2 / g);\n    return {(x * m1 + b1 + l) % l, l};\n}\nPLL ChineseRemainders(const\
    \ std::vector<ll>& b,\n                      const std::vector<ll>& m) {\n   \
    \ PLL res{0, 1};\n    rep (i, b.size()) {\n        res = ChineseRemainder(res.first,\
    \ res.second, b[i], m[i]);\n        if (res.first == -1) return res;\n    }\n\
    \    return res;\n}\n\ntemplate<class F> class RecLambda {\nprivate:\n    F f;\n\
    \npublic:\n    explicit constexpr RecLambda(F&& f_) : f(std::forward<F>(f_)) {}\n\
    \    template<class... Args>\n    constexpr auto operator()(Args&&... args) const\n\
    \        -> decltype(f(*this, std::forward<Args>(args)...)) {\n        return\
    \ f(*this, std::forward<Args>(args)...);\n    }\n};\n\ntemplate<class F> inline\
    \ constexpr RecLambda<F> rec_lambda(F&& f) {\n    return RecLambda<F>(std::forward<F>(f));\n\
    }\n\ntemplate<class Head, class... Tail> struct multi_dim_vector {\n    using\
    \ type = std::vector<typename multi_dim_vector<Tail...>::type>;\n};\ntemplate<class\
    \ T> struct multi_dim_vector<T> { using type = T; };\n\ntemplate<class T, class\
    \ Arg>\nconstexpr std::vector<T> make_vec(int n, Arg&& arg) {\n    return std::vector<T>(n,\
    \ std::forward<Arg>(arg));\n}\ntemplate<class T, class... Args>\nconstexpr typename\
    \ multi_dim_vector<Args..., T>::type make_vec(int n,\n                       \
    \                                        Args&&... args) {\n    return typename\
    \ multi_dim_vector<Args..., T>::type(\n        n, make_vec<T>(std::forward<Args>(args)...));\n\
    }\n\ninline CONSTEXPR int popcnt(ull x) noexcept {\n#if __cplusplus >= 202002L\n\
    \    return std::popcount(x);\n#endif\n    x = (x & 0x5555555555555555) + ((x\
    \ >> 1) & 0x5555555555555555);\n    x = (x & 0x3333333333333333) + ((x >> 2) &\
    \ 0x3333333333333333);\n    x = (x & 0x0f0f0f0f0f0f0f0f) + ((x >> 4) & 0x0f0f0f0f0f0f0f0f);\n\
    \    x = (x & 0x00ff00ff00ff00ff) + ((x >> 8) & 0x00ff00ff00ff00ff);\n    x =\
    \ (x & 0x0000ffff0000ffff) + ((x >> 16) & 0x0000ffff0000ffff);\n    return (x\
    \ & 0x00000000ffffffff) + ((x >> 32) & 0x00000000ffffffff);\n}\n\ntemplate<class\
    \ T, class Comp = std::less<T>> class presser {\nprivate:\n    std::vector<T>\
    \ dat;\n    Comp cmp;\n    bool sorted = false;\n\npublic:\n    presser() : presser(Comp())\
    \ {}\n    presser(const Comp& cmp) : cmp(cmp) {}\n    presser(const std::vector<T>&\
    \ vec, const Comp& cmp = Comp())\n        : dat(vec), cmp(cmp) {}\n    presser(std::vector<T>&&\
    \ vec, const Comp& cmp = Comp())\n        : dat(std::move(vec)), cmp(cmp) {}\n\
    \    presser(std::initializer_list<T> il, const Comp& cmp = Comp())\n        :\
    \ dat(il.begin(), il.end()), cmp(cmp) {}\n    void reserve(int n) {\n        assert(!sorted);\n\
    \        dat.reserve(n);\n    }\n    void push_back(const T& v) {\n        assert(!sorted);\n\
    \        dat.push_back(v);\n    }\n    void push_back(T&& v) {\n        assert(!sorted);\n\
    \        dat.push_back(std::move(v));\n    }\n    void push(const std::vector<T>&\
    \ vec) {\n        assert(!sorted);\n        const int n = dat.size();\n      \
    \  dat.resize(n + vec.size());\n        rep (i, vec.size()) dat[n + i] = vec[i];\n\
    \    }\n    int build() {\n        assert(!sorted);\n        sorted = true;\n\
    \        std::sort(all(dat), cmp);\n        dat.erase(std::unique(all(dat),\n\
    \                              [&](const T& a, const T& b) -> bool {\n       \
    \                           return !cmp(a, b) && !cmp(b, a);\n               \
    \               }),\n                  dat.end());\n        return dat.size();\n\
    \    }\n    const T& operator[](int k) const& {\n        assert(sorted);\n   \
    \     assert(0 <= k && k < (int)dat.size());\n        return dat[k];\n    }\n\
    \    T operator[](int k) && {\n        assert(sorted);\n        assert(0 <= k\
    \ && k < (int)dat.size());\n        return std::move(dat[k]);\n    }\n    int\
    \ get(const T& val) const {\n        assert(sorted);\n        auto itr = std::lower_bound(all(dat),\
    \ val, cmp);\n        assert(itr != dat.end() && !cmp(val, *itr));\n        return\
    \ itr - dat.begin();\n    }\n    int lower_bound(const T& val) const {\n     \
    \   assert(sorted);\n        auto itr = std::lower_bound(all(dat), val, cmp);\n\
    \        return itr - dat.begin();\n    }\n    std::vector<int> pressed(const\
    \ std::vector<T>& vec) const {\n        assert(sorted);\n        std::vector<int>\
    \ res(vec.size());\n        rep (i, vec.size()) res[i] = get(vec[i]);\n      \
    \  return res;\n    }\n    void press(std::vector<T>& vec) const {\n        static_assert(std::is_integral<T>::value,\n\
    \                      \"template argument must be convertible from int type\"\
    );\n        assert(sorted);\n        each_for (i : vec) i = get(i);\n    }\n \
    \   int size() const {\n        assert(sorted);\n        return dat.size();\n\
    \    }\n    const std::vector<T>& data() const& { return dat; }\n    std::vector<T>\
    \ data() && { return std::move(dat); }\n};\n#line 2 \"graph/Graph.hpp\"\n\n#line\
    \ 4 \"graph/Graph.hpp\"\n\ntemplate<class T = int> struct edge {\n    int from,\
    \ to;\n    T cost;\n    int idx;\n    edge() : from(-1), to(-1) {}\n    edge(int\
    \ f, int t, const T& c = 1, int i = -1)\n        : from(f), to(t), cost(c), idx(i)\
    \ {}\n    edge(int f, int t, T&& c, int i = -1)\n        : from(f), to(t), cost(std::move(c)),\
    \ idx(i) {}\n    operator int() const { return to; }\n    friend bool operator<(const\
    \ edge<T>& lhs, const edge<T>& rhs) {\n        return lhs.cost < rhs.cost;\n \
    \   }\n    friend bool operator>(const edge<T>& lhs, const edge<T>& rhs) {\n \
    \       return lhs.cost > rhs.cost;\n    }\n};\n\ntemplate<class T = int> using\
    \ Edges = std::vector<edge<T>>;\ntemplate<class T = int> using GMatrix = std::vector<std::vector<T>>;\n\
    \ntemplate<class T = int> class Graph : public std::vector<std::vector<edge<T>>>\
    \ {\nprivate:\n    using Base = std::vector<std::vector<edge<T>>>;\n\npublic:\n\
    \    int edge_id = 0;\n    using Base::Base;\n    int edge_size() const { return\
    \ edge_id; }\n    int add_edge(int a, int b, const T& c, bool is_directed = false)\
    \ {\n        assert(0 <= a && a < (int)this->size());\n        assert(0 <= b &&\
    \ b < (int)this->size());\n        (*this)[a].emplace_back(a, b, c, edge_id);\n\
    \        if (!is_directed) (*this)[b].emplace_back(b, a, c, edge_id);\n      \
    \  return edge_id++;\n    }\n    int add_edge(int a, int b, bool is_directed =\
    \ false) {\n        assert(0 <= a && a < (int)this->size());\n        assert(0\
    \ <= b && b < (int)this->size());\n        (*this)[a].emplace_back(a, b, 1, edge_id);\n\
    \        if (!is_directed) (*this)[b].emplace_back(b, a, 1, edge_id);\n      \
    \  return edge_id++;\n    }\n};\n\ntemplate<class T> GMatrix<T> ListToMatrix(const\
    \ Graph<T>& G) {\n    const int N = G.size();\n    auto res = make_vec<T>(N, N,\
    \ infinity<T>::value);\n    rep (i, N) res[i][i] = 0;\n    rep (i, N) {\n    \
    \    each_const (e : G[i]) res[i][e.to] = e.cost;\n    }\n    return res;\n}\n\
    \ntemplate<class T> Edges<T> UndirectedListToEdges(const Graph<T>& G) {\n    const\
    \ int V = G.size();\n    const int E = G.edge_size();\n    Edges<T> Ed(E);\n \
    \   rep (i, V) {\n        each_const (e : G[i]) Ed[e.idx] = e;\n    }\n    return\
    \ Ed;\n}\n\ntemplate<class T> Edges<T> DirectedListToEdges(const Graph<T>& G)\
    \ {\n    const int V = G.size();\n    const int E = std::accumulate(\n       \
    \ all(G), 0, [](int a, const std::vector<edge<T>>& v) -> int {\n            return\
    \ a + v.size();\n        });\n    Edges<T> Ed(G.edge_size());\n    Ed.reserve(E);\n\
    \    rep (i, V) {\n        each_const (e : G[i]) {\n            if (Ed[e.idx]\
    \ == -1) Ed[e.idx] = e;\n            else Ed.push_back(e);\n        }\n    }\n\
    \    return Ed;\n}\n\ntemplate<class T> Graph<T> ReverseGraph(const Graph<T>&\
    \ G) {\n    const int V = G.size();\n    Graph<T> res(V);\n    rep (i, V) {\n\
    \        each_const (e : G[i]) {\n            res[e.to].emplace_back(e.to, e.from,\
    \ e.cost, e.idx);\n        }\n    }\n    res.edge_id = G.edge_size();\n    return\
    \ res;\n}\n\n\nstruct unweighted_edge {\n    template<class... Args> unweighted_edge(const\
    \ Args&...) {}\n    operator int() { return 1; }\n};\n\nusing UnweightedGraph\
    \ = Graph<unweighted_edge>;\n\n/**\n * @brief Graph-template\n * @docs docs/graph/Graph.md\n\
    \ */\n#line 2 \"graph/tree/DoublingLowestCommonAncestor.hpp\"\n\n#line 2 \"other/bitop.hpp\"\
    \n\n#line 4 \"other/bitop.hpp\"\n\nnamespace bitop {\n\n#define KTH_BIT(b, k)\
    \ (((b) >> (k)) & 1)\n#define POW2(k) (1ull << (k))\n\ninline ull next_combination(int\
    \ n, ull x) {\n    if (n == 0) return 1;\n    ull a = x & -x;\n    ull b = x +\
    \ a;\n    return (x & ~b) / a >> 1 | b;\n}\n\n#define rep_comb(i, n, k)      \
    \                                                \\\n    for (ull i = (1ull <<\
    \ (k)) - 1; i < (1ull << (n));                         \\\n         i = bitop::next_combination((n),\
    \ i))\n\ninline CONSTEXPR int msb(ull x) {\n    int res = x ? 0 : -1;\n    if\
    \ (x & 0xFFFFFFFF00000000) x &= 0xFFFFFFFF00000000, res += 32;\n    if (x & 0xFFFF0000FFFF0000)\
    \ x &= 0xFFFF0000FFFF0000, res += 16;\n    if (x & 0xFF00FF00FF00FF00) x &= 0xFF00FF00FF00FF00,\
    \ res += 8;\n    if (x & 0xF0F0F0F0F0F0F0F0) x &= 0xF0F0F0F0F0F0F0F0, res += 4;\n\
    \    if (x & 0xCCCCCCCCCCCCCCCC) x &= 0xCCCCCCCCCCCCCCCC, res += 2;\n    return\
    \ res + ((x & 0xAAAAAAAAAAAAAAAA) ? 1 : 0);\n}\n\ninline CONSTEXPR int ceil_log2(ull\
    \ x) { return x ? msb(x - 1) + 1 : 0; }\n} // namespace bitop\n#line 6 \"graph/tree/DoublingLowestCommonAncestor.hpp\"\
    \n\ntemplate<class T> class DoublingLCA {\nprivate:\n    int root, n, h;\n   \
    \ Graph<T> G_;\n    const Graph<T>& G;\n    std::vector<edge<T>> par;\n    std::vector<int>\
    \ dep;\n    std::vector<std::vector<int>> dbl;\n    void dfs_build(int v, int\
    \ p) {\n        each_const (e : G[v]) {\n            if (e.to != p) {\n      \
    \          par[e.to] = edge<T>(e.to, e.from, e.cost, e.idx);\n               \
    \ dep[e.to] = dep[v] + 1;\n                dfs_build(e.to, v);\n            }\n\
    \        }\n    }\n    void init() {\n        n = G.size();\n        h = bitop::ceil_log2(n)\
    \ + 1;\n        par.resize(n);\n        par[root] = edge<T>{};\n        dep.resize(n);\n\
    \        dep[root] = 0;\n        dfs_build(root, -1);\n        dbl.assign(n, std::vector<int>(h,\
    \ -1));\n        rep (i, n) dbl[i][0] = par[i].to;\n        rep (i, h - 1) {\n\
    \            rep (j, n) dbl[j][i + 1] = dbl[j][i] == -1 ? -1 : dbl[dbl[j][i]][i];\n\
    \        }\n    }\n\npublic:\n    DoublingLCA(const Graph<T>& G, int r = 0) :\
    \ root(r), G(G) { init(); }\n    DoublingLCA(Graph<T>&& G, int r = 0) : root(r),\
    \ G_(std::move(G)), G(G_) {\n        init();\n    }\n    int depth(int v) const\
    \ { return dep[v]; }\n    int parent(int v) const { return par[v].to; }\n    int\
    \ kth_ancestor(int v, int k) const {\n        if (dep[v] < k) return -1;\n   \
    \     rrep (i, h) {\n            if ((k >> i) & 1) v = dbl[v][i];\n        }\n\
    \        return v;\n    }\n    int next_vertex(int s, int t) const {\n       \
    \ assert(s != t);\n        if (dep[s] >= dep[t]) return parent(s);\n        int\
    \ u = kth_ancestor(t, dep[t] - dep[s] - 1);\n        return parent(u) == s ? u\
    \ : parent(s);\n    }\n    int kth_next_vertext(int s, int t, int k) const {\n\
    \        int l = lca(s, t);\n        int d = dep[s] + dep[t] - 2 * dep[l];\n \
    \       if (d < k) return -1;\n        if (dep[s] - dep[l] >= k) return kth_ancestor(s,\
    \ k);\n        return kth_ancestor(t, d - k);\n    }\n    Edges<T> path(int s,\
    \ int t) const {\n        Edges<T> pre, suf;\n        while (dep[s] > dep[t])\
    \ pre.push_back(par[s]), s = par[s].to;\n        while (dep[t] > dep[s]) suf.push_back(par[t]),\
    \ t = par[t].to;\n        while (s != t) {\n            pre.push_back(par[s]),\
    \ s = par[s].to;\n            suf.push_back(par[t]), t = par[t].to;\n        }\n\
    \        rrep (i, suf.size())\n            pre.emplace_back(suf[i].to, suf[i].from,\
    \ suf[i].cost, suf[i].idx);\n        return pre;\n    }\n    int lca(int u, int\
    \ v) const {\n        if (dep[u] > dep[v]) u = kth_ancestor(u, dep[u] - dep[v]);\n\
    \        if (dep[u] < dep[v]) v = kth_ancestor(v, dep[v] - dep[u]);\n        if\
    \ (u == v) return u;\n        rrep (i, h) {\n            if (dbl[u][i] != dbl[v][i])\
    \ {\n                u = dbl[u][i];\n                v = dbl[v][i];\n        \
    \    }\n        }\n        return parent(u);\n    }\n    int dist(int u, int v)\
    \ const {\n        return dep[u] + dep[v] - 2 * dep[lca(u, v)];\n    }\n};\n\n\
    /**\n * @brief DoublingLowestCommonAncestor(\u30C0\u30D6\u30EA\u30F3\u30B0\u306B\
    \u3088\u308BLCA)\n * @docs docs/graph/tree/DoublingLowestCommonAncestor.md\n */\n\
    #line 5 \"test/aoj/GRL/GRL_5_C-LCA.test.cpp\"\nusing namespace std;\nint main()\
    \ {\n    int N; cin >> N;\n    Graph<int> G(N);\n    rep (i, N) {\n        int\
    \ k; cin >> k;\n        rep (k) {\n            int t; cin >> t;\n            G.add_edge(i,\
    \ t, true);\n        }\n    }\n    DoublingLCA<int> T(G);\n    int Q; cin >> Q;\n\
    \    rep (i, Q) {\n        int a, b; cin >> a >> b;\n        cout << T.lca(a,\
    \ b) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C\"\n#include\
    \ \"../../../other/template.hpp\"\n#include \"../../../graph/Graph.hpp\"\n#include\
    \ \"../../../graph/tree/DoublingLowestCommonAncestor.hpp\"\nusing namespace std;\n\
    int main() {\n    int N; cin >> N;\n    Graph<int> G(N);\n    rep (i, N) {\n \
    \       int k; cin >> k;\n        rep (k) {\n            int t; cin >> t;\n  \
    \          G.add_edge(i, t, true);\n        }\n    }\n    DoublingLCA<int> T(G);\n\
    \    int Q; cin >> Q;\n    rep (i, Q) {\n        int a, b; cin >> a >> b;\n  \
    \      cout << T.lca(a, b) << endl;\n    }\n}\n"
  dependsOn:
  - other/template.hpp
  - graph/Graph.hpp
  - graph/tree/DoublingLowestCommonAncestor.hpp
  - other/bitop.hpp
  isVerificationFile: true
  path: test/aoj/GRL/GRL_5_C-LCA.test.cpp
  requiredBy: []
  timestamp: '2022-08-18 19:11:53+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/GRL/GRL_5_C-LCA.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL/GRL_5_C-LCA.test.cpp
- /verify/test/aoj/GRL/GRL_5_C-LCA.test.cpp.html
title: test/aoj/GRL/GRL_5_C-LCA.test.cpp
---
