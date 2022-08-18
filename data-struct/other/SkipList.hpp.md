---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: other/monoid.hpp
    title: other/monoid.hpp
  - icon: ':question:'
    path: other/template.hpp
    title: other/template.hpp
  - icon: ':heavy_check_mark:'
    path: random/Random.hpp
    title: Random
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/data_structure/dynamic_sequence_range_affine_range_sum.test.cpp
    title: test/yosupo/data_structure/dynamic_sequence_range_affine_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-struct/other/SkipList.md
    document_title: SkipList
    links: []
  bundledCode: "#line 2 \"data-struct/other/SkipList.hpp\"\n\n#line 2 \"other/template.hpp\"\
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
    \ data() && { return std::move(dat); }\n};\n#line 2 \"other/monoid.hpp\"\n\n#line\
    \ 4 \"other/monoid.hpp\"\n\nnamespace Monoid {\n\ntemplate<class M, class = void>\
    \ class has_op : public std::false_type {};\ntemplate<class M>\nclass has_op<M,\
    \ decltype((void)M::op)> : public std::true_type {};\n\ntemplate<class M, class\
    \ = void> class has_id : public std::false_type {};\ntemplate<class M>\nclass\
    \ has_id<M, decltype((void)M::id)> : public std::true_type {};\n\ntemplate<class\
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
    \ b.val), b.len};\n    }\n};\n\n} // namespace Monoid\n#line 2 \"random/Random.hpp\"\
    \n\n#line 4 \"random/Random.hpp\"\n\ntemplate<class Engine> class Random {\nprivate:\n\
    \    Engine rnd;\n\npublic:\n    using result_type = typename Engine::result_type;\n\
    \    Random() : Random(std::random_device{}()) {}\n    Random(result_type seed)\
    \ : rnd(seed) {}\n    result_type operator()() { return rnd(); }\n    template<class\
    \ IntType = ll> IntType uniform(IntType l, IntType r) {\n        static_assert(std::is_integral<IntType>::value,\n\
    \                      \"template argument must be an integral type\");\n    \
    \    assert(l <= r);\n        return std::uniform_int_distribution<IntType>{l,\
    \ r}(rnd);\n    }\n    template<class RealType = double>\n    RealType uniform_real(RealType\
    \ l, RealType r) {\n        static_assert(std::is_floating_point<RealType>::value,\n\
    \                      \"template argument must be an floating point type\");\n\
    \        assert(l <= r);\n        return std::uniform_real_distribution<RealType>{l,\
    \ r}(rnd);\n    }\n    bool uniform_bool() { return uniform<int>(0, 1) == 1; }\n\
    \    template<class T = ll> std::pair<T, T> uniform_pair(T l, T r) {\n       \
    \ assert(l < r);\n        T a, b;\n        do {\n            a = uniform<T>(l,\
    \ r);\n            b = uniform<T>(l, r);\n        } while (a == b);\n        if\
    \ (a > b) swap(a, b);\n        return {a, b};\n    }\n    template<class T = ll>\
    \ std::vector<T> choice(int n, T l, T r) {\n        assert(l <= r);\n        assert(T(n)\
    \ <= (r - l + 1));\n        std::set<T> res;\n        while ((int)res.size() <\
    \ n) res.insert(uniform<T>(l, r));\n        return {res.begin(), res.end()};\n\
    \    }\n    template<class Iter> void shuffle(const Iter& first, const Iter& last)\
    \ {\n        std::shuffle(first, last, rnd);\n    }\n    template<class T> std::vector<T>\
    \ permutation(T n) {\n        std::vector<T> res(n);\n        rep (i, n) res[i]\
    \ = i;\n        shuffle(all(res));\n        return res;\n    }\n    template<class\
    \ T = ll>\n    std::vector<T> choice_shuffle(int n, T l, T r, bool sorted = true)\
    \ {\n        assert(l <= r);\n        assert(T(n) <= (r - l + 1));\n        std::vector<T>\
    \ res(r - l + 1);\n        rep (i, l, r + 1) res[i - l] = i;\n        shuffle(all(res));\n\
    \        res.erase(res.begin() + n, res.end());\n        if (sorted) sort(all(res));\n\
    \        return res;\n    }\n};\n\nusing Random32 = Random<std::mt19937>;\nRandom32\
    \ rand32;\nusing Random64 = Random<std::mt19937_64>;\nRandom64 rand64;\n\n/**\n\
    \ * @brief Random\n * @docs docs/random/Random.md\n */\n#line 6 \"data-struct/other/SkipList.hpp\"\
    \n\ntemplate<class A, class Rand = Random32, bool = Monoid::has_mul_op<A>::value>\n\
    class SkipList {\nprivate:\n    using M = typename A::M;\n    using E = typename\
    \ A::E;\n    using T = typename M::value_type;\n    using U = typename E::value_type;\n\
    \    static inline int get_level(Rand& rnd) {\n        int level = 1;\n      \
    \  while ((rnd() & 1) == 0) ++level;\n        return level;\n    }\n    struct\
    \ node;\n    using node_ptr = node*;\n    struct next_node {\n        node_ptr\
    \ node;\n        int dist;\n        T sm;\n        U lazy;\n        bool lazyflag;\n\
    \        next_node(node_ptr n, int d, const T& s)\n            : node(n), dist(d),\
    \ sm(s), lazyflag(false) {}\n        next_node(node_ptr n, int d, const T& s,\
    \ const U& l)\n            : node(n), dist(d), sm(s), lazy(l), lazyflag(true)\
    \ {}\n    };\n    struct node {\n        std::vector<next_node> nxt;\n       \
    \ std::vector<node_ptr> prv;\n        int level() const {\n            assert(nxt.size()\
    \ == prv.size());\n            return nxt.size();\n        }\n        node(Rand&\
    \ rnd) : node(get_level(rnd)) {}\n        node(int lev) : nxt(lev, {nullptr, 1,\
    \ M::id()}), prv(lev, nullptr) {}\n    };\n    using nodepair = std::pair<node_ptr,\
    \ node_ptr>;\n    Rand rnd;\n    nodepair sl;\n    static inline void all_apply(const\
    \ node_ptr& nd, int k, const U& x) {\n        assert(0 <= k && k < nd->level());\n\
    \        nd->nxt[k].sm = A::op(x, nd->nxt[k].sm);\n        if (k != 0) {\n   \
    \         if (nd->nxt[k].lazyflag) {\n                nd->nxt[k].lazy = E::op(nd->nxt[k].lazy,\
    \ x);\n            }\n            else {\n                nd->nxt[k].lazy = x;\n\
    \                nd->nxt[k].lazyflag = true;\n            }\n        }\n    }\n\
    \    static inline void eval(const node_ptr& nd, int k) {\n        assert(0 <=\
    \ k && k < nd->level());\n        if (k != 0 && nd->nxt[k].lazyflag) {\n     \
    \       for (auto ptr = nd; ptr != nd->nxt[k].node;\n                 ptr = ptr->nxt[k\
    \ - 1].node) {\n                all_apply(ptr, k - 1, nd->nxt[k].lazy);\n    \
    \        }\n            nd->nxt[k].lazyflag = false;\n        }\n    }\n    static\
    \ inline void all_eval(const nodepair& sl, int k) {\n        auto nd = sl.first;\n\
    \        int cnt = 0;\n        rrep (i, sl.first->level(), 1) {\n            while\
    \ (cnt + nd->nxt[i].dist <= k) {\n                cnt += nd->nxt[i].dist;\n  \
    \              nd = nd->nxt[i].node;\n            }\n            eval(nd, i);\n\
    \        }\n    }\n    static inline void calc(const node_ptr& l, int k) {\n \
    \       assert(1 <= k && k < l->level());\n        l->nxt[k].sm = l->nxt[k - 1].sm;\n\
    \        for (node_ptr ptr = l->nxt[k - 1].node; ptr != l->nxt[k].node;\n    \
    \         ptr = ptr->nxt[k - 1].node) {\n            l->nxt[k].sm = M::op(l->nxt[k].sm,\
    \ ptr->nxt[k - 1].sm);\n        }\n    }\n    static inline void all_calc(const\
    \ nodepair& sl, int k) {\n        auto nd = sl.first;\n        int cnt = 0;\n\
    \        std::vector<node_ptr> nds(sl.first->level());\n        rrep (i, sl.first->level(),\
    \ 1) {\n            while (cnt + nd->nxt[i].dist <= k) {\n                cnt\
    \ += nd->nxt[i].dist;\n                nd = nd->nxt[i].node;\n            }\n\
    \            nds[i] = nd;\n        }\n        rep (i, 1, sl.first->level()) calc(nds[i],\
    \ i);\n    }\n    static void match_level(nodepair& lhs, nodepair& rhs) {\n  \
    \      const int llv = lhs.first->level(), rlv = rhs.second->level();\n      \
    \  if (llv < rlv) {\n            eval(lhs.first, llv - 1);\n            lhs.first->prv.resize(rlv,\
    \ {lhs.first->prv.back()});\n            lhs.first->nxt.resize(rlv, {lhs.first->nxt.back()});\n\
    \            lhs.second->prv.resize(rlv, {lhs.second->prv.back()});\n        \
    \    lhs.second->nxt.resize(rlv, {lhs.second->nxt.back()});\n        }\n     \
    \   else if (llv > rlv) {\n            eval(rhs.second, rlv - 1);\n          \
    \  rhs.first->prv.resize(llv, {rhs.first->prv.back()});\n            rhs.first->nxt.resize(llv,\
    \ {rhs.first->nxt.back()});\n            rhs.second->prv.resize(llv, {rhs.second->prv.back()});\n\
    \            rhs.second->nxt.resize(llv, {rhs.second->nxt.back()});\n        }\n\
    \    }\n    static nodepair merge(nodepair&& lhs, nodepair&& rhs, Rand& rnd) {\n\
    \        assert(lhs.first != rhs.first);\n        assert(lhs.second != rhs.second);\n\
    \        if (lhs.first == lhs.second) {\n            delete lhs.first;\n     \
    \       auto res = std::move(rhs);\n            lhs = rhs = {nullptr, nullptr};\n\
    \            return res;\n        }\n        if (rhs.first == rhs.second) {\n\
    \            delete rhs.first;\n            auto res = std::move(lhs);\n     \
    \       lhs = rhs = {nullptr, nullptr};\n            return res;\n        }\n\
    \        match_level(lhs, rhs);\n        rep (i, lhs.first->level()) {\n     \
    \       auto&& l = lhs.second->prv[i];\n            auto&& r = rhs.first;\n  \
    \          l->nxt[i].node = r;\n            r->prv[i] = std::move(l);\n      \
    \  }\n        delete lhs.second;\n        const int lev = get_level(rnd);\n  \
    \      while (lev < rhs.first->level()) {\n            const int h = rhs.first->level();\n\
    \            const auto lp = std::move(rhs.first->prv.back());\n            const\
    \ auto l = lp->nxt[h - 1];\n            const auto r = std::move(rhs.first->nxt.back());\n\
    \            eval(lp, h - 1);\n            eval(rhs.first, h - 1);\n         \
    \   rhs.first->prv.pop_back();\n            rhs.first->nxt.pop_back();\n     \
    \       lp->nxt[h - 1] = {r.node, l.dist + r.dist, M::op(l.sm, r.sm)};\n     \
    \       r.node->prv[h - 1] = lp;\n        }\n        if (lev >= lhs.first->level())\
    \ {\n            eval(lhs.first, lhs.first->level() - 1);\n            eval(rhs.first,\
    \ lhs.first->level() - 1);\n            lhs.first->prv.resize(lev + 1, {lhs.first->prv.back()});\n\
    \            lhs.first->nxt.resize(lev, {lhs.first->nxt.back()});\n          \
    \  rhs.first->prv.resize(lev, {rhs.first->prv.back()});\n            rhs.first->nxt.resize(lev,\
    \ {rhs.first->nxt.back()});\n            rhs.second->prv.resize(lev, {rhs.second->prv.back()});\n\
    \            rhs.second->nxt.resize(lev + 1, {rhs.second->nxt.back()});\n    \
    \        const auto& lp = rhs.first->prv.back();\n            const auto& l =\
    \ lp->nxt[lev - 1];\n            const auto& r = rhs.first->nxt.back();\n    \
    \        lhs.first->nxt.emplace_back(rhs.second, l.dist + r.dist,\n          \
    \                              M::op(l.sm, r.sm));\n            rhs.second->prv.push_back(lhs.first);\n\
    \        }\n        nodepair res{lhs.first, rhs.second};\n        lhs = rhs =\
    \ {nullptr, nullptr};\n        return res;\n    }\n    static std::pair<nodepair,\
    \ nodepair> split(nodepair&& sl, int k) {\n        const int n = sl.first->nxt.back().dist;\n\
    \        assert(0 <= k && k <= n);\n        if (n == 0 || k == 0) {\n        \
    \    node_ptr np = new node(1);\n            auto res = std::make_pair(nodepair{np,\
    \ np}, std::move(sl));\n            sl = {nullptr, nullptr};\n            return\
    \ res;\n        }\n        if (k == n) {\n            node_ptr np = new node(1);\n\
    \            auto res = std::make_pair(std::move(sl), nodepair{np, np});\n   \
    \         sl = {nullptr, nullptr};\n            return res;\n        }\n     \
    \   const int h = sl.first->level();\n        std::vector<node_ptr> lft(h);\n\
    \        std::vector<int> idx(h);\n        lft[h - 1] = sl.first;\n        idx[h\
    \ - 1] = 0;\n        rrep (i, h - 1) {\n            lft[i] = lft[i + 1];\n   \
    \         idx[i] = idx[i + 1];\n            while (idx[i] + lft[i]->nxt[i].dist\
    \ < k) {\n                idx[i] += lft[i]->nxt[i].dist;\n                lft[i]\
    \ = lft[i]->nxt[i].node;\n            }\n        }\n        rrep (i, h, 1) eval(lft[i],\
    \ i);\n        node_ptr npl = new node(h);\n        node_ptr npr = lft[0]->nxt[0].node;\n\
    \        rep (i, h) {\n            const auto l = lft[i];\n            const auto\
    \ r = lft[i]->nxt[i].node;\n            const int d = l->nxt[i].dist;\n      \
    \      l->nxt[i] = {npl, k - idx[i], l->nxt[i].sm};\n            npl->prv[i] =\
    \ l;\n            if (i != 0) calc(l, i);\n            if (npr == r) {\n     \
    \           r->prv[i] = nullptr;\n            }\n            else {\n        \
    \        npr->prv.push_back(nullptr);\n                npr->nxt.emplace_back(r,\
    \ d + idx[i] - k, M::id());\n                r->prv[i] = npr;\n              \
    \  calc(npr, i);\n            }\n        }\n        auto res =\n            std::make_pair(nodepair{sl.first,\
    \ npl}, nodepair{npr, sl.second});\n        sl = {nullptr, nullptr};\n       \
    \ return res;\n    }\n    SkipList(const nodepair& sl, const Rand& rnd) : rnd(rnd),\
    \ sl(sl) {}\n    SkipList(nodepair&& sl, const Rand& rnd) : rnd(rnd), sl(std::move(sl))\
    \ {}\n    static node_ptr get_ptr(const nodepair& sl, int k) {\n        int cnt\
    \ = 0;\n        node_ptr nw = sl.first;\n        rrep (i, sl.first->level()) {\n\
    \            while (cnt + nw->nxt[i].dist <= k) {\n                cnt += nw->nxt[i].dist;\n\
    \                nw = nw->nxt[i].node;\n            }\n        }\n        return\
    \ nw;\n    }\n\npublic:\n    SkipList() : SkipList(Rand()) {}\n    SkipList(const\
    \ Rand& rnd) : rnd(rnd) { sl.first = sl.second = new node(1); }\n    SkipList(const\
    \ std::vector<T>& v, const Rand& rnd = Rand()) : rnd(rnd) {\n        init(v);\n\
    \    }\n    SkipList(const SkipList& other) : SkipList(other.get_data(), other.rnd)\
    \ {}\n    SkipList(SkipList&& other) : rnd(other.rnd), sl(std::move(other.sl))\
    \ {\n        other.sl = {nullptr, nullptr};\n    }\n    ~SkipList() {\n      \
    \  for (node_ptr ptr = sl.first; ptr;) {\n            node_ptr nxt = ptr->nxt[0].node;\n\
    \            delete ptr;\n            ptr = nxt;\n        }\n        sl = {nullptr,\
    \ nullptr};\n    }\n    SkipList& operator=(const SkipList& other) {\n       \
    \ if (this == &other) return *this;\n        init(other.get_data());\n       \
    \ return *this;\n    }\n    SkipList& operator=(SkipList&& other) {\n        if\
    \ (this == &other) return *this;\n        sl = std::move(other.sl);\n        other.sl\
    \ = {nullptr, nullptr};\n        return *this;\n    }\n    void init(const std::vector<T>&\
    \ v) {\n        if (sl.first) {\n            for (node_ptr ptr = sl.first; ptr;)\
    \ {\n                node_ptr nxt = ptr->nxt[0].node;\n                delete\
    \ ptr;\n                ptr = nxt;\n            }\n        }\n        const int\
    \ n = v.size();\n        std::vector<int> lev(n + 1);\n        rep (i, 1, n) lev[i]\
    \ = get_level(rnd);\n        lev[0] = lev[n] = *max_element(lev.begin() + 1, lev.end()\
    \ - 1) + 1;\n        std::vector<node_ptr> nd(n + 1);\n        rep (i, n + 1)\
    \ nd[i] = new node(lev[i]);\n        rep (i, n) {\n            nd[i]->nxt[0] =\
    \ {nd[i + 1], 1, v[i]};\n            nd[i + 1]->prv[0] = nd[i];\n        }\n \
    \       nd[0]->prv[0] = nullptr;\n        nd[n]->nxt[0] = {nullptr, 1, M::id()};\n\
    \        rep (i, 1, lev[0]) {\n            std::vector<int> idx;\n           \
    \ rep (j, n + 1) {\n                if (lev[j] > i) idx.push_back(j);\n      \
    \      }\n            const int m = idx.size();\n            rep (j, m - 1) {\n\
    \                nd[idx[j]]->nxt[i] = {nd[idx[j + 1]], idx[j + 1] - idx[j],\n\
    \                                      nd[idx[j]]->nxt[i - 1].sm};\n         \
    \       for (node_ptr ptr = nd[idx[j]]->nxt[i - 1].node;\n                   \
    \  ptr != nd[idx[j + 1]]; ptr = ptr->nxt[i - 1].node) {\n                    nd[idx[j]]->nxt[i].sm\
    \ =\n                        M::op(nd[idx[j]]->nxt[i].sm, ptr->nxt[i - 1].sm);\n\
    \                }\n                nd[idx[j + 1]]->prv[i] = nd[idx[j]];\n   \
    \         }\n            nd[idx[0]]->prv[i] = nullptr;\n            nd[idx[m -\
    \ 1]]->nxt[i] = {nullptr, 1, M::id()};\n        }\n        sl = {nd[0], nd[n]};\n\
    \    }\n    int size() const {\n        assert(sl.first);\n        return sl.first\
    \ == sl.second ? 0 : sl.first->nxt.back().dist;\n    }\n    bool empty() const\
    \ { return sl.first == sl.second; }\n    void insert(int k, const T& x) {\n  \
    \      const int n = size();\n        assert(0 <= k && k <= n);\n        if (n\
    \ == 0) {\n            delete sl.first;\n            sl.first = new node(1);\n\
    \            sl.second = new node(1);\n            sl.first->nxt[0] = {sl.second,\
    \ 1, x};\n            sl.second->prv[0] = sl.first;\n            return;\n   \
    \     }\n        if (k == 0) {\n            /*\n            if (lev < sl.first->level())\
    \ {\n                node_ptr ptr = new node(lev);\n                rep (i, lev)\
    \ {\n                    ptr->nxt[i] = sl.first->nxt[i];\n                   \
    \ sl.first->nxt[i].node->prv[i] = ptr;\n                    sl.first->nxt[i] =\
    \ {ptr, 1, x};\n                    ptr->prv[i] = sl.first;\n                }\n\
    \                rep (i, lev, sl.first->level()) {\n                    ++sl.first->nxt[i].dist;\n\
    \                    sl.first->nxt[i].sm = M::op(x, sl.first->nxt[i].sm);\n  \
    \              }\n            }\n            else {\n                node_ptr\
    \ ptr = new node(lev);\n                rep (i, sl.first->level()) {\n       \
    \             ptr->nxt[i] = sl.first->nxt[i];\n                    sl.first->nxt[i].node->prv[i]\
    \ = ptr;\n                    sl.first->nxt[i] = {ptr, 1, x};\n              \
    \      ptr->prv[i] = sl.first;\n                }\n                rep (i, sl.first->level(),\
    \ lev) {\n                    sl.first->nxt[i] = sl.first->nxt[i - 1];\n     \
    \               sl.first->prv[i] = sl.first->prv[i - 1];\n                }\n\
    \                sl.first->prv.resize(lev + 1, {sl.first->prv.back()});\n    \
    \            sl.first->nxt.resize(lev + 1, {sl.first->nxt.back()});\n        \
    \        sl.second->prv.resize(lev + 1, {sl.second->prv.back()});\n          \
    \      sl.second->nxt.resize(lev + 1, {sl.second->nxt.back()});\n            \
    \    sl.first->nxt.back() = {sl.second, sl.first->nxt.back().dist +\n        \
    \    1, M::op(x, sl.first->nxt.back().sm)}; sl.second->prv.back() =\n        \
    \    sl.first;\n            }\n            */\n\n\n            nodepair p{new\
    \ node(1), new node(1)};\n            p.first->nxt[0] = {p.second, 1, x};\n  \
    \          p.second->prv[0] = p.first;\n            sl = merge(std::move(p), std::move(sl),\
    \ rnd);\n            return;\n        }\n        const int h = sl.first->level();\n\
    \        std::vector<node_ptr> lft(h);\n        std::vector<int> idx(h);\n   \
    \     lft[h - 1] = sl.first;\n        idx[h - 1] = 0;\n        rrep (i, h - 1)\
    \ {\n            lft[i] = lft[i + 1];\n            idx[i] = idx[i + 1];\n    \
    \        while (idx[i] + lft[i]->nxt[i].dist < k) {\n                idx[i] +=\
    \ lft[i]->nxt[i].dist;\n                lft[i] = lft[i]->nxt[i].node;\n      \
    \      }\n        }\n        rrep (i, h, 1) eval(lft[i], i);\n        const int\
    \ lev = get_level(rnd);\n        node_ptr np = new node(lev);\n        if (lev\
    \ < h) {\n            rep (i, lev) {\n                const auto l = lft[i];\n\
    \                const auto r = lft[i]->nxt[i].node;\n                np->nxt[i]\
    \ = {r, idx[i] + l->nxt[i].dist - k + 1, x};\n                r->prv[i] = np;\n\
    \                l->nxt[i] = {np, k - idx[i], l->nxt[i].sm};\n               \
    \ np->prv[i] = l;\n            }\n            rep (i, lev, h) ++lft[i]->nxt[i].dist;\n\
    \            rep (i, 1, h) {\n                calc(lft[i], i);\n             \
    \   if (i < lev) calc(lft[i]->nxt[i].node, i);\n            }\n        }\n   \
    \     else {\n            rep (i, h) {\n                const auto l = lft[i];\n\
    \                const auto r = lft[i]->nxt[i].node;\n                np->nxt[i]\
    \ = {r, idx[i] + l->nxt[i].dist - k + 1, x};\n                r->prv[i] = np;\n\
    \                l->nxt[i] = {np, k - idx[i], l->nxt[i].sm};\n               \
    \ np->prv[i] = l;\n            }\n            rep (i, 1, h) {\n              \
    \  calc(lft[i], i);\n                if (i < lev) calc(lft[i]->nxt[i].node, i);\n\
    \            }\n            sl.first->prv.resize(lev + 1, {sl.first->prv.back()});\n\
    \            sl.first->nxt.resize(lev + 1, {sl.second, n + 1, x});\n         \
    \   sl.second->prv.resize(lev + 1, sl.first);\n            sl.second->nxt.resize(lev\
    \ + 1, {sl.second->nxt.back()});\n            rep (i, h, lev) {\n            \
    \    sl.first->nxt[i] = {np, k, x};\n                np->prv[i] = sl.first;\n\
    \                np->nxt[i] = {sl.second, n - k + 1, x};\n                sl.second->prv[i]\
    \ = np;\n                calc(sl.first, i);\n                calc(np, i);\n  \
    \          }\n            calc(sl.first, lev);\n        }\n    }\n    void erase(int\
    \ k) {\n        const int n = size();\n        assert(0 <= k && k < n);\n    \
    \    if (n == 1) {\n            delete sl.first;\n            delete sl.second;\n\
    \            sl.first = sl.second = new node(1);\n            return;\n      \
    \  }\n        if (k == 0) {\n            all_eval(sl, 0);\n            all_eval(sl,\
    \ 1);\n            rep (i, sl.first->level()) {\n                if (sl.first->nxt[i].dist\
    \ == 1) {\n                    const auto l = sl.first;\n                    const\
    \ auto m = l->nxt[i].node;\n                    const auto r = m->nxt[i].node;\n\
    \                    l->nxt[i] = {r, l->nxt[i].dist + m->nxt[i].dist - 1,\n  \
    \                               m->nxt[i].sm};\n                    r->prv[i]\
    \ = l;\n                }\n                else {\n                    sl.first->nxt[i].dist--;\n\
    \                }\n            }\n            rep (i, 1, sl.first->level()) calc(sl.first,\
    \ i);\n            return;\n        }\n        all_eval(sl, k - 1);\n        all_eval(sl,\
    \ k);\n        node_ptr np = sl.first;\n        int cnt = 0;\n        rrep (i,\
    \ sl.first->level()) {\n            while (cnt + np->nxt[i].dist <= k) {\n   \
    \             cnt += np->nxt[i].dist;\n                np = np->nxt[i].node;\n\
    \            }\n            if (cnt == k) {\n                const auto l = np->prv[i];\n\
    \                const auto r = np->nxt[i].node;\n                r->prv[i] =\
    \ l;\n                l->nxt[i] = {r, l->nxt[i].dist + np->nxt[i].dist - 1,\n\
    \                             l->nxt[i].sm};\n            }\n            else\
    \ {\n                np->nxt[i].dist--;\n            }\n        }\n        delete\
    \ np;\n        all_calc(sl, k - 1);\n    }\n    T prod(int l, int r) const {\n\
    \        assert(0 <= l && l <= r && r <= size());\n        all_eval(sl, l);\n\
    \        all_eval(sl, r - 1);\n        auto np = get_ptr(sl, l);\n        T sm\
    \ = M::id();\n        rrep (i, sl.first->level()) {\n            while (1) {\n\
    \                int t = std::min((int)i, np->level() - 1);\n                if\
    \ (l + np->nxt[t].dist > r) break;\n                l += np->nxt[t].dist;\n  \
    \              sm = M::op(sm, np->nxt[t].sm);\n                np = np->nxt[t].node;\n\
    \            }\n        }\n        return sm;\n    }\n    T all_prod() const {\
    \ return sl.first->nxt.back().sm; }\n    T get(int k) const {\n        assert(0\
    \ <= k && k < size());\n        all_eval(sl, k);\n        return get_ptr(sl, k)->nxt[0].sm;\n\
    \    }\n    void apply(int l, int r, const U& x) {\n        assert(0 <= l && l\
    \ <= r && r <= size());\n        all_eval(sl, l);\n        all_eval(sl, r - 1);\n\
    \        auto np = get_ptr(sl, l);\n        int idx = l;\n        rrep (i, sl.first->level())\
    \ {\n            while (1) {\n                int t = std::min((int)i, np->level()\
    \ - 1);\n                if (idx + np->nxt[t].dist > r) break;\n             \
    \   idx += np->nxt[t].dist;\n                all_apply(np, t, x);\n          \
    \      np = np->nxt[t].node;\n            }\n        }\n        all_eval(sl, l);\n\
    \        all_eval(sl, r - 1);\n        all_calc(sl, l);\n        all_calc(sl,\
    \ r - 1);\n    }\n    template<class Upd> void update(int k, const Upd& upd) {\n\
    \        assert(0 <= k && k < size());\n        all_eval(sl, k);\n        auto\
    \ nd = get_ptr(sl, k);\n        nd->nxt[0].sm = upd(nd->nxt[0].sm);\n        all_calc(sl,\
    \ k);\n    }\n    void set(int k, const T& x) {\n        update(k, [&](const T&)\
    \ { return x; });\n    }\n    void apply(int k, const U& x) {\n        update(k,\
    \ [&](const T& sm) { return E::op(x, sm); });\n    }\n    template<class C> int\
    \ max_right(int l, const C& cond) const {\n        assert(0 <= l && l <= size());\n\
    \        assert(cond(M::id()));\n        if (l == size()) return size();\n   \
    \     all_eval(sl, l);\n        auto np = get_ptr(sl, l);\n        T sm = M::id();\n\
    \        rrep (i, sl.first->level()) {\n            while (1) {\n            \
    \    int t = std::min((int)i, np->level() - 1);\n                if (t != np->level()\
    \ - 1) eval(np, t + 1);\n                if (!cond(M::op(sm, np->nxt[t].sm)))\
    \ break;\n                sm = M::op(sm, np->nxt[t].sm);\n                l +=\
    \ np->nxt[t].dist;\n                np = np->nxt[t].node;\n                if\
    \ (np == sl.second) return size();\n            }\n        }\n        return l;\n\
    \    }\n    template<class C> int min_left(int r, const C& cond) const {\n   \
    \     assert(0 <= r && r <= size());\n        assert(cond(M::id()));\n       \
    \ if (r == 0) return 0;\n        all_eval(sl, r - 1);\n        auto np = get_ptr(sl,\
    \ r);\n        T sm = M::id();\n        rrep (i, sl.first->level()) {\n      \
    \      while (1) {\n                int t = std::min((int)i, np->level() - 1);\n\
    \                if (t != np->level() - 1) eval(np->prv[t], t + 1);\n        \
    \        if (!cond(M::op(sm, np->prv[t]->nxt[t].sm))) break;\n               \
    \ sm = M::op(sm, np->prv[t]->nxt[t].sm);\n                r -= np->prv[t]->nxt[t].dist;\n\
    \                np = np->prv[t];\n                if (np == sl.first) return\
    \ 0;\n            }\n        }\n        return r;\n    }\n    std::vector<T> get_data()\
    \ const {\n        rrep (i, sl.first->level(), 1) {\n            for (node_ptr\
    \ ptr = sl.first; ptr != sl.second;\n                 ptr = ptr->nxt[i].node)\
    \ {\n                eval(ptr, i);\n            }\n        }\n        std::vector<T>\
    \ res;\n        res.reserve(size());\n        for (node_ptr ptr = sl.first; ptr\
    \ != sl.second;\n             ptr = ptr->nxt[0].node) {\n            res.push_back(ptr->nxt[0].sm);\n\
    \        }\n        return res;\n    }\n    friend SkipList merge(SkipList lhs,\
    \ SkipList rhs) {\n        return {merge(std::move(lhs.sl), std::move(rhs.sl),\
    \ lhs.rnd), lhs.rnd};\n    }\n    friend std::pair<SkipList, SkipList> split(SkipList\
    \ sl, int k) {\n        auto s = split(std::move(sl.sl), k);\n        return {SkipList{std::move(s.first),\
    \ sl.rnd},\n                SkipList{std::move(s.second), sl.rnd}};\n    }\n};\n\
    \ntemplate<class A, class Rand> class SkipList<A, Rand, true> {\nprivate:\n  \
    \  using Base = SkipList<Monoid::MultiAction<A>, Rand>;\n    using T_ = typename\
    \ A::M::value_type;\n    using U_ = typename A::E::value_type;\n    Base sl;\n\
    \    using elm = typename Monoid::MultiAction<A>::M::value_type;\n    static std::vector<elm>\
    \ get_elm_vec(const std::vector<T_>& v) {\n        const int n = v.size();\n \
    \       std::vector<elm> res(n);\n        rep (i, n) res[i] = {v[i], 1};\n   \
    \     return res;\n    }\n    SkipList(const Base& other) : sl(other) {}\n   \
    \ SkipList(Base&& other) : sl(std::move(other)) {}\n\npublic:\n    SkipList()\
    \ : SkipList(Rand()) {}\n    SkipList(const Rand& rnd) : sl(rnd) {}\n    SkipList(const\
    \ std::vector<T_>& v, const Rand& rnd = Rand())\n        : sl(get_elm_vec(v),\
    \ rnd) {}\n    void init(const std::vector<T_>& v) { sl.init(get_elm_vec(v));\
    \ }\n    int size() const { return sl.size(); }\n    bool empty() const { return\
    \ sl.empty(); }\n    void insert(int k, const T_& sm) { sl.insert(k, {sm, 1});\
    \ }\n    void erase(int k) { sl.erase(k); }\n    T_ prod(int l, int r) const {\
    \ return sl.prod(l, r).val; }\n    T_ all_prod() const { return sl.all_prod().val;\
    \ }\n    T_ get(int k) const { return sl.get(k).val; }\n    void apply(int l,\
    \ int r, const U_& x) { sl.apply(l, r, x); }\n    template<class Upd> void update(int\
    \ k, const Upd& upd) {\n        sl.update(k, [&](const elm& e) -> elm { return\
    \ {upd(e.val), e.len}; });\n    }\n    void set(int k, const T_& x) { sl.set(k,\
    \ {x, 1}); }\n    void apply(int k, const U_& x) { sl.apply(k, x); }\n    template<class\
    \ C> int max_right(int l, const C& cond) const {\n        return sl.max_right(l,\n\
    \                            [&](const elm& e) -> bool { return cond(e.val); });\n\
    \    }\n    template<class C> int min_left(int r, const C& cond) const {\n   \
    \     return sl.min_left(r,\n                           [&](const elm& e) -> bool\
    \ { return cond(e.val); });\n    }\n    std::vector<T_> get_data() const {\n \
    \       std::vector<elm> d = sl.get_data();\n        std::vector<T_> res(d.size());\n\
    \        rep (i, d.size()) res[i] = d[i].val;\n        return res;\n    }\n  \
    \  friend SkipList merge(SkipList lhs, SkipList rhs) {\n        return {merge(std::move(lhs.sl),\
    \ std::move(rhs.sl))};\n    }\n    friend std::pair<SkipList, SkipList> split(SkipList\
    \ sl, int k) {\n        auto s = split(std::move(sl.sl), k);\n        return {SkipList{std::move(s.first)},\
    \ SkipList{std::move(s.second)}};\n    }\n};\n\n/**\n * @brief SkipList\n * @docs\
    \ docs/data-struct/other/SkipList.md\n */\n"
  code: "#pragma once\n\n#include \"../../other/template.hpp\"\n#include \"../../other/monoid.hpp\"\
    \n#include \"../../random/Random.hpp\"\n\ntemplate<class A, class Rand = Random32,\
    \ bool = Monoid::has_mul_op<A>::value>\nclass SkipList {\nprivate:\n    using\
    \ M = typename A::M;\n    using E = typename A::E;\n    using T = typename M::value_type;\n\
    \    using U = typename E::value_type;\n    static inline int get_level(Rand&\
    \ rnd) {\n        int level = 1;\n        while ((rnd() & 1) == 0) ++level;\n\
    \        return level;\n    }\n    struct node;\n    using node_ptr = node*;\n\
    \    struct next_node {\n        node_ptr node;\n        int dist;\n        T\
    \ sm;\n        U lazy;\n        bool lazyflag;\n        next_node(node_ptr n,\
    \ int d, const T& s)\n            : node(n), dist(d), sm(s), lazyflag(false) {}\n\
    \        next_node(node_ptr n, int d, const T& s, const U& l)\n            : node(n),\
    \ dist(d), sm(s), lazy(l), lazyflag(true) {}\n    };\n    struct node {\n    \
    \    std::vector<next_node> nxt;\n        std::vector<node_ptr> prv;\n       \
    \ int level() const {\n            assert(nxt.size() == prv.size());\n       \
    \     return nxt.size();\n        }\n        node(Rand& rnd) : node(get_level(rnd))\
    \ {}\n        node(int lev) : nxt(lev, {nullptr, 1, M::id()}), prv(lev, nullptr)\
    \ {}\n    };\n    using nodepair = std::pair<node_ptr, node_ptr>;\n    Rand rnd;\n\
    \    nodepair sl;\n    static inline void all_apply(const node_ptr& nd, int k,\
    \ const U& x) {\n        assert(0 <= k && k < nd->level());\n        nd->nxt[k].sm\
    \ = A::op(x, nd->nxt[k].sm);\n        if (k != 0) {\n            if (nd->nxt[k].lazyflag)\
    \ {\n                nd->nxt[k].lazy = E::op(nd->nxt[k].lazy, x);\n          \
    \  }\n            else {\n                nd->nxt[k].lazy = x;\n             \
    \   nd->nxt[k].lazyflag = true;\n            }\n        }\n    }\n    static inline\
    \ void eval(const node_ptr& nd, int k) {\n        assert(0 <= k && k < nd->level());\n\
    \        if (k != 0 && nd->nxt[k].lazyflag) {\n            for (auto ptr = nd;\
    \ ptr != nd->nxt[k].node;\n                 ptr = ptr->nxt[k - 1].node) {\n  \
    \              all_apply(ptr, k - 1, nd->nxt[k].lazy);\n            }\n      \
    \      nd->nxt[k].lazyflag = false;\n        }\n    }\n    static inline void\
    \ all_eval(const nodepair& sl, int k) {\n        auto nd = sl.first;\n       \
    \ int cnt = 0;\n        rrep (i, sl.first->level(), 1) {\n            while (cnt\
    \ + nd->nxt[i].dist <= k) {\n                cnt += nd->nxt[i].dist;\n       \
    \         nd = nd->nxt[i].node;\n            }\n            eval(nd, i);\n   \
    \     }\n    }\n    static inline void calc(const node_ptr& l, int k) {\n    \
    \    assert(1 <= k && k < l->level());\n        l->nxt[k].sm = l->nxt[k - 1].sm;\n\
    \        for (node_ptr ptr = l->nxt[k - 1].node; ptr != l->nxt[k].node;\n    \
    \         ptr = ptr->nxt[k - 1].node) {\n            l->nxt[k].sm = M::op(l->nxt[k].sm,\
    \ ptr->nxt[k - 1].sm);\n        }\n    }\n    static inline void all_calc(const\
    \ nodepair& sl, int k) {\n        auto nd = sl.first;\n        int cnt = 0;\n\
    \        std::vector<node_ptr> nds(sl.first->level());\n        rrep (i, sl.first->level(),\
    \ 1) {\n            while (cnt + nd->nxt[i].dist <= k) {\n                cnt\
    \ += nd->nxt[i].dist;\n                nd = nd->nxt[i].node;\n            }\n\
    \            nds[i] = nd;\n        }\n        rep (i, 1, sl.first->level()) calc(nds[i],\
    \ i);\n    }\n    static void match_level(nodepair& lhs, nodepair& rhs) {\n  \
    \      const int llv = lhs.first->level(), rlv = rhs.second->level();\n      \
    \  if (llv < rlv) {\n            eval(lhs.first, llv - 1);\n            lhs.first->prv.resize(rlv,\
    \ {lhs.first->prv.back()});\n            lhs.first->nxt.resize(rlv, {lhs.first->nxt.back()});\n\
    \            lhs.second->prv.resize(rlv, {lhs.second->prv.back()});\n        \
    \    lhs.second->nxt.resize(rlv, {lhs.second->nxt.back()});\n        }\n     \
    \   else if (llv > rlv) {\n            eval(rhs.second, rlv - 1);\n          \
    \  rhs.first->prv.resize(llv, {rhs.first->prv.back()});\n            rhs.first->nxt.resize(llv,\
    \ {rhs.first->nxt.back()});\n            rhs.second->prv.resize(llv, {rhs.second->prv.back()});\n\
    \            rhs.second->nxt.resize(llv, {rhs.second->nxt.back()});\n        }\n\
    \    }\n    static nodepair merge(nodepair&& lhs, nodepair&& rhs, Rand& rnd) {\n\
    \        assert(lhs.first != rhs.first);\n        assert(lhs.second != rhs.second);\n\
    \        if (lhs.first == lhs.second) {\n            delete lhs.first;\n     \
    \       auto res = std::move(rhs);\n            lhs = rhs = {nullptr, nullptr};\n\
    \            return res;\n        }\n        if (rhs.first == rhs.second) {\n\
    \            delete rhs.first;\n            auto res = std::move(lhs);\n     \
    \       lhs = rhs = {nullptr, nullptr};\n            return res;\n        }\n\
    \        match_level(lhs, rhs);\n        rep (i, lhs.first->level()) {\n     \
    \       auto&& l = lhs.second->prv[i];\n            auto&& r = rhs.first;\n  \
    \          l->nxt[i].node = r;\n            r->prv[i] = std::move(l);\n      \
    \  }\n        delete lhs.second;\n        const int lev = get_level(rnd);\n  \
    \      while (lev < rhs.first->level()) {\n            const int h = rhs.first->level();\n\
    \            const auto lp = std::move(rhs.first->prv.back());\n            const\
    \ auto l = lp->nxt[h - 1];\n            const auto r = std::move(rhs.first->nxt.back());\n\
    \            eval(lp, h - 1);\n            eval(rhs.first, h - 1);\n         \
    \   rhs.first->prv.pop_back();\n            rhs.first->nxt.pop_back();\n     \
    \       lp->nxt[h - 1] = {r.node, l.dist + r.dist, M::op(l.sm, r.sm)};\n     \
    \       r.node->prv[h - 1] = lp;\n        }\n        if (lev >= lhs.first->level())\
    \ {\n            eval(lhs.first, lhs.first->level() - 1);\n            eval(rhs.first,\
    \ lhs.first->level() - 1);\n            lhs.first->prv.resize(lev + 1, {lhs.first->prv.back()});\n\
    \            lhs.first->nxt.resize(lev, {lhs.first->nxt.back()});\n          \
    \  rhs.first->prv.resize(lev, {rhs.first->prv.back()});\n            rhs.first->nxt.resize(lev,\
    \ {rhs.first->nxt.back()});\n            rhs.second->prv.resize(lev, {rhs.second->prv.back()});\n\
    \            rhs.second->nxt.resize(lev + 1, {rhs.second->nxt.back()});\n    \
    \        const auto& lp = rhs.first->prv.back();\n            const auto& l =\
    \ lp->nxt[lev - 1];\n            const auto& r = rhs.first->nxt.back();\n    \
    \        lhs.first->nxt.emplace_back(rhs.second, l.dist + r.dist,\n          \
    \                              M::op(l.sm, r.sm));\n            rhs.second->prv.push_back(lhs.first);\n\
    \        }\n        nodepair res{lhs.first, rhs.second};\n        lhs = rhs =\
    \ {nullptr, nullptr};\n        return res;\n    }\n    static std::pair<nodepair,\
    \ nodepair> split(nodepair&& sl, int k) {\n        const int n = sl.first->nxt.back().dist;\n\
    \        assert(0 <= k && k <= n);\n        if (n == 0 || k == 0) {\n        \
    \    node_ptr np = new node(1);\n            auto res = std::make_pair(nodepair{np,\
    \ np}, std::move(sl));\n            sl = {nullptr, nullptr};\n            return\
    \ res;\n        }\n        if (k == n) {\n            node_ptr np = new node(1);\n\
    \            auto res = std::make_pair(std::move(sl), nodepair{np, np});\n   \
    \         sl = {nullptr, nullptr};\n            return res;\n        }\n     \
    \   const int h = sl.first->level();\n        std::vector<node_ptr> lft(h);\n\
    \        std::vector<int> idx(h);\n        lft[h - 1] = sl.first;\n        idx[h\
    \ - 1] = 0;\n        rrep (i, h - 1) {\n            lft[i] = lft[i + 1];\n   \
    \         idx[i] = idx[i + 1];\n            while (idx[i] + lft[i]->nxt[i].dist\
    \ < k) {\n                idx[i] += lft[i]->nxt[i].dist;\n                lft[i]\
    \ = lft[i]->nxt[i].node;\n            }\n        }\n        rrep (i, h, 1) eval(lft[i],\
    \ i);\n        node_ptr npl = new node(h);\n        node_ptr npr = lft[0]->nxt[0].node;\n\
    \        rep (i, h) {\n            const auto l = lft[i];\n            const auto\
    \ r = lft[i]->nxt[i].node;\n            const int d = l->nxt[i].dist;\n      \
    \      l->nxt[i] = {npl, k - idx[i], l->nxt[i].sm};\n            npl->prv[i] =\
    \ l;\n            if (i != 0) calc(l, i);\n            if (npr == r) {\n     \
    \           r->prv[i] = nullptr;\n            }\n            else {\n        \
    \        npr->prv.push_back(nullptr);\n                npr->nxt.emplace_back(r,\
    \ d + idx[i] - k, M::id());\n                r->prv[i] = npr;\n              \
    \  calc(npr, i);\n            }\n        }\n        auto res =\n            std::make_pair(nodepair{sl.first,\
    \ npl}, nodepair{npr, sl.second});\n        sl = {nullptr, nullptr};\n       \
    \ return res;\n    }\n    SkipList(const nodepair& sl, const Rand& rnd) : rnd(rnd),\
    \ sl(sl) {}\n    SkipList(nodepair&& sl, const Rand& rnd) : rnd(rnd), sl(std::move(sl))\
    \ {}\n    static node_ptr get_ptr(const nodepair& sl, int k) {\n        int cnt\
    \ = 0;\n        node_ptr nw = sl.first;\n        rrep (i, sl.first->level()) {\n\
    \            while (cnt + nw->nxt[i].dist <= k) {\n                cnt += nw->nxt[i].dist;\n\
    \                nw = nw->nxt[i].node;\n            }\n        }\n        return\
    \ nw;\n    }\n\npublic:\n    SkipList() : SkipList(Rand()) {}\n    SkipList(const\
    \ Rand& rnd) : rnd(rnd) { sl.first = sl.second = new node(1); }\n    SkipList(const\
    \ std::vector<T>& v, const Rand& rnd = Rand()) : rnd(rnd) {\n        init(v);\n\
    \    }\n    SkipList(const SkipList& other) : SkipList(other.get_data(), other.rnd)\
    \ {}\n    SkipList(SkipList&& other) : rnd(other.rnd), sl(std::move(other.sl))\
    \ {\n        other.sl = {nullptr, nullptr};\n    }\n    ~SkipList() {\n      \
    \  for (node_ptr ptr = sl.first; ptr;) {\n            node_ptr nxt = ptr->nxt[0].node;\n\
    \            delete ptr;\n            ptr = nxt;\n        }\n        sl = {nullptr,\
    \ nullptr};\n    }\n    SkipList& operator=(const SkipList& other) {\n       \
    \ if (this == &other) return *this;\n        init(other.get_data());\n       \
    \ return *this;\n    }\n    SkipList& operator=(SkipList&& other) {\n        if\
    \ (this == &other) return *this;\n        sl = std::move(other.sl);\n        other.sl\
    \ = {nullptr, nullptr};\n        return *this;\n    }\n    void init(const std::vector<T>&\
    \ v) {\n        if (sl.first) {\n            for (node_ptr ptr = sl.first; ptr;)\
    \ {\n                node_ptr nxt = ptr->nxt[0].node;\n                delete\
    \ ptr;\n                ptr = nxt;\n            }\n        }\n        const int\
    \ n = v.size();\n        std::vector<int> lev(n + 1);\n        rep (i, 1, n) lev[i]\
    \ = get_level(rnd);\n        lev[0] = lev[n] = *max_element(lev.begin() + 1, lev.end()\
    \ - 1) + 1;\n        std::vector<node_ptr> nd(n + 1);\n        rep (i, n + 1)\
    \ nd[i] = new node(lev[i]);\n        rep (i, n) {\n            nd[i]->nxt[0] =\
    \ {nd[i + 1], 1, v[i]};\n            nd[i + 1]->prv[0] = nd[i];\n        }\n \
    \       nd[0]->prv[0] = nullptr;\n        nd[n]->nxt[0] = {nullptr, 1, M::id()};\n\
    \        rep (i, 1, lev[0]) {\n            std::vector<int> idx;\n           \
    \ rep (j, n + 1) {\n                if (lev[j] > i) idx.push_back(j);\n      \
    \      }\n            const int m = idx.size();\n            rep (j, m - 1) {\n\
    \                nd[idx[j]]->nxt[i] = {nd[idx[j + 1]], idx[j + 1] - idx[j],\n\
    \                                      nd[idx[j]]->nxt[i - 1].sm};\n         \
    \       for (node_ptr ptr = nd[idx[j]]->nxt[i - 1].node;\n                   \
    \  ptr != nd[idx[j + 1]]; ptr = ptr->nxt[i - 1].node) {\n                    nd[idx[j]]->nxt[i].sm\
    \ =\n                        M::op(nd[idx[j]]->nxt[i].sm, ptr->nxt[i - 1].sm);\n\
    \                }\n                nd[idx[j + 1]]->prv[i] = nd[idx[j]];\n   \
    \         }\n            nd[idx[0]]->prv[i] = nullptr;\n            nd[idx[m -\
    \ 1]]->nxt[i] = {nullptr, 1, M::id()};\n        }\n        sl = {nd[0], nd[n]};\n\
    \    }\n    int size() const {\n        assert(sl.first);\n        return sl.first\
    \ == sl.second ? 0 : sl.first->nxt.back().dist;\n    }\n    bool empty() const\
    \ { return sl.first == sl.second; }\n    void insert(int k, const T& x) {\n  \
    \      const int n = size();\n        assert(0 <= k && k <= n);\n        if (n\
    \ == 0) {\n            delete sl.first;\n            sl.first = new node(1);\n\
    \            sl.second = new node(1);\n            sl.first->nxt[0] = {sl.second,\
    \ 1, x};\n            sl.second->prv[0] = sl.first;\n            return;\n   \
    \     }\n        if (k == 0) {\n            /*\n            if (lev < sl.first->level())\
    \ {\n                node_ptr ptr = new node(lev);\n                rep (i, lev)\
    \ {\n                    ptr->nxt[i] = sl.first->nxt[i];\n                   \
    \ sl.first->nxt[i].node->prv[i] = ptr;\n                    sl.first->nxt[i] =\
    \ {ptr, 1, x};\n                    ptr->prv[i] = sl.first;\n                }\n\
    \                rep (i, lev, sl.first->level()) {\n                    ++sl.first->nxt[i].dist;\n\
    \                    sl.first->nxt[i].sm = M::op(x, sl.first->nxt[i].sm);\n  \
    \              }\n            }\n            else {\n                node_ptr\
    \ ptr = new node(lev);\n                rep (i, sl.first->level()) {\n       \
    \             ptr->nxt[i] = sl.first->nxt[i];\n                    sl.first->nxt[i].node->prv[i]\
    \ = ptr;\n                    sl.first->nxt[i] = {ptr, 1, x};\n              \
    \      ptr->prv[i] = sl.first;\n                }\n                rep (i, sl.first->level(),\
    \ lev) {\n                    sl.first->nxt[i] = sl.first->nxt[i - 1];\n     \
    \               sl.first->prv[i] = sl.first->prv[i - 1];\n                }\n\
    \                sl.first->prv.resize(lev + 1, {sl.first->prv.back()});\n    \
    \            sl.first->nxt.resize(lev + 1, {sl.first->nxt.back()});\n        \
    \        sl.second->prv.resize(lev + 1, {sl.second->prv.back()});\n          \
    \      sl.second->nxt.resize(lev + 1, {sl.second->nxt.back()});\n            \
    \    sl.first->nxt.back() = {sl.second, sl.first->nxt.back().dist +\n        \
    \    1, M::op(x, sl.first->nxt.back().sm)}; sl.second->prv.back() =\n        \
    \    sl.first;\n            }\n            */\n\n\n            nodepair p{new\
    \ node(1), new node(1)};\n            p.first->nxt[0] = {p.second, 1, x};\n  \
    \          p.second->prv[0] = p.first;\n            sl = merge(std::move(p), std::move(sl),\
    \ rnd);\n            return;\n        }\n        const int h = sl.first->level();\n\
    \        std::vector<node_ptr> lft(h);\n        std::vector<int> idx(h);\n   \
    \     lft[h - 1] = sl.first;\n        idx[h - 1] = 0;\n        rrep (i, h - 1)\
    \ {\n            lft[i] = lft[i + 1];\n            idx[i] = idx[i + 1];\n    \
    \        while (idx[i] + lft[i]->nxt[i].dist < k) {\n                idx[i] +=\
    \ lft[i]->nxt[i].dist;\n                lft[i] = lft[i]->nxt[i].node;\n      \
    \      }\n        }\n        rrep (i, h, 1) eval(lft[i], i);\n        const int\
    \ lev = get_level(rnd);\n        node_ptr np = new node(lev);\n        if (lev\
    \ < h) {\n            rep (i, lev) {\n                const auto l = lft[i];\n\
    \                const auto r = lft[i]->nxt[i].node;\n                np->nxt[i]\
    \ = {r, idx[i] + l->nxt[i].dist - k + 1, x};\n                r->prv[i] = np;\n\
    \                l->nxt[i] = {np, k - idx[i], l->nxt[i].sm};\n               \
    \ np->prv[i] = l;\n            }\n            rep (i, lev, h) ++lft[i]->nxt[i].dist;\n\
    \            rep (i, 1, h) {\n                calc(lft[i], i);\n             \
    \   if (i < lev) calc(lft[i]->nxt[i].node, i);\n            }\n        }\n   \
    \     else {\n            rep (i, h) {\n                const auto l = lft[i];\n\
    \                const auto r = lft[i]->nxt[i].node;\n                np->nxt[i]\
    \ = {r, idx[i] + l->nxt[i].dist - k + 1, x};\n                r->prv[i] = np;\n\
    \                l->nxt[i] = {np, k - idx[i], l->nxt[i].sm};\n               \
    \ np->prv[i] = l;\n            }\n            rep (i, 1, h) {\n              \
    \  calc(lft[i], i);\n                if (i < lev) calc(lft[i]->nxt[i].node, i);\n\
    \            }\n            sl.first->prv.resize(lev + 1, {sl.first->prv.back()});\n\
    \            sl.first->nxt.resize(lev + 1, {sl.second, n + 1, x});\n         \
    \   sl.second->prv.resize(lev + 1, sl.first);\n            sl.second->nxt.resize(lev\
    \ + 1, {sl.second->nxt.back()});\n            rep (i, h, lev) {\n            \
    \    sl.first->nxt[i] = {np, k, x};\n                np->prv[i] = sl.first;\n\
    \                np->nxt[i] = {sl.second, n - k + 1, x};\n                sl.second->prv[i]\
    \ = np;\n                calc(sl.first, i);\n                calc(np, i);\n  \
    \          }\n            calc(sl.first, lev);\n        }\n    }\n    void erase(int\
    \ k) {\n        const int n = size();\n        assert(0 <= k && k < n);\n    \
    \    if (n == 1) {\n            delete sl.first;\n            delete sl.second;\n\
    \            sl.first = sl.second = new node(1);\n            return;\n      \
    \  }\n        if (k == 0) {\n            all_eval(sl, 0);\n            all_eval(sl,\
    \ 1);\n            rep (i, sl.first->level()) {\n                if (sl.first->nxt[i].dist\
    \ == 1) {\n                    const auto l = sl.first;\n                    const\
    \ auto m = l->nxt[i].node;\n                    const auto r = m->nxt[i].node;\n\
    \                    l->nxt[i] = {r, l->nxt[i].dist + m->nxt[i].dist - 1,\n  \
    \                               m->nxt[i].sm};\n                    r->prv[i]\
    \ = l;\n                }\n                else {\n                    sl.first->nxt[i].dist--;\n\
    \                }\n            }\n            rep (i, 1, sl.first->level()) calc(sl.first,\
    \ i);\n            return;\n        }\n        all_eval(sl, k - 1);\n        all_eval(sl,\
    \ k);\n        node_ptr np = sl.first;\n        int cnt = 0;\n        rrep (i,\
    \ sl.first->level()) {\n            while (cnt + np->nxt[i].dist <= k) {\n   \
    \             cnt += np->nxt[i].dist;\n                np = np->nxt[i].node;\n\
    \            }\n            if (cnt == k) {\n                const auto l = np->prv[i];\n\
    \                const auto r = np->nxt[i].node;\n                r->prv[i] =\
    \ l;\n                l->nxt[i] = {r, l->nxt[i].dist + np->nxt[i].dist - 1,\n\
    \                             l->nxt[i].sm};\n            }\n            else\
    \ {\n                np->nxt[i].dist--;\n            }\n        }\n        delete\
    \ np;\n        all_calc(sl, k - 1);\n    }\n    T prod(int l, int r) const {\n\
    \        assert(0 <= l && l <= r && r <= size());\n        all_eval(sl, l);\n\
    \        all_eval(sl, r - 1);\n        auto np = get_ptr(sl, l);\n        T sm\
    \ = M::id();\n        rrep (i, sl.first->level()) {\n            while (1) {\n\
    \                int t = std::min((int)i, np->level() - 1);\n                if\
    \ (l + np->nxt[t].dist > r) break;\n                l += np->nxt[t].dist;\n  \
    \              sm = M::op(sm, np->nxt[t].sm);\n                np = np->nxt[t].node;\n\
    \            }\n        }\n        return sm;\n    }\n    T all_prod() const {\
    \ return sl.first->nxt.back().sm; }\n    T get(int k) const {\n        assert(0\
    \ <= k && k < size());\n        all_eval(sl, k);\n        return get_ptr(sl, k)->nxt[0].sm;\n\
    \    }\n    void apply(int l, int r, const U& x) {\n        assert(0 <= l && l\
    \ <= r && r <= size());\n        all_eval(sl, l);\n        all_eval(sl, r - 1);\n\
    \        auto np = get_ptr(sl, l);\n        int idx = l;\n        rrep (i, sl.first->level())\
    \ {\n            while (1) {\n                int t = std::min((int)i, np->level()\
    \ - 1);\n                if (idx + np->nxt[t].dist > r) break;\n             \
    \   idx += np->nxt[t].dist;\n                all_apply(np, t, x);\n          \
    \      np = np->nxt[t].node;\n            }\n        }\n        all_eval(sl, l);\n\
    \        all_eval(sl, r - 1);\n        all_calc(sl, l);\n        all_calc(sl,\
    \ r - 1);\n    }\n    template<class Upd> void update(int k, const Upd& upd) {\n\
    \        assert(0 <= k && k < size());\n        all_eval(sl, k);\n        auto\
    \ nd = get_ptr(sl, k);\n        nd->nxt[0].sm = upd(nd->nxt[0].sm);\n        all_calc(sl,\
    \ k);\n    }\n    void set(int k, const T& x) {\n        update(k, [&](const T&)\
    \ { return x; });\n    }\n    void apply(int k, const U& x) {\n        update(k,\
    \ [&](const T& sm) { return E::op(x, sm); });\n    }\n    template<class C> int\
    \ max_right(int l, const C& cond) const {\n        assert(0 <= l && l <= size());\n\
    \        assert(cond(M::id()));\n        if (l == size()) return size();\n   \
    \     all_eval(sl, l);\n        auto np = get_ptr(sl, l);\n        T sm = M::id();\n\
    \        rrep (i, sl.first->level()) {\n            while (1) {\n            \
    \    int t = std::min((int)i, np->level() - 1);\n                if (t != np->level()\
    \ - 1) eval(np, t + 1);\n                if (!cond(M::op(sm, np->nxt[t].sm)))\
    \ break;\n                sm = M::op(sm, np->nxt[t].sm);\n                l +=\
    \ np->nxt[t].dist;\n                np = np->nxt[t].node;\n                if\
    \ (np == sl.second) return size();\n            }\n        }\n        return l;\n\
    \    }\n    template<class C> int min_left(int r, const C& cond) const {\n   \
    \     assert(0 <= r && r <= size());\n        assert(cond(M::id()));\n       \
    \ if (r == 0) return 0;\n        all_eval(sl, r - 1);\n        auto np = get_ptr(sl,\
    \ r);\n        T sm = M::id();\n        rrep (i, sl.first->level()) {\n      \
    \      while (1) {\n                int t = std::min((int)i, np->level() - 1);\n\
    \                if (t != np->level() - 1) eval(np->prv[t], t + 1);\n        \
    \        if (!cond(M::op(sm, np->prv[t]->nxt[t].sm))) break;\n               \
    \ sm = M::op(sm, np->prv[t]->nxt[t].sm);\n                r -= np->prv[t]->nxt[t].dist;\n\
    \                np = np->prv[t];\n                if (np == sl.first) return\
    \ 0;\n            }\n        }\n        return r;\n    }\n    std::vector<T> get_data()\
    \ const {\n        rrep (i, sl.first->level(), 1) {\n            for (node_ptr\
    \ ptr = sl.first; ptr != sl.second;\n                 ptr = ptr->nxt[i].node)\
    \ {\n                eval(ptr, i);\n            }\n        }\n        std::vector<T>\
    \ res;\n        res.reserve(size());\n        for (node_ptr ptr = sl.first; ptr\
    \ != sl.second;\n             ptr = ptr->nxt[0].node) {\n            res.push_back(ptr->nxt[0].sm);\n\
    \        }\n        return res;\n    }\n    friend SkipList merge(SkipList lhs,\
    \ SkipList rhs) {\n        return {merge(std::move(lhs.sl), std::move(rhs.sl),\
    \ lhs.rnd), lhs.rnd};\n    }\n    friend std::pair<SkipList, SkipList> split(SkipList\
    \ sl, int k) {\n        auto s = split(std::move(sl.sl), k);\n        return {SkipList{std::move(s.first),\
    \ sl.rnd},\n                SkipList{std::move(s.second), sl.rnd}};\n    }\n};\n\
    \ntemplate<class A, class Rand> class SkipList<A, Rand, true> {\nprivate:\n  \
    \  using Base = SkipList<Monoid::MultiAction<A>, Rand>;\n    using T_ = typename\
    \ A::M::value_type;\n    using U_ = typename A::E::value_type;\n    Base sl;\n\
    \    using elm = typename Monoid::MultiAction<A>::M::value_type;\n    static std::vector<elm>\
    \ get_elm_vec(const std::vector<T_>& v) {\n        const int n = v.size();\n \
    \       std::vector<elm> res(n);\n        rep (i, n) res[i] = {v[i], 1};\n   \
    \     return res;\n    }\n    SkipList(const Base& other) : sl(other) {}\n   \
    \ SkipList(Base&& other) : sl(std::move(other)) {}\n\npublic:\n    SkipList()\
    \ : SkipList(Rand()) {}\n    SkipList(const Rand& rnd) : sl(rnd) {}\n    SkipList(const\
    \ std::vector<T_>& v, const Rand& rnd = Rand())\n        : sl(get_elm_vec(v),\
    \ rnd) {}\n    void init(const std::vector<T_>& v) { sl.init(get_elm_vec(v));\
    \ }\n    int size() const { return sl.size(); }\n    bool empty() const { return\
    \ sl.empty(); }\n    void insert(int k, const T_& sm) { sl.insert(k, {sm, 1});\
    \ }\n    void erase(int k) { sl.erase(k); }\n    T_ prod(int l, int r) const {\
    \ return sl.prod(l, r).val; }\n    T_ all_prod() const { return sl.all_prod().val;\
    \ }\n    T_ get(int k) const { return sl.get(k).val; }\n    void apply(int l,\
    \ int r, const U_& x) { sl.apply(l, r, x); }\n    template<class Upd> void update(int\
    \ k, const Upd& upd) {\n        sl.update(k, [&](const elm& e) -> elm { return\
    \ {upd(e.val), e.len}; });\n    }\n    void set(int k, const T_& x) { sl.set(k,\
    \ {x, 1}); }\n    void apply(int k, const U_& x) { sl.apply(k, x); }\n    template<class\
    \ C> int max_right(int l, const C& cond) const {\n        return sl.max_right(l,\n\
    \                            [&](const elm& e) -> bool { return cond(e.val); });\n\
    \    }\n    template<class C> int min_left(int r, const C& cond) const {\n   \
    \     return sl.min_left(r,\n                           [&](const elm& e) -> bool\
    \ { return cond(e.val); });\n    }\n    std::vector<T_> get_data() const {\n \
    \       std::vector<elm> d = sl.get_data();\n        std::vector<T_> res(d.size());\n\
    \        rep (i, d.size()) res[i] = d[i].val;\n        return res;\n    }\n  \
    \  friend SkipList merge(SkipList lhs, SkipList rhs) {\n        return {merge(std::move(lhs.sl),\
    \ std::move(rhs.sl))};\n    }\n    friend std::pair<SkipList, SkipList> split(SkipList\
    \ sl, int k) {\n        auto s = split(std::move(sl.sl), k);\n        return {SkipList{std::move(s.first)},\
    \ SkipList{std::move(s.second)}};\n    }\n};\n\n/**\n * @brief SkipList\n * @docs\
    \ docs/data-struct/other/SkipList.md\n */\n"
  dependsOn:
  - other/template.hpp
  - other/monoid.hpp
  - random/Random.hpp
  isVerificationFile: false
  path: data-struct/other/SkipList.hpp
  requiredBy: []
  timestamp: '2022-08-18 19:11:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/data_structure/dynamic_sequence_range_affine_range_sum.test.cpp
documentation_of: data-struct/other/SkipList.hpp
layout: document
redirect_from:
- /library/data-struct/other/SkipList.hpp
- /library/data-struct/other/SkipList.hpp.html
title: SkipList
---
## 概要

セグ木の各区切り目の高さをルーラー関数ではなくランダムにした感じのデータ構造。なので insert や erase ができる。

- コンストラクタ
  - `SkipList()` : 長さ $0$ に初期化する。 $\Theta(1)$ 。
  - `SkipList(Rand rnd)` : 乱数生成器を `rnd` で初期化する。 $\Theta(1)$ 。
  - `SkipList(vector<T> , Rand rnd = Rand())` : 列 `v` で初期化する。期待 $\Theta(N)$ 。
  - `void init(vector<T> v)` : 列 `v` で初期化する。期待 $\Theta(N)$ 。
- 取得クエリ
  - `T prod(int l, int r)` : `op(a[l], a[l+1], ..., a[r-1])` を返す。期待 $\Theta(\log N)$ 。
  - `T get(int k)` : `a[k]` を返す。期待 $\Theta(\log N)$ 。
  - `T all_prod()` : `op(a[0], a[1], ..., a[N-1])` を返す。 $\Theta(1)$ 
  - `int size()` : 列の長さを返す。 $\Theta(1)$ 。
  - `bool empty()` : 列が空であるかを返す。 $\Theta(1)$ 。
- 追加/削除クエリ
  - `void insert(int k, T x)` : `k` 番目に `x` を挿入する。期待 $\Theta(\log N)$ 。
  - `void erase(int k)` : `k` 番目の要素を削除する。期待 $\Theta(\log N)$ 。
- 更新クエリ
  - `void set(int k, T x)` : `a[k]` に `x` を代入する。期待 $\Theta(\log N)$ 。
  - `void apply(int k, U f)` : `a[k]` に `mp(f, a[k])` を代入する。期待 $\Theta(\log N)$ 。
  - `void update(int k, T upd(T))` : `a[k]` に `upd(a[k])` を代入する。期待 $\Theta(\log N)$ 。
  - `void apply(int l, int r, U f)` : `a[l], a[l+1], ..., a[r-1]` に `mp(f, a[l]), mp(f, a[l+1]), ..., mp(f, a[r-1])` を代入する。期待 $\Theta(\log N)$ 。
- セグメント木上の二分探索
  - `int max_right(int l, bool f(T))` :  
`[l, r)` に対して `f` が `true` を返すような最大の `r` を返す。`f(e) = true` である必要がある。期待 $\Theta(\log N)$ 。  
厳密には、以下の条件を共に満たす `r` (のうち1つ)を返す。  
    - `r = l` または `f(op(a[l], a[l+1], ..., a[r-1])) = true`
    - `r = n` または `f(op(a[l], a[l+1], ..., a[r])) = false`
  - `int min_left(int r, bool f(T))` :  
`[l, r)` に対して `f` が `true` を返すような最小の `l` を返す。`f(e) = true` である必要がある。期待 $\Theta(\log N)$ 。  
厳密には、以下の条件を共に満たす `l` (のうち1つ)を返す。  
    - `l = r` または `f(op(a[l], a[l+1], ..., a[r-1])) = true`
    - `l = 0` または `f(op(a[l-1], a[l], ..., a[r-1])) = false`
