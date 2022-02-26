---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: other/template.hpp
    title: other/template.hpp
  - icon: ':heavy_check_mark:'
    path: string/RollingHash.hpp
    title: "RollingHash(\u30ED\u30EA\u30CF)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B
  bundledCode: "#line 1 \"test/aoj/ALDS1/ALDS1_14_B-RollingHash.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B\"\n#line 2 \"\
    other/template.hpp\"\n\n#include<bits/stdc++.h>\n\n#ifndef __COUNTER__\n#define\
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
    }\n\ntemplate<class T, class Comp = std::less<T>> class presser {\n  private:\n\
    \    std::vector<T> dat;\n    Comp cmp;\n    bool sorted = false;\n  public:\n\
    \    presser() = default;\n    presser(const Comp& cmp) : cmp(cmp) {}\n    presser(const\
    \ std::vector<T>& vec, const Comp& cmp = Comp()) : dat(vec), cmp(cmp) {}\n   \
    \ presser(std::vector<T>&& vec, const Comp& cmp = Comp()) : dat(std::move(vec)),\
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
    \ }\n};\n#line 2 \"string/RollingHash.hpp\"\n\n#line 4 \"string/RollingHash.hpp\"\
    \n\nclass RollingHash {\n  protected:\n    static constexpr ull MOD = (1ull <<\
    \ 61) - 1;\n    static constexpr ull MASK30 = (1ull << 30) - 1;\n    static constexpr\
    \ ull MASK31 = (1ull << 31) - 1;\n    static constexpr ull MASK61 = MOD;\n   \
    \ static ull calc_mod(ull a) {\n        ull res = (a & MASK61) + (a >> 61);\n\
    \        if (res >= MOD) res -= MOD;\n        return res;\n    }\n    static ull\
    \ calc_multi(ull a, ull b) {\n        ull au = a >> 31, ad = a & MASK31;\n   \
    \     ull bu = b >> 31, bd = b & MASK31;\n        ull mid = au * bd + ad * bu;\n\
    \        return calc_mod(((au * bu) << 1) + ((mid & MASK30) << 31) + (mid >> 30)\
    \ + ad * bd);\n    }\n    static ull calc_add(ull a, ull b) {\n        ull res\
    \ = a + b;\n        if (res >= MOD) res -= MOD;\n        return res;\n    }\n\
    \    ull BASE;\n    void init() {\n        BASE = (1ull << 31) + (std::random_device()()\
    \ & MASK31);\n    }\n  public:\n    class Hash {\n      protected:\n        int\
    \ n;\n        ull BASE;\n        std::vector<ull> hash;\n        std::vector<ull>\
    \ pows;\n      public:\n        template<class Cont> Hash(ull b, const Cont& str)\
    \ : BASE(b) {\n            n = str.size();\n            hash.resize(n + 1);\n\
    \            rep (i, n) hash[i + 1] = calc_add(calc_multi(hash[i], BASE), str[i]);\n\
    \            pows.resize(n + 1); pows[0] = 1;\n            rep (i, n) pows[i +\
    \ 1] = calc_multi(pows[i], BASE);\n        }\n        ull get_hash(int l, int\
    \ r) const {\n            assert(0 <= l && l <= r && r <= n);\n            return\
    \ calc_add(hash[r], MOD - calc_multi(hash[l], pows[r - l]));\n        }\n    \
    \    ull get_all() const {\n            return hash[n];\n        }\n    };\n \
    \   RollingHash() { init(); }\n    template<class Cont> Hash get_hash(const Cont&\
    \ str) const {\n        return Hash(BASE, str);\n    }\n    ull get_base() const\
    \ {\n        return BASE;\n    }\n};\n\n/**\n * @brief RollingHash(\u30ED\u30EA\
    \u30CF)\n * @docs docs/RollingHash.md\n */\n#line 4 \"test/aoj/ALDS1/ALDS1_14_B-RollingHash.test.cpp\"\
    \nusing namespace std;\nint main() {\n    string T, P; cin >> T >> P;\n    RollingHash\
    \ RH;\n    auto tr = RH.get_hash(T);\n    auto pr = RH.get_hash(P);\n    rep (i,\
    \ T.size() - P.size() + 1) {\n        if (tr.get_hash(i, i + P.size()) == pr.get_all())\
    \ cout << i << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B\"\n\
    #include \"../../../other/template.hpp\"\n#include \"../../../string/RollingHash.hpp\"\
    \nusing namespace std;\nint main() {\n    string T, P; cin >> T >> P;\n    RollingHash\
    \ RH;\n    auto tr = RH.get_hash(T);\n    auto pr = RH.get_hash(P);\n    rep (i,\
    \ T.size() - P.size() + 1) {\n        if (tr.get_hash(i, i + P.size()) == pr.get_all())\
    \ cout << i << endl;\n    }\n}\n"
  dependsOn:
  - other/template.hpp
  - string/RollingHash.hpp
  isVerificationFile: true
  path: test/aoj/ALDS1/ALDS1_14_B-RollingHash.test.cpp
  requiredBy: []
  timestamp: '2022-02-26 19:19:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1/ALDS1_14_B-RollingHash.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1/ALDS1_14_B-RollingHash.test.cpp
- /verify/test/aoj/ALDS1/ALDS1_14_B-RollingHash.test.cpp.html
title: test/aoj/ALDS1/ALDS1_14_B-RollingHash.test.cpp
---
