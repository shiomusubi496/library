---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yuki/1601-RangeSet.test.cpp
    title: test/yuki/1601-RangeSet.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/data-struct/other/RangeSet.md
    document_title: "RangeSet(\u533A\u9593\u3092std::set\u3067\u7BA1\u7406\u3059\u308B\
      \u4F8B\u306E\u3084\u3064)"
    links: []
  bundledCode: "#line 2 \"data-struct/other/RangeSet.hpp\"\n\n#line 2 \"other/template.hpp\"\
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
    \ std::end(v)\n#define rall(v) std::rbegin(v), std::rend(v)\n\n#if __cplusplus\
    \ >= 201402L\n#define CONSTEXPR constexpr\n#else\n#define CONSTEXPR\n#endif\n\n\
    #ifdef __cpp_if_constexpr\n#define IF_CONSTEXPR constexpr\n#else\n#define IF_CONSTEXPR\n\
    #endif\n\nusing ll = long long;\nusing ull = unsigned long long;\nusing ld = long\
    \ double;\nusing PLL = std::pair<ll, ll>;\ntemplate<class T>\nusing prique = std::priority_queue<T,\
    \ std::vector<T>, std::greater<T>>;\n\ntemplate<class T> class infinity {\npublic:\n\
    \    static constexpr T value = std::numeric_limits<T>::max() / 2;\n    static\
    \ constexpr T mvalue = std::numeric_limits<T>::min() / 2;\n    static constexpr\
    \ T max = std::numeric_limits<T>::max();\n    static constexpr T min = std::numeric_limits<T>::min();\n\
    };\n\n#if __cplusplus <= 201402L\ntemplate<class T> constexpr T infinity<T>::value;\n\
    template<class T> constexpr T infinity<T>::mvalue;\ntemplate<class T> constexpr\
    \ T infinity<T>::max;\ntemplate<class T> constexpr T infinity<T>::min;\n#endif\n\
    \n#if __cplusplus >= 201402L\ntemplate<class T> constexpr T INF = infinity<T>::value;\n\
    #endif\n\nconstexpr ll inf = infinity<ll>::value;\nconstexpr ld EPS = 1e-8;\n\
    constexpr ld PI = 3.1415926535897932384626;\n\ntemplate<class T, class U>\nstd::ostream&\
    \ operator<<(std::ostream& ost, const std::pair<T, U>& p) {\n    return ost <<\
    \ p.first << ' ' << p.second;\n}\ntemplate<class T, class U>\nstd::istream& operator>>(std::istream&\
    \ ist, std::pair<T, U>& p) {\n    return ist >> p.first >> p.second;\n}\n\ntemplate<class\
    \ Container, typename std::enable_if<!std::is_same<\n                        \
    \      Container, std::string>::value>::type* = nullptr>\nauto operator<<(std::ostream&\
    \ ost, const Container& cont)\n    -> decltype(cont.begin(), cont.end(), ost)\
    \ {\n    for (auto itr = cont.begin(); itr != cont.end(); ++itr) {\n        if\
    \ (itr != cont.begin()) ost << ' ';\n        ost << *itr;\n    }\n    return ost;\n\
    }\ntemplate<class Container, typename std::enable_if<!std::is_same<\n        \
    \                      Container, std::string>::value>::type* = nullptr>\nauto\
    \ operator>>(std::istream& ist, Container& cont)\n    -> decltype(cont.begin(),\
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
    \ }\n};\n#line 4 \"data-struct/other/RangeSet.hpp\"\n\nclass RangeSet {\nprivate:\n\
    \    using iterator = typename std::set<std::pair<ll, ll>>::iterator;\n    ll\
    \ sz;\n    std::set<std::pair<ll, ll>> st;\n    iterator st_emplace_hint(const\
    \ iterator& itr, ll l, ll r) {\n        sz += r - l;\n        return st.emplace_hint(itr,\
    \ l, r);\n    }\n    iterator st_erase(const iterator& itr) {\n        sz -= itr->second\
    \ - itr->first;\n        return st.erase(itr);\n    }\n\npublic:\n    RangeSet()\
    \ : sz(0) {}\n    RangeSet(const std::set<std::pair<ll, ll>>& st_) : sz(0) {\n\
    \        each_const (p : st_) insert(p.first, p.second);\n    }\n    iterator\
    \ begin() const { return st.begin(); }\n    iterator end() const { return st.end();\
    \ }\n    bool empty() const { return st.empty(); }\n    int size() const { return\
    \ st.size(); }\n    ll length() const { return sz; }\n    const std::set<std::pair<ll,\
    \ ll>>& get_data() const& { return st; }\n    std::set<std::pair<ll, ll>>& get_data()\
    \ & { return st; }\n    std::set<std::pair<ll, ll>> get_data() && { return std::move(st);\
    \ }\n    std::pair<iterator, bool> insert(ll l, ll r) {\n        assert(l <= r);\n\
    \        if (l == r) return {st.end(), false};\n        auto itr = st.lower_bound({l,\
    \ r});\n        if (itr != st.end() && itr->first == l) return {itr, false};\n\
    \        if (itr != st.begin() && prev(itr)->first != l &&\n            r <= prev(itr)->second)\
    \ {\n            return {prev(itr), false};\n        }\n        itr = st_emplace_hint(itr,\
    \ l, r);\n        while (itr != prev(st.end()) && next(itr)->first <= itr->second)\
    \ {\n            if (next(itr)->second <= itr->second) st_erase(next(itr));\n\
    \            else {\n                itr = st_emplace_hint(next(itr), itr->first,\
    \ next(itr)->second);\n                st_erase(prev(itr));\n                st_erase(next(itr));\n\
    \            }\n        }\n        while (itr != st.begin() && itr->first <= prev(itr)->second)\
    \ {\n            if (itr->first == prev(itr)->first) st_erase(prev(itr));\n  \
    \          else {\n                itr = st_emplace_hint(itr, prev(itr)->first,\
    \ itr->second);\n                st_erase(prev(itr));\n                st_erase(next(itr));\n\
    \            }\n        }\n        return {itr, true};\n    }\n    std::pair<iterator,\
    \ bool> insert(ll l) { return insert(l, l + 1); }\n    void erase(ll l, ll r)\
    \ {\n        assert(l <= r);\n        if (l == r) return;\n        auto itr =\
    \ st.lower_bound({l, r});\n        while (itr != st.end() && itr->first < r) {\n\
    \            if (itr->second <= r) itr = st_erase(itr);\n            else {\n\
    \                itr = st_emplace_hint(itr, r, itr->second);\n               \
    \ st_erase(prev(itr));\n            }\n        }\n        if (itr != st.begin()\
    \ && prev(itr)->first == l) st_erase(prev(itr));\n        else if (itr != st.begin()\
    \ && l < prev(itr)->second) {\n            st_emplace_hint(prev(itr), prev(itr)->first,\
    \ l);\n            st_erase(prev(itr));\n        }\n    }\n    void erase(ll l)\
    \ { erase(l, l + 1); }\n    bool include(ll k) {\n        auto itr = st.lower_bound({k\
    \ + 1, k + 1});\n        return itr != st.begin() && k < prev(itr)->second;\n\
    \    }\n    std::pair<ll, ll> find(ll k) {\n        auto itr = st.lower_bound({k\
    \ + 1, k + 1});\n        if (itr == st.begin()) return {-1, -1};\n        --itr;\n\
    \        if (itr->second <= k) return {-1, -1};\n        return *itr;\n    }\n\
    \    friend RangeSet operator||(const RangeSet& lhs, const RangeSet& rhs) {\n\
    \        RangeSet res = lhs;\n        each_const (p : rhs) res.insert(p.first,\
    \ p.second);\n        return res;\n    }\n    friend RangeSet operator&&(const\
    \ RangeSet& lhs, const RangeSet& rhs) {\n        RangeSet res;\n        auto itr1\
    \ = lhs.begin(), itr2 = rhs.begin();\n        while (itr1 != lhs.end() && itr2\
    \ != rhs.end()) {\n            ll l = std::max(itr1->first, itr2->first);\n  \
    \          ll r = std::min(itr1->second, itr2->second);\n            if (l < r)\
    \ res.insert(l, r);\n            if (itr1->second < itr2->second) ++itr1;\n  \
    \          else ++itr2;\n        }\n        return res;\n    }\n    friend bool\
    \ operator==(const RangeSet& a, const RangeSet& b) {\n        return a.st == b.st;\n\
    \    }\n    friend bool operator!=(const RangeSet& a, const RangeSet& b) {\n \
    \       return a.st != b.st;\n    }\n    friend bool operator>(const RangeSet&\
    \ a, const RangeSet& b) {\n        return a.st > b.st;\n    }\n    friend bool\
    \ operator>=(const RangeSet& a, const RangeSet& b) {\n        return a.st >= b.st;\n\
    \    }\n    friend bool operator<(const RangeSet& a, const RangeSet& b) {\n  \
    \      return a.st < b.st;\n    }\n    friend bool operator<=(const RangeSet&\
    \ a, const RangeSet& b) {\n        return a.st <= b.st;\n    }\n};\n\n/**\n *\
    \ @brief RangeSet(\u533A\u9593\u3092std::set\u3067\u7BA1\u7406\u3059\u308B\u4F8B\
    \u306E\u3084\u3064)\n * @docs docs/data-struct/other/RangeSet.md\n */\n"
  code: "#pragma once\n\n#include \"../../other/template.hpp\"\n\nclass RangeSet {\n\
    private:\n    using iterator = typename std::set<std::pair<ll, ll>>::iterator;\n\
    \    ll sz;\n    std::set<std::pair<ll, ll>> st;\n    iterator st_emplace_hint(const\
    \ iterator& itr, ll l, ll r) {\n        sz += r - l;\n        return st.emplace_hint(itr,\
    \ l, r);\n    }\n    iterator st_erase(const iterator& itr) {\n        sz -= itr->second\
    \ - itr->first;\n        return st.erase(itr);\n    }\n\npublic:\n    RangeSet()\
    \ : sz(0) {}\n    RangeSet(const std::set<std::pair<ll, ll>>& st_) : sz(0) {\n\
    \        each_const (p : st_) insert(p.first, p.second);\n    }\n    iterator\
    \ begin() const { return st.begin(); }\n    iterator end() const { return st.end();\
    \ }\n    bool empty() const { return st.empty(); }\n    int size() const { return\
    \ st.size(); }\n    ll length() const { return sz; }\n    const std::set<std::pair<ll,\
    \ ll>>& get_data() const& { return st; }\n    std::set<std::pair<ll, ll>>& get_data()\
    \ & { return st; }\n    std::set<std::pair<ll, ll>> get_data() && { return std::move(st);\
    \ }\n    std::pair<iterator, bool> insert(ll l, ll r) {\n        assert(l <= r);\n\
    \        if (l == r) return {st.end(), false};\n        auto itr = st.lower_bound({l,\
    \ r});\n        if (itr != st.end() && itr->first == l) return {itr, false};\n\
    \        if (itr != st.begin() && prev(itr)->first != l &&\n            r <= prev(itr)->second)\
    \ {\n            return {prev(itr), false};\n        }\n        itr = st_emplace_hint(itr,\
    \ l, r);\n        while (itr != prev(st.end()) && next(itr)->first <= itr->second)\
    \ {\n            if (next(itr)->second <= itr->second) st_erase(next(itr));\n\
    \            else {\n                itr = st_emplace_hint(next(itr), itr->first,\
    \ next(itr)->second);\n                st_erase(prev(itr));\n                st_erase(next(itr));\n\
    \            }\n        }\n        while (itr != st.begin() && itr->first <= prev(itr)->second)\
    \ {\n            if (itr->first == prev(itr)->first) st_erase(prev(itr));\n  \
    \          else {\n                itr = st_emplace_hint(itr, prev(itr)->first,\
    \ itr->second);\n                st_erase(prev(itr));\n                st_erase(next(itr));\n\
    \            }\n        }\n        return {itr, true};\n    }\n    std::pair<iterator,\
    \ bool> insert(ll l) { return insert(l, l + 1); }\n    void erase(ll l, ll r)\
    \ {\n        assert(l <= r);\n        if (l == r) return;\n        auto itr =\
    \ st.lower_bound({l, r});\n        while (itr != st.end() && itr->first < r) {\n\
    \            if (itr->second <= r) itr = st_erase(itr);\n            else {\n\
    \                itr = st_emplace_hint(itr, r, itr->second);\n               \
    \ st_erase(prev(itr));\n            }\n        }\n        if (itr != st.begin()\
    \ && prev(itr)->first == l) st_erase(prev(itr));\n        else if (itr != st.begin()\
    \ && l < prev(itr)->second) {\n            st_emplace_hint(prev(itr), prev(itr)->first,\
    \ l);\n            st_erase(prev(itr));\n        }\n    }\n    void erase(ll l)\
    \ { erase(l, l + 1); }\n    bool include(ll k) {\n        auto itr = st.lower_bound({k\
    \ + 1, k + 1});\n        return itr != st.begin() && k < prev(itr)->second;\n\
    \    }\n    std::pair<ll, ll> find(ll k) {\n        auto itr = st.lower_bound({k\
    \ + 1, k + 1});\n        if (itr == st.begin()) return {-1, -1};\n        --itr;\n\
    \        if (itr->second <= k) return {-1, -1};\n        return *itr;\n    }\n\
    \    friend RangeSet operator||(const RangeSet& lhs, const RangeSet& rhs) {\n\
    \        RangeSet res = lhs;\n        each_const (p : rhs) res.insert(p.first,\
    \ p.second);\n        return res;\n    }\n    friend RangeSet operator&&(const\
    \ RangeSet& lhs, const RangeSet& rhs) {\n        RangeSet res;\n        auto itr1\
    \ = lhs.begin(), itr2 = rhs.begin();\n        while (itr1 != lhs.end() && itr2\
    \ != rhs.end()) {\n            ll l = std::max(itr1->first, itr2->first);\n  \
    \          ll r = std::min(itr1->second, itr2->second);\n            if (l < r)\
    \ res.insert(l, r);\n            if (itr1->second < itr2->second) ++itr1;\n  \
    \          else ++itr2;\n        }\n        return res;\n    }\n    friend bool\
    \ operator==(const RangeSet& a, const RangeSet& b) {\n        return a.st == b.st;\n\
    \    }\n    friend bool operator!=(const RangeSet& a, const RangeSet& b) {\n \
    \       return a.st != b.st;\n    }\n    friend bool operator>(const RangeSet&\
    \ a, const RangeSet& b) {\n        return a.st > b.st;\n    }\n    friend bool\
    \ operator>=(const RangeSet& a, const RangeSet& b) {\n        return a.st >= b.st;\n\
    \    }\n    friend bool operator<(const RangeSet& a, const RangeSet& b) {\n  \
    \      return a.st < b.st;\n    }\n    friend bool operator<=(const RangeSet&\
    \ a, const RangeSet& b) {\n        return a.st <= b.st;\n    }\n};\n\n/**\n *\
    \ @brief RangeSet(\u533A\u9593\u3092std::set\u3067\u7BA1\u7406\u3059\u308B\u4F8B\
    \u306E\u3084\u3064)\n * @docs docs/data-struct/other/RangeSet.md\n */\n"
  dependsOn:
  - other/template.hpp
  isVerificationFile: false
  path: data-struct/other/RangeSet.hpp
  requiredBy: []
  timestamp: '2022-08-16 22:53:46+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yuki/1601-RangeSet.test.cpp
