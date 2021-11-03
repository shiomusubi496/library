---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/Graph.hpp
    title: Graph-template
  - icon: ':heavy_check_mark:'
    path: graph/shortest-path/WarshallFloyd.hpp
    title: "Warshall-Floyd(\u30EF\u30FC\u30B7\u30E3\u30EB\u30D5\u30ED\u30A4\u30C9\u6CD5\
      )"
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C
  bundledCode: "#line 1 \"test/aoj/GRL_1_C-WarshallFloyd.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C\"\n#line\
    \ 2 \"template.hpp\"\n\n#include<bits/stdc++.h>\n\n#define rep(i, n) for (int\
    \ i = 0; i < (int)(n); ++i)\n#define rrep(i, n) for (int i = (int)(n) - 1; i >=\
    \ 0; --i)\n#define all(v) (v).begin(), (v).end()\n\nusing ll = long long;\nusing\
    \ ull = unsigned long long;\nusing ld = long double;\nusing PLL = std::pair<ll,\
    \ ll>;\n\nconstexpr int inf = 1e9;\nconstexpr ll INF = 1e18;\nconstexpr ld EPS\
    \ = 1e-8;\nconstexpr ld PI = 3.1415926535897932384626;\n\ntemplate<class T, class\
    \ U> inline constexpr bool chmin(T &a, const U &b) noexcept {\n    if (a > b)\
    \ {\n        a = b;\n        return true;\n    }\n    return false;\n}\ntemplate<class\
    \ T, class U> inline constexpr bool chmax(T &a, const U &b) noexcept {\n    if\
    \ (a < b) {\n        a = b;\n        return true;\n    }\n    return false;\n\
    }\n\ninline constexpr ll gcd(ll a, ll b) noexcept {\n    while (b) {\n       \
    \ const ll c = a;\n        a = b;\n        b = c % b;\n    }\n    return a;\n\
    }\ninline constexpr ll lcm(ll a, ll b) noexcept {\n    return a / gcd(a, b) *\
    \ b;\n}\n\ninline constexpr ll my_pow(ll a, ll b) noexcept {\n    ll res = 1;\n\
    \    while (b) {\n        if (b & 1) res *= a;\n        b >>= 1;\n        a *=\
    \ a;\n    }\n    return res;\n}\ninline constexpr ll mod_pow(ll a, ll b, ll mod)\
    \ noexcept {\n    a %= mod;\n    ll res = 1;\n    while (b) {\n        if (b &\
    \ 1) (res *= a) %= mod;\n        b >>= 1;\n        (a *= a) %= mod;\n    }\n \
    \   return res;\n}\n\ntemplate<class F> class rec_lambda {\n  private:\n    F\
    \ f;\n  public:\n    explicit constexpr rec_lambda(F&& f_) : f(std::forward<F>(f_))\
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
    \ 2 \"graph/shortest-path/WarshallFloyd.hpp\"\n\n#line 2 \"graph/Graph.hpp\"\n\
    \n#line 4 \"graph/Graph.hpp\"\n\ntemplate<class T = int> struct edge {\n    int\
    \ from, to;\n    T cost;\n    int idx;\n    edge() = default;\n    edge(int t)\
    \ : from(-1), to(t), cost(1) {}\n    edge(int t, T c) : from(-1), to(t), cost(c)\
    \ {}\n    edge(int f, int t, T c) : from(f), to(t), cost(c) {}\n    edge(int f,\
    \ int t, T c, int i): from(f), to(t), cost(c), idx(i) {}\n    operator int() {\
    \ return to; }\n};\n\ntemplate<class T = int> using Edges = std::vector<edge<T>>;\n\
    \ntemplate<class T = int> class Graph : public std::vector<std::vector<edge<T>>>\
    \ {\n  private:\n    using Base = std::vector<std::vector<edge<T>>>;\n  public:\n\
    \    using Base::Base;\n    int edge_id = 0;\n    int add_edge(int a, int b, T\
    \ c, bool is_directed = false){\n        assert(0 <= a && a < this->size());\n\
    \        assert(0 <= b && b < this->size());\n        (*this)[a].emplace_back(a,\
    \ b, c, edge_id);\n        if (!is_directed) (*this)[b].emplace_back(b, a, c,\
    \ edge_id);\n        return edge_id++;\n    }\n    int add_edge(int a, int b,\
    \ bool is_directed = false){\n        assert(0 <= a && a < this->size());\n  \
    \      assert(0 <= b && b < this->size());\n        (*this)[a].emplace_back(a,\
    \ b, 1, edge_id);\n        if (!is_directed) (*this)[b].emplace_back(b, a, 1,\
    \ edge_id);\n        return edge_id++;\n    }\n};\n\n/*\n@brief Graph-template\n\
    @docs docs/Graph.md\n*/\n#line 5 \"graph/shortest-path/WarshallFloyd.hpp\"\n\n\
    template<class T> void WarshallFloyd(std::vector<std::vector<T>>& G){\n    int\
    \ N = G.size();\n    rep (i, N) G[i][i] = 0;\n    rep (k, N) {\n        rep (i,\
    \ N) {\n            rep (j, N) chmin(G[i][j], G[i][k] + G[k][j]);\n        }\n\
    \    }\n}\n\n/*\n@brief Warshall-Floyd(\u30EF\u30FC\u30B7\u30E3\u30EB\u30D5\u30ED\
    \u30A4\u30C9\u6CD5)\n@docs docs/WarshallFloyd.md\n*/\n#line 4 \"test/aoj/GRL_1_C-WarshallFloyd.test.cpp\"\
    \nusing namespace std;\nint main() {\n    int V, E; cin >> V >> E;\n    auto D\
    \ = make_vec<ll>(V, V, INF);\n    rep (i, E) {\n        int s, t, d; cin >> s\
    \ >> t >> d;\n        D[s][t] = d;\n    }\n    WarshallFloyd(D);\n    rep (i,\
    \ V) {\n        if (D[i][i] < 0) {\n            puts(\"NEGATIVE CYCLE\");\n  \
    \          return 0;\n        }\n    }\n    rep (i, V) {\n        rep (j, V) {\n\
    \            if (D[i][j] >= INF / 2) cout << \"INF\";\n            else cout <<\
    \ D[i][j];\n            cout << \" \\n\"[j == V - 1];\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C\"\
    \n#include \"../../template.hpp\"\n#include \"../../graph/shortest-path/WarshallFloyd.hpp\"\
    \nusing namespace std;\nint main() {\n    int V, E; cin >> V >> E;\n    auto D\
    \ = make_vec<ll>(V, V, INF);\n    rep (i, E) {\n        int s, t, d; cin >> s\
    \ >> t >> d;\n        D[s][t] = d;\n    }\n    WarshallFloyd(D);\n    rep (i,\
    \ V) {\n        if (D[i][i] < 0) {\n            puts(\"NEGATIVE CYCLE\");\n  \
    \          return 0;\n        }\n    }\n    rep (i, V) {\n        rep (j, V) {\n\
    \            if (D[i][j] >= INF / 2) cout << \"INF\";\n            else cout <<\
    \ D[i][j];\n            cout << \" \\n\"[j == V - 1];\n        }\n    }\n}\n"
  dependsOn:
  - template.hpp
  - graph/shortest-path/WarshallFloyd.hpp
  - graph/Graph.hpp
  isVerificationFile: true
  path: test/aoj/GRL_1_C-WarshallFloyd.test.cpp
  requiredBy: []
  timestamp: '2021-11-04 08:22:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_1_C-WarshallFloyd.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_1_C-WarshallFloyd.test.cpp
- /verify/test/aoj/GRL_1_C-WarshallFloyd.test.cpp.html
title: test/aoj/GRL_1_C-WarshallFloyd.test.cpp
---
