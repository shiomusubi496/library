---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-struct/segment/PlusMinusOneRMQ.hpp
    title: PlusMinusOneRMQ($\pm1$RMQ)
  - icon: ':question:'
    path: data-struct/segment/SparseTable.hpp
    title: SparseTable
  - icon: ':question:'
    path: graph/Graph.hpp
    title: Graph-template
  - icon: ':heavy_check_mark:'
    path: graph/tree/CartesianTree.hpp
    title: CartesianTree
  - icon: ':question:'
    path: graph/tree/EulerTour.hpp
    title: "EulerTour(\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC)"
  - icon: ':heavy_check_mark:'
    path: graph/tree/PMORMQLCA.hpp
    title: "PMORMQLCA($\\pm1$RMQ\u306B\u3088\u308BLCA)"
  - icon: ':question:'
    path: other/bitop.hpp
    title: other/bitop.hpp
  - icon: ':question:'
    path: other/monoid.hpp
    title: other/monoid.hpp
  - icon: ':question:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/staticrmq-LCARMQ.test.cpp
    title: test/yosupo/staticrmq-LCARMQ.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/LCARMQ.md
    document_title: LCARMQ
    links: []
  bundledCode: "#line 2 \"data-struct/segment/LCARMQ.hpp\"\n\n#line 2 \"other/template.hpp\"\
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
    \ }\n};\n#line 2 \"graph/tree/CartesianTree.hpp\"\n\n#line 2 \"graph/Graph.hpp\"\
    \n\n#line 4 \"graph/Graph.hpp\"\n\ntemplate<class T = int> struct edge {\n   \
    \ int from, to;\n    T cost;\n    int idx;\n    edge() : from(-1), to(-1) {}\n\
    \    edge(int f, int t, const T& c = 1, int i = -1) : from(f), to(t), cost(c),\
    \ idx(i) {}\n    edge(int f, int t, T&& c, int i = -1) : from(f), to(t), cost(std::move(c)),\
    \ idx(i) {}\n    operator int() const { return to; }\n    friend bool operator<(const\
    \ edge<T>& lhs, const edge<T>& rhs) {\n        return lhs.cost < rhs.cost;\n \
    \   }\n    friend bool operator>(const edge<T>& lhs, const edge<T>& rhs) {\n \
    \       return lhs.cost > rhs.cost;\n    }\n};\n\ntemplate<class T = int> using\
    \ Edges = std::vector<edge<T>>;\ntemplate<class T = int> using GMatrix = std::vector<std::vector<T>>;\n\
    \ntemplate<class T = int> class Graph : public std::vector<std::vector<edge<T>>>\
    \ {\n  private:\n    using Base = std::vector<std::vector<edge<T>>>;\n  public:\n\
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
    \ all(G), 0,\n        [](int a, const std::vector<edge<T>>& v) -> int { return\
    \ a + v.size(); }\n    );\n    Edges<T> Ed(G.edge_size()); Ed.reserve(E);\n  \
    \  rep (i, V) {\n        each_const (e : G[i]) {\n            if (Ed[e.idx] ==\
    \ -1) Ed[e.idx] = e;\n            else Ed.push_back(e);\n        }\n    }\n  \
    \  return Ed;\n}\n\ntemplate<class T> Graph<T> ReverseGraph(const Graph<T>& G)\
    \ {\n    const int V = G.size();\n    Graph<T> res(V);\n    rep (i, V) {\n   \
    \     each_const (e : G[i]) {\n            res[e.to].emplace_back(e.to, e.from,\
    \ e.cost, e.idx);\n        }\n    }\n    res.edge_id = G.edge_size();\n    return\
    \ res;\n}\n\n\nstruct unweighted_edge {\n    template<class... Args> unweighted_edge(const\
    \ Args&...) {}\n    operator int() { return 1; }\n};\n\nusing UnweightedGraph\
    \ = Graph<unweighted_edge>;\n\n/**\n * @brief Graph-template\n * @docs docs/Graph.md\n\
    \ */\n#line 5 \"graph/tree/CartesianTree.hpp\"\n\ntemplate<class T, class Comp\
    \ = std::less<T>> class CartesianTree {\n  protected:\n    int n;\n    const std::vector<T>&\
    \ v;\n    std::vector<int> par;\n    Comp cmp;\n    void init() {\n        n =\
    \ v.size();\n        par.assign(n, -1);\n        rep (i, 1, n) {\n           \
    \ int p = i - 1;\n            int lst = -1;\n            while (p != -1 && cmp(v[i],\
    \ v[p])) {\n                lst = p;\n                p = par[p];\n          \
    \  }\n            if (lst != -1) par[lst] = i;\n            par[i] = p;\n    \
    \    }\n    }\n  public:\n    CartesianTree(const std::vector<T>& v) : v(v), cmp(Comp())\
    \ { init(); }\n    CartesianTree(const std::vector<T>& v, const Comp& cmp) : v(v),\
    \ cmp(cmp) { init(); }\n    const std::vector<int>& get_vec() const& { return\
    \ par; }\n    std::vector<int> get_vec() && { return std::move(par); }\n    template<class\
    \ U = int> std::pair<Graph<U>, int> get_graph() {\n        Graph<U> res(n);\n\
    \        int root = 0;\n        rep (i, n) {\n            if (par[i] == -1) root\
    \ = i;\n            else res.add_edge(i, par[i]);\n        }\n        return {res,\
    \ root};\n    }\n};\n\n/**\n * @brief CartesianTree\n * @docs docs/CartesianTree.md\n\
    \ */\n#line 2 \"graph/tree/PMORMQLCA.hpp\"\n\n#line 2 \"graph/tree/EulerTour.hpp\"\
    \n\n#line 2 \"data-struct/segment/SparseTable.hpp\"\n\n#line 2 \"other/bitop.hpp\"\
    \n\n#line 4 \"other/bitop.hpp\"\n\nnamespace bitop {\n\n#define KTH_BIT(b, k)\
    \ (((b) >> (k)) & 1)\n#define POW2(k) (1ull << (k))\n\n    inline ull next_combination(int\
    \ n, ull x) {\n        if (n == 0) return 1;\n        ull a = x & -x;\n      \
    \  ull b = x + a;\n        return (x & ~b) / a >> 1 | b;\n    }\n\n#define rep_comb(i,\
    \ n, k) for (ull i = (1ull << (k)) - 1; i < (1ull << (n)); i = bitop::next_combination((n),\
    \ i))\n\n    inline CONSTEXPR int msb(ull x) {\n        int res = x ? 0 : -1;\n\
    \        if (x & 0xFFFFFFFF00000000) x &= 0xFFFFFFFF00000000, res += 32;\n   \
    \     if (x & 0xFFFF0000FFFF0000) x &= 0xFFFF0000FFFF0000, res += 16;\n      \
    \  if (x & 0xFF00FF00FF00FF00) x &= 0xFF00FF00FF00FF00, res +=  8;\n        if\
    \ (x & 0xF0F0F0F0F0F0F0F0) x &= 0xF0F0F0F0F0F0F0F0, res +=  4;\n        if (x\
    \ & 0xCCCCCCCCCCCCCCCC) x &= 0xCCCCCCCCCCCCCCCC, res +=  2;\n        return res\
    \ + ((x & 0xAAAAAAAAAAAAAAAA) ? 1 : 0);\n    }\n\n    inline CONSTEXPR int ceil_log2(ull\
    \ x) {\n        return x ? msb(x - 1) + 1 : 0;\n    }\n}\n#line 2 \"other/monoid.hpp\"\
    \n\n#line 4 \"other/monoid.hpp\"\n\nnamespace Monoid {\n\ntemplate<class M, class\
    \ = void> class has_op : public std::false_type {};\ntemplate<class M>\nclass\
    \ has_op<M, decltype((void)M::op)> : public std::true_type {};\n\ntemplate<class\
    \ M, class = void> class has_id : public std::false_type {};\ntemplate<class M>\n\
    class has_id<M, decltype((void)M::id)> : public std::true_type {};\n\ntemplate<class\
    \ M, class = void> class has_inv : public std::false_type {};\ntemplate<class\
    \ M>\nclass has_inv<M, decltype((void)M::inv)> : public std::true_type {};\n\n\
    template<class M, class = void> class has_get_inv : public std::false_type {};\n\
    template<class M>\nclass has_get_inv<M, decltype((void)M::get_inv)> : public std::true_type\
    \ {};\n\ntemplate<class M, class = void> class has_init : public std::false_type\
    \ {};\ntemplate<class M>\nclass has_init<M, decltype((void)M::init)> : public\
    \ std::true_type {};\n\ntemplate<class A, class = void> class has_mul_op : public\
    \ std::false_type {};\ntemplate<class A>\nclass has_mul_op<A, decltype((void)A::mul_op)>\
    \ : public std::true_type {};\n\ntemplate<class T, class = void> class is_semigroup\
    \ : public std::false_type {};\ntemplate<class T>\nclass is_semigroup<T, decltype(std::declval<typename\
    \ T::value_type>(),\n                               (void)T::op)> : public std::true_type\
    \ {};\n\ntemplate<class T, class = void> class is_monoid : public std::false_type\
    \ {};\n\ntemplate<class T>\nclass is_monoid<T, decltype(std::declval<typename\
    \ T::value_type>(), (void)T::op,\n                            (void)T::id)> :\
    \ public std::true_type {};\n\ntemplate<class T, class = void> class is_group\
    \ : public std::false_type {};\n\ntemplate<class T>\nclass is_group<T, decltype(std::declval<typename\
    \ T::value_type>(), (void)T::op,\n                           (void)T::id, (void)T::get_inv)>\n\
    \    : public std::true_type {};\n\ntemplate<class T, class = void> class is_action\
    \ : public std::false_type {};\ntemplate<class T>\nclass is_action<T, typename\
    \ std::enable_if<is_monoid<typename T::M>::value &&\n                        \
    \                   is_semigroup<typename T::E>::value &&\n                  \
    \                         (has_op<T>::value ||\n                             \
    \               has_mul_op<T>::value)>::type>\n    : public std::true_type {};\n\
    \ntemplate<class T, class = void>\nclass is_distributable_action : public std::false_type\
    \ {};\ntemplate<class T>\nclass is_distributable_action<\n    T,\n    typename\
    \ std::enable_if<is_action<T>::value && !has_mul_op<T>::value>::type>\n    : public\
    \ std::true_type {};\n\ntemplate<class T> struct Sum {\n    using value_type =\
    \ T;\n    static constexpr T op(const T& a, const T& b) { return a + b; }\n  \
    \  static constexpr T id() { return T{0}; }\n    static constexpr T inv(const\
    \ T& a, const T& b) { return a - b; }\n    static constexpr T get_inv(const T&\
    \ a) { return -a; }\n};\n\ntemplate<class T, T max_value = infinity<T>::max> struct\
    \ Min {\n    using value_type = T;\n    static constexpr T op(const T& a, const\
    \ T& b) { return a < b ? a : b; }\n    static constexpr T id() { return max_value;\
    \ }\n};\n\ntemplate<class T, T min_value = infinity<T>::min> struct Max {\n  \
    \  using value_type = T;\n    static constexpr T op(const T& a, const T& b) {\
    \ return a < b ? b : a; }\n    static constexpr T id() { return min_value; }\n\
    };\n\ntemplate<class T> struct Assign {\n    using value_type = T;\n    static\
    \ constexpr T op(const T&, const T& b) { return b; }\n};\n\n\ntemplate<class T,\
    \ T max_value = infinity<T>::max> struct AssignMin {\n    using M = Min<T, max_value>;\n\
    \    using E = Assign<T>;\n    static constexpr T op(const T& a, const T&) { return\
    \ a; }\n};\n\ntemplate<class T, T min_value = infinity<T>::min> struct AssignMax\
    \ {\n    using M = Max<T, min_value>;\n    using E = Assign<T>;\n    static constexpr\
    \ T op(const T& a, const T&) { return a; }\n};\n\ntemplate<class T> struct AssignSum\
    \ {\n    using M = Sum<T>;\n    using E = Assign<T>;\n    static constexpr T mul_op(const\
    \ T& a, int b, const T&) { return a * b; }\n};\n\ntemplate<class T, T max_value\
    \ = infinity<T>::max> struct AddMin {\n    using M = Min<T, max_value>;\n    using\
    \ E = Sum<T>;\n    static constexpr T op(const T& a, const T& b) { return b +\
    \ a; }\n};\n\ntemplate<class T, T min_value = infinity<T>::min> struct AddMax\
    \ {\n    using M = Max<T, min_value>;\n    using E = Sum<T>;\n    static constexpr\
    \ T op(const T& a, const T& b) { return b + a; }\n};\n\ntemplate<class T> struct\
    \ AddSum {\n    using M = Sum<T>;\n    using E = Sum<T>;\n    static constexpr\
    \ T mul_op(const T& a, int b, const T& c) {\n        return c + a * b;\n    }\n\
    };\n\ntemplate<class T, T max_value = infinity<T>::max> struct ChminMin {\n  \
    \  using M = Min<T, max_value>;\n    using E = Min<T>;\n    static constexpr T\
    \ op(const T& a, const T& b) { return std::min(b, a); }\n};\n\ntemplate<class\
    \ T, T min_value = infinity<T>::min> struct ChminMax {\n    using M = Max<T, min_value>;\n\
    \    using E = Min<T>;\n    static constexpr T op(const T& a, const T& b) { return\
    \ std::min(b, a); }\n};\n\ntemplate<class T, T max_value = infinity<T>::max> struct\
    \ ChmaxMin {\n    using M = Min<T, max_value>;\n    using E = Max<T>;\n    static\
    \ constexpr T op(const T& a, const T& b) { return std::max(b, a); }\n};\n\ntemplate<class\
    \ T, T min_value = infinity<T>::min> struct ChmaxMax {\n    using M = Max<T, min_value>;\n\
    \    using E = Max<T>;\n    static constexpr T op(const T& a, const T& b) { return\
    \ std::max(b, a); }\n};\n\n\ntemplate<class M> struct ReverseMonoid {\n    using\
    \ value_type = typename M::value_type;\n    static value_type op(const value_type&\
    \ a, const value_type& b) {\n        return M::op(b, a);\n    }\n    static value_type\
    \ id() {\n        static_assert(has_id<M>::value, \"id is not defined\");\n  \
    \      return M::id();\n    }\n    static value_type get_inv(const value_type&\
    \ a) {\n        static_assert(has_get_inv<M>::value, \"get_inv is not defined\"\
    );\n        return M::get_inv(a);\n    }\n};\n\ntemplate<class M_> struct AttachEffector\
    \ {\n    using M = M_;\n    using E = M_;\n    using T = typename M_::value_type;\n\
    \    static T op(const T& a, const T& b) { return M_::op(b, a); }\n};\n\ntemplate<class\
    \ E_> struct AttachMonoid {\n    using M = E_;\n    using E = E_;\n    using T\
    \ = typename E_::value_type;\n    static T op(const T& a, const T& b) { return\
    \ E_::op(b, a); }\n};\n\n\ntemplate<class A, bool = has_init<typename A::M>::value>\
    \ struct MultiAction {\n    struct M {\n        struct value_type {\n        private:\n\
    \            using T_ = typename A::M::value_type;\n        public:\n        \
    \    T_ val;\n            ll len;\n            value_type() = default;\n     \
    \       value_type(T_ v, ll l) : val(v), len(l) {}\n            friend std::ostream&\
    \ operator<<(std::ostream& ost,\n                                            const\
    \ value_type& e) {\n                return ost << e.val << '*' << e.len;\n   \
    \         }\n        };\n        static value_type op(const value_type& a, const\
    \ value_type& b) {\n            return {A::M::op(a.val, b.val), a.len + b.len};\n\
    \        }\n        static value_type id() { return {A::M::id(), 0}; }\n    };\n\
    \    using E = typename A::E;\n\nprivate:\n    using T = typename M::value_type;\n\
    \    using U = typename E::value_type;\n\npublic:\n    static T op(const U& a,\
    \ const T& b) {\n        return {A::mul_op(a, b.len, b.val), b.len};\n    }\n\
    };\n\ntemplate<class A> struct MultiAction<A, true> {\n    struct M {\n      \
    \  struct value_type {\n        private:\n            using T_ = typename A::M::value_type;\n\
    \        public:\n            T_ val;\n            ll len;\n            value_type()\
    \ = default;\n            value_type(T_ v, ll l) : val(v), len(l) {}\n       \
    \     friend std::ostream& operator<<(std::ostream& ost,\n                   \
    \                         const value_type& e) {\n                return ost <<\
    \ e.val << '*' << e.len;\n            }\n        };\n        static value_type\
    \ op(const value_type& a, const value_type& b) {\n            return {A::M::op(a.val,\
    \ b.val), a.len + b.len};\n        }\n        static value_type id() { return\
    \ {A::M::id(), 0}; }\n        static value_type init(ll l, ll r) {\n         \
    \   return {A::M::init(l, r), r - l};\n        }\n    };\n    using E = typename\
    \ A::E;\n\nprivate:\n    using T = typename M::value_type;\n    using U = typename\
    \ E::value_type;\n\npublic:\n    static T op(const U& a, const T& b) {\n     \
    \   return {A::mul_op(a, b.len, b.val), b.len};\n    }\n};\n\n} // namespace Monoid\n\
    #line 6 \"data-struct/segment/SparseTable.hpp\"\n\ntemplate<class M> class SparseTable\
    \ {\n  protected:\n    using T = typename M::value_type;\n    int h, ori;\n  \
    \  std::vector<int> logtable;\n    std::vector<std::vector<T>> data;\n    T internal_prod(int\
    \ l, int r) const {\n        assert(0 <= l && l < r && r <= ori);\n        int\
    \ d = logtable[r - l];\n        return M::op(data[d][l], data[d][r - (1 << d)]);\n\
    \    }\n  public:\n    SparseTable() = default;\n    SparseTable(const std::vector<T>&\
    \ v) { init(v); }\n    void init(const std::vector<T>& v) {\n        ori = v.size();\n\
    \        h = bitop::ceil_log2(ori);\n        logtable.assign((1 << h) + 1, 0);\n\
    \        reps (i, 1, 1 << h) logtable[i] = logtable[i >> 1] + 1;\n        data.assign(h\
    \ + 1, std::vector<T>(1 << h));\n        rep (i, ori) data[0][i] = v[i];\n   \
    \     rep (i, h) {\n            rep (j, (1 << h) - (1 << i)) {\n             \
    \   data[i + 1][j] = M::op(data[i][j], data[i][j + (1 << i)]);\n            }\n\
    \        }\n    }\n    template<bool AlwaysTrue = true, typename std::enable_if<\
    \ Monoid::has_id<M>::value && AlwaysTrue>::type* = nullptr>\n    T prod(int l,\
    \ int r) const {\n        if (l == r) return M::id();\n        return internal_prod(l,\
    \ r);\n    }\n    template<bool AlwaysTrue = true, typename std::enable_if<!Monoid::has_id<M>::value\
    \ && AlwaysTrue>::type* = nullptr>\n    T prod(int l, int r) const {\n       \
    \ return internal_prod(l, r);\n    }\n};\n\n/**\n * @brief SparseTable\n * @docs\
    \ docs/SparseTable.md\n */\n#line 6 \"graph/tree/EulerTour.hpp\"\n\nnamespace\
    \ Monoid {\n    struct PairMinForEulerTour {\n        using value_type = std::pair<int,\
    \ int>;\n        static value_type op(const value_type& a, const value_type& b)\
    \ {\n            return a.first < b.first ? a : b;\n        }\n        static\
    \ value_type id() {\n            return {infinity<int>::value, -1};\n        }\n\
    \    };\n}\n\ntemplate<class T, class StaticRMQ = SparseTable<Monoid::PairMinForEulerTour>>\n\
    class EulerTour {\n  protected:\n    int n, cnt;\n    std::vector<int> root;\n\
    \    const Graph<T>& G;\n    std::vector<int> dep;\n    std::vector<std::pair<int,\
    \ int>> idx;\n    std::vector<std::pair<int, int>> rmqvec;\n    StaticRMQ RMQ;\n\
    \    void dfs(int v, int p) {\n        idx[v].first = cnt++;\n        rmqvec.emplace_back(dep[v],\
    \ v);\n        each_const (e : G[v]) {\n            if (e.to == p) continue;\n\
    \            dep[e.to] = dep[v] + 1;\n            dfs(e.to, v);\n            rmqvec.emplace_back(dep[v],\
    \ v);\n        }\n        idx[v].second = cnt++;\n    }\n    void init() {\n \
    \       n = G.size();\n        dep.assign(n, 0);\n        idx.assign(n, {-1, -1});\n\
    \        rmqvec.reserve(n << 1);\n        cnt = 0;\n        each_const (r : root)\
    \ {\n            dfs(r, -1);\n            rmqvec.emplace_back(-1, -1);\n     \
    \   }\n        rep (i, n) {\n            if (idx[i].first != -1) continue;\n \
    \           dfs(i, -1);\n            rmqvec.emplace_back(-1, -1);\n        }\n\
    \        RMQ.init(rmqvec);\n    }\n  public:\n    EulerTour(const Graph<T>& G,\
    \ int root = 0) : root({root}), G(G) { init(); }\n    EulerTour(const Graph<T>&\
    \ G, const std::vector<int>& root) : root(root), G(G) { init(); }\n    const std::pair<int,\
    \ int>& get_idx(int k) const& { return idx[k]; }\n    std::pair<int, int> get_idx(int\
    \ k) && { return std::move(idx[k]); }\n    int get_par(int a, int b) const { return\
    \ dep[a] < dep[b] ? a : b; }\n    int lca(int u, int v) const {\n        return\
    \ RMQ.prod(\n            std::min(idx[u].first, idx[v].first),\n            std::max(idx[u].second,\
    \ idx[v].second)\n        ).second;\n    }\n    template<class F> void each_vertex_subtree(int\
    \ v, const F& f) const {\n        f(idx[v].first, idx[v].second + 1);\n    }\n\
    \    template<class F> void each_edge_subtree(int v, const F& f) const {\n   \
    \     f(idx[v].first + 1, idx[v].second + 1);\n    }\n    template<class F> void\
    \ each_vertex(int u, int v, const F& f) const { each_vertex(u, v, f, f); }\n \
    \   template<class F, class G> void each_vertex(int u, int v, const F& f, const\
    \ G& g) const {\n        int l = lca(u, v);\n        g(idx[l].first, idx[u].first\
    \ + 1);\n        f(idx[l].first + 1, idx[v].first + 1);\n    }\n    template<class\
    \ F> void each_edge(int u, int v, const F& f) const { each_edge(u, v, f, f); }\n\
    \    template<class F, class G> void each_edge(int u, int v, const F& f, const\
    \ G& g) const {\n        int l = lca(u, v);\n        g(idx[l].first + 1, idx[u].first\
    \ + 1);\n        f(idx[l].first + 1, idx[v].first + 1);\n    }\n};\n\n/**\n *\
    \ @brief EulerTour(\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC)\n * @docs docs/EulerTour.md\n\
    \ */\n#line 2 \"data-struct/segment/PlusMinusOneRMQ.hpp\"\n\n#line 6 \"data-struct/segment/PlusMinusOneRMQ.hpp\"\
    \n\ntemplate<class T> class PlusMinusOneRMQ {\n  protected:\n    int n, b, m;\n\
    \    std::vector<T> v;\n    std::vector<int> ud;\n    std::vector<std::vector<std::vector<int>>>\
    \ lookup;\n    struct PairMin {\n        using value_type = std::pair<T, int>;\n\
    \        static value_type op(const value_type& a, const value_type& b) {\n  \
    \          return a.first < b.first ? a : b;\n        }\n        static value_type\
    \ id() {\n            return {infinity<T>::value, -1};\n        }\n    };\n  \
    \  SparseTable<PairMin> st;\n  public:\n    PlusMinusOneRMQ() = default;\n   \
    \ PlusMinusOneRMQ(const std::vector<T>& v_) { init(v_); }\n    void init(const\
    \ std::vector<T>& v_) {\n        v = v_;\n        n = v.size();\n        b = bitop::msb(n)\
    \ / 2 + 1;\n        m = (n + b - 1) / b;\n        lookup = make_vec<int>(1 <<\
    \ (b - 1), b, b, -1);\n        rep (i, 1 << (b - 1)) {\n            T now = 0;\n\
    \            rep (j, b) {\n                T nw = now, mn = nw, id = j;\n    \
    \            lookup[i][j][j] = j;\n                rep (k, j, b - 1) {\n     \
    \               nw += ((i >> k) & 1) ? 1 : -1;\n                    if (chmin(mn,\
    \ nw)) lookup[i][j][k + 1] = id = k + 1;\n                    else lookup[i][j][k\
    \ + 1] = id;\n                }\n                now += ((i >> j) & 1) ? 1 : -1;\n\
    \            }\n        }\n        ud.resize(m);\n        rep (i, m) {\n     \
    \       rep (j, b - 1) {\n                if (i * b + j + 1 >= n) break;\n   \
    \             if (v[i * b + j] + 1 == v[i * b + j + 1]) ud[i] |= (1 << j);\n \
    \           }\n        }\n        std::vector<std::pair<T, int>> stv(m);\n   \
    \     rep (i, m) {\n            stv[i] = {v[i * b], i * b};\n            rep (j,\
    \ i * b + 1, (i + 1) * b) {\n                if (j >= n) break;\n            \
    \    stv[i] = PairMin::op(stv[i], {v[j], j});\n            }\n        }\n    \
    \    st.init(stv);\n    }\n    int prod_idx(int l, int r) const {\n        assert(0\
    \ <= l && l < r && r <= n);\n        --r;\n        int lb = l / b, rb = r / b;\n\
    \        int lp = l - lb * b, rp = r - rb * b;\n        if (lb == rb) return lb\
    \ * b + lookup[ud[lb]][lp][rp];\n        if (lb + 1 == rb) {\n            int\
    \ x = lb * b + lookup[ud[lb]][lp][b - 1], y = rb * b + lookup[ud[rb]][0][rp];\n\
    \            if (v[x] < v[y]) return x;\n            else return y;\n        }\n\
    \        int res = st.prod(lb + 1, rb).second;\n        {\n            int a =\
    \ lb * b + lookup[ud[lb]][lp][b - 1];\n            if (v[a] < v[res]) res = a;\n\
    \        }\n        {\n            int a = rb * b + lookup[ud[rb]][0][rp];\n \
    \           if (v[a] < v[res]) res = a;\n        }\n        return res;\n    }\n\
    \    T prod(int l, int r) const { return v[prod(l, r)]; }\n};\n\n/**\n * @brief\
    \ PlusMinusOneRMQ($\\pm1$RMQ)\n * @docs docs/PlusMinusOneRMQ.md\n */\n#line 6\
    \ \"graph/tree/PMORMQLCA.hpp\"\n\nclass PMORMQForLCA {\n  protected:\n    int\
    \ n;\n    std::vector<std::pair<int, int>> v;\n    PlusMinusOneRMQ<int> RMQ;\n\
    \  public:\n    PMORMQForLCA() = default;\n    PMORMQForLCA(const std::vector<std::pair<int,\
    \ int>>& v_) { init(v_); }\n    void init(const std::vector<std::pair<int, int>>&\
    \ v_) {\n        v = v_;\n        n = v.size();\n        std::vector<int> rmqvec(n);\n\
    \        rep (i, n) rmqvec[i] = v[i].first;\n        RMQ.init(rmqvec);\n    }\n\
    \    std::pair<int, int> prod(int l, int r) const {\n        return v[RMQ.prod_idx(l,\
    \ r)];\n    }\n};\n\ntemplate<class T> using PMORMQLCA = EulerTour<T, PMORMQForLCA>;\n\
    \n/**\n * @brief PMORMQLCA($\\pm1$RMQ\u306B\u3088\u308BLCA)\n * @docs docs/PMORMQLCA.md\n\
    \ */\n#line 6 \"data-struct/segment/LCARMQ.hpp\"\n\ntemplate<class T> class LCARMQ\
    \ {\n  protected:\n    int n;\n    std::vector<T> v;\n    std::pair<Graph<int>,\
    \ int> G;\n    PMORMQLCA<int> LCA;\n  public:\n    LCARMQ(const std::vector<T>&\
    \ v) : v(v), G(CartesianTree<T>(v).get_graph()), LCA(G.first, G.second) { n =\
    \ v.size(); }\n    T prod(int l, int r) {\n        assert(0 <= l && l < r && r\
    \ <= n);\n        return v[LCA.lca(l, r - 1)];\n    }\n};\n\n/**\n * @brief LCARMQ\n\
    \ * @docs docs/LCARMQ.md\n */\n"
  code: "#pragma once\n\n#include \"../../other/template.hpp\"\n#include \"../../graph/tree/CartesianTree.hpp\"\
    \n#include \"../../graph/tree/PMORMQLCA.hpp\"\n\ntemplate<class T> class LCARMQ\
    \ {\n  protected:\n    int n;\n    std::vector<T> v;\n    std::pair<Graph<int>,\
    \ int> G;\n    PMORMQLCA<int> LCA;\n  public:\n    LCARMQ(const std::vector<T>&\
    \ v) : v(v), G(CartesianTree<T>(v).get_graph()), LCA(G.first, G.second) { n =\
    \ v.size(); }\n    T prod(int l, int r) {\n        assert(0 <= l && l < r && r\
    \ <= n);\n        return v[LCA.lca(l, r - 1)];\n    }\n};\n\n/**\n * @brief LCARMQ\n\
    \ * @docs docs/LCARMQ.md\n */\n"
  dependsOn:
  - other/template.hpp
  - graph/tree/CartesianTree.hpp
  - graph/Graph.hpp
  - graph/tree/PMORMQLCA.hpp
  - graph/tree/EulerTour.hpp
  - data-struct/segment/SparseTable.hpp
  - other/bitop.hpp
  - other/monoid.hpp
  - data-struct/segment/PlusMinusOneRMQ.hpp
  isVerificationFile: false
  path: data-struct/segment/LCARMQ.hpp
  requiredBy: []
  timestamp: '2022-07-10 23:06:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/staticrmq-LCARMQ.test.cpp
documentation_of: data-struct/segment/LCARMQ.hpp
layout: document
redirect_from:
- /library/data-struct/segment/LCARMQ.hpp
- /library/data-struct/segment/LCARMQ.hpp.html
title: LCARMQ
---
## 概要

Cartesian Tree を用いて RMQ を LCA に帰着して解く。 $\pm 1$ RMQ に帰着することで LCA は前処理 $\Theta(N)$ 、各クエリ $\Theta(1)$ で解けるため、 Cartesian Tree を求めるのは $\Theta(N)$ であることと合わせて、前処理 $\Theta(N)$ 各クエリ $\Theta(1)$ が達成される。

- `LCARMQ(std::vector<T> v)` : リスト `v` で初期化する。 $\Theta(N)$ 。
- `T prod(int l, int r)` : `min(v[l], v[l+1], ..., v[r-1])` を返す。 $\Theta(1)$ 。
