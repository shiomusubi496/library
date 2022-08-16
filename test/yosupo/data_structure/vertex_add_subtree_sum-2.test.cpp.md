---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-struct/segment/BinaryIndexedTree.hpp
    title: BinaryIndexedTree(FenwickTree, BIT)
  - icon: ':question:'
    path: graph/Graph.hpp
    title: Graph-template
  - icon: ':x:'
    path: graph/tree/EulerTourSubtree.hpp
    title: "EulerTourSubtree(\u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC\u90E8\u5206\
      \u6728\u30AF\u30A8\u30EA)"
  - icon: ':question:'
    path: other/monoid.hpp
    title: other/monoid.hpp
  - icon: ':question:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "#line 1 \"test/yosupo/data_structure/vertex_add_subtree_sum-2.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\n\
    #line 2 \"other/template.hpp\"\n\n#include <bits/stdc++.h>\n\n#ifndef __COUNTER__\n\
    #define __COUNTER__ __LINE__\n#endif\n\n#define REP_SELECTER(a, b, c, d, e, ...)\
    \ e\n#define REP1_0(b, c) REP1_1(b, c)\n#define REP1_1(b, c)                 \
    \                                          \\\n    for (ll REP_COUNTER_##c = 0;\
    \ REP_COUNTER_##c < (ll)(b); ++REP_COUNTER_##c)\n#define REP1(b) REP1_0(b, __COUNTER__)\n\
    #define REP2(i, b) for (ll i = 0; i < (ll)(b); ++i)\n#define REP3(i, a, b) for\
    \ (ll i = (ll)(a); i < (ll)(b); ++i)\n#define REP4(i, a, b, c) for (ll i = (ll)(a);\
    \ i < (ll)(b); i += (ll)(c))\n#define rep(...) REP_SELECTER(__VA_ARGS__, REP4,\
    \ REP3, REP2, REP1)(__VA_ARGS__)\n#define RREP2(i, a) for (ll i = (ll)(a)-1; i\
    \ >= 0; --i)\n#define RREP3(i, a, b) for (ll i = (ll)(a)-1; i >= (ll)(b); --i)\n\
    #define RREP4(i, a, b, c) for (ll i = (ll)(a)-1; i >= (ll)(b); i -= (ll)(c))\n\
    #define rrep(...) REP_SELECTER(__VA_ARGS__, RREP4, RREP3, RREP2)(__VA_ARGS__)\n\
    #define REPS2(i, b) for (ll i = 1; i <= (ll)(b); ++i)\n#define REPS3(i, a, b)\
    \ for (ll i = (ll)(a) + 1; i <= (ll)(b); ++i)\n#define REPS4(i, a, b, c) for (ll\
    \ i = (ll)(a) + 1; i <= (ll)(b); i += (ll)(c))\n#define reps(...) REP_SELECTER(__VA_ARGS__,\
    \ REPS4, REPS3, REPS2)(__VA_ARGS__)\n#define RREPS2(i, a) for (ll i = (ll)(a);\
    \ i > 0; --i)\n#define RREPS3(i, a, b) for (ll i = (ll)(a); i > (ll)(b); --i)\n\
    #define RREPS4(i, a, b, c) for (ll i = (ll)(a); i > (ll)(b); i -= (ll)(c))\n#define\
    \ rreps(...)                                                             \\\n\
    \    REP_SELECTER(__VA_ARGS__, RREPS4, RREPS3, RREPS2)(__VA_ARGS__)\n\n#define\
    \ each_for(...) for (auto&& __VA_ARGS__)\n#define each_const(...) for (const auto&\
    \ __VA_ARGS__)\n\n#define all(v) std::begin(v), std::end(v)\n#define rall(v) std::rbegin(v),\
    \ std::rend(v)\n\n#if __cplusplus >= 201402L\n#define CONSTEXPR constexpr\n#else\n\
    #define CONSTEXPR\n#endif\n\n#ifdef __cpp_if_constexpr\n#define IF_CONSTEXPR constexpr\n\
    #else\n#define IF_CONSTEXPR\n#endif\n\nusing ll = long long;\nusing ull = unsigned\
    \ long long;\nusing ld = long double;\nusing PLL = std::pair<ll, ll>;\ntemplate<class\
    \ T>\nusing prique = std::priority_queue<T, std::vector<T>, std::greater<T>>;\n\
    \ntemplate<class T> class infinity {\npublic:\n    static constexpr T value =\
    \ std::numeric_limits<T>::max() / 2;\n    static constexpr T mvalue = std::numeric_limits<T>::min()\
    \ / 2;\n    static constexpr T max = std::numeric_limits<T>::max();\n    static\
    \ constexpr T min = std::numeric_limits<T>::min();\n};\n\n#if __cplusplus <= 201402L\n\
    template<class T> constexpr T infinity<T>::value;\ntemplate<class T> constexpr\
    \ T infinity<T>::mvalue;\ntemplate<class T> constexpr T infinity<T>::max;\ntemplate<class\
    \ T> constexpr T infinity<T>::min;\n#endif\n\n#if __cplusplus >= 201402L\ntemplate<class\
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
    inline std::vector<ll> prime_factor(ll N) noexcept {\n    std::vector<ll> res;\n\
    \    for (ll i = 2; i * i <= N; ++i) {\n        while (N % i == 0) {\n       \
    \     res.push_back(i);\n            N /= i;\n        }\n    }\n    if (N != 1)\
    \ res.push_back(N);\n    return res;\n}\n\ninline CONSTEXPR ll my_pow(ll a, ll\
    \ b) noexcept {\n    ll res = 1;\n    while (b) {\n        if (b & 1) res *= a;\n\
    \        b >>= 1;\n        a *= a;\n    }\n    return res;\n}\ninline CONSTEXPR\
    \ ll mod_pow(ll a, ll b, ll mod) noexcept {\n    assert(mod > 0);\n    if (mod\
    \ == 1) return 0;\n    a %= mod;\n    ll res = 1;\n    while (b) {\n        if\
    \ (b & 1) (res *= a) %= mod;\n        b >>= 1;\n        (a *= a) %= mod;\n   \
    \ }\n    return res;\n}\n\ninline PLL extGCD(ll a, ll b) noexcept {\n    const\
    \ ll n = a, m = b;\n    ll x = 1, y = 0, u = 0, v = 1;\n    ll t;\n    while (b)\
    \ {\n        t = a / b;\n        std::swap(a -= t * b, b);\n        std::swap(x\
    \ -= t * u, u);\n        std::swap(y -= t * v, v);\n    }\n    if (x < 0) {\n\
    \        x += m;\n        y -= n;\n    }\n    return {x, y};\n}\ninline ll mod_inv(ll\
    \ a, ll mod) noexcept {\n    ll b = mod;\n    ll x = 1, u = 0;\n    ll t;\n  \
    \  while (b) {\n        t = a / b;\n        std::swap(a -= t * b, b);\n      \
    \  std::swap(x -= t * u, u);\n    }\n    if (x < 0) x += mod;\n    assert(a ==\
    \ 1);\n    return x;\n}\ninline PLL ChineseRemainder(ll b1, ll m1, ll b2, ll m2)\
    \ noexcept {\n    const PLL p = extGCD(m1, m2);\n    const ll g = p.first * m1\
    \ + p.second * m2;\n    const ll l = m1 / g * m2;\n    if ((b2 - b1) % g != 0)\
    \ return PLL{-1, -1};\n    const ll x = (b2 - b1) / g * p.first % (m2 / g);\n\
    \    return {(x * m1 + b1 + l) % l, l};\n}\nPLL ChineseRemainders(const std::vector<ll>&\
    \ b,\n                      const std::vector<ll>& m) noexcept {\n    PLL res{0,\
    \ 1};\n    rep (i, b.size()) {\n        res = ChineseRemainder(res.first, res.second,\
    \ b[i], m[i]);\n        if (res.first == -1) return res;\n    }\n    return res;\n\
    }\n\ntemplate<class F> class RecLambda {\nprivate:\n    F f;\n\npublic:\n    explicit\
    \ constexpr RecLambda(F&& f_) : f(std::forward<F>(f_)) {}\n    template<class...\
    \ Args>\n    constexpr auto operator()(Args&&... args) const\n        -> decltype(f(*this,\
    \ std::forward<Args>(args)...)) {\n        return f(*this, std::forward<Args>(args)...);\n\
    \    }\n};\n\ntemplate<class F> inline constexpr RecLambda<F> rec_lambda(F&& f)\
    \ {\n    return RecLambda<F>(std::forward<F>(f));\n}\n\ntemplate<class Head, class...\
    \ Tail> struct multi_dim_vector {\n    using type = std::vector<typename multi_dim_vector<Tail...>::type>;\n\
    };\ntemplate<class T> struct multi_dim_vector<T> { using type = T; };\n\ntemplate<class\
    \ T, class Arg>\nconstexpr std::vector<T> make_vec(int n, Arg&& arg) {\n    return\
    \ std::vector<T>(n, std::forward<Arg>(arg));\n}\ntemplate<class T, class... Args>\n\
    constexpr typename multi_dim_vector<Args..., T>::type make_vec(int n,\n      \
    \                                                         Args&&... args) {\n\
    \    return typename multi_dim_vector<Args..., T>::type(\n        n, make_vec<T>(std::forward<Args>(args)...));\n\
    }\n\ninline CONSTEXPR int popcnt(ull x) {\n#if __cplusplus >= 202002L\n    return\
    \ std::popcount(x);\n#endif\n    x = (x & 0x5555555555555555) + ((x >> 1) & 0x5555555555555555);\n\
    \    x = (x & 0x3333333333333333) + ((x >> 2) & 0x3333333333333333);\n    x =\
    \ (x & 0x0f0f0f0f0f0f0f0f) + ((x >> 4) & 0x0f0f0f0f0f0f0f0f);\n    x = (x & 0x00ff00ff00ff00ff)\
    \ + ((x >> 8) & 0x00ff00ff00ff00ff);\n    x = (x & 0x0000ffff0000ffff) + ((x >>\
    \ 16) & 0x0000ffff0000ffff);\n    return (x & 0x00000000ffffffff) + ((x >> 32)\
    \ & 0x00000000ffffffff);\n}\n\ntemplate<class T, class Comp = std::less<T>> class\
    \ presser {\nprivate:\n    std::vector<T> dat;\n    Comp cmp;\n    bool sorted\
    \ = false;\n\npublic:\n    presser() : presser(Comp()) {}\n    presser(const Comp&\
    \ cmp) : cmp(cmp) {}\n    presser(const std::vector<T>& vec, const Comp& cmp =\
    \ Comp())\n        : dat(vec), cmp(cmp) {}\n    presser(std::vector<T>&& vec,\
    \ const Comp& cmp = Comp())\n        : dat(std::move(vec)), cmp(cmp) {}\n    presser(std::initializer_list<T>\
    \ il, const Comp& cmp = Comp())\n        : dat(il.begin(), il.end()), cmp(cmp)\
    \ {}\n    void reserve(int n) {\n        assert(!sorted);\n        dat.reserve(n);\n\
    \    }\n    void push_back(const T& v) {\n        assert(!sorted);\n        dat.push_back(v);\n\
    \    }\n    void push_back(T&& v) {\n        assert(!sorted);\n        dat.push_back(std::move(v));\n\
    \    }\n    void push(const std::vector<T>& vec) {\n        assert(!sorted);\n\
    \        const int n = dat.size();\n        dat.resize(n + vec.size());\n    \
    \    rep (i, vec.size()) dat[n + i] = vec[i];\n    }\n    int build() {\n    \
    \    assert(!sorted);\n        sorted = true;\n        std::sort(all(dat), cmp);\n\
    \        dat.erase(std::unique(all(dat),\n                              [&](const\
    \ T& a, const T& b) -> bool {\n                                  return !cmp(a,\
    \ b) && !cmp(b, a);\n                              }),\n                  dat.end());\n\
    \        return dat.size();\n    }\n    const T& operator[](int k) const& {\n\
    \        assert(sorted);\n        assert(0 <= k && k < (int)dat.size());\n   \
    \     return dat[k];\n    }\n    T operator[](int k) && {\n        assert(sorted);\n\
    \        assert(0 <= k && k < (int)dat.size());\n        return std::move(dat[k]);\n\
    \    }\n    int get_index(const T& val) const {\n        assert(sorted);\n   \
    \     return static_cast<int>(std::lower_bound(all(dat), val, cmp) -\n       \
    \                         dat.begin());\n    }\n    std::vector<int> pressed(const\
    \ std::vector<T>& vec) const {\n        assert(sorted);\n        std::vector<int>\
    \ res(vec.size());\n        rep (i, vec.size()) res[i] = get_index(vec[i]);\n\
    \        return res;\n    }\n    void press(std::vector<T>& vec) const {\n   \
    \     static_assert(std::is_integral<T>::value,\n                      \"template\
    \ argument must be convertible from int type\");\n        assert(sorted);\n  \
    \      each_for (i : vec) i = get_index(i);\n    }\n    int size() const {\n \
    \       assert(sorted);\n        return dat.size();\n    }\n    const std::vector<T>&\
    \ data() const& { return dat; }\n    std::vector<T> data() && { return std::move(dat);\
    \ }\n};\n#line 2 \"data-struct/segment/BinaryIndexedTree.hpp\"\n\n#line 2 \"other/monoid.hpp\"\
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
    \ b.val), b.len};\n    }\n};\n\n} // namespace Monoid\n#line 5 \"data-struct/segment/BinaryIndexedTree.hpp\"\
    \n\ntemplate<class M, bool = Monoid::is_monoid<M>::value> class BinaryIndexedTree\
    \ {\nprivate:\n    using T = typename M::value_type;\n    int n;\n    std::vector<T>\
    \ data;\n\npublic:\n    BinaryIndexedTree() : BinaryIndexedTree(0) {}\n    BinaryIndexedTree(int\
    \ n_) { init(n_); }\n    void init(int n_) {\n        n = n_;\n        data.assign(n\
    \ + 1, M::id());\n    }\n    void apply(int k, T x) {\n        assert(0 <= k &&\
    \ k < n);\n        ++k;\n        while (k <= n) {\n            data[k] = M::op(data[k],\
    \ x);\n            k += k & -k;\n        }\n    }\n    T prod(int k) const {\n\
    \        assert(0 <= k && k <= n);\n        T res = M::id();\n        while (k)\
    \ {\n            res = M::op(res, data[k]);\n            k -= k & -k;\n      \
    \  }\n        return res;\n    }\n    template<bool AlwaysTrue = true,\n     \
    \        typename std::enable_if<Monoid::has_inv<M>::value &&\n              \
    \                       AlwaysTrue>::type* = nullptr>\n    T prod(int l, int r)\
    \ const {\n        assert(l <= r);\n        return M::inv(prod(r), prod(l));\n\
    \    }\n    T get(int k) const { return prod(k, k + 1); }\n    void set(int k,\
    \ T x) { apply(k, M::inv(x, prod(k))); }\n};\n\ntemplate<class T>\nclass BinaryIndexedTree<T,\
    \ false> : public BinaryIndexedTree<Monoid::Sum<T>> {\nprivate:\n    using Base\
    \ = BinaryIndexedTree<Monoid::Sum<T>>;\n\npublic:\n    using Base::Base;\n   \
    \ void add(int k, T x) { this->apply(k, x); }\n    T sum(int k) const { return\
    \ this->prod(k); }\n    T sum(int l, int r) const { return this->prod(l, r); }\n\
    };\n\n/**\n * @brief BinaryIndexedTree(FenwickTree, BIT)\n * @docs docs/data-struct/segment/BinaryIndexedTree.md\n\
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
    \ * @docs docs/graph/Graph.md\n */\n#line 2 \"graph/tree/EulerTourSubtree.hpp\"\
    \n\n#line 5 \"graph/tree/EulerTourSubtree.hpp\"\n\ntemplate<class T> class EulerTourSubtree\
    \ {\nprivate:\n    int n, cnt;\n    std::vector<int> root;\n    const Graph<T>&\
    \ G;\n    std::vector<std::pair<int, int>> idx;\n    void dfs(int v, int p) {\n\
    \        idx[v].first = cnt++;\n        each_const (e : G[v]) {\n            if\
    \ (e.to != p) dfs(e.to, v);\n        }\n        idx[v].second = cnt;\n    }\n\
    \    void init() {\n        n = G.size();\n        idx.assign(n, {-1, -1});\n\
    \        cnt = 0;\n        each_const (r : root) dfs(r, -1);\n        rep (i,\
    \ n) {\n            if (idx[i].first == -1) dfs(i, -1);\n        }\n    }\n\n\
    public:\n    EulerTourSubtree(const Graph<T>& G, int root = 0) : root({root}),\
    \ G(G) {\n        init();\n    }\n    EulerTourSubtree(const Graph<T>& G, const\
    \ std::vector<int>& root)\n        : root(root), G(G) {\n        init();\n   \
    \ }\n    const std::pair<int, int>& get_idx(int k) const& { return idx[k]; }\n\
    \    std::pair<int, int> get_idx(int k) && { return std::move(idx[k]); }\n   \
    \ int get_par(int a, int b) const {\n        return idx[a].first < idx[b].first\
    \ ? a : b;\n    }\n    template<class F> void each_vertex_subtree(int v, const\
    \ F& f) const {\n        f(idx[v].first, idx[v].second);\n    }\n    template<class\
    \ F> void each_edge_subtree(int v, const F& f) const {\n        f(idx[v].first\
    \ + 1, idx[v].second);\n    }\n};\n\n/**\n * @brief EulerTourSubtree(\u30AA\u30A4\
    \u30E9\u30FC\u30C4\u30A2\u30FC\u90E8\u5206\u6728\u30AF\u30A8\u30EA)\n * @docs\
    \ docs/graph/tree/EulerTourSubtree.md\n */\n#line 6 \"test/yosupo/data_structure/vertex_add_subtree_sum-2.test.cpp\"\
    \nusing namespace std;\nint main() {\n    int N, Q; cin >> N >> Q;\n    vector<ll>\
    \ A(N); cin >> A;\n    Graph<int> G(N);\n    rep (i, 1, N) {\n        int p; cin\
    \ >> p;\n        G.add_edge(i, p);\n    }\n    EulerTourSubtree<int> ET(G);\n\
    \    BinaryIndexedTree<ll> BIT(N);\n    rep (i, N) {\n        auto p = ET.get_idx(i);\n\
    \        BIT.add(p.first, A[i]);\n    }\n    rep (i, Q) {\n        int t; cin\
    \ >> t;\n        if (t == 0) {\n            int p; ll x; cin >> p >> x;\n    \
    \        auto idx = ET.get_idx(p);\n            BIT.add(idx.first, x);\n     \
    \   }\n        else {\n            int u; cin >> u;\n            ll ans = 0;\n\
    \            ET.each_vertex_subtree(u, [&](int l, int r) { ans += BIT.sum(l, r);\
    \ });\n            cout << ans << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n#include \"../../../other/template.hpp\"\n#include \"../../../data-struct/segment/BinaryIndexedTree.hpp\"\
    \n#include \"../../../graph/Graph.hpp\"\n#include \"../../../graph/tree/EulerTourSubtree.hpp\"\
    \nusing namespace std;\nint main() {\n    int N, Q; cin >> N >> Q;\n    vector<ll>\
    \ A(N); cin >> A;\n    Graph<int> G(N);\n    rep (i, 1, N) {\n        int p; cin\
    \ >> p;\n        G.add_edge(i, p);\n    }\n    EulerTourSubtree<int> ET(G);\n\
    \    BinaryIndexedTree<ll> BIT(N);\n    rep (i, N) {\n        auto p = ET.get_idx(i);\n\
    \        BIT.add(p.first, A[i]);\n    }\n    rep (i, Q) {\n        int t; cin\
    \ >> t;\n        if (t == 0) {\n            int p; ll x; cin >> p >> x;\n    \
    \        auto idx = ET.get_idx(p);\n            BIT.add(idx.first, x);\n     \
    \   }\n        else {\n            int u; cin >> u;\n            ll ans = 0;\n\
    \            ET.each_vertex_subtree(u, [&](int l, int r) { ans += BIT.sum(l, r);\
    \ });\n            cout << ans << endl;\n        }\n    }\n}\n"
  dependsOn:
  - other/template.hpp
  - data-struct/segment/BinaryIndexedTree.hpp
  - other/monoid.hpp
  - graph/Graph.hpp
  - graph/tree/EulerTourSubtree.hpp
  isVerificationFile: true
  path: test/yosupo/data_structure/vertex_add_subtree_sum-2.test.cpp
  requiredBy: []
  timestamp: '2022-08-16 22:53:46+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/data_structure/vertex_add_subtree_sum-2.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/data_structure/vertex_add_subtree_sum-2.test.cpp
- /verify/test/yosupo/data_structure/vertex_add_subtree_sum-2.test.cpp.html
title: test/yosupo/data_structure/vertex_add_subtree_sum-2.test.cpp
---
