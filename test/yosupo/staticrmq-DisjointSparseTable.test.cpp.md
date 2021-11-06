---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: segment/DisjointSparseTable.hpp
    title: segment/DisjointSparseTable.hpp
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/yosupo/staticrmq-DisjointSparseTable.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#line 2 \"segment/DisjointSparseTable.hpp\"\
    \n\n#line 2 \"template.hpp\"\n\n#include<bits/stdc++.h>\n\n#define rep(i, n) for\
    \ (int i = 0; i < (int)(n); ++i)\n#define rrep(i, n) for (int i = (int)(n) - 1;\
    \ i >= 0; --i)\n#define all(v) (v).begin(), (v).end()\n\nusing ll = long long;\n\
    using ull = unsigned long long;\nusing ld = long double;\nusing PLL = std::pair<ll,\
    \ ll>;\ntemplate<class T> using prique = std::priority_queue<T, std::vector<T>,\
    \ std::greater<T>>;\n\ntemplate<class T> constexpr T INF = std::numeric_limits<T>::max()\
    \ / 2;\nconstexpr ll inf = INF<ll>;\nconstexpr ld EPS = 1e-8;\nconstexpr ld PI\
    \ = 3.1415926535897932384626;\n\ntemplate<class T, class U> inline constexpr bool\
    \ chmin(T &a, const U &b) noexcept {\n    if (a > b) {\n        a = b;\n     \
    \   return true;\n    }\n    return false;\n}\ntemplate<class T, class U> inline\
    \ constexpr bool chmax(T &a, const U &b) noexcept {\n    if (a < b) {\n      \
    \  a = b;\n        return true;\n    }\n    return false;\n}\n\ninline constexpr\
    \ ll gcd(ll a, ll b) noexcept {\n    while (b) {\n        const ll c = a;\n  \
    \      a = b;\n        b = c % b;\n    }\n    return a;\n}\ninline constexpr ll\
    \ lcm(ll a, ll b) noexcept {\n    return a / gcd(a, b) * b;\n}\n\ninline constexpr\
    \ bool is_prime(ll N) noexcept {\n    if (N <= 1) return false;\n    for (ll i\
    \ = 2; i * i <= N; ++i) {\n        if (N % i == 0) return false;\n    }\n    return\
    \ true;\n}\ninline std::vector<ll> prime_factor(ll N) noexcept {\n    std::vector<ll>\
    \ res;\n    for (ll i = 2; i * i <= N; ++i) {\n        while (N % i == 0) {\n\
    \            res.push_back(i);\n            N /= i;\n        }\n    }\n    if\
    \ (N != 1) res.push_back(N);\n    return res;\n}\n\ninline constexpr ll my_pow(ll\
    \ a, ll b) noexcept {\n    ll res = 1;\n    while (b) {\n        if (b & 1) res\
    \ *= a;\n        b >>= 1;\n        a *= a;\n    }\n    return res;\n}\ninline\
    \ constexpr ll mod_pow(ll a, ll b, ll mod) noexcept {\n    a %= mod;\n    ll res\
    \ = 1;\n    while (b) {\n        if (b & 1) (res *= a) %= mod;\n        b >>=\
    \ 1;\n        (a *= a) %= mod;\n    }\n    return res;\n}\n\ntemplate<class F>\
    \ class rec_lambda {\n  private:\n    F f;\n  public:\n    explicit constexpr\
    \ rec_lambda(F&& f_) : f(std::forward<F>(f_)) {}\n    template<class... Args>\
    \ constexpr auto operator()(Args&&... args) const {\n        return f(*this, std::forward<Args>(args)...);\n\
    \    }\n};\n\ntemplate<class T, class Arg> constexpr std::vector<T> make_vec(int\
    \ n, Arg&& arg) {\n    return std::vector<T>(n, arg);\n}\ntemplate<class T, class...\
    \ Args> constexpr auto make_vec(int n, Args&&... args) {\n    return std::vector<decltype(make_vec<T>(args...))>\n\
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
    \ 4 \"segment/DisjointSparseTable.hpp\"\n\ntemplate<class T> class DisjointSparseTable\
    \ {\n  protected:\n    using F = std::function<T(T, T)>;\n    int h;\n    F op;\n\
    \    std::vector<int> logtable;\n    std::vector<std::vector<T>> data;\n  public:\n\
    \    DisjointSparseTable() = default;\n    DisjointSparseTable(const std::vector<T>&\
    \ v, const F& _op) : op(_op) {\n        h = 1;\n        while ((1 << h) < (int)v.size())\
    \ ++h;\n        logtable.resize(1 << h, 0);\n        for (int i = 2; i < (1 <<\
    \ h); ++i) logtable[i] = logtable[i >> 1] + 1;\n        data.resize(h, std::vector<T>(1\
    \ << h));\n        rep (i, h) {\n            int len = 1 << i;\n            for\
    \ (int j = len; j < v.size(); j += (len << 1)) {\n                data[i][j -\
    \ 1] = v[j - 1];\n                for (int k = 1; k < len; ++k) data[i][j - k\
    \ - 1] = op(v[j - k - 1], data[i][j - k]);\n                data[i][j] = v[j];\n\
    \                for (int k = 1; k < len; ++k) {\n                    if (j +\
    \ k >= v.size()) break;\n                    data[i][j + k] = op(data[i][j + k\
    \ - 1], v[j + k]);\n                }\n            }\n        }\n    }\n    T\
    \ query(int l, int r) {\n        assert(0 <= l && l < r && r <= (1 << h));\n \
    \       --r;\n        if (l == r) return data[0][l];\n        int d = logtable[l\
    \ ^ r];\n        return op(data[d][l], data[d][r]);\n    }\n};\n#line 3 \"test/yosupo/staticrmq-DisjointSparseTable.test.cpp\"\
    \nusing namespace std;\nint main() {\n    int N, Q; cin >> N >> Q;\n    vector<int>\
    \ A(N);\n    for (auto&& i : A) cin >> i;\n    DisjointSparseTable<int> ST(A,\
    \ [](int a, int b) -> int { return min(a, b); });\n    rep (i, Q) {\n        int\
    \ l, r; cin >> l >> r;\n        cout << ST.query(l, r) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include \"\
    ../../segment/DisjointSparseTable.hpp\"\nusing namespace std;\nint main() {\n\
    \    int N, Q; cin >> N >> Q;\n    vector<int> A(N);\n    for (auto&& i : A) cin\
    \ >> i;\n    DisjointSparseTable<int> ST(A, [](int a, int b) -> int { return min(a,\
    \ b); });\n    rep (i, Q) {\n        int l, r; cin >> l >> r;\n        cout <<\
    \ ST.query(l, r) << endl;\n    }\n}\n"
  dependsOn:
  - segment/DisjointSparseTable.hpp
  - template.hpp
  isVerificationFile: true
  path: test/yosupo/staticrmq-DisjointSparseTable.test.cpp
  requiredBy: []
  timestamp: '2021-11-06 18:55:11+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/staticrmq-DisjointSparseTable.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/staticrmq-DisjointSparseTable.test.cpp
- /verify/test/yosupo/staticrmq-DisjointSparseTable.test.cpp.html
title: test/yosupo/staticrmq-DisjointSparseTable.test.cpp
---
