---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: other/monoid.hpp
    title: other/monoid.hpp
  - icon: ':heavy_check_mark:'
    path: other/template.hpp
    title: other/template.hpp
  - icon: ':heavy_check_mark:'
    path: random/Random.hpp
    title: Random
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/SkipList.md
    document_title: SkipList
    links: []
  bundledCode: "#line 2 \"data-struct/other/SkipList.hpp\"\n\n#line 2 \"other/template.hpp\"\
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
    \ }\n};\n#line 2 \"other/monoid.hpp\"\n\n#line 4 \"other/monoid.hpp\"\n\nnamespace\
    \ Monoid {\n\ntemplate<class M, class = void> class has_op : public std::false_type\
    \ {};\ntemplate<class M>\nclass has_op<M, decltype((void)M::op)> : public std::true_type\
    \ {};\n\ntemplate<class M, class = void> class has_id : public std::false_type\
    \ {};\ntemplate<class M>\nclass has_id<M, decltype((void)M::id)> : public std::true_type\
    \ {};\n\ntemplate<class M, class = void> class has_inv : public std::false_type\
    \ {};\ntemplate<class M>\nclass has_inv<M, decltype((void)M::inv)> : public std::true_type\
    \ {};\n\ntemplate<class M, class = void> class has_get_inv : public std::false_type\
    \ {};\ntemplate<class M>\nclass has_get_inv<M, decltype((void)M::get_inv)> : public\
    \ std::true_type {};\n\ntemplate<class M, class = void> class has_init : public\
    \ std::false_type {};\ntemplate<class M>\nclass has_init<M, decltype((void)M::init)>\
    \ : public std::true_type {};\n\ntemplate<class A, class = void> class has_mul_op\
    \ : public std::false_type {};\ntemplate<class A>\nclass has_mul_op<A, decltype((void)A::mul_op)>\
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
    \ E_::op(b, a); }\n};\n\n\ntemplate<class A> struct MultiAction {\n    struct\
    \ M {\n        struct value_type {\n        private:\n            using T_ = typename\
    \ A::M::value_type;\n        public:\n            T_ val;\n            ll len;\n\
    \            value_type() = default;\n            value_type(T_ v, ll l) : val(v),\
    \ len(l) {}\n            friend std::ostream& operator<<(std::ostream& ost,\n\
    \                                            const value_type& e) {\n        \
    \        return ost << e.val << '*' << e.len;\n            }\n        };\n   \
    \     static value_type op(const value_type& a, const value_type& b) {\n     \
    \       return {A::M::op(a.val, b.val), a.len + b.len};\n        }\n        static\
    \ value_type id() { return {A::M::id(), 0}; }\n        static value_type init(ll\
    \ l, ll r) {\n            return {A::M::init(l, r), r - l};\n        }\n    };\n\
    \    using E = typename A::E;\n\nprivate:\n    using T = typename M::value_type;\n\
    \    using U = typename E::value_type;\n\npublic:\n    static T op(const U& a,\
    \ const T& b) {\n        return {A::mul_op(a, b.len, b.val), b.len};\n    }\n\
    };\n\n} // namespace Monoid\n#line 2 \"random/Random.hpp\"\n\n#line 4 \"random/Random.hpp\"\
    \n\ntemplate<class Engine> class Random {\n  protected:\n    Engine rnd;\n  public:\n\
    \    using result_type = typename Engine::result_type;\n    Random() : Random(std::random_device{}())\
    \ {}\n    Random(result_type seed) : rnd(seed) {}\n    result_type operator()()\
    \ {\n        return rnd();\n    }\n    template<class IntType = ll> IntType uniform(IntType\
    \ l, IntType r) {\n        static_assert(std::is_integral<IntType>::value, \"\
    template argument must be an integral type\");\n        assert(l <= r);\n    \
    \    return std::uniform_int_distribution<IntType>{l, r}(rnd);\n    }\n    template<class\
    \ RealType = double> RealType uniform_real(RealType l, RealType r) {\n       \
    \ static_assert(std::is_floating_point<RealType>::value, \"template argument must\
    \ be an floating point type\");\n        assert(l <= r);\n        return std::uniform_real_distribution<RealType>{l,\
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
    \ T = ll> std::vector<T> choice_shuffle(int n, T l, T r, bool sorted = true) {\n\
    \        assert(l <= r);\n        assert(T(n) <= (r - l + 1));\n        std::vector<T>\
    \ res(r - l + 1);\n        rep (i, l, r + 1) res[i - l] = i;\n        shuffle(all(res));\n\
    \        res.erase(res.begin() + n, res.end());\n        if (sorted) sort(all(res));\n\
    \        return res;\n    }\n};\n\nusing Random32 = Random<std::mt19937>;    \
    \  Random32 rand32;\nusing Random64 = Random<std::mt19937_64>;   Random64 rand64;\n\
    \n/**\n * @brief Random\n * @docs docs/Random.md\n */\n#line 6 \"data-struct/other/SkipList.hpp\"\
    \n\nusing M = Monoid::Max<ll>;\nusing Rand = Random32;\n\nclass SkipList {\n \
    \ protected:\n    using T = typename M::value_type;\n    static inline int get_level(Rand&\
    \ rnd) {\n        int level = 1;\n        while (rnd() & 1) ++level;\n       \
    \ return level;\n    }\n    struct node;\n    using node_ptr = node*;\n    struct\
    \ next_node {\n        node_ptr node;\n        int dist;\n        T sm;\n    };\n\
    \    struct node {\n        std::vector<next_node> nxt, prv;\n        int level()\
    \ const {\n            assert(nxt.size() == prv.size());\n            return nxt.size();\n\
    \        }\n        node(Rand& rnd) : node(get_level(rnd)) {}\n        node(int\
    \ lev) : nxt(lev, {nullptr, 0, M::id()}), prv(lev, {nullptr, 0, M::id()}) {}\n\
    \    };\n    using nodepair = std::pair<node_ptr, node_ptr>;\n    Rand rnd;\n\
    \    nodepair sl;\n    static inline void calc(const node_ptr& l, int k) {\n \
    \       l->nxt[k].sm = l->nxt[k - 1].sm;\n        for (node_ptr ptr = l->nxt[k\
    \ - 1].node; ptr != l->nxt[k].node; ptr = ptr->nxt[k - 1].node) {\n          \
    \  l->nxt[k].sm = M::op(l->nxt[k].sm, ptr->nxt[k - 1].sm);\n        }\n      \
    \  l->nxt[k].node->prv[k].sm = l->nxt[k].sm;\n    }\n    static void match_level(nodepair&\
    \ lhs, nodepair& rhs) {\n        const int llv = lhs.first->level(), rlv = rhs.second->level();\n\
    \        if (llv < rlv) {\n            lhs.first->prv.resize(rlv, next_node(lhs.first->prv.back()));\n\
    \            lhs.first->nxt.resize(rlv, next_node(lhs.first->nxt.back()));\n \
    \           lhs.second->prv.resize(rlv, next_node(lhs.second->prv.back()));\n\
    \            lhs.second->nxt.resize(rlv, next_node(lhs.second->nxt.back()));\n\
    \        }\n        else if (llv > rlv) {\n            rhs.first->prv.resize(llv,\
    \ next_node(rhs.first->prv.back()));\n            rhs.first->nxt.resize(llv, next_node(rhs.first->nxt.back()));\n\
    \            rhs.second->prv.resize(llv, next_node(rhs.second->prv.back()));\n\
    \            rhs.second->nxt.resize(llv, next_node(rhs.second->nxt.back()));\n\
    \        }\n    }\n    static nodepair merge(nodepair&& lhs, nodepair&& rhs, Rand&\
    \ rnd) {\n        assert(lhs.first != rhs.first);\n        assert(lhs.second !=\
    \ rhs.second);\n        if (lhs.first == lhs.second) {\n            delete lhs.first;\n\
    \            return std::move(rhs);\n        }\n        if (rhs.first == rhs.second)\
    \ {\n            delete rhs.first;\n            return std::move(lhs);\n     \
    \   }\n        match_level(lhs, rhs);\n        rep (i, lhs.first->level()) {\n\
    \            auto&& l = lhs.second->prv[i];\n            auto&& r = rhs.first;\n\
    \            l.node->nxt[i].node = r;\n            r->prv[i] = std::move(l);\n\
    \        }\n        delete lhs.second;\n        const int lev = get_level(rnd);\n\
    \        while (lev < rhs.first->level()) {\n            const int h = rhs.first->level();\n\
    \            const auto& l = std::move(rhs.first->prv.back()); rhs.first->prv.pop_back();\n\
    \            const auto& r = std::move(rhs.first->nxt.back()); rhs.first->nxt.pop_back();\n\
    \            T sm = M::op(l.sm, r.sm);\n            l.node->nxt[h - 1] = {r.node,\
    \ l.dist + r.dist, sm};\n            r.node->prv[h - 1] = {l.node, l.dist + r.dist,\
    \ std::move(sm)};\n        }\n        if (lev >= rhs.first->level()) {\n     \
    \       lhs.first->prv.resize(lev + 1, next_node(lhs.first->prv.back()));\n  \
    \          lhs.first->nxt.resize(lev, next_node(lhs.first->nxt.back()));\n   \
    \         rhs.first->prv.resize(lev, next_node(rhs.first->prv.back()));\n    \
    \        rhs.first->nxt.resize(lev, next_node(rhs.first->nxt.back()));\n     \
    \       rhs.second->prv.resize(lev, next_node(rhs.second->prv.back()));\n    \
    \        rhs.second->nxt.resize(lev + 1, next_node(rhs.second->nxt.back()));\n\
    \            const auto& l = rhs.first->prv.back();\n            const auto& r\
    \ = rhs.first->nxt.back();\n            T sm = M::op(l.sm, r.sm);\n          \
    \  lhs.first->nxt.emplace_back(rhs.second, l.dist + r.dist, sm);\n           \
    \ rhs.second->prv.emplace_back(lhs.first, l.dist + r.dist, std::move(sm));\n \
    \       }\n        return {lhs.first, rhs.second};\n    }\n    static std::pair<nodepair,\
    \ nodepair> split(nodepair&& sl, int k) {\n        const int n = sl.first->nxt.back().dist;\n\
    \        assert(0 <= k && k <= n);\n        if (n == 0) {\n            node_ptr\
    \ np = new node(sl.first->level());\n            return {std::move(sl), {np, np}};\n\
    \        }\n        if (k == 0) {\n            node_ptr np = new node(sl.first->level());\n\
    \            return {{np, np}, std::move(sl)};\n        }\n        if (k == n)\
    \ {\n            node_ptr np = new node(sl.first->level());\n            return\
    \ {std::move(sl), {np, np}};\n        }\n        const int h = sl.first->level();\n\
    \        std::vector<node_ptr> lft(h);\n        std::vector<int> idx(h);\n   \
    \     lft[h - 1] = sl.first;\n        idx[h - 1] = 0;\n        rrep (i, h - 1)\
    \ {\n            lft[i] = lft[i + 1];\n            idx[i] = idx[i + 1];\n    \
    \        while (idx[i] + lft[i]->nxt[i].dist < k) {\n                idx[i] +=\
    \ lft[i]->nxt[i].dist;\n                lft[i] = lft[i]->nxt[i].node;\n      \
    \      }\n        }\n        node_ptr npl = new node(h);\n        node_ptr npr\
    \ = lft[0]->nxt[0].node;\n        rep (i, h) {\n            const auto& l = lft[i];\n\
    \            const auto& r = lft[i]->nxt[i].node;\n            const int d = l->nxt[i].dist;\n\
    \            l->nxt[i] = {npl, k - idx[i], l->nxt[i].sm};\n            npl->prv[i]\
    \ = {l, k - idx[i], l->nxt[i].sm};\n            if (i != 0) calc(l, i);\n    \
    \        if (npr == r) {\n                r->prv[i] = {nullptr, 0, M::id()};\n\
    \            }\n            else {\n                npr->nxt.emplace_back(r, d\
    \ + idx[i] - k, M::id());\n                r->prv[i] = {npr, d + idx[i] - k, M::id()};\n\
    \                calc(npr, i);\n            }\n        }\n        return {{sl.first,\
    \ npl}, {npr, sl.second}};\n    }\n    SkipList(const nodepair& sl, const Rand&\
    \ rnd) : sl(sl), rnd(rnd) {}\n  public:\n    SkipList() : SkipList(Rand()) {}\n\
    \    SkipList(const Rand &rnd) : rnd(rnd) {\n        sl.first = sl.second = new\
    \ node(1);\n    }\n    SkipList(const SkipList&) = delete;\n    SkipList(SkipList&&)\
    \ = default;\n    SkipList& operator=(const SkipList&) = delete;\n    SkipList&\
    \ operator=(SkipList&&) = default;\n    int size() const { return sl.first->nxt[0].dist;\
    \ }\n    bool empty() const { return size() == 0; }\n    friend SkipList merge(SkipList\
    \ lhs, SkipList rhs) {\n        return {merge(std::move(lhs.sl), std::move(rhs.sl),\
    \ lhs.rnd), lhs.rnd};\n    }\n    friend SkipList merge(SkipList&& lhs, SkipList&&\
    \ rhs) {\n        return {merge(std::move(lhs.sl), std::move(rhs.sl), lhs.rnd),\
    \ lhs.rnd};\n    }\n    friend SkipList merge(SkipList lhs, SkipList&& rhs) {\n\
    \        return {merge(std::move(lhs.sl), std::move(rhs.sl), lhs.rnd), lhs.rnd};\n\
    \    }\n    friend SkipList merge(SkipList&& lhs, SkipList rhs) {\n        return\
    \ {merge(std::move(lhs.sl), std::move(rhs.sl), lhs.rnd), lhs.rnd};\n    }\n};\n\
    \n/**\n * @brief SkipList\n * @docs docs/SkipList.md\n */\n"
  code: "#pragma once\n\n#include \"../../other/template.hpp\"\n#include \"../../other/monoid.hpp\"\
    \n#include \"../../random/Random.hpp\"\n\nusing M = Monoid::Max<ll>;\nusing Rand\
    \ = Random32;\n\nclass SkipList {\n  protected:\n    using T = typename M::value_type;\n\
    \    static inline int get_level(Rand& rnd) {\n        int level = 1;\n      \
    \  while (rnd() & 1) ++level;\n        return level;\n    }\n    struct node;\n\
    \    using node_ptr = node*;\n    struct next_node {\n        node_ptr node;\n\
    \        int dist;\n        T sm;\n    };\n    struct node {\n        std::vector<next_node>\
    \ nxt, prv;\n        int level() const {\n            assert(nxt.size() == prv.size());\n\
    \            return nxt.size();\n        }\n        node(Rand& rnd) : node(get_level(rnd))\
    \ {}\n        node(int lev) : nxt(lev, {nullptr, 0, M::id()}), prv(lev, {nullptr,\
    \ 0, M::id()}) {}\n    };\n    using nodepair = std::pair<node_ptr, node_ptr>;\n\
    \    Rand rnd;\n    nodepair sl;\n    static inline void calc(const node_ptr&\
    \ l, int k) {\n        l->nxt[k].sm = l->nxt[k - 1].sm;\n        for (node_ptr\
    \ ptr = l->nxt[k - 1].node; ptr != l->nxt[k].node; ptr = ptr->nxt[k - 1].node)\
    \ {\n            l->nxt[k].sm = M::op(l->nxt[k].sm, ptr->nxt[k - 1].sm);\n   \
    \     }\n        l->nxt[k].node->prv[k].sm = l->nxt[k].sm;\n    }\n    static\
    \ void match_level(nodepair& lhs, nodepair& rhs) {\n        const int llv = lhs.first->level(),\
    \ rlv = rhs.second->level();\n        if (llv < rlv) {\n            lhs.first->prv.resize(rlv,\
    \ next_node(lhs.first->prv.back()));\n            lhs.first->nxt.resize(rlv, next_node(lhs.first->nxt.back()));\n\
    \            lhs.second->prv.resize(rlv, next_node(lhs.second->prv.back()));\n\
    \            lhs.second->nxt.resize(rlv, next_node(lhs.second->nxt.back()));\n\
    \        }\n        else if (llv > rlv) {\n            rhs.first->prv.resize(llv,\
    \ next_node(rhs.first->prv.back()));\n            rhs.first->nxt.resize(llv, next_node(rhs.first->nxt.back()));\n\
    \            rhs.second->prv.resize(llv, next_node(rhs.second->prv.back()));\n\
    \            rhs.second->nxt.resize(llv, next_node(rhs.second->nxt.back()));\n\
    \        }\n    }\n    static nodepair merge(nodepair&& lhs, nodepair&& rhs, Rand&\
    \ rnd) {\n        assert(lhs.first != rhs.first);\n        assert(lhs.second !=\
    \ rhs.second);\n        if (lhs.first == lhs.second) {\n            delete lhs.first;\n\
    \            return std::move(rhs);\n        }\n        if (rhs.first == rhs.second)\
    \ {\n            delete rhs.first;\n            return std::move(lhs);\n     \
    \   }\n        match_level(lhs, rhs);\n        rep (i, lhs.first->level()) {\n\
    \            auto&& l = lhs.second->prv[i];\n            auto&& r = rhs.first;\n\
    \            l.node->nxt[i].node = r;\n            r->prv[i] = std::move(l);\n\
    \        }\n        delete lhs.second;\n        const int lev = get_level(rnd);\n\
    \        while (lev < rhs.first->level()) {\n            const int h = rhs.first->level();\n\
    \            const auto& l = std::move(rhs.first->prv.back()); rhs.first->prv.pop_back();\n\
    \            const auto& r = std::move(rhs.first->nxt.back()); rhs.first->nxt.pop_back();\n\
    \            T sm = M::op(l.sm, r.sm);\n            l.node->nxt[h - 1] = {r.node,\
    \ l.dist + r.dist, sm};\n            r.node->prv[h - 1] = {l.node, l.dist + r.dist,\
    \ std::move(sm)};\n        }\n        if (lev >= rhs.first->level()) {\n     \
    \       lhs.first->prv.resize(lev + 1, next_node(lhs.first->prv.back()));\n  \
    \          lhs.first->nxt.resize(lev, next_node(lhs.first->nxt.back()));\n   \
    \         rhs.first->prv.resize(lev, next_node(rhs.first->prv.back()));\n    \
    \        rhs.first->nxt.resize(lev, next_node(rhs.first->nxt.back()));\n     \
    \       rhs.second->prv.resize(lev, next_node(rhs.second->prv.back()));\n    \
    \        rhs.second->nxt.resize(lev + 1, next_node(rhs.second->nxt.back()));\n\
    \            const auto& l = rhs.first->prv.back();\n            const auto& r\
    \ = rhs.first->nxt.back();\n            T sm = M::op(l.sm, r.sm);\n          \
    \  lhs.first->nxt.emplace_back(rhs.second, l.dist + r.dist, sm);\n           \
    \ rhs.second->prv.emplace_back(lhs.first, l.dist + r.dist, std::move(sm));\n \
    \       }\n        return {lhs.first, rhs.second};\n    }\n    static std::pair<nodepair,\
    \ nodepair> split(nodepair&& sl, int k) {\n        const int n = sl.first->nxt.back().dist;\n\
    \        assert(0 <= k && k <= n);\n        if (n == 0) {\n            node_ptr\
    \ np = new node(sl.first->level());\n            return {std::move(sl), {np, np}};\n\
    \        }\n        if (k == 0) {\n            node_ptr np = new node(sl.first->level());\n\
    \            return {{np, np}, std::move(sl)};\n        }\n        if (k == n)\
    \ {\n            node_ptr np = new node(sl.first->level());\n            return\
    \ {std::move(sl), {np, np}};\n        }\n        const int h = sl.first->level();\n\
    \        std::vector<node_ptr> lft(h);\n        std::vector<int> idx(h);\n   \
    \     lft[h - 1] = sl.first;\n        idx[h - 1] = 0;\n        rrep (i, h - 1)\
    \ {\n            lft[i] = lft[i + 1];\n            idx[i] = idx[i + 1];\n    \
    \        while (idx[i] + lft[i]->nxt[i].dist < k) {\n                idx[i] +=\
    \ lft[i]->nxt[i].dist;\n                lft[i] = lft[i]->nxt[i].node;\n      \
    \      }\n        }\n        node_ptr npl = new node(h);\n        node_ptr npr\
    \ = lft[0]->nxt[0].node;\n        rep (i, h) {\n            const auto& l = lft[i];\n\
    \            const auto& r = lft[i]->nxt[i].node;\n            const int d = l->nxt[i].dist;\n\
    \            l->nxt[i] = {npl, k - idx[i], l->nxt[i].sm};\n            npl->prv[i]\
    \ = {l, k - idx[i], l->nxt[i].sm};\n            if (i != 0) calc(l, i);\n    \
    \        if (npr == r) {\n                r->prv[i] = {nullptr, 0, M::id()};\n\
    \            }\n            else {\n                npr->nxt.emplace_back(r, d\
    \ + idx[i] - k, M::id());\n                r->prv[i] = {npr, d + idx[i] - k, M::id()};\n\
    \                calc(npr, i);\n            }\n        }\n        return {{sl.first,\
    \ npl}, {npr, sl.second}};\n    }\n    SkipList(const nodepair& sl, const Rand&\
    \ rnd) : sl(sl), rnd(rnd) {}\n  public:\n    SkipList() : SkipList(Rand()) {}\n\
    \    SkipList(const Rand &rnd) : rnd(rnd) {\n        sl.first = sl.second = new\
    \ node(1);\n    }\n    SkipList(const SkipList&) = delete;\n    SkipList(SkipList&&)\
    \ = default;\n    SkipList& operator=(const SkipList&) = delete;\n    SkipList&\
    \ operator=(SkipList&&) = default;\n    int size() const { return sl.first->nxt[0].dist;\
    \ }\n    bool empty() const { return size() == 0; }\n    friend SkipList merge(SkipList\
    \ lhs, SkipList rhs) {\n        return {merge(std::move(lhs.sl), std::move(rhs.sl),\
    \ lhs.rnd), lhs.rnd};\n    }\n    friend SkipList merge(SkipList&& lhs, SkipList&&\
    \ rhs) {\n        return {merge(std::move(lhs.sl), std::move(rhs.sl), lhs.rnd),\
    \ lhs.rnd};\n    }\n    friend SkipList merge(SkipList lhs, SkipList&& rhs) {\n\
    \        return {merge(std::move(lhs.sl), std::move(rhs.sl), lhs.rnd), lhs.rnd};\n\
    \    }\n    friend SkipList merge(SkipList&& lhs, SkipList rhs) {\n        return\
    \ {merge(std::move(lhs.sl), std::move(rhs.sl), lhs.rnd), lhs.rnd};\n    }\n};\n\
    \n/**\n * @brief SkipList\n * @docs docs/SkipList.md\n */\n"
  dependsOn:
  - other/template.hpp
  - other/monoid.hpp
  - random/Random.hpp
  isVerificationFile: false
  path: data-struct/other/SkipList.hpp
  requiredBy: []
  timestamp: '2022-07-10 18:39:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-struct/other/SkipList.hpp
layout: document
redirect_from:
- /library/data-struct/other/SkipList.hpp
- /library/data-struct/other/SkipList.hpp.html
title: SkipList
---
