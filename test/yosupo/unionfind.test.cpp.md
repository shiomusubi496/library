---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/UnionFind.cpp
    title: graph/UnionFind.cpp
  - icon: ':heavy_check_mark:'
    path: template.cpp
    title: template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/yosupo/unionfind.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n#line 2 \"template.cpp\"\n\n#include<bits/stdc++.h>\n\n#define rep(i, n) for(int\
    \ i = 0; i < (int)(n); ++i)\n#define rrep(i, n) for(int i = (int)(n) - 1; i >=\
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
    \ 2 \"graph/UnionFind.cpp\"\n\n#line 4 \"graph/UnionFind.cpp\"\n\nclass UnionFind\
    \ {\n  protected:\n    int _n;\n    std::vector<int> par_vec;\n  public:\n   \
    \ UnionFind() : UnionFind(0) {}\n    UnionFind(int n) : _n(n), par_vec(n, -1)\
    \ {}\n    int find(int x) {\n        return par_vec[x] < 0 ? x : par_vec[x] =\
    \ find(par_vec[x]);\n    }\n    bool merge(int x, int y) {\n        x = find(x);\n\
    \        y = find(y);\n        if (x == y) return false;\n        if (par_vec[x]\
    \ > par_vec[y]) std::swap(x, y);\n        par_vec[x] += par_vec[y];\n        par_vec[y]\
    \ = x;\n        return true;\n    }\n    bool same(int x, int y) {\n        return\
    \ find(x) == find(y);\n    }\n    int size(int x) {\n        return -par_vec[find(x)];\n\
    \    }\n    std::vector<std::vector<int>> groups() {\n        std::vector<std::vector<int>>\
    \ res(_n);\n        rep(i, _n) res[find(i)].push_back(i);\n        res.erase(\n\
    \            remove_if(res.begin(), res.end(),\n                      [](const\
    \ std::vector<int>& v) { return v.empty(); }),\n            res.end());\n    \
    \    return res;\n    }\n    bool is_root(int x) const {\n        return par_vec[x]\
    \ < 0;\n    }\n    int group_size() const {\n        return count_if(par_vec.begin(),\
    \ par_vec.end(), [](int x) { return x < 0; });\n    }\n};\n#line 4 \"test/yosupo/unionfind.test.cpp\"\
    \nusing namespace std;\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    UnionFind\
    \ UF(N);\n    while (Q--) {\n        int t, u, v;\n        cin >> t >> u >> v;\n\
    \        if (t == 0) UF.merge(u, v);\n        else cout << UF.same(u, v) << endl;\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include \"\
    ../../template.cpp\"\n#include \"../../graph/UnionFind.cpp\"\nusing namespace\
    \ std;\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    UnionFind UF(N);\n\
    \    while (Q--) {\n        int t, u, v;\n        cin >> t >> u >> v;\n      \
    \  if (t == 0) UF.merge(u, v);\n        else cout << UF.same(u, v) << endl;\n\
    \    }\n}\n"
  dependsOn:
  - template.cpp
  - graph/UnionFind.cpp
  isVerificationFile: true
  path: test/yosupo/unionfind.test.cpp
  requiredBy: []
  timestamp: '2021-11-02 18:05:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/unionfind.test.cpp
- /verify/test/yosupo/unionfind.test.cpp.html
title: test/yosupo/unionfind.test.cpp
---