documentation_of: data-struct/other/RangeSet.hpp
layout: document
redirect_from:
- /library/data-struct/other/RangeSet.hpp
- /library/data-struct/other/RangeSet.hpp.html
title: "RangeSet(\u533A\u9593\u3092std::set\u3067\u7BA1\u7406\u3059\u308B\u4F8B\u306E\
  \u3084\u3064)"
---
## 概要

区間を `std::set` で管理するやつ。

- `RangeSet()` : コンストラクタ。 $\Theta(1)$ 。
- `bool empty()` : 空であるかを返す。 $\Theta(1)$ 。
- `int size()` : 区間の個数を返す。 $\Theta(1)$ 。
- `ll length()` : 区間内の整数の数を返す。 $\Theta(1)$ 。
- `set<PLL> get_data()` : `set` を返す。 $\Theta(N)$ 。
- `pair<iterator, bool> insert(ll l, ll r)` : 区間 `[l, r)` を追加する。償却 $\Theta(\log N)$ 。
- `void erase(ll l, ll r)` : 区間 `[l, r)` を全て削除する。償却 $\Theta(\log N)$ 。
- `bool include(ll k)` : 整数 `k` が含まれているかを返す。 $\Theta(\log N)$ 。
- `PLL find(ll k)` : 整数 `k` を含む区間を返す。ない場合は `(-1, -1)` を返す。 $\Theta(\log N)$ 。
- `RangeSet operator&&(Range a, Range b)` : 共通集合を返す。 $\Theta(N \log N)$ 。
- `RangeSet operator||(Range a, Range b)` : 和集合を返す。 $\Theta(N \log N)$ 。
