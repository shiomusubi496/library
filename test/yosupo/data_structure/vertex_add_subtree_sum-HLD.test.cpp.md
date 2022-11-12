---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-struct/segment/BinaryIndexedTree.hpp
    title: BinaryIndexedTree(FenwickTree, BIT)
  - icon: ':question:'
    path: graph/Graph.hpp
    title: Graph-template
  - icon: ':question:'
    path: graph/tree/HeavyLightDecomposition.hpp
    title: "HeavyLightDecomposition(HL\u5206\u89E3)"
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
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "#line 1 \"test/yosupo/data_structure/vertex_add_subtree_sum-HLD.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\n\
    #line 2 \"other/template.hpp\"\n\n#include <bits/stdc++.h>\n#line 2 \"template/macros.hpp\"\
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
    \ data() && { return std::move(dat); }\n};\n#line 2 \"data-struct/segment/BinaryIndexedTree.hpp\"\
    \n\n#line 2 \"other/monoid.hpp\"\n\n#line 4 \"other/monoid.hpp\"\n\nnamespace\
    \ Monoid {\n\ntemplate<class M, class = void> class has_op : public std::false_type\
    \ {};\ntemplate<class M>\nclass has_op<M, decltype((void)M::op)> : public std::true_type\
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
    \ E_::op(b, a); }\n};\n\n} // namespace Monoid\n#line 5 \"data-struct/segment/BinaryIndexedTree.hpp\"\
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
    \ * @docs docs/graph/Graph.md\n */\n#line 2 \"graph/tree/HeavyLightDecomposition.hpp\"\
    \n\n#line 5 \"graph/tree/HeavyLightDecomposition.hpp\"\n\ntemplate<class T> class\
    \ HeavyLightDecomposition {\nprivate:\n    int n, root, cnt;\n    std::vector<int>\
    \ ssz, head, vin, vout, par;\n    const Graph<T>& G;\n    int szdfs(int v, int\
    \ p) {\n        ssz[v] = 1;\n        each_const (e : G[v]) {\n            if (e.to\
    \ == p) continue;\n            ssz[v] += szdfs(e.to, v);\n        }\n        return\
    \ ssz[v];\n    }\n    void bldfs(int v, int p) {\n        par[v] = p;\n      \
    \  vin[v] = cnt++;\n        int idx = -1;\n        each_const (e : G[v]) {\n \
    \           if (e.to != p) {\n                if (idx == -1 || ssz[idx] < ssz[e.to])\
    \ idx = e.to;\n            }\n        }\n        if (idx != -1) {\n          \
    \  head[idx] = head[v];\n            bldfs(idx, v);\n        }\n        each_const\
    \ (e : G[v]) {\n            if (e.to != p && e.to != idx) {\n                head[e.to]\
    \ = e.to;\n                bldfs(e.to, v);\n            }\n        }\n       \
    \ vout[v] = cnt;\n    }\n    void init() {\n        n = G.size();\n        ssz.assign(n,\
    \ -1);\n        szdfs(root, -1);\n        rep (i, n) {\n            if (ssz[i]\
    \ == -1) szdfs(i, -1);\n        }\n        cnt = 0;\n        head.assign(n, -1);\n\
    \        head[root] = root;\n        vin.resize(n);\n        vout.resize(n);\n\
    \        par.resize(n);\n        bldfs(root, -1);\n        rep (i, n) {\n    \
    \        if (head[i] == -1) {\n                head[i] = i;\n                bldfs(i,\
    \ -1);\n            }\n        }\n    }\n\npublic:\n    HeavyLightDecomposition(const\
    \ Graph<T>& G, int root = 0)\n        : root(root), G(G) {\n        init();\n\
    \    }\n    int get_size(int k) const { return ssz[k]; }\n    std::pair<int, int>\
    \ get_idx(int k) const { return {vin[k], vout[k]}; }\n    std::pair<int, int>\
    \ get_pach(int a, int b) const {\n        if (vin[a] < vin[b]) return {a, b};\n\
    \        return {b, a};\n    }\n    int lca(int u, int v) const {\n        while\
    \ (head[u] != head[v]) {\n            if (vin[u] > vin[v]) std::swap(u, v);\n\
    \            v = par[head[v]];\n        }\n        return vin[u] < vin[v] ? u\
    \ : v;\n    }\n    std::vector<std::pair<int, int>> up_path(int u, int v) const\
    \ {\n        std::vector<std::pair<int, int>> res;\n        while (head[u] !=\
    \ head[v]) {\n            res.emplace_back(vin[u], vin[head[u]]);\n          \
    \  u = par[head[u]];\n        }\n        if (u != v) res.emplace_back(vin[u],\
    \ vin[v] + 1);\n        return res;\n    }\n    std::vector<std::pair<int, int>>\
    \ down_path(int u, int v) const {\n        auto res = up_path(v, u);\n       \
    \ each_for (p : res) std::swap(p.first, p.second);\n        std::reverse(all(res));\n\
    \        return res;\n    }\n    template<class F> void each_vertex(int u, int\
    \ v, const F& f) const {\n        return each_vertex(u, v, f, f);\n    }\n   \
    \ template<class F, class G>\n    void each_vertex(int u, int v, const F& f, const\
    \ G& g) const {\n        int l = lca(u, v);\n        auto func = [&](int a, int\
    \ b) {\n            if (a <= b) f(a, b + 1);\n            else g(b, a + 1);\n\
    \        };\n        each_const (p : up_path(u, l)) func(p.first, p.second);\n\
    \        func(vin[l], vin[l]);\n        each_const (p : down_path(l, v)) func(p.first,\
    \ p.second);\n    }\n    template<class F> void each_edge(int u, int v, const\
    \ F& f) const {\n        return each_edge(u, v, f, f);\n    }\n    template<class\
    \ F, class G>\n    void each_edge(int u, int v, const F& f, const G& g) const\
    \ {\n        int l = lca(u, v);\n        auto func = [&](int a, int b) {\n   \
    \         if (a <= b) f(a, b + 1);\n            else g(b, a + 1);\n        };\n\
    \        each_const (p : up_path(u, l)) func(p.first, p.second);\n        each_const\
    \ (p : down_path(l, v)) func(p.first, p.second);\n    }\n    template<class F>\
    \ void each_vertex_subtree(int u, const F& f) const {\n        f(vin[u], vout[u]);\n\
    \    }\n    template<class F> void each_edge_subtree(int u, const F& f) const\
    \ {\n        f(vin[u] + 1, vout[u]);\n    }\n};\n\n/**\n * @brief HeavyLightDecomposition(HL\u5206\
    \u89E3)\n * @docs docs/graph/tree/HeavyLightDecomposition.md\n */\n#line 6 \"\
    test/yosupo/data_structure/vertex_add_subtree_sum-HLD.test.cpp\"\nusing namespace\
    \ std;\nint main() {\n    int N, Q; scan >> N >> Q;\n    vector<ll> A(N); scan\
    \ >> A;\n    Graph<int> G(N);\n    rep (i, 1, N) {\n        int p; scan >> p;\n\
    \        G.add_edge(i, p);\n    }\n    HeavyLightDecomposition<int> HLD(G);\n\
    \    BinaryIndexedTree<ll> BIT(N);\n    rep (i, N) {\n        auto p = HLD.get_idx(i);\n\
    \        BIT.add(p.first, A[i]);\n    }\n    rep (i, Q) {\n        int t; scan\
    \ >> t;\n        if (t == 0) {\n            int p; ll x; scan >> p >> x;\n   \
    \         auto idx = HLD.get_idx(p);\n            BIT.add(idx.first, x);\n   \
    \     }\n        else {\n            int u; scan >> u;\n            ll ans = 0;\n\
    \            HLD.each_vertex_subtree(u, [&](int l, int r) { ans += BIT.sum(l,\
    \ r); });\n            print << ans << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n#include \"../../../other/template.hpp\"\n#include \"../../../data-struct/segment/BinaryIndexedTree.hpp\"\
    \n#include \"../../../graph/Graph.hpp\"\n#include \"../../../graph/tree/HeavyLightDecomposition.hpp\"\
    \nusing namespace std;\nint main() {\n    int N, Q; scan >> N >> Q;\n    vector<ll>\
    \ A(N); scan >> A;\n    Graph<int> G(N);\n    rep (i, 1, N) {\n        int p;\
    \ scan >> p;\n        G.add_edge(i, p);\n    }\n    HeavyLightDecomposition<int>\
    \ HLD(G);\n    BinaryIndexedTree<ll> BIT(N);\n    rep (i, N) {\n        auto p\
    \ = HLD.get_idx(i);\n        BIT.add(p.first, A[i]);\n    }\n    rep (i, Q) {\n\
    \        int t; scan >> t;\n        if (t == 0) {\n            int p; ll x; scan\
    \ >> p >> x;\n            auto idx = HLD.get_idx(p);\n            BIT.add(idx.first,\
    \ x);\n        }\n        else {\n            int u; scan >> u;\n            ll\
    \ ans = 0;\n            HLD.each_vertex_subtree(u, [&](int l, int r) { ans +=\
    \ BIT.sum(l, r); });\n            print << ans << endl;\n        }\n    }\n}\n"
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
  - data-struct/segment/BinaryIndexedTree.hpp
  - other/monoid.hpp
  - graph/Graph.hpp
  - graph/tree/HeavyLightDecomposition.hpp
  isVerificationFile: true
  path: test/yosupo/data_structure/vertex_add_subtree_sum-HLD.test.cpp
  requiredBy: []
  timestamp: '2022-11-12 14:20:38+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/data_structure/vertex_add_subtree_sum-HLD.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/data_structure/vertex_add_subtree_sum-HLD.test.cpp
- /verify/test/yosupo/data_structure/vertex_add_subtree_sum-HLD.test.cpp.html
title: test/yosupo/data_structure/vertex_add_subtree_sum-HLD.test.cpp
---