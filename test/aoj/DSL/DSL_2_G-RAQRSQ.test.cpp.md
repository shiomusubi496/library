---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-struct/segment/LazySegmentTree.hpp
    title: "LazySegmentTree(\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_G
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_G
  bundledCode: "#line 1 \"test/aoj/DSL/DSL_2_G-RAQRSQ.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_G\"\n#line 2 \"other/template.hpp\"\
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
    \n#define all(v) (v).begin(), (v).end()\n\n#if __cplusplus >= 201402L\n#define\
    \ CONSTEXPR constexpr\n#else\n#define CONSTEXPR\n#endif\n\nusing ll = long long;\n\
    using ull = unsigned long long;\nusing ld = long double;\nusing PLL = std::pair<ll,\
    \ ll>;\ntemplate<class T> using prique = std::priority_queue<T, std::vector<T>,\
    \ std::greater<T>>;\n\ntemplate<class T> class infinity {\n  public:\n    static\
    \ constexpr T value = std::numeric_limits<T>::max() / 2;\n    static constexpr\
    \ T mvalue = std::numeric_limits<T>::min() / 2;\n    static constexpr T max =\
    \ std::numeric_limits<T>::max();\n    static constexpr T min = std::numeric_limits<T>::min();\n\
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
    \ Tails> struct multi_dim_vector {\n    using type = std::vector<typename multi_dim_vector<Tails...>::type>;\n\
    };\ntemplate<class T> struct multi_dim_vector<T> {\n    using type = T;\n};\n\n\
    template<class T, class Arg> constexpr std::vector<T> make_vec(int n, Arg&& arg)\
    \ {\n    return std::vector<T>(n, arg);\n}\ntemplate<class T, class... Args>\n\
    constexpr typename multi_dim_vector<Args..., T>::type make_vec(int n, Args&&...\
    \ args) {\n    return typename multi_dim_vector<Args..., T>::type (n, make_vec<T>(std::forward<Args>(args)...));\n\
    }\n\ninline CONSTEXPR int popcnt(ull x) {\n#if __cplusplus >= 202002L\n    return\
    \ std::popcount(x);\n#endif\n    x = (x & 0x5555555555555555) + ((x >> 1 ) & 0x5555555555555555);\n\
    \    x = (x & 0x3333333333333333) + ((x >> 2 ) & 0x3333333333333333);\n    x =\
    \ (x & 0x0f0f0f0f0f0f0f0f) + ((x >> 4 ) & 0x0f0f0f0f0f0f0f0f);\n    x = (x & 0x00ff00ff00ff00ff)\
    \ + ((x >> 8 ) & 0x00ff00ff00ff00ff);\n    x = (x & 0x0000ffff0000ffff) + ((x\
    \ >> 16) & 0x0000ffff0000ffff);\n    return (x & 0x00000000ffffffff) + ((x >>\
    \ 32) & 0x00000000ffffffff);\n}\n\ntemplate<class T> class presser : public std::vector<T>\
    \ {\n  private:\n    using Base = std::vector<T>;\n  public:\n    using Base::Base;\n\
    \    presser(const std::vector<T>& vec) : Base(vec) {}\n    void push(const std::vector<T>&\
    \ vec) {\n        int n = this->size();\n        this->resize(n + vec.size());\n\
    \        std::copy(all(vec), this->begin() + n);\n    }\n    int build() {\n \
    \       std::sort(this->begin(), this->end());\n        this->erase(std::unique(this->begin(),\
    \ this->end()), this->end());\n        return this->size();\n    }\n    int get_index(const\
    \ T& val) const {\n        return static_cast<int>(std::lower_bound(this->begin(),\
    \ this->end(), val) - this->begin());\n    }\n    std::vector<int> pressed(const\
    \ std::vector<T>& vec) const {\n        std::vector<int> res(vec.size());\n  \
    \      rep (i, vec.size()) res[i] = this->get_index(vec[i]);\n        return res;\n\
    \    }\n    void press(std::vector<T>& vec) const {\n        static_assert(std::is_integral<T>::value,\
    \ \"cannot convert from int type\");\n        rep (i, vec.size()) vec[i] = this->get_index(vec[i]);\n\
    \    }\n};\n#line 2 \"data-struct/segment/LazySegmentTree.hpp\"\n\n#line 2 \"\
    other/bitop.hpp\"\n\n#line 4 \"other/bitop.hpp\"\n\nnamespace bitop {\n\n#define\
    \ KTH_BIT(b, k) (((b) >> (k)) & 1)\n#define POW2(k) (1ull << (k))\n\n    inline\
    \ ull next_combination(int n, ull x) {\n        if (n == 0) return 1;\n      \
    \  ull a = x & -x;\n        ull b = x + a;\n        return (x & ~b) / a >> 1 |\
    \ b;\n    }\n\n#define rep_comb(i, n, k) for (ull i = (1ull << (k)) - 1; i < (1ull\
    \ << (n)); i = bitop::next_combination((n), i))\n\n    inline CONSTEXPR int msb(ull\
    \ x) {\n        int res = x ? 0 : -1;\n        if (x & 0xFFFFFFFF00000000) x &=\
    \ 0xFFFFFFFF00000000, res += 32;\n        if (x & 0xFFFF0000FFFF0000) x &= 0xFFFF0000FFFF0000,\
    \ res += 16;\n        if (x & 0xFF00FF00FF00FF00) x &= 0xFF00FF00FF00FF00, res\
    \ +=  8;\n        if (x & 0xF0F0F0F0F0F0F0F0) x &= 0xF0F0F0F0F0F0F0F0, res +=\
    \  4;\n        if (x & 0xCCCCCCCCCCCCCCCC) x &= 0xCCCCCCCCCCCCCCCC, res +=  2;\n\
    \        return res + ((x & 0xAAAAAAAAAAAAAAAA) ? 1 : 0);\n    }\n\n    inline\
    \ CONSTEXPR int ceil_log2(ull x) {\n        return x ? msb(x - 1) + 1 : 0;\n \
    \   }\n}\n#line 2 \"other/monoid.hpp\"\n\n#line 4 \"other/monoid.hpp\"\n\nnamespace\
    \ Monoid {\n\ntemplate<class T> struct Sum {\n    using value_type = T;\n    static\
    \ constexpr T op(T a, T b) { return a + b; }\n    static constexpr T id() { return\
    \ T{0}; }\n    static constexpr T inv(T a, T b) { return a - b; }\n    static\
    \ constexpr T get_inv(T a) { return -a; }\n};\n\ntemplate<class T, T max_value\
    \ = infinity<T>::max> struct Min {\n    using value_type = T;\n    static constexpr\
    \ T op(T a, T b) { return a > b ? b : a; }\n    static constexpr T id() { return\
    \ max_value; }\n};\n\ntemplate<class T, T min_value = infinity<T>::min> struct\
    \ Max {\n    using value_type = T;\n    static constexpr T op(T a, T b) { return\
    \ a < b ? b : a;}\n    static constexpr T id() { return min_value; }\n};\n\ntemplate<class\
    \ T> struct Assign {\n    using value_type = T;\n    static constexpr T op(T a,\
    \ T b) { return b; }\n};\n\n\ntemplate<class T, T max_value = infinity<T>::max>\
    \ struct AssignMin {\n    using M = Min<T, max_value>;\n    using E = Assign<T>;\n\
    \    static constexpr T op(T a, T b) { return a; }\n};\n\ntemplate<class T, T\
    \ min_value = infinity<T>::min> struct AssignMax {\n    using M = Max<T, min_value>;\n\
    \    using E = Assign<T>;\n    static constexpr T op(T a, T b) { return a; }\n\
    };\n\ntemplate<class T> struct AssignSum {\n    using M = Sum<T>;\n    using E\
    \ = Assign<T>;\n    static constexpr T op(T a, T b) { return a; }\n    static\
    \ constexpr T mul(T a, int b) { return a * b; }\n};\n\ntemplate<class T, T max_value\
    \ = infinity<T>::max> struct AddMin {\n    using M = Min<T, max_value>;\n    using\
    \ E = Sum<T>;\n    static constexpr T op(T a, T b) { return b + a; }\n};\n\ntemplate<class\
    \ T, T min_value = infinity<T>::min> struct AddMax {\n    using M = Max<T, min_value>;\n\
    \    using E = Sum<T>;\n    static constexpr T op(T a, T b) { return b + a; }\n\
    };\n\ntemplate<class T> struct AddSum {\n    using M = Sum<T>;\n    using E =\
    \ Sum<T>;\n    static constexpr T op(T a, T b) { return b + a; }\n    static constexpr\
    \ T mul(T a, int b) { return a * b; }\n};\n\ntemplate<class T, T max_value = infinity<T>::max>\
    \ struct ChminMin {\n    using M = Min<T, max_value>;\n    using E = Min<T>;\n\
    \    static constexpr T op(T a, T b) { return std::min(b, a); }\n};\n\ntemplate<class\
    \ T, T min_value = infinity<T>::min> struct ChminMax {\n    using M = Max<T, min_value>;\n\
    \    using E = Min<T>;\n    static constexpr T op(T a, T b) { return std::min(b,\
    \ a); }\n};\n\ntemplate<class T, T max_value = infinity<T>::max> struct ChmaxMin\
    \ {\n    using M = Min<T, max_value>;\n    using E = Max<T>;\n    static constexpr\
    \ T op(T a, T b) { return std::max(b, a); }\n};\n\ntemplate<class T, T min_value\
    \ = infinity<T>::min> struct ChmaxMax {\n    using M = Max<T, min_value>;\n  \
    \  using E = Max<T>;\n    static constexpr T op(T a, T b) { return std::max(b,\
    \ a); }\n};\n\n\ntemplate<class M_> struct AttachEffector {\n    using M = M_;\n\
    \    using E = M_;\n    using T = typename M_::value_type;\n    static T op(const\
    \ T& a, const T& b) { return M_::op(b, a); }\n};\n\ntemplate<class E_> struct\
    \ AttachMonoid {\n    using M = E_;\n    using E = E_;\n    using T = typename\
    \ E_::value_type;\n    static T op(const T& a, const T& b) { return E_::op(b,\
    \ a); }\n};\n\n\ntemplate<class M, class = void> struct has_id : public std::false_type\
    \ {};\ntemplate<class M> struct has_id<M, typename std::conditional<false, decltype(M::id),\
    \ void>::type> : public std::true_type {};\n\ntemplate<class M, class = void>\
    \ struct has_inv : public std::false_type {};\ntemplate<class M> struct has_inv<M,\
    \ typename std::conditional<false, decltype(M::inv), void>::type> : public std::true_type\
    \ {};\n\ntemplate<class M, class = void> struct has_get_inv : public std::false_type\
    \ {};\ntemplate<class M> struct has_get_inv<M, typename std::conditional<false,\
    \ decltype(M::get_inv), void>::type> : public std::true_type {};\n\n} // namespace\
    \ Monoid\n#line 6 \"data-struct/segment/LazySegmentTree.hpp\"\n\ntemplate<class\
    \ A> class LazySegmentTree {\n  protected:\n    using M = typename A::M;\n   \
    \ using E = typename A::E;\n    using T = typename M::value_type;\n    using U\
    \ = typename E::value_type;\n    int h, n, ori;\n    std::vector<T> data;\n  \
    \  std::vector<U> lazy;\n    std::vector<bool> lazyflag;\n    void all_apply(int\
    \ k, const U& x) {\n        data[k] = A::op(x, data[k]);\n        if (k < n) {\n\
    \            if (lazyflag[k]) {\n                lazy[k] = E::op(lazy[k], x);\n\
    \            }\n            else {\n                lazy[k] = x;\n           \
    \     lazyflag[k] = true;\n            }\n        }\n    }\n    void eval(int\
    \ k) {\n        if (lazyflag[k]) {\n            all_apply(k << 1, lazy[k]);\n\
    \            all_apply(k << 1 ^ 1, lazy[k]);\n            lazyflag[k] = false;\n\
    \        }\n    }\n    void dataup(int k) {\n        data[k] = M::op(data[k <<\
    \ 1], data[k << 1 ^ 1]);\n    }\n  public:\n    LazySegmentTree() : LazySegmentTree(0)\
    \ {}\n    LazySegmentTree(int n_) : LazySegmentTree(std::vector<T>(n_, M::id()))\
    \ {}\n    LazySegmentTree(const std::vector<T>& v) { init(v); }\n    void init(const\
    \ std::vector<T>& v) {\n        ori = v.size();\n        h = bitop::ceil_log2(ori);\n\
    \        n = 1 << h;\n        data.assign(n << 1, M::id());\n        rep (i, ori)\
    \ data[n + i] = v[i];\n        rrep (i, n, 1) dataup(i);\n        lazy.resize(n);\
    \ lazyflag.assign(n, false);\n    }\n    T prod(int l, int r) {\n        assert(0\
    \ <= l && l <= r && r <= ori);\n        if (l == r) return M::id();\n\n      \
    \  l += n; r += n;\n        rreps (i, h) {\n            bool seen = false;\n \
    \           if (((l >> i) << i) != l) eval(l >> i), seen = true;\n           \
    \ if (((r >> i) << i) != r) eval((r - 1) >> i), seen = true;\n            if (!seen)\
    \ break;\n        }\n\n        T lsm = M::id(), rsm = M::id();\n        while\
    \ (l != r) {\n            if (l & 1) lsm = M::op(lsm, data[l++]);\n          \
    \  if (r & 1) rsm = M::op(data[--r], rsm);\n            l >>= 1; r >>= 1;\n  \
    \      }\n        return M::op(lsm, rsm);\n    }\n    T get(int k) {\n       \
    \ assert(0 <= k && k < ori);\n        \n        k += n;\n        rreps (i, h)\
    \ eval(k >> i);\n        return data[k];\n    }\n    T all_prod() const { return\
    \ data[1]; }\n    template<class Upd> void update(int k, const Upd& upd) {\n \
    \       assert(0 <= k && k < ori);\n\n        k += n;\n        rreps (i, h) eval(k\
    \ >> i);\n        data[k] = upd(data[k]);\n        reps (i, h) dataup(k >> i);\n\
    \    }\n    void set(int k, T x) {\n        update(k, [&](const T&) -> T { return\
    \ x; });\n    }\n    void apply(int k, U x) {\n        update(k, [&](const T&\
    \ a) -> T { return A::op(x, a); });\n    }\n    void apply(int l, int r, U x)\
    \ {\n        assert(0 <= l && l <= r && r <= ori);\n        if (l == r) return;\n\
    \n        l += n; r += n;\n        int lst = h + 1;\n        rreps (i, h) {\n\
    \            if (((l >> i) << i) != l) eval(l >> i), lst = i;\n            if\
    \ (((r >> i) << i) != r) eval((r - 1) >> i), lst = i;\n            if (lst !=\
    \ i) break;\n        }\n\n        for (int l2 = l, r2 = r; l2 != r2; l2 >>= 1,\
    \ r2 >>= 1) {\n            if (l2 & 1) all_apply(l2++, x);\n            if (r2\
    \ & 1) all_apply(--r2, x);\n        }\n        \n        rep (i, lst, h + 1) {\n\
    \            if (((l >> i) << i) != l) dataup(l >> i);\n            if (((r >>\
    \ i) << i) != r) dataup((r - 1) >> i);\n        }\n    }\n    template<class C>\
    \ int max_right(int l, const C& cond) {\n        assert(0 <= l && l <= ori);\n\
    \        assert(cond(M::id()));\n        if (l == ori) return ori;\n\n       \
    \ l += n;\n        rreps (i, h) {\n            if (((l >> i) << i) != l) eval(l\
    \ >> i);\n            else break;\n        }\n\n        T sm = M::id();\n    \
    \    do {\n            while ((l & 1) == 0) l >>= 1;\n            if (!cond(M::op(sm,\
    \ data[l]))) {\n                while (l < n) {\n                    eval(l);\n\
    \                    l <<= 1;\n                    if (cond(M::op(sm, data[l])))\
    \ sm = M::op(sm, data[l++]);\n                }\n                return l - n;\n\
    \            }\n            sm = M::op(sm, data[l++]);\n        } while ((l &\
    \ -l) != l);\n        return ori;\n    }\n    template<class C> int min_left(int\
    \ r, const C& cond) {\n        assert(0 <= r && r <= ori);\n        assert(cond(M::id()));\n\
    \        if (r == 0) return 0;\n\n        r += n;\n        rreps (i, n) {\n  \
    \          if (((r >> i) << i) != r) eval((r - 1) >> i);\n            else break;\n\
    \        }\n\n        T sm = M::id();\n        do {\n            --r;\n      \
    \      while ((r & 1) && r > 1) r >>= 1;\n            if (!cond(M::op(data[r],\
    \ sm))) {\n                while (r < n) {\n                    eval(r);\n   \
    \                 r = r << 1 ^ 1;\n                    if (cond(M::op(data[r],\
    \ sm))) sm = M::op(data[r--], sm);\n                }\n                return\
    \ r + 1 - n;\n            }\n            sm = M::op(data[r], sm);\n        } while\
    \ ((r & -r) != r);\n        return 0;\n    }\n};\n\ntemplate<class A> class MultiLazySegmentTree\
    \ {\n  protected:\n    using M_ = typename A::M;\n    using E_ = typename A::E;\n\
    \    using T_ = typename M_::value_type;\n    using U_ = typename E_::value_type;\n\
    \    struct MultiA {\n        struct M {\n            struct value_type {\n  \
    \              T_ val;\n                int len;\n                value_type()\
    \ = default;\n                value_type(T_ v, int l) : val(v), len(l) {}\n  \
    \              friend std::ostream& operator<<(std::ostream& ost, const value_type&\
    \ e) { return ost << e.val << '*' << e.len; }\n            };\n            static\
    \ value_type op(const value_type& a, const value_type& b) { return {M_::op(a.val,\
    \ b.val), a.len + b.len}; }\n            static value_type id() { return {M_::id(),\
    \ 0}; }\n        };\n        using E = E_;\n        using T = typename M::value_type;\n\
    \        using U = typename E::value_type;\n        static T op(const U& a, const\
    \ T& b) { return {A::op(A::mul(a, b.len), b.val), b.len}; }\n    };\n    using\
    \ elm = typename MultiA::M::value_type;\n    static std::vector<elm> get_elm_vec(const\
    \ std::vector<T_>& v) {\n        const int n = v.size();\n        std::vector<elm>\
    \ res(n);\n        rep (i, n) res[i] = elm{v[i], 1};\n        return res;\n  \
    \  }\n    LazySegmentTree<MultiA> seg;\n  public:\n    MultiLazySegmentTree()\
    \ : MultiLazySegmentTree(0) {}\n    MultiLazySegmentTree(int n_) : seg(std::vector<elm>(n_,\
    \ {M_::id(), 1})) {}\n    MultiLazySegmentTree(const std::vector<T_>& v) : seg(get_elm_vec(v))\
    \ {}\n    void init(const std::vector<T_>& v) { seg.init(get_elm_vec(v)); }\n\
    \    T_ prod(int l, int r) { return seg.prod(l, r).val; }\n    T_ get(int k) {\
    \ return seg.get(k).val; }\n    T_ all_prod() const { return seg.all_prod().val;\
    \ }\n    template<class Upd> void update(int k, const Upd& upd) { seg.update(k,\
    \ [&](const elm& a) -> elm { return {upd(a.val), a.len}; }); }\n    void set(int\
    \ k, T_ x) { seg.set(k, elm{x, 1}); }\n    void apply(int k, U_ x) { seg.apply(k,\
    \ x); }\n    void apply(int l, int r, U_ x) { seg.apply(l, r, x); }\n    template<class\
    \ C> int max_right(int l, const C& cond) { return seg.max_right(l, [&](const elm&\
    \ a) -> bool { return cond(a.val); }); }\n    template<class C> int min_left(int\
    \ r, const C& cond) { return seg.min_left(r, [&](const elm& a) -> bool { return\
    \ cond(a.val); }); }\n};\n\n//verified with test/aoj/DSL/DSL_2_F-RUQRMQ.test.cpp\n\
    template<class T, T max_value = infinity<T>::max> using RangeUpdateQueryRangeMinimumQuery\
    \ = LazySegmentTree<Monoid::AssignMin<T, max_value>>;\n\ntemplate<class T, T min_value\
    \ = infinity<T>::min> using RangeUpdateQueryRangeMaximumQuery = LazySegmentTree<Monoid::AssignMax<T,\
    \ min_value>>;\n\n//verified with test/aoj/DSL/DSL_2_I-RUQRSQ.test.cpp\ntemplate<class\
    \ T> using RangeUpdateQueryRangeSumQuery = MultiLazySegmentTree<Monoid::AssignSum<T>>;\n\
    \n//verified with test/aoj/DSL/DSL_2_H-RAQRMQ.test.cpp\ntemplate<class T, T max_value\
    \ = infinity<T>::max> using RangeAddQueryRangeMinimumQuery = LazySegmentTree<Monoid::AddMin<T,\
    \ max_value>>;\n\ntemplate<class T, T min_value = infinity<T>::min> using RangeAddQueryRangeMaximumQuery\
    \ = LazySegmentTree<Monoid::AddMax<T, min_value>>;\n\n//verified with test/aoj/DSL/DSL_2_G-RAQRSQ.test.cpp\n\
    template<class T> using RangeAddQueryRangeSumQuery = MultiLazySegmentTree<Monoid::AddSum<T>>;\n\
    \ntemplate<class T, T max_value = infinity<T>::max> using RangeChminQueryRangeMinimumQuery\
    \ = LazySegmentTree<Monoid::ChminMin<T, max_value>>;\n\ntemplate<class T, T min_value\
    \ = infinity<T>::min> using RangeChminQueryRangeMaximumQuery = LazySegmentTree<Monoid::ChminMax<T,\
    \ min_value>>;\n\ntemplate<class T, T max_value = infinity<T>::max> using RangeChmaxQueryRangeMinimumQuery\
    \ = LazySegmentTree<Monoid::ChmaxMin<T, max_value>>;\n\ntemplate<class T, T min_value\
    \ = infinity<T>::min> using RangeChmaxQueryRangeMaximumQuery = LazySegmentTree<Monoid::ChmaxMax<T,\
    \ min_value>>;\n\n/**\n * @brief LazySegmentTree(\u9045\u5EF6\u30BB\u30B0\u30E1\
    \u30F3\u30C8\u6728)\n * @docs docs/LazySegmentTree.md\n */\n#line 4 \"test/aoj/DSL/DSL_2_G-RAQRSQ.test.cpp\"\
    \nusing namespace std;\nint main() {\n    int n, q; cin >> n >> q;\n    RangeAddQueryRangeSumQuery<ll>\
    \ RAQRSQ(n);\n    rep (q) {\n        int t; cin >> t;\n        if (t == 0) {\n\
    \            int l, r, x; cin >> l >> r >> x;\n            RAQRSQ.apply(l - 1,\
    \ r, x);\n        }\n        else {\n            int l, r; cin >> l >> r;\n  \
    \          cout << RAQRSQ.prod(l - 1, r) << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_G\"\n#include\
    \ \"../../../other/template.hpp\"\n#include \"../../../data-struct/segment/LazySegmentTree.hpp\"\
    \nusing namespace std;\nint main() {\n    int n, q; cin >> n >> q;\n    RangeAddQueryRangeSumQuery<ll>\
    \ RAQRSQ(n);\n    rep (q) {\n        int t; cin >> t;\n        if (t == 0) {\n\
    \            int l, r, x; cin >> l >> r >> x;\n            RAQRSQ.apply(l - 1,\
    \ r, x);\n        }\n        else {\n            int l, r; cin >> l >> r;\n  \
    \          cout << RAQRSQ.prod(l - 1, r) << endl;\n        }\n    }\n}\n"
  dependsOn:
  - other/template.hpp
  - data-struct/segment/LazySegmentTree.hpp
  - other/bitop.hpp
  - other/monoid.hpp
  isVerificationFile: true
  path: test/aoj/DSL/DSL_2_G-RAQRSQ.test.cpp
  requiredBy: []
  timestamp: '2021-12-26 19:31:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL/DSL_2_G-RAQRSQ.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL/DSL_2_G-RAQRSQ.test.cpp
- /verify/test/aoj/DSL/DSL_2_G-RAQRSQ.test.cpp.html
title: test/aoj/DSL/DSL_2_G-RAQRSQ.test.cpp
---