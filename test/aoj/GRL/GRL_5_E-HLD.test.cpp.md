---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-struct/segment/LazySegmentTree.hpp
    title: "LazySegmentTree(\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  - icon: ':question:'
    path: graph/Graph.hpp
    title: Graph-template
  - icon: ':question:'
    path: graph/tree/HeavyLightDecomposition.hpp
    title: "HeavyLightDecomposition(HL\u5206\u89E3)"
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
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_E
  bundledCode: "#line 1 \"test/aoj/GRL/GRL_5_E-HLD.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_E\"\n#line 2 \"other/template.hpp\"\
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
    \ data() && { return std::move(dat); }\n};\n#line 2 \"data-struct/segment/LazySegmentTree.hpp\"\
    \n\n#line 2 \"other/bitop.hpp\"\n\n#line 4 \"other/bitop.hpp\"\n\nnamespace bitop\
    \ {\n\n#define KTH_BIT(b, k) (((b) >> (k)) & 1)\n#define POW2(k) (1ull << (k))\n\
    \ninline ull next_combination(int n, ull x) {\n    if (n == 0) return 1;\n   \
    \ ull a = x & -x;\n    ull b = x + a;\n    return (x & ~b) / a >> 1 | b;\n}\n\n\
    #define rep_comb(i, n, k)                                                    \
    \  \\\n    for (ull i = (1ull << (k)) - 1; i < (1ull << (n));                \
    \         \\\n         i = bitop::next_combination((n), i))\n\ninline CONSTEXPR\
    \ int msb(ull x) {\n    int res = x ? 0 : -1;\n    if (x & 0xFFFFFFFF00000000)\
    \ x &= 0xFFFFFFFF00000000, res += 32;\n    if (x & 0xFFFF0000FFFF0000) x &= 0xFFFF0000FFFF0000,\
    \ res += 16;\n    if (x & 0xFF00FF00FF00FF00) x &= 0xFF00FF00FF00FF00, res +=\
    \ 8;\n    if (x & 0xF0F0F0F0F0F0F0F0) x &= 0xF0F0F0F0F0F0F0F0, res += 4;\n   \
    \ if (x & 0xCCCCCCCCCCCCCCCC) x &= 0xCCCCCCCCCCCCCCCC, res += 2;\n    return res\
    \ + ((x & 0xAAAAAAAAAAAAAAAA) ? 1 : 0);\n}\n\ninline CONSTEXPR int ceil_log2(ull\
    \ x) { return x ? msb(x - 1) + 1 : 0; }\n} // namespace bitop\n#line 2 \"other/monoid.hpp\"\
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
    \            using T_ = typename A::M::value_type;\n\n        public:\n      \
    \      T_ val;\n            ll len;\n            value_type() = default;\n   \
    \         value_type(T_ v, ll l) : val(v), len(l) {}\n            friend std::ostream&\
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
    \n        public:\n            T_ val;\n            ll len;\n            value_type()\
    \ = default;\n            value_type(T_ v, ll l) : val(v), len(l) {}\n       \
    \     friend std::ostream& operator<<(std::ostream& ost,\n                   \
    \                         const value_type& e) {\n                return ost <<\
    \ e.val << '*' << e.len;\n            }\n        };\n        static value_type\
    \ op(const value_type& a, const value_type& b) {\n            return {A::M::op(a.val,\
    \ b.val), a.len + b.len};\n        }\n        static value_type id() { return\
    \ {A::M::id(), 0}; }\n        static value_type init(ll l, ll r) { return {A::M::init(l,\
    \ r), r - l}; }\n    };\n    using E = typename A::E;\n\nprivate:\n    using T\
    \ = typename M::value_type;\n    using U = typename E::value_type;\n\npublic:\n\
    \    static T op(const U& a, const T& b) {\n        return {A::mul_op(a, b.len,\
    \ b.val), b.len};\n    }\n};\n\n} // namespace Monoid\n#line 6 \"data-struct/segment/LazySegmentTree.hpp\"\
    \n\ntemplate<class A, bool = Monoid::has_mul_op<A>::value> class LazySegmentTree\
    \ {\n    static_assert(Monoid::is_action<A>::value, \"A must be action\");\n\n\
    private:\n    using M = typename A::M;\n    using E = typename A::E;\n    using\
    \ T = typename M::value_type;\n    using U = typename E::value_type;\n    int\
    \ h, n, ori;\n    std::vector<T> data;\n    std::vector<U> lazy;\n    std::vector<bool>\
    \ lazyflag;\n    void all_apply(int k, const U& x) {\n        data[k] = A::op(x,\
    \ data[k]);\n        if (k < n) {\n            if (lazyflag[k]) {\n          \
    \      lazy[k] = E::op(lazy[k], x);\n            }\n            else {\n     \
    \           lazy[k] = x;\n                lazyflag[k] = true;\n            }\n\
    \        }\n    }\n    void eval(int k) {\n        if (lazyflag[k]) {\n      \
    \      all_apply(k << 1, lazy[k]);\n            all_apply(k << 1 ^ 1, lazy[k]);\n\
    \            lazyflag[k] = false;\n        }\n    }\n    void calc(int k) { data[k]\
    \ = M::op(data[k << 1], data[k << 1 ^ 1]); }\n\npublic:\n    LazySegmentTree()\
    \ : LazySegmentTree(0) {}\n    LazySegmentTree(int n) : LazySegmentTree(std::vector<T>(n,\
    \ M::id())) {}\n    LazySegmentTree(int n, const T& v)\n        : LazySegmentTree(std::vector<T>(n,\
    \ v)) {}\n    LazySegmentTree(const std::vector<T>& v) { init(v); }\n    void\
    \ init(const std::vector<T>& v) {\n        ori = v.size();\n        h = bitop::ceil_log2(ori);\n\
    \        n = 1 << h;\n        data.assign(n << 1, M::id());\n        rep (i, ori)\
    \ data[n + i] = v[i];\n        rrep (i, n, 1) calc(i);\n        lazy.resize(n);\n\
    \        lazyflag.assign(n, false);\n    }\n    T prod(int l, int r) {\n     \
    \   assert(0 <= l && l <= r && r <= ori);\n        if (l == r) return M::id();\n\
    \n        l += n, r += n;\n        rreps (i, h) {\n            bool seen = false;\n\
    \            if (((l >> i) << i) != l) eval(l >> i), seen = true;\n          \
    \  if (((r >> i) << i) != r) eval((r - 1) >> i), seen = true;\n            if\
    \ (!seen) break;\n        }\n\n        T lsm = M::id(), rsm = M::id();\n     \
    \   while (l != r) {\n            if (l & 1) lsm = M::op(lsm, data[l++]);\n  \
    \          if (r & 1) rsm = M::op(data[--r], rsm);\n            l >>= 1, r >>=\
    \ 1;\n        }\n        return M::op(lsm, rsm);\n    }\n    T get(int k) {\n\
    \        assert(0 <= k && k < ori);\n\n        k += n;\n        rreps (i, h) eval(k\
    \ >> i);\n        return data[k];\n    }\n    T all_prod() const { return data[1];\
    \ }\n    template<class Upd> void update(int k, const Upd& upd) {\n        assert(0\
    \ <= k && k < ori);\n\n        k += n;\n        rreps (i, h) eval(k >> i);\n \
    \       data[k] = upd(data[k]);\n        reps (i, h) calc(k >> i);\n    }\n  \
    \  void set(int k, T x) {\n        update(k, [&](const T&) -> T { return x; });\n\
    \    }\n    void apply(int k, U x) {\n        update(k, [&](const T& a) -> T {\
    \ return A::op(x, a); });\n    }\n    void apply(int l, int r, U x) {\n      \
    \  assert(0 <= l && l <= r && r <= ori);\n        if (l == r) return;\n\n    \
    \    l += n, r += n;\n        int lst = h + 1;\n        rreps (i, h) {\n     \
    \       if (((l >> i) << i) != l) eval(l >> i), lst = i;\n            if (((r\
    \ >> i) << i) != r) eval((r - 1) >> i), lst = i;\n            if (lst != i) break;\n\
    \        }\n\n        for (int l2 = l, r2 = r; l2 != r2; l2 >>= 1, r2 >>= 1) {\n\
    \            if (l2 & 1) all_apply(l2++, x);\n            if (r2 & 1) all_apply(--r2,\
    \ x);\n        }\n\n        rep (i, lst, h + 1) {\n            if (((l >> i) <<\
    \ i) != l) calc(l >> i);\n            if (((r >> i) << i) != r) calc((r - 1) >>\
    \ i);\n        }\n    }\n    template<class C> int max_right(int l, const C& cond)\
    \ {\n        assert(0 <= l && l <= ori);\n        assert(cond(M::id()));\n   \
    \     if (l == ori) return ori;\n\n        l += n;\n        rreps (i, h) {\n \
    \           if (((l >> i) << i) != l) eval(l >> i);\n            else break;\n\
    \        }\n\n        T sm = M::id();\n        do {\n            while ((l & 1)\
    \ == 0) l >>= 1;\n            if (!cond(M::op(sm, data[l]))) {\n             \
    \   while (l < n) {\n                    eval(l);\n                    l <<= 1;\n\
    \                    if (cond(M::op(sm, data[l]))) sm = M::op(sm, data[l++]);\n\
    \                }\n                return l - n;\n            }\n           \
    \ sm = M::op(sm, data[l++]);\n        } while ((l & -l) != l);\n        return\
    \ ori;\n    }\n    template<class C> int min_left(int r, const C& cond) {\n  \
    \      assert(0 <= r && r <= ori);\n        assert(cond(M::id()));\n        if\
    \ (r == 0) return 0;\n\n        r += n;\n        rreps (i, n) {\n            if\
    \ (((r >> i) << i) != r) eval((r - 1) >> i);\n            else break;\n      \
    \  }\n\n        T sm = M::id();\n        do {\n            --r;\n            while\
    \ ((r & 1) && r > 1) r >>= 1;\n            if (!cond(M::op(data[r], sm))) {\n\
    \                while (r < n) {\n                    eval(r);\n             \
    \       r = r << 1 ^ 1;\n                    if (cond(M::op(data[r], sm))) sm\
    \ = M::op(data[r--], sm);\n                }\n                return r + 1 - n;\n\
    \            }\n            sm = M::op(data[r], sm);\n        } while ((r & -r)\
    \ != r);\n        return 0;\n    }\n};\n\ntemplate<class A> class LazySegmentTree<A,\
    \ true> {\n    static_assert(Monoid::is_action<A>::value, \"A must be action\"\
    );\n\nprivate:\n    using T_ = typename A::M::value_type;\n    using U_ = typename\
    \ A::E::value_type;\n    using elm = typename Monoid::MultiAction<A>::M::value_type;\n\
    \    static std::vector<elm> get_elm_vec(const std::vector<T_>& v) {\n       \
    \ const int n = v.size();\n        std::vector<elm> res(n);\n        rep (i, n)\
    \ res[i] = elm{v[i], 1};\n        return res;\n    }\n    LazySegmentTree<Monoid::MultiAction<A>>\
    \ seg;\n\npublic:\n    LazySegmentTree() : LazySegmentTree(0) {}\n    LazySegmentTree(int\
    \ n_) : seg(n_, {A::M::id(), 1}) {}\n    LazySegmentTree(int n_, const T_& v)\
    \ : seg(n_, {v, 1}) {}\n    LazySegmentTree(const std::vector<T_>& v) : seg(get_elm_vec(v))\
    \ {}\n    void init(const std::vector<T_>& v) { seg.init(get_elm_vec(v)); }\n\
    \    T_ prod(int l, int r) { return seg.prod(l, r).val; }\n    T_ get(int k) {\
    \ return seg.get(k).val; }\n    T_ all_prod() const { return seg.all_prod().val;\
    \ }\n    template<class Upd> void update(int k, const Upd& upd) {\n        seg.update(k,\
    \ [&](const elm& a) -> elm { return {upd(a.val), a.len}; });\n    }\n    void\
    \ set(int k, T_ x) { seg.set(k, elm{x, 1}); }\n    void apply(int k, U_ x) { seg.apply(k,\
    \ x); }\n    void apply(int l, int r, U_ x) { seg.apply(l, r, x); }\n    template<class\
    \ C> int max_right(int l, const C& cond) {\n        return seg.max_right(l,\n\
    \                             [&](const elm& a) -> bool { return cond(a.val);\
    \ });\n    }\n    template<class C> int min_left(int r, const C& cond) {\n   \
    \     return seg.min_left(r,\n                            [&](const elm& a) ->\
    \ bool { return cond(a.val); });\n    }\n};\n\ntemplate<class T, T max_value =\
    \ infinity<T>::max>\nusing RangeUpdateQueryRangeMinimumQuery =\n    LazySegmentTree<Monoid::AssignMin<T,\
    \ max_value>>;\n\ntemplate<class T, T min_value = infinity<T>::min>\nusing RangeUpdateQueryRangeMaximumQuery\
    \ =\n    LazySegmentTree<Monoid::AssignMax<T, min_value>>;\n\ntemplate<class T>\n\
    using RangeUpdateQueryRangeSumQuery = LazySegmentTree<Monoid::AssignSum<T>>;\n\
    \ntemplate<class T, T max_value = infinity<T>::max>\nusing RangeAddQueryRangeMinimumQuery\
    \ =\n    LazySegmentTree<Monoid::AddMin<T, max_value>>;\n\ntemplate<class T, T\
    \ min_value = infinity<T>::min>\nusing RangeAddQueryRangeMaximumQuery =\n    LazySegmentTree<Monoid::AddMax<T,\
    \ min_value>>;\n\ntemplate<class T>\nusing RangeAddQueryRangeSumQuery = LazySegmentTree<Monoid::AddSum<T>>;\n\
    \ntemplate<class T, T max_value = infinity<T>::max>\nusing RangeChminQueryRangeMinimumQuery\
    \ =\n    LazySegmentTree<Monoid::ChminMin<T, max_value>>;\n\ntemplate<class T,\
    \ T min_value = infinity<T>::min>\nusing RangeChminQueryRangeMaximumQuery =\n\
    \    LazySegmentTree<Monoid::ChminMax<T, min_value>>;\n\ntemplate<class T, T max_value\
    \ = infinity<T>::max>\nusing RangeChmaxQueryRangeMinimumQuery =\n    LazySegmentTree<Monoid::ChmaxMin<T,\
    \ max_value>>;\n\ntemplate<class T, T min_value = infinity<T>::min>\nusing RangeChmaxQueryRangeMaximumQuery\
    \ =\n    LazySegmentTree<Monoid::ChmaxMax<T, min_value>>;\n\n/**\n * @brief LazySegmentTree(\u9045\
    \u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)\n * @docs docs/data-struct/segment/LazySegmentTree.md\n\
    \ */\n#line 2 \"graph/Graph.hpp\"\n\n#line 4 \"graph/Graph.hpp\"\n\ntemplate<class\
    \ T = int> struct edge {\n    int from, to;\n    T cost;\n    int idx;\n    edge()\
    \ : from(-1), to(-1) {}\n    edge(int f, int t, const T& c = 1, int i = -1)\n\
    \        : from(f), to(t), cost(c), idx(i) {}\n    edge(int f, int t, T&& c, int\
    \ i = -1)\n        : from(f), to(t), cost(std::move(c)), idx(i) {}\n    operator\
    \ int() const { return to; }\n    friend bool operator<(const edge<T>& lhs, const\
    \ edge<T>& rhs) {\n        return lhs.cost < rhs.cost;\n    }\n    friend bool\
    \ operator>(const edge<T>& lhs, const edge<T>& rhs) {\n        return lhs.cost\
    \ > rhs.cost;\n    }\n};\n\ntemplate<class T = int> using Edges = std::vector<edge<T>>;\n\
    template<class T = int> using GMatrix = std::vector<std::vector<T>>;\n\ntemplate<class\
    \ T = int> class Graph : public std::vector<std::vector<edge<T>>> {\nprivate:\n\
    \    using Base = std::vector<std::vector<edge<T>>>;\n\npublic:\n    int edge_id\
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
    \    const int E = std::accumulate(\n        all(G), 0, [](int a, const std::vector<edge<T>>&\
    \ v) -> int {\n            return a + v.size();\n        });\n    Edges<T> Ed(G.edge_size());\n\
    \    Ed.reserve(E);\n    rep (i, V) {\n        each_const (e : G[i]) {\n     \
    \       if (Ed[e.idx] == -1) Ed[e.idx] = e;\n            else Ed.push_back(e);\n\
    \        }\n    }\n    return Ed;\n}\n\ntemplate<class T> Graph<T> ReverseGraph(const\
    \ Graph<T>& G) {\n    const int V = G.size();\n    Graph<T> res(V);\n    rep (i,\
    \ V) {\n        each_const (e : G[i]) {\n            res[e.to].emplace_back(e.to,\
    \ e.from, e.cost, e.idx);\n        }\n    }\n    res.edge_id = G.edge_size();\n\
    \    return res;\n}\n\n\nstruct unweighted_edge {\n    template<class... Args>\
    \ unweighted_edge(const Args&...) {}\n    operator int() { return 1; }\n};\n\n\
    using UnweightedGraph = Graph<unweighted_edge>;\n\n/**\n * @brief Graph-template\n\
    \ * @docs docs/graph/Graph.md\n */\n#line 2 \"graph/tree/HeavyLightDecomposition.hpp\"\
    \n\n#line 5 \"graph/tree/HeavyLightDecomposition.hpp\"\n\ntemplate<class T> class\
    \ HeavyLightDecomposition {\nprivate:\n    int n, root, cnt;\n    std::vector<int>\
    \ ssz, head, vin, vout, par;\n    const Graph<T>& G;\n    int szdfs(int v, int\
    \ p) {\n        ssz[v] = 1;\n        each_const (e : G[v]) {\n            if (e.to\
    \ == p) continue;\n            ssz[v] += szdfs(e.to, v);\n        }\n        return\
    \ ssz[v];\n    }\n    void bldfs(int v, int p) {\n        par[v] = p;\n      \
    \  vin[v] = cnt++;\n        int idx = -1;\n        each_const (e : G[v]) {\n \
    \           if (e.to != p) {\n                if (idx == -1 || ssz[idx] < ssz[e.to])\
    \ idx = e.to;\n            }\n        }\n        if (idx != -1) {\n          \
    \  head[idx] = head[v];\n            bldfs(idx, v);\n        }\n        each_const\
    \ (e : G[v]) {\n            if (e.to != p && e.to != idx) {\n                head[e.to]\
    \ = e.to;\n                bldfs(e.to, v);\n            }\n        }\n       \
    \ vout[v] = cnt;\n    }\n    void init() {\n        n = G.size();\n        ssz.assign(n,\
    \ -1);\n        szdfs(root, -1);\n        rep (i, n) {\n            if (ssz[i]\
    \ == -1) szdfs(i, -1);\n        }\n        cnt = 0;\n        head.assign(n, -1);\n\
    \        head[root] = root;\n        vin.resize(n);\n        vout.resize(n);\n\
    \        par.resize(n);\n        bldfs(root, -1);\n        rep (i, n) {\n    \
    \        if (head[i] == -1) {\n                head[i] = i;\n                bldfs(i,\
    \ -1);\n            }\n        }\n    }\n\npublic:\n    HeavyLightDecomposition(const\
    \ Graph<T>& G, int root = 0)\n        : root(root), G(G) {\n        init();\n\
    \    }\n    int get_size(int k) const { return ssz[k]; }\n    std::pair<int, int>\
    \ get_idx(int k) const { return {vin[k], vout[k]}; }\n    std::pair<int, int>\
    \ get_pach(int a, int b) const {\n        if (vin[a] < vin[b]) return {a, b};\n\
    \        return {b, a};\n    }\n    int lca(int u, int v) const {\n        while\
    \ (head[u] != head[v]) {\n            if (vin[u] > vin[v]) std::swap(u, v);\n\
    \            v = par[head[v]];\n        }\n        return vin[u] < vin[v] ? u\
    \ : v;\n    }\n    std::vector<std::pair<int, int>> up_path(int u, int v) const\
    \ {\n        std::vector<std::pair<int, int>> res;\n        while (head[u] !=\
    \ head[v]) {\n            res.emplace_back(vin[u], vin[head[u]]);\n          \
    \  u = par[head[u]];\n        }\n        if (u != v) res.emplace_back(vin[u],\
    \ vin[v] + 1);\n        return res;\n    }\n    std::vector<std::pair<int, int>>\
    \ down_path(int u, int v) const {\n        auto res = up_path(v, u);\n       \
    \ each_for (p : res) std::swap(p.first, p.second);\n        std::reverse(all(res));\n\
    \        return res;\n    }\n    template<class F> void each_vertex(int u, int\
    \ v, const F& f) const {\n        return each_vertex(u, v, f, f);\n    }\n   \
    \ template<class F, class G>\n    void each_vertex(int u, int v, const F& f, const\
    \ G& g) const {\n        int l = lca(u, v);\n        auto func = [&](int a, int\
    \ b) {\n            if (a <= b) f(a, b + 1);\n            else g(b, a + 1);\n\
    \        };\n        each_const (p : up_path(u, l)) func(p.first, p.second);\n\
    \        func(vin[l], vin[l]);\n        each_const (p : down_path(l, v)) func(p.first,\
    \ p.second);\n    }\n    template<class F> void each_edge(int u, int v, const\
    \ F& f) const {\n        return each_edge(u, v, f, f);\n    }\n    template<class\
    \ F, class G>\n    void each_edge(int u, int v, const F& f, const G& g) const\
    \ {\n        int l = lca(u, v);\n        auto func = [&](int a, int b) {\n   \
    \         if (a <= b) f(a, b + 1);\n            else g(b, a + 1);\n        };\n\
    \        each_const (p : up_path(u, l)) func(p.first, p.second);\n        each_const\
    \ (p : down_path(l, v)) func(p.first, p.second);\n    }\n    template<class F>\
    \ void each_vertex_subtree(int u, const F& f) const {\n        f(vin[u], vout[u]);\n\
    \    }\n    template<class F> void each_edge_subtree(int u, const F& f) const\
    \ {\n        f(vin[u] + 1, vout[u]);\n    }\n};\n\n/**\n * @brief HeavyLightDecomposition(HL\u5206\
    \u89E3)\n * @docs docs/graph/tree/HeavyLightDecomposition.md\n */\n#line 6 \"\
    test/aoj/GRL/GRL_5_E-HLD.test.cpp\"\nusing namespace std;\nint main() {\n    int\
    \ n; cin >> n;\n    Graph<int> G(n);\n    rep (i, n) {\n        int k; cin >>\
    \ k;\n        rep (k) {\n            int a; cin >> a;\n            G.add_edge(i,\
    \ a);\n        }\n    }\n    HeavyLightDecomposition<int> HLD(G);\n    RangeAddQueryRangeSumQuery<ll>\
    \ seg(n);\n    int q; cin >> q;\n    rep (q) {\n        int t; cin >> t;\n   \
    \     if (t == 0) {\n            int v; ll w; cin >> v >> w;\n            HLD.each_edge(0,\
    \ v, [&](int l, int r) {\n                seg.apply(l, r, w);\n            });\n\
    \        }\n        else {\n            int u; cin >> u;\n            ll ans =\
    \ 0;\n            HLD.each_edge(0, u, [&](int l, int r) {\n                ans\
    \ += seg.prod(l, r);\n            });\n            cout << ans << endl;\n    \
    \    }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_E\"\n#include\
    \ \"../../../other/template.hpp\"\n#include \"../../../data-struct/segment/LazySegmentTree.hpp\"\
    \n#include \"../../../graph/Graph.hpp\"\n#include \"../../../graph/tree/HeavyLightDecomposition.hpp\"\
    \nusing namespace std;\nint main() {\n    int n; cin >> n;\n    Graph<int> G(n);\n\
    \    rep (i, n) {\n        int k; cin >> k;\n        rep (k) {\n            int\
    \ a; cin >> a;\n            G.add_edge(i, a);\n        }\n    }\n    HeavyLightDecomposition<int>\
    \ HLD(G);\n    RangeAddQueryRangeSumQuery<ll> seg(n);\n    int q; cin >> q;\n\
    \    rep (q) {\n        int t; cin >> t;\n        if (t == 0) {\n            int\
    \ v; ll w; cin >> v >> w;\n            HLD.each_edge(0, v, [&](int l, int r) {\n\
    \                seg.apply(l, r, w);\n            });\n        }\n        else\
    \ {\n            int u; cin >> u;\n            ll ans = 0;\n            HLD.each_edge(0,\
    \ u, [&](int l, int r) {\n                ans += seg.prod(l, r);\n           \
    \ });\n            cout << ans << endl;\n        }\n    }\n}\n"
  dependsOn:
  - other/template.hpp
  - data-struct/segment/LazySegmentTree.hpp
  - other/bitop.hpp
  - other/monoid.hpp
  - graph/Graph.hpp
  - graph/tree/HeavyLightDecomposition.hpp
  isVerificationFile: true
  path: test/aoj/GRL/GRL_5_E-HLD.test.cpp
  requiredBy: []
  timestamp: '2022-08-18 19:11:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL/GRL_5_E-HLD.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL/GRL_5_E-HLD.test.cpp
- /verify/test/aoj/GRL/GRL_5_E-HLD.test.cpp.html
title: test/aoj/GRL/GRL_5_E-HLD.test.cpp
---
