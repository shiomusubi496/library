---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/Matrix.hpp
    title: "Matrix(\u884C\u5217)"
  - icon: ':question:'
    path: math/ModInt.hpp
    title: ModInt
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
    PROBLEM: https://judge.yosupo.jp/problem/matrix_product
    links:
    - https://judge.yosupo.jp/problem/matrix_product
  bundledCode: "#line 1 \"test/yosupo/matrix_product.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/matrix_product\"\n#line 2 \"other/template.hpp\"\
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
    \ }\n};\n#line 2 \"math/ModInt.hpp\"\n\n#line 4 \"math/ModInt.hpp\"\n\nclass ModIntBase\
    \ {};\nclass StaticModIntBase : ModIntBase {};\nclass DynamicModIntBase : ModIntBase\
    \ {};\n\ntemplate<class T> using is_ModInt = std::is_base_of<ModIntBase, T>;\n\
    template<class T> using is_StaticModInt = std::is_base_of<StaticModIntBase, T>;\n\
    template<class T> using is_DynamicModInt = std::is_base_of<DynamicModIntBase,\
    \ T>;\n\ntemplate<unsigned int mod> class StaticModInt : StaticModIntBase {\n\
    \    static_assert(mod > 0, \"mod must be greater than 0\");\n  protected:\n \
    \   unsigned int val;\n    static constexpr unsigned int inv1000000007[] = {0,\
    \ 1, 500000004, 333333336, 250000002,\n            400000003, 166666668, 142857144,\
    \ 125000001, 111111112, 700000005};\n    static constexpr unsigned int inv998244353\
    \ [] = {0, 1, 499122177, 332748118, 748683265,\n            598946612, 166374059,\
    \ 855638017, 873463809, 443664157, 299473306};\n  public:\n    StaticModInt()\
    \ : StaticModInt(0) {}\n    template<class T, typename std::enable_if<std::is_integral<T>::value>::type*\
    \ = nullptr> StaticModInt(T v) {\n        v %= (long long)mod;\n        if (v\
    \ < 0) v += (long long)mod;\n        val = v;\n    }\n    unsigned int get() const\
    \ { return val; }\n    static unsigned int get_mod() { return mod; }\n    static\
    \ StaticModInt raw(unsigned int v) {\n        StaticModInt res;\n        res.val\
    \ = v;\n        return res;\n    }\n    StaticModInt inv() const {\n        if\
    \ IF_CONSTEXPR (mod == 1000000007) {\n            if (val <= 10) return inv1000000007[val];\n\
    \        }\n        else if IF_CONSTEXPR (mod == 998244353) {\n            if\
    \ (val <= 10) return inv998244353[val];\n        }\n        return mod_inv(val,\
    \ mod);\n    }\n    StaticModInt& operator++() {\n        ++val;\n        if (val\
    \ == mod) val = 0;\n        return *this;\n    }\n    StaticModInt operator++(int)\
    \ {\n        StaticModInt res = *this;\n        ++ *this;\n        return res;\n\
    \    }\n    StaticModInt& operator--() {\n        if (val == 0) val = mod;\n \
    \       --val;\n        return *this;\n    }\n    StaticModInt operator--(int)\
    \ {\n        StaticModInt res = *this;\n        -- *this;\n        return res;\n\
    \    }\n    StaticModInt& operator+=(const StaticModInt& other) {\n        val\
    \ += other.val;\n        if (val >= mod) val -= mod;\n        return *this;\n\
    \    }\n    StaticModInt& operator-=(const StaticModInt& other) {\n        if\
    \ (val < other.val) val += mod;\n        val -= other.val;\n        return *this;\n\
    \    }\n    StaticModInt& operator*=(const StaticModInt& other) {\n        unsigned\
    \ long long a = val;\n        a *= other.val;\n        a %= mod;\n        val\
    \ = a;\n        return *this;\n    }\n    StaticModInt& operator/=(const StaticModInt&\
    \ other) {\n        *this *= other.inv();\n        return *this;\n    }\n    friend\
    \ StaticModInt operator+(const StaticModInt& lhs, const StaticModInt& rhs) {\n\
    \        return StaticModInt(lhs) += rhs;\n    }\n    friend StaticModInt operator-(const\
    \ StaticModInt& lhs, const StaticModInt& rhs) {\n        return StaticModInt(lhs)\
    \ -= rhs;\n    }\n    friend StaticModInt operator*(const StaticModInt& lhs, const\
    \ StaticModInt& rhs) {\n        return StaticModInt(lhs) *= rhs;\n    }\n    friend\
    \ StaticModInt operator/(const StaticModInt& lhs, const StaticModInt& rhs) {\n\
    \        return StaticModInt(lhs) /= rhs;\n    }\n    StaticModInt operator+()\
    \ const {\n        return StaticModInt(*this);\n    }\n    StaticModInt operator-()\
    \ const {\n        return StaticModInt::raw(0) - *this;\n    }\n    friend bool\
    \ operator==(const StaticModInt& lhs, const StaticModInt& rhs) {\n        return\
    \ lhs.val == rhs.val;\n    }\n    friend bool operator!=(const StaticModInt& lhs,\
    \ const StaticModInt& rhs) {\n        return lhs.val != rhs.val;\n    }\n    StaticModInt\
    \ pow(ll a) const {\n        StaticModInt v = *this, res = 1;\n        while (a)\
    \ {\n            if (a & 1) res *= v;\n            a >>= 1;\n            v *=\
    \ v;\n        }\n        return res;\n    }\n    friend std::ostream& operator<<(std::ostream&\
    \ ost, const StaticModInt& sm) {\n        return ost << sm.val;\n    }\n    friend\
    \ std::istream& operator>>(std::istream& ist, StaticModInt& sm) {\n        ll\
    \ v; ist >> v;\n        sm = v;\n        return ist;\n    }\n};\n\n#if __cplusplus\
    \ < 201703L\ntemplate<unsigned int mod> constexpr unsigned int StaticModInt<mod>::inv1000000007[];\n\
    template<unsigned int mod> constexpr unsigned int StaticModInt<mod>::inv998244353\
    \ [];\n#endif\n\nusing modint1000000007 = StaticModInt<1000000007>;\nusing modint998244353\
    \  = StaticModInt<998244353>;\n\ntemplate<int id> class DynamicModInt : DynamicModIntBase\
    \ {\n  protected:\n    unsigned int val;\n    static unsigned int mod;\n  public:\n\
    \    DynamicModInt() : DynamicModInt(0) {}\n    template<class T, typename std::enable_if<std::is_integral<T>::value>::type*\
    \ = nullptr> DynamicModInt(T v) {\n        v %= (long long)mod;\n        if (v\
    \ < 0) v += (long long)mod;\n        val = v;\n    }\n    unsigned int get() const\
    \ { return val; }\n    static unsigned int get_mod() { return mod; }\n    static\
    \ void set_mod(unsigned int v) { mod = v; }\n    static DynamicModInt raw(unsigned\
    \ int v) {\n        DynamicModInt res;\n        res.val = v;\n        return res;\n\
    \    }\n    DynamicModInt inv() const { return mod_inv(val, mod); }\n    DynamicModInt&\
    \ operator++() {\n        ++val;\n        if (val == mod) val = 0;\n        return\
    \ *this;\n    }\n    DynamicModInt operator++(int) {\n        DynamicModInt res\
    \ = *this;\n        ++ *this;\n        return res;\n    }\n    DynamicModInt&\
    \ operator--() {\n        if (val == 0) val = mod;\n        --val;\n        return\
    \ *this;\n    }\n    DynamicModInt operator--(int) {\n        DynamicModInt res\
    \ = *this;\n        -- *this;\n        return res;\n    }\n    DynamicModInt&\
    \ operator+=(const DynamicModInt& other) {\n        val += other.val;\n      \
    \  if (val >= mod) val -= mod;\n        return *this;\n    }\n    DynamicModInt&\
    \ operator-=(const DynamicModInt& other) {\n        if (val < other.val) val +=\
    \ mod;\n        val -= other.val;\n        return *this;\n    }\n    DynamicModInt&\
    \ operator*=(const DynamicModInt& other) {\n        unsigned long long a = val;\n\
    \        a *= other.val;\n        a %= mod;\n        val = a;\n        return\
    \ *this;\n    }\n    DynamicModInt& operator/=(const DynamicModInt& other) {\n\
    \        *this *= other.inv();\n        return *this;\n    }\n    friend DynamicModInt\
    \ operator+(const DynamicModInt& lhs, const DynamicModInt& rhs) {\n        return\
    \ DynamicModInt(lhs) += rhs;\n    }\n    friend DynamicModInt operator-(const\
    \ DynamicModInt& lhs, const DynamicModInt& rhs) {\n        return DynamicModInt(lhs)\
    \ -= rhs;\n    }\n    friend DynamicModInt operator*(const DynamicModInt& lhs,\
    \ const DynamicModInt& rhs) {\n        return DynamicModInt(lhs) *= rhs;\n   \
    \ }\n    friend DynamicModInt operator/(const DynamicModInt& lhs, const DynamicModInt&\
    \ rhs) {\n        return DynamicModInt(lhs) /= rhs;\n    }\n    DynamicModInt\
    \ operator+() const {\n        return DynamicModInt(*this);\n    }\n    DynamicModInt\
    \ operator-() const {\n        return DynamicModInt::raw(0) - *this;\n    }\n\
    \    friend bool operator==(const DynamicModInt& lhs, const DynamicModInt& rhs)\
    \ {\n        return lhs.val == rhs.val;\n    }\n    friend bool operator!=(const\
    \ DynamicModInt& lhs, const DynamicModInt& rhs) {\n        return lhs.val != rhs.val;\n\
    \    }\n    DynamicModInt pow(ll a) const {\n        DynamicModInt v = *this,\
    \ res = 1;\n        while (a) {\n            if (a & 1) res *= v;\n          \
    \  a >>= 1;\n            v *= v;\n        }\n        return res;\n    }\n    friend\
    \ std::ostream& operator<<(std::ostream& ost, const DynamicModInt& dm) {\n   \
    \     return ost << dm.val;\n    }\n    friend std::istream& operator>>(std::istream&\
    \ ist, DynamicModInt& dm) {\n        ll v; ist >> v;\n        dm = v;\n      \
    \  return ist;\n    }\n};\n\ntemplate<int id> unsigned int DynamicModInt<id>::mod\
    \ = 1000000007;\n\nusing modint = DynamicModInt<-1>;\n\n/**\n * @brief ModInt\n\
    \ * @docs docs/ModInt.md\n */\n#line 2 \"math/Matrix.hpp\"\n\n#line 4 \"math/Matrix.hpp\"\
    \n\ntemplate<class T> class Matrix : public std::vector<std::vector<T>> {\n  protected:\n\
    \    using Base = std::vector<std::vector<T>>;\n  public:\n    Matrix() = default;\n\
    \    Matrix(int h, int w) : Base(h, std::vector<T>(w)) {}\n    Matrix(int h, int\
    \ w, const T& v) : Base(h, std::vector<T>(w, v)) {}\n    Matrix(const Base& v)\
    \ : Base(v) {}\n    Matrix(Base&& v) : Base(std::move(v)) {}\n    static Matrix\
    \ get_id(int sz) {\n        Matrix res(sz, sz, T{0});\n        rep (i, sz) res[i][i]\
    \ = T{1};\n        return res;\n    }\n    int height() const { return this->size();\
    \ }\n    int width() const { return (*this)[0].size(); }\n    Matrix& operator+=(const\
    \ Matrix& other) {\n        rep (i, this->size()) {\n            rep (j, (*this)[0].size())\
    \ (*this)[i][j] += other[i][j];\n        }\n        return *this;\n    }\n   \
    \ Matrix& operator-=(const Matrix& other) {\n        rep (i, this->size()) {\n\
    \            rep (j, (*this)[0].size()) (*this)[i][j] -= other[i][j];\n      \
    \  }\n        return *this;\n    }\n    Matrix& operator*=(const Matrix& other)\
    \ {\n        assert(this->width() == other.height());\n        Matrix res(this->size(),\
    \ other[0].size());\n        rep (i, this->size()) {\n            rep (k, other.size())\
    \ {\n                rep (j, other[0].size()) res[i][j] += (*this)[i][k] * other[k][j];\n\
    \            }\n        }\n        *this = std::move(res);\n        return *this;\n\
    \    }\n    Matrix& operator*=(T s) {\n        rep (i, this->size()) {\n     \
    \       rep (j, (*this)[0].size()) (*this)[i][j] *= s;\n        }\n        return\
    \ *this;\n    }\n    friend Matrix operator+(const Matrix& lhs, const Matrix&\
    \ rhs) {\n        return Matrix(lhs) += rhs;\n    }\n    friend Matrix operator-(const\
    \ Matrix& lhs, const Matrix& rhs) {\n        return Matrix(lhs) -= rhs;\n    }\n\
    \    friend Matrix operator*(const Matrix& lhs, const Matrix& rhs) {\n       \
    \ return Matrix(lhs) *= rhs;\n    }\n    friend Matrix operator*(const Matrix&\
    \ lhs, int rhs) {\n        return Matrix(lhs) *= rhs;\n    }\n    Matrix pow(ll\
    \ b) {\n        Matrix a = *this, res = get_id(this->size());\n        while (b)\
    \ {\n            if (b & 1) res *= a;\n            a *= a;\n            b >>=\
    \ 1;\n        }\n        return res;\n    }\n};\n\n/**\n * @brief Matrix(\u884C\
    \u5217)\n * @docs docs/Matrix.md\n */\n#line 5 \"test/yosupo/matrix_product.test.cpp\"\
    \nusing namespace std;\nusing mint = modint998244353;\nusing Mat = Matrix<mint>;\n\
    int main() {\n    int N, M, K; cin >> N >> M >> K;\n    Mat A(N, M); cin >> A;\n\
    \    Mat B(M, K); cin >> B;\n    Mat C = A * B;\n    each_const (v : C) cout <<\
    \ v << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\n#include\
    \ \"../../other/template.hpp\"\n#include \"../../math/ModInt.hpp\"\n#include \"\
    ../../math/Matrix.hpp\"\nusing namespace std;\nusing mint = modint998244353;\n\
    using Mat = Matrix<mint>;\nint main() {\n    int N, M, K; cin >> N >> M >> K;\n\
    \    Mat A(N, M); cin >> A;\n    Mat B(M, K); cin >> B;\n    Mat C = A * B;\n\
    \    each_const (v : C) cout << v << endl;\n}\n"
  dependsOn:
  - other/template.hpp
  - math/ModInt.hpp
  - math/Matrix.hpp
  isVerificationFile: true
  path: test/yosupo/matrix_product.test.cpp
  requiredBy: []
  timestamp: '2022-07-26 02:52:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/matrix_product.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/matrix_product.test.cpp
- /verify/test/yosupo/matrix_product.test.cpp.html
title: test/yosupo/matrix_product.test.cpp
---
