---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-struct/cht/LiChaoTree.hpp
    title: LiChaoTree
  - icon: ':heavy_check_mark:'
    path: other/bitop.hpp
    title: other/bitop.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/segment_add_get_min
    links:
    - https://judge.yosupo.jp/problem/segment_add_get_min
  bundledCode: "#line 1 \"test/yosupo/data_structure/segment_add_get_min.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n#line\
    \ 2 \"other/template.hpp\"\n\n#include <bits/stdc++.h>\n\n#ifndef __COUNTER__\n\
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
    \ std::rend(v)\n\n#if __cpp_constexpr >= 201304L\n#define CONSTEXPR constexpr\n\
    #else\n#define CONSTEXPR\n#endif\n\n#if __cpp_if_constexpr >= 201606L\n#define\
    \ IF_CONSTEXPR constexpr\n#else\n#define IF_CONSTEXPR\n#endif\n\nusing ll = long\
    \ long;\nusing ull = unsigned long long;\nusing ld = long double;\nusing PLL =\
    \ std::pair<ll, ll>;\ntemplate<class T>\nusing prique = std::priority_queue<T,\
    \ std::vector<T>, std::greater<T>>;\n\ntemplate<class T> class infinity {\npublic:\n\
    \    static constexpr T value = std::numeric_limits<T>::max() / 2;\n    static\
    \ constexpr T mvalue = std::numeric_limits<T>::min() / 2;\n    static constexpr\
    \ T max = std::numeric_limits<T>::max();\n    static constexpr T min = std::numeric_limits<T>::min();\n\
    };\n\n#if __cplusplus <= 201402L\ntemplate<class T> constexpr T infinity<T>::value;\n\
    template<class T> constexpr T infinity<T>::mvalue;\ntemplate<class T> constexpr\
    \ T infinity<T>::max;\ntemplate<class T> constexpr T infinity<T>::min;\n#endif\n\
    \n#if __cpp_variable_templates >= 201304L\ntemplate<class T> constexpr T INF =\
    \ infinity<T>::value;\n#endif\n\nconstexpr ll inf = infinity<ll>::value;\nconstexpr\
    \ ld EPS = 1e-8;\nconstexpr ld PI = 3.1415926535897932384626;\n\ntemplate<class\
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
    \ data() && { return std::move(dat); }\n};\n#line 2 \"data-struct/cht/LiChaoTree.hpp\"\
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
    \ x) { return x ? msb(x - 1) + 1 : 0; }\n} // namespace bitop\n#line 5 \"data-struct/cht/LiChaoTree.hpp\"\
    \n\ntemplate<class T = ll, bool is_max = false> class LiChaoTree {\nprivate:\n\
    \    struct Line {\n        T a, b;\n        int idx;\n        T get(T x) const\
    \ { return a * x + b; }\n        Line() = default;\n        Line(T a, T b, int\
    \ id) : a(a), b(b), idx(id) {}\n    };\n    int line_count = 0;\n    int ori,\
    \ n;\n    std::vector<T> xs;\n    std::vector<Line> lns;\n    void add_line(int\
    \ k, int a, int b, const Line& line) {\n        if (a + 1 == b) {\n          \
    \  if (line.get(xs[a]) < lns[k].get(xs[a])) lns[k] = line;\n            return;\n\
    \        }\n        int m = (a + b) >> 1;\n        T x1 = lns[k].get(xs[a]), x2\
    \ = line.get(xs[a]);\n        T y1 = lns[k].get(xs[b - 1]), y2 = line.get(xs[b\
    \ - 1]);\n        if (x1 <= x2 && y1 <= y2) return;\n        if (x2 <= x1 && y2\
    \ <= y1) {\n            lns[k] = line;\n            return;\n        }\n     \
    \   if (lns[k].get(xs[m]) <= line.get(xs[m])) {\n            if (y1 < y2) add_line(k\
    \ << 1, a, m, line);\n            else add_line(k << 1 | 1, m, b, line);\n   \
    \     }\n        else {\n            if (y1 < y2) add_line(k << 1 | 1, m, b, lns[k]);\n\
    \            else add_line(k << 1, a, m, lns[k]);\n            lns[k] = line;\n\
    \        }\n    }\n    void add_segment(int k, int a, int b, int l, int r, const\
    \ Line& line) {\n        if (l <= a && b <= r) {\n            add_line(k, a, b,\
    \ line);\n            return;\n        }\n        if (r <= a || b <= l) return;\n\
    \        int m = (a + b) >> 1;\n        add_segment(k << 1, a, m, l, r, line);\n\
    \        add_segment(k << 1 | 1, m, b, l, r, line);\n    }\n\npublic:\n    LiChaoTree()\
    \ : LiChaoTree({0}) {}\n    LiChaoTree(const std::vector<T>& xs_) { init(xs_);\
    \ }\n    void init(const std::vector<T>& xs_) {\n        xs = xs_.empty() ? std::vector<T>{0}\
    \ : xs_;\n        ori = xs.size();\n        n = 1 << bitop::ceil_log2(ori);\n\
    \        xs.reserve(n);\n        rep (i, xs_.size(), n) xs.push_back(xs_[i] +\
    \ 1);\n        lns.assign(n << 1,\n                   Line{0, is_max ? infinity<T>::min\
    \ : infinity<T>::max, -1});\n    }\n    int add_segment(int l, int r, T x, T y)\
    \ {\n        assert(0 <= l && l <= r && r <= ori);\n        add_segment(1, 0,\
    \ n, l, r,\n                    Line{is_max ? -x : x, is_max ? -y : y, line_count});\n\
    \        return line_count++;\n    }\n    int add_line(T x, T y) {\n        add_line(1,\
    \ 0, n, Line{is_max ? -x : x, is_max ? -y : y, line_count});\n        return line_count++;\n\
    \    }\n    T get_min(int k) const {\n        int x = k + n;\n        T res =\
    \ lns[x].get(xs[k]);\n        while (x >>= 1) {\n            const T y = lns[x].get(xs[k]);\n\
    \            chmin(res, is_max ? -y : y);\n        }\n        return res;\n  \
    \  }\n    struct line {\n        T a, b;\n        int idx;\n    };\n    line get_min_line(int\
    \ k) const {\n        int x = k + n;\n        T mn = lns[x].get(xs[k]);\n    \
    \    Line res = lns[x];\n        while (x >>= 1) {\n            const T y = lns[x].get(xs[k]);\n\
    \            if (chmin(mn, is_max ? -y : y)) res = lns[x];\n        }\n      \
    \  return line{is_max ? -res.a : res.a, is_max ? -res.b : res.b, res.idx};\n \
    \   }\n};\n\n/**\n * @brief LiChaoTree\n * @docs docs/data-struct/cht/LiChaoTree.md\n\
    \ */\n#line 4 \"test/yosupo/data_structure/segment_add_get_min.test.cpp\"\nusing\
    \ namespace std;\nint main() {\n    int N, Q; cin >> N >> Q;\n    vector<array<ll,\
    \ 4>> A(N); cin >> A;\n    vector<array<ll, 5>> B(Q);\n    each_for ([a, b, c,\
    \ d, e] : B) {\n        cin >> a;\n        if (a == 0) cin >> b >> c >> d >> e;\n\
    \        else cin >> b;\n    }\n    presser<ll> ps;\n    each_const ([a, b, c,\
    \ d, e] : B) {\n        if (a == 1) ps.push_back(b);\n    }\n    ps.build();\n\
    \    if (ps.size() == 0) return 0;\n    LiChaoTree lct(ps.data());\n    each_const\
    \ ([a, b, c, d] : A) {\n        lct.add_segment(ps.lower_bound(a), ps.lower_bound(b),\
    \ c, d);\n    }\n    each_const ([a, b, c, d, e] : B) {\n        if (a == 0) lct.add_segment(ps.lower_bound(b),\
    \ ps.lower_bound(c), d, e);\n        else {\n            ll res = lct.get_min(ps.get(b));\n\
    \            if (res == infinity<ll>::max) puts(\"INFINITY\");\n            else\
    \ cout << res << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n\
    #include \"../../../other/template.hpp\"\n#include \"../../../data-struct/cht/LiChaoTree.hpp\"\
    \nusing namespace std;\nint main() {\n    int N, Q; cin >> N >> Q;\n    vector<array<ll,\
    \ 4>> A(N); cin >> A;\n    vector<array<ll, 5>> B(Q);\n    each_for ([a, b, c,\
    \ d, e] : B) {\n        cin >> a;\n        if (a == 0) cin >> b >> c >> d >> e;\n\
    \        else cin >> b;\n    }\n    presser<ll> ps;\n    each_const ([a, b, c,\
    \ d, e] : B) {\n        if (a == 1) ps.push_back(b);\n    }\n    ps.build();\n\
    \    if (ps.size() == 0) return 0;\n    LiChaoTree lct(ps.data());\n    each_const\
    \ ([a, b, c, d] : A) {\n        lct.add_segment(ps.lower_bound(a), ps.lower_bound(b),\
    \ c, d);\n    }\n    each_const ([a, b, c, d, e] : B) {\n        if (a == 0) lct.add_segment(ps.lower_bound(b),\
    \ ps.lower_bound(c), d, e);\n        else {\n            ll res = lct.get_min(ps.get(b));\n\
    \            if (res == infinity<ll>::max) puts(\"INFINITY\");\n            else\
    \ cout << res << endl;\n        }\n    }\n}\n"
  dependsOn:
  - other/template.hpp
  - data-struct/cht/LiChaoTree.hpp
  - other/bitop.hpp
  isVerificationFile: true
  path: test/yosupo/data_structure/segment_add_get_min.test.cpp
  requiredBy: []
  timestamp: '2022-08-19 03:53:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/data_structure/segment_add_get_min.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/data_structure/segment_add_get_min.test.cpp
- /verify/test/yosupo/data_structure/segment_add_get_min.test.cpp.html
title: test/yosupo/data_structure/segment_add_get_min.test.cpp
---
