---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: other/monoid.hpp
    title: other/monoid.hpp
  - icon: ':heavy_check_mark:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/bitwise_and_convolution-or.test.cpp
    title: test/yosupo/bitwise_and_convolution-or.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/bitwise_and_convolution.test.cpp
    title: test/yosupo/bitwise_and_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/gcd_convolution.test.cpp
    title: test/yosupo/gcd_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/lcm_convolution.test.cpp
    title: test/yosupo/lcm_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point_set_range_composite.test.cpp
    title: test/yosupo/point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/queue_operate_all_composite.test.cpp
    title: test/yosupo/queue_operate_all_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range_affine_range_sum.test.cpp
    title: test/yosupo/range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertex_set_path_composite-HLD.test.cpp
    title: test/yosupo/vertex_set_path_composite-HLD.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertex_set_path_composite.test.cpp
    title: test/yosupo/vertex_set_path_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"other/monoid2.hpp\"\n\n#line 2 \"other/template.hpp\"\n\n\
    #include<bits/stdc++.h>\n\n#ifndef __COUNTER__\n#define __COUNTER__ __LINE__\n\
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
    \ }\n};\n#line 2 \"other/monoid.hpp\"\n\n#line 4 \"other/monoid.hpp\"\n\nnamespace\
    \ Monoid {\n\ntemplate<class T> struct Sum {\n    using value_type = T;\n    static\
    \ constexpr T op(const T& a, const T& b) { return a + b; }\n    static constexpr\
    \ T id() { return T{0}; }\n    static constexpr T inv(const T& a, const T& b)\
    \ { return a - b; }\n    static constexpr T get_inv(const T& a) { return -a; }\n\
    };\n\ntemplate<class T, T max_value = infinity<T>::max> struct Min {\n    using\
    \ value_type = T;\n    static constexpr T op(const T& a, const T& b) { return\
    \ a > b ? b : a; }\n    static constexpr T id() { return max_value; }\n};\n\n\
    template<class T, T min_value = infinity<T>::min> struct Max {\n    using value_type\
    \ = T;\n    static constexpr T op(const T& a, const T& b) { return a < b ? b :\
    \ a;}\n    static constexpr T id() { return min_value; }\n};\n\ntemplate<class\
    \ T> struct Assign {\n    using value_type = T;\n    static constexpr T op(const\
    \ T&, const T& b) { return b; }\n};\n\n\ntemplate<class T, T max_value = infinity<T>::max>\
    \ struct AssignMin {\n    using M = Min<T, max_value>;\n    using E = Assign<T>;\n\
    \    static constexpr T op(const T& a, const T&) { return a; }\n    static constexpr\
    \ T mul(const T& a, int) { return a; }\n    static constexpr T mul_op(const T&\
    \ a, int, const T&) { return a; }\n};\n\ntemplate<class T, T min_value = infinity<T>::min>\
    \ struct AssignMax {\n    using M = Max<T, min_value>;\n    using E = Assign<T>;\n\
    \    static constexpr T op(const T& a, const T&) { return a; }\n    static constexpr\
    \ T mul(const T& a, int) { return a; }\n    static constexpr T mul_op(const T&\
    \ a, int, const T&) { return a; }\n};\n\ntemplate<class T> struct AssignSum {\n\
    \    using M = Sum<T>;\n    using E = Assign<T>;\n    static constexpr T op(const\
    \ T& a, const T&) { return a; }\n    static constexpr T mul(const T& a, int b)\
    \ { return a * b; }\n    static constexpr T mul_op(const T& a, int b, const T&)\
    \ { return a * b; }\n};\n\ntemplate<class T, T max_value = infinity<T>::max> struct\
    \ AddMin {\n    using M = Min<T, max_value>;\n    using E = Sum<T>;\n    static\
    \ constexpr T op(const T& a, const T& b) { return b + a; }\n    static constexpr\
    \ T mul(const T& a, int) { return a; }\n    static constexpr T mul_op(const T&\
    \ a, int, const T& c) { return c + a; }\n};\n\ntemplate<class T, T min_value =\
    \ infinity<T>::min> struct AddMax {\n    using M = Max<T, min_value>;\n    using\
    \ E = Sum<T>;\n    static constexpr T op(const T& a, const T& b) { return b +\
    \ a; }\n    static constexpr T mul(const T& a, int) { return a; }\n    static\
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
    \ {};\n\n} // namespace Monoid\n#line 5 \"other/monoid2.hpp\"\n\nnamespace Monoid\
    \ {\n\ntemplate<class T> struct Product {\n    using value_type = T;\n    static\
    \ T op(const T& a, const T& b) {\n        return a * b;\n    }\n    static T id()\
    \ {\n        return T{1};\n    }\n    static T inv(const T& a, const T& b) {\n\
    \        return a / b;\n    }\n    static T get_inv(const T& a) {\n        return\
    \ T{1} / a;\n    }\n};\n\ntemplate<class T> struct Composite {\n    using value_type\
    \ = std::pair<T, T>;\n    static value_type op(const value_type& a, const value_type&\
    \ b) {\n        return {b.first * a.first, b.first * a.second + b.second};\n \
    \   }\n    static value_type id() {\n        return {T{1}, T{0}};\n    }\n   \
    \ static value_type get_inv(const value_type& a) {\n        return {T{1} / a.first,\
    \ - a.second / a.first};\n    }\n    static value_type inv(const value_type& a,\
    \ const value_type& b) {\n        return op(a, get_inv(b));\n    }\n};\n\ntemplate<class\
    \ T> struct GCD {\n    using value_type = T;\n    static T op(T a, T b) { return\
    \ gcd(a, b); }\n    static T id() { return 0; }\n};\ntemplate<class T> struct\
    \ LCM {\n    using value_type = T;\n    static T op(T a, T b) { return lcm(a,\
    \ b); }\n    static T id() { return 1; }\n};\n\ntemplate<class T> struct AddAssign\
    \ {\n    using value_type = std::pair<bool, T>; // false: add, true: assign\n\
    \    static value_type op(const value_type& a, const value_type& b) {\n      \
    \  if (b.first) return b;\n        return {a.first, a.second + b.second};\n  \
    \  }\n    static value_type id() { return {false, T{0}}; }\n};\n\n\ntemplate<class\
    \ T> struct AffineSum {\n    using M = Sum<T>;\n    using E = Composite<T>;\n\
    \    using U = typename E::value_type;\n    static T op(const U& a, const T& b)\
    \ { return a.first * b + a.second; };\n    static U mul(const U& a, int b) { return\
    \ U{a.first, a.second * b}; };\n    static T mul_op(const U& a, int b, const T&\
    \ c) {\n        return a.first * c + a.second * b;\n    }\n};\n\ntemplate<class\
    \ T> struct AddAssignSum {\n    using M = Sum<T>;\n    using E = AddAssign<T>;\n\
    \    using U = typename E::value_type;\n    static T op(const U& a, const T& b)\
    \ {\n        if (a.first) return a.second;\n        return b + a.second;\n   \
    \ }\n    static U mul(const U& a, int b) { return U{a.first, a.second * b}; }\n\
    \    static T mul_op(const U& a, int b, const T& c) {\n        if (a.first) return\
    \ a.second * b;\n        return c + a.second * b;\n    }\n};\n\n} // namespace\
    \ Monoid\n"
  code: "#pragma once\n\n#include \"template.hpp\"\n#include \"monoid.hpp\"\n\nnamespace\
    \ Monoid {\n\ntemplate<class T> struct Product {\n    using value_type = T;\n\
    \    static T op(const T& a, const T& b) {\n        return a * b;\n    }\n   \
    \ static T id() {\n        return T{1};\n    }\n    static T inv(const T& a, const\
    \ T& b) {\n        return a / b;\n    }\n    static T get_inv(const T& a) {\n\
    \        return T{1} / a;\n    }\n};\n\ntemplate<class T> struct Composite {\n\
    \    using value_type = std::pair<T, T>;\n    static value_type op(const value_type&\
    \ a, const value_type& b) {\n        return {b.first * a.first, b.first * a.second\
    \ + b.second};\n    }\n    static value_type id() {\n        return {T{1}, T{0}};\n\
    \    }\n    static value_type get_inv(const value_type& a) {\n        return {T{1}\
    \ / a.first, - a.second / a.first};\n    }\n    static value_type inv(const value_type&\
    \ a, const value_type& b) {\n        return op(a, get_inv(b));\n    }\n};\n\n\
    template<class T> struct GCD {\n    using value_type = T;\n    static T op(T a,\
    \ T b) { return gcd(a, b); }\n    static T id() { return 0; }\n};\ntemplate<class\
    \ T> struct LCM {\n    using value_type = T;\n    static T op(T a, T b) { return\
    \ lcm(a, b); }\n    static T id() { return 1; }\n};\n\ntemplate<class T> struct\
    \ AddAssign {\n    using value_type = std::pair<bool, T>; // false: add, true:\
    \ assign\n    static value_type op(const value_type& a, const value_type& b) {\n\
    \        if (b.first) return b;\n        return {a.first, a.second + b.second};\n\
    \    }\n    static value_type id() { return {false, T{0}}; }\n};\n\n\ntemplate<class\
    \ T> struct AffineSum {\n    using M = Sum<T>;\n    using E = Composite<T>;\n\
    \    using U = typename E::value_type;\n    static T op(const U& a, const T& b)\
    \ { return a.first * b + a.second; };\n    static U mul(const U& a, int b) { return\
    \ U{a.first, a.second * b}; };\n    static T mul_op(const U& a, int b, const T&\
    \ c) {\n        return a.first * c + a.second * b;\n    }\n};\n\ntemplate<class\
    \ T> struct AddAssignSum {\n    using M = Sum<T>;\n    using E = AddAssign<T>;\n\
    \    using U = typename E::value_type;\n    static T op(const U& a, const T& b)\
    \ {\n        if (a.first) return a.second;\n        return b + a.second;\n   \
    \ }\n    static U mul(const U& a, int b) { return U{a.first, a.second * b}; }\n\
    \    static T mul_op(const U& a, int b, const T& c) {\n        if (a.first) return\
    \ a.second * b;\n        return c + a.second * b;\n    }\n};\n\n} // namespace\
    \ Monoid\n"
  dependsOn:
  - other/template.hpp
  - other/monoid.hpp
  isVerificationFile: false
  path: other/monoid2.hpp
  requiredBy: []
  timestamp: '2022-05-01 15:10:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/bitwise_and_convolution.test.cpp
  - test/yosupo/vertex_set_path_composite-HLD.test.cpp
  - test/yosupo/gcd_convolution.test.cpp
  - test/yosupo/vertex_set_path_composite.test.cpp
  - test/yosupo/queue_operate_all_composite.test.cpp
  - test/yosupo/bitwise_and_convolution-or.test.cpp
  - test/yosupo/point_set_range_composite.test.cpp
  - test/yosupo/lcm_convolution.test.cpp
  - test/yosupo/range_affine_range_sum.test.cpp
documentation_of: other/monoid2.hpp
layout: document
redirect_from:
- /library/other/monoid2.hpp
- /library/other/monoid2.hpp.html
title: other/monoid2.hpp
---