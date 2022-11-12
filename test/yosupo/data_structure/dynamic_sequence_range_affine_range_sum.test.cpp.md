---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data-struct/other/SkipList.hpp
    title: SkipList
  - icon: ':question:'
    path: math/ModInt.hpp
    title: ModInt
  - icon: ':question:'
    path: other/monoid.hpp
    title: other/monoid.hpp
  - icon: ':x:'
    path: other/monoid2.hpp
    title: other/monoid2.hpp
  - icon: ':question:'
    path: other/template.hpp
    title: other/template.hpp
  - icon: ':question:'
    path: random/Random.hpp
    title: Random
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
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
  bundledCode: "#line 1 \"test/yosupo/data_structure/dynamic_sequence_range_affine_range_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
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
    \ T, class = void> struct is_range : std::false_type {};\ntemplate<class T>\n\
    struct is_range<\n    T,\n    decltype(all(std::declval<typename std::add_lvalue_reference<T>::type>()),\n\
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
    \ntemplate<class T>\nusing double_size =\n    typename std::conditional<std::is_signed<T>::value,\
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
    \ }\n    };\n\n    iterator begin() noexcept { return iterator(this); }\n};\n\n\
    Reader<> reader(0);\n\ntemplate<class Iterator, std::size_t decimal_precision\
    \ = 16> class Scanner {\npublic:\n    using iterator_type = Iterator;\n\nprivate:\n\
    \    template<class, class = void> struct has_scan : std::false_type {};\n   \
    \ template<class T>\n    struct has_scan<\n        T, decltype(std::declval<T>().scan(std::declval<Scanner&>()),\
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
    \             typename std::enable_if<std::is_integral<T>::value &&\n        \
    \                             !has_scan<T>::value>::type* = nullptr>\n    void\
    \ scan(T& a) {\n        discard_space();\n        bool sgn = false;\n        if\
    \ IF_CONSTEXPR (std::is_signed<T>::value) {\n            if (*itr == '-') {\n\
    \                sgn = true;\n                ++itr;\n            }\n        }\n\
    \        a = 0;\n        while ('0' <= *itr && *itr <= '9') {\n            a =\
    \ a * 10 + *itr - '0';\n            ++itr;\n        }\n        if IF_CONSTEXPR\
    \ (std::is_signed<T>::value) {\n            if (sgn) a = -a;\n        }\n    }\n\
    \    template<class T,\n             typename std::enable_if<std::is_floating_point<T>::value\
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
    \ }\n};\n\nScanner<Reader<>::iterator> scan(reader.begin());\n\ntemplate<class\
    \ Iterator, std::size_t decimal_precision>\nScanner<Iterator, decimal_precision>&\n\
    getline(Scanner<Iterator, decimal_precision>& scan, std::string& a) {\n    a.clear();\n\
    \    char c;\n    while ((c = scan.scan_char()) != '\\n') {\n        a += c;\n\
    \    }\n    return scan;\n}\n#line 2 \"template/out.hpp\"\n\n#line 8 \"template/out.hpp\"\
    \n\ntemplate<std::size_t buf_size = IO_BUFFER_SIZE> class Writer {\nprivate:\n\
    \    int fd, idx;\n    std::array<char, buf_size> buffer;\n    inline void write_buf()\
    \ {\n        int num = write(fd, buffer.begin(), idx);\n        idx = 0;\n   \
    \     if (num < 0) throw std::runtime_error(\"output failed\");\n    }\n\npublic:\n\
    \    Writer() noexcept : fd(1), idx(0) {}\n    Writer(int fd) noexcept : fd(fd),\
    \ idx(0) {}\n    Writer(FILE* fp) noexcept : fd(fileno(fp)), idx(0) {}\n\n   \
    \ ~Writer() { write_buf(); }\n\n    class iterator {\n    private:\n        Writer*\
    \ writer;\n\n    public:\n        using difference_type = void;\n        using\
    \ value_type = void;\n        using pointer = void;\n        using reference =\
    \ void;\n        using iterator_category = std::output_iterator_tag;\n\n     \
    \   iterator() noexcept : writer(nullptr) {}\n        explicit iterator(Writer&\
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
    \ T,\n             typename std::enable_if<std::is_integral<T>::value &&\n   \
    \                                  !has_print<T>::value>::type* = nullptr>\n \
    \   void print(T a) {\n        if (!a) {\n            print_char('0');\n     \
    \       return;\n        }\n        if IF_CONSTEXPR (std::is_signed<T>::value)\
    \ {\n            if (a < 0) {\n                print_char('-');\n            \
    \    a = -a;\n            }\n        }\n        std::string s;\n        while\
    \ (a) {\n            s += (char)(a % 10 + '0');\n            a /= 10;\n      \
    \  }\n        for (auto i = s.rbegin(); i != s.rend(); ++i) print_char(*i);\n\
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
    \        for (auto i = a.begin(); i != a.end(); ++i) {\n            if (i != a.begin())\
    \ {\n                if IF_CONSTEXPR (debug) print_char(',');\n              \
    \  print_char(' ');\n            }\n            print(*i);\n        }\n      \
    \  if IF_CONSTEXPR (debug) print_char('}');\n    }\n    template<class T, typename\
    \ std::enable_if<has_print<T>::value &&\n                                    \
    \          !debug>::type* = nullptr>\n    void print(const T& a) {\n        a.print(*this);\n\
    \    }\n    template<class T, typename std::enable_if<has_print<T>::value &&\n\
    \                                              debug>::type* = nullptr>\n    void\
    \ print(const T& a) {\n        a.debug(*this);\n    }\n\n    void operator()()\
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
    \ SetPrec{n}; };\n\nPrinter<Writer<>::iterator> print(writer.begin()), eprint(writer.begin());\n\
    \ntemplate<class T> auto prints(const T& v) -> decltype(print << v, (void)0) {\n\
    \    print << v;\n    print.print_char('\\n');\n}\n\n#ifdef SHIO_LOCAL\nPrinter<Writer<>::iterator,\
    \ true> debug(writer.begin()),\n    edebug(ewriter.begin());\n#else\nchar debug_iterator_character;\n\
    class DebugIterator {\npublic:\n    DebugIterator() noexcept = default;\n    DebugIterator&\
    \ operator++() { return *this; }\n    DebugIterator& operator++(int) { return\
    \ *this; }\n    char& operator*() const { return debug_iterator_character; }\n\
    \    void flush() const {}\n};\nPrinter<DebugIterator> debug, edebug;\n#endif\n\
    #line 2 \"template/bitop.hpp\"\n\n#line 6 \"template/bitop.hpp\"\n\nnamespace\
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
    \ x) { return x ? msb(x - 1) + 1 : 0; }\n\n} // namespace bitop\n\ninline CONSTEXPR\
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
    \ PLL extGCD(ll a, ll b) {\n    const ll n = a, m = b;\n    ll x = 1, y = 0, u\
    \ = 0, v = 1;\n    ll t;\n    while (b) {\n        t = a / b;\n        std::swap(a\
    \ -= t * b, b);\n        std::swap(x -= t * u, u);\n        std::swap(y -= t *\
    \ v, v);\n    }\n    if (x < 0) {\n        x += m;\n        y -= n;\n    }\n \
    \   return {x, y};\n}\ninline ll mod_inv(ll a, ll mod) {\n    ll b = mod;\n  \
    \  ll x = 1, u = 0;\n    ll t;\n    while (b) {\n        t = a / b;\n        std::swap(a\
    \ -= t * b, b);\n        std::swap(x -= t * u, u);\n    }\n    if (x < 0) x +=\
    \ mod;\n    assert(a == 1);\n    return x;\n}\n#line 2 \"template/util.hpp\"\n\
    \n#line 6 \"template/util.hpp\"\n\ntemplate<class F> class RecLambda {\nprivate:\n\
    \    F f;\n\npublic:\n    explicit constexpr RecLambda(F&& f_) : f(std::forward<F>(f_))\
    \ {}\n    template<class... Args>\n    constexpr auto operator()(Args&&... args)\n\
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
    \   void press(std::vector<T>& vec) const {\n        static_assert(std::is_integral<T>::value,\n\
    \                      \"template argument must be convertible from int type\"\
    );\n        assert(sorted);\n        each_for (i : vec) i = get(i);\n    }\n \
    \   int size() const {\n        assert(sorted);\n        return dat.size();\n\
    \    }\n    const std::vector<T>& data() const& { return dat; }\n    std::vector<T>\
    \ data() && { return std::move(dat); }\n};\n#line 2 \"other/monoid2.hpp\"\n\n\
    #line 2 \"other/monoid.hpp\"\n\n#line 4 \"other/monoid.hpp\"\n\nnamespace Monoid\
    \ {\n\ntemplate<class M, class = void> class has_op : public std::false_type {};\n\
    template<class M>\nclass has_op<M, decltype((void)M::op)> : public std::true_type\
    \ {};\n\ntemplate<class M, class = void> class has_id : public std::false_type\
    \ {};\ntemplate<class M>\nclass has_id<M, decltype((void)M::id)> : public std::true_type\
    \ {};\n\ntemplate<class M, class = void> class has_inv : public std::false_type\
    \ {};\ntemplate<class M>\nclass has_inv<M, decltype((void)M::inv)> : public std::true_type\
    \ {};\n\ntemplate<class M, class = void> class has_get_inv : public std::false_type\
    \ {};\ntemplate<class M>\nclass has_get_inv<M, decltype((void)M::get_inv)> : public\
    \ std::true_type {};\n\ntemplate<class M, class = void> class has_init : public\
    \ std::false_type {};\ntemplate<class M>\nclass has_init<M, decltype((void)M::init(0,\
    \ 0))> : public std::true_type {};\n\ntemplate<class A, class = void> class has_mul_op\
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
    \ E_::op(b, a); }\n};\n\n} // namespace Monoid\n#line 5 \"other/monoid2.hpp\"\n\
    \nnamespace Monoid {\n\ntemplate<class T> struct Product {\n    using value_type\
    \ = T;\n    static T op(const T& a, const T& b) { return a * b; }\n    static\
    \ T id() { return T{1}; }\n    static T inv(const T& a, const T& b) { return a\
    \ / b; }\n    static T get_inv(const T& a) { return T{1} / a; }\n};\n\ntemplate<class\
    \ T> struct Composite {\n    using value_type = std::pair<T, T>;\n    static value_type\
    \ op(const value_type& a, const value_type& b) {\n        return {b.first * a.first,\
    \ b.first * a.second + b.second};\n    }\n    static value_type id() { return\
    \ {T{1}, T{0}}; }\n    static value_type get_inv(const value_type& a) {\n    \
    \    return {T{1} / a.first, -a.second / a.first};\n    }\n    static value_type\
    \ inv(const value_type& a, const value_type& b) {\n        return op(a, get_inv(b));\n\
    \    }\n};\n\ntemplate<class T> struct GCD {\n    using value_type = T;\n    static\
    \ T op(T a, T b) { return gcd(a, b); }\n    static T id() { return 0; }\n};\n\
    template<class T> struct LCM {\n    using value_type = T;\n    static T op(T a,\
    \ T b) { return lcm(a, b); }\n    static T id() { return 1; }\n};\n\ntemplate<class\
    \ T> struct AddAssign {\n    using value_type = std::pair<bool, T>; // false:\
    \ add, true: assign\n    static value_type op(const value_type& a, const value_type&\
    \ b) {\n        if (b.first) return b;\n        return {a.first, a.second + b.second};\n\
    \    }\n    static value_type id() { return {false, T{0}}; }\n};\n\n\ntemplate<class\
    \ T> struct AffineSum {\n    using M = Sum<T>;\n    using E = Composite<T>;\n\
    \    using U = typename E::value_type;\n    static T mul_op(const U& a, int b,\
    \ const T& c) {\n        return a.first * c + a.second * b;\n    }\n};\n\ntemplate<class\
    \ T> struct AddAssignSum {\n    using M = Sum<T>;\n    using E = AddAssign<T>;\n\
    \    using U = typename E::value_type;\n    static T mul_op(const U& a, int b,\
    \ const T& c) {\n        if (a.first) return a.second * b;\n        return c +\
    \ a.second * b;\n    }\n};\n\n} // namespace Monoid\n#line 2 \"math/ModInt.hpp\"\
    \n\n#line 4 \"math/ModInt.hpp\"\n\ntemplate<class T, T mod> class StaticModInt\
    \ {\n    static_assert(std::is_unsigned<T>::value, \"T must be unsigned integer\"\
    );\n    static_assert(mod > 0, \"mod must be positive\");\n    static_assert(mod\
    \ <= std::numeric_limits<T>::max() / 2,\n                  \"mod * 2 must be less\
    \ than or equal to T::max()\");\n\nprivate:\n    using large_t = typename double_size_uint<T>::type;\n\
    \    using signed_t = typename std::make_signed<T>::type;\n    T val;\n    static\
    \ constexpr unsigned int inv1000000007[] = {\n        0,         1,         500000004,\
    \ 333333336, 250000002, 400000003,\n        166666668, 142857144, 125000001, 111111112,\
    \ 700000005};\n    static constexpr unsigned int inv998244353[] = {\n        0,\
    \         1,         499122177, 332748118, 748683265, 598946612,\n        166374059,\
    \ 855638017, 873463809, 443664157, 299473306};\n\npublic:\n    StaticModInt()\
    \ : val(0) {}\n    template<class U,\n             typename std::enable_if<std::is_signed<U>::value>::type*\
    \ = nullptr>\n    StaticModInt(U v) {\n        v %= static_cast<signed_t>(mod);\n\
    \        if (v < 0) v += static_cast<signed_t>(mod);\n        val = static_cast<T>(v);\n\
    \    }\n    template<class U, typename std::enable_if<\n                     \
    \     std::is_unsigned<U>::value>::type* = nullptr>\n    StaticModInt(U v) {\n\
    \        val = static_cast<T>(v % mod);\n    }\n    T get() const { return val;\
    \ }\n    static T get_mod() { return mod; }\n    static StaticModInt raw(T v)\
    \ {\n        StaticModInt res;\n        res.val = v;\n        return res;\n  \
    \  }\n    StaticModInt inv() const {\n        if IF_CONSTEXPR (mod == 1000000007)\
    \ {\n            if (val <= 10) return inv1000000007[val];\n        }\n      \
    \  else if IF_CONSTEXPR (mod == 998244353) {\n            if (val <= 10) return\
    \ inv998244353[val];\n        }\n        return mod_inv(val, mod);\n    }\n  \
    \  StaticModInt& operator++() {\n        ++val;\n        if (val == mod) val =\
    \ 0;\n        return *this;\n    }\n    StaticModInt operator++(int) {\n     \
    \   StaticModInt res = *this;\n        ++*this;\n        return res;\n    }\n\
    \    StaticModInt& operator--() {\n        if (val == 0) val = mod;\n        --val;\n\
    \        return *this;\n    }\n    StaticModInt operator--(int) {\n        StaticModInt\
    \ res = *this;\n        --*this;\n        return res;\n    }\n    StaticModInt&\
    \ operator+=(const StaticModInt& other) {\n        val += other.val;\n       \
    \ if (val >= mod) val -= mod;\n        return *this;\n    }\n    StaticModInt&\
    \ operator-=(const StaticModInt& other) {\n        if (val < other.val) val +=\
    \ mod;\n        val -= other.val;\n        return *this;\n    }\n    StaticModInt&\
    \ operator*=(const StaticModInt& other) {\n        large_t a = val;\n        a\
    \ *= other.val;\n        a %= mod;\n        val = a;\n        return *this;\n\
    \    }\n    StaticModInt& operator/=(const StaticModInt& other) {\n        *this\
    \ *= other.inv();\n        return *this;\n    }\n    friend StaticModInt operator+(const\
    \ StaticModInt& lhs,\n                                  const StaticModInt& rhs)\
    \ {\n        return StaticModInt(lhs) += rhs;\n    }\n    friend StaticModInt\
    \ operator-(const StaticModInt& lhs,\n                                  const\
    \ StaticModInt& rhs) {\n        return StaticModInt(lhs) -= rhs;\n    }\n    friend\
    \ StaticModInt operator*(const StaticModInt& lhs,\n                          \
    \        const StaticModInt& rhs) {\n        return StaticModInt(lhs) *= rhs;\n\
    \    }\n    friend StaticModInt operator/(const StaticModInt& lhs,\n         \
    \                         const StaticModInt& rhs) {\n        return StaticModInt(lhs)\
    \ /= rhs;\n    }\n    StaticModInt operator+() const { return StaticModInt(*this);\
    \ }\n    StaticModInt operator-() const { return StaticModInt() - *this; }\n \
    \   friend bool operator==(const StaticModInt& lhs, const StaticModInt& rhs) {\n\
    \        return lhs.val == rhs.val;\n    }\n    friend bool operator!=(const StaticModInt&\
    \ lhs, const StaticModInt& rhs) {\n        return lhs.val != rhs.val;\n    }\n\
    \    StaticModInt pow(ll a) const {\n        StaticModInt v = *this, res = 1;\n\
    \        while (a) {\n            if (a & 1) res *= v;\n            a >>= 1;\n\
    \            v *= v;\n        }\n        return res;\n    }\n    friend std::ostream&\
    \ operator<<(std::ostream& ost, const StaticModInt& sm) {\n        return ost\
    \ << sm.val;\n    }\n    template<class Pr> void print(Pr& a) const { a.print(val);\
    \ }\n    template<class Pr> void debug(Pr& a) const { a.print(val); }\n    friend\
    \ std::istream& operator>>(std::istream& ist, StaticModInt& sm) {\n        ll\
    \ v;\n        ist >> v;\n        sm = v;\n        return ist;\n    }\n    template<class\
    \ Sc> void scan(Sc& a) {\n        ll v;\n        a.scan(v);\n        *this = v;\n\
    \    }\n};\n\n#if __cplusplus < 201703L\ntemplate<unsigned int mod>\nconstexpr\
    \ unsigned int StaticModInt<mod>::inv1000000007[];\ntemplate<unsigned int mod>\n\
    constexpr unsigned int StaticModInt<mod>::inv998244353[];\n#endif\n\nusing modint1000000007\
    \ = StaticModInt<unsigned int, 1000000007>;\nusing modint998244353 = StaticModInt<unsigned\
    \ int, 998244353>;\n\ntemplate<class T, int id> class DynamicModInt {\n    static_assert(std::is_unsigned<T>::value,\
    \ \"T must be unsigned integer\");\n\nprivate:\n    using large_t = typename double_size_uint<T>::type;\n\
    \    using signed_t = typename std::make_signed<T>::type;\n    T val;\n    static\
    \ T mod;\n\npublic:\n    DynamicModInt() : val(0) {}\n    template<class U,\n\
    \             typename std::enable_if<std::is_signed<U>::value>::type* = nullptr>\n\
    \    DynamicModInt(U v) {\n        v %= static_cast<signed_t>(mod);\n        if\
    \ (v < 0) v += static_cast<signed_t>(mod);\n        val = static_cast<T>(v);\n\
    \    }\n    template<class U, typename std::enable_if<\n                     \
    \     std::is_unsigned<U>::value>::type* = nullptr>\n    DynamicModInt(U v) {\n\
    \        val = static_cast<T>(v % mod);\n    }\n    T get() const { return val;\
    \ }\n    static T get_mod() { return mod; }\n    static void set_mod(T v) {\n\
    \        assert(v > 0);\n        assert(v <= std::numeric_limits<T>::max() / 2);\n\
    \        mod = v;\n    }\n    static DynamicModInt raw(T v) {\n        DynamicModInt\
    \ res;\n        res.val = v;\n        return res;\n    }\n    DynamicModInt inv()\
    \ const { return mod_inv(val, mod); }\n    DynamicModInt& operator++() {\n   \
    \     ++val;\n        if (val == mod) val = 0;\n        return *this;\n    }\n\
    \    DynamicModInt operator++(int) {\n        DynamicModInt res = *this;\n   \
    \     ++*this;\n        return res;\n    }\n    DynamicModInt& operator--() {\n\
    \        if (val == 0) val = mod;\n        --val;\n        return *this;\n   \
    \ }\n    DynamicModInt operator--(int) {\n        DynamicModInt res = *this;\n\
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
    \  a >>= 1;\n            v *= v;\n        }\n        return res;\n    }\n    friend\
    \ std::ostream& operator<<(std::ostream& ost,\n                              \
    \      const DynamicModInt& dm) {\n        return ost << dm.val;\n    }\n    template<class\
    \ Pr> void print(Pr& a) const { a.print(val); }\n    template<class Pr> void debug(Pr&\
    \ a) const { a.print(val); }\n    friend std::istream& operator>>(std::istream&\
    \ ist, DynamicModInt& dm) {\n        ll v;\n        ist >> v;\n        dm = v;\n\
    \        return ist;\n    }\n    template<class Sc> void scan(Sc& a) {\n     \
    \   ll v;\n        a.scan(v);\n        *this = v;\n    }\n};\n\ntemplate<class\
    \ T, int id> T DynamicModInt<T, id>::mod = 998244353;\n\nusing modint = DynamicModInt<unsigned\
    \ int, -1>;\n\n/**\n * @brief ModInt\n * @docs docs/math/ModInt.md\n */\n#line\
    \ 2 \"data-struct/other/SkipList.hpp\"\n\n#line 2 \"random/Random.hpp\"\n\n#line\
    \ 4 \"random/Random.hpp\"\n\ntemplate<class Engine> class Random {\nprivate:\n\
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
    \n\ntemplate<class A, class Rand = Random32> class SkipList {\nprivate:\n    using\
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
    \    nodepair sl;\n\n    template<bool AlwaysTrue = true,\n             typename\
    \ std::enable_if<!Monoid::has_mul_op<A>::value &&\n                          \
    \           AlwaysTrue>::type* = nullptr>\n    static inline T Aop(const U& a,\
    \ const T& b, int) {\n        return A::op(a, b);\n    }\n    template<bool AlwaysTrue\
    \ = true,\n             typename std::enable_if<Monoid::has_mul_op<A>::value &&\n\
    \                                     AlwaysTrue>::type* = nullptr>\n    static\
    \ inline T Aop(const U& a, const T& b, int c) {\n        return A::mul_op(a, c,\
    \ b);\n    }\n\n    static inline void all_apply(const node_ptr& nd, int k, const\
    \ U& x) {\n        assert(0 <= k && k < nd->level());\n        nd->nxt[k].sm =\
    \ Aop(x, nd->nxt[k].sm, nd->nxt[k].dist);\n        if (k != 0) {\n           \
    \ if (nd->nxt[k].lazyflag) {\n                nd->nxt[k].lazy = E::op(nd->nxt[k].lazy,\
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
    \ [&](const T& sm) { return Aop(x, sm, 1); });\n    }\n    template<class C> int\
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
    \n/**\n * @brief SkipList\n * @docs docs/data-struct/other/SkipList.md\n */\n\
    #line 6 \"test/yosupo/data_structure/dynamic_sequence_range_affine_range_sum.test.cpp\"\
    \nusing namespace std;\nusing mint = modint998244353;\nint main() {\n    int N,\
    \ Q; scan >> N >> Q;\n    vector<mint> A(N); scan >> A;\n    SkipList<Monoid::AffineSum<mint>>\
    \ sl(A), slrev(vector<mint>(rall(A)));\n    rep (Q) {\n        int t; scan >>\
    \ t;\n        if (t == 0) {\n            int k; scan >> k;\n            mint x;\
    \ scan >> x;\n            sl.insert(k, x);\n            slrev.insert(slrev.size()\
    \ - k, x);\n        }\n        else if (t == 1) {\n            int k; scan >>\
    \ k;\n            sl.erase(k);\n            slrev.erase(slrev.size() - k - 1);\n\
    \        }\n        else if (t == 2) {\n            int l, r; scan >> l >> r;\n\
    \            auto s11 = split(std::move(sl), l);\n            auto s12 = split(std::move(s11.second),\
    \ r - l);\n            int n = slrev.size();\n            auto s21 = split(std::move(slrev),\
    \ n - r);\n            auto s22 = split(std::move(s21.second), r - l);\n     \
    \       sl = merge(merge(std::move(s11.first), std::move(s22.first)), std::move(s12.second));\n\
    \            slrev = merge(merge(std::move(s21.first), std::move(s12.first)),\
    \ std::move(s22.second));\n        }\n        else if (t == 3) {\n           \
    \ int l, r; scan >> l >> r;\n            mint b, c; scan >> b >> c;\n        \
    \    sl.apply(l, r, {b, c});\n            slrev.apply(slrev.size() - r, slrev.size()\
    \ - l, {b, c});\n        }\n        else {\n            int l, r; scan >> l >>\
    \ r;\n            print << sl.prod(l, r) << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n#include \"../../../other/template.hpp\"\n#include \"../../../other/monoid2.hpp\"\
    \n#include \"../../../math/ModInt.hpp\"\n#include \"../../../data-struct/other/SkipList.hpp\"\
    \nusing namespace std;\nusing mint = modint998244353;\nint main() {\n    int N,\
    \ Q; scan >> N >> Q;\n    vector<mint> A(N); scan >> A;\n    SkipList<Monoid::AffineSum<mint>>\
    \ sl(A), slrev(vector<mint>(rall(A)));\n    rep (Q) {\n        int t; scan >>\
    \ t;\n        if (t == 0) {\n            int k; scan >> k;\n            mint x;\
    \ scan >> x;\n            sl.insert(k, x);\n            slrev.insert(slrev.size()\
    \ - k, x);\n        }\n        else if (t == 1) {\n            int k; scan >>\
    \ k;\n            sl.erase(k);\n            slrev.erase(slrev.size() - k - 1);\n\
    \        }\n        else if (t == 2) {\n            int l, r; scan >> l >> r;\n\
    \            auto s11 = split(std::move(sl), l);\n            auto s12 = split(std::move(s11.second),\
    \ r - l);\n            int n = slrev.size();\n            auto s21 = split(std::move(slrev),\
    \ n - r);\n            auto s22 = split(std::move(s21.second), r - l);\n     \
    \       sl = merge(merge(std::move(s11.first), std::move(s22.first)), std::move(s12.second));\n\
    \            slrev = merge(merge(std::move(s21.first), std::move(s12.first)),\
    \ std::move(s22.second));\n        }\n        else if (t == 3) {\n           \
    \ int l, r; scan >> l >> r;\n            mint b, c; scan >> b >> c;\n        \
    \    sl.apply(l, r, {b, c});\n            slrev.apply(slrev.size() - r, slrev.size()\
    \ - l, {b, c});\n        }\n        else {\n            int l, r; scan >> l >>\
    \ r;\n            print << sl.prod(l, r) << endl;\n        }\n    }\n}\n"
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
  - other/monoid2.hpp
  - other/monoid.hpp
  - math/ModInt.hpp
  - data-struct/other/SkipList.hpp
  - random/Random.hpp
  isVerificationFile: true
  path: test/yosupo/data_structure/dynamic_sequence_range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2022-11-12 14:20:38+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/data_structure/dynamic_sequence_range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/data_structure/dynamic_sequence_range_affine_range_sum.test.cpp
- /verify/test/yosupo/data_structure/dynamic_sequence_range_affine_range_sum.test.cpp.html
title: test/yosupo/data_structure/dynamic_sequence_range_affine_range_sum.test.cpp
---