---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/Combinatorics.hpp
    title: Combinatorics
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL/DPL_5_A.test.cpp
    title: test/aoj/DPL/DPL_5_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL/DPL_5_B.test.cpp
    title: test/aoj/DPL/DPL_5_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL/DPL_5_C.test.cpp
    title: test/aoj/DPL/DPL_5_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL/DPL_5_D.test.cpp
    title: test/aoj/DPL/DPL_5_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL/DPL_5_E.test.cpp
    title: test/aoj/DPL/DPL_5_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL/DPL_5_F.test.cpp
    title: test/aoj/DPL/DPL_5_F.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/ModInt.md
    document_title: ModInt
    links: []
  bundledCode: "#line 2 \"math/ModInt.hpp\"\n\n#line 2 \"template.hpp\"\n\n#include<bits/stdc++.h>\n\
    \n#ifndef __COUNTER__\n#define __COUNTER__ __LINE__\n#endif\n\n#define REP_SELECTER(a,\
    \ b, c, d, e, ...) e\n#define REP1_0(b, c) REP1_1(b, c)\n#define REP1_1(b, c)\
    \ for (ll REP_COUNTER_ ## c = 0; REP_COUNTER_ ## c < (ll)(b); ++ REP_COUNTER_\
    \ ## c)\n#define REP1(b) REP1_0(b, __COUNTER__)\n#define REP2(i, b) for (ll i\
    \ = 0; i < (ll)(b); ++i)\n#define REP3(i, a, b) for (ll i = (ll)(a); i < (ll)(b);\
    \ ++i)\n#define REP4(i, a, b, c) for (ll i = (ll)(a); i < (ll)(b); i += (ll)(c))\n\
    #define rep(...) REP_SELECTER(__VA_ARGS__, REP4, REP3, REP2, REP1) (__VA_ARGS__)\n\
    #define RREP2(i, a) for (ll i = (ll)(a) - 1; i >= 0; --i)\n#define RREP3(i, a,\
    \ b) for (ll i = (ll)(a) - 1; i >= (ll)(b); --i)\n#define RREP4(i, a, b, c) for\
    \ (ll i = (ll)(a) - 1; i >= (ll)(b); i -= (ll)(c))\n#define rrep(...) REP_SELECTER(__VA_ARGS__,\
    \ RREP4, RREP3, RREP2) (__VA_ARGS__)\n#define REPS2(i, b) for (ll i = 1; i <=\
    \ (ll)(b); ++i)\n#define REPS3(i, a, b) for (ll i = (ll)(a) + 1; i <= (ll)(b);\
    \ ++i)\n#define REPS4(i, a, b, c) for (ll i = (ll)(a) + 1; i <= (ll)(b); i +=\
    \ (ll)(c))\n#define reps(...) REP_SELECTER(__VA_ARGS__, REPS4, REPS3, REPS2) (__VA_ARGS__)\n\
    #define RREPS2(i, a) for (ll i = (ll)(a); i > 0; --i)\n#define RREPS3(i, a, b)\
    \ for (ll i = (ll)(a); i > (ll)(b); --i)\n#define RREPS4(i, a, b, c) for (ll i\
    \ = (ll)(a); i > (ll)(b); i -= (ll)(c))\n#define rreps(...) REP_SELECTER(__VA_ARGS__,\
    \ RREPS4, RREPS3, RREPS2) (__VA_ARGS__)\n\n#define all(v) (v).begin(), (v).end()\n\
    \nusing ll = long long;\nusing ull = unsigned long long;\nusing ld = long double;\n\
    using PLL = std::pair<ll, ll>;\ntemplate<class T> using prique = std::priority_queue<T,\
    \ std::vector<T>, std::greater<T>>;\n\ntemplate<class T> constexpr T INF = std::numeric_limits<T>::max()\
    \ / 2;\nconstexpr ll inf = INF<ll>;\nconstexpr ld EPS = 1e-8;\nconstexpr ld PI\
    \ = 3.1415926535897932384626;\n\ntemplate<class T, class U> std::ostream& operator<<(std::ostream&\
    \ ost, const std::pair<T, U>& p) {\n    return ost << p.first << ' ' << p.second;\n\
    }\ntemplate<class T, class U> std::istream& operator<<(std::istream& ist, std::pair<T,\
    \ U>& p) {\n    return ist >> p.first >> p.second;\n}\n\ntemplate<class Container,\n\
    \        std::enable_if_t<!std::is_same<Container, std::string>::value>* = nullptr>\n\
    auto operator<<(std::ostream& ost, const Container& cont)\n        -> decltype(cont.begin(),\
    \ cont.end(), ost)\n{\n    for (auto itr = cont.begin(); itr != cont.end(); ++itr)\
    \ {\n        if (itr != cont.begin()) ost << ' ';\n        ost << *itr;\n    }\n\
    \    return ost;\n}\ntemplate<class Container,\n        std::enable_if_t<!std::is_same<Container,\
    \ std::string>::value>* = nullptr>\nauto operator>>(std::istream& ist, Container&\
    \ cont)\n        -> decltype(cont.begin(), cont.end(), ist)\n{\n    for (auto\
    \ itr = cont.begin(); itr != cont.end(); ++itr) ist >> *itr;\n    return ist;\n\
    }\n\ntemplate<class T, class U> inline constexpr bool chmin(T &a, const U &b)\
    \ noexcept {\n    if (a > b) {\n        a = b;\n        return true;\n    }\n\
    \    return false;\n}\ntemplate<class T, class U> inline constexpr bool chmax(T\
    \ &a, const U &b) noexcept {\n    if (a < b) {\n        a = b;\n        return\
    \ true;\n    }\n    return false;\n}\n\ninline constexpr ll gcd(ll a, ll b) noexcept\
    \ {\n    while (b) {\n        const ll c = a;\n        a = b;\n        b = c %\
    \ b;\n    }\n    return a;\n}\ninline constexpr ll lcm(ll a, ll b) noexcept {\n\
    \    return a / gcd(a, b) * b;\n}\n\ninline constexpr bool is_prime(ll N) noexcept\
    \ {\n    if (N <= 1) return false;\n    for (ll i = 2; i * i <= N; ++i) {\n  \
    \      if (N % i == 0) return false;\n    }\n    return true;\n}\ninline std::vector<ll>\
    \ prime_factor(ll N) noexcept {\n    std::vector<ll> res;\n    for (ll i = 2;\
    \ i * i <= N; ++i) {\n        while (N % i == 0) {\n            res.push_back(i);\n\
    \            N /= i;\n        }\n    }\n    if (N != 1) res.push_back(N);\n  \
    \  return res;\n}\n\ninline constexpr ll my_pow(ll a, ll b) noexcept {\n    ll\
    \ res = 1;\n    while (b) {\n        if (b & 1) res *= a;\n        b >>= 1;\n\
    \        a *= a;\n    }\n    return res;\n}\ninline constexpr ll mod_pow(ll a,\
    \ ll b, ll mod) noexcept {\n    a %= mod;\n    ll res = 1;\n    while (b) {\n\
    \        if (b & 1) (res *= a) %= mod;\n        b >>= 1;\n        (a *= a) %=\
    \ mod;\n    }\n    return res;\n}\n\nPLL extGCD(ll a, ll b) noexcept {\n    if\
    \ (b == 0) return PLL{1, 0};\n    PLL p = extGCD(b, a % b);\n    std::swap(p.first,\
    \ p.second);\n    p.second -= p.first * (a / b);\n    if (p.first < 0) {\n   \
    \     p.first += b;\n        p.second -= a;\n    }\n    return p;\n}\nll mod_inv(ll\
    \ a, ll mod) noexcept {\n    const PLL p = extGCD(a, mod);\n    assert(p.first\
    \ * a + p.second * mod == 1);\n    return p.first;\n}\nPLL ChineseRemainder(ll\
    \ b1, ll m1, ll b2, ll m2) noexcept {\n    const PLL p = extGCD(m1, m2);\n   \
    \ const ll g = p.first * m1 + p.second * m2;\n    const ll l = m1 / g * m2;\n\
    \    if((b2 - b1) % g != 0) return PLL{-1, -1};\n    const ll x = (b2 - b1) /\
    \ g * p.first % (m2 / g);\n    return {(x * m1 + b1 + l) % l, l};\n}\nPLL ChineseRemainders(const\
    \ std::vector<ll>& b, const std::vector<ll>& m) noexcept {\n    PLL res{0, 1};\n\
    \    rep (i, b.size()) {\n        res = ChineseRemainder(res.first, res.second,\
    \ b[i], m[i]);\n        if (res.first == -1) return res;\n    }\n    return res;\n\
    }\n\ntemplate<class F> class rec_lambda {\n  private:\n    F f;\n  public:\n \
    \   explicit constexpr rec_lambda(F&& f_) : f(std::forward<F>(f_)) {}\n    template<class...\
    \ Args> constexpr auto operator()(Args&&... args) const {\n        return f(*this,\
    \ std::forward<Args>(args)...);\n    }\n};\n\ntemplate<class T, class Arg> constexpr\
    \ std::vector<T> make_vec(int n, Arg&& arg) {\n    return std::vector<T>(n, arg);\n\
    }\ntemplate<class T, class... Args> constexpr auto make_vec(int n, Args&&... args)\
    \ {\n    return std::vector<decltype(make_vec<T>(args...))>\n               (n,\
    \ make_vec<T>(std::forward<Args>(args)...));\n}\n\ninline constexpr int popcnt(ull\
    \ x) {\n#if __cplusplus >= 202002L\n    return std::popcount(x);\n#endif\n   \
    \ x = (x & 0x5555555555555555) + ((x >> 1 ) & 0x5555555555555555);\n    x = (x\
    \ & 0x3333333333333333) + ((x >> 2 ) & 0x3333333333333333);\n    x = (x & 0x0f0f0f0f0f0f0f0f)\
    \ + ((x >> 4 ) & 0x0f0f0f0f0f0f0f0f);\n    x = (x & 0x00ff00ff00ff00ff) + ((x\
    \ >> 8 ) & 0x00ff00ff00ff00ff);\n    x = (x & 0x0000ffff0000ffff) + ((x >> 16)\
    \ & 0x0000ffff0000ffff);\n    return (x & 0x00000000ffffffff) + ((x >> 32) & 0x00000000ffffffff);\n\
    }\n\ntemplate<class T> class presser : public std::vector<T> {\n  private:\n \
    \   using Base = std::vector<T>;\n  public:\n    using Base::Base;\n    presser(const\
    \ std::vector<T>& vec) : Base(vec) {}\n    void push(const std::vector<T>& vec)\
    \ {\n        int n = this->size();\n        this->resize(n + vec.size());\n  \
    \      std::copy(vec.begin(), vec.end(), this->begin() + n);\n    }\n    int build()\
    \ {\n        std::sort(this->begin(), this->end());\n        this->erase(std::unique(this->begin(),\
    \ this->end()), this->end());\n        return this->size();\n    }\n    int get_index(const\
    \ T& val) const {\n        return static_cast<int>(std::lower_bound(this->begin(),\
    \ this->end(), val) - this->begin());\n    }\n    std::vector<int> pressed(const\
    \ std::vector<T>& vec) const {\n        std::vector<int> res(vec.size());\n  \
    \      rep (i, vec.size()) res[i] = this->get_index(vec[i]);\n        return res;\n\
    \    }\n    void press(std::vector<T>& vec) const {\n        static_assert(std::is_integral<T>::value,\
    \ \"cannot convert from int type\");\n        rep (i, vec.size()) vec[i] = this->get_index(vec[i]);\n\
    \    }\n};\n#line 4 \"math/ModInt.hpp\"\n\nclass ModIntBase {};\nclass StaticModIntBase\
    \ : ModIntBase {};\nclass DynamicModIntBase : ModIntBase {};\n\ntemplate<class\
    \ T> using is_ModInt = std::is_base_of<ModIntBase, T>;\ntemplate<class T> using\
    \ is_StaticModInt = std::is_base_of<StaticModIntBase, T>;\ntemplate<class T> using\
    \ is_DynamicModInt = std::is_base_of<DynamicModIntBase, T>;\n\ntemplate<ll mod>\
    \ class StaticModInt : StaticModIntBase {\n  protected:\n    ll val;\n    static\
    \ constexpr ll inv1000000007[] = {-1, 1, 500000004, 333333336, 250000002,\n  \
    \          400000003, 166666668, 142857144, 125000001, 111111112, 700000005};\n\
    \    static constexpr ll inv998244353 [] = {-1, 1, 499122177, 332748118, 748683265,\n\
    \            598946612, 166374059, 855638017, 873463809, 443664157, 299473306};\n\
    \  public:\n    StaticModInt() : StaticModInt(0) {}\n    template<class T, std::enable_if_t<std::is_integral<T>::value>*\
    \ = nullptr> StaticModInt(T v) : val(v) {\n        val %= mod;\n        if (val\
    \ < 0) val += mod;\n    }\n    ll get() const { return val; }\n    static ll get_mod()\
    \ { return mod; }\n    static StaticModInt raw(ll v) {\n        StaticModInt res;\n\
    \        res.val = v;\n        return res;\n    }\n    StaticModInt inv() const\
    \ {\n#if __cplusplus >= 201703L\n        if constexpr (mod == 1000000007) {\n\
    \            if (val <= 10) return inv1000000007[val];\n        }\n        else\
    \ if constexpr (mod == 998244353) {\n            if (val <= 10) return inv998244353[val];\n\
    \        }\n#else\n        if (mod == 1000000007) {\n            if (val <= 10)\
    \ return inv1000000007[val];\n        }\n        else if (mod == 998244353) {\n\
    \            if (val <= 10) return inv998244353[val];\n        }\n#endif\n   \
    \     return mod_inv(val, mod);\n    }\n    StaticModInt& operator++() {\n   \
    \     ++val;\n        if (val == mod) val = 0;\n        return *this;\n    }\n\
    \    StaticModInt operator++(int) {\n        StaticModInt res = *this;\n     \
    \   ++ *this;\n        return res;\n    }\n    StaticModInt& operator--() {\n\
    \        if (val == 0) val = mod;\n        --val;\n        return *this;\n   \
    \ }\n    StaticModInt operator--(int) {\n        StaticModInt res = *this;\n \
    \       -- *this;\n        return res;\n    }\n    StaticModInt& operator+=(const\
    \ StaticModInt& other) {\n        val += other.val;\n        if (val >= mod) val\
    \ -= mod;\n        return *this;\n    }\n    StaticModInt& operator-=(const StaticModInt&\
    \ other) {\n        val -= other.val;\n        if (val < 0) val += mod;\n    \
    \    return *this;\n    }\n    StaticModInt& operator*=(const StaticModInt& other)\
    \ {\n        (val *= other.val) %= mod;\n        return *this;\n    }\n    StaticModInt&\
    \ operator/=(const StaticModInt& other) {\n        (val *= other.inv().get())\
    \ %= mod;\n        return *this;\n    }\n    friend StaticModInt operator+(const\
    \ StaticModInt& lhs, const StaticModInt& rhs) {\n        return StaticModInt(lhs)\
    \ += rhs;\n    }\n    friend StaticModInt operator-(const StaticModInt& lhs, const\
    \ StaticModInt& rhs) {\n        return StaticModInt(lhs) -= rhs;\n    }\n    friend\
    \ StaticModInt operator*(const StaticModInt& lhs, const StaticModInt& rhs) {\n\
    \        return StaticModInt(lhs) *= rhs;\n    }\n    friend StaticModInt operator/(const\
    \ StaticModInt& lhs, const StaticModInt& rhs) {\n        return StaticModInt(lhs)\
    \ /= rhs;\n    }\n    StaticModInt operator+() const {\n        return StaticModInt(*this);\n\
    \    }\n    StaticModInt operator-() const {\n        return StaticModInt(0) -\
    \ *this;\n    }\n    StaticModInt pow(ll a) const {\n        StaticModInt v =\
    \ *this, res = 1;\n        while (a) {\n            if (a & 1) res *= v;\n   \
    \         a >>= 1;\n            v *= v;\n        }\n        return res;\n    }\n\
    \    friend std::ostream& operator<<(std::ostream& ost, const StaticModInt& sm)\
    \ {\n        return ost << sm.val;\n    }\n    friend std::istream& operator>>(std::istream&\
    \ ist, StaticModInt& sm) {\n        return ist >> sm.val;\n    }\n};\n\n#if __cplusplus\
    \ < 201703L\ntemplate<ll mod> constexpr ll StaticModInt<mod>::inv1000000007[];\n\
    template<ll mod> constexpr ll StaticModInt<mod>::inv998244353 [];\n#endif\n\n\
    using modint1000000007 = StaticModInt<1000000007>;\nusing modint998244353  = StaticModInt<998244353>;\n\
    \ntemplate<int id> class DynamicModInt : DynamicModIntBase {\n  protected:\n \
    \   ll val;\n    static ll mod;\n  public:\n    DynamicModInt() : DynamicModInt(0)\
    \ {}\n    template<class T, std::enable_if_t<std::is_integral<T>::value>* = nullptr>\
    \ DynamicModInt(T v) : val(v) {\n        val %= mod;\n        if (val < 0) val\
    \ += mod;\n    }\n    ll get() const { return val; }\n    static ll get_mod()\
    \ { return mod; }\n    static void set_mod(ll v) { mod = v; }\n    static DynamicModInt\
    \ raw(ll v) {\n        DynamicModInt res;\n        res.val = v;\n        return\
    \ res;\n    }\n    DynamicModInt inv() const { return mod_inv(val, mod); }\n \
    \   DynamicModInt& operator++() {\n        ++val;\n        if (val == mod) val\
    \ = 0;\n        return *this;\n    }\n    DynamicModInt operator++(int) {\n  \
    \      DynamicModInt res = *this;\n        ++ *this;\n        return res;\n  \
    \  }\n    DynamicModInt& operator--() {\n        if (val == 0) val = mod;\n  \
    \      --val;\n        return *this;\n    }\n    DynamicModInt operator--(int)\
    \ {\n        DynamicModInt res = *this;\n        -- *this;\n        return res;\n\
    \    }\n    DynamicModInt& operator+=(const DynamicModInt& other) {\n        val\
    \ += other.val;\n        if (val >= mod) val -= mod;\n        return *this;\n\
    \    }\n    DynamicModInt& operator-=(const DynamicModInt& other) {\n        val\
    \ -= other.val;\n        if (val < 0) val += mod;\n        return *this;\n   \
    \ }\n    DynamicModInt& operator*=(const DynamicModInt& other) {\n        (val\
    \ *= other.val) %= mod;\n        return *this;\n    }\n    DynamicModInt& operator/=(const\
    \ DynamicModInt& other) {\n        (val *= other.inv().get()) %= mod;\n      \
    \  return *this;\n    }\n    friend DynamicModInt operator+(const DynamicModInt&\
    \ lhs, const DynamicModInt& rhs) {\n        return DynamicModInt(lhs) += rhs;\n\
    \    }\n    friend DynamicModInt operator-(const DynamicModInt& lhs, const DynamicModInt&\
    \ rhs) {\n        return DynamicModInt(lhs) -= rhs;\n    }\n    friend DynamicModInt\
    \ operator*(const DynamicModInt& lhs, const DynamicModInt& rhs) {\n        return\
    \ DynamicModInt(lhs) *= rhs;\n    }\n    friend DynamicModInt operator/(const\
    \ DynamicModInt& lhs, const DynamicModInt& rhs) {\n        return DynamicModInt(lhs)\
    \ /= rhs;\n    }\n    DynamicModInt operator+() const {\n        return DynamicModInt(*this);\n\
    \    }\n    DynamicModInt operator-() const {\n        return DynamicModInt(0)\
    \ - *this;\n    }\n    DynamicModInt pow(ll a) const {\n        DynamicModInt\
    \ v = *this, res = 1;\n        while (a) {\n            if (a & 1) res *= v;\n\
    \            a >>= 1;\n            v *= v;\n        }\n        return res;\n \
    \   }\n    friend std::ostream& operator<<(std::ostream& ost, const DynamicModInt&\
    \ sm) {\n        return ost << sm.val;\n    }\n    friend std::istream& operator>>(std::istream&\
    \ ist, DynamicModInt& sm) {\n        return ist >> sm.val;\n    }\n};\n\ntemplate<int\
    \ id> ll DynamicModInt<id>::mod = 1000000007;\n\nusing modint = DynamicModInt<-1>;\n\
    \n/**\n * @brief ModInt\n * @docs docs/ModInt.md\n */\n"
  code: "#pragma once\n\n#include \"../template.hpp\"\n\nclass ModIntBase {};\nclass\
    \ StaticModIntBase : ModIntBase {};\nclass DynamicModIntBase : ModIntBase {};\n\
    \ntemplate<class T> using is_ModInt = std::is_base_of<ModIntBase, T>;\ntemplate<class\
    \ T> using is_StaticModInt = std::is_base_of<StaticModIntBase, T>;\ntemplate<class\
    \ T> using is_DynamicModInt = std::is_base_of<DynamicModIntBase, T>;\n\ntemplate<ll\
    \ mod> class StaticModInt : StaticModIntBase {\n  protected:\n    ll val;\n  \
    \  static constexpr ll inv1000000007[] = {-1, 1, 500000004, 333333336, 250000002,\n\
    \            400000003, 166666668, 142857144, 125000001, 111111112, 700000005};\n\
    \    static constexpr ll inv998244353 [] = {-1, 1, 499122177, 332748118, 748683265,\n\
    \            598946612, 166374059, 855638017, 873463809, 443664157, 299473306};\n\
    \  public:\n    StaticModInt() : StaticModInt(0) {}\n    template<class T, std::enable_if_t<std::is_integral<T>::value>*\
    \ = nullptr> StaticModInt(T v) : val(v) {\n        val %= mod;\n        if (val\
    \ < 0) val += mod;\n    }\n    ll get() const { return val; }\n    static ll get_mod()\
    \ { return mod; }\n    static StaticModInt raw(ll v) {\n        StaticModInt res;\n\
    \        res.val = v;\n        return res;\n    }\n    StaticModInt inv() const\
    \ {\n#if __cplusplus >= 201703L\n        if constexpr (mod == 1000000007) {\n\
    \            if (val <= 10) return inv1000000007[val];\n        }\n        else\
    \ if constexpr (mod == 998244353) {\n            if (val <= 10) return inv998244353[val];\n\
    \        }\n#else\n        if (mod == 1000000007) {\n            if (val <= 10)\
    \ return inv1000000007[val];\n        }\n        else if (mod == 998244353) {\n\
    \            if (val <= 10) return inv998244353[val];\n        }\n#endif\n   \
    \     return mod_inv(val, mod);\n    }\n    StaticModInt& operator++() {\n   \
    \     ++val;\n        if (val == mod) val = 0;\n        return *this;\n    }\n\
    \    StaticModInt operator++(int) {\n        StaticModInt res = *this;\n     \
    \   ++ *this;\n        return res;\n    }\n    StaticModInt& operator--() {\n\
    \        if (val == 0) val = mod;\n        --val;\n        return *this;\n   \
    \ }\n    StaticModInt operator--(int) {\n        StaticModInt res = *this;\n \
    \       -- *this;\n        return res;\n    }\n    StaticModInt& operator+=(const\
    \ StaticModInt& other) {\n        val += other.val;\n        if (val >= mod) val\
    \ -= mod;\n        return *this;\n    }\n    StaticModInt& operator-=(const StaticModInt&\
    \ other) {\n        val -= other.val;\n        if (val < 0) val += mod;\n    \
    \    return *this;\n    }\n    StaticModInt& operator*=(const StaticModInt& other)\
    \ {\n        (val *= other.val) %= mod;\n        return *this;\n    }\n    StaticModInt&\
    \ operator/=(const StaticModInt& other) {\n        (val *= other.inv().get())\
    \ %= mod;\n        return *this;\n    }\n    friend StaticModInt operator+(const\
    \ StaticModInt& lhs, const StaticModInt& rhs) {\n        return StaticModInt(lhs)\
    \ += rhs;\n    }\n    friend StaticModInt operator-(const StaticModInt& lhs, const\
    \ StaticModInt& rhs) {\n        return StaticModInt(lhs) -= rhs;\n    }\n    friend\
    \ StaticModInt operator*(const StaticModInt& lhs, const StaticModInt& rhs) {\n\
    \        return StaticModInt(lhs) *= rhs;\n    }\n    friend StaticModInt operator/(const\
    \ StaticModInt& lhs, const StaticModInt& rhs) {\n        return StaticModInt(lhs)\
    \ /= rhs;\n    }\n    StaticModInt operator+() const {\n        return StaticModInt(*this);\n\
    \    }\n    StaticModInt operator-() const {\n        return StaticModInt(0) -\
    \ *this;\n    }\n    StaticModInt pow(ll a) const {\n        StaticModInt v =\
    \ *this, res = 1;\n        while (a) {\n            if (a & 1) res *= v;\n   \
    \         a >>= 1;\n            v *= v;\n        }\n        return res;\n    }\n\
    \    friend std::ostream& operator<<(std::ostream& ost, const StaticModInt& sm)\
    \ {\n        return ost << sm.val;\n    }\n    friend std::istream& operator>>(std::istream&\
    \ ist, StaticModInt& sm) {\n        return ist >> sm.val;\n    }\n};\n\n#if __cplusplus\
    \ < 201703L\ntemplate<ll mod> constexpr ll StaticModInt<mod>::inv1000000007[];\n\
    template<ll mod> constexpr ll StaticModInt<mod>::inv998244353 [];\n#endif\n\n\
    using modint1000000007 = StaticModInt<1000000007>;\nusing modint998244353  = StaticModInt<998244353>;\n\
    \ntemplate<int id> class DynamicModInt : DynamicModIntBase {\n  protected:\n \
    \   ll val;\n    static ll mod;\n  public:\n    DynamicModInt() : DynamicModInt(0)\
    \ {}\n    template<class T, std::enable_if_t<std::is_integral<T>::value>* = nullptr>\
    \ DynamicModInt(T v) : val(v) {\n        val %= mod;\n        if (val < 0) val\
    \ += mod;\n    }\n    ll get() const { return val; }\n    static ll get_mod()\
    \ { return mod; }\n    static void set_mod(ll v) { mod = v; }\n    static DynamicModInt\
    \ raw(ll v) {\n        DynamicModInt res;\n        res.val = v;\n        return\
    \ res;\n    }\n    DynamicModInt inv() const { return mod_inv(val, mod); }\n \
    \   DynamicModInt& operator++() {\n        ++val;\n        if (val == mod) val\
    \ = 0;\n        return *this;\n    }\n    DynamicModInt operator++(int) {\n  \
    \      DynamicModInt res = *this;\n        ++ *this;\n        return res;\n  \
    \  }\n    DynamicModInt& operator--() {\n        if (val == 0) val = mod;\n  \
    \      --val;\n        return *this;\n    }\n    DynamicModInt operator--(int)\
    \ {\n        DynamicModInt res = *this;\n        -- *this;\n        return res;\n\
    \    }\n    DynamicModInt& operator+=(const DynamicModInt& other) {\n        val\
    \ += other.val;\n        if (val >= mod) val -= mod;\n        return *this;\n\
    \    }\n    DynamicModInt& operator-=(const DynamicModInt& other) {\n        val\
    \ -= other.val;\n        if (val < 0) val += mod;\n        return *this;\n   \
    \ }\n    DynamicModInt& operator*=(const DynamicModInt& other) {\n        (val\
    \ *= other.val) %= mod;\n        return *this;\n    }\n    DynamicModInt& operator/=(const\
    \ DynamicModInt& other) {\n        (val *= other.inv().get()) %= mod;\n      \
    \  return *this;\n    }\n    friend DynamicModInt operator+(const DynamicModInt&\
    \ lhs, const DynamicModInt& rhs) {\n        return DynamicModInt(lhs) += rhs;\n\
    \    }\n    friend DynamicModInt operator-(const DynamicModInt& lhs, const DynamicModInt&\
    \ rhs) {\n        return DynamicModInt(lhs) -= rhs;\n    }\n    friend DynamicModInt\
    \ operator*(const DynamicModInt& lhs, const DynamicModInt& rhs) {\n        return\
    \ DynamicModInt(lhs) *= rhs;\n    }\n    friend DynamicModInt operator/(const\
    \ DynamicModInt& lhs, const DynamicModInt& rhs) {\n        return DynamicModInt(lhs)\
    \ /= rhs;\n    }\n    DynamicModInt operator+() const {\n        return DynamicModInt(*this);\n\
    \    }\n    DynamicModInt operator-() const {\n        return DynamicModInt(0)\
    \ - *this;\n    }\n    DynamicModInt pow(ll a) const {\n        DynamicModInt\
    \ v = *this, res = 1;\n        while (a) {\n            if (a & 1) res *= v;\n\
    \            a >>= 1;\n            v *= v;\n        }\n        return res;\n \
    \   }\n    friend std::ostream& operator<<(std::ostream& ost, const DynamicModInt&\
    \ sm) {\n        return ost << sm.val;\n    }\n    friend std::istream& operator>>(std::istream&\
    \ ist, DynamicModInt& sm) {\n        return ist >> sm.val;\n    }\n};\n\ntemplate<int\
    \ id> ll DynamicModInt<id>::mod = 1000000007;\n\nusing modint = DynamicModInt<-1>;\n\
    \n/**\n * @brief ModInt\n * @docs docs/ModInt.md\n */\n"
  dependsOn:
  - template.hpp
  isVerificationFile: false
  path: math/ModInt.hpp
  requiredBy:
  - math/Combinatorics.hpp
  timestamp: '2021-11-13 20:58:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DPL/DPL_5_E.test.cpp
  - test/aoj/DPL/DPL_5_B.test.cpp
  - test/aoj/DPL/DPL_5_F.test.cpp
  - test/aoj/DPL/DPL_5_C.test.cpp
  - test/aoj/DPL/DPL_5_A.test.cpp
  - test/aoj/DPL/DPL_5_D.test.cpp
documentation_of: math/ModInt.hpp
layout: document
redirect_from:
- /library/math/ModInt.hpp
- /library/math/ModInt.hpp.html
title: ModInt
---
## 概要

様々な演算で自動で mod を取ってくれる構造体。

- `StaticModInt` : mod が問題で与えられる等の場合に使う
- `DynamicModInt` : mod が入力で与えられる等の場合に使う

以下のメンバを持つ。

- `ll get()` : modint の持つ値を返す。 $O(1)$ 。
- `ll get_mod()` : 現在の mod を返す。 $O(1)$ 。
- `void set_mod(ll m)` : (`DynamicModInt` のみ) mod を `m` にセットする。 $O(1)$ 。
- `modint inv()` : 逆数を返す。 $O(\log mod)$ 。
- `modint pow(ll x)` : `x` 乗を返す。 $O(\log x)$ 。

### 演算

以下の演算が動く。

```
+modint
-modint

modint++
modint--
++modint
--modint

modint += modint
modint -= modint
modint *= modint
modint /= modint

modint + modint
modint - modint
modint * modint
modint / modint

cin >> modint
cout << modint
```

割り算は $O(\log mod)$ 、それ以外は $O(1)$ 。
