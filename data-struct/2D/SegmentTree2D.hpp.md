---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data-struct/2D/Struct2D.hpp
    title: data-struct/2D/Struct2D.hpp
  - icon: ':question:'
    path: data-struct/segment/SegmentTree.hpp
    title: "SegmentTree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  - icon: ':question:'
    path: other/monoid.hpp
    title: other/monoid.hpp
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
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/data_structure/point_add_rectangle_sum-2DSegTree.test.cpp
    title: test/yosupo/data_structure/point_add_rectangle_sum-2DSegTree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/data-struct/2D/SegmentTree2D.md
    document_title: SegmentTree2D
    links: []
  bundledCode: "#line 2 \"data-struct/2D/SegmentTree2D.hpp\"\n\n#line 2 \"other/template.hpp\"\
    \n\n#include <bits/stdc++.h>\n#line 2 \"template/macros.hpp\"\n\n#line 4 \"template/macros.hpp\"\
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
    \ fd) : fd(fd), idx(0), sz(0) {}\n    Scanner(FILE* fp) : fd(fileno(fp)), idx(0),\
    \ sz(0) {}\n\n    inline char scan_char() {\n        if (idx == sz) load();\n\
    \        return idx == sz ? '\\0' : buffer[idx++];\n    }\n\n    Scanner ignore(int\
    \ n = 1) {\n        if (idx + n > sz) load();\n        idx += n;\n        return\
    \ *this;\n    }\n\n    inline void discard_space() {\n        if (idx == sz) load();\n\
    \        while (('\\t' <= buffer[idx] && buffer[idx] <= '\\r') ||\n          \
    \     buffer[idx] == ' ') {\n            if (++idx == sz) load();\n        }\n\
    \    }\n    void scan(char& a) {\n        discard_space();\n        a = scan_char();\n\
    \    }\n    void scan(bool& a) {\n        discard_space();\n        a = scan_char()\
    \ != '0';\n    }\n    void scan(std::string& a) {\n        discard_space();\n\
    \        a.clear();\n        while (cur() != '\\0' && (buffer[idx] < '\\t' ||\
    \ '\\r' < buffer[idx]) &&\n               buffer[idx] != ' ') {\n            a\
    \ += scan_char();\n        }\n    }\n    template<std::size_t len> void scan(std::bitset<len>&\
    \ a) {\n        discard_space();\n        if (idx + len > sz) load();\n      \
    \  rrep (i, len) a[i] = buffer[idx++] != '0';\n    }\n    template<class T,\n\
    \             typename std::enable_if<is_signed_int<T>::value &&\n           \
    \                          !has_scan<T>::value>::type* = nullptr>\n    void scan(T&\
    \ a) {\n        discard_space();\n        if (buffer[idx] == '-') {\n        \
    \    ++idx;\n            if (idx + 40 > sz &&\n                (idx == sz || ('0'\
    \ <= buffer[sz - 1] && buffer[sz - 1] <= '9')))\n                load();\n   \
    \         a = 0;\n            while ('0' <= buffer[idx] && buffer[idx] <= '9')\
    \ {\n                a = a * 10 - (buffer[idx++] - '0');\n            }\n    \
    \    }\n        else {\n            if (idx + 40 > sz && '0' <= buffer[sz - 1]\
    \ && buffer[sz - 1] <= '9')\n                load();\n            a = 0;\n   \
    \         while ('0' <= buffer[idx] && buffer[idx] <= '9') {\n               \
    \ a = a * 10 + (buffer[idx++] - '0');\n            }\n        }\n    }\n    template<class\
    \ T,\n             typename std::enable_if<is_unsigned_int<T>::value &&\n    \
    \                                 !has_scan<T>::value>::type* = nullptr>\n   \
    \ void scan(T& a) {\n        discard_space();\n        if (idx + 40 > sz && '0'\
    \ <= buffer[sz - 1] && buffer[sz - 1] <= '9')\n            load();\n        a\
    \ = 0;\n        while ('0' <= buffer[idx] && buffer[idx] <= '9') {\n         \
    \   a = a * 10 + (buffer[idx++] - '0');\n        }\n    }\n    template<class\
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
    };\n#line 2 \"other/monoid.hpp\"\n\n#line 4 \"other/monoid.hpp\"\n\nnamespace\
    \ Monoid {\n\ntemplate<class M, class = void>\nclass has_value_type : public std::false_type\
    \ {};\ntemplate<class M>\nclass has_value_type<M, decltype((void)std::declval<typename\
    \ M::value_type>())>\n    : public std::true_type {};\n\ntemplate<class M, class\
    \ = void> class has_op : public std::false_type {};\ntemplate<class M>\nclass\
    \ has_op<M, decltype((void)M::op)> : public std::true_type {};\n\ntemplate<class\
    \ M, class = void> class has_id : public std::false_type {};\ntemplate<class M>\n\
    class has_id<M, decltype((void)M::id)> : public std::true_type {};\n\ntemplate<class\
    \ M, class = void> class has_inv : public std::false_type {};\ntemplate<class\
    \ M>\nclass has_inv<M, decltype((void)M::inv)> : public std::true_type {};\n\n\
    template<class M, class = void> class has_get_inv : public std::false_type {};\n\
    template<class M>\nclass has_get_inv<M, decltype((void)M::get_inv)> : public std::true_type\
    \ {};\n\ntemplate<class M, class = void> class has_init : public std::false_type\
    \ {};\ntemplate<class M>\nclass has_init<M, decltype((void)M::init(0, 0))> : public\
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
    \ a) { return -a; }\n};\n\ntemplate<class T, int i = -1> struct Min {\n    using\
    \ value_type = T;\n    static T max_value;\n    static T op(const T& a, const\
    \ T& b) { return a < b ? a : b; }\n    static T id() { return max_value; }\n};\n\
    template<class T> struct Min<T, -1> {\n    using value_type = T;\n    static constexpr\
    \ T op(const T& a, const T& b) { return a < b ? a : b; }\n    static constexpr\
    \ T id() { return infinity<T>::value; }\n};\ntemplate<class T> struct Min<T, -2>\
    \ {\n    using value_type = T;\n    static constexpr T op(const T& a, const T&\
    \ b) { return a < b ? a : b; }\n    static constexpr T id() { return infinity<T>::max;\
    \ }\n};\ntemplate<class T, int id> T Min<T, id>::max_value;\n\ntemplate<class\
    \ T, int i = -1> struct Max {\n    using value_type = T;\n    static T min_value;\n\
    \    static T op(const T& a, const T& b) { return a > b ? a : b; }\n    static\
    \ T id() { return min_value; }\n};\ntemplate<class T> struct Max<T, -1> {\n  \
    \  using value_type = T;\n    static constexpr T op(const T& a, const T& b) {\
    \ return a > b ? a : b; }\n    static constexpr T id() { return infinity<T>::mvalue;\
    \ }\n};\ntemplate<class T> struct Max<T, -2> {\n    using value_type = T;\n  \
    \  static constexpr T op(const T& a, const T& b) { return a > b ? a : b; }\n \
    \   static constexpr T id() { return infinity<T>::min; }\n};\n\ntemplate<class\
    \ T> struct Assign {\n    using value_type = T;\n    static constexpr T op(const\
    \ T&, const T& b) { return b; }\n};\n\n\ntemplate<class T, int id = -1> struct\
    \ AssignMin {\n    using M = Min<T, id>;\n    using E = Assign<T>;\n    static\
    \ constexpr T op(const T& a, const T&) { return a; }\n};\n\ntemplate<class T,\
    \ int id = -1> struct AssignMax {\n    using M = Max<T, id>;\n    using E = Assign<T>;\n\
    \    static constexpr T op(const T& a, const T&) { return a; }\n};\n\ntemplate<class\
    \ T> struct AssignSum {\n    using M = Sum<T>;\n    using E = Assign<T>;\n   \
    \ static constexpr T mul_op(const T& a, int b, const T&) { return a * b; }\n};\n\
    \ntemplate<class T, int id = -1> struct AddMin {\n    using M = Min<T, id>;\n\
    \    using E = Sum<T>;\n    static constexpr T op(const T& a, const T& b) { return\
    \ b + a; }\n};\n\ntemplate<class T, int id = -1> struct AddMax {\n    using M\
    \ = Max<T, id>;\n    using E = Sum<T>;\n    static constexpr T op(const T& a,\
    \ const T& b) { return b + a; }\n};\n\ntemplate<class T> struct AddSum {\n   \
    \ using M = Sum<T>;\n    using E = Sum<T>;\n    static constexpr T mul_op(const\
    \ T& a, int b, const T& c) {\n        return c + a * b;\n    }\n};\n\ntemplate<class\
    \ T, int id = -1> struct ChminMin {\n    using M = Min<T, id>;\n    using E =\
    \ Min<T>;\n    static constexpr T op(const T& a, const T& b) { return std::min(b,\
    \ a); }\n};\n\ntemplate<class T, int id = -1> struct ChminMax {\n    using M =\
    \ Max<T, id>;\n    using E = Min<T>;\n    static constexpr T op(const T& a, const\
    \ T& b) { return std::min(b, a); }\n};\n\ntemplate<class T, int id = -1> struct\
    \ ChmaxMin {\n    using M = Min<T, id>;\n    using E = Max<T>;\n    static constexpr\
    \ T op(const T& a, const T& b) { return std::max(b, a); }\n};\n\ntemplate<class\
    \ T, int id = -1> struct ChmaxMax {\n    using M = Max<T, id>;\n    using E =\
    \ Max<T>;\n    static constexpr T op(const T& a, const T& b) { return std::max(b,\
    \ a); }\n};\n\n\ntemplate<class M> struct ReverseMonoid {\n    using value_type\
    \ = typename M::value_type;\n    static value_type op(const value_type& a, const\
    \ value_type& b) {\n        return M::op(b, a);\n    }\n    static value_type\
    \ id() {\n        static_assert(has_id<M>::value, \"id is not defined\");\n  \
    \      return M::id();\n    }\n    static value_type inv(const value_type& a,\
    \ const value_type& b) {\n        static_assert(has_inv<M>::value, \"inv is not\
    \ defined\");\n        return M::inv(b, a);\n    }\n    static value_type get_inv(const\
    \ value_type& a) {\n        static_assert(has_get_inv<M>::value, \"get_inv is\
    \ not defined\");\n        return M::get_inv(a);\n    }\n};\n\ntemplate<class\
    \ E_> struct MakeAction {\n    using M = E_;\n    using E = E_;\n    using T =\
    \ typename E_::value_type;\n    static T op(const T& a, const T& b) { return E_::op(b,\
    \ a); }\n};\n\n} // namespace Monoid\n#line 2 \"data-struct/segment/SegmentTree.hpp\"\
    \n\n#line 5 \"data-struct/segment/SegmentTree.hpp\"\n\ntemplate<class M> class\
    \ SegmentTree {\nprivate:\n    using T = typename M::value_type;\n    int n, ori;\n\
    \    std::vector<T> data;\n\npublic:\n    SegmentTree() : SegmentTree(0) {}\n\
    \    SegmentTree(int n) : SegmentTree(std::vector<T>(n, M::id())) {}\n    SegmentTree(int\
    \ n, const T& v) : SegmentTree(std::vector<T>(n, v)) {}\n    SegmentTree(const\
    \ std::vector<T>& v) { init(v); }\n    void init(const std::vector<T>& v) {\n\
    \        ori = v.size();\n        n = 1 << bitop::ceil_log2(ori);\n        data.assign(n\
    \ << 1, M::id());\n        rep (i, ori) data[n + i] = v[i];\n        rrep (i,\
    \ n, 1) data[i] = M::op(data[i << 1], data[i << 1 ^ 1]);\n    }\n    template<class\
    \ Upd> void update(int k, const Upd& upd) {\n        assert(0 <= k && k < ori);\n\
    \        k += n;\n        data[k] = upd(data[k]);\n        while (k >>= 1) data[k]\
    \ = M::op(data[k << 1], data[k << 1 ^ 1]);\n    }\n    void set(int k, T x) {\n\
    \        update(k, [&](T) -> T { return x; });\n    }\n    void apply(int k, T\
    \ x) {\n        update(k, [&](T a) -> T { return M::op(a, x); });\n    }\n   \
    \ T prod(int l, int r) const {\n        assert(0 <= l && l <= r && r <= ori);\n\
    \        l += n;\n        r += n;\n        T lsm = M::id(), rsm = M::id();\n \
    \       while (l < r) {\n            if (l & 1) lsm = M::op(lsm, data[l++]);\n\
    \            if (r & 1) rsm = M::op(data[--r], rsm);\n            l >>= 1;\n \
    \           r >>= 1;\n        }\n        return M::op(lsm, rsm);\n    }\n    T\
    \ all_prod() const { return data[1]; }\n    T get(int k) const { return data[k\
    \ + n]; }\n    template<class Cond> int max_right(int l, const Cond& cond) const\
    \ {\n        assert(0 <= l && l <= ori);\n        assert(cond(M::id()));\n   \
    \     if (l == ori) return ori;\n        l += n;\n        T sm = M::id();\n  \
    \      do {\n            while ((l & 1) == 0) l >>= 1;\n            if (!cond(M::op(sm,\
    \ data[l]))) {\n                while (l < n) {\n                    l <<= 1;\n\
    \                    if (cond(M::op(sm, data[l]))) sm = M::op(sm, data[l++]);\n\
    \                }\n                return l - n;\n            }\n           \
    \ sm = M::op(sm, data[l++]);\n        } while ((l & -l) != l);\n        return\
    \ ori;\n    }\n    template<class Cond> int min_left(int r, const Cond& cond)\
    \ const {\n        assert(0 <= r && r <= ori);\n        assert(cond(M::id()));\n\
    \        if (r == 0) return 0;\n        r += n;\n        T sm = M::id();\n   \
    \     do {\n            --r;\n            while ((r & 1) && r > 1) r >>= 1;\n\
    \            if (!cond(M::op(data[r], sm))) {\n                while (r < n) {\n\
    \                    r = r << 1 ^ 1;\n                    if (cond(M::op(data[r],\
    \ sm))) sm = M::op(data[r--], sm);\n                }\n                return\
    \ r + 1 - n;\n            }\n            sm = M::op(data[r], sm);\n        } while\
    \ ((r & -r) != r);\n        return 0;\n    }\n};\n\n// verified with test/aoj/DSL/DSL_2_A-RMQ.test.cpp\n\
    template<class T, int id = -1>\nusing RangeMinimumQuery = SegmentTree<Monoid::Min<T,\
    \ id>>;\n\ntemplate<class T, int id = -1>\nusing RangeMaximumQuery = SegmentTree<Monoid::Max<T,\
    \ id>>;\n\n// verified with test/aoj/DSL/DSL_2_B-RSQ.test.cpp\ntemplate<class\
    \ T> using RangeSumQuery = SegmentTree<Monoid::Sum<T>>;\n\n/**\n * @brief SegmentTree(\u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728)\n * @docs docs/data-struct/segment/SegmentTree.md\n\
    \ */\n#line 2 \"data-struct/2D/Struct2D.hpp\"\n\n#line 5 \"data-struct/2D/Struct2D.hpp\"\
    \n\nclass Struct2D {\nprivate:\n    int ori, n, h;\n    compressor<ll> psx;\n\
    \    std::vector<std::vector<ll>> idx;\n\npublic:\n    template<class F> void\
    \ init(F&& f, std::vector<ll> xs, std::vector<ll> ys) {\n        psx.push(xs);\n\
    \        psx.build();\n        psx.press(xs);\n        ori = psx.size();\n   \
    \     h = bitop::ceil_log2(ori);\n        n = 1 << h;\n        idx.resize(n <<\
    \ 1);\n        rep (i, xs.size()) idx[xs[i] + n].push_back(ys[i]);\n        rep\
    \ (i, ori) {\n            std::sort(all(idx[i + n]));\n            idx[i + n].erase(std::unique(all(idx[i\
    \ + n])), idx[i + n].end());\n        }\n        rrep (i, n, 1) {\n          \
    \  std::merge(all(idx[i << 1]), all(idx[i << 1 | 1]),\n                      \
    \ std::back_inserter(idx[i]));\n            idx[i].erase(std::unique(all(idx[i])),\
    \ idx[i].end());\n        }\n        std::vector<int> sz(n << 1);\n        rep\
    \ (i, n << 1) sz[i] = idx[i].size();\n        f(sz);\n    }\n    template<class\
    \ F, class M>\n    void init(F&& f, std::vector<ll> xs, std::vector<ll> ys,\n\
    \              std::vector<typename M::value_type> v) {\n        psx.push(xs);\n\
    \        psx.build();\n        psx.press(xs);\n        ori = psx.size();\n   \
    \     h = bitop::ceil_log2(ori);\n        n = 1 << h;\n        std::vector<std::vector<std::pair<ll,\
    \ typename M::value_type>>> tmp(\n            n << 1);\n        rep (i, xs.size())\
    \ tmp[xs[i] + n].emplace_back(ys[i], v[i]);\n        rep (i, ori) {\n        \
    \    std::stable_sort(all(tmp[i + n]), [](const auto& a, const auto& b) {\n  \
    \              return a.first < b.first;\n            });\n            int k =\
    \ 0;\n            rep (j, 1, tmp[i + n].size()) {\n                if (tmp[i +\
    \ n][k].first == tmp[i + n][j].first) {\n                    tmp[i + n][k].second\
    \ =\n                        M::op(tmp[i + n][k].second, tmp[i + n][j].second);\n\
    \                }\n                else {\n                    tmp[i + n][++k]\
    \ = tmp[i + n][j];\n                }\n            }\n            tmp[i + n].resize(k\
    \ + 1);\n        }\n        rrep (i, n, 1) {\n            tmp[i].reserve(tmp[i\
    \ << 1].size() + tmp[i << 1 | 1].size());\n            std::merge(\n         \
    \       all(tmp[i << 1]), all(tmp[i << 1 | 1]),\n                std::back_inserter(tmp[i]),\n\
    \                [](const auto& a, const auto& b) { return a.first < b.first;\
    \ });\n            int k = 0;\n            rep (j, 1, tmp[i].size()) {\n     \
    \           if (tmp[i][k].first == tmp[i][j].first) {\n                    tmp[i][k].second\
    \ =\n                        M::op(tmp[i][k].second, tmp[i][j].second);\n    \
    \            }\n                else {\n                    tmp[i][++k] = tmp[i][j];\n\
    \                }\n            }\n            tmp[i].resize(k + 1);\n       \
    \ }\n        idx.resize(n << 1);\n        std::vector<std::vector<typename M::value_type>>\
    \ dat(n << 1);\n        rep (i, n << 1) {\n            idx[i].resize(tmp[i].size());\n\
    \            dat[i].resize(tmp[i].size());\n            rep (j, tmp[i].size())\
    \ {\n                idx[i][j] = tmp[i][j].first;\n                dat[i][j] =\
    \ tmp[i][j].second;\n            }\n        }\n        f(dat);\n    }\n    template<class\
    \ Upd> void apply(ll x, ll y, Upd&& upd) const {\n        int k = psx.get(x) +\
    \ n;\n        auto itr = std::lower_bound(all(idx[k]), y);\n        assert(itr\
    \ != idx[k].end() && *itr == y);\n        upd(k, itr - idx[k].begin());\n    \
    \    while (k > 1) {\n            k >>= 1;\n            upd(k, std::lower_bound(all(idx[k]),\
    \ y) - idx[k].begin());\n        }\n    }\n    template<class Upd, class Upd2,\
    \ class Mrg>\n    void update(ll x, ll y, Upd&& upd, Upd2&& upd2, Mrg&& mrg) const\
    \ {\n        int k = psx.get(x) + n;\n        auto itr = std::lower_bound(all(idx[k]),\
    \ y);\n        assert(itr != idx[k].end() && *itr == y);\n        upd(k, itr -\
    \ idx[k].begin());\n        while (k > 1) {\n            int l = k ^ 1;\n    \
    \        auto itr2 = std::lower_bound(all(idx[l]), y);\n            if (itr2 !=\
    \ idx[l].end() && *itr2 == y) {\n                if (k < l) mrg(l, itr2 - idx[l].begin(),\
    \ false);\n                else mrg(l, itr2 - idx[l].begin(), true);\n       \
    \     }\n            k >>= 1;\n            upd2(k, std::lower_bound(all(idx[k]),\
    \ y) - idx[k].begin());\n        }\n    }\n    template<class Mrg> void prod(ll\
    \ l, ll r, ll u, ll d, Mrg&& mrg) const {\n        assert(l <= r && u <= d);\n\
    \        l = psx.lower_bound(l) + n;\n        r = psx.lower_bound(r) + n;\n  \
    \      while (l != r) {\n            if (l & 1) {\n                int a = std::lower_bound(all(idx[l]),\
    \ u) - idx[l].begin();\n                int b = std::lower_bound(all(idx[l]),\
    \ d) - idx[l].begin();\n                mrg(l, a, b, true);\n                ++l;\n\
    \            }\n            if (r & 1) {\n                --r;\n             \
    \   int a = std::lower_bound(all(idx[r]), u) - idx[r].begin();\n             \
    \   int b = std::lower_bound(all(idx[r]), d) - idx[r].begin();\n             \
    \   mrg(r, a, b, false);\n            }\n            l >>= 1;\n            r >>=\
    \ 1;\n        }\n    }\n    template<class Mrg> void get(ll x, ll y, Mrg&& mrg)\
    \ const {\n        int k = psx.get(x) + n;\n        auto itr = std::lower_bound(all(idx[k]),\
    \ y);\n        assert(itr != idx[k].end() && *itr == y);\n        mrg(k, itr -\
    \ idx[k].begin());\n    }\n};\n#line 7 \"data-struct/2D/SegmentTree2D.hpp\"\n\n\
    template<class M> class SegmentTree2D {\nprivate:\n    using T = typename M::value_type;\n\
    \    int n;\n    std::vector<SegmentTree<M>> seg;\n    Struct2D str;\n\npublic:\n\
    \    SegmentTree2D(const std::vector<ll>& xs, const std::vector<ll>& ys) {\n \
    \       str.init(\n            [&](const auto& sz) {\n                n = sz.size()\
    \ >> 1;\n                seg.resize(n << 1);\n                rep (i, n << 1)\
    \ seg[i] = SegmentTree<M>(sz[i]);\n            },\n            xs, ys);\n    }\n\
    \    SegmentTree2D(const std::vector<ll>& xs, const std::vector<ll>& ys,\n   \
    \               const std::vector<T>& v) {\n        auto f = [&](const auto& dat)\
    \ {\n            n = dat.size() >> 1;\n            seg.resize(n << 1);\n     \
    \       rep (i, n << 1) seg[i] = SegmentTree<M>(dat[i]);\n        };\n       \
    \ str.init<decltype((f)), M>(f, xs, ys, v);\n    }\n\n    template<class Upd>\
    \ void update(ll x, ll y, Upd&& upd) {\n        T cur = M::id();\n        str.update(\n\
    \            x, y,\n            [&](int k, int i) {\n                seg[k].update(i,\
    \ upd);\n                cur = seg[k].get(i);\n            },\n            [&](int\
    \ k, int i) { seg[k].set(i, cur); },\n            [&](int k, int i, bool f) {\n\
    \                if (f) cur = M::op(cur, seg[k].get(i));\n                else\
    \ cur = M::op(seg[k].get(i), cur);\n            });\n    }\n    void set(ll x,\
    \ ll y, const T& v) {\n        update(x, y, [&](const T&) { return v; });\n  \
    \  }\n    void apply(ll x, ll y, const T& v) {\n        str.apply(x, y, [&](int\
    \ k, int i) { seg[k].apply(i, v); });\n    }\n    T prod(ll l, ll r, ll u, ll\
    \ d) const {\n        T lsm = M::id(), rsm = M::id();\n        str.prod(l, r,\
    \ u, d, [&](int k, int a, int b, bool f) {\n            if (f) lsm = M::op(lsm,\
    \ seg[k].prod(a, b));\n            else rsm = M::op(seg[k].prod(a, b), rsm);\n\
    \        });\n        return M::op(lsm, rsm);\n    }\n    T get(ll x, ll y) {\n\
    \        T res = M::id();\n        str.get(x, y, [&](int k, int i) { res = seg[k].get(i);\
    \ });\n        return res;\n    }\n    T all_prod() const { return seg[1].all_prod();\
    \ }\n};\n\n/**\n * @brief SegmentTree2D\n * @docs docs/data-struct/2D/SegmentTree2D.md\n\
    \ */\n"
  code: "#pragma once\n\n#include \"../../other/template.hpp\"\n#include \"../../other/monoid.hpp\"\
    \n#include \"../segment/SegmentTree.hpp\"\n#include \"Struct2D.hpp\"\n\ntemplate<class\
    \ M> class SegmentTree2D {\nprivate:\n    using T = typename M::value_type;\n\
    \    int n;\n    std::vector<SegmentTree<M>> seg;\n    Struct2D str;\n\npublic:\n\
    \    SegmentTree2D(const std::vector<ll>& xs, const std::vector<ll>& ys) {\n \
    \       str.init(\n            [&](const auto& sz) {\n                n = sz.size()\
    \ >> 1;\n                seg.resize(n << 1);\n                rep (i, n << 1)\
    \ seg[i] = SegmentTree<M>(sz[i]);\n            },\n            xs, ys);\n    }\n\
    \    SegmentTree2D(const std::vector<ll>& xs, const std::vector<ll>& ys,\n   \
    \               const std::vector<T>& v) {\n        auto f = [&](const auto& dat)\
    \ {\n            n = dat.size() >> 1;\n            seg.resize(n << 1);\n     \
    \       rep (i, n << 1) seg[i] = SegmentTree<M>(dat[i]);\n        };\n       \
    \ str.init<decltype((f)), M>(f, xs, ys, v);\n    }\n\n    template<class Upd>\
    \ void update(ll x, ll y, Upd&& upd) {\n        T cur = M::id();\n        str.update(\n\
    \            x, y,\n            [&](int k, int i) {\n                seg[k].update(i,\
    \ upd);\n                cur = seg[k].get(i);\n            },\n            [&](int\
    \ k, int i) { seg[k].set(i, cur); },\n            [&](int k, int i, bool f) {\n\
    \                if (f) cur = M::op(cur, seg[k].get(i));\n                else\
    \ cur = M::op(seg[k].get(i), cur);\n            });\n    }\n    void set(ll x,\
    \ ll y, const T& v) {\n        update(x, y, [&](const T&) { return v; });\n  \
    \  }\n    void apply(ll x, ll y, const T& v) {\n        str.apply(x, y, [&](int\
    \ k, int i) { seg[k].apply(i, v); });\n    }\n    T prod(ll l, ll r, ll u, ll\
    \ d) const {\n        T lsm = M::id(), rsm = M::id();\n        str.prod(l, r,\
    \ u, d, [&](int k, int a, int b, bool f) {\n            if (f) lsm = M::op(lsm,\
    \ seg[k].prod(a, b));\n            else rsm = M::op(seg[k].prod(a, b), rsm);\n\
    \        });\n        return M::op(lsm, rsm);\n    }\n    T get(ll x, ll y) {\n\
    \        T res = M::id();\n        str.get(x, y, [&](int k, int i) { res = seg[k].get(i);\
    \ });\n        return res;\n    }\n    T all_prod() const { return seg[1].all_prod();\
    \ }\n};\n\n/**\n * @brief SegmentTree2D\n * @docs docs/data-struct/2D/SegmentTree2D.md\n\
    \ */\n"
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
  - other/monoid.hpp
  - data-struct/segment/SegmentTree.hpp
  - data-struct/2D/Struct2D.hpp
  isVerificationFile: false
  path: data-struct/2D/SegmentTree2D.hpp
  requiredBy: []
  timestamp: '2024-05-12 12:21:41+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/data_structure/point_add_rectangle_sum-2DSegTree.test.cpp
documentation_of: data-struct/2D/SegmentTree2D.hpp
layout: document
redirect_from:
- /library/data-struct/2D/SegmentTree2D.hpp
- /library/data-struct/2D/SegmentTree2D.hpp.html
title: SegmentTree2D
---
