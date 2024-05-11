---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/MillerRabin.hpp
    title: "MillerRabin(\u30DF\u30E9\u30FC\u30E9\u30D3\u30F3\u7D20\u6570\u5224\u5B9A\
      )"
  - icon: ':x:'
    path: math/MontgomeryModInt.hpp
    title: "MontgomeryModInt(\u30E2\u30F3\u30B4\u30E1\u30EA\u4E57\u7B97)"
  - icon: ':x:'
    path: math/PollardRho.hpp
    title: "PollardRho(\u7D20\u56E0\u6570\u5206\u89E3)"
  - icon: ':question:'
    path: other/template.hpp
    title: other/template.hpp
  - icon: ':question:'
    path: random/Random.hpp
    title: Random
  - icon: ':x:'
    path: string/RunLength.hpp
    title: "RunLength(\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E)"
  - icon: ':question:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':question:'
    path: template/bitop.hpp
    title: template/bitop.hpp
  - icon: ':question:'
    path: template/func.hpp
    title: template/func.hpp
  - icon: ':question:'
    path: template/in.hpp
    title: template/in.hpp
  - icon: ':question:'
    path: template/macros.hpp
    title: template/macros.hpp
  - icon: ':question:'
    path: template/out.hpp
    title: template/out.hpp
  - icon: ':question:'
    path: template/type_traits.hpp
    title: template/type_traits.hpp
  - icon: ':question:'
    path: template/util.hpp
    title: template/util.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: math/TetrationMod.hpp
    title: TetrationMod
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/NTL/NTL_1_D-Phi.test.cpp
    title: test/aoj/NTL/NTL_1_D-Phi.test.cpp
  - icon: ':x:'
    path: test/yosupo/math/tetration_mod.test.cpp
    title: test/yosupo/math/tetration_mod.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/math/EulerPhi.md
    document_title: "Euler's-Phi(\u30AA\u30A4\u30E9\u30FC\u306E\u03C6\u95A2\u6570)"
    links: []
  bundledCode: "#line 2 \"math/EulerPhi.hpp\"\n\n#line 2 \"other/template.hpp\"\n\n\
    #include <bits/stdc++.h>\n#line 2 \"template/macros.hpp\"\n\n#line 4 \"template/macros.hpp\"\
    \n\n#ifndef __COUNTER__\n#define __COUNTER__ __LINE__\n#endif\n\n#define OVERLOAD5(a,\
    \ b, c, d, e, ...) e\n#define REP1_0(b, c) REP1_1(b, c)\n#define REP1_1(b, c)\
    \                                                           \\\n    for (ll REP_COUNTER_##c\
    \ = 0; REP_COUNTER_##c < (ll)(b); ++REP_COUNTER_##c)\n#define REP1(b) REP1_0(b,\
    \ __COUNTER__)\n#define REP2(i, b) for (ll i = 0; i < (ll)(b); ++i)\n#define REP3(i,\
    \ a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)\n#define REP4(i, a, b, c) for (ll\
    \ i = (ll)(a); i < (ll)(b); i += (ll)(c))\n#define rep(...) OVERLOAD5(__VA_ARGS__,\
    \ REP4, REP3, REP2, REP1)(__VA_ARGS__)\n#define RREP2(i, a) for (ll i = (ll)(a)-1;\
    \ i >= 0; --i)\n#define RREP3(i, a, b) for (ll i = (ll)(a)-1; i >= (ll)(b); --i)\n\
    #define RREP4(i, a, b, c) for (ll i = (ll)(a)-1; i >= (ll)(b); i -= (ll)(c))\n\
    #define rrep(...) OVERLOAD5(__VA_ARGS__, RREP4, RREP3, RREP2)(__VA_ARGS__)\n#define\
    \ REPS2(i, b) for (ll i = 1; i <= (ll)(b); ++i)\n#define REPS3(i, a, b) for (ll\
    \ i = (ll)(a) + 1; i <= (ll)(b); ++i)\n#define REPS4(i, a, b, c) for (ll i = (ll)(a)\
    \ + 1; i <= (ll)(b); i += (ll)(c))\n#define reps(...) OVERLOAD5(__VA_ARGS__, REPS4,\
    \ REPS3, REPS2)(__VA_ARGS__)\n#define RREPS2(i, a) for (ll i = (ll)(a); i > 0;\
    \ --i)\n#define RREPS3(i, a, b) for (ll i = (ll)(a); i > (ll)(b); --i)\n#define\
    \ RREPS4(i, a, b, c) for (ll i = (ll)(a); i > (ll)(b); i -= (ll)(c))\n#define\
    \ rreps(...) OVERLOAD5(__VA_ARGS__, RREPS4, RREPS3, RREPS2)(__VA_ARGS__)\n\n#define\
    \ each_for(...) for (auto&& __VA_ARGS__)\n#define each_const(...) for (const auto&\
    \ __VA_ARGS__)\n\n#define all(v) std::begin(v), std::end(v)\n#define rall(v) std::rbegin(v),\
    \ std::rend(v)\n\n#if __cpp_if_constexpr >= 201606L\n#define IF_CONSTEXPR constexpr\n\
    #else\n#define IF_CONSTEXPR\n#endif\n\n#define IO_BUFFER_SIZE (1 << 17)\n#line\
    \ 2 \"template/alias.hpp\"\n\n#line 4 \"template/alias.hpp\"\n\nusing ll = long\
    \ long;\nusing uint = unsigned int;\nusing ull = unsigned long long;\nusing i128\
    \ = __int128_t;\nusing u128 = __uint128_t;\nusing ld = long double;\nusing PLL\
    \ = std::pair<ll, ll>;\ntemplate<class T>\nusing prique = std::priority_queue<T,\
    \ std::vector<T>, std::greater<T>>;\n\ntemplate<class T> struct infinity {\n \
    \   static constexpr T value = std::numeric_limits<T>::max() / 2;\n    static\
    \ constexpr T mvalue = std::numeric_limits<T>::lowest() / 2;\n    static constexpr\
    \ T max = std::numeric_limits<T>::max();\n    static constexpr T min = std::numeric_limits<T>::lowest();\n\
    };\n\n#if __cplusplus <= 201402L\ntemplate<class T> constexpr T infinity<T>::value;\n\
    template<class T> constexpr T infinity<T>::mvalue;\ntemplate<class T> constexpr\
    \ T infinity<T>::max;\ntemplate<class T> constexpr T infinity<T>::min;\n#endif\n\
    \n#if __cpp_variable_templates >= 201304L\ntemplate<class T> constexpr T INF =\
    \ infinity<T>::value;\n#endif\n\nconstexpr ll inf = infinity<ll>::value;\nconstexpr\
    \ ld EPS = 1e-8;\nconstexpr ld PI = 3.1415926535897932384626;\n#line 2 \"template/type_traits.hpp\"\
    \n\n#line 5 \"template/type_traits.hpp\"\n\ntemplate<class T, class... Args> struct\
    \ function_traits_impl {\n    using result_type = T;\n    template<std::size_t\
    \ idx>\n    using argument_type =\n        typename std::tuple_element<idx, std::tuple<Args...>>::type;\n\
    \    using argument_tuple = std::tuple<Args...>;\n    static constexpr std::size_t\
    \ arg_size() { return sizeof...(Args); }\n};\n\ntemplate<class> struct function_traits_helper;\n\
    \ntemplate<class Res, class Tp, class... Args>\nstruct function_traits_helper<Res\
    \ (Tp::*)(Args...)> {\n    using type = function_traits_impl<Res, Args...>;\n\
    };\ntemplate<class Res, class Tp, class... Args>\nstruct function_traits_helper<Res\
    \ (Tp::*)(Args...)&> {\n    using type = function_traits_impl<Res, Args...>;\n\
    };\ntemplate<class Res, class Tp, class... Args>\nstruct function_traits_helper<Res\
    \ (Tp::*)(Args...) const> {\n    using type = function_traits_impl<Res, Args...>;\n\
    };\ntemplate<class Res, class Tp, class... Args>\nstruct function_traits_helper<Res\
    \ (Tp::*)(Args...) const&> {\n    using type = function_traits_impl<Res, Args...>;\n\
    };\n\n#if __cpp_noexcept_function_type >= 201510L\ntemplate<class Res, class Tp,\
    \ class... Args>\nstruct function_traits_helper<Res (Tp::*)(Args...) noexcept>\
    \ {\n    using type = function_traits_impl<Res, Args...>;\n};\ntemplate<class\
    \ Res, class Tp, class... Args>\nstruct function_traits_helper<Res (Tp::*)(Args...)&\
    \ noexcept> {\n    using type = function_traits_impl<Res, Args...>;\n};\ntemplate<class\
    \ Res, class Tp, class... Args>\nstruct function_traits_helper<Res (Tp::*)(Args...)\
    \ const noexcept> {\n    using type = function_traits_impl<Res, Args...>;\n};\n\
    template<class Res, class Tp, class... Args>\nstruct function_traits_helper<Res\
    \ (Tp::*)(Args...) const& noexcept> {\n    using type = function_traits_impl<Res,\
    \ Args...>;\n};\n#endif\n\ntemplate<class F>\nusing function_traits = typename\
    \ function_traits_helper<\n    decltype(&std::remove_reference<F>::type::operator())>::type;\n\
    \ntemplate<class F>\nusing function_result_type = typename function_traits<F>::result_type;\n\
    template<class F, std::size_t idx>\nusing function_argument_type =\n    typename\
    \ function_traits<F>::template argument_type<idx>;\ntemplate<class F>\nusing function_argument_tuple\
    \ = typename function_traits<F>::argument_tuple;\n\ntemplate<class T>\nusing is_signed_int\
    \ =\n    std::integral_constant<bool, (std::is_integral<T>::value &&\n       \
    \                           std::is_signed<T>::value) ||\n                   \
    \                  std::is_same<T, i128>::value>;\ntemplate<class T>\nusing is_unsigned_int\
    \ =\n    std::integral_constant<bool, (std::is_integral<T>::value &&\n       \
    \                           std::is_unsigned<T>::value) ||\n                 \
    \                    std::is_same<T, u128>::value>;\ntemplate<class T>\nusing\
    \ is_int = std::integral_constant<bool, is_signed_int<T>::value ||\n         \
    \                                       is_unsigned_int<T>::value>;\ntemplate<class\
    \ T>\nusing make_signed_int = typename std::conditional<\n    std::is_same<T,\
    \ i128>::value || std::is_same<T, u128>::value,\n    std::common_type<i128>, std::make_signed<T>>::type;\n\
    template<class T>\nusing make_unsigned_int = typename std::conditional<\n    std::is_same<T,\
    \ i128>::value || std::is_same<T, u128>::value,\n    std::common_type<u128>, std::make_unsigned<T>>::type;\n\
    \n\ntemplate<class T, class = void> struct is_range : std::false_type {};\ntemplate<class\
    \ T>\nstruct is_range<\n    T,\n    decltype(all(std::declval<typename std::add_lvalue_reference<T>::type>()),\n\
    \             (void)0)> : std::true_type {};\n\ntemplate<class T, bool = is_range<T>::value>\n\
    struct range_rank : std::integral_constant<std::size_t, 0> {};\ntemplate<class\
    \ T>\nstruct range_rank<T, true>\n    : std::integral_constant<std::size_t,\n\
    \                             range_rank<typename T::value_type>::value + 1> {};\n\
    \ntemplate<std::size_t size> struct int_least {\n    static_assert(size <= 128,\
    \ \"size must be less than or equal to 128\");\n\n    using type = typename std::conditional<\n\
    \        size <= 8, std::int_least8_t,\n        typename std::conditional<\n \
    \           size <= 16, std::int_least16_t,\n            typename std::conditional<\n\
    \                size <= 32, std::int_least32_t,\n                typename std::conditional<size\
    \ <= 64, std::int_least64_t,\n                                          i128>::type>::type>::type>::type;\n\
    };\n\ntemplate<std::size_t size> using int_least_t = typename int_least<size>::type;\n\
    \ntemplate<std::size_t size> struct uint_least {\n    static_assert(size <= 128,\
    \ \"size must be less than or equal to 128\");\n\n    using type = typename std::conditional<\n\
    \        size <= 8, std::uint_least8_t,\n        typename std::conditional<\n\
    \            size <= 16, std::uint_least16_t,\n            typename std::conditional<\n\
    \                size <= 32, std::uint_least32_t,\n                typename std::conditional<size\
    \ <= 64, std::uint_least64_t,\n                                          u128>::type>::type>::type>::type;\n\
    };\n\ntemplate<std::size_t size> using uint_least_t = typename uint_least<size>::type;\n\
    \ntemplate<class T>\nusing double_size_int = int_least<std::numeric_limits<T>::digits\
    \ * 2 + 1>;\ntemplate<class T> using double_size_int_t = typename double_size_int<T>::type;\n\
    template<class T>\nusing double_size_uint = uint_least<std::numeric_limits<T>::digits\
    \ * 2>;\ntemplate<class T> using double_size_uint_t = typename double_size_uint<T>::type;\n\
    \ntemplate<class T>\nusing double_size =\n    typename std::conditional<is_signed_int<T>::value,\
    \ double_size_int<T>,\n                              double_size_uint<T>>::type;\n\
    template<class T> using double_size_t = typename double_size<T>::type;\n#line\
    \ 2 \"template/in.hpp\"\n\n#line 4 \"template/in.hpp\"\n#include <unistd.h>\n\
    #line 8 \"template/in.hpp\"\n\ntemplate<std::size_t buf_size = IO_BUFFER_SIZE,\
    \ std::size_t decimal_precision = 16> class Scanner {\nprivate:\n    template<class,\
    \ class = void> struct has_scan : std::false_type {};\n    template<class T>\n\
    \    struct has_scan<\n        T, decltype(std::declval<T>().scan(std::declval<Scanner&>()),\
    \ (void)0)>\n        : std::true_type {};\n    int fd;\n    int idx, sz;\n   \
    \ bool state;\n    std::array<char, IO_BUFFER_SIZE + 1> buffer;\n    inline char\
    \ cur() {\n        if (idx == sz) load();\n        if (idx == sz) {\n        \
    \    state = false;\n            return '\\0';\n        }\n        return buffer[idx];\n\
    \    }\n    inline void next() {\n        if (idx == sz) load();\n        if (idx\
    \ == sz) return;\n        ++idx;\n    }\n\npublic:\n    inline void load() {\n\
    \        int len = sz - idx;\n        if (idx < len) return;\n        std::memcpy(buffer.begin(),\
    \ buffer.begin() + idx, len);\n        sz = len + read(fd, buffer.data() + len,\
    \ buf_size - len);\n        buffer[sz] = 0;\n        idx = 0;\n    }\n\n    Scanner(int\
    \ fd) : fd(fd), idx(0), sz(0) {}\n    Scanner(FILE* fp) : fd(fileno(fp)), idx(0),\
    \ sz(0) {}\n\n    inline char scan_char() {\n        if (idx == sz) load();\n\
    \        return idx == sz ? '\\0' : buffer[idx++];\n    }\n\n    Scanner ignore(int\
    \ n = 1) {\n        if (idx + n > sz) load();\n        idx += n;\n        return\
    \ *this;\n    }\n\n    inline void discard_space() {\n        if (idx == sz) load();\n\
    \        while (('\\t' <= buffer[idx] && buffer[idx] <= '\\r') || buffer[idx]\
    \ == ' ') {\n            if (++idx == sz) load();\n        }\n    }\n    void\
    \ scan(char& a) {\n        discard_space();\n        a = scan_char();\n    }\n\
    \    void scan(bool& a) {\n        discard_space();\n        a = scan_char() !=\
    \ '0';\n    }\n    void scan(std::string& a) {\n        discard_space();\n   \
    \     a.clear();\n        while (cur() != '\\0' && (buffer[idx] < '\\t' || '\\\
    r' < buffer[idx]) && buffer[idx] != ' ') {\n            a += scan_char();\n  \
    \      }\n    }\n    template<std::size_t len> void scan(std::bitset<len>& a)\
    \ {\n        discard_space();\n        if (idx + len > sz) load();\n        rrep\
    \ (i, len) a[i] = buffer[idx++] != '0';\n    }\n    template<class T,\n      \
    \       typename std::enable_if<is_signed_int<T>::value &&\n                 \
    \                    !has_scan<T>::value>::type* = nullptr>\n    void scan(T&\
    \ a) {\n        discard_space();\n        if (buffer[idx] == '-') {\n        \
    \    ++idx;\n            if (idx + 20 > sz && '0' <= buffer[sz - 1] && buffer[sz\
    \ - 1] <= '9') load();\n            a = 0;\n            while ('0' <= buffer[idx]\
    \ && buffer[idx] <= '9') {\n                a = a * 10 - (buffer[idx++] - '0');\n\
    \            }\n        }\n        else {\n            if (idx + 20 > sz && '0'\
    \ <= buffer[sz - 1] && buffer[sz - 1] <= '9') load();\n            a = 0;\n  \
    \          while ('0' <= buffer[idx] && buffer[idx] <= '9') {\n              \
    \  a = a * 10 + (buffer[idx++] - '0');\n            }\n        }\n    }\n    template<class\
    \ T,\n             typename std::enable_if<is_unsigned_int<T>::value &&\n    \
    \                                 !has_scan<T>::value>::type* = nullptr>\n   \
    \ void scan(T& a) {\n        discard_space();\n        if (idx + 20 > sz && '0'\
    \ <= buffer[sz - 1] && buffer[sz - 1] <= '9') load();\n        a = 0;\n      \
    \  while ('0' <= buffer[idx] && buffer[idx] <= '9') {\n            a = a * 10\
    \ + (buffer[idx++] - '0');\n        }\n    }\n    template<class T,\n        \
    \     typename std::enable_if<std::is_floating_point<T>::value &&\n          \
    \                           !has_scan<T>::value>::type* = nullptr>\n    void scan(T&\
    \ a) {\n        discard_space();\n        bool sgn = false;\n        if (cur()\
    \ == '-') {\n            sgn = true;\n            next();\n        }\n       \
    \ a = 0;\n        while ('0' <= cur() && cur() <= '9') {\n            a = a *\
    \ 10 + cur() - '0';\n            next();\n        }\n        if (cur() == '.')\
    \ {\n            next();\n            T n = 0, d = 1;\n            for (int i\
    \ = 0;\n                 '0' <= cur() && cur() <= '9' && i < (int)decimal_precision;\n\
    \                 ++i) {\n                n = n * 10 + cur() - '0';\n        \
    \        d *= 10;\n                next();\n            }\n            while ('0'\
    \ <= cur() && cur() <= '9') next();\n            a += n / d;\n        }\n    \
    \    if (sgn) a = -a;\n    }\n\nprivate:\n    template<std::size_t i, class...\
    \ Args> void scan(std::tuple<Args...>& a) {\n        if IF_CONSTEXPR (i < sizeof...(Args))\
    \ {\n            scan(std::get<i>(a));\n            scan<i + 1, Args...>(a);\n\
    \        }\n    }\n\npublic:\n    template<class... Args> void scan(std::tuple<Args...>&\
    \ a) {\n        scan<0, Args...>(a);\n    }\n    template<class T, class U> void\
    \ scan(std::pair<T, U>& a) {\n        scan(a.first);\n        scan(a.second);\n\
    \    }\n    template<class T,\n             typename std::enable_if<is_range<T>::value\
    \ &&\n                                     !has_scan<T>::value>::type* = nullptr>\n\
    \    void scan(T& a) {\n        for (auto&& i : a) scan(i);\n    }\n    template<class\
    \ T,\n             typename std::enable_if<has_scan<T>::value>::type* = nullptr>\n\
    \    void scan(T& a) {\n        a.scan(*this);\n    }\n\n    void operator()()\
    \ {}\n    template<class Head, class... Args>\n    void operator()(Head& head,\
    \ Args&... args) {\n        scan(head);\n        operator()(args...);\n    }\n\
    \n    template<class T> Scanner& operator>>(T& a) {\n        scan(a);\n      \
    \  return *this;\n    }\n\n    explicit operator bool() const { return state;\
    \ }\n\n    friend Scanner& getline(Scanner& scan, std::string& a) {\n        a.erase();\n\
    \        char c;\n        if ((c = scan.scan_char()) == '\\n' || c == '\\0') return\
    \ scan;\n        a += c;\n        while ((c = scan.scan_char()) != '\\n' && c\
    \ != '\\0') a += c;\n        scan.state = true;\n        return scan;\n    }\n\
    };\n\nScanner<> scan(0);\n#line 2 \"template/out.hpp\"\n\n#line 8 \"template/out.hpp\"\
    \n\nstruct NumberToString {\n    char buf[10000][4];\n    constexpr NumberToString()\
    \ : buf{} {\n        rep (i, 10000) {\n            int n = i;\n            rrep\
    \ (j, 4) {\n                buf[i][j] = (char)('0' + n % 10);\n              \
    \  n /= 10;\n            }\n        }\n    }\n} constexpr precalc_number_to_string;\n\
    \ntemplate<std::size_t buf_size = IO_BUFFER_SIZE, bool debug = false> class Printer\
    \ {\nprivate:\n    template<class, bool = debug, class = void>\n    struct has_print\
    \ : std::false_type {};\n    template<class T>\n    struct has_print<T, false,\n\
    \                     decltype(std::declval<T>().print(std::declval<Printer&>()),\n\
    \                              (void)0)> : std::true_type {};\n    template<class\
    \ T>\n    struct has_print<T, true,\n                     decltype(std::declval<T>().debug(std::declval<Printer&>()),\n\
    \                              (void)0)> : std::true_type {};\n    int fd;\n \
    \   std::size_t idx;\n    std::array<char, buf_size> buffer;\n\n    std::size_t\
    \ decimal_precision;\n\npublic:\n    inline void print_char(char c) {\n#if SHIO_LOCAL\n\
    \        buffer[idx++] = c;\n        if (idx == buf_size) flush();\n#else\n  \
    \      if IF_CONSTEXPR (!debug) {\n            buffer[idx++] = c;\n          \
    \  if (idx == buf_size) flush();\n        }\n#endif\n    }\n    inline void flush()\
    \ {\n        idx = write(fd, buffer.begin(), idx);\n        idx = 0;\n    }\n\n\
    \    Printer(int fd) : fd(fd), idx(0), decimal_precision(16) {}\n    Printer(FILE*\
    \ fp) : fd(fileno(fp)), idx(0), decimal_precision(16) {}\n    ~Printer() { flush();\
    \ }\n\n    void set_decimal_precision(std::size_t decimal_precision) {\n     \
    \   this->decimal_precision = decimal_precision;\n    }\n\n    void print(char\
    \ c) {\n        if IF_CONSTEXPR (debug) print_char('\\'');\n        print_char(c);\n\
    \        if IF_CONSTEXPR (debug) print_char('\\'');\n    }\n    void print(bool\
    \ b) { print_char((char)(b + '0')); }\n    void print(const char* a) {\n     \
    \   if IF_CONSTEXPR (debug) print_char('\"');\n        for (; *a != '\\0'; ++a)\
    \ print_char(*a);\n        if IF_CONSTEXPR (debug) print_char('\"');\n    }\n\
    \    template<std::size_t len> void print(const char (&a)[len]) {\n        if\
    \ IF_CONSTEXPR (debug) print_char('\"');\n        for (auto i : a) print_char(i);\n\
    \        if IF_CONSTEXPR (debug) print_char('\"');\n    }\n    void print(const\
    \ std::string& a) {\n        if IF_CONSTEXPR (debug) print_char('\"');\n     \
    \   for (auto i : a) print_char(i);\n        if IF_CONSTEXPR (debug) print_char('\"\
    ');\n    }\n    template<std::size_t len> void print(const std::bitset<len>& a)\
    \ {\n        rrep (i, len) print_char((char)(a[i] + '0'));\n    }\n    template<class\
    \ T,\n             typename std::enable_if<is_int<T>::value &&\n             \
    \                        !has_print<T>::value>::type* = nullptr>\n    void print(T\
    \ a) {\n        if (!a) {\n            print_char('0');\n            return;\n\
    \        }\n        if IF_CONSTEXPR (is_signed_int<T>::value) {\n            if\
    \ (a < 0) {\n                print_char('-');\n                using U = typename\
    \ make_unsigned_int<T>::type;\n                print(static_cast<U>(-static_cast<U>(a)));\n\
    \                return;\n            }\n        }\n        if (idx + 40 >= buf_size)\
    \ flush();\n        static char s[40];\n        int t = 40;\n        while (a\
    \ >= 10000) {\n            int i = a % 10000;\n            a /= 10000;\n     \
    \       t -= 4;\n            std::memcpy(s + t, precalc_number_to_string.buf[i],\
    \ 4);\n        }\n        if (a >= 1000) {\n            std::memcpy(buffer.begin()\
    \ + idx, precalc_number_to_string.buf[a], 4);\n            idx += 4;\n       \
    \ }\n        else if (a >= 100) {\n            std::memcpy(buffer.begin() + idx,\
    \ precalc_number_to_string.buf[a] + 1, 3);\n            idx += 3;\n        }\n\
    \        else if (a >= 10) {\n            std::memcpy(buffer.begin() + idx, precalc_number_to_string.buf[a]\
    \ + 2, 2);\n            idx += 2;\n        }\n        else {\n            buffer[idx++]\
    \ = '0' | a;\n        }\n        std::memcpy(buffer.begin() + idx, s + t, 40 -\
    \ t);\n        idx += 40 - t;\n    }\n    template<class T,\n             typename\
    \ std::enable_if<std::is_floating_point<T>::value &&\n                       \
    \              !has_print<T>::value>::type* = nullptr>\n    void print(T a) {\n\
    \        if (a == std::numeric_limits<T>::infinity()) {\n            print(\"\
    inf\");\n            return;\n        }\n        if (a == -std::numeric_limits<T>::infinity())\
    \ {\n            print(\"-inf\");\n            return;\n        }\n        if\
    \ (std::isnan(a)) {\n            print(\"nan\");\n            return;\n      \
    \  }\n        if (a < 0) {\n            print_char('-');\n            a = -a;\n\
    \        }\n        T b = a;\n        if (b < 1) {\n            print_char('0');\n\
    \        }\n        else {\n            std::string s;\n            while (b >=\
    \ 1) {\n                s += (char)('0' + (int)std::fmod(b, 10.0));\n        \
    \        b /= 10;\n            }\n            for (auto i = s.rbegin(); i != s.rend();\
    \ ++i) print_char(*i);\n        }\n        print_char('.');\n        rep (decimal_precision)\
    \ {\n            a *= 10;\n            print_char((char)('0' + (int)std::fmod(a,\
    \ 10.0)));\n        }\n    }\n\nprivate:\n    template<std::size_t i, class...\
    \ Args>\n    void print(const std::tuple<Args...>& a) {\n        if IF_CONSTEXPR\
    \ (i < sizeof...(Args)) {\n            if IF_CONSTEXPR (debug) print_char(',');\n\
    \            print_char(' ');\n            print(std::get<i>(a));\n          \
    \  print<i + 1, Args...>(a);\n        }\n    }\n\npublic:\n    template<class...\
    \ Args> void print(const std::tuple<Args...>& a) {\n        if IF_CONSTEXPR (debug)\
    \ print_char('(');\n        if IF_CONSTEXPR (sizeof...(Args) != 0) print(std::get<0>(a));\n\
    \        print<1, Args...>(a);\n        if IF_CONSTEXPR (debug) print_char(')');\n\
    \    }\n    template<class T, class U> void print(const std::pair<T, U>& a) {\n\
    \        if IF_CONSTEXPR (debug) print_char('(');\n        print(a.first);\n \
    \       if IF_CONSTEXPR (debug) print_char(',');\n        print_char(' ');\n \
    \       print(a.second);\n        if IF_CONSTEXPR (debug) print_char(')');\n \
    \   }\n    template<class T,\n             typename std::enable_if<is_range<T>::value\
    \ &&\n                                     !has_print<T>::value>::type* = nullptr>\n\
    \    void print(const T& a) {\n        if IF_CONSTEXPR (debug) print_char('{');\n\
    \        for (auto i = std::begin(a); i != std::end(a); ++i) {\n            if\
    \ (i != std::begin(a)) {\n                if IF_CONSTEXPR (debug) print_char(',');\n\
    \                print_char(' ');\n            }\n            print(*i);\n   \
    \     }\n        if IF_CONSTEXPR (debug) print_char('}');\n    }\n    template<class\
    \ T, typename std::enable_if<has_print<T>::value &&\n                        \
    \                      !debug>::type* = nullptr>\n    void print(const T& a) {\n\
    \        a.print(*this);\n    }\n    template<class T, typename std::enable_if<has_print<T>::value\
    \ &&\n                                              debug>::type* = nullptr>\n\
    \    void print(const T& a) {\n        a.debug(*this);\n    }\n\n    void operator()()\
    \ {}\n    template<class Head, class... Args>\n    void operator()(const Head&\
    \ head, const Args&... args) {\n        print(head);\n        operator()(args...);\n\
    \    }\n\n    template<class T> Printer& operator<<(const T& a) {\n        print(a);\n\
    \        return *this;\n    }\n\n    Printer& operator<<(Printer& (*pf)(Printer&))\
    \ { return pf(*this); }\n};\n\ntemplate<std::size_t buf_size, bool debug>\nPrinter<buf_size,\
    \ debug>& endl(Printer<buf_size, debug>& pr) {\n    pr.print_char('\\n');\n  \
    \  pr.flush();\n    return pr;\n}\ntemplate<std::size_t buf_size, bool debug>\n\
    Printer<buf_size, debug>& flush(Printer<buf_size, debug>& pr) {\n    pr.flush();\n\
    \    return pr;\n}\n\nstruct SetPrec {\n    int n;\n    template<class Pr> void\
    \ print(Pr& pr) const { pr.set_decimal_precision(n); }\n    template<class Pr>\
    \ void debug(Pr& pr) const { pr.set_decimal_precision(n); }\n};\nSetPrec setprec(int\
    \ n) { return SetPrec{n}; };\n\nPrinter<> print(1), eprint(2);\n\nvoid prints()\
    \ { print.print_char('\\n'); }\n\ntemplate<class T> auto prints(const T& v) ->\
    \ decltype(print << v, (void)0) {\n    print << v;\n    print.print_char('\\n');\n\
    }\n\ntemplate<class Head, class... Tail>\nauto prints(const Head& head, const\
    \ Tail&... tail)\n    -> decltype(print << head, (void)0) {\n    print << head;\n\
    \    print.print_char(' ');\n    prints(tail...);\n}\n\nPrinter<IO_BUFFER_SIZE,\
    \ true> debug(1), edebug(2);\n\nvoid debugs() { debug.print_char('\\n'); }\n\n\
    template<class T> auto debugs(const T& v) -> decltype(debug << v, (void)0) {\n\
    \    debug << v;\n    debug.print_char('\\n');\n}\n\ntemplate<class Head, class...\
    \ Tail>\nauto debugs(const Head& head, const Tail&... tail)\n    -> decltype(debug\
    \ << head, (void)0) {\n    debug << head;\n    debug.print_char(' ');\n    debugs(tail...);\n\
    }\n#line 2 \"template/bitop.hpp\"\n\n#line 6 \"template/bitop.hpp\"\n\nnamespace\
    \ bitop {\n\n#define KTH_BIT(b, k) (((b) >> (k)) & 1)\n#define POW2(k) (1ull <<\
    \ (k))\n\ninline ull next_combination(int n, ull x) {\n    if (n == 0) return\
    \ 1;\n    ull a = x & -x;\n    ull b = x + a;\n    return (x & ~b) / a >> 1 |\
    \ b;\n}\n\n#define rep_comb(i, n, k)                                         \
    \             \\\n    for (ull i = (1ull << (k)) - 1; i < (1ull << (n));     \
    \                    \\\n         i = bitop::next_combination((n), i))\n\ninline\
    \ constexpr int msb(ull x) {\n    int res = x ? 0 : -1;\n    if (x & 0xFFFFFFFF00000000)\
    \ x &= 0xFFFFFFFF00000000, res += 32;\n    if (x & 0xFFFF0000FFFF0000) x &= 0xFFFF0000FFFF0000,\
    \ res += 16;\n    if (x & 0xFF00FF00FF00FF00) x &= 0xFF00FF00FF00FF00, res +=\
    \ 8;\n    if (x & 0xF0F0F0F0F0F0F0F0) x &= 0xF0F0F0F0F0F0F0F0, res += 4;\n   \
    \ if (x & 0xCCCCCCCCCCCCCCCC) x &= 0xCCCCCCCCCCCCCCCC, res += 2;\n    return res\
    \ + ((x & 0xAAAAAAAAAAAAAAAA) ? 1 : 0);\n}\n\ninline constexpr int ceil_log2(ull\
    \ x) { return x ? msb(x - 1) + 1 : 0; }\n\ninline constexpr ull reverse(ull x)\
    \ {\n    x = ((x & 0xAAAAAAAAAAAAAAAA) >> 1) | ((x & 0x5555555555555555) << 1);\n\
    \    x = ((x & 0xCCCCCCCCCCCCCCCC) >> 2) | ((x & 0x3333333333333333) << 2);\n\
    \    x = ((x & 0xF0F0F0F0F0F0F0F0) >> 4) | ((x & 0x0F0F0F0F0F0F0F0F) << 4);\n\
    \    x = ((x & 0xFF00FF00FF00FF00) >> 8) | ((x & 0x00FF00FF00FF00FF) << 8);\n\
    \    x = ((x & 0xFFFF0000FFFF0000) >> 16) | ((x & 0x0000FFFF0000FFFF) << 16);\n\
    \    return (x >> 32) | (x << 32);\n}\n\ninline constexpr ull reverse(ull x, int\
    \ n) { return reverse(x) >> (64 - n); }\n\n} // namespace bitop\n\ninline constexpr\
    \ int popcnt(ull x) noexcept {\n#if __cplusplus >= 202002L\n    return std::popcount(x);\n\
    #endif\n    x = (x & 0x5555555555555555) + ((x >> 1) & 0x5555555555555555);\n\
    \    x = (x & 0x3333333333333333) + ((x >> 2) & 0x3333333333333333);\n    x =\
    \ (x & 0x0f0f0f0f0f0f0f0f) + ((x >> 4) & 0x0f0f0f0f0f0f0f0f);\n    x = (x & 0x00ff00ff00ff00ff)\
    \ + ((x >> 8) & 0x00ff00ff00ff00ff);\n    x = (x & 0x0000ffff0000ffff) + ((x >>\
    \ 16) & 0x0000ffff0000ffff);\n    return (x & 0x00000000ffffffff) + ((x >> 32)\
    \ & 0x00000000ffffffff);\n}\n#line 2 \"template/func.hpp\"\n\n#line 6 \"template/func.hpp\"\
    \n\ntemplate<class T, class U, class Comp = std::less<>>\ninline constexpr bool\
    \ chmin(T& a, const U& b,\n                            Comp cmp = Comp()) noexcept(noexcept(cmp(b,\
    \ a))) {\n    return cmp(b, a) ? a = b, true : false;\n}\ntemplate<class T, class\
    \ U, class Comp = std::less<>>\ninline constexpr bool chmax(T& a, const U& b,\n\
    \                            Comp cmp = Comp()) noexcept(noexcept(cmp(a, b)))\
    \ {\n    return cmp(a, b) ? a = b, true : false;\n}\n\ninline constexpr ll gcd(ll\
    \ a, ll b) {\n    if (a < 0) a = -a;\n    if (b < 0) b = -b;\n    while (b) {\n\
    \        const ll c = a;\n        a = b;\n        b = c % b;\n    }\n    return\
    \ a;\n}\ninline constexpr ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }\n\n\
    inline constexpr bool is_prime(ll N) {\n    if (N <= 1) return false;\n    for\
    \ (ll i = 2; i * i <= N; ++i) {\n        if (N % i == 0) return false;\n    }\n\
    \    return true;\n}\ninline std::vector<ll> prime_factor(ll N) {\n    std::vector<ll>\
    \ res;\n    for (ll i = 2; i * i <= N; ++i) {\n        while (N % i == 0) {\n\
    \            res.push_back(i);\n            N /= i;\n        }\n    }\n    if\
    \ (N != 1) res.push_back(N);\n    return res;\n}\n\ninline constexpr ll my_pow(ll\
    \ a, ll b) {\n    ll res = 1;\n    while (b) {\n        if (b & 1) res *= a;\n\
    \        b >>= 1;\n        a *= a;\n    }\n    return res;\n}\ninline constexpr\
    \ ll mod_pow(ll a, ll b, ll mod) {\n    assert(mod > 0);\n    if (mod == 1) return\
    \ 0;\n    a %= mod;\n    ll res = 1;\n    while (b) {\n        if (b & 1) (res\
    \ *= a) %= mod;\n        b >>= 1;\n        (a *= a) %= mod;\n    }\n    return\
    \ res;\n}\n\ninline PLL extGCD(ll a, ll b) {\n    const ll n = a, m = b;\n   \
    \ ll x = 1, y = 0, u = 0, v = 1;\n    ll t;\n    while (b) {\n        t = a /\
    \ b;\n        std::swap(a -= t * b, b);\n        std::swap(x -= t * u, u);\n \
    \       std::swap(y -= t * v, v);\n    }\n    if (x < 0) {\n        x += m;\n\
    \        y -= n;\n    }\n    return {x, y};\n}\ninline ll mod_inv(ll a, ll mod)\
    \ {\n    ll b = mod;\n    ll x = 1, u = 0;\n    ll t;\n    while (b) {\n     \
    \   t = a / b;\n        std::swap(a -= t * b, b);\n        std::swap(x -= t *\
    \ u, u);\n    }\n    if (x < 0) x += mod;\n    assert(a == 1);\n    return x;\n\
    }\n#line 2 \"template/util.hpp\"\n\n#line 6 \"template/util.hpp\"\n\ntemplate<class\
    \ F> class RecLambda {\nprivate:\n    F f;\n\npublic:\n    explicit constexpr\
    \ RecLambda(F&& f_) : f(std::forward<F>(f_)) {}\n    template<class... Args>\n\
    \    constexpr auto operator()(Args&&... args)\n        -> decltype(f(*this, std::forward<Args>(args)...))\
    \ {\n        return f(*this, std::forward<Args>(args)...);\n    }\n};\n\ntemplate<class\
    \ F> inline constexpr RecLambda<F> rec_lambda(F&& f) {\n    return RecLambda<F>(std::forward<F>(f));\n\
    }\n\n\ntemplate<class Head, class... Tail> struct multi_dim_vector {\n    using\
    \ type = std::vector<typename multi_dim_vector<Tail...>::type>;\n};\ntemplate<class\
    \ T> struct multi_dim_vector<T> { using type = T; };\n\ntemplate<class T, class\
    \ Arg>\nconstexpr std::vector<T> make_vec(int n, Arg&& arg) {\n    return std::vector<T>(n,\
    \ std::forward<Arg>(arg));\n}\ntemplate<class T, class... Args>\nconstexpr typename\
    \ multi_dim_vector<Args..., T>::type make_vec(int n,\n                       \
    \                                        Args&&... args) {\n    return typename\
    \ multi_dim_vector<Args..., T>::type(\n        n, make_vec<T>(std::forward<Args>(args)...));\n\
    }\n\n\ntemplate<class T, class Comp = std::less<T>> class compressor {\nprivate:\n\
    \    std::vector<T> dat;\n    Comp cmp;\n    bool sorted = false;\n\npublic:\n\
    \    compressor() : compressor(Comp()) {}\n    compressor(const Comp& cmp) : cmp(cmp)\
    \ {}\n    compressor(const std::vector<T>& vec, bool f = false,\n            \
    \   const Comp& cmp = Comp())\n        : dat(vec), cmp(cmp) {\n        if (f)\
    \ build();\n    }\n    compressor(std::vector<T>&& vec, bool f = false, const\
    \ Comp& cmp = Comp())\n        : dat(std::move(vec)), cmp(cmp) {\n        if (f)\
    \ build();\n    }\n    compressor(std::initializer_list<T> il, bool f = false,\n\
    \               const Comp& cmp = Comp())\n        : dat(all(il)), cmp(cmp) {\n\
    \        if (f) build();\n    }\n    void reserve(int n) {\n        assert(!sorted);\n\
    \        dat.reserve(n);\n    }\n    void push_back(const T& v) {\n        assert(!sorted);\n\
    \        dat.push_back(v);\n    }\n    void push_back(T&& v) {\n        assert(!sorted);\n\
    \        dat.push_back(std::move(v));\n    }\n    template<class... Args> void\
    \ emplace_back(Args&&... args) {\n        assert(!sorted);\n        dat.emplace_back(std::forward<Args>(args)...);\n\
    \    }\n    void push(const std::vector<T>& vec) {\n        assert(!sorted);\n\
    \        const int n = dat.size();\n        dat.resize(n + vec.size());\n    \
    \    rep (i, vec.size()) dat[n + i] = vec[i];\n    }\n    int build() {\n    \
    \    assert(!sorted);\n        sorted = true;\n        std::sort(all(dat), cmp);\n\
    \        dat.erase(std::unique(all(dat),\n                              [&](const\
    \ T& a, const T& b) -> bool {\n                                  return !cmp(a,\
    \ b) && !cmp(b, a);\n                              }),\n                  dat.end());\n\
    \        return dat.size();\n    }\n    const T& operator[](int k) const& {\n\
    \        assert(sorted);\n        assert(0 <= k && k < (int)dat.size());\n   \
    \     return dat[k];\n    }\n    int get(const T& val) const {\n        assert(sorted);\n\
    \        auto itr = std::lower_bound(all(dat), val, cmp);\n        assert(itr\
    \ != dat.end() && !cmp(val, *itr));\n        return itr - dat.begin();\n    }\n\
    \    int lower_bound(const T& val) const {\n        assert(sorted);\n        auto\
    \ itr = std::lower_bound(all(dat), val, cmp);\n        return itr - dat.begin();\n\
    \    }\n    int upper_bound(const T& val) const {\n        assert(sorted);\n \
    \       auto itr = std::upper_bound(all(dat), val, cmp);\n        return itr -\
    \ dat.begin();\n    }\n    bool contains(const T& val) const {\n        assert(sorted);\n\
    \        return std::binary_search(all(dat), val, cmp);\n    }\n    std::vector<int>\
    \ pressed(const std::vector<T>& vec) const {\n        assert(sorted);\n      \
    \  std::vector<int> res(vec.size());\n        rep (i, vec.size()) res[i] = get(vec[i]);\n\
    \        return res;\n    }\n    void press(std::vector<T>& vec) const {\n   \
    \     assert(sorted);\n        for (auto&& i : vec) i = get(i);\n    }\n    int\
    \ size() const {\n        assert(sorted);\n        return dat.size();\n    }\n\
    };\n#line 2 \"math/PollardRho.hpp\"\n\n#line 2 \"random/Random.hpp\"\n\n#line\
    \ 4 \"random/Random.hpp\"\n\ntemplate<class Engine> class Random {\nprivate:\n\
    \    Engine rnd;\n\npublic:\n    using result_type = typename Engine::result_type;\n\
    \    Random() : Random(std::random_device{}()) {}\n    Random(result_type seed)\
    \ : rnd(seed) {}\n    result_type operator()() { return rnd(); }\n    result_type\
    \ min() const { return rnd.min(); }\n    result_type max() const { return rnd.max();\
    \ }\n    template<class IntType = ll> IntType uniform(IntType l, IntType r) {\n\
    \        static_assert(std::is_integral<IntType>::value,\n                   \
    \   \"template argument must be an integral type\");\n        assert(l <= r);\n\
    \        return std::uniform_int_distribution<IntType>{l, r}(rnd);\n    }\n  \
    \  template<class RealType = double>\n    RealType uniform_real(RealType l, RealType\
    \ r) {\n        static_assert(std::is_floating_point<RealType>::value,\n     \
    \                 \"template argument must be an floating point type\");\n   \
    \     assert(l <= r);\n        return std::uniform_real_distribution<RealType>{l,\
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
    \ * @brief Random\n * @docs docs/random/Random.md\n */\n#line 2 \"math/MontgomeryModInt.hpp\"\
    \n\n#line 4 \"math/MontgomeryModInt.hpp\"\n\ntemplate<class T> class MontgomeryReduction\
    \ {\n    static_assert(std::is_integral<T>::value, \"T must be integral\");\n\
    \    static_assert(std::is_unsigned<T>::value, \"T must be unsigned\");\n\nprivate:\n\
    \    using large_t = typename double_size_uint<T>::type;\n    static constexpr\
    \ int lg = std::numeric_limits<T>::digits;\n    T mod;\n    T r;\n    T r2; //\
    \ r^2 mod m\n    T calc_minv() {\n        T t = 0, res = 0;\n        rep (i, lg)\
    \ {\n            if (~t & 1) {\n                t += mod;\n                res\
    \ += static_cast<T>(1) << i;\n            }\n            t >>= 1;\n        }\n\
    \        return res;\n    }\n    T minv;\n\npublic:\n    MontgomeryReduction(T\
    \ v) { set_mod(v); }\n    static constexpr int get_lg() { return lg; }\n    void\
    \ set_mod(T v) {\n        assert(v > 0);\n        assert(v & 1);\n        assert(v\
    \ <= std::numeric_limits<T>::max() / 2);\n        mod = v;\n        r = (-static_cast<T>(mod))\
    \ % mod;\n        r2 = (-static_cast<large_t>(mod)) % mod;\n        minv = calc_minv();\n\
    \    }\n    inline T get_mod() const { return mod; }\n    inline T get_r() const\
    \ { return r; }\n    T reduce(large_t x) const {\n        large_t tmp =\n    \
    \        (x + static_cast<large_t>(static_cast<T>(x) * minv) * mod) >> lg;\n \
    \       return tmp >= mod ? tmp - mod : tmp;\n    }\n    T transform(large_t x)\
    \ const { return reduce(x * r2); }\n};\n\ntemplate<class T, int id> class MontgomeryModInt\
    \ {\nprivate:\n    using large_t = typename double_size_uint<T>::type;\n    using\
    \ signed_t = typename std::make_signed<T>::type;\n    T val;\n\n    static MontgomeryReduction<T>\
    \ mont;\n\npublic:\n    MontgomeryModInt() : val(0) {}\n    template<class U,\
    \ typename std::enable_if<\n                          std::is_integral<U>::value\
    \ &&\n                          std::is_unsigned<U>::value>::type* = nullptr>\n\
    \    MontgomeryModInt(U x)\n        : val(mont.transform(\n              x < (static_cast<large_t>(mont.get_mod())\
    \ << mont.get_lg())\n                  ? x\n                  : x % mont.get_mod()))\
    \ {}\n    template<class U,\n             typename std::enable_if<std::is_integral<U>::value\
    \ &&\n                                     std::is_signed<U>::value>::type* =\
    \ nullptr>\n    MontgomeryModInt(U x)\n        : MontgomeryModInt(static_cast<typename\
    \ std::make_unsigned<U>::type>(\n              x < 0 ? -x : x)) {\n        if\
    \ (x < 0 && val) val = mont.get_mod() - val;\n    }\n\n    T get() const { return\
    \ mont.reduce(val); }\n    static T get_mod() { return mont.get_mod(); }\n\n \
    \   static void set_mod(T v) { mont.set_mod(v); }\n\n    MontgomeryModInt operator+()\
    \ const { return *this; }\n    MontgomeryModInt operator-() const {\n        MontgomeryModInt\
    \ res;\n        if (val) res.val = mont.get_mod() - val;\n        return res;\n\
    \    }\n    MontgomeryModInt& operator++() {\n        val += mont.get_r();\n \
    \       if (val >= mont.get_mod()) val -= mont.get_mod();\n        return *this;\n\
    \    }\n    MontgomeryModInt& operator--() {\n        if (val < mont.get_r())\
    \ val += mont.get_mod();\n        val -= mont.get_r();\n        return *this;\n\
    \    }\n    MontgomeryModInt operator++(int) {\n        MontgomeryModInt res =\
    \ *this;\n        ++*this;\n        return res;\n    }\n    MontgomeryModInt operator--(int)\
    \ {\n        MontgomeryModInt res = *this;\n        --*this;\n        return res;\n\
    \    }\n\n    MontgomeryModInt& operator+=(const MontgomeryModInt& rhs) {\n  \
    \      val += rhs.val;\n        if (val >= mont.get_mod()) val -= mont.get_mod();\n\
    \        return *this;\n    }\n    MontgomeryModInt& operator-=(const MontgomeryModInt&\
    \ rhs) {\n        if (val < rhs.val) val += mont.get_mod();\n        val -= rhs.val;\n\
    \        return *this;\n    }\n    MontgomeryModInt& operator*=(const MontgomeryModInt&\
    \ rhs) {\n        val = mont.reduce(static_cast<large_t>(val) * rhs.val);\n  \
    \      return *this;\n    }\n\n    MontgomeryModInt pow(ull n) const {\n     \
    \   MontgomeryModInt res = 1, x = *this;\n        while (n) {\n            if\
    \ (n & 1) res *= x;\n            x *= x;\n            n >>= 1;\n        }\n  \
    \      return res;\n    }\n    MontgomeryModInt inv() const { return pow(mont.get_mod()\
    \ - 2); }\n\n    MontgomeryModInt& operator/=(const MontgomeryModInt& rhs) {\n\
    \        return *this *= rhs.inv();\n    }\n\n    friend MontgomeryModInt operator+(const\
    \ MontgomeryModInt& lhs,\n                                      const MontgomeryModInt&\
    \ rhs) {\n        return MontgomeryModInt(lhs) += rhs;\n    }\n    friend MontgomeryModInt\
    \ operator-(const MontgomeryModInt& lhs,\n                                   \
    \   const MontgomeryModInt& rhs) {\n        return MontgomeryModInt(lhs) -= rhs;\n\
    \    }\n    friend MontgomeryModInt operator*(const MontgomeryModInt& lhs,\n \
    \                                     const MontgomeryModInt& rhs) {\n       \
    \ return MontgomeryModInt(lhs) *= rhs;\n    }\n    friend MontgomeryModInt operator/(const\
    \ MontgomeryModInt& lhs,\n                                      const MontgomeryModInt&\
    \ rhs) {\n        return MontgomeryModInt(lhs) /= rhs;\n    }\n\n    friend bool\
    \ operator==(const MontgomeryModInt& lhs,\n                           const MontgomeryModInt&\
    \ rhs) {\n        return lhs.val == rhs.val;\n    }\n    friend bool operator!=(const\
    \ MontgomeryModInt& lhs,\n                           const MontgomeryModInt& rhs)\
    \ {\n        return lhs.val != rhs.val;\n    }\n\n    template<class Pr> void\
    \ print(Pr& a) const { a.print(mont.reduce(val)); }\n    template<class Pr> void\
    \ debug(Pr& a) const { a.print(mont.reduce(val)); }\n    template<class Sc> void\
    \ scan(Sc& a) {\n        ll v;\n        a.scan(v);\n        *this = v;\n    }\n\
    };\n\ntemplate<class T, int id>\nMontgomeryReduction<T>\n    MontgomeryModInt<T,\
    \ id>::mont = MontgomeryReduction<T>(998244353);\n\nusing mmodint = MontgomeryModInt<unsigned\
    \ int, -1>;\n\n/**\n * @brief MontgomeryModInt(\u30E2\u30F3\u30B4\u30E1\u30EA\u4E57\
    \u7B97)\n * @docs docs/math/MontgomeryModInt.md\n */\n#line 2 \"math/MillerRabin.hpp\"\
    \n\n#line 5 \"math/MillerRabin.hpp\"\n\nconstexpr ull base_miller_rabin_int[3]\
    \ = {2, 7, 61};\nconstexpr ull base_miller_rabin_ll[7] = {2,      325,     9375,\
    \      28178,\n                                         450775, 9780504, 1795265022};\n\
    \ntemplate<class T> constexpr bool miller_rabin(ull n, const ull base[], int s)\
    \ {\n    if (T::get_mod() != n) T::set_mod(n);\n    ull d = n - 1;\n    while\
    \ (~d & 1) d >>= 1;\n    T e{1}, re{n - 1};\n    rep (i, s) {\n        ull a =\
    \ base[i];\n        if (a >= n) return true;\n        ull t = d;\n        T y\
    \ = T(a).pow(t);\n        while (t != n - 1 && y != e && y != re) {\n        \
    \    y *= y;\n            t <<= 1;\n        }\n        if (y != re && !(t & 1))\
    \ return false;\n    }\n    return true;\n}\n\nconstexpr bool is_prime_mr(ll n)\
    \ {\n    if (n == 2) return true;\n    if (n < 2 || n % 2 == 0) return false;\n\
    \    if (n < (1u << 31))\n        return miller_rabin<MontgomeryModInt<unsigned\
    \ int, -2>>(\n            n, base_miller_rabin_int, 3);\n    return miller_rabin<MontgomeryModInt<ull,\
    \ -2>>(n, base_miller_rabin_ll, 7);\n}\n\n#if __cpp_variable_templates >= 201304L\
    \ && __cpp_constexpr >= 201304L\ntemplate<ull n> constexpr bool is_prime_v = is_prime_mr(n);\n\
    #endif\n\n/**\n * @brief MillerRabin(\u30DF\u30E9\u30FC\u30E9\u30D3\u30F3\u7D20\
    \u6570\u5224\u5B9A)\n * @docs docs/math/MillerRabin.md\n */\n#line 2 \"string/RunLength.hpp\"\
    \n\n#line 4 \"string/RunLength.hpp\"\n\ntemplate<class Cont, class Comp>\nstd::vector<std::pair<typename\
    \ Cont::value_type, int>>\nRunLength(const Cont& str, const Comp& cmp) {\n   \
    \ std::vector<std::pair<typename Cont::value_type, int>> res;\n    if (str.size()\
    \ == 0) return res;\n    res.emplace_back(str[0], 1);\n    rep (i, 1, str.size())\
    \ {\n        if (cmp(res.back().first, str[i])) ++res.back().second;\n       \
    \ else res.emplace_back(str[i], 1);\n    }\n    return res;\n}\n\ntemplate<class\
    \ Cont>\nstd::vector<std::pair<typename Cont::value_type, int>>\nRunLength(const\
    \ Cont& str) {\n    return RunLength(str, std::equal_to<typename Cont::value_type>());\n\
    }\n\n/**\n * @brief RunLength(\u30E9\u30F3\u30EC\u30F3\u30B0\u30B9\u5727\u7E2E\
    )\n * @docs docs/string/RunLength.md\n */\n#line 8 \"math/PollardRho.hpp\"\n\n\
    template<class T, class Rnd> ull pollard_rho(ull n, Rnd& rnd) {\n    if (~n &\
    \ 1) return 2;\n    if (T::get_mod() != n) T::set_mod(n);\n    T c, one = 1;\n\
    \    auto f = [&](T x) -> T { return x * x + c; };\n    constexpr int M = 128;\n\
    \    while (1) {\n        c = rnd.uniform(1ull, n - 1);\n        T x = rnd.uniform(2ull,\
    \ n - 1), y = x;\n        ull g = 1;\n        while (g == 1) {\n            T\
    \ p = one, tx = x, ty = y;\n            rep (M) {\n                x = f(x);\n\
    \                y = f(f(y));\n                p *= x - y;\n            }\n  \
    \          g = gcd(p.get(), n);\n            if (g == 1) continue;\n         \
    \   rep (M) {\n                tx = f(tx);\n                ty = f(f(ty));\n \
    \               g = gcd((tx - ty).get(), n);\n                if (g != 1) {\n\
    \                    if (g != n) return g;\n                    break;\n     \
    \           }\n            }\n        }\n    }\n    return -1;\n}\n\ntemplate<class\
    \ T = MontgomeryModInt<ull, -3>, class Rnd = Random64>\nstd::vector<ull> factorize(ull\
    \ n, Rnd& rnd = rand64) {\n    if (n == 1) return {};\n    std::vector<ull> res;\n\
    \    std::vector<ull> st = {n};\n    while (!st.empty()) {\n        ull t = st.back();\n\
    \        st.pop_back();\n        if (t == 1) continue;\n        if (is_prime_mr(t))\
    \ {\n            res.push_back(t);\n            continue;\n        }\n       \
    \ ull f = pollard_rho<T>(t, rnd);\n        st.push_back(f);\n        st.push_back(t\
    \ / f);\n    }\n    std::sort(all(res));\n    return res;\n}\n\ntemplate<class\
    \ T = MontgomeryModInt<ull, -3>, class Rnd = Random64>\nstd::vector<std::pair<ull,\
    \ int>> expfactorize(ull n, Rnd& rnd = rand64) {\n    auto f = factorize<T, Rnd>(n,\
    \ rnd);\n    return RunLength(f);\n}\n\nstd::vector<ll> divisors_pr(ll n) {\n\
    \    std::vector<ll> res;\n    auto r = expfactorize(n);\n    int m = r.size();\n\
    \    rec_lambda([&](auto&& self, int k, ll d) -> void {\n        if (k == m) {\n\
    \            res.push_back(d);\n            return;\n        }\n        ll t =\
    \ d;\n        rep (r[k].second) {\n            self(k + 1, d);\n            d\
    \ *= r[k].first;\n        }\n        self(k + 1, d);\n        d = t;\n    })(0,\
    \ 1);\n    std::sort(all(res));\n    return res;\n}\n\n/**\n * @brief PollardRho(\u7D20\
    \u56E0\u6570\u5206\u89E3)\n * @docs docs/math/PollardRho.md\n */\n#line 5 \"math/EulerPhi.hpp\"\
    \n\nll euler_phi(ll n) {\n    ll res = n;\n    for (ll i = 2; i * i <= n; ++i)\
    \ {\n        if (n % i == 0) {\n            res = res / i * (i - 1);\n       \
    \     while (n % i == 0) n /= i;\n        }\n    }\n    if (n != 1) res = res\
    \ / n * (n - 1);\n    return res;\n}\n\nll euler_phi_pollardrho(ll n) {\n    for\
    \ (auto p : expfactorize(n)) n = n / p.first * (p.first - 1);\n    return n;\n\
    }\n\nclass EulerPhi {\nprivate:\n    ll MAX;\n    std::vector<ll> data;\n\npublic:\n\
    \    EulerPhi(ll MAX) : MAX(MAX), data(MAX + 1, 0) {\n        rep (i, MAX + 1)\
    \ data[i] = i;\n        rep (i, 2, MAX + 1) {\n            if (data[i] != i) continue;\n\
    \            rep (j, i, MAX + 1, i) {\n                data[j] = data[j] / i *\
    \ (i - 1);\n            }\n        }\n    }\n    ll phi(ll x) { return data[x];\
    \ }\n};\n\n/**\n * @brief Euler's-Phi(\u30AA\u30A4\u30E9\u30FC\u306E\u03C6\u95A2\
    \u6570)\n * @docs docs/math/EulerPhi.md\n */\n"
  code: "#pragma once\n\n#include \"../other/template.hpp\"\n#include \"PollardRho.hpp\"\
    \n\nll euler_phi(ll n) {\n    ll res = n;\n    for (ll i = 2; i * i <= n; ++i)\
    \ {\n        if (n % i == 0) {\n            res = res / i * (i - 1);\n       \
    \     while (n % i == 0) n /= i;\n        }\n    }\n    if (n != 1) res = res\
    \ / n * (n - 1);\n    return res;\n}\n\nll euler_phi_pollardrho(ll n) {\n    for\
    \ (auto p : expfactorize(n)) n = n / p.first * (p.first - 1);\n    return n;\n\
    }\n\nclass EulerPhi {\nprivate:\n    ll MAX;\n    std::vector<ll> data;\n\npublic:\n\
    \    EulerPhi(ll MAX) : MAX(MAX), data(MAX + 1, 0) {\n        rep (i, MAX + 1)\
    \ data[i] = i;\n        rep (i, 2, MAX + 1) {\n            if (data[i] != i) continue;\n\
    \            rep (j, i, MAX + 1, i) {\n                data[j] = data[j] / i *\
    \ (i - 1);\n            }\n        }\n    }\n    ll phi(ll x) { return data[x];\
    \ }\n};\n\n/**\n * @brief Euler's-Phi(\u30AA\u30A4\u30E9\u30FC\u306E\u03C6\u95A2\
    \u6570)\n * @docs docs/math/EulerPhi.md\n */\n"
  dependsOn:
  - other/template.hpp
  - template/macros.hpp
  - template/alias.hpp
  - template/type_traits.hpp
  - template/in.hpp
  - template/out.hpp
  - template/bitop.hpp
  - template/func.hpp
  - template/util.hpp
  - math/PollardRho.hpp
  - random/Random.hpp
  - math/MontgomeryModInt.hpp
  - math/MillerRabin.hpp
  - string/RunLength.hpp
  isVerificationFile: false
  path: math/EulerPhi.hpp
  requiredBy:
  - math/TetrationMod.hpp
  timestamp: '2024-05-12 00:53:40+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/math/tetration_mod.test.cpp
  - test/aoj/NTL/NTL_1_D-Phi.test.cpp
documentation_of: math/EulerPhi.hpp
layout: document
redirect_from:
- /library/math/EulerPhi.hpp
- /library/math/EulerPhi.hpp.html
title: "Euler's-Phi(\u30AA\u30A4\u30E9\u30FC\u306E\u03C6\u95A2\u6570)"
---
## 概要

オイラーの $\phi$ 関数。読み方はトーシェント、ファイなど。

- `ll euler_phi(ll N)` : $\phi(N)$ を返す。 $\Theta(\sqrt N)$ 。
- `ll euler_phi_pollardrho(ll N)` : $\phi(N)$ を返す。素因数分解に Pollard の Rho 法を用いている。計算量は PollardRho 参照。

また、エラトステネスの篩を応用して、多くのクエリに効率よく答えることもできる。

- `EulerPhi(ll N)` : `N` 以下の $\phi$ 関数のテーブルを作る。 $\Theta(N\log\log N)$ 。
- `ll phi(ll x)` : $\phi(x)$ を返す。 $\Theta(1)$ 。
