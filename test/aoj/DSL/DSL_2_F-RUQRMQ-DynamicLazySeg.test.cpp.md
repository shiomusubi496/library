---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-struct/segment/DynamicLazySegmentTree.hpp
    title: "DynamicLazySegmentTree(\u52D5\u7684\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\
      \u30C8\u6728)"
  - icon: ':heavy_check_mark:'
    path: other/bitop.hpp
    title: other/bitop.hpp
  - icon: ':heavy_check_mark:'
    path: other/monoid.hpp
    title: other/monoid.hpp
  - icon: ':heavy_check_mark:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_F
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_F
  bundledCode: "#line 1 \"test/aoj/DSL/DSL_2_F-RUQRMQ-DynamicLazySeg.test.cpp\"\n\
    #define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_F\"\n#line 2\
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
    \ }\n};\n#line 2 \"data-struct/segment/DynamicLazySegmentTree.hpp\"\n\n#line 2\
    \ \"other/bitop.hpp\"\n\n#line 4 \"other/bitop.hpp\"\n\nnamespace bitop {\n\n\
    #define KTH_BIT(b, k) (((b) >> (k)) & 1)\n#define POW2(k) (1ull << (k))\n\n  \
    \  inline ull next_combination(int n, ull x) {\n        if (n == 0) return 1;\n\
    \        ull a = x & -x;\n        ull b = x + a;\n        return (x & ~b) / a\
    \ >> 1 | b;\n    }\n\n#define rep_comb(i, n, k) for (ull i = (1ull << (k)) - 1;\
    \ i < (1ull << (n)); i = bitop::next_combination((n), i))\n\n    inline CONSTEXPR\
    \ int msb(ull x) {\n        int res = x ? 0 : -1;\n        if (x & 0xFFFFFFFF00000000)\
    \ x &= 0xFFFFFFFF00000000, res += 32;\n        if (x & 0xFFFF0000FFFF0000) x &=\
    \ 0xFFFF0000FFFF0000, res += 16;\n        if (x & 0xFF00FF00FF00FF00) x &= 0xFF00FF00FF00FF00,\
    \ res +=  8;\n        if (x & 0xF0F0F0F0F0F0F0F0) x &= 0xF0F0F0F0F0F0F0F0, res\
    \ +=  4;\n        if (x & 0xCCCCCCCCCCCCCCCC) x &= 0xCCCCCCCCCCCCCCCC, res +=\
    \  2;\n        return res + ((x & 0xAAAAAAAAAAAAAAAA) ? 1 : 0);\n    }\n\n   \
    \ inline CONSTEXPR int ceil_log2(ull x) {\n        return x ? msb(x - 1) + 1 :\
    \ 0;\n    }\n}\n#line 2 \"other/monoid.hpp\"\n\n#line 4 \"other/monoid.hpp\"\n\
    \nnamespace Monoid {\n\ntemplate<class T> struct Sum {\n    using value_type =\
    \ T;\n    static constexpr T op(const T& a, const T& b) { return a + b; }\n  \
    \  static constexpr T id() { return T{0}; }\n    static constexpr T inv(const\
    \ T& a, const T& b) { return a - b; }\n    static constexpr T get_inv(const T&\
    \ a) { return -a; }\n};\n\ntemplate<class T, T max_value = infinity<T>::max> struct\
    \ Min {\n    using value_type = T;\n    static constexpr T op(const T& a, const\
    \ T& b) { return a > b ? b : a; }\n    static constexpr T id() { return max_value;\
    \ }\n};\n\ntemplate<class T, T min_value = infinity<T>::min> struct Max {\n  \
    \  using value_type = T;\n    static constexpr T op(const T& a, const T& b) {\
    \ return a < b ? b : a;}\n    static constexpr T id() { return min_value; }\n\
    };\n\ntemplate<class T> struct Assign {\n    using value_type = T;\n    static\
    \ constexpr T op(const T&, const T& b) { return b; }\n};\n\n\ntemplate<class T,\
    \ T max_value = infinity<T>::max> struct AssignMin {\n    using M = Min<T, max_value>;\n\
    \    using E = Assign<T>;\n    static constexpr T op(const T& a, const T&) { return\
    \ a; }\n    static constexpr T mul(const T& a, int) { return a; }\n    static\
    \ constexpr T mul_op(const T& a, int, const T&) { return a; }\n};\n\ntemplate<class\
    \ T, T min_value = infinity<T>::min> struct AssignMax {\n    using M = Max<T,\
    \ min_value>;\n    using E = Assign<T>;\n    static constexpr T op(const T& a,\
    \ const T&) { return a; }\n    static constexpr T mul(const T& a, int) { return\
    \ a; }\n    static constexpr T mul_op(const T& a, int, const T&) { return a; }\n\
    };\n\ntemplate<class T> struct AssignSum {\n    using M = Sum<T>;\n    using E\
    \ = Assign<T>;\n    static constexpr T op(const T& a, const T&) { return a; }\n\
    \    static constexpr T mul(const T& a, int b) { return a * b; }\n    static constexpr\
    \ T mul_op(const T& a, int b, const T&) { return a * b; }\n};\n\ntemplate<class\
    \ T, T max_value = infinity<T>::max> struct AddMin {\n    using M = Min<T, max_value>;\n\
    \    using E = Sum<T>;\n    static constexpr T op(const T& a, const T& b) { return\
    \ b + a; }\n    static constexpr T mul(const T& a, int) { return a; }\n    static\
    \ constexpr T mul_op(const T& a, int, const T& c) { return c + a; }\n};\n\ntemplate<class\
    \ T, T min_value = infinity<T>::min> struct AddMax {\n    using M = Max<T, min_value>;\n\
    \    using E = Sum<T>;\n    static constexpr T op(const T& a, const T& b) { return\
    \ b + a; }\n    static constexpr T mul(const T& a, int) { return a; }\n    static\
    \ constexpr T mul_op(const T& a, int, const T& c) { return c + a; }\n};\n\ntemplate<class\
    \ T> struct AddSum {\n    using M = Sum<T>;\n    using E = Sum<T>;\n    static\
    \ constexpr T op(const T& a, const T& b) { return b + a; }\n    static constexpr\
    \ T mul(const T& a, int b) { return a * b; }\n    static constexpr T mul_op(const\
    \ T& a, int b, const T& c) { return c + a * b; }\n};\n\ntemplate<class T, T max_value\
    \ = infinity<T>::max> struct ChminMin {\n    using M = Min<T, max_value>;\n  \
    \  using E = Min<T>;\n    static constexpr T op(const T& a, const T& b) { return\
    \ std::min(b, a); }\n    static constexpr T mul(const T& a, int) { return a; }\n\
    \    static constexpr T mul_op(const T& a, int, const T& c) { return std::min(c,\
    \ a); }\n};\n\ntemplate<class T, T min_value = infinity<T>::min> struct ChminMax\
    \ {\n    using M = Max<T, min_value>;\n    using E = Min<T>;\n    static constexpr\
    \ T op(const T& a, const T& b) { return std::min(b, a); }\n    static constexpr\
    \ T mul(const T& a, int) { return a; }\n    static constexpr T mul_op(const T&\
    \ a, int, const T& c) { return std::min(c, a); }\n};\n\ntemplate<class T, T max_value\
    \ = infinity<T>::max> struct ChmaxMin {\n    using M = Min<T, max_value>;\n  \
    \  using E = Max<T>;\n    static constexpr T op(const T& a, const T& b) { return\
    \ std::max(b, a); }\n    static constexpr T mul(const T& a, int) { return a; }\n\
    \    static constexpr T mul_op(const T& a, int, const T& c) { return std::max(c,\
    \ a); }\n};\n\ntemplate<class T, T min_value = infinity<T>::min> struct ChmaxMax\
    \ {\n    using M = Max<T, min_value>;\n    using E = Max<T>;\n    static constexpr\
    \ T op(const T& a, const T& b) { return std::max(b, a); }\n    static constexpr\
    \ T mul(const T& a, int) { return a; }\n    static constexpr T mul_op(const T&\
    \ a, int, const T& c) { return std::max(c, a); }\n};\n\n\ntemplate<class M> struct\
    \ ReverseMonoid {\n    using value_type = typename M::value_type;\n    static\
    \ value_type op(const value_type& a, const value_type& b) {\n        return M::op(b,\
    \ a);\n    }\n    static value_type id() { return M::id(); }\n    static value_type\
    \ get_inv(const value_type& a) { return M::get_inv(a); }\n};\n\ntemplate<class\
    \ M_> struct AttachEffector {\n    using M = M_;\n    using E = M_;\n    using\
    \ T = typename M_::value_type;\n    static T op(const T& a, const T& b) { return\
    \ M_::op(b, a); }\n};\n\ntemplate<class E_> struct AttachMonoid {\n    using M\
    \ = E_;\n    using E = E_;\n    using T = typename E_::value_type;\n    static\
    \ T op(const T& a, const T& b) { return E_::op(b, a); }\n};\n\n\ntemplate<class\
    \ M, class = void> class has_id : public std::false_type {};\ntemplate<class M>\
    \ class has_id<M, decltype((void)M::id)> : public std::true_type {};\n\ntemplate<class\
    \ M, class = void> class has_inv : public std::false_type {};\ntemplate<class\
    \ M> class has_inv<M, decltype((void)M::inv)> : public std::true_type {};\n\n\
    template<class M, class = void> class has_get_inv : public std::false_type {};\n\
    template<class M> class has_get_inv<M, decltype((void)M::get_inv)> : public std::true_type\
    \ {};\n\n\ntemplate<class A, class = void> class has_mul : public std::false_type\
    \ {};\ntemplate<class A> class has_mul<A, decltype((void)A::mul)> : public std::true_type\
    \ {};\n\ntemplate<class A, class = void> class has_mul_op : public std::false_type\
    \ {};\ntemplate<class A> class has_mul_op<A, decltype((void)A::mul_op)> : public\
    \ std::true_type {};\n\n\ntemplate<class T, class = void> class is_semigroup :\
    \ public std::false_type {};;\ntemplate<class T> class is_semigroup<T, decltype(std::declval<typename\
    \ T::value_type>(), (void)T::op)> : public std::true_type {};\n\ntemplate<class\
    \ T, class = void> class is_monoid : public std::false_type {};;\ntemplate<class\
    \ T> class is_monoid<T, decltype(std::declval<typename T::value_type>(), (void)T::op,\
    \ (void)T::id)> : public std::true_type {};\n\ntemplate<class T, class = void>\
    \ class is_group : public std::false_type {};;\ntemplate<class T> class is_group<T,\
    \ decltype(std::declval<typename T::value_type>(), (void)T::op, (void)T::id, (void)T::get_inv)>\
    \ : public std::true_type {};\n\ntemplate<class T, class = void> class is_action\
    \ : public std::true_type {};\ntemplate<class T> class is_action<T, decltype(std::declval<typename\
    \ T::M>(), std::declval<typename T::E>(), (void)T::op)> : public std::false_type\
    \ {};\n\n} // namespace Monoid\n#line 6 \"data-struct/segment/DynamicLazySegmentTree.hpp\"\
    \n\ntemplate<class A> class DynamicLazySegmentTree {\n  protected:\n    using\
    \ M = typename A::M;\n    using E = typename A::E;\n    using T = typename M::value_type;\n\
    \    using U = typename E::value_type;\n    struct node;\n    using node_ptr =\
    \ std::unique_ptr<node>;\n    struct node {\n        T val;\n        U lazy;\n\
    \        bool lazyflag;\n        node_ptr l, r;\n        node_ptr& get_l(const\
    \ T& v) {\n            if (l == nullptr) l = std::make_unique<node>(v);\n    \
    \        return l;\n        }\n        node_ptr& get_r(const T& v) {\n       \
    \     if (r == nullptr) r = std::make_unique<node>(v);\n            return r;\n\
    \        }\n        void update() {\n            val = M::id();\n            if\
    \ (l != nullptr) val = M::op(val, l->val);\n            if (r != nullptr) val\
    \ = M::op(val, r->val);\n        }\n        node(const T& v) : val(v), lazyflag(false),\
    \ l(nullptr), r(nullptr) {}\n        node(const T& v, const U& x) : val(v), lazy(x),\
    \ lazyflag(true), l(nullptr), r(nullptr) {}\n    };\n    void all_apply(node_ptr&\
    \ p, ll t, const U& x) {\n        p->val = A::op(x, p->val);\n        if (t !=\
    \ 0) {\n            if (p->lazyflag) {\n                p->lazy = E::op(p->lazy,\
    \ x);\n            }\n            else {\n                p->lazy = x;\n     \
    \           p->lazyflag = true;\n            }\n        }\n    }\n    void eval(node_ptr&\
    \ p, ll a, ll b, int t) {\n        if (p->lazyflag) {\n            ll m = (a +\
    \ b) >> 1;\n            all_apply(p->get_l(m <= ori ? iv[t - 1] : iv2[t - 1]),\
    \ t - 1, p->lazy);\n            all_apply(p->get_r(b <= ori ? iv[t - 1] : iv2[t\
    \ - 1]), t - 1, p->lazy);\n            p->lazyflag = false;\n        }\n    }\n\
    \    ll ori, h, n;\n    std::vector<T> iv, iv2;\n    node_ptr root;\n    template<class\
    \ Upd> void update(node_ptr& nd, ll a, ll b, int t, ll k, const Upd& upd) {\n\
    \        if (a + 1 == b) {\n            nd->val = upd(nd->val);\n            return;\n\
    \        }\n        eval(nd, a, b, t);\n        ll m = (a + b) >> 1;\n       \
    \ if (k < m) update(nd->get_l(m <= ori ? iv[t - 1] : iv2[t - 1]), a, m, t - 1,\
    \ k, upd);\n        else update(nd->get_r(b <= ori ? iv[t - 1] : iv2[t - 1]),\
    \ m, b, t - 1, k, upd);\n        nd->update();\n    }\n    T prod(node_ptr& nd,\
    \ ll a, ll b, int t, ll l, ll r) {\n        if (nd == nullptr) return M::id();\n\
    \        if (l <= a && b <= r) return nd->val;\n        if (r <= a || b <= l)\
    \ return M::id();\n        eval(nd, a, b, t);\n        ll m = (a + b) >> 1;\n\
    \        return M::op(prod(nd->l, a, m, t - 1, l, r), prod(nd->r, m, b, t - 1,\
    \ l, r));\n    }\n    void apply(node_ptr& nd, ll a, ll b, int t, ll l, ll r,\
    \ const U& x) {\n        if (l <= a && b <= r) {\n            all_apply(nd, t,\
    \ x);\n            return;\n        }\n        if (r <= a || b <= l) return;\n\
    \        eval(nd, a, b, t);\n        ll m = (a + b) >> 1;\n        apply(nd->get_l(m\
    \ <= ori ? iv[t - 1] : iv2[t - 1]), a, m, t - 1, l, r, x);\n        apply(nd->get_r(b\
    \ <= ori ? iv[t - 1] : iv2[t - 1]), m, b, t - 1, l, r, x);\n        nd->update();\n\
    \    }\n    template<class Cond> ll max_right(node_ptr& nd, ll a, ll b, int t,\
    \ ll l, const Cond& cond, T& sm) {\n        if (nd == nullptr || b <= l) return\
    \ n;\n        if (l <= a && cond(M::op(sm, nd->val))) {\n            sm = M::op(sm,\
    \ nd->val);\n            return n;\n        }\n        eval(nd, a, b, t);\n  \
    \      if (a + 1 == b) return a;\n        ll m = (a + b) >> 1;\n        ll res\
    \ = max_right(nd->l, a, m, t - 1, l, cond, sm);\n        if (res != n) return\
    \ res;\n        return max_right(nd->r, m, b, t - 1, l, cond, sm);\n    }\n  \
    \  template<class Cond> ll min_left(node_ptr& nd, ll a, ll b, int t, ll r, const\
    \ Cond& cond, T& sm) {\n        if (nd == nullptr || r <= a) return 0;\n     \
    \   if (b <= r && cond(M::op(nd->val, sm))) {\n            sm = M::op(nd->val,\
    \ sm);\n            return 0;\n        }\n        eval(nd, a, b, t);\n       \
    \ if (a + 1 == b) return b;\n        ll m = (a + b) >> 1;\n        ll res = min_left(nd->r,\
    \ m, b, t - 1, r, cond, sm);\n        if (res != 0) return res;\n        return\
    \ min_left(nd->l, a, m, t - 1, r, cond, sm);\n    }\n    void reset(node_ptr&\
    \ nd, ll a, ll b, ll l, ll r) {\n        if (nd == nullptr) return;\n        if\
    \ (r <= a || b <= l) return;\n        if (l <= a && b <= r) {\n            if\
    \ (nd == root) nd = std::make_unique<node>(iv2[h]);\n            else nd.reset();\n\
    \            return;\n        }\n        ll m = (a + b) >> 1;\n        reset(nd->l,\
    \ a, m, l, r);\n        reset(nd->r, m, b, l, r);\n        nd->update();\n   \
    \ }\n    void init_copy(node_ptr& nd, const node_ptr& src) {\n        if (src\
    \ == nullptr) return;\n        if (src->lazyflag) nd = std::make_unique<node>(src->val,\
    \ src->lazy);\n        else nd = std::make_unique<node>(src->val);\n        init_copy(nd->l,\
    \ src->l);\n        init_copy(nd->r, src->r);\n    }\n  public:\n    DynamicLazySegmentTree()\
    \ : DynamicLazySegmentTree(inf) {}\n    DynamicLazySegmentTree(ll n_) { init(n_);\
    \ }\n    DynamicLazySegmentTree(ll n_, const T& v) { init(n_, v); }\n    DynamicLazySegmentTree(const\
    \ DynamicLazySegmentTree& other)\n            : n(other.n), h(other.h), ori(other.ori),\
    \ iv(other.iv), iv2(other.iv2),\n            root(std::make_unique<node>(other.root->val))\
    \ {\n        init_copy(root, other.root);\n    }\n    DynamicLazySegmentTree(DynamicLazySegmentTree&&)\
    \ = default;\n    DynamicLazySegmentTree& operator=(const DynamicLazySegmentTree&\
    \ other) {\n        if (this == &other) return *this;\n        n = other.n;\n\
    \        h = other.h;\n        ori = other.ori;\n        iv = other.iv;\n    \
    \    iv2 = other.iv2;\n        root = std::make_unique<node>(other.root->val);\n\
    \        init_copy(root, other.root);\n        return *this;\n    }\n    DynamicLazySegmentTree&\
    \ operator=(DynamicLazySegmentTree&&) = default;\n    void init(ll n_, const T&\
    \ v = M::id()) {\n        ori = n_;\n        h = bitop::ceil_log2(ori);\n    \
    \    n = 1ull << h;\n        iv.reserve(h + 1); iv.push_back(v);\n        rep\
    \ (h) iv.push_back(M::op(iv.back(), iv.back()));\n        iv2.assign(h + 1, M::id());\n\
    \        rep (i, h) {\n            if ((ori >> i) & 1) iv2[i + 1] = M::op(iv2[i],\
    \ iv[i]);\n            else iv2[i + 1] = iv2[i];\n        }\n        if (ori ==\
    \ n) iv2[h] = M::op(iv2[h], iv[h]);\n        root = std::make_unique<node>(iv2[h]);\n\
    \    }\n    template<class Upd> void update(ll k, const Upd& upd) {\n        assert(0\
    \ <= k && k < ori);\n        update(root, 0, n, h, k, upd);\n    }\n    void set(ll\
    \ k, T x) {\n        update(k, [&](const T&) -> T { return x; });\n    }\n   \
    \ void apply(ll k, const U& x) {\n        update(k, [&](const T& a) -> T { return\
    \ A::op(a, x); });\n    }\n    void apply(ll l, ll r, const U& x) {\n        assert(0\
    \ <= l && l <= r && r <= ori);\n        apply(root, 0, n, h, l, r, x);\n    }\n\
    \    T prod(ll l, ll r) {\n        assert(0 <= l && l <= r && r <= ori);\n   \
    \     return prod(root, 0, n, h, l, r);\n    }\n    T all_prod() const { return\
    \ root->val; }\n    T get(ll k) { return prod(k, k + 1); }\n    template<class\
    \ Cond> ll max_right(ll l, const Cond& cond) {\n        assert(0 <= l && l <=\
    \ ori);\n        if (l == n) return n;\n        T sm = M::id();\n        assert(cond(sm));\n\
    \        return std::min(max_right(root, 0, n, h, l, cond, sm), ori);\n    }\n\
    \    template<class Cond> ll min_left(ll r, const Cond& cond) {\n        assert(0\
    \ <= r && r <= ori);\n        if (0 == r) return 0;\n        T sm = M::id();\n\
    \        assert(cond(sm));\n        return min_left(root, 0, n, h, r, cond, sm);\n\
    \    }\n    void reset(ll l, ll r) { reset(root, 0, n, l, r); }\n    void reset(ll\
    \ k) { reset(root, 0, n, k, k + 1); }\n};\n\n\ntemplate<class A> class DynamicMultiLazySegmentTree\
    \ {\n  protected:\n    using M_ = typename A::M;\n    using E_ = typename A::E;\n\
    \    using T_ = typename M_::value_type;\n    using U_ = typename E_::value_type;\n\
    \    struct MultiA {\n        struct M {\n            struct value_type {\n  \
    \              T_ val;\n                ll len;\n                value_type()\
    \ = default;\n                value_type(T_ v, ll l) : val(v), len(l) {}\n   \
    \             friend std::ostream& operator<<(std::ostream& ost, const value_type&\
    \ e) { return ost << e.val << '*' << e.len; }\n            };\n            static\
    \ value_type op(const value_type& a, const value_type& b) { return {M_::op(a.val,\
    \ b.val), a.len + b.len}; }\n            static value_type id() { return {M_::id(),\
    \ 0}; }\n        };\n        using E = E_;\n        using T = typename M::value_type;\n\
    \        using U = typename E::value_type;\n        template<bool AlwaysTrue =\
    \ true, typename std::enable_if< Monoid::has_mul_op<A>::value && AlwaysTrue>::type*\
    \ = nullptr>\n        static T op(const U& a, const T& b) { return {A::mul_op(a,\
    \ b.len, b.val), b.len}; }\n        template<bool AlwaysTrue = true, typename\
    \ std::enable_if<!Monoid::has_mul_op<A>::value && AlwaysTrue>::type* = nullptr>\n\
    \        static T op(const U& a, const T& b) { return {A::op(A::mul(a, b.len),\
    \ b.val), b.len}; }\n    };\n    using elm = typename MultiA::M::value_type;\n\
    \    DynamicLazySegmentTree<MultiA> seg;\n  public:\n    DynamicMultiLazySegmentTree()\
    \ : DynamicMultiLazySegmentTree(inf) {}\n    DynamicMultiLazySegmentTree(ll n_)\
    \ : seg(n_, {M_::id(), 1}) {}\n    void init(ll n_, const T_& v = M_::id()) {\
    \ seg.init(n_, {v, 1}); }\n    T_ prod(ll l, ll r) { return seg.prod(l, r).val;\
    \ }\n    T_ get(ll k) { return seg.get(k).val; }\n    T_ all_prod() const { return\
    \ seg.all_prod().val; }\n    template<class Upd> void update(ll k, const Upd&\
    \ upd) { seg.update(k, [&](const elm& a) -> elm { return {upd(a.val), a.len};\
    \ }); }\n    void set(ll k, T_ x) { seg.set(k, elm{x, 1}); }\n    void apply(ll\
    \ k, U_ x) { seg.apply(k, x); }\n    void apply(ll l, ll r, U_ x) { seg.apply(l,\
    \ r, x); }\n    template<class C> ll max_right(ll l, const C& cond) { return seg.max_right(l,\
    \ [&](const elm& a) -> bool { return cond(a.val); }); }\n    template<class C>\
    \ ll min_left(ll r, const C& cond) { return seg.min_left(r, [&](const elm& a)\
    \ -> bool { return cond(a.val); }); }\n};\n\n/**\n * @brief DynamicLazySegmentTree(\u52D5\
    \u7684\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)\n * @docs docs/DynamicLazySegmentTree.md\n\
    \ */\n#line 4 \"test/aoj/DSL/DSL_2_F-RUQRMQ-DynamicLazySeg.test.cpp\"\nusing namespace\
    \ std;\nint main() {\n    int n, q; cin >> n >> q;\n    DynamicLazySegmentTree<Monoid::AssignMin<int,\
    \ (1ull << 31) - 1>> RUQRMQ(n);\n    rep (q) {\n        int t; cin >> t;\n   \
    \     if (t == 0) {\n            int l, r, x; cin >> l >> r >> x;\n          \
    \  RUQRMQ.apply(l, r + 1, x);\n        }\n        else {\n            int l, r;\
    \ cin >> l >> r;\n            cout << RUQRMQ.prod(l, r + 1) << endl;\n       \
    \ }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_F\"\n#include\
    \ \"../../../other/template.hpp\"\n#include \"../../../data-struct/segment/DynamicLazySegmentTree.hpp\"\
    \nusing namespace std;\nint main() {\n    int n, q; cin >> n >> q;\n    DynamicLazySegmentTree<Monoid::AssignMin<int,\
    \ (1ull << 31) - 1>> RUQRMQ(n);\n    rep (q) {\n        int t; cin >> t;\n   \
    \     if (t == 0) {\n            int l, r, x; cin >> l >> r >> x;\n          \
    \  RUQRMQ.apply(l, r + 1, x);\n        }\n        else {\n            int l, r;\
    \ cin >> l >> r;\n            cout << RUQRMQ.prod(l, r + 1) << endl;\n       \
    \ }\n    }\n}\n"
  dependsOn:
  - other/template.hpp
  - data-struct/segment/DynamicLazySegmentTree.hpp
  - other/bitop.hpp
  - other/monoid.hpp
  isVerificationFile: true
  path: test/aoj/DSL/DSL_2_F-RUQRMQ-DynamicLazySeg.test.cpp
  requiredBy: []
  timestamp: '2022-06-12 17:29:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL/DSL_2_F-RUQRMQ-DynamicLazySeg.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL/DSL_2_F-RUQRMQ-DynamicLazySeg.test.cpp
- /verify/test/aoj/DSL/DSL_2_F-RUQRMQ-DynamicLazySeg.test.cpp.html
title: test/aoj/DSL/DSL_2_F-RUQRMQ-DynamicLazySeg.test.cpp
---
