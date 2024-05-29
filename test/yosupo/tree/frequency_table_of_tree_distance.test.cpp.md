---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/Graph.hpp
    title: Graph-template
  - icon: ':x:'
    path: graph/tree/FrequencyTableofTreeDistance.hpp
    title: Frequency Table of Tree Distance
  - icon: ':question:'
    path: graph/tree/TreeCentroid.hpp
    title: "TreeCentroid(\u6728\u306E\u91CD\u5FC3)"
  - icon: ':x:'
    path: math/ChineseRemainder.hpp
    title: "Chinese Remainder(\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406)"
  - icon: ':question:'
    path: math/ModInt.hpp
    title: ModInt
  - icon: ':question:'
    path: math/convolution/Convolution.hpp
    title: "Convolution(\u7573\u307F\u8FBC\u307F)"
  - icon: ':question:'
    path: other/template.hpp
    title: other/template.hpp
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
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
    links:
    - https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
  bundledCode: "#line 1 \"test/yosupo/tree/frequency_table_of_tree_distance.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\
    \n#line 2 \"other/template.hpp\"\n\n#include <bits/stdc++.h>\n#line 2 \"template/macros.hpp\"\
    \n\n#line 4 \"template/macros.hpp\"\n\n#ifndef __COUNTER__\n#define __COUNTER__\
    \ __LINE__\n#endif\n\n#define OVERLOAD5(a, b, c, d, e, ...) e\n#define REP1_0(b,\
    \ c) REP1_1(b, c)\n#define REP1_1(b, c)                                      \
    \                     \\\n    for (ll REP_COUNTER_##c = 0; REP_COUNTER_##c < (ll)(b);\
    \ ++REP_COUNTER_##c)\n#define REP1(b) REP1_0(b, __COUNTER__)\n#define REP2(i,\
    \ b) for (ll i = 0; i < (ll)(b); ++i)\n#define REP3(i, a, b) for (ll i = (ll)(a);\
    \ i < (ll)(b); ++i)\n#define REP4(i, a, b, c) for (ll i = (ll)(a); i < (ll)(b);\
    \ i += (ll)(c))\n#define rep(...) OVERLOAD5(__VA_ARGS__, REP4, REP3, REP2, REP1)(__VA_ARGS__)\n\
    #define RREP2(i, a) for (ll i = (ll)(a)-1; i >= 0; --i)\n#define RREP3(i, a, b)\
    \ for (ll i = (ll)(a)-1; i >= (ll)(b); --i)\n#define RREP4(i, a, b, c) for (ll\
    \ i = (ll)(a)-1; i >= (ll)(b); i -= (ll)(c))\n#define rrep(...) OVERLOAD5(__VA_ARGS__,\
    \ RREP4, RREP3, RREP2)(__VA_ARGS__)\n#define REPS2(i, b) for (ll i = 1; i <= (ll)(b);\
    \ ++i)\n#define REPS3(i, a, b) for (ll i = (ll)(a) + 1; i <= (ll)(b); ++i)\n#define\
    \ REPS4(i, a, b, c) for (ll i = (ll)(a) + 1; i <= (ll)(b); i += (ll)(c))\n#define\
    \ reps(...) OVERLOAD5(__VA_ARGS__, REPS4, REPS3, REPS2)(__VA_ARGS__)\n#define\
    \ RREPS2(i, a) for (ll i = (ll)(a); i > 0; --i)\n#define RREPS3(i, a, b) for (ll\
    \ i = (ll)(a); i > (ll)(b); --i)\n#define RREPS4(i, a, b, c) for (ll i = (ll)(a);\
    \ i > (ll)(b); i -= (ll)(c))\n#define rreps(...) OVERLOAD5(__VA_ARGS__, RREPS4,\
    \ RREPS3, RREPS2)(__VA_ARGS__)\n\n#define each_for(...) for (auto&& __VA_ARGS__)\n\
    #define each_const(...) for (const auto& __VA_ARGS__)\n\n#define all(v) std::begin(v),\
    \ std::end(v)\n#define rall(v) std::rbegin(v), std::rend(v)\n\n#if __cpp_if_constexpr\
    \ >= 201606L\n#define IF_CONSTEXPR constexpr\n#else\n#define IF_CONSTEXPR\n#endif\n\
    \n#define IO_BUFFER_SIZE (1 << 17)\n#line 2 \"template/alias.hpp\"\n\n#line 4\
    \ \"template/alias.hpp\"\n\nusing ll = long long;\nusing uint = unsigned int;\n\
    using ull = unsigned long long;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    using ld = long double;\nusing PLL = std::pair<ll, ll>;\ntemplate<class T>\nusing\
    \ prique = std::priority_queue<T, std::vector<T>, std::greater<T>>;\n\ntemplate<class\
    \ T> struct infinity {\n    static constexpr T value = std::numeric_limits<T>::max()\
    \ / 2;\n    static constexpr T mvalue = std::numeric_limits<T>::lowest() / 2;\n\
    \    static constexpr T max = std::numeric_limits<T>::max();\n    static constexpr\
    \ T min = std::numeric_limits<T>::lowest();\n};\n\n#if __cplusplus <= 201402L\n\
    template<class T> constexpr T infinity<T>::value;\ntemplate<class T> constexpr\
    \ T infinity<T>::mvalue;\ntemplate<class T> constexpr T infinity<T>::max;\ntemplate<class\
    \ T> constexpr T infinity<T>::min;\n#endif\n\n#if __cpp_variable_templates >=\
    \ 201304L\ntemplate<class T> constexpr T INF = infinity<T>::value;\n#endif\n\n\
    constexpr ll inf = infinity<ll>::value;\nconstexpr ld EPS = 1e-8;\nconstexpr ld\
    \ PI = 3.1415926535897932384626;\n#line 2 \"template/type_traits.hpp\"\n\n#line\
    \ 5 \"template/type_traits.hpp\"\n\ntemplate<class T, class... Args> struct function_traits_impl\
    \ {\n    using result_type = T;\n    template<std::size_t idx>\n    using argument_type\
    \ =\n        typename std::tuple_element<idx, std::tuple<Args...>>::type;\n  \
    \  using argument_tuple = std::tuple<Args...>;\n    static constexpr std::size_t\
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
    #line 8 \"template/in.hpp\"\n\ntemplate<std::size_t buf_size = IO_BUFFER_SIZE,\n\
    \         std::size_t decimal_precision = 16>\nclass Scanner {\nprivate:\n   \
    \ template<class, class = void> struct has_scan : std::false_type {};\n    template<class\
    \ T>\n    struct has_scan<\n        T, decltype(std::declval<T>().scan(std::declval<Scanner&>()),\
    \ (void)0)>\n        : std::true_type {};\n    int fd;\n    int idx, sz;\n   \
    \ bool state;\n    std::array<char, IO_BUFFER_SIZE + 1> buffer;\n    inline char\
    \ cur() {\n        if (idx == sz) load();\n        if (idx == sz) {\n        \
    \    state = false;\n            return '\\0';\n        }\n        return buffer[idx];\n\
    \    }\n    inline void next() {\n        if (idx == sz) load();\n        if (idx\
    \ == sz) return;\n        ++idx;\n    }\n\npublic:\n    inline void load() {\n\
    \        int len = sz - idx;\n        if (idx < len) return;\n        std::memcpy(buffer.begin(),\
    \ buffer.begin() + idx, len);\n        sz = len + read(fd, buffer.data() + len,\
    \ buf_size - len);\n        buffer[sz] = 0;\n        idx = 0;\n    }\n\n    Scanner(int\
    \ fd) : fd(fd), idx(0), sz(0), state(true) {}\n    Scanner(FILE* fp) : fd(fileno(fp)),\
    \ idx(0), sz(0), state(true) {}\n\n    inline char scan_char() {\n        if (idx\
    \ == sz) load();\n        return idx == sz ? '\\0' : buffer[idx++];\n    }\n\n\
    \    Scanner ignore(int n = 1) {\n        if (idx + n > sz) load();\n        idx\
    \ += n;\n        return *this;\n    }\n\n    inline void discard_space() {\n \
    \       if (idx == sz) load();\n        while (('\\t' <= buffer[idx] && buffer[idx]\
    \ <= '\\r') ||\n               buffer[idx] == ' ') {\n            if (++idx ==\
    \ sz) load();\n        }\n    }\n    void scan(char& a) {\n        discard_space();\n\
    \        a = scan_char();\n    }\n    void scan(bool& a) {\n        discard_space();\n\
    \        a = scan_char() != '0';\n    }\n    void scan(std::string& a) {\n   \
    \     discard_space();\n        a.clear();\n        while (cur() != '\\0' && (buffer[idx]\
    \ < '\\t' || '\\r' < buffer[idx]) &&\n               buffer[idx] != ' ') {\n \
    \           a += scan_char();\n        }\n    }\n    template<std::size_t len>\
    \ void scan(std::bitset<len>& a) {\n        discard_space();\n        if (idx\
    \ + len > sz) load();\n        rrep (i, len) a[i] = buffer[idx++] != '0';\n  \
    \  }\n    template<class T,\n             typename std::enable_if<is_signed_int<T>::value\
    \ &&\n                                     !has_scan<T>::value>::type* = nullptr>\n\
    \    void scan(T& a) {\n        discard_space();\n        if (buffer[idx] == '-')\
    \ {\n            ++idx;\n            if (idx + 40 > sz &&\n                (idx\
    \ == sz || ('0' <= buffer[sz - 1] && buffer[sz - 1] <= '9')))\n              \
    \  load();\n            a = 0;\n            while ('0' <= buffer[idx] && buffer[idx]\
    \ <= '9') {\n                a = a * 10 - (buffer[idx++] - '0');\n           \
    \ }\n        }\n        else {\n            if (idx + 40 > sz && '0' <= buffer[sz\
    \ - 1] && buffer[sz - 1] <= '9')\n                load();\n            a = 0;\n\
    \            while ('0' <= buffer[idx] && buffer[idx] <= '9') {\n            \
    \    a = a * 10 + (buffer[idx++] - '0');\n            }\n        }\n    }\n  \
    \  template<class T,\n             typename std::enable_if<is_unsigned_int<T>::value\
    \ &&\n                                     !has_scan<T>::value>::type* = nullptr>\n\
    \    void scan(T& a) {\n        discard_space();\n        if (idx + 40 > sz &&\
    \ '0' <= buffer[sz - 1] && buffer[sz - 1] <= '9')\n            load();\n     \
    \   a = 0;\n        while ('0' <= buffer[idx] && buffer[idx] <= '9') {\n     \
    \       a = a * 10 + (buffer[idx++] - '0');\n        }\n    }\n    template<class\
    \ T,\n             typename std::enable_if<std::is_floating_point<T>::value &&\n\
    \                                     !has_scan<T>::value>::type* = nullptr>\n\
    \    void scan(T& a) {\n        discard_space();\n        bool sgn = false;\n\
    \        if (cur() == '-') {\n            sgn = true;\n            next();\n \
    \       }\n        a = 0;\n        while ('0' <= cur() && cur() <= '9') {\n  \
    \          a = a * 10 + cur() - '0';\n            next();\n        }\n       \
    \ if (cur() == '.') {\n            next();\n            T n = 0, d = 1;\n    \
    \        for (int i = 0;\n                 '0' <= cur() && cur() <= '9' && i <\
    \ (int)decimal_precision;\n                 ++i) {\n                n = n * 10\
    \ + cur() - '0';\n                d *= 10;\n                next();\n        \
    \    }\n            while ('0' <= cur() && cur() <= '9') next();\n           \
    \ a += n / d;\n        }\n        if (sgn) a = -a;\n    }\n\nprivate:\n    template<std::size_t\
    \ i, class... Args> void scan(std::tuple<Args...>& a) {\n        if IF_CONSTEXPR\
    \ (i < sizeof...(Args)) {\n            scan(std::get<i>(a));\n            scan<i\
    \ + 1, Args...>(a);\n        }\n    }\n\npublic:\n    template<class... Args>\
    \ void scan(std::tuple<Args...>& a) {\n        scan<0, Args...>(a);\n    }\n \
    \   template<class T, class U> void scan(std::pair<T, U>& a) {\n        scan(a.first);\n\
    \        scan(a.second);\n    }\n    template<class T,\n             typename\
    \ std::enable_if<is_range<T>::value &&\n                                     !has_scan<T>::value>::type*\
    \ = nullptr>\n    void scan(T& a) {\n        for (auto&& i : a) scan(i);\n   \
    \ }\n    template<class T,\n             typename std::enable_if<has_scan<T>::value>::type*\
    \ = nullptr>\n    void scan(T& a) {\n        a.scan(*this);\n    }\n\n    void\
    \ operator()() {}\n    template<class Head, class... Args>\n    void operator()(Head&\
    \ head, Args&... args) {\n        scan(head);\n        operator()(args...);\n\
    \    }\n\n    template<class T> Scanner& operator>>(T& a) {\n        scan(a);\n\
    \        return *this;\n    }\n\n    explicit operator bool() const { return state;\
    \ }\n\n    friend Scanner& getline(Scanner& scan, std::string& a) {\n        a.erase();\n\
    \        char c;\n        if ((c = scan.scan_char()) == '\\n' || c == '\\0') return\
    \ scan;\n        a += c;\n        while ((c = scan.scan_char()) != '\\n' && c\
    \ != '\\0') a += c;\n        scan.state = true;\n        return scan;\n    }\n\
    };\n\nScanner<> scan(0);\n#line 2 \"template/out.hpp\"\n\n#line 8 \"template/out.hpp\"\
    \n\nstruct NumberToString {\n    char buf[10000][4];\n    constexpr NumberToString()\
    \ : buf{} {\n        rep (i, 10000) {\n            int n = i;\n            rrep\
    \ (j, 4) {\n                buf[i][j] = (char)('0' + n % 10);\n              \
    \  n /= 10;\n            }\n        }\n    }\n} constexpr precalc_number_to_string;\n\
    \ntemplate<std::size_t buf_size = IO_BUFFER_SIZE, bool debug = false>\nclass Printer\
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
    \ + idx, precalc_number_to_string.buf[a],\n                        4);\n     \
    \       idx += 4;\n        }\n        else if (a >= 100) {\n            std::memcpy(buffer.begin()\
    \ + idx,\n                        precalc_number_to_string.buf[a] + 1, 3);\n \
    \           idx += 3;\n        }\n        else if (a >= 10) {\n            std::memcpy(buffer.begin()\
    \ + idx,\n                        precalc_number_to_string.buf[a] + 2, 2);\n \
    \           idx += 2;\n        }\n        else {\n            buffer[idx++] =\
    \ '0' | a;\n        }\n        std::memcpy(buffer.begin() + idx, s + t, 40 - t);\n\
    \        idx += 40 - t;\n    }\n    template<class T,\n             typename std::enable_if<std::is_floating_point<T>::value\
    \ &&\n                                     !has_print<T>::value>::type* = nullptr>\n\
    \    void print(T a) {\n        if (a == std::numeric_limits<T>::infinity()) {\n\
    \            print(\"inf\");\n            return;\n        }\n        if (a ==\
    \ -std::numeric_limits<T>::infinity()) {\n            print(\"-inf\");\n     \
    \       return;\n        }\n        if (std::isnan(a)) {\n            print(\"\
    nan\");\n            return;\n        }\n        if (a < 0) {\n            print_char('-');\n\
    \            a = -a;\n        }\n        T b = a;\n        if (b < 1) {\n    \
    \        print_char('0');\n        }\n        else {\n            std::string\
    \ s;\n            while (b >= 1) {\n                s += (char)('0' + (int)std::fmod(b,\
    \ 10.0));\n                b /= 10;\n            }\n            for (auto i =\
    \ s.rbegin(); i != s.rend(); ++i) print_char(*i);\n        }\n        print_char('.');\n\
    \        rep (decimal_precision) {\n            a *= 10;\n            print_char((char)('0'\
    \ + (int)std::fmod(a, 10.0)));\n        }\n    }\n\nprivate:\n    template<std::size_t\
    \ i, class... Args>\n    void print(const std::tuple<Args...>& a) {\n        if\
    \ IF_CONSTEXPR (i < sizeof...(Args)) {\n            if IF_CONSTEXPR (debug) print_char(',');\n\
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
    };\n#line 2 \"graph/Graph.hpp\"\n\n#line 4 \"graph/Graph.hpp\"\n\ntemplate<class\
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
    \   rep (i, N) res[i][i] = 0;\n    rep (i, N) {\n        for (const auto& e :\
    \ G[i]) res[i][e.to] = e.cost;\n    }\n    return res;\n}\n\ntemplate<class T>\
    \ Edges<T> UndirectedListToEdges(const Graph<T>& G) {\n    const int V = G.size();\n\
    \    const int E = G.edge_size();\n    Edges<T> Ed(E);\n    rep (i, V) {\n   \
    \     for (const auto& e : G[i]) Ed[e.idx] = e;\n    }\n    return Ed;\n}\n\n\
    template<class T> Edges<T> DirectedListToEdges(const Graph<T>& G) {\n    const\
    \ int V = G.size();\n    const int E = std::accumulate(\n        all(G), 0, [](int\
    \ a, const std::vector<edge<T>>& v) -> int {\n            return a + v.size();\n\
    \        });\n    Edges<T> Ed(G.edge_size());\n    Ed.reserve(E);\n    rep (i,\
    \ V) {\n        for (const auto& e : G[i]) {\n            if (Ed[e.idx] == -1)\
    \ Ed[e.idx] = e;\n            else Ed.push_back(e);\n        }\n    }\n    return\
    \ Ed;\n}\n\ntemplate<class T> Graph<T> ReverseGraph(const Graph<T>& G) {\n   \
    \ const int V = G.size();\n    Graph<T> res(V);\n    rep (i, V) {\n        for\
    \ (const auto& e : G[i]) {\n            res[e.to].emplace_back(e.to, e.from, e.cost,\
    \ e.idx);\n        }\n    }\n    res.edge_id = G.edge_size();\n    return res;\n\
    }\n\n\nstruct unweighted_edge {\n    template<class... Args> unweighted_edge(const\
    \ Args&...) {}\n    operator int() { return 1; }\n};\n\nusing UnweightedGraph\
    \ = Graph<unweighted_edge>;\n\n/**\n * @brief Graph-template\n * @docs docs/graph/Graph.md\n\
    \ */\n#line 2 \"graph/tree/FrequencyTableofTreeDistance.hpp\"\n\n#line 2 \"math/ChineseRemainder.hpp\"\
    \n\n#line 4 \"math/ChineseRemainder.hpp\"\n\nPLL ChineseRemainder(ll b1, ll m1,\
    \ ll b2, ll m2) {\n    const PLL p = extGCD(m1, m2);\n    const ll g = p.first\
    \ * m1 + p.second * m2;\n    const ll l = m1 / g * m2;\n    if ((b2 - b1) % g\
    \ != 0) return PLL{-1, -1};\n    const ll x = (b2 - b1) / g * p.first % (m2 /\
    \ g);\n    return {(x * m1 + b1 + l) % l, l};\n}\nPLL ChineseRemainder(const std::vector<ll>&\
    \ b, const std::vector<ll>& m) {\n    PLL res{0, 1};\n    rep (i, b.size()) {\n\
    \        res = ChineseRemainder(res.first, res.second, b[i], m[i]);\n        if\
    \ (res.first == -1) return res;\n    }\n    return res;\n}\n\nPLL Garner(std::vector<ll>\
    \ b, std::vector<ll> m, ll MOD) {\n    const int n = b.size();\n    rep (i, n)\
    \ {\n        rep (j, i) {\n            ll g = gcd(m[i], m[j]);\n            if\
    \ ((b[i] - b[j]) % g != 0) return PLL{-1, -1};\n            m[i] /= g;\n     \
    \       m[j] /= g;\n            ll gi = gcd(m[i], g), gj = g / gi;\n         \
    \   for (g = gcd(gi, gj); g != 1; g = gcd(gi, gj)) {\n                gi *= g;\n\
    \                gj /= g;\n            }\n            m[i] *= gi;\n          \
    \  m[j] *= gj;\n            b[i] %= m[i];\n            b[j] %= m[j];\n       \
    \ }\n    }\n    m.push_back(MOD);\n    std::vector<ll> ans(n + 1), pr(n + 1, 1);\n\
    \    rep (i, n) {\n        ll t = (b[i] - ans[i]) * mod_inv(pr[i], m[i]) % m[i];\n\
    \        if (t < 0) t += m[i];\n        rep (j, i + 1, n + 1) {\n            (ans[j]\
    \ += t * pr[j]) %= m[j];\n            (pr[j] *= m[i]) %= m[j];\n        }\n  \
    \  }\n    return {ans[n], pr[n]};\n}\n\n/**\n * @brief Chinese Remainder(\u4E2D\
    \u56FD\u5270\u4F59\u5B9A\u7406)\n * @docs docs/math/ChineseRemainder.md\n * @see\
    \ https://qiita.com/drken/items/ae02240cd1f8edfc86fd\n */\n#line 2 \"math/ModInt.hpp\"\
    \n\n#line 4 \"math/ModInt.hpp\"\n\ntemplate<class T, T mod> class StaticModInt\
    \ {\n    static_assert(std::is_integral<T>::value, \"T must be integral\");\n\
    \    static_assert(std::is_unsigned<T>::value, \"T must be unsigned\");\n    static_assert(mod\
    \ > 0, \"mod must be positive\");\n    static_assert(mod <= std::numeric_limits<T>::max()\
    \ / 2,\n                  \"mod * 2 must be less than or equal to T::max()\");\n\
    \nprivate:\n    using large_t = typename double_size_uint<T>::type;\n    using\
    \ signed_t = typename std::make_signed<T>::type;\n    T val;\n    static constexpr\
    \ unsigned int inv1000000007[] = {\n        0,         1,         500000004, 333333336,\
    \ 250000002, 400000003,\n        166666668, 142857144, 125000001, 111111112, 700000005};\n\
    \    static constexpr unsigned int inv998244353[] = {\n        0,         1, \
    \        499122177, 332748118, 748683265, 598946612,\n        166374059, 855638017,\
    \ 873463809, 443664157, 299473306};\n\n    static constexpr ll mod_inv(ll a) {\n\
    \        ll b = mod;\n        ll x = 1, u = 0;\n        ll t = 0, tmp = 0;\n \
    \       while (b) {\n            t = a / b;\n            tmp = (a - t * b);\n\
    \            a = b;\n            b = tmp;\n            tmp = (x - t * u);\n  \
    \          x = u;\n            u = tmp;\n        }\n        if (x < 0) x += mod;\n\
    \        return x;\n    }\n\npublic:\n    constexpr StaticModInt() : val(0) {}\n\
    \    template<class U,\n             typename std::enable_if<std::is_integral<U>::value\
    \ &&\n                                     std::is_signed<U>::value>::type* =\
    \ nullptr>\n    constexpr StaticModInt(U v) : val{} {\n        v %= static_cast<signed_t>(mod);\n\
    \        if (v < 0) v += static_cast<signed_t>(mod);\n        val = static_cast<T>(v);\n\
    \    }\n    template<class U, typename std::enable_if<\n                     \
    \     std::is_integral<U>::value &&\n                          std::is_unsigned<U>::value>::type*\
    \ = nullptr>\n    constexpr StaticModInt(U v) : val(v % mod) {}\n    constexpr\
    \ T get() const { return val; }\n    static constexpr T get_mod() { return mod;\
    \ }\n    static constexpr StaticModInt raw(T v) {\n        StaticModInt res;\n\
    \        res.val = v;\n        return res;\n    }\n    constexpr StaticModInt\
    \ inv() const {\n        if IF_CONSTEXPR (mod == 1000000007) {\n            if\
    \ (val <= 10) return inv1000000007[val];\n        }\n        else if IF_CONSTEXPR\
    \ (mod == 998244353) {\n            if (val <= 10) return inv998244353[val];\n\
    \        }\n        return mod_inv(val);\n    }\n    constexpr StaticModInt& operator++()\
    \ {\n        ++val;\n        if (val == mod) val = 0;\n        return *this;\n\
    \    }\n    constexpr StaticModInt operator++(int) {\n        StaticModInt res\
    \ = *this;\n        ++*this;\n        return res;\n    }\n    constexpr StaticModInt&\
    \ operator--() {\n        if (val == 0) val = mod;\n        --val;\n        return\
    \ *this;\n    }\n    constexpr StaticModInt operator--(int) {\n        StaticModInt\
    \ res = *this;\n        --*this;\n        return res;\n    }\n    constexpr StaticModInt&\
    \ operator+=(const StaticModInt& other) {\n        val += other.val;\n       \
    \ if (val >= mod) val -= mod;\n        return *this;\n    }\n    constexpr StaticModInt&\
    \ operator-=(const StaticModInt& other) {\n        if (val < other.val) val +=\
    \ mod;\n        val -= other.val;\n        return *this;\n    }\n    constexpr\
    \ StaticModInt& operator*=(const StaticModInt& other) {\n        large_t a = val;\n\
    \        a *= other.val;\n        a %= mod;\n        val = a;\n        return\
    \ *this;\n    }\n    constexpr StaticModInt& operator/=(const StaticModInt& other)\
    \ {\n        *this *= other.inv();\n        return *this;\n    }\n    friend constexpr\
    \ StaticModInt operator+(const StaticModInt& lhs,\n                          \
    \                  const StaticModInt& rhs) {\n        return StaticModInt(lhs)\
    \ += rhs;\n    }\n    friend constexpr StaticModInt operator-(const StaticModInt&\
    \ lhs,\n                                            const StaticModInt& rhs) {\n\
    \        return StaticModInt(lhs) -= rhs;\n    }\n    friend constexpr StaticModInt\
    \ operator*(const StaticModInt& lhs,\n                                       \
    \     const StaticModInt& rhs) {\n        return StaticModInt(lhs) *= rhs;\n \
    \   }\n    friend constexpr StaticModInt operator/(const StaticModInt& lhs,\n\
    \                                            const StaticModInt& rhs) {\n    \
    \    return StaticModInt(lhs) /= rhs;\n    }\n    constexpr StaticModInt operator+()\
    \ const { return StaticModInt(*this); }\n    constexpr StaticModInt operator-()\
    \ const { return StaticModInt() - *this; }\n    friend constexpr bool operator==(const\
    \ StaticModInt& lhs,\n                                     const StaticModInt&\
    \ rhs) {\n        return lhs.val == rhs.val;\n    }\n    friend constexpr bool\
    \ operator!=(const StaticModInt& lhs,\n                                     const\
    \ StaticModInt& rhs) {\n        return lhs.val != rhs.val;\n    }\n    constexpr\
    \ StaticModInt pow(ll a) const {\n        StaticModInt v = *this, res = 1;\n \
    \       while (a) {\n            if (a & 1) res *= v;\n            a >>= 1;\n\
    \            v *= v;\n        }\n        return res;\n    }\n    template<class\
    \ Pr> void print(Pr& a) const { a.print(val); }\n    template<class Pr> void debug(Pr&\
    \ a) const { a.print(val); }\n    template<class Sc> void scan(Sc& a) {\n    \
    \    ll v;\n        a.scan(v);\n        *this = v;\n    }\n};\n\n#if __cplusplus\
    \ < 201703L\ntemplate<class T, T mod>\nconstexpr unsigned int StaticModInt<T,\
    \ mod>::inv1000000007[];\ntemplate<class T, T mod>\nconstexpr unsigned int StaticModInt<T,\
    \ mod>::inv998244353[];\n#endif\n\ntemplate<unsigned int p> using static_modint\
    \ = StaticModInt<unsigned int, p>;\nusing modint1000000007 = static_modint<1000000007>;\n\
    using modint998244353 = static_modint<998244353>;\n\ntemplate<class T, int id>\
    \ class DynamicModInt {\n    static_assert(std::is_integral<T>::value, \"T must\
    \ be integral\");\n    static_assert(std::is_unsigned<T>::value, \"T must be unsigned\"\
    );\n\nprivate:\n    using large_t = typename double_size_uint<T>::type;\n    using\
    \ signed_t = typename std::make_signed<T>::type;\n    T val;\n    static T mod;\n\
    \npublic:\n    constexpr DynamicModInt() : val(0) {}\n    template<class U,\n\
    \             typename std::enable_if<std::is_integral<U>::value &&\n        \
    \                             std::is_signed<U>::value>::type* = nullptr>\n  \
    \  constexpr DynamicModInt(U v) : val{} {\n        v %= static_cast<signed_t>(mod);\n\
    \        if (v < 0) v += static_cast<signed_t>(mod);\n        val = static_cast<T>(v);\n\
    \    }\n    template<class U, typename std::enable_if<\n                     \
    \     std::is_integral<U>::value &&\n                          std::is_unsigned<U>::value>::type*\
    \ = nullptr>\n    constexpr DynamicModInt(U v) : val(v % mod) {}\n    T get()\
    \ const { return val; }\n    static T get_mod() { return mod; }\n    static void\
    \ set_mod(T v) {\n        assert(v > 0);\n        assert(v <= std::numeric_limits<T>::max()\
    \ / 2);\n        mod = v;\n    }\n    static DynamicModInt raw(T v) {\n      \
    \  DynamicModInt res;\n        res.val = v;\n        return res;\n    }\n    DynamicModInt\
    \ inv() const { return mod_inv(val, mod); }\n    DynamicModInt& operator++() {\n\
    \        ++val;\n        if (val == mod) val = 0;\n        return *this;\n   \
    \ }\n    DynamicModInt operator++(int) {\n        DynamicModInt res = *this;\n\
    \        ++*this;\n        return res;\n    }\n    DynamicModInt& operator--()\
    \ {\n        if (val == 0) val = mod;\n        --val;\n        return *this;\n\
    \    }\n    DynamicModInt operator--(int) {\n        DynamicModInt res = *this;\n\
    \        --*this;\n        return res;\n    }\n    DynamicModInt& operator+=(const\
    \ DynamicModInt& other) {\n        val += other.val;\n        if (val >= mod)\
    \ val -= mod;\n        return *this;\n    }\n    DynamicModInt& operator-=(const\
    \ DynamicModInt& other) {\n        if (val < other.val) val += mod;\n        val\
    \ -= other.val;\n        return *this;\n    }\n    DynamicModInt& operator*=(const\
    \ DynamicModInt& other) {\n        large_t a = val;\n        a *= other.val;\n\
    \        a %= mod;\n        val = a;\n        return *this;\n    }\n    DynamicModInt&\
    \ operator/=(const DynamicModInt& other) {\n        *this *= other.inv();\n  \
    \      return *this;\n    }\n    friend DynamicModInt operator+(const DynamicModInt&\
    \ lhs,\n                                   const DynamicModInt& rhs) {\n     \
    \   return DynamicModInt(lhs) += rhs;\n    }\n    friend DynamicModInt operator-(const\
    \ DynamicModInt& lhs,\n                                   const DynamicModInt&\
    \ rhs) {\n        return DynamicModInt(lhs) -= rhs;\n    }\n    friend DynamicModInt\
    \ operator*(const DynamicModInt& lhs,\n                                   const\
    \ DynamicModInt& rhs) {\n        return DynamicModInt(lhs) *= rhs;\n    }\n  \
    \  friend DynamicModInt operator/(const DynamicModInt& lhs,\n                \
    \                   const DynamicModInt& rhs) {\n        return DynamicModInt(lhs)\
    \ /= rhs;\n    }\n    DynamicModInt operator+() const { return DynamicModInt(*this);\
    \ }\n    DynamicModInt operator-() const { return DynamicModInt() - *this; }\n\
    \    friend bool operator==(const DynamicModInt& lhs, const DynamicModInt& rhs)\
    \ {\n        return lhs.val == rhs.val;\n    }\n    friend bool operator!=(const\
    \ DynamicModInt& lhs, const DynamicModInt& rhs) {\n        return lhs.val != rhs.val;\n\
    \    }\n    DynamicModInt pow(ll a) const {\n        DynamicModInt v = *this,\
    \ res = 1;\n        while (a) {\n            if (a & 1) res *= v;\n          \
    \  a >>= 1;\n            v *= v;\n        }\n        return res;\n    }\n    template<class\
    \ Pr> void print(Pr& a) const { a.print(val); }\n    template<class Pr> void debug(Pr&\
    \ a) const { a.print(val); }\n    template<class Sc> void scan(Sc& a) {\n    \
    \    ll v;\n        a.scan(v);\n        *this = v;\n    }\n};\n\ntemplate<class\
    \ T, int id> T DynamicModInt<T, id>::mod = 998244353;\n\ntemplate<int id> using\
    \ dynamic_modint = DynamicModInt<unsigned int, id>;\nusing modint = dynamic_modint<-1>;\n\
    \n/**\n * @brief ModInt\n * @docs docs/math/ModInt.md\n */\n#line 2 \"math/convolution/Convolution.hpp\"\
    \n\n#line 5 \"math/convolution/Convolution.hpp\"\n\nconstexpr ull primitive_root_for_convolution(ull\
    \ p) {\n    if (p == 2) return 1;\n    if (p == 998244353) return 3;\n    if (p\
    \ == 469762049) return 3;\n    if (p == 1811939329) return 11;\n    if (p == 2013265921)\
    \ return 11;\n    rep (g, 2, p) {\n        if (mod_pow(g, (p - 1) >> 1, p) !=\
    \ 1) return g;\n    }\n    return -1;\n}\n\nnamespace internal {\n\ntemplate<class\
    \ T> class NthRoot {\nprivate:\n    static constexpr unsigned int lg =\n     \
    \   bitop::msb((T::get_mod() - 1) & (1 - T::get_mod()));\n    T root[lg + 1];\n\
    \    T inv_root[lg + 1];\n    T rate[lg + 1];\n    T inv_rate[lg + 1];\n\npublic:\n\
    \    constexpr NthRoot() : root{}, inv_root{}, rate{}, inv_rate{} {\n        root[lg]\
    \ = T{primitive_root_for_convolution(T::get_mod())}.pow(\n            (T::get_mod()\
    \ - 1) >> lg);\n        inv_root[lg] = root[lg].inv();\n        rrep (i, lg) {\n\
    \            root[i] = root[i + 1] * root[i + 1];\n            inv_root[i] = inv_root[i\
    \ + 1] * inv_root[i + 1];\n        }\n        T r = 1;\n        rep (i, 2, lg\
    \ + 1) {\n            rate[i - 2] = r * root[i];\n            r = r * inv_root[i];\n\
    \        }\n        r = 1;\n        rep (i, 2, lg + 1) {\n            inv_rate[i\
    \ - 2] = r * inv_root[i];\n            r = r * root[i];\n        }\n    }\n  \
    \  static constexpr unsigned int get_lg() { return lg; }\n    constexpr T get(int\
    \ n) const { return root[n]; }\n    constexpr T inv(int n) const { return inv_root[n];\
    \ }\n    constexpr T get_rate(int n) const { return rate[n]; }\n    constexpr\
    \ T get_inv_rate(int n) const { return inv_rate[n]; }\n};\n\ntemplate<class T>\
    \ void number_theoretic_transform(std::vector<T>& a) {\n    static constexpr NthRoot<T>\
    \ nth_root;\n    int n = a.size();\n    for (int i = n >> 1; i > 0; i >>= 1) {\n\
    \        T z = T::raw(1);\n        rep (j, 0, n, i << 1) {\n            rep (k,\
    \ i) {\n                const T x = a[j + k];\n                const T y = a[j\
    \ + i + k] * z;\n                a[j + k] = x + y;\n                a[j + i +\
    \ k] = x - y;\n            }\n            z *= nth_root.get_rate(popcnt(j & ~(j\
    \ + (i << 1))));\n        }\n    }\n}\n\ntemplate<class T> void inverse_number_theoretic_transform(std::vector<T>&\
    \ a) {\n    static constexpr NthRoot<T> nth_root;\n    int n = a.size();\n   \
    \ for (int i = 1; i < n; i <<= 1) {\n        T z = T::raw(1);\n        rep (j,\
    \ 0, n, i << 1) {\n            rep (k, i) {\n                const T x = a[j +\
    \ k];\n                const T y = a[j + i + k];\n                a[j + k] = x\
    \ + y;\n                a[j + i + k] = (x - y) * z;\n            }\n         \
    \   z *= nth_root.get_inv_rate(popcnt(j & ~(j + (i << 1))));\n        }\n    }\n\
    \    T inv_n = T(1) / n;\n    for (auto&& x : a) x *= inv_n;\n}\n\ntemplate<class\
    \ T>\nstd::vector<T> convolution_naive(const std::vector<T>& a,\n            \
    \                     const std::vector<T>& b) {\n    int n = a.size(), m = b.size();\n\
    \    std::vector<T> c(n + m - 1);\n    rep (i, n)\n        rep (j, m) c[i + j]\
    \ += a[i] * b[j];\n    return c;\n}\n\ntemplate<class T> std::vector<T> convolution_pow2(std::vector<T>\
    \ a) {\n    int n = a.size() * 2 - 1;\n    int lg = bitop::msb(n - 1) + 1;\n \
    \   if (n - (1 << (lg - 1)) <= 5) {\n        --lg;\n        int m = a.size() -\
    \ (1 << (lg - 1));\n        std::vector<T> a1(a.begin(), a.begin() + m), a2(a.begin()\
    \ + m, a.end());\n        std::vector<T> c(n);\n        std::vector<T> c1 = convolution_naive(a1,\
    \ a1);\n        std::vector<T> c2 = convolution_naive(a1, a2);\n        std::vector<T>\
    \ c3 = convolution_pow2(a2);\n        rep (i, c1.size()) c[i] += c1[i];\n    \
    \    rep (i, c2.size()) c[i + m] += c2[i] * 2;\n        rep (i, c3.size()) c[i\
    \ + m * 2] += c3[i];\n        return c;\n    }\n    int m = 1 << lg;\n    a.resize(m);\n\
    \    number_theoretic_transform(a);\n    rep (i, m) a[i] *= a[i];\n    inverse_number_theoretic_transform(a);\n\
    \    a.resize(n);\n    return a;\n}\n\ntemplate<class T>\nstd::vector<T> convolution(std::vector<T>\
    \ a, std::vector<T> b) {\n    int n = a.size() + b.size() - 1;\n    int lg = bitop::ceil_log2(n);\n\
    \    int m = 1 << lg;\n    if (n - (1 << (lg - 1)) <= 5) {\n        --lg;\n  \
    \      if (a.size() < b.size()) std::swap(a, b);\n        int m = n - (1 << lg);\n\
    \        std::vector<T> a1(a.begin(), a.begin() + m), a2(a.begin() + m, a.end());\n\
    \        std::vector<T> c(n);\n        std::vector<T> c1 = convolution_naive(a1,\
    \ b);\n        std::vector<T> c2 = convolution(a2, b);\n        rep (i, c1.size())\
    \ c[i] += c1[i];\n        rep (i, c2.size()) c[i + m] += c2[i];\n        return\
    \ c;\n    }\n    a.resize(m);\n    b.resize(m);\n    number_theoretic_transform(a);\n\
    \    number_theoretic_transform(b);\n    rep (i, m) a[i] *= b[i];\n    inverse_number_theoretic_transform(a);\n\
    \    a.resize(n);\n    return a;\n}\n\n} // namespace internal\n\nusing internal::inverse_number_theoretic_transform;\n\
    using internal::number_theoretic_transform;\n\ntemplate<unsigned int p>\nstd::vector<static_modint<p>>\n\
    convolution_for_any_mod(const std::vector<static_modint<p>>& a,\n            \
    \            const std::vector<static_modint<p>>& b);\n\ntemplate<unsigned int\
    \ p>\nstd::vector<static_modint<p>>\nconvolution(const std::vector<static_modint<p>>&\
    \ a,\n            const std::vector<static_modint<p>>& b) {\n    unsigned int\
    \ n = a.size(), m = b.size();\n    if (n == 0 || m == 0) return {};\n    if (n\
    \ <= 60 || m <= 60) return internal::convolution_naive(a, b);\n    if (n + m -\
    \ 1 <= ((1 - p) & (p - 1))) {\n        if (n == m && a == b) return internal::convolution_pow2(a);\n\
    \        return internal::convolution(a, b);\n    }\n    return convolution_for_any_mod(a,\
    \ b);\n}\n\ntemplate<unsigned int p>\nstd::vector<ll> convolution(const std::vector<ll>&\
    \ a,\n                            const std::vector<ll>& b) {\n    int n = a.size(),\
    \ m = b.size();\n    std::vector<static_modint<p>> a2(n), b2(m);\n    rep (i,\
    \ n) a2[i] = a[i];\n    rep (i, m) b2[i] = b[i];\n    auto c2 = convolution(a2,\
    \ b2);\n    std::vector<ll> c(c2.size());\n    rep (i, c2.size()) c[i] = c2[i].get();\n\
    \    return c;\n}\n\ntemplate<unsigned int p>\nstd::vector<static_modint<p>>\n\
    convolution_for_any_mod(const std::vector<static_modint<p>>& a,\n            \
    \            const std::vector<static_modint<p>>& b) {\n    int n = a.size(),\
    \ m = b.size();\n    assert(n + m - 1 <= (1 << 26));\n    std::vector<ll> a2(n),\
    \ b2(m);\n    rep (i, n) a2[i] = a[i].get();\n    rep (i, m) b2[i] = b[i].get();\n\
    \    static constexpr ll MOD1 = 469762049;\n    static constexpr ll MOD2 = 1811939329;\n\
    \    static constexpr ll MOD3 = 2013265921;\n    static constexpr ll INV1_2 =\
    \ mod_pow(MOD1, MOD2 - 2, MOD2);\n    static constexpr ll INV1_3 = mod_pow(MOD1,\
    \ MOD3 - 2, MOD3);\n    static constexpr ll INV2_3 = mod_pow(MOD2, MOD3 - 2, MOD3);\n\
    \    auto c1 = convolution<MOD1>(a2, b2);\n    auto c2 = convolution<MOD2>(a2,\
    \ b2);\n    auto c3 = convolution<MOD3>(a2, b2);\n    std::vector<static_modint<p>>\
    \ res(n + m - 1);\n    rep (i, n + m - 1) {\n        ll t1 = c1[i];\n        ll\
    \ t2 = (c2[i] - t1 + MOD2) * INV1_2 % MOD2;\n        if (t2 < 0) t2 += MOD2;\n\
    \        ll t3 =\n            ((c3[i] - t1 + MOD3) * INV1_3 % MOD3 - t2 + MOD3)\
    \ * INV2_3 % MOD3;\n        if (t3 < 0) t3 += MOD3;\n        res[i] = static_modint<p>(t1\
    \ + (t2 + t3 * MOD2) % p * MOD1);\n    }\n    return res;\n}\n\ntemplate<class\
    \ T> void ntt_doubling_(std::vector<T>& a) {\n    static constexpr internal::NthRoot<T>\
    \ nth_root;\n    int n = a.size();\n    auto b = a;\n    inverse_number_theoretic_transform(b);\n\
    \    const T z = nth_root.get(bitop::msb(n) + 1);\n    T r = 1;\n    rep (i, n)\
    \ {\n        b[i] *= r;\n        r *= z;\n    }\n    number_theoretic_transform(b);\n\
    \    std::copy(all(b), std::back_inserter(a));\n}\n\ntemplate<unsigned int p>\
    \ struct is_ntt_friendly : std::false_type {};\n\ntemplate<> struct is_ntt_friendly<998244353>\
    \ : std::true_type {};\n\n/**\n * @brief Convolution(\u7573\u307F\u8FBC\u307F\
    )\n * @docs docs/math/convolution/Convolution.md\n */\n#line 2 \"graph/tree/TreeCentroid.hpp\"\
    \n\n#line 5 \"graph/tree/TreeCentroid.hpp\"\n\ntemplate<class T> class TreeCentroids\
    \ {\nprivate:\n    int n;\n    const Graph<T>& G;\n    std::vector<int> sz;\n\
    \    std::vector<int> cent;\n    int dfs(int v, int p) {\n        for (const auto&\
    \ e : G[v]) {\n            if (e.to == p) continue;\n            sz[v] += dfs(e.to,\
    \ v);\n        }\n        return sz[v];\n    }\n    void init() {\n        n =\
    \ G.size();\n        sz.assign(n, 1);\n        int s = dfs(0, -1);\n        int\
    \ v = 0, p = -1;\n        while (true) {\n            bool ok = true;\n      \
    \      for (const auto& e : G[v]) {\n                if (e.to == p) continue;\n\
    \                if (sz[e.to] * 2 > s) {\n                    p = v;\n       \
    \             v = e.to;\n                    ok = false;\n                   \
    \ break;\n                }\n                if (sz[e.to] * 2 == s) {\n      \
    \              cent = {v, e.to};\n                    return;\n              \
    \  }\n            }\n            if (ok) {\n                cent = {v};\n    \
    \            return;\n            }\n        }\n    }\n\npublic:\n    TreeCentroids(const\
    \ Graph<T>& G) : G(G) { init(); }\n    bool has_one_centroid() const { return\
    \ cent.size() == 1; }\n    std::vector<int> get() { return cent; }\n};\n\ntemplate<class\
    \ T> class CentroidDecomposition {\nprivate:\n    int n;\n    const Graph<T>&\
    \ G;\n    std::vector<bool> seen;\n    std::vector<int> sz;\n    int root;\n \
    \   UnweightedGraph C;\n    int dfs(int v, int p) {\n        sz[v] = 1;\n    \
    \    for (const auto& e : G[v]) {\n            if (e.to == p) continue;\n    \
    \        if (seen[e.to]) continue;\n            sz[v] += dfs(e.to, v);\n     \
    \   }\n        return sz[v];\n    }\n    void init() {\n        n = G.size();\n\
    \        seen.assign(n, false);\n        sz.assign(n, 1);\n        std::vector<std::pair<int,\
    \ int>> st = {{0, -1}};\n        st.reserve(n);\n        C = UnweightedGraph(n);\n\
    \        while (!st.empty()) {\n            int v = st.back().first, vp = st.back().second;\n\
    \            st.pop_back();\n            int s = dfs(v, -1);\n            int\
    \ p = -1;\n            while (true) {\n                bool ok = true;\n     \
    \           for (const auto& e : G[v]) {\n                    if (e.to == p) continue;\n\
    \                    if (seen[e.to]) continue;\n                    if (sz[e.to]\
    \ * 2 > s) {\n                        p = v;\n                        v = e.to;\n\
    \                        ok = false;\n                        break;\n       \
    \             }\n                }\n                if (ok) break;\n         \
    \   }\n            seen[v] = true;\n            if (vp != -1) C.add_edge(vp, v,\
    \ true);\n            else root = v;\n            for (const auto& e : G[v]) {\n\
    \                if (seen[e.to]) continue;\n                st.emplace_back(e.to,\
    \ v);\n            }\n        }\n    }\n\npublic:\n    CentroidDecomposition(const\
    \ Graph<T>& G) : G(G) { init(); }\n    int get_root() { return root; }\n    const\
    \ UnweightedGraph& get() const& { return C; }\n    UnweightedGraph get() && {\
    \ return std::move(C); }\n};\n\n/**\n * @brief TreeCentroid(\u6728\u306E\u91CD\
    \u5FC3)\n * @docs docs/graph/tree/TreeCentroid.md\n */\n#line 9 \"graph/tree/FrequencyTableofTreeDistance.hpp\"\
    \n\ntemplate<class T> class FrequencyTableofTreeDistance {\nprivate:\n    static\
    \ constexpr int MOD1 = 469762049;\n    static constexpr int MOD2 = 1811939329;\n\
    \    using mint1 = static_modint<MOD1>;\n    using mint2 = static_modint<MOD2>;\n\
    \n    int n;\n    const Graph<T>& G;\n    CentroidDecomposition<T> C;\n    std::vector<mint1>\
    \ ans1;\n    std::vector<mint2> ans2;\n    std::vector<ll> ans;\n\n    template<class\
    \ M> void build(std::vector<M>& ans) {\n        std::vector<int> st = {C.get_root()};\n\
    \        st.reserve(n);\n        std::vector<bool> seen(n, false);\n        std::vector<std::tuple<int,\
    \ int, int>> st2;\n        st2.reserve(n);\n        while (!st.empty()) {\n  \
    \          int v = st.back();\n            st.pop_back();\n            seen[v]\
    \ = true;\n            std::vector<std::vector<M>> dist;\n            dist.reserve(G[v].size());\n\
    \            for (const auto& s : G[v]) {\n                if (seen[s.to]) continue;\n\
    \                dist.push_back(std::vector<M>(2, 0));\n                st2.emplace_back(s.to,\
    \ -1, 1);\n                while (!st2.empty()) {\n                    int u,\
    \ p, d;\n                    std::tie(u, p, d) = st2.back();\n               \
    \     st2.pop_back();\n                    if ((int)dist.back().size() == d) dist.back().push_back(1);\n\
    \                    else ++dist.back()[d];\n                    for (const auto&\
    \ e : G[u]) {\n                        if (e.to == p || seen[e.to]) continue;\n\
    \                        st2.emplace_back(e.to, u, d + 1);\n                 \
    \   }\n                }\n            }\n            sort(all(dist),\n       \
    \          [](const std::vector<M>& a, const std::vector<M>& b) {\n          \
    \           return a.size() < b.size();\n                 });\n            std::vector<M>\
    \ tmp;\n            for (const auto& d : dist) {\n                if (tmp.empty())\
    \ {\n                    tmp = d;\n                    continue;\n           \
    \     }\n                auto tmp2 = convolution(tmp, d);\n                rep\
    \ (i, tmp2.size()) ans[i] += tmp2[i];\n                tmp.resize(d.size());\n\
    \                rep (i, d.size()) tmp[i] += d[i];\n            }\n          \
    \  rep (i, tmp.size()) ans[i] += tmp[i];\n            for (const auto& e : C.get()[v])\
    \ st.push_back(e.to);\n        }\n    }\n\npublic:\n    FrequencyTableofTreeDistance(const\
    \ Graph<T>& G_)\n        : n(G_.size()), G(G_), C(G_), ans1(n, 0), ans2(n, 0)\
    \ {\n        build(ans1);\n        build(ans2);\n        ans.resize(n);\n    \
    \    ans[0] = n;\n        rep (i, 1, n) {\n            ans[i] = ChineseRemainder(ans1[i].get(),\
    \ MOD1, ans2[i].get(), MOD2)\n                         .first;\n        }\n  \
    \  }\n    const std::vector<ll>& get() const& { return ans; }\n    std::vector<ll>\
    \ get() && { return std::move(ans); }\n};\n\n/**\n * @brief Frequency Table of\
    \ Tree Distance\n * @docs docs/graph/tree/FrequencyTableofTreeDistance.md\n */\n\
    #line 5 \"test/yosupo/tree/frequency_table_of_tree_distance.test.cpp\"\nusing\
    \ namespace std;\nint main() {\n    int N; scan >> N;\n    Graph<int> G(N);\n\
    \    rep (N - 1) {\n        int a, b; scan >> a >> b;\n        G.add_edge(a, b);\n\
    \    }\n    auto ans = FrequencyTableofTreeDistance<int>(G).get();\n    ans.erase(ans.begin());\n\
    \    prints(ans);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\
    \n#include \"../../../other/template.hpp\"\n#include \"../../../graph/Graph.hpp\"\
    \n#include \"../../../graph/tree/FrequencyTableofTreeDistance.hpp\"\nusing namespace\
    \ std;\nint main() {\n    int N; scan >> N;\n    Graph<int> G(N);\n    rep (N\
    \ - 1) {\n        int a, b; scan >> a >> b;\n        G.add_edge(a, b);\n    }\n\
    \    auto ans = FrequencyTableofTreeDistance<int>(G).get();\n    ans.erase(ans.begin());\n\
    \    prints(ans);\n}\n"
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
  - graph/Graph.hpp
  - graph/tree/FrequencyTableofTreeDistance.hpp
  - math/ChineseRemainder.hpp
  - math/ModInt.hpp
  - math/convolution/Convolution.hpp
  - graph/tree/TreeCentroid.hpp
  isVerificationFile: true
  path: test/yosupo/tree/frequency_table_of_tree_distance.test.cpp
  requiredBy: []
  timestamp: '2024-05-29 15:54:32+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/tree/frequency_table_of_tree_distance.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/tree/frequency_table_of_tree_distance.test.cpp
- /verify/test/yosupo/tree/frequency_table_of_tree_distance.test.cpp.html
title: test/yosupo/tree/frequency_table_of_tree_distance.test.cpp
---
