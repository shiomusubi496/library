---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/Combinatorics.hpp
    title: Combinatorics
  - icon: ':question:'
    path: math/MillerRabin.hpp
    title: "MillerRabin(\u30DF\u30E9\u30FC\u30E9\u30D3\u30F3\u7D20\u6570\u5224\u5B9A\
      )"
  - icon: ':question:'
    path: math/ModInt.hpp
    title: ModInt
  - icon: ':question:'
    path: math/MontgomeryModInt.hpp
    title: "MontgomeryModInt(\u30E2\u30F3\u30B4\u30E1\u30EA\u4E57\u7B97)"
  - icon: ':question:'
    path: math/PollardRho.hpp
    title: "PollardRho(\u7D20\u56E0\u6570\u5206\u89E3)"
  - icon: ':question:'
    path: math/PrimitiveRoot.hpp
    title: "PrimitiveRoot(\u539F\u59CB\u6839)"
  - icon: ':question:'
    path: math/SqrtMod.hpp
    title: "SqrtMod(\u5E73\u65B9\u5270\u4F59)"
  - icon: ':question:'
    path: math/convolution/Convolution.hpp
    title: "Convolution(\u7573\u307F\u8FBC\u307F)"
  - icon: ':question:'
    path: math/poly/FormalPowerSeries.hpp
    title: "FormalPowerSeries(\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570)"
  - icon: ':question:'
    path: math/poly/SparseFormalPowerSeries.hpp
    title: "SparseFormalPowerSeries(\u758E\u306A\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\
      )"
  - icon: ':question:'
    path: other/template.hpp
    title: other/template.hpp
  - icon: ':question:'
    path: random/Random.hpp
    title: Random
  - icon: ':question:'
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
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/exp_of_formal_power_series_sparse
    links:
    - https://judge.yosupo.jp/problem/exp_of_formal_power_series_sparse
  bundledCode: "#line 1 \"test/yosupo/polynomial/exp_of_formal_power_series_sparse.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/exp_of_formal_power_series_sparse\"\
    \n#line 2 \"other/template.hpp\"\n\n#include <bits/stdc++.h>\n#line 2 \"template/macros.hpp\"\
    \n\n#line 4 \"template/macros.hpp\"\n\n#ifndef __COUNTER__\n#define __COUNTER__\
    \ __LINE__\n#endif\n\n#define REP_SELECTER(a, b, c, d, e, ...) e\n#define REP1_0(b,\
    \ c) REP1_1(b, c)\n#define REP1_1(b, c)                                      \
    \                     \\\n    for (ll REP_COUNTER_##c = 0; REP_COUNTER_##c < (ll)(b);\
    \ ++REP_COUNTER_##c)\n#define REP1(b) REP1_0(b, __COUNTER__)\n#define REP2(i,\
    \ b) for (ll i = 0; i < (ll)(b); ++i)\n#define REP3(i, a, b) for (ll i = (ll)(a);\
    \ i < (ll)(b); ++i)\n#define REP4(i, a, b, c) for (ll i = (ll)(a); i < (ll)(b);\
    \ i += (ll)(c))\n#define rep(...) REP_SELECTER(__VA_ARGS__, REP4, REP3, REP2,\
    \ REP1)(__VA_ARGS__)\n#define RREP2(i, a) for (ll i = (ll)(a)-1; i >= 0; --i)\n\
    #define RREP3(i, a, b) for (ll i = (ll)(a)-1; i >= (ll)(b); --i)\n#define RREP4(i,\
    \ a, b, c) for (ll i = (ll)(a)-1; i >= (ll)(b); i -= (ll)(c))\n#define rrep(...)\
    \ REP_SELECTER(__VA_ARGS__, RREP4, RREP3, RREP2)(__VA_ARGS__)\n#define REPS2(i,\
    \ b) for (ll i = 1; i <= (ll)(b); ++i)\n#define REPS3(i, a, b) for (ll i = (ll)(a)\
    \ + 1; i <= (ll)(b); ++i)\n#define REPS4(i, a, b, c) for (ll i = (ll)(a) + 1;\
    \ i <= (ll)(b); i += (ll)(c))\n#define reps(...) REP_SELECTER(__VA_ARGS__, REPS4,\
    \ REPS3, REPS2)(__VA_ARGS__)\n#define RREPS2(i, a) for (ll i = (ll)(a); i > 0;\
    \ --i)\n#define RREPS3(i, a, b) for (ll i = (ll)(a); i > (ll)(b); --i)\n#define\
    \ RREPS4(i, a, b, c) for (ll i = (ll)(a); i > (ll)(b); i -= (ll)(c))\n#define\
    \ rreps(...)                                                             \\\n\
    \    REP_SELECTER(__VA_ARGS__, RREPS4, RREPS3, RREPS2)(__VA_ARGS__)\n\n#define\
    \ each_for(...) for (auto&& __VA_ARGS__)\n#define each_const(...) for (const auto&\
    \ __VA_ARGS__)\n\n#define all(v) std::begin(v), std::end(v)\n#if __cplusplus >=\
    \ 201402L\n#define rall(v) std::rbegin(v), std::rend(v)\n#else\n#define rall(v)\
    \ v.rbegin(), v.rend()\n#endif\n\n#if __cpp_constexpr >= 201304L\n#define CONSTEXPR\
    \ constexpr\n#else\n#define CONSTEXPR\n#endif\n\n#if __cpp_if_constexpr >= 201606L\n\
    #define IF_CONSTEXPR constexpr\n#else\n#define IF_CONSTEXPR\n#endif\n\n#define\
    \ IO_BUFFER_SIZE 2048\n#line 2 \"template/alias.hpp\"\n\n#line 4 \"template/alias.hpp\"\
    \n\nusing ll = long long;\nusing ull = unsigned long long;\nusing ld = long double;\n\
    using PLL = std::pair<ll, ll>;\ntemplate<class T>\nusing prique = std::priority_queue<T,\
    \ std::vector<T>, std::greater<T>>;\n\ntemplate<class T> class infinity {\npublic:\n\
    \    static constexpr T value = std::numeric_limits<T>::max() / 2;\n    static\
    \ constexpr T mvalue = std::numeric_limits<T>::min() / 2;\n    static constexpr\
    \ T max = std::numeric_limits<T>::max();\n    static constexpr T min = std::numeric_limits<T>::min();\n\
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
    \ Args...>;\n};\n#endif\n\ntemplate<class F>\nusing function_traits =\n    typename\
    \ function_traits_helper<decltype(&F::operator())>::type;\n\n\ntemplate<class\
    \ T>\nusing is_signed_int =\n    std::disjunction<std::conjunction<std::is_integral<T>,\
    \ std::is_signed<T>>,\n                     std::is_same<T, __int128_t>>;\ntemplate<class\
    \ T>\nusing is_unsigned_int =\n    std::disjunction<std::conjunction<std::is_integral<T>,\
    \ std::is_unsigned<T>>,\n                     std::is_same<T, __uint128_t>>;\n\
    template<class T>\nusing is_int = std::disjunction<is_signed_int<T>, is_unsigned_int<T>>;\n\
    template<class T>\nusing make_signed_int = typename std::conditional<\n    std::is_same<T,\
    \ __int128_t>::value || std::is_same<T, __uint128_t>::value,\n    std::common_type<__int128_t>,\
    \ std::make_signed<T>>::type;\ntemplate<class T>\nusing make_unsigned_int = typename\
    \ std::conditional<\n    std::is_same<T, __int128_t>::value || std::is_same<T,\
    \ __uint128_t>::value,\n    std::common_type<__uint128_t>, std::make_unsigned<T>>::type;\n\
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
    \ <= 64, std::int_least64_t,\n                                          __int128_t>::type>::type>::type>::\n\
    \        type;\n};\n\ntemplate<std::size_t size> using int_least_t = typename\
    \ int_least<size>::type;\n\ntemplate<std::size_t size> struct uint_least {\n \
    \   static_assert(size <= 128, \"size must be less than or equal to 128\");\n\n\
    \    using type = typename std::conditional<\n        size <= 8, std::uint_least8_t,\n\
    \        typename std::conditional<\n            size <= 16, std::uint_least16_t,\n\
    \            typename std::conditional<\n                size <= 32, std::uint_least32_t,\n\
    \                typename std::conditional<size <= 64, std::uint_least64_t,\n\
    \                                          __uint128_t>::type>::type>::type>::\n\
    \        type;\n};\n\ntemplate<std::size_t size> using uint_least_t = typename\
    \ uint_least<size>::type;\n\ntemplate<class T>\nusing double_size_int = int_least<std::numeric_limits<T>::digits\
    \ * 2 + 1>;\ntemplate<class T> using double_size_int_t = typename double_size_int<T>::type;\n\
    template<class T>\nusing double_size_uint = uint_least<std::numeric_limits<T>::digits\
    \ * 2>;\ntemplate<class T> using double_size_uint_t = typename double_size_uint<T>::type;\n\
    \ntemplate<class T>\nusing double_size =\n    typename std::conditional<is_signed_int<T>::value,\
    \ double_size_int<T>,\n                              double_size_uint<T>>::type;\n\
    template<class T> using double_size_t = typename double_size<T>::type;\n#line\
    \ 2 \"template/in.hpp\"\n\n#line 4 \"template/in.hpp\"\n#include <unistd.h>\n\
    #line 8 \"template/in.hpp\"\n\ntemplate<std::size_t buf_size = IO_BUFFER_SIZE>\
    \ class Reader {\nprivate:\n    int fd, idx, sz;\n    bool state;\n    std::array<char,\
    \ buf_size> buffer;\n    inline void read_buf() {\n        sz = read(fd, buffer.begin(),\
    \ buf_size);\n        idx = 0;\n        if (sz < 0) throw std::runtime_error(\"\
    input failed\");\n    }\n\npublic:\n    static constexpr int get_buf_size() {\
    \ return buf_size; }\n    Reader() noexcept : fd(0), idx(0), sz(0), state(true)\
    \ {}\n    Reader(int fd) noexcept : fd(fd), idx(0), sz(0), state(true) {}\n  \
    \  Reader(FILE* fp) noexcept : fd(fileno(fp)), idx(0), sz(0), state(true) {}\n\
    \n    class iterator {\n    private:\n        Reader* reader;\n\n    public:\n\
    \        using difference_type = void;\n        using value_type = void;\n   \
    \     using pointer = void;\n        using reference = void;\n        using iterator_category\
    \ = std::input_iterator_tag;\n\n        iterator() : reader(nullptr) {}\n    \
    \    explicit iterator(Reader& reader) : reader(&reader) {}\n        explicit\
    \ iterator(Reader* reader) : reader(reader) {}\n\n        iterator& operator++()\
    \ {\n            if (reader->idx == reader->sz) reader->read_buf();\n        \
    \    ++reader->idx;\n            return *this;\n        }\n        iterator operator++(int)\
    \ {\n            iterator res = *this;\n            ++(*this);\n            return\
    \ res;\n        }\n        char operator*() const {\n            if (reader->idx\
    \ == reader->sz) reader->read_buf();\n            if (reader->idx < reader->sz)\
    \ return reader->buffer[reader->idx];\n            reader->state = false;\n  \
    \          return '\\0';\n        }\n        bool rdstate() const { return reader->state;\
    \ }\n        void setstate(bool state) { reader->state = state; }\n    };\n\n\
    \    iterator begin() noexcept { return iterator(this); }\n};\n\nReader<> reader(0);\n\
    \ntemplate<class Iterator, std::size_t decimal_precision = 16> class Scanner {\n\
    public:\n    using iterator_type = Iterator;\n\nprivate:\n    template<class,\
    \ class = void> struct has_scan : std::false_type {};\n    template<class T>\n\
    \    struct has_scan<\n        T, decltype(std::declval<T>().scan(std::declval<Scanner&>()),\
    \ (void)0)>\n        : std::true_type {};\n    Iterator itr;\n\npublic:\n    Scanner()\
    \ = default;\n    Scanner(const Iterator& itr) : itr(itr) {}\n\n    char scan_char()\
    \ {\n        char c = *itr;\n        ++itr;\n        return c;\n    }\n\n    Scanner\
    \ ignore(int n = 1) {\n        rep (n) ++itr;\n        return *this;\n    }\n\n\
    \    inline void discard_space() {\n        while (('\\t' <= *itr && *itr <= '\\\
    r') || *itr == ' ') ++itr;\n    }\n    void scan(char& a) {\n        discard_space();\n\
    \        a = *itr;\n        ++itr;\n    }\n    void scan(bool& a) {\n        discard_space();\n\
    \        a = *itr != '0';\n        ++itr;\n    }\n    void scan(std::string& a)\
    \ {\n        discard_space();\n        a.clear();\n        while ((*itr < '\\\
    t' || '\\r' < *itr) && *itr != ' ' && *itr != '\\0') {\n            a += *itr;\n\
    \            ++itr;\n        }\n    }\n    template<std::size_t len> void scan(std::bitset<len>&\
    \ a) {\n        discard_space();\n        rrep (i, len) {\n            a[i] =\
    \ *itr != '0';\n            ++itr;\n        }\n    }\n    template<class T,\n\
    \             typename std::enable_if<is_signed_int<T>::value &&\n           \
    \                          !has_scan<T>::value>::type* = nullptr>\n    void scan(T&\
    \ a) {\n        discard_space();\n        if (*itr == '-') {\n            ++itr;\n\
    \            a = 0;\n            while ('0' <= *itr && *itr <= '9') {\n      \
    \          a = a * 10 - (*itr - '0');\n                ++itr;\n            }\n\
    \        }\n        else {\n            a = 0;\n            while ('0' <= *itr\
    \ && *itr <= '9') {\n                a = a * 10 + (*itr - '0');\n            \
    \    ++itr;\n            }\n        }\n    }\n    template<class T,\n        \
    \     typename std::enable_if<is_unsigned_int<T>::value &&\n                 \
    \                    !has_scan<T>::value>::type* = nullptr>\n    void scan(T&\
    \ a) {\n        discard_space();\n        a = 0;\n        while ('0' <= *itr &&\
    \ *itr <= '9') {\n            a = a * 10 + *itr - '0';\n            ++itr;\n \
    \       }\n    }\n    template<class T,\n             typename std::enable_if<std::is_floating_point<T>::value\
    \ &&\n                                     !has_scan<T>::value>::type* = nullptr>\n\
    \    void scan(T& a) {\n        discard_space();\n        bool sgn = false;\n\
    \        if (*itr == '-') {\n            sgn = true;\n            ++itr;\n   \
    \     }\n        a = 0;\n        while ('0' <= *itr && *itr <= '9') {\n      \
    \      a = a * 10 + *itr - '0';\n            ++itr;\n        }\n        if (*itr\
    \ == '.') {\n            ++itr;\n            T n = 0, d = 1;\n            for\
    \ (int i = 0;\n                 '0' <= *itr && *itr <= '9' && i < (int)decimal_precision;\n\
    \                 ++i) {\n                n = n * 10 + *itr - '0';\n         \
    \       d *= 10;\n                ++itr;\n            }\n            while ('0'\
    \ <= *itr && *itr <= '9') ++itr;\n            a += n / d;\n        }\n       \
    \ if (sgn) a = -a;\n    }\n\nprivate:\n    template<std::size_t i, class... Args>\
    \ void scan(std::tuple<Args...>& a) {\n        if IF_CONSTEXPR (i < sizeof...(Args))\
    \ {\n            scan(std::get<i>(a));\n            scan<i + 1, Args...>(a);\n\
    \        }\n    }\n\npublic:\n    template<class... Args> void scan(std::tuple<Args...>&\
    \ a) {\n        scan<0, Args...>(a);\n    }\n    template<class T, class U> void\
    \ scan(std::pair<T, U>& a) {\n        scan(a.first);\n        scan(a.second);\n\
    \    }\n    template<class T,\n             typename std::enable_if<is_range<T>::value\
    \ &&\n                                     !has_scan<T>::value>::type* = nullptr>\n\
    \    void scan(T& a) {\n        each_for (i : a) scan(i);\n    }\n    template<class\
    \ T,\n             typename std::enable_if<has_scan<T>::value>::type* = nullptr>\n\
    \    void scan(T& a) {\n        a.scan(*this);\n    }\n\n    void operator()()\
    \ {}\n    template<class Head, class... Args>\n    void operator()(Head& head,\
    \ Args&... args) {\n        scan(head);\n        operator()(args...);\n    }\n\
    \n    template<class T> Scanner& operator>>(T& a) {\n        scan(a);\n      \
    \  return *this;\n    }\n\n    explicit operator bool() const { return itr.rdstate();\
    \ }\n\n    friend Scanner& getline(Scanner& scan, std::string& a) {\n        a.erase();\n\
    \        char c;\n        if ((c = scan.scan_char()) == '\\n' || c == '\\0') return\
    \ scan;\n        a += c;\n        while ((c = scan.scan_char()) != '\\n' && c\
    \ != '\\0') a += c;\n        scan.itr.setstate(true);\n        return scan;\n\
    \    }\n};\n\nScanner<Reader<>::iterator> scan(reader.begin());\n#line 2 \"template/out.hpp\"\
    \n\n#line 8 \"template/out.hpp\"\n\ntemplate<std::size_t buf_size = IO_BUFFER_SIZE>\
    \ class Writer {\nprivate:\n    int fd, idx;\n    std::array<char, buf_size> buffer;\n\
    \    inline void write_buf() {\n        int num = write(fd, buffer.begin(), idx);\n\
    \        idx = 0;\n        if (num < 0) throw std::runtime_error(\"output failed\"\
    );\n    }\n\npublic:\n    Writer() noexcept : fd(1), idx(0) {}\n    Writer(int\
    \ fd) noexcept : fd(fd), idx(0) {}\n    Writer(FILE* fp) noexcept : fd(fileno(fp)),\
    \ idx(0) {}\n\n    ~Writer() { write_buf(); }\n\n    class iterator {\n    private:\n\
    \        Writer* writer;\n\n    public:\n        using difference_type = void;\n\
    \        using value_type = void;\n        using pointer = void;\n        using\
    \ reference = void;\n        using iterator_category = std::output_iterator_tag;\n\
    \n        iterator() noexcept : writer(nullptr) {}\n        explicit iterator(Writer&\
    \ writer) noexcept : writer(&writer) {}\n        explicit iterator(Writer* writer)\
    \ noexcept : writer(writer) {}\n\n        iterator& operator++() {\n         \
    \   ++writer->idx;\n            if (writer->idx == buf_size) writer->write_buf();\n\
    \            return *this;\n        }\n        iterator operator++(int) {\n  \
    \          iterator res = *this;\n            ++(*this);\n            return res;\n\
    \        }\n        char& operator*() const { return writer->buffer[writer->idx];\
    \ }\n        void flush() const { writer->write_buf(); }\n    };\n\n    iterator\
    \ begin() noexcept { return iterator(this); }\n};\n\nWriter<> writer(1), ewriter(2);\n\
    \ntemplate<class Iterator, bool debug = false> class Printer {\npublic:\n    using\
    \ iterator_type = Iterator;\n\nprivate:\n    template<class, bool = debug, class\
    \ = void>\n    struct has_print : std::false_type {};\n    template<class T>\n\
    \    struct has_print<T, false,\n                     decltype(std::declval<T>().print(std::declval<Printer&>()),\n\
    \                              (void)0)> : std::true_type {};\n    template<class\
    \ T>\n    struct has_print<T, true,\n                     decltype(std::declval<T>().debug(std::declval<Printer&>()),\n\
    \                              (void)0)> : std::true_type {};\n    Iterator itr;\n\
    \    std::size_t decimal_precision;\n\npublic:\n    void print_char(char c) {\n\
    \        *itr = c;\n        ++itr;\n    }\n\n    void flush() { itr.flush(); }\n\
    \n    Printer() noexcept = default;\n    explicit Printer(const Iterator& itr)\
    \ noexcept\n        : itr(itr), decimal_precision(16) {}\n\n    void set_decimal_precision(std::size_t\
    \ decimal_precision) {\n        this->decimal_precision = decimal_precision;\n\
    \    }\n\n    void print(char c) {\n        if IF_CONSTEXPR (debug) print_char('\\\
    '');\n        print_char(c);\n        if IF_CONSTEXPR (debug) print_char('\\'');\n\
    \    }\n    void print(bool b) { print_char((char)(b + '0')); }\n    void print(const\
    \ char* a) {\n        if IF_CONSTEXPR (debug) print_char('\"');\n        for (;\
    \ *a != '\\0'; ++a) print_char(*a);\n        if IF_CONSTEXPR (debug) print_char('\"\
    ');\n    }\n    template<std::size_t len> void print(const char (&a)[len]) {\n\
    \        if IF_CONSTEXPR (debug) print_char('\"');\n        for (auto i : a) print_char(i);\n\
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
    \                return;\n            }\n        }\n        std::string s;\n \
    \       while (a) {\n            s += (char)(a % 10 + '0');\n            a /=\
    \ 10;\n        }\n        for (auto i = s.rbegin(); i != s.rend(); ++i) print_char(*i);\n\
    \    }\n    template<class T,\n             typename std::enable_if<std::is_floating_point<T>::value\
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
    \ { return pf(*this); }\n};\n\ntemplate<class Iterator, bool debug>\nPrinter<Iterator,\
    \ debug>& endl(Printer<Iterator, debug>& pr) {\n    pr.print_char('\\n');\n  \
    \  pr.flush();\n    return pr;\n}\ntemplate<class Iterator, bool debug>\nPrinter<Iterator,\
    \ debug>& flush(Printer<Iterator, debug>& pr) {\n    pr.flush();\n    return pr;\n\
    }\n\nstruct SetPrec {\n    int n;\n    template<class Pr> void print(Pr& pr) const\
    \ { pr.set_decimal_precision(n); }\n    template<class Pr> void debug(Pr& pr)\
    \ const { pr.set_decimal_precision(n); }\n};\nSetPrec setprec(int n) { return\
    \ SetPrec{n}; };\n\nPrinter<Writer<>::iterator> print(writer.begin()), eprint(ewriter.begin());\n\
    \ntemplate<class T> auto prints(const T& v) -> decltype(print << v, (void)0) {\n\
    \    print << v;\n    print.print_char('\\n');\n}\n\ntemplate<class Head, class...\
    \ Tail>\nauto prints(const Head& head, const Tail&... tail)\n    -> decltype(print\
    \ << head, (void)0) {\n    print << head;\n    print.print_char(' ');\n    prints(tail...);\n\
    }\n\n#ifdef SHIO_LOCAL\nPrinter<Writer<>::iterator, true> debug(writer.begin()),\n\
    \    edebug(ewriter.begin());\n#else\nchar debug_iterator_character;\nclass DebugIterator\
    \ {\npublic:\n    DebugIterator() noexcept = default;\n    DebugIterator& operator++()\
    \ { return *this; }\n    DebugIterator& operator++(int) { return *this; }\n  \
    \  char& operator*() const { return debug_iterator_character; }\n    void flush()\
    \ const {}\n};\nPrinter<DebugIterator> debug, edebug;\n#endif\n\ntemplate<class\
    \ T> auto debugs(const T& v) -> decltype(debug << v, (void)0) {\n    debug <<\
    \ v;\n    debug.print_char('\\n');\n}\n\ntemplate<class Head, class... Tail>\n\
    auto debugs(const Head& head, const Tail&... tail)\n    -> decltype(debug << head,\
    \ (void)0) {\n    debug << head;\n    debug.print_char(' ');\n    debugs(tail...);\n\
    }\n#line 2 \"template/bitop.hpp\"\n\n#line 6 \"template/bitop.hpp\"\n\nnamespace\
    \ bitop {\n\n#define KTH_BIT(b, k) (((b) >> (k)) & 1)\n#define POW2(k) (1ull <<\
    \ (k))\n\ninline ull next_combination(int n, ull x) {\n    if (n == 0) return\
    \ 1;\n    ull a = x & -x;\n    ull b = x + a;\n    return (x & ~b) / a >> 1 |\
    \ b;\n}\n\n#define rep_comb(i, n, k)                                         \
    \             \\\n    for (ull i = (1ull << (k)) - 1; i < (1ull << (n));     \
    \                    \\\n         i = bitop::next_combination((n), i))\n\ninline\
    \ CONSTEXPR int msb(ull x) {\n    int res = x ? 0 : -1;\n    if (x & 0xFFFFFFFF00000000)\
    \ x &= 0xFFFFFFFF00000000, res += 32;\n    if (x & 0xFFFF0000FFFF0000) x &= 0xFFFF0000FFFF0000,\
    \ res += 16;\n    if (x & 0xFF00FF00FF00FF00) x &= 0xFF00FF00FF00FF00, res +=\
    \ 8;\n    if (x & 0xF0F0F0F0F0F0F0F0) x &= 0xF0F0F0F0F0F0F0F0, res += 4;\n   \
    \ if (x & 0xCCCCCCCCCCCCCCCC) x &= 0xCCCCCCCCCCCCCCCC, res += 2;\n    return res\
    \ + ((x & 0xAAAAAAAAAAAAAAAA) ? 1 : 0);\n}\n\ninline CONSTEXPR int ceil_log2(ull\
    \ x) { return x ? msb(x - 1) + 1 : 0; }\n\ninline CONSTEXPR ull reverse(ull x)\
    \ {\n    x = ((x & 0xAAAAAAAAAAAAAAAA) >> 1) | ((x & 0x5555555555555555) << 1);\n\
    \    x = ((x & 0xCCCCCCCCCCCCCCCC) >> 2) | ((x & 0x3333333333333333) << 2);\n\
    \    x = ((x & 0xF0F0F0F0F0F0F0F0) >> 4) | ((x & 0x0F0F0F0F0F0F0F0F) << 4);\n\
    \    x = ((x & 0xFF00FF00FF00FF00) >> 8) | ((x & 0x00FF00FF00FF00FF) << 8);\n\
    \    x = ((x & 0xFFFF0000FFFF0000) >> 16) | ((x & 0x0000FFFF0000FFFF) << 16);\n\
    \    return (x >> 32) | (x << 32);\n}\n\ninline CONSTEXPR ull reverse(ull x, int\
    \ n) { return reverse(x) >> (64 - n); }\n\n} // namespace bitop\n\ninline CONSTEXPR\
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
    \ {\n    return cmp(a, b) ? a = b, true : false;\n}\n\ninline CONSTEXPR ll gcd(ll\
    \ a, ll b) noexcept {\n    if (a < 0) a = -a;\n    if (b < 0) b = -b;\n    while\
    \ (b) {\n        const ll c = a;\n        a = b;\n        b = c % b;\n    }\n\
    \    return a;\n}\ninline CONSTEXPR ll lcm(ll a, ll b) noexcept { return a / gcd(a,\
    \ b) * b; }\n\ninline CONSTEXPR bool is_prime(ll N) noexcept {\n    if (N <= 1)\
    \ return false;\n    for (ll i = 2; i * i <= N; ++i) {\n        if (N % i == 0)\
    \ return false;\n    }\n    return true;\n}\ninline std::vector<ll> prime_factor(ll\
    \ N) {\n    std::vector<ll> res;\n    for (ll i = 2; i * i <= N; ++i) {\n    \
    \    while (N % i == 0) {\n            res.push_back(i);\n            N /= i;\n\
    \        }\n    }\n    if (N != 1) res.push_back(N);\n    return res;\n}\n\ninline\
    \ CONSTEXPR ll my_pow(ll a, ll b) noexcept {\n    ll res = 1;\n    while (b) {\n\
    \        if (b & 1) res *= a;\n        b >>= 1;\n        a *= a;\n    }\n    return\
    \ res;\n}\ninline CONSTEXPR ll mod_pow(ll a, ll b, ll mod) {\n    assert(mod >\
    \ 0);\n    if (mod == 1) return 0;\n    a %= mod;\n    ll res = 1;\n    while\
    \ (b) {\n        if (b & 1) (res *= a) %= mod;\n        b >>= 1;\n        (a *=\
    \ a) %= mod;\n    }\n    return res;\n}\n\ninline PLL extGCD(ll a, ll b) {\n \
    \   const ll n = a, m = b;\n    ll x = 1, y = 0, u = 0, v = 1;\n    ll t;\n  \
    \  while (b) {\n        t = a / b;\n        std::swap(a -= t * b, b);\n      \
    \  std::swap(x -= t * u, u);\n        std::swap(y -= t * v, v);\n    }\n    if\
    \ (x < 0) {\n        x += m;\n        y -= n;\n    }\n    return {x, y};\n}\n\
    inline ll mod_inv(ll a, ll mod) {\n    ll b = mod;\n    ll x = 1, u = 0;\n   \
    \ ll t;\n    while (b) {\n        t = a / b;\n        std::swap(a -= t * b, b);\n\
    \        std::swap(x -= t * u, u);\n    }\n    if (x < 0) x += mod;\n    assert(a\
    \ == 1);\n    return x;\n}\n#line 2 \"template/util.hpp\"\n\n#line 6 \"template/util.hpp\"\
    \n\ntemplate<class F> class RecLambda {\nprivate:\n    F f;\n\npublic:\n    explicit\
    \ constexpr RecLambda(F&& f_) : f(std::forward<F>(f_)) {}\n    template<class...\
    \ Args>\n    constexpr auto operator()(Args&&... args)\n        -> decltype(f(*this,\
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
    }\n\ntemplate<class T, class Comp = std::less<T>> class presser {\nprivate:\n\
    \    std::vector<T> dat;\n    Comp cmp;\n    bool sorted = false;\n\npublic:\n\
    \    presser() : presser(Comp()) {}\n    presser(const Comp& cmp) : cmp(cmp) {}\n\
    \    presser(const std::vector<T>& vec, const Comp& cmp = Comp())\n        : dat(vec),\
    \ cmp(cmp) {}\n    presser(std::vector<T>&& vec, const Comp& cmp = Comp())\n \
    \       : dat(std::move(vec)), cmp(cmp) {}\n    presser(std::initializer_list<T>\
    \ il, const Comp& cmp = Comp())\n        : dat(all(il)), cmp(cmp) {}\n    void\
    \ reserve(int n) {\n        assert(!sorted);\n        dat.reserve(n);\n    }\n\
    \    void push_back(const T& v) {\n        assert(!sorted);\n        dat.push_back(v);\n\
    \    }\n    void push_back(T&& v) {\n        assert(!sorted);\n        dat.push_back(std::move(v));\n\
    \    }\n    template<class... Args> void emplace_back(Args&&... args) {\n    \
    \    assert(!sorted);\n        dat.emplace_back(std::forward<Args>(args)...);\n\
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
    \    }\n    int get(const T& val) const {\n        assert(sorted);\n        auto\
    \ itr = std::lower_bound(all(dat), val, cmp);\n        assert(itr != dat.end()\
    \ && !cmp(val, *itr));\n        return itr - dat.begin();\n    }\n    int lower_bound(const\
    \ T& val) const {\n        assert(sorted);\n        auto itr = std::lower_bound(all(dat),\
    \ val, cmp);\n        return itr - dat.begin();\n    }\n    int upper_bound(const\
    \ T& val) const {\n        assert(sorted);\n        auto itr = std::upper_bound(all(dat),\
    \ val, cmp);\n        return itr - dat.begin();\n    }\n    bool contains(const\
    \ T& val) const {\n        assert(sorted);\n        return std::binary_search(all(dat),\
    \ val, cmp);\n    }\n    std::vector<int> pressed(const std::vector<T>& vec) const\
    \ {\n        assert(sorted);\n        std::vector<int> res(vec.size());\n    \
    \    rep (i, vec.size()) res[i] = get(vec[i]);\n        return res;\n    }\n \
    \   void press(std::vector<T>& vec) const {\n        static_assert(std::is_convertible<T,\
    \ int>::value,\n                      \"template argument must be convertible\
    \ from int type\");\n        assert(sorted);\n        each_for (i : vec) i = get(i);\n\
    \    }\n    int size() const {\n        assert(sorted);\n        return dat.size();\n\
    \    }\n    const std::vector<T>& data() const& { return dat; }\n    std::vector<T>\
    \ data() && { return std::move(dat); }\n};\n#line 2 \"math/poly/FormalPowerSeries.hpp\"\
    \n\n#line 2 \"math/convolution/Convolution.hpp\"\n\n#line 2 \"math/ModInt.hpp\"\
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
    \ 873463809, 443664157, 299473306};\n\npublic:\n    constexpr StaticModInt() :\
    \ val(0) {}\n    template<class U,\n             typename std::enable_if<std::is_integral<U>::value\
    \ &&\n                                     std::is_signed<U>::value>::type* =\
    \ nullptr>\n    constexpr StaticModInt(U v) : val{} {\n        v %= static_cast<signed_t>(mod);\n\
    \        if (v < 0) v += static_cast<signed_t>(mod);\n        val = static_cast<T>(v);\n\
    \    }\n    template<class U, typename std::enable_if<\n                     \
    \     std::is_integral<U>::value &&\n                          std::is_unsigned<U>::value>::type*\
    \ = nullptr>\n    constexpr StaticModInt(U v) : val(v % mod) {}\n    T get() const\
    \ { return val; }\n    static constexpr T get_mod() { return mod; }\n    static\
    \ StaticModInt raw(T v) {\n        StaticModInt res;\n        res.val = v;\n \
    \       return res;\n    }\n    StaticModInt inv() const {\n        if IF_CONSTEXPR\
    \ (mod == 1000000007) {\n            if (val <= 10) return inv1000000007[val];\n\
    \        }\n        else if IF_CONSTEXPR (mod == 998244353) {\n            if\
    \ (val <= 10) return inv998244353[val];\n        }\n        return mod_inv(val,\
    \ mod);\n    }\n    StaticModInt& operator++() {\n        ++val;\n        if (val\
    \ == mod) val = 0;\n        return *this;\n    }\n    StaticModInt operator++(int)\
    \ {\n        StaticModInt res = *this;\n        ++*this;\n        return res;\n\
    \    }\n    StaticModInt& operator--() {\n        if (val == 0) val = mod;\n \
    \       --val;\n        return *this;\n    }\n    StaticModInt operator--(int)\
    \ {\n        StaticModInt res = *this;\n        --*this;\n        return res;\n\
    \    }\n    StaticModInt& operator+=(const StaticModInt& other) {\n        val\
    \ += other.val;\n        if (val >= mod) val -= mod;\n        return *this;\n\
    \    }\n    StaticModInt& operator-=(const StaticModInt& other) {\n        if\
    \ (val < other.val) val += mod;\n        val -= other.val;\n        return *this;\n\
    \    }\n    StaticModInt& operator*=(const StaticModInt& other) {\n        large_t\
    \ a = val;\n        a *= other.val;\n        a %= mod;\n        val = a;\n   \
    \     return *this;\n    }\n    StaticModInt& operator/=(const StaticModInt& other)\
    \ {\n        *this *= other.inv();\n        return *this;\n    }\n    friend StaticModInt\
    \ operator+(const StaticModInt& lhs,\n                                  const\
    \ StaticModInt& rhs) {\n        return StaticModInt(lhs) += rhs;\n    }\n    friend\
    \ StaticModInt operator-(const StaticModInt& lhs,\n                          \
    \        const StaticModInt& rhs) {\n        return StaticModInt(lhs) -= rhs;\n\
    \    }\n    friend StaticModInt operator*(const StaticModInt& lhs,\n         \
    \                         const StaticModInt& rhs) {\n        return StaticModInt(lhs)\
    \ *= rhs;\n    }\n    friend StaticModInt operator/(const StaticModInt& lhs,\n\
    \                                  const StaticModInt& rhs) {\n        return\
    \ StaticModInt(lhs) /= rhs;\n    }\n    StaticModInt operator+() const { return\
    \ StaticModInt(*this); }\n    StaticModInt operator-() const { return StaticModInt()\
    \ - *this; }\n    friend bool operator==(const StaticModInt& lhs, const StaticModInt&\
    \ rhs) {\n        return lhs.val == rhs.val;\n    }\n    friend bool operator!=(const\
    \ StaticModInt& lhs, const StaticModInt& rhs) {\n        return lhs.val != rhs.val;\n\
    \    }\n    StaticModInt pow(ll a) const {\n        StaticModInt v = *this, res\
    \ = 1;\n        while (a) {\n            if (a & 1) res *= v;\n            a >>=\
    \ 1;\n            v *= v;\n        }\n        return res;\n    }\n    template<class\
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
    \n/**\n * @brief ModInt\n * @docs docs/math/ModInt.md\n */\n#line 2 \"math/PrimitiveRoot.hpp\"\
    \n\n#line 2 \"random/Random.hpp\"\n\n#line 4 \"random/Random.hpp\"\n\ntemplate<class\
    \ Engine> class Random {\nprivate:\n    Engine rnd;\n\npublic:\n    using result_type\
    \ = typename Engine::result_type;\n    Random() : Random(std::random_device{}())\
    \ {}\n    Random(result_type seed) : rnd(seed) {}\n    result_type operator()()\
    \ { return rnd(); }\n    template<class IntType = ll> IntType uniform(IntType\
    \ l, IntType r) {\n        static_assert(std::is_integral<IntType>::value,\n \
    \                     \"template argument must be an integral type\");\n     \
    \   assert(l <= r);\n        return std::uniform_int_distribution<IntType>{l,\
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
    \ntemplate<class T> CONSTEXPR bool miller_rabin(ull n, const ull base[], int s)\
    \ {\n    if (T::get_mod() != n) T::set_mod(n);\n    ull d = n - 1;\n    while\
    \ (~d & 1) d >>= 1;\n    T e{1}, re{n - 1};\n    rep (i, s) {\n        ull a =\
    \ base[i];\n        if (a >= n) return true;\n        ull t = d;\n        T y\
    \ = T(a).pow(t);\n        while (t != n - 1 && y != e && y != re) {\n        \
    \    y *= y;\n            t <<= 1;\n        }\n        if (y != re && !(t & 1))\
    \ return false;\n    }\n    return true;\n}\n\nCONSTEXPR bool is_prime_mr(ll n)\
    \ {\n    if (n == 2) return true;\n    if (n < 2 || n % 2 == 0) return false;\n\
    \    if (n < (1u << 31))\n        return miller_rabin<MontgomeryModInt<unsigned\
    \ int, -2>>(\n            n, base_miller_rabin_int, 3);\n    return miller_rabin<MontgomeryModInt<ull,\
    \ -2>>(n, base_miller_rabin_ll, 7);\n}\n\n#if __cpp_variable_templates >= 201304L\
    \ && __cpp_constexpr >= 201304L\ntemplate<ull n> constexpr bool is_prime_v = is_prime_mr(n);\n\
    #endif\n\n/**\n * @brief MillerRabin(\u30DF\u30E9\u30FC\u30E9\u30D3\u30F3\u7D20\
    \u6570\u5224\u5B9A)\n * @docs docs/math/MillerRabin.md\n */\n#line 2 \"math/PollardRho.hpp\"\
    \n\n#line 2 \"string/RunLength.hpp\"\n\n#line 4 \"string/RunLength.hpp\"\n\ntemplate<class\
    \ Cont, class Comp>\nstd::vector<std::pair<typename Cont::value_type, int>>\n\
    RunLength(const Cont& str, const Comp& cmp) {\n    std::vector<std::pair<typename\
    \ Cont::value_type, int>> res;\n    if (str.size() == 0) return res;\n    res.emplace_back(str[0],\
    \ 1);\n    rep (i, 1, str.size()) {\n        if (cmp(res.back().first, str[i]))\
    \ ++res.back().second;\n        else res.emplace_back(str[i], 1);\n    }\n   \
    \ return res;\n}\n\ntemplate<class Cont>\nstd::vector<std::pair<typename Cont::value_type,\
    \ int>>\nRunLength(const Cont& str) {\n    return RunLength(str, std::equal_to<typename\
    \ Cont::value_type>());\n}\n\n/**\n * @brief RunLength(\u30E9\u30F3\u30EC\u30F3\
    \u30B0\u30B9\u5727\u7E2E)\n * @docs docs/string/RunLength.md\n */\n#line 8 \"\
    math/PollardRho.hpp\"\n\ntemplate<class T, class Rnd> ull pollard_rho(ull n, Rnd&\
    \ rnd) {\n    if (~n & 1) return 2;\n    if (T::get_mod() != n) T::set_mod(n);\n\
    \    T c, one = 1;\n    auto f = [&](T x) -> T { return x * x + c; };\n    constexpr\
    \ int M = 128;\n    while (1) {\n        c = rnd.uniform(1ull, n - 1);\n     \
    \   T x = rnd.uniform(2ull, n - 1), y = x;\n        ull g = 1;\n        while\
    \ (g == 1) {\n            T p = one, tx = x, ty = y;\n            rep (M) {\n\
    \                x = f(x);\n                y = f(f(y));\n                p *=\
    \ x - y;\n            }\n            g = gcd(p.get(), n);\n            if (g ==\
    \ 1) continue;\n            rep (M) {\n                tx = f(tx);\n         \
    \       ty = f(f(ty));\n                g = gcd((tx - ty).get(), n);\n       \
    \         if (g != 1) {\n                    if (g != n) return g;\n         \
    \           break;\n                }\n            }\n        }\n    }\n    return\
    \ -1;\n}\n\ntemplate<class T = MontgomeryModInt<ull, -3>, class Rnd = Random64>\n\
    std::vector<ull> factorize(ull n, Rnd& rnd = rand64) {\n    if (n == 1) return\
    \ {};\n    std::vector<ull> res;\n    std::vector<ull> st = {n};\n    while (!st.empty())\
    \ {\n        ull t = st.back();\n        st.pop_back();\n        if (t == 1) continue;\n\
    \        if (is_prime_mr(t)) {\n            res.push_back(t);\n            continue;\n\
    \        }\n        ull f = pollard_rho<T>(t, rnd);\n        st.push_back(f);\n\
    \        st.push_back(t / f);\n    }\n    std::sort(all(res));\n    return res;\n\
    }\n\ntemplate<class T = MontgomeryModInt<ull, -3>, class Rnd = Random64>\nstd::vector<std::pair<ull,\
    \ int>> expfactorize(ull n, Rnd& rnd = rand64) {\n    auto f = factorize<T, Rnd>(n,\
    \ rnd);\n    return RunLength(f);\n}\n\nstd::vector<ll> divisors_pr(ll n) {\n\
    \    std::vector<ll> res;\n    auto r = expfactorize(n);\n    int m = r.size();\n\
    \    rec_lambda([&](auto&& self, int k, ll d) -> void {\n        if (k == m) {\n\
    \            res.push_back(d);\n            return;\n        }\n        ll t =\
    \ d;\n        rep (r[k].second) {\n            self(k + 1, d);\n            d\
    \ *= r[k].first;\n        }\n        self(k + 1, d);\n        d = t;\n    })(0,\
    \ 1);\n    std::sort(all(res));\n    return res;\n}\n\n/**\n * @brief PollardRho(\u7D20\
    \u56E0\u6570\u5206\u89E3)\n * @docs docs/math/PollardRho.md\n */\n#line 9 \"math/PrimitiveRoot.hpp\"\
    \n\ntemplate<class T = MontgomeryModInt<ull, -4>> ull primitive_root(ull p) {\n\
    \    assert(is_prime_mr(p));\n    if (p == 2) return 1;\n    if (T::get_mod()\
    \ != p) T::set_mod(p);\n    auto pf = factorize(p - 1);\n    pf.erase(std::unique(all(pf)),\
    \ pf.end());\n    each_for (x : pf) x = (p - 1) / x;\n    T one = 1;\n    while\
    \ (1) {\n        ull g = rand64.uniform(2ull, p - 1);\n        bool ok = true;\n\
    \        each_const (x : pf) {\n            if (T(g).pow(x) == one) {\n      \
    \          ok = false;\n                break;\n            }\n        }\n   \
    \     if (ok) return g;\n    }\n}\n\nCONSTEXPR ull primitive_root_for_convolution(ull\
    \ p) {\n    if (p == 2) return 1;\n    if (p == 998244353) return 3;\n    if (p\
    \ == 469762049) return 3;\n    if (p == 1811939329) return 11;\n    if (p == 2013265921)\
    \ return 11;\n    rep (g, 2, p) {\n        if (mod_pow(g, (p - 1) >> 1, p) !=\
    \ 1) return g;\n    }\n    return -1;\n}\n\n/**\n * @brief PrimitiveRoot(\u539F\
    \u59CB\u6839)\n * @docs docs/math/PrimitiveRoot.md\n */\n#line 6 \"math/convolution/Convolution.hpp\"\
    \n\nnamespace internal {\n\ntemplate<unsigned int p> class NthRoot {\nprivate:\n\
    \    static constexpr unsigned int lg = bitop::msb((p - 1) & (1 - p));\n    unsigned\
    \ int root[lg + 1];\n    unsigned int inv_root[lg + 1];\n    unsigned int rate[lg\
    \ + 1];\n    unsigned int inv_rate[lg + 1];\n\npublic:\n    constexpr NthRoot()\
    \ : root{}, inv_root{}, rate{}, inv_rate{} {\n        root[lg] = mod_pow(primitive_root_for_convolution(p),\
    \ (p - 1) >> lg, p);\n        inv_root[lg] = mod_pow(root[lg], p - 2, p);\n  \
    \      rrep (i, lg) {\n            root[i] = (ull)root[i + 1] * root[i + 1] %\
    \ p;\n            inv_root[i] = (ull)inv_root[i + 1] * inv_root[i + 1] % p;\n\
    \        }\n        ull r = 1;\n        rep (i, 2, lg + 1) {\n            rate[i\
    \ - 2] = r * root[i] % p;\n            r = r * inv_root[i] % p;\n        }\n \
    \       r = 1;\n        rep (i, 2, lg + 1) {\n            inv_rate[i - 2] = r\
    \ * inv_root[i] % p;\n            r = r * root[i] % p;\n        }\n    }\n   \
    \ static constexpr unsigned int get_lg() { return lg; }\n    constexpr unsigned\
    \ int get(int n) const { return root[n]; }\n    constexpr unsigned int inv(int\
    \ n) const { return inv_root[n]; }\n    constexpr unsigned int get_rate(int n)\
    \ const { return rate[n]; }\n    constexpr unsigned int get_inv_rate(int n) const\
    \ { return inv_rate[n]; }\n};\n\ntemplate<unsigned int p> constexpr NthRoot<p>\
    \ nth_root;\n\ntemplate<class T> void number_theoretic_transform(std::vector<T>&\
    \ a) {\n    int n = a.size();\n    int lg = bitop::msb(n - 1) + 1;\n    rrep (i,\
    \ lg) {\n        T z = T(1);\n        rep (j, 1 << (lg - i - 1)) {\n         \
    \   int offset = j << (i + 1);\n            rep (k, 1 << i) {\n              \
    \  T x = a[offset + k];\n                T y = a[offset + k + (1 << i)] * z;\n\
    \                a[offset + k] = x + y;\n                a[offset + k + (1 <<\
    \ i)] = x - y;\n            }\n            if (j != (1 << (lg - i - 1)) - 1) {\n\
    \                z *= nth_root<T::get_mod()>.get_rate(popcnt(j & ~(j + 1)));\n\
    \            }\n        }\n    }\n}\ntemplate<class T> void inverse_number_theoretic_transform(std::vector<T>&\
    \ a) {\n    int n = a.size();\n    int lg = bitop::msb(n - 1) + 1;\n    rep (i,\
    \ lg) {\n        T z = T(1);\n        rep (j, 1 << (lg - i - 1)) {\n         \
    \   int offset = j << (i + 1);\n            rep (k, 1 << i) {\n              \
    \  T x = a[offset + k];\n                T y = a[offset + k + (1 << i)];\n   \
    \             a[offset + k] = x + y;\n                a[offset + k + (1 << i)]\
    \ = (x - y) * z;\n            }\n            if (j != (1 << (lg - i - 1)) - 1)\
    \ {\n                z *= nth_root<T::get_mod()>.get_inv_rate(popcnt(j & ~(j +\
    \ 1)));\n            }\n        }\n    }\n    T inv_n = T(1) / n;\n    each_for\
    \ (x : a) x *= inv_n;\n}\n\ntemplate<class T>\nstd::vector<T> convolution_naive(const\
    \ std::vector<T>& a,\n                                 const std::vector<T>& b)\
    \ {\n    int n = a.size(), m = b.size();\n    std::vector<T> c(n + m - 1);\n \
    \   rep (i, n)\n        rep (j, m) c[i + j] += a[i] * b[j];\n    return c;\n}\n\
    \ntemplate<class T> std::vector<T> convolution_pow2(std::vector<T> a) {\n    int\
    \ n = a.size() * 2 - 1;\n    int lg = bitop::msb(n - 1) + 1;\n    if (n - (1 <<\
    \ (lg - 1)) <= 5) {\n        --lg;\n        int m = a.size() - (1 << (lg - 1));\n\
    \        std::vector<T> a1(a.begin(), a.begin() + m), a2(a.begin() + m, a.end());\n\
    \        std::vector<T> c(n);\n        std::vector<T> c1 = convolution_naive(a1,\
    \ a1);\n        std::vector<T> c2 = convolution_naive(a1, a2);\n        std::vector<T>\
    \ c3 = convolution_pow2(a2);\n        rep (i, c1.size()) c[i] += c1[i];\n    \
    \    rep (i, c2.size()) c[i + m] += c2[i] * 2;\n        rep (i, c3.size()) c[i\
    \ + m * 2] += c3[i];\n        return c;\n    }\n    int m = 1 << lg;\n    a.resize(m);\n\
    \    number_theoretic_transform(a);\n    rep (i, m) a[i] *= a[i];\n    inverse_number_theoretic_transform(a);\n\
    \    a.resize(n);\n    return a;\n}\n\ntemplate<class T>\nstd::vector<T> convolution(std::vector<T>\
    \ a, std::vector<T> b) {\n    int n = a.size() + b.size() - 1;\n    int lg = bitop::msb(n\
    \ - 1) + 1;\n    int m = 1 << lg;\n    if (n - (1 << (lg - 1)) <= 5) {\n     \
    \   --lg;\n        if (a.size() < b.size()) std::swap(a, b);\n        int m =\
    \ n - (1 << lg);\n        std::vector<T> a1(a.begin(), a.begin() + m), a2(a.begin()\
    \ + m, a.end());\n        std::vector<T> c(n);\n        std::vector<T> c1 = convolution_naive(a1,\
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
    \ 1 > ((1 - p) & (p - 1))) return convolution_for_any_mod(a, b);\n    if (n ==\
    \ m && a == b) return internal::convolution_pow2(a);\n    return internal::convolution(a,\
    \ b);\n}\n\ntemplate<unsigned int p>\nstd::vector<ll> convolution(const std::vector<ll>&\
    \ a,\n                            const std::vector<ll>& b) {\n    int n = a.size(),\
    \ m = b.size();\n    std::vector<static_modint<p>> a2(n), b2(m);\n    rep (i,\
    \ n) a2[i] = a[i];\n    rep (i, m) b2[i] = b[i];\n    auto c2 = convolution(a2,\
    \ b2);\n    std::vector<ll> c(n + m - 1);\n    rep (i, n + m - 1) c[i] = c2[i].get();\n\
    \    return c;\n}\n\ntemplate<unsigned int p>\nstd::vector<static_modint<p>>\n\
    convolution_for_any_mod(const std::vector<static_modint<p>>& a,\n            \
    \            const std::vector<static_modint<p>>& b) {\n    int n = a.size(),\
    \ m = b.size();\n    assert(n + m - 1 <= (1 << 26));\n    std::vector<ll> a2(n),\
    \ b2(m);\n    rep (i, n) a2[i] = a[i].get();\n    rep (i, m) b2[i] = b[i].get();\n\
    \    static constexpr ull MOD1 = 469762049;\n    static constexpr ull MOD2 = 1811939329;\n\
    \    static constexpr ull MOD3 = 2013265921;\n    static constexpr ull INV1_2\
    \ = mod_pow(MOD1, MOD2 - 2, MOD2);\n    static constexpr ull INV1_3 = mod_pow(MOD1,\
    \ MOD3 - 2, MOD3);\n    static constexpr ull INV2_3 = mod_pow(MOD2, MOD3 - 2,\
    \ MOD3);\n    auto c1 = convolution<MOD1>(a2, b2);\n    auto c2 = convolution<MOD2>(a2,\
    \ b2);\n    auto c3 = convolution<MOD3>(a2, b2);\n    std::vector<static_modint<p>>\
    \ res(n + m - 1);\n    rep (i, n + m - 1) {\n        ull t1 = c1[i];\n       \
    \ ull t2 = (c2[i] - t1 + MOD2) * INV1_2 % MOD2;\n        if (t2 < 0) t2 += MOD2;\n\
    \        ull t3 =\n            ((c3[i] - t1 + MOD3) * INV1_3 % MOD3 - t2 + MOD3)\
    \ * INV2_3 % MOD3;\n        if (t3 < 0) t3 += MOD3;\n        assert(0 <= t1 &&\
    \ t1 < MOD1);\n        assert(0 <= t2 && t2 < MOD2);\n        assert(0 <= t3 &&\
    \ t3 < MOD3);\n        res[i] = static_modint<p>(t1 + (t2 + t3 * MOD2) % p * MOD1);\n\
    \    }\n    return res;\n}\n\ntemplate<class T> void ntt_doubling_(std::vector<T>&\
    \ a) {\n    int n = a.size();\n    auto b = a;\n    inverse_number_theoretic_transform(b);\n\
    \    const T z = internal::nth_root<T::get_mod()>.get(bitop::msb(n) + 1);\n  \
    \  T r = 1;\n    rep (i, n) {\n        b[i] *= r;\n        r *= z;\n    }\n  \
    \  number_theoretic_transform(b);\n    std::copy(all(b), std::back_inserter(a));\n\
    }\n\ntemplate<unsigned int p> struct is_ntt_friendly : std::false_type {};\n\n\
    template<> struct is_ntt_friendly<998244353> : std::true_type {};\n\n/**\n * @brief\
    \ Convolution(\u7573\u307F\u8FBC\u307F)\n * @docs docs/math/convolution.md\n */\n\
    #line 2 \"math/Combinatorics.hpp\"\n\n#line 5 \"math/Combinatorics.hpp\"\n\ntemplate<class\
    \ T> class Combinatorics {\nprivate:\n    static std::vector<T> factorial;\n \
    \   static std::vector<T> factinv;\n\npublic:\n    static void init(ll n) {\n\
    \        const int b = factorial.size();\n        if (n < b) return;\n       \
    \ factorial.resize(n + 1);\n        rep (i, b, n + 1) factorial[i] = factorial[i\
    \ - 1] * i;\n        factinv.resize(n + 1);\n        factinv[n] = T(1) / factorial[n];\n\
    \        rreps (i, n, b) factinv[i - 1] = factinv[i] * i;\n    }\n    static T\
    \ fact(ll x) {\n        init(x);\n        return factorial[x];\n    }\n    static\
    \ T finv(ll x) {\n        init(x);\n        return factinv[x];\n    }\n    static\
    \ T inv(ll x) {\n        init(x);\n        return factorial[x - 1] * factinv[x];\n\
    \    }\n    static T perm(ll n, ll r) {\n        if (r < 0 || r > n) return 0;\n\
    \        init(n);\n        return factorial[n] * factinv[n - r];\n    }\n    static\
    \ T comb(ll n, ll r) {\n        if (n < 0) return 0;\n        if (r < 0 || r >\
    \ n) return 0;\n        init(n);\n        return factorial[n] * factinv[n - r]\
    \ * factinv[r];\n    }\n    static T homo(ll n, ll r) { return comb(n + r - 1,\
    \ r); }\n    static T small_perm(ll n, ll r) {\n        if (r < 0 || r > n) return\
    \ 0;\n        T res = 1;\n        reps (i, r) res *= n - r + i;\n        return\
    \ res;\n    }\n    static T small_comb(ll n, ll r) {\n        if (r < 0 || r >\
    \ n) return 0;\n        chmin(r, n - r);\n        init(r);\n        T res = factinv[r];\n\
    \        reps (i, r) res *= n - r + i;\n        return res;\n    }\n    static\
    \ T small_homo(ll n, ll r) { return small_comb(n + r - 1, r); }\n};\n\ntemplate<class\
    \ T>\nstd::vector<T> Combinatorics<T>::factorial = std::vector<T>(1, 1);\ntemplate<class\
    \ T>\nstd::vector<T> Combinatorics<T>::factinv = std::vector<T>(1, 1);\n\n/**\n\
    \ * @brief Combinatorics\n * @docs docs/math/Combinatorics.md\n */\n#line 2 \"\
    math/SqrtMod.hpp\"\n\n#line 5 \"math/SqrtMod.hpp\"\n\ntemplate<class T> ll sqrt_mod(ll\
    \ a) {\n    const ll p = T::get_mod();\n    if (p == 2) return a;\n    if (a ==\
    \ 0) return 0;\n    if (T{a}.pow((p - 1) >> 1) != 1) return -1;\n    T b = 2;\n\
    \    while (T{b}.pow((p - 1) >> 1) == 1) ++b;\n    ll s = 0, t = p - 1;\n    while\
    \ ((t & 1) == 0) t >>= 1, ++s;\n    T x = T{a}.pow((t + 1) >> 1);\n    T w = T{a}.pow(t);\n\
    \    T v = T{b}.pow(t);\n    while (w != 1) {\n        ll k = 0;\n        T y\
    \ = w;\n        while (y != 1) {\n            y *= y;\n            ++k;\n    \
    \    }\n        T z = v;\n        rep (s - k - 1) z *= z;\n        x *= z;\n \
    \       w *= z * z;\n    }\n    return std::min<ll>(x.get(), p - x.get());\n}\n\
    \nll sqrt_mod(ll a, ll p) {\n    if (p == 2) return a;\n    using mint = MontgomeryModInt<unsigned\
    \ int, 493174342>;\n    mint::set_mod(p);\n    return sqrt_mod<mint>(a);\n}\n\n\
    /**\n * @brief SqrtMod(\u5E73\u65B9\u5270\u4F59)\n * @docs docs/math/SqrtMod.md\n\
    \ * @see https://37zigen.com/tonelli-shanks-algorithm/\n */\n#line 7 \"math/poly/FormalPowerSeries.hpp\"\
    \n\ntemplate<class T> class FormalPowerSeries : public std::vector<T> {\nprivate:\n\
    \    using Base = std::vector<T>;\n    using Comb = Combinatorics<T>;\n\npublic:\n\
    \    using Base::Base;\n    FormalPowerSeries(const Base& v) : Base(v) {}\n  \
    \  FormalPowerSeries(Base&& v) : Base(std::move(v)) {}\n\n    FormalPowerSeries&\
    \ shrink() {\n        while (!this->empty() && this->back() == T{0}) this->pop_back();\n\
    \        return *this;\n    }\n\n    T eval(T x) const {\n        T res = 0;\n\
    \        rrep (i, this->size()) {\n            res *= x;\n            res += (*this)[i];\n\
    \        }\n        return res;\n    }\n\n    FormalPowerSeries prefix(int deg)\
    \ const {\n        assert(0 <= deg);\n        if (deg < (int)this->size()) {\n\
    \            return FormalPowerSeries(this->begin(), this->begin() + deg);\n \
    \       }\n        FormalPowerSeries res(*this);\n        res.resize(deg);\n \
    \       return res;\n    }\n\n    FormalPowerSeries operator+() const { return\
    \ *this; }\n    FormalPowerSeries operator-() const {\n        FormalPowerSeries\
    \ res(this->size());\n        rep (i, this->size()) res[i] = -(*this)[i];\n  \
    \      return res;\n    }\n    FormalPowerSeries& operator<<=(int n) {\n     \
    \   this->insert(this->begin(), n, T{0});\n        return *this;\n    }\n    FormalPowerSeries&\
    \ operator>>=(int n) {\n        this->erase(this->begin(),\n                 \
    \   this->begin() + std::min(n, (int)this->size()));\n        return *this;\n\
    \    }\n    friend FormalPowerSeries operator<<(const FormalPowerSeries& lhs,\
    \ int rhs) {\n        return FormalPowerSeries(lhs) <<= rhs;\n    }\n    friend\
    \ FormalPowerSeries operator>>(const FormalPowerSeries& lhs, int rhs) {\n    \
    \    return FormalPowerSeries(lhs) >>= rhs;\n    }\n    FormalPowerSeries& operator+=(const\
    \ FormalPowerSeries& rhs) {\n        if (this->size() < rhs.size()) this->resize(rhs.size());\n\
    \        rep (i, rhs.size()) (*this)[i] += rhs[i];\n        return *this;\n  \
    \  }\n    FormalPowerSeries& operator-=(const FormalPowerSeries& rhs) {\n    \
    \    if (this->size() < rhs.size()) this->resize(rhs.size());\n        rep (i,\
    \ rhs.size()) (*this)[i] -= rhs[i];\n        return *this;\n    }\n    friend\
    \ FormalPowerSeries operator+(const FormalPowerSeries& lhs,\n                \
    \                       const FormalPowerSeries& rhs) {\n        return FormalPowerSeries(lhs)\
    \ += rhs;\n    }\n    friend FormalPowerSeries operator-(const FormalPowerSeries&\
    \ lhs,\n                                       const FormalPowerSeries& rhs) {\n\
    \        return FormalPowerSeries(lhs) -= rhs;\n    }\n    friend FormalPowerSeries\
    \ operator*(const FormalPowerSeries& lhs,\n                                  \
    \     const FormalPowerSeries& rhs) {\n        return FormalPowerSeries(convolution(lhs,\
    \ rhs));\n    }\n    FormalPowerSeries& operator*=(const FormalPowerSeries& rhs)\
    \ {\n        return *this = *this * rhs;\n    }\n    FormalPowerSeries& operator*=(const\
    \ T& rhs) {\n        rep (i, this->size()) (*this)[i] *= rhs;\n        return\
    \ *this;\n    }\n    friend FormalPowerSeries operator*(const FormalPowerSeries&\
    \ lhs,\n                                       const T& rhs) {\n        return\
    \ FormalPowerSeries(lhs) *= rhs;\n    }\n    friend FormalPowerSeries operator*(const\
    \ T& lhs,\n                                       const FormalPowerSeries& rhs)\
    \ {\n        return FormalPowerSeries(rhs) *= lhs;\n    }\n    FormalPowerSeries&\
    \ operator/=(const T& rhs) {\n        rep (i, this->size()) (*this)[i] /= rhs;\n\
    \        return *this;\n    }\n    friend FormalPowerSeries operator/(const FormalPowerSeries&\
    \ lhs,\n                                       const T& rhs) {\n        return\
    \ FormalPowerSeries(lhs) /= rhs;\n    }\n\n    FormalPowerSeries rev() const {\n\
    \        FormalPowerSeries res(*this);\n        std::reverse(all(res));\n    \
    \    return res;\n    }\n\n    friend FormalPowerSeries div(FormalPowerSeries\
    \ lhs, FormalPowerSeries rhs) {\n        lhs.shrink();\n        rhs.shrink();\n\
    \        if (lhs.size() < rhs.size()) {\n            return FormalPowerSeries{};\n\
    \        }\n        int n = lhs.size() - rhs.size() + 1;\n        if (rhs.size()\
    \ <= 32) {\n            FormalPowerSeries res(n);\n            T iv = rhs.back().inv();\n\
    \            rrep (i, n) {\n                T d = lhs[i + rhs.size() - 1] * iv;\n\
    \                res[i] = d;\n                rep (j, rhs.size()) lhs[i + j] -=\
    \ d * rhs[j];\n            }\n            return res;\n        }\n        return\
    \ (lhs.rev().prefix(n) * rhs.rev().inv(n)).prefix(n).rev();\n    }\n    friend\
    \ FormalPowerSeries operator%(FormalPowerSeries lhs,\n                       \
    \                FormalPowerSeries rhs) {\n        lhs.shrink();\n        rhs.shrink();\n\
    \        if (lhs.size() < rhs.size()) {\n            return lhs;\n        }\n\
    \        int n = lhs.size() - rhs.size() + 1;\n        if (rhs.size() <= 32) {\n\
    \            T iv = rhs.back().inv();\n            rrep (i, n) {\n           \
    \     T d = lhs[i + rhs.size() - 1] * iv;\n                rep (j, rhs.size())\
    \ lhs[i + j] -= d * rhs[j];\n            }\n            return lhs.shrink();\n\
    \        }\n        return (lhs - div(lhs, rhs) * rhs).shrink();\n    }\n    friend\
    \ std::pair<FormalPowerSeries, FormalPowerSeries>\n    divmod(FormalPowerSeries\
    \ lhs, FormalPowerSeries rhs) {\n        lhs.shrink();\n        rhs.shrink();\n\
    \        if (lhs.size() < rhs.size()) {\n            return {FormalPowerSeries{},\
    \ lhs};\n        }\n        int n = lhs.size() - rhs.size() + 1;\n        if (rhs.size()\
    \ <= 32) {\n            FormalPowerSeries res(n);\n            T iv = rhs.back().inv();\n\
    \            rrep (i, n) {\n                T d = lhs[i + rhs.size() - 1] * iv;\n\
    \                res[i] = d;\n                rep (j, rhs.size()) lhs[i + j] -=\
    \ d * rhs[j];\n            }\n            return {res, lhs.shrink()};\n      \
    \  }\n        FormalPowerSeries q = div(lhs, rhs);\n        return {q, (lhs -\
    \ q * rhs).shrink()};\n    }\n    FormalPowerSeries& operator%=(const FormalPowerSeries&\
    \ rhs) {\n        return *this = *this % rhs;\n    }\n\n    FormalPowerSeries\
    \ diff() const {\n        FormalPowerSeries res(this->size() - 1);\n        rep\
    \ (i, res.size()) res[i] = (*this)[i + 1] * (i + 1);\n        return res;\n  \
    \  }\n    FormalPowerSeries integral() const {\n        FormalPowerSeries res(this->size()\
    \ + 1);\n        res[0] = 0;\n        Comb::init(this->size());\n        rep (i,\
    \ this->size()) res[i + 1] = (*this)[i] * Comb::inv(i + 1);\n        return res;\n\
    \    }\n\n    template<bool AlwaysTrue = true,\n             typename std::enable_if<\n\
    \                 AlwaysTrue && is_ntt_friendly<T::get_mod()>::value>::type* =\n\
    \                 nullptr>\n    FormalPowerSeries inv(int deg = -1) const {\n\
    \        assert(this->size() > 0 && (*this)[0] != 0);\n        if (deg == -1)\
    \ deg = this->size();\n        FormalPowerSeries res(1, (*this)[0].inv());\n \
    \       for (int m = 1; m < deg; m <<= 1) {\n            FormalPowerSeries f(2\
    \ * m);\n            for (int i = 0; i < std::min(2 * m, (int)this->size()); i++)\n\
    \                f[i] = (*this)[i];\n            res.resize(2 * m);\n        \
    \    FormalPowerSeries dft = res;\n            number_theoretic_transform(f);\n\
    \            number_theoretic_transform(dft);\n            rep (i, 2 * m) f[i]\
    \ *= dft[i];\n            inverse_number_theoretic_transform(f);\n           \
    \ std::fill(f.begin(), f.begin() + m, T{0});\n            number_theoretic_transform(f);\n\
    \            rep (i, 2 * m) dft[i] *= f[i];\n            inverse_number_theoretic_transform(dft);\n\
    \            rep (i, m, 2 * m) res[i] = -dft[i];\n        }\n        return res.prefix(deg);\n\
    \    }\n    template<bool AlwaysTrue = true,\n             typename std::enable_if<\n\
    \                 AlwaysTrue && !is_ntt_friendly<T::get_mod()>::value>::type*\
    \ =\n                 nullptr>\n    FormalPowerSeries inv(int deg = -1) const\
    \ {\n        assert(this->size() > 0 && (*this)[0] != 0);\n        if (deg ==\
    \ -1) deg = this->size();\n        FormalPowerSeries res(1, (*this)[0].inv());\n\
    \        for (int m = 1; m < deg; m <<= 1) {\n            res = (res * 2 - (res\
    \ * res * this->prefix(2 * m)).prefix(2 * m))\n                      .prefix(2\
    \ * m);\n        }\n        return res.prefix(deg);\n    }\n    FormalPowerSeries\
    \ log(int deg = -1) const {\n        assert(this->size() > 0 && (*this)[0] ==\
    \ 1);\n        if (deg == -1) deg = this->size();\n        return (diff() * inv(deg)).prefix(deg\
    \ - 1).integral();\n    }\n    template<bool AlwaysTrue = true,\n            \
    \ typename std::enable_if<\n                 AlwaysTrue && is_ntt_friendly<T::get_mod()>::value>::type*\
    \ =\n                 nullptr>\n    FormalPowerSeries exp(int deg = -1) const\
    \ {\n        assert(this->size() > 0 && (*this)[0] == 0);\n        if (deg ==\
    \ -1) deg = this->size();\n        FormalPowerSeries f(1, 1);\n        FormalPowerSeries\
    \ g(1, 1);\n        FormalPowerSeries dft_f(1, 1);\n        for (int m = 1; m\
    \ < deg; m <<= 1) {\n            FormalPowerSeries q = prefix(m).diff();\n   \
    \         q.resize(m);\n            number_theoretic_transform(q);\n         \
    \   rep (i, m) q[i] *= dft_f[i];\n            inverse_number_theoretic_transform(q);\n\
    \            FormalPowerSeries s = f.diff();\n            s.resize(m);\n     \
    \       rep (i, m) s[i] -= q[i];\n            s.insert(s.begin(), (T)s.back());\n\
    \            s.pop_back();\n            FormalPowerSeries dft_g = g;\n       \
    \     s.resize(2 * m);\n            dft_g.resize(2 * m);\n            number_theoretic_transform(s);\n\
    \            number_theoretic_transform(dft_g);\n            rep (i, 2 * m) s[i]\
    \ *= dft_g[i];\n            inverse_number_theoretic_transform(s);\n         \
    \   FormalPowerSeries u =\n                (prefix(2 * m) - (s.prefix(m) << (m\
    \ - 1)).integral()) >> m;\n            u.resize(2 * m);\n            FormalPowerSeries\
    \ dft_f_2 = f;\n            dft_f_2.resize(2 * m);\n            number_theoretic_transform(u);\n\
    \            number_theoretic_transform(dft_f_2);\n            rep (i, 2 * m)\
    \ u[i] *= dft_f_2[i];\n            inverse_number_theoretic_transform(u);\n  \
    \          f = f + (u.prefix(m) << m);\n            if (2 * m < deg) {\n     \
    \           g.resize(2 * m);\n                FormalPowerSeries dft_g_2 = g;\n\
    \                FormalPowerSeries dft_f_2 = f;\n                number_theoretic_transform(dft_g_2);\n\
    \                number_theoretic_transform(dft_f_2);\n                dft_f =\
    \ dft_f_2;\n                rep (i, 2 * m) dft_f_2[i] *= dft_g_2[i];\n       \
    \         inverse_number_theoretic_transform(dft_f_2);\n                std::fill(dft_f_2.begin(),\
    \ dft_f_2.begin() + m, T{0});\n                number_theoretic_transform(dft_f_2);\n\
    \                rep (i, 2 * m) dft_f_2[i] *= dft_g_2[i];\n                inverse_number_theoretic_transform(dft_f_2);\n\
    \                rep (i, m, 2 * m) g[i] = -dft_f_2[i];\n            }\n      \
    \  }\n        return f.prefix(deg);\n    }\n    template<bool AlwaysTrue = true,\n\
    \             typename std::enable_if<\n                 AlwaysTrue && !is_ntt_friendly<T::get_mod()>::value>::type*\
    \ =\n                 nullptr>\n    FormalPowerSeries exp(int deg = -1) const\
    \ {\n        assert(this->size() > 0 && (*this)[0] == 0);\n        if (deg ==\
    \ -1) deg = this->size();\n        FormalPowerSeries res(1, 1);\n        for (int\
    \ m = 1; m < deg; m <<= 1) {\n            res = (res * (prefix(2 * m) - res.log(2\
    \ * m)) + res).prefix(2 * m);\n        }\n        return res.prefix(deg);\n  \
    \  }\n    FormalPowerSeries pow(ll k, int deg = -1) const {\n        if (deg ==\
    \ -1) deg = this->size();\n        if (deg == 0) return {};\n        if (k ==\
    \ 0) {\n            FormalPowerSeries res(deg);\n            res[0] = 1;\n   \
    \         return res;\n        }\n        if (k == 1) return prefix(deg);\n  \
    \      if (k == 2) return (*this * *this).prefix(deg);\n        T a;\n       \
    \ int d = -1;\n        rep (i, this->size()) {\n            if ((*this)[i] !=\
    \ 0) {\n                a = (*this)[i];\n                d = i;\n            \
    \    break;\n            }\n        }\n        if (d == -1) {\n            FormalPowerSeries\
    \ res(deg);\n            return res;\n        }\n        if ((__int128_t)(d)*k\
    \ >= deg) {\n            FormalPowerSeries res(deg);\n            return res;\n\
    \        }\n        deg -= d * k;\n        FormalPowerSeries res = (((*this >>\
    \ d) / a).log(deg) * k).exp(deg);\n        res *= a.pow(k);\n        res <<= d\
    \ * k;\n        return res;\n    }\n    FormalPowerSeries sqrt(int deg = -1) const\
    \ {\n        if (deg == -1) deg = this->size();\n        T a;\n        int d =\
    \ -1;\n        rep (i, this->size()) {\n            if ((*this)[i] != 0) {\n \
    \               a = (*this)[i];\n                d = i;\n                break;\n\
    \            }\n        }\n        if (d == -1) {\n            FormalPowerSeries\
    \ res(deg);\n            return res;\n        }\n        if (d & 1) return {};\n\
    \        deg -= (d >> 1);\n        if (deg <= 0) {\n            FormalPowerSeries\
    \ res(deg);\n            return res;\n        }\n        FormalPowerSeries f =\
    \ (*this >> d);\n        T sq = sqrt_mod<T>(a.get());\n        if (sq == -1) return\
    \ {};\n        FormalPowerSeries g(1, sq);\n        for (int m = 1; m < deg; m\
    \ <<= 1) {\n            g = (g + (f.prefix(2 * m) * g.inv(2 * m)).prefix(2 * m))\
    \ / 2;\n        }\n        g.resize(deg);\n        return g << (d >> 1);\n   \
    \ }\n    template<bool AlwaysTrue = true,\n             typename std::enable_if<\n\
    \                 AlwaysTrue && is_ntt_friendly<T::get_mod()>::value>::type* =\n\
    \                 nullptr>\n    FormalPowerSeries& ntt_doubling() {\n        ntt_doubling_(*this);\n\
    \        return *this;\n    }\n};\n\n/**\n * @brief FormalPowerSeries(\u5F62\u5F0F\
    \u7684\u51AA\u7D1A\u6570)\n * @docs docs/math/poly/FormalPowerSeries.md\n * @see\
    \ https://nyaannyaan.github.io/library/fps/formal-power-series.hpp\n */\n#line\
    \ 2 \"math/poly/SparseFormalPowerSeries.hpp\"\n\n#line 8 \"math/poly/SparseFormalPowerSeries.hpp\"\
    \n\ntemplate<class T> class SparseFPS : public std::vector<std::pair<int, T>>\
    \ {\nprivate:\n    using Base = std::vector<std::pair<int, T>>;\n    using FPS\
    \ = FormalPowerSeries<T>;\n    using Comb = Combinatorics<T>;\n\n    void refine()\
    \ {\n        if (this->empty()) return;\n        std::sort(this->begin(), this->end(),\
    \ [](const auto& a, const auto& b) {\n            return a.first < b.first;\n\
    \        });\n        int p = -1;\n        rep (i, this->size()) {\n         \
    \   if ((*this)[i].second != T{0}) {\n                if (p >= 0 && (*this)[i].first\
    \ == (*this)[p].first) {\n                    (*this)[p].second += (*this)[i].second;\n\
    \                }\n                else {\n                    (*this)[++p] =\
    \ (*this)[i];\n                }\n            }\n        }\n        this->resize(p\
    \ + 1);\n    }\n\npublic:\n    using Base::Base;\n    SparseFPS(const Base& v)\
    \ : Base(v) {}\n    SparseFPS(Base&& v) : Base(std::move(v)) {}\n    SparseFPS(const\
    \ FPS& v) {\n        rep (i, v.size())\n            if (v[i] != T{0}) this->emplace_back(i,\
    \ v[i]);\n    }\n    SparseFPS(FPS&& v) {\n        rep (i, v.size())\n       \
    \     if (v[i] != T{0}) this->emplace_back(i, std::move(v[i]));\n    }\n    FPS\
    \ fps(int deg = -1) const {\n        if (deg == -1) {\n            deg = 0;\n\
    \            for (auto p : *this) chmax(deg, p.first + 1);\n        }\n      \
    \  FPS res(deg);\n        for (auto p : *this) {\n            if (p.first < deg)\
    \ res[p.first] += p.second;\n        }\n        return res;\n    }\n\n    SparseFPS&\
    \ operator<<=(int n) {\n        for (auto& p : *this) p.first += n;\n        return\
    \ *this;\n    }\n    SparseFPS& operator>>=(int n) {\n        for (auto& p : *this)\
    \ p.first -= n;\n        this->erase(std::remove_if(all(*this),\n            \
    \                       [](const auto& p) { return p.first < 0; }),\n        \
    \            this->end());\n        return *this;\n    }\n    friend SparseFPS\
    \ operator<<(const SparseFPS& lhs, int rhs) {\n        return SparseFPS(lhs) <<=\
    \ rhs;\n    }\n    friend SparseFPS operator>>(const SparseFPS& lhs, int rhs)\
    \ {\n        return SparseFPS(lhs) >>= rhs;\n    }\n    SparseFPS& operator*=(const\
    \ T& rhs) {\n        for (auto& p : *this) p.second *= rhs;\n        return *this;\n\
    \    }\n    friend SparseFPS operator*(const SparseFPS& lhs, const T& rhs) {\n\
    \        return SparseFPS(lhs) *= rhs;\n    }\n    friend SparseFPS operator*(const\
    \ T& lhs, const SparseFPS& rhs) {\n        return SparseFPS(rhs) *= lhs;\n   \
    \ }\n    SparseFPS& operator/=(const T& rhs) {\n        T inv = T{1} / rhs;\n\
    \        for (auto& p : *this) p.second *= inv;\n        return *this;\n    }\n\
    \    friend SparseFPS operator/(const SparseFPS& lhs, const T& rhs) {\n      \
    \  return SparseFPS(lhs) /= rhs;\n    }\n\n    SparseFPS diff() const {\n    \
    \    SparseFPS res(*this);\n        for (auto& p : res) {\n            p.second\
    \ *= p.first;\n            --p.first;\n        }\n        res.erase(\n       \
    \     std::remove_if(all(res), [](const auto& p) { return p.first < 0; }),\n \
    \           res.end());\n        return res;\n    }\n    SparseFPS integral()\
    \ const {\n        int d = 0;\n        for (auto& p : *this) chmax(d, p.first);\n\
    \        Comb::init(d);\n        SparseFPS res(*this);\n        for (auto& p :\
    \ res) {\n            ++p.first;\n            p.second *= Comb::inv(p.first);\n\
    \        }\n        return res;\n    }\n\n    friend FPS prod_sparse(FPS lhs,\
    \ SparseFPS rhs, int deg = -1) {\n        if (deg == -1) deg = lhs.size();\n \
    \       lhs.resize(deg);\n        rhs.refine();\n        FPS res(deg);\n     \
    \   rep (i, deg) {\n            for (auto p : rhs) {\n                if (i +\
    \ p.first < deg) res[i + p.first] += lhs[i] * p.second;\n            }\n     \
    \   }\n        return res;\n    }\n\n    friend FPS div_sparse(FPS lhs, SparseFPS\
    \ rhs, int deg = -1) {\n        if (deg == -1) deg = lhs.size();\n        lhs.resize(deg);\n\
    \        rhs.refine();\n        FPS res(deg);\n        T inv0 = T{1} / rhs[0].second;\n\
    \        rep (i, deg) {\n            res[i] = lhs[i] * inv0;\n            for\
    \ (auto p : rhs) {\n                if (i + p.first < deg) lhs[i + p.first] -=\
    \ res[i] * p.second;\n            }\n        }\n        return res;\n    }\n \
    \   FPS inv(int deg) { return div_sparse(FPS{1}, *this, deg); }\n    FPS log(int\
    \ deg) {\n        refine();\n        assert(!this->empty() && (*this)[0].first\
    \ == 0 &&\n               (*this)[0].second == T{1});\n        return div_sparse(this->diff().fps(deg\
    \ - 1), *this, deg - 1).integral();\n    }\n    FPS exp(int deg) {\n        refine();\n\
    \        assert(this->empty() || (*this)[0].first != 0);\n        Comb::init(deg\
    \ - 1);\n        SparseFPS f = diff();\n        FPS res(deg);\n        res[0]\
    \ = T{1};\n        rep (i, deg) {\n            if (i != 0) res[i] *= Comb::inv(i);\n\
    \            for (auto p : f) {\n                if (i + p.first + 1 < deg) {\n\
    \                    res[i + p.first + 1] += res[i] * p.second;\n            \
    \    }\n            }\n        }\n        return res;\n    }\n    FPS pow(ll k,\
    \ int deg) {\n        refine();\n        if (deg == 0) return {};\n        if\
    \ (k == 0) {\n            FPS res(deg);\n            res[0] = 1;\n           \
    \ return res;\n        }\n        if (this->empty()) return FPS(deg);\n      \
    \  int d = (*this)[0].first;\n        T a = (*this)[0].second;\n        if ((__int128_t)(d)*k\
    \ >= deg) return FPS(deg);\n        if (k == 1) return fps(deg);\n        if (k\
    \ == 2) return prod_sparse(fps(deg), *this, deg);\n        deg -= d * k;\n   \
    \     SparseFPS f = (*this >> d) / a;\n        std::vector<std::tuple<int, T,\
    \ T>> g;\n        for (auto p : f) {\n            if (p.first != 0) {\n      \
    \          g.emplace_back(p.first, p.second, p.first * p.second * k);\n      \
    \      }\n        }\n        Comb::init(deg - 1);\n        FPS res(deg);\n   \
    \     res[0] = 1;\n        rep (i, deg) {\n            if (i != 0) res[i] *= Comb::inv(i);\n\
    \            for (auto& p : g) {\n                int a;\n                T b,\
    \ c;\n                std::tie(a, b, c) = p;\n                if (i + a < deg)\
    \ {\n                    res[i + a] += res[i] * c;\n                    std::get<2>(p)\
    \ -= b;\n                }\n            }\n        }\n        return (res * a.pow(k))\
    \ << (d * k);\n    }\n    FPS sqrt(int deg) {\n        refine();\n        if (this->empty())\
    \ return FPS(deg);\n        int d = (*this)[0].first;\n        T a = (*this)[0].second;\n\
    \        if (d & 1) return {};\n        if (d / 2 >= deg) return FPS(deg);\n \
    \       deg -= d / 2;\n        ll sq = sqrt_mod<T>(a.get());\n        if (sq ==\
    \ -1) return {};\n        SparseFPS f = (*this >> d) / a;\n        std::vector<std::tuple<int,\
    \ T, T>> g;\n        for (auto p : f) {\n            if (p.first != 0) {\n   \
    \             g.emplace_back(p.first, p.second, p.first * p.second / 2);\n   \
    \         }\n        }\n        Comb::init(deg - 1);\n        FPS res(deg);\n\
    \        res[0] = 1;\n        rep (i, deg) {\n            if (i != 0) res[i] *=\
    \ Comb::inv(i);\n            for (auto& p : g) {\n                int a;\n   \
    \             T b, c;\n                std::tie(a, b, c) = p;\n              \
    \  if (i + a < deg) {\n                    res[i + a] += res[i] * c;\n       \
    \             std::get<2>(p) -= b;\n                }\n            }\n       \
    \ }\n        return (res * T{sq}) << (d / 2);\n    }\n};\n\n/**\n * @brief SparseFormalPowerSeries(\u758E\
    \u306A\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570)\n * @docs docs/math/poly/SparseFormalPowerSeries.md\n\
    \ */\n#line 6 \"test/yosupo/polynomial/exp_of_formal_power_series_sparse.test.cpp\"\
    \nusing namespace std;\nusing mint = modint998244353;\nint main() {\n    int n,\
    \ k; scan >> n >> k;\n    SparseFPS<mint> a(k); scan >> a;\n    prints(a.exp(n));\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/exp_of_formal_power_series_sparse\"\
    \n#include \"../../../other/template.hpp\"\n#include \"../../../math/poly/FormalPowerSeries.hpp\"\
    \n#include \"../../../math/poly/SparseFormalPowerSeries.hpp\"\n#include \"../../../math/ModInt.hpp\"\
    \nusing namespace std;\nusing mint = modint998244353;\nint main() {\n    int n,\
    \ k; scan >> n >> k;\n    SparseFPS<mint> a(k); scan >> a;\n    prints(a.exp(n));\n\
    }\n"
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
  - math/poly/FormalPowerSeries.hpp
  - math/convolution/Convolution.hpp
  - math/ModInt.hpp
  - math/PrimitiveRoot.hpp
  - random/Random.hpp
  - math/MontgomeryModInt.hpp
  - math/MillerRabin.hpp
  - math/PollardRho.hpp
  - string/RunLength.hpp
  - math/Combinatorics.hpp
  - math/SqrtMod.hpp
  - math/poly/SparseFormalPowerSeries.hpp
  isVerificationFile: true
  path: test/yosupo/polynomial/exp_of_formal_power_series_sparse.test.cpp
  requiredBy: []
  timestamp: '2023-07-15 19:35:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/polynomial/exp_of_formal_power_series_sparse.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/polynomial/exp_of_formal_power_series_sparse.test.cpp
- /verify/test/yosupo/polynomial/exp_of_formal_power_series_sparse.test.cpp.html
title: test/yosupo/polynomial/exp_of_formal_power_series_sparse.test.cpp
---
