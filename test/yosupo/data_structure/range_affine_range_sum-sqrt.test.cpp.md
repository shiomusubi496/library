---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-struct/segment/SqrtDecomposition.hpp
    title: "SqrtDecomposition(\u5E73\u65B9\u5206\u5272)"
  - icon: ':question:'
    path: math/ModInt.hpp
    title: ModInt
  - icon: ':question:'
    path: other/monoid.hpp
    title: other/monoid.hpp
  - icon: ':question:'
    path: other/monoid2.hpp
    title: other/monoid2.hpp
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
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/yosupo/data_structure/range_affine_range_sum-sqrt.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\
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
    \ v.begin(), v.end()\n#endif\n\n#if __cpp_constexpr >= 201304L\n#define CONSTEXPR\
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
    #line 2 \"template/in.hpp\"\n\n#line 6 \"template/in.hpp\"\n#include <unistd.h>\n\
    \ntemplate<std::size_t buf_size = IO_BUFFER_SIZE> class Reader {\nprivate:\n \
    \   int fd, idx, sz;\n    bool state;\n    std::array<char, buf_size> buffer;\n\
    \    inline void read_buf() {\n        sz = read(fd, buffer.begin(), buf_size);\n\
    \        idx = 0;\n        if (sz < 0) throw std::runtime_error(\"input failed\"\
    );\n    }\n\npublic:\n    static constexpr int get_buf_size() { return buf_size;\
    \ }\n    Reader() noexcept : fd(0), idx(0), sz(0), state(true) {}\n    Reader(int\
    \ fd) noexcept : fd(fd), idx(0), sz(0), state(true) {}\n    Reader(FILE* fp) noexcept\
    \ : fd(fileno(fp)), idx(0), sz(0), state(true) {}\n\n    class iterator {\n  \
    \  private:\n        Reader* reader;\n\n    public:\n        using difference_type\
    \ = void;\n        using value_type = void;\n        using pointer = void;\n \
    \       using reference = void;\n        using iterator_category = std::input_iterator_tag;\n\
    \n        iterator() : reader(nullptr) {}\n        explicit iterator(Reader& reader)\
    \ : reader(&reader) {}\n        explicit iterator(Reader* reader) : reader(reader)\
    \ {}\n\n        iterator& operator++() {\n            if (reader->idx == reader->sz)\
    \ reader->read_buf();\n            ++reader->idx;\n            return *this;\n\
    \        }\n        iterator operator++(int) {\n            iterator res = *this;\n\
    \            ++(*this);\n            return res;\n        }\n        char operator*()\
    \ const {\n            if (reader->idx == reader->sz) reader->read_buf();\n  \
    \          if (reader->idx < reader->sz) return reader->buffer[reader->idx];\n\
    \            reader->state = false;\n            return '\\0';\n        }\n  \
    \      bool rdstate() const { return reader->state; }\n    };\n\n    iterator\
    \ begin() noexcept { return iterator(this); }\n};\n\nReader<> reader(0);\n\ntemplate<class\
    \ Iterator, std::size_t decimal_precision = 16> class Scanner {\npublic:\n   \
    \ using iterator_type = Iterator;\n\nprivate:\n    template<class, class = void>\
    \ struct has_scan : std::false_type {};\n    template<class T>\n    struct has_scan<\n\
    \        T, decltype(std::declval<T>().scan(std::declval<Scanner&>()), (void)0)>\n\
    \        : std::true_type {};\n    Iterator itr;\n\npublic:\n    Scanner() = default;\n\
    \    Scanner(const Iterator& itr) : itr(itr) {}\n\n    inline void discard_space()\
    \ {\n        while (('\\t' <= *itr && *itr <= '\\r') || *itr == ' ') ++itr;\n\
    \    }\n    void scan(char& a) {\n        discard_space();\n        a = *itr;\n\
    \        ++itr;\n    }\n    void scan(bool& a) {\n        discard_space();\n \
    \       a = *itr != '0';\n        ++itr;\n    }\n    void scan(std::string& a)\
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
    \ }\n};\n\nScanner<Reader<>::iterator> scan(reader.begin());\n#line 2 \"template/out.hpp\"\
    \n\n#line 7 \"template/out.hpp\"\n\ntemplate<std::size_t buf_size = IO_BUFFER_SIZE>\
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
    \nvoid prints(const std::string& s) {\n    print << s;\n    print.print_char('\\\
    n');\n}\n\n#ifdef SHIO_LOCAL\nPrinter<Writer<>::iterator, true> debug(writer.begin()),\n\
    \    edebug(ewriter.begin());\n#else\nchar debug_iterator_character;\nclass DebugIterator\
    \ {\npublic:\n    DebugIterator() noexcept = default;\n    DebugIterator& operator++()\
    \ { return *this; }\n    DebugIterator& operator++(int) { return *this; }\n  \
    \  char& operator*() const { return debug_iterator_character; }\n    void flush()\
    \ const {}\n};\nPrinter<DebugIterator> debug, edebug;\n#endif\n#line 2 \"template/bitop.hpp\"\
    \n\n#line 5 \"template/bitop.hpp\"\n\nnamespace bitop {\n\n#define KTH_BIT(b,\
    \ k) (((b) >> (k)) & 1)\n#define POW2(k) (1ull << (k))\n\ninline ull next_combination(int\
    \ n, ull x) {\n    if (n == 0) return 1;\n    ull a = x & -x;\n    ull b = x +\
    \ a;\n    return (x & ~b) / a >> 1 | b;\n}\n\n#define rep_comb(i, n, k)      \
    \                                                \\\n    for (ull i = (1ull <<\
    \ (k)) - 1; i < (1ull << (n));                         \\\n         i = bitop::next_combination((n),\
    \ i))\n\ninline CONSTEXPR int msb(ull x) {\n    int res = x ? 0 : -1;\n    if\
    \ (x & 0xFFFFFFFF00000000) x &= 0xFFFFFFFF00000000, res += 32;\n    if (x & 0xFFFF0000FFFF0000)\
    \ x &= 0xFFFF0000FFFF0000, res += 16;\n    if (x & 0xFF00FF00FF00FF00) x &= 0xFF00FF00FF00FF00,\
    \ res += 8;\n    if (x & 0xF0F0F0F0F0F0F0F0) x &= 0xF0F0F0F0F0F0F0F0, res += 4;\n\
    \    if (x & 0xCCCCCCCCCCCCCCCC) x &= 0xCCCCCCCCCCCCCCCC, res += 2;\n    return\
    \ res + ((x & 0xAAAAAAAAAAAAAAAA) ? 1 : 0);\n}\n\ninline CONSTEXPR int ceil_log2(ull\
    \ x) { return x ? msb(x - 1) + 1 : 0; }\n\n} // namespace bitop\n\ninline CONSTEXPR\
    \ int popcnt(ull x) noexcept {\n#if __cplusplus >= 202002L\n    return std::popcount(x);\n\
    #endif\n    x = (x & 0x5555555555555555) + ((x >> 1) & 0x5555555555555555);\n\
    \    x = (x & 0x3333333333333333) + ((x >> 2) & 0x3333333333333333);\n    x =\
    \ (x & 0x0f0f0f0f0f0f0f0f) + ((x >> 4) & 0x0f0f0f0f0f0f0f0f);\n    x = (x & 0x00ff00ff00ff00ff)\
    \ + ((x >> 8) & 0x00ff00ff00ff00ff);\n    x = (x & 0x0000ffff0000ffff) + ((x >>\
    \ 16) & 0x0000ffff0000ffff);\n    return (x & 0x00000000ffffffff) + ((x >> 32)\
    \ & 0x00000000ffffffff);\n}\n#line 10 \"other/template.hpp\"\n\ntemplate<class\
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
    \ std::vector<ll>& b, const std::vector<ll>& m) {\n    PLL res{0, 1};\n    rep\
    \ (i, b.size()) {\n        res = ChineseRemainder(res.first, res.second, b[i],\
    \ m[i]);\n        if (res.first == -1) return res;\n    }\n    return res;\n}\n\
    \ntemplate<class F> class RecLambda {\nprivate:\n    F f;\n\npublic:\n    explicit\
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
    }\n\ntemplate<class T, class Comp = std::less<T>> class presser {\nprivate:\n\
    \    std::vector<T> dat;\n    Comp cmp;\n    bool sorted = false;\n\npublic:\n\
    \    presser() : presser(Comp()) {}\n    presser(const Comp& cmp) : cmp(cmp) {}\n\
    \    presser(const std::vector<T>& vec, const Comp& cmp = Comp())\n        : dat(vec),\
    \ cmp(cmp) {}\n    presser(std::vector<T>&& vec, const Comp& cmp = Comp())\n \
    \       : dat(std::move(vec)), cmp(cmp) {}\n    presser(std::initializer_list<T>\
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
    \    }\n    int get(const T& val) const {\n        assert(sorted);\n        auto\
    \ itr = std::lower_bound(all(dat), val, cmp);\n        assert(itr != dat.end()\
    \ && !cmp(val, *itr));\n        return itr - dat.begin();\n    }\n    int lower_bound(const\
    \ T& val) const {\n        assert(sorted);\n        auto itr = std::lower_bound(all(dat),\
    \ val, cmp);\n        return itr - dat.begin();\n    }\n    std::vector<int> pressed(const\
    \ std::vector<T>& vec) const {\n        assert(sorted);\n        std::vector<int>\
    \ res(vec.size());\n        rep (i, vec.size()) res[i] = get(vec[i]);\n      \
    \  return res;\n    }\n    void press(std::vector<T>& vec) const {\n        static_assert(std::is_integral<T>::value,\n\
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
    \n\n#line 4 \"math/ModInt.hpp\"\n\ntemplate<unsigned int mod> class StaticModInt\
    \ {\n    static_assert(mod > 0, \"mod must be greater than 0\");\n\nprivate:\n\
    \    unsigned int val;\n    static constexpr unsigned int inv1000000007[] = {\n\
    \        0,         1,         500000004, 333333336, 250000002, 400000003,\n \
    \       166666668, 142857144, 125000001, 111111112, 700000005};\n    static constexpr\
    \ unsigned int inv998244353[] = {\n        0,         1,         499122177, 332748118,\
    \ 748683265, 598946612,\n        166374059, 855638017, 873463809, 443664157, 299473306};\n\
    \npublic:\n    StaticModInt() : val(0) {}\n    template<class T, typename std::enable_if<\n\
    \                          std::is_integral<T>::value>::type* = nullptr>\n   \
    \ StaticModInt(T v) {\n        v %= (long long)mod;\n        if (v < 0) v += (long\
    \ long)mod;\n        val = v;\n    }\n    unsigned int get() const { return val;\
    \ }\n    static unsigned int get_mod() { return mod; }\n    static StaticModInt\
    \ raw(unsigned int v) {\n        StaticModInt res;\n        res.val = v;\n   \
    \     return res;\n    }\n    StaticModInt inv() const {\n        if IF_CONSTEXPR\
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
    \    }\n    StaticModInt& operator*=(const StaticModInt& other) {\n        unsigned\
    \ long long a = val;\n        a *= other.val;\n        a %= mod;\n        val\
    \ = a;\n        return *this;\n    }\n    StaticModInt& operator/=(const StaticModInt&\
    \ other) {\n        *this *= other.inv();\n        return *this;\n    }\n    friend\
    \ StaticModInt operator+(const StaticModInt& lhs,\n                          \
    \        const StaticModInt& rhs) {\n        return StaticModInt(lhs) += rhs;\n\
    \    }\n    friend StaticModInt operator-(const StaticModInt& lhs,\n         \
    \                         const StaticModInt& rhs) {\n        return StaticModInt(lhs)\
    \ -= rhs;\n    }\n    friend StaticModInt operator*(const StaticModInt& lhs,\n\
    \                                  const StaticModInt& rhs) {\n        return\
    \ StaticModInt(lhs) *= rhs;\n    }\n    friend StaticModInt operator/(const StaticModInt&\
    \ lhs,\n                                  const StaticModInt& rhs) {\n       \
    \ return StaticModInt(lhs) /= rhs;\n    }\n    StaticModInt operator+() const\
    \ { return StaticModInt(*this); }\n    StaticModInt operator-() const { return\
    \ StaticModInt::raw(0) - *this; }\n    friend bool operator==(const StaticModInt&\
    \ lhs, const StaticModInt& rhs) {\n        return lhs.val == rhs.val;\n    }\n\
    \    friend bool operator!=(const StaticModInt& lhs, const StaticModInt& rhs)\
    \ {\n        return lhs.val != rhs.val;\n    }\n    StaticModInt pow(ll a) const\
    \ {\n        StaticModInt v = *this, res = 1;\n        while (a) {\n         \
    \   if (a & 1) res *= v;\n            a >>= 1;\n            v *= v;\n        }\n\
    \        return res;\n    }\n    friend std::ostream& operator<<(std::ostream&\
    \ ost, const StaticModInt& sm) {\n        return ost << sm.val;\n    }\n    template<class\
    \ Pr> void print(Pr& a) const { a.print(val); }\n    template<class Pr> void debug(Pr&\
    \ a) const { a.print(val); }\n    friend std::istream& operator>>(std::istream&\
    \ ist, StaticModInt& sm) {\n        ll v;\n        ist >> v;\n        sm = v;\n\
    \        return ist;\n    }\n    template<class Sc> void scan(Sc& a) {\n     \
    \   ll v;\n        a.scan(v);\n        *this = v;\n    }\n};\n\n#if __cplusplus\
    \ < 201703L\ntemplate<unsigned int mod>\nconstexpr unsigned int StaticModInt<mod>::inv1000000007[];\n\
    template<unsigned int mod>\nconstexpr unsigned int StaticModInt<mod>::inv998244353[];\n\
    #endif\n\nusing modint1000000007 = StaticModInt<1000000007>;\nusing modint998244353\
    \ = StaticModInt<998244353>;\n\ntemplate<int id> class DynamicModInt {\nprivate:\n\
    \    unsigned int val;\n    static unsigned int mod;\n\npublic:\n    DynamicModInt()\
    \ : val(0) {}\n    template<class T, typename std::enable_if<\n              \
    \            std::is_integral<T>::value>::type* = nullptr>\n    DynamicModInt(T\
    \ v) {\n        v %= (long long)mod;\n        if (v < 0) v += (long long)mod;\n\
    \        val = v;\n    }\n    unsigned int get() const { return val; }\n    static\
    \ unsigned int get_mod() { return mod; }\n    static void set_mod(unsigned int\
    \ v) {\n        assert(v > 0);\n        mod = v;\n    }\n    static DynamicModInt\
    \ raw(unsigned int v) {\n        DynamicModInt res;\n        res.val = v;\n  \
    \      return res;\n    }\n    DynamicModInt inv() const { return mod_inv(val,\
    \ mod); }\n    DynamicModInt& operator++() {\n        ++val;\n        if (val\
    \ == mod) val = 0;\n        return *this;\n    }\n    DynamicModInt operator++(int)\
    \ {\n        DynamicModInt res = *this;\n        ++*this;\n        return res;\n\
    \    }\n    DynamicModInt& operator--() {\n        if (val == 0) val = mod;\n\
    \        --val;\n        return *this;\n    }\n    DynamicModInt operator--(int)\
    \ {\n        DynamicModInt res = *this;\n        --*this;\n        return res;\n\
    \    }\n    DynamicModInt& operator+=(const DynamicModInt& other) {\n        val\
    \ += other.val;\n        if (val >= mod) val -= mod;\n        return *this;\n\
    \    }\n    DynamicModInt& operator-=(const DynamicModInt& other) {\n        if\
    \ (val < other.val) val += mod;\n        val -= other.val;\n        return *this;\n\
    \    }\n    DynamicModInt& operator*=(const DynamicModInt& other) {\n        unsigned\
    \ long long a = val;\n        a *= other.val;\n        a %= mod;\n        val\
    \ = a;\n        return *this;\n    }\n    DynamicModInt& operator/=(const DynamicModInt&\
    \ other) {\n        *this *= other.inv();\n        return *this;\n    }\n    friend\
    \ DynamicModInt operator+(const DynamicModInt& lhs,\n                        \
    \           const DynamicModInt& rhs) {\n        return DynamicModInt(lhs) +=\
    \ rhs;\n    }\n    friend DynamicModInt operator-(const DynamicModInt& lhs,\n\
    \                                   const DynamicModInt& rhs) {\n        return\
    \ DynamicModInt(lhs) -= rhs;\n    }\n    friend DynamicModInt operator*(const\
    \ DynamicModInt& lhs,\n                                   const DynamicModInt&\
    \ rhs) {\n        return DynamicModInt(lhs) *= rhs;\n    }\n    friend DynamicModInt\
    \ operator/(const DynamicModInt& lhs,\n                                   const\
    \ DynamicModInt& rhs) {\n        return DynamicModInt(lhs) /= rhs;\n    }\n  \
    \  DynamicModInt operator+() const { return DynamicModInt(*this); }\n    DynamicModInt\
    \ operator-() const { return DynamicModInt::raw(0) - *this; }\n    friend bool\
    \ operator==(const DynamicModInt& lhs, const DynamicModInt& rhs) {\n        return\
    \ lhs.val == rhs.val;\n    }\n    friend bool operator!=(const DynamicModInt&\
    \ lhs, const DynamicModInt& rhs) {\n        return lhs.val != rhs.val;\n    }\n\
    \    DynamicModInt pow(ll a) const {\n        DynamicModInt v = *this, res = 1;\n\
    \        while (a) {\n            if (a & 1) res *= v;\n            a >>= 1;\n\
    \            v *= v;\n        }\n        return res;\n    }\n    friend std::ostream&\
    \ operator<<(std::ostream& ost,\n                                    const DynamicModInt&\
    \ dm) {\n        return ost << dm.val;\n    }\n    template<class Pr> void print(Pr&\
    \ a) const { a.print(val); }\n    template<class Pr> void debug(Pr& a) const {\
    \ a.print(val); }\n    friend std::istream& operator>>(std::istream& ist, DynamicModInt&\
    \ dm) {\n        ll v;\n        ist >> v;\n        dm = v;\n        return ist;\n\
    \    }\n    template<class Sc> void scan(Sc& a) {\n        ll v;\n        a.scan(v);\n\
    \        *this = v;\n    }\n};\n\ntemplate<int id> unsigned int DynamicModInt<id>::mod\
    \ = 1000000007;\n\nusing modint = DynamicModInt<-1>;\n\n/**\n * @brief ModInt\n\
    \ * @docs docs/math/ModInt.md\n */\n#line 2 \"data-struct/segment/SqrtDecomposition.hpp\"\
    \n\n#line 5 \"data-struct/segment/SqrtDecomposition.hpp\"\n\ntemplate<class T,\
    \ class F, class G = void, class A = void>\nclass SqrtDecomposition;\n\ntemplate<class\
    \ T, class F> class SqrtDecomposition<T, F, void, void> {\n    static_assert(std::is_same<typename\
    \ function_traits<F>::argument_tuple,\n                               std::tuple<std::vector<T>&&>>::value,\n\
    \                  \"F must take a single argument of type vector<T>&&\");\n\n\
    protected:\n    using U = typename function_traits<F>::result_type;\n    int n,\
    \ b, nb;\n    F f;\n    std::vector<T> v;\n    std::vector<U> data;\n    virtual\
    \ void eval(int) { return; }\n\npublic:\n    SqrtDecomposition(const std::vector<T>&\
    \ v_, const F& f) : f(f) { init(v_); }\n    SqrtDecomposition(const std::vector<T>&\
    \ v_, int b_, const F& f) : f(f) {\n        init(v_, b_);\n    }\n    void init(const\
    \ std::vector<T>& v_, int b_ = -1) {\n        v = v_;\n        n = v.size();\n\
    \        if (b_ == -1) b_ = sqrt(n);\n        b = b_;\n        nb = n / b;\n \
    \       data.reserve(nb);\n        rep (i, nb) {\n            std::vector<T> v2(v.begin()\
    \ + i * b, v.begin() + (i + 1) * b);\n            data.push_back(f(std::move(v2)));\n\
    \        }\n    }\n    template<class M, class G, class H>\n    auto prod(int\
    \ l, int r, const G& g, const H& h) -> typename std::enable_if<\n        Monoid::is_monoid<M>::value\
    \ &&\n            std::is_same<decltype(g(std::declval<T>())),\n             \
    \            typename M::value_type>::value &&\n            std::is_same<decltype(h(std::declval<U>())),\n\
    \                         typename M::value_type>::value,\n        typename M::value_type>::type\
    \ {\n        using S = typename M::value_type;\n        assert(0 <= l && l <=\
    \ r && r <= n);\n        const int lb = l / b, rb = r / b;\n        if (lb ==\
    \ rb) {\n            if (lb < nb) eval(lb);\n            S res = M::id();\n  \
    \          rep (i, l, r) res = M::op(res, g(v[i]));\n            return res;\n\
    \        }\n        eval(lb);\n        if (rb < nb) eval(rb);\n        S res =\
    \ M::id();\n        rep (i, l, b * (lb + 1)) res = M::op(res, g(v[i]));\n    \
    \    rep (i, lb + 1, rb) res = M::op(res, h(data[i]));\n        rep (i, rb * b,\
    \ r) res = M::op(res, g(v[i]));\n        return res;\n    }\n    template<class\
    \ G>\n    auto update(int k, const G& g) -> typename std::enable_if<\n       \
    \ std::is_same<decltype(g(std::declval<T&>())), void>::value>::type {\n      \
    \  assert(0 <= k && k < n);\n        const int bk = k / b;\n        if (bk < nb)\
    \ eval(bk);\n        g(v[k]);\n        if (bk < nb) {\n            std::vector<T>\
    \ v2(v.begin() + bk * b, v.begin() + (bk + 1) * b);\n            data[bk] = f(std::move(v2));\n\
    \        }\n    }\n    void set(int k, const T& x) {\n        update(k, [&](T&\
    \ y) -> void { y = x; });\n    }\n};\n\ntemplate<class T, class F, class G, class\
    \ A>\nclass SqrtDecomposition : public SqrtDecomposition<T, F, void> {\nprivate:\n\
    \    using Base = SqrtDecomposition<T, F, void>;\n    using E = typename A::E;\n\
    \    using U = typename Base::U;\n    using S = typename E::value_type;\n\n  \
    \  static_assert(std::is_same<typename A::M::value_type, T>::value,\n        \
    \          \"A::M::value_type and T must be same\");\n\n    G g;\n    std::vector<S>\
    \ lazy;\n    std::vector<bool> lazyflag;\n    void eval(int i) override {\n  \
    \      if (lazyflag[i]) {\n            rep (j, this->b)\n                this->v[i\
    \ * this->b + j] =\n                    A::op(lazy[i], this->v[i * this->b + j]);\n\
    \            lazyflag[i] = false;\n        }\n    }\n    void all_apply(const\
    \ S& x, int i) {\n        g(x, this->data[i]);\n        if (lazyflag[i]) {\n \
    \           lazy[i] = E::op(lazy[i], x);\n        }\n        else {\n        \
    \    lazy[i] = x;\n            lazyflag[i] = true;\n        }\n    }\n\npublic:\n\
    \    SqrtDecomposition(const std::vector<T>& v_, const F& f, const G& g)\n   \
    \     : Base(v_, f), g(g), lazy(this->nb), lazyflag(this->nb, false) {}\n    SqrtDecomposition(const\
    \ std::vector<T>& v_, int b_, const F& f, const G& g)\n        : Base(v_, b_,\
    \ f), g(g), lazy(this->nb), lazyflag(this->nb, false) {}\n    void apply(int k,\
    \ const S& x) {\n        this->update(k, [&](T& y) -> void { y = A::op(x, y);\
    \ });\n    }\n    auto apply(int l, int r, const S& x) -> typename std::enable_if<\n\
    \        std::is_same<decltype(g(x, std::declval<U&>())), void>::value>::type\
    \ {\n        assert(0 <= l && l <= r && r <= this->n);\n        const int lb =\
    \ l / this->b, rb = r / this->b;\n        if (lb == rb) {\n            if (lb\
    \ < this->nb) eval(lb);\n            rep (i, l, r) this->v[i] = A::op(x, this->v[i]);\n\
    \            if (lb < this->nb) {\n                std::vector<T> v2(this->v.begin()\
    \ + lb * this->b,\n                                  this->v.begin() + (lb + 1)\
    \ * this->b);\n                this->data[lb] = this->f(std::move(v2));\n    \
    \        }\n            return;\n        }\n        eval(lb);\n        if (rb\
    \ < this->nb) eval(rb);\n        rep (i, l, this->b * (lb + 1)) this->v[i] = A::op(x,\
    \ this->v[i]);\n        rep (i, lb + 1, rb) all_apply(x, i);\n        rep (i,\
    \ rb * this->b, r) this->v[i] = A::op(x, this->v[i]);\n        {\n           \
    \ std::vector<T> v2(this->v.begin() + lb * this->b,\n                        \
    \      this->v.begin() + (lb + 1) * this->b);\n            this->data[lb] = this->f(std::move(v2));\n\
    \        }\n        if (rb < this->nb) {\n            std::vector<T> v2(this->v.begin()\
    \ + rb * this->b,\n                              this->v.begin() + (rb + 1) *\
    \ this->b);\n            this->data[rb] = this->f(std::move(v2));\n        }\n\
    \    }\n};\n\n/**\n * @brief SqrtDecomposition(\u5E73\u65B9\u5206\u5272)\n * @docs\
    \ docs/data-struct/segment/SqrtDecomposition.md\n */\n#line 6 \"test/yosupo/data_structure/range_affine_range_sum-sqrt.test.cpp\"\
    \nusing namespace std;\nusing mint = modint998244353;\nusing PMM = pair<mint,\
    \ mint>;\nstruct CompositeAction {\n    using M = Monoid::Sum<mint>;\n    using\
    \ E = Monoid::Composite<mint>;\n    static mint op(const PMM& a, const mint& b)\
    \ {\n        return a.first * b + a.second;\n    }\n};\nint main() {\n    int\
    \ N, Q; scan >> N >> Q;\n    vector<mint> A(N); scan >> A;\n    auto f = [&](vector<mint>&&\
    \ v) -> pair<mint, int> {\n        mint ans = 0;\n        each_const (i : v) ans\
    \ += i;\n        return {ans, v.size()};\n    };\n    auto g = [&](const PMM&\
    \ x, pair<mint, int>& p) -> void {\n        p.first = p.first * x.first + p.second\
    \ * x.second;\n    };\n    SqrtDecomposition<mint, decltype(f), decltype(g), CompositeAction>\
    \ seg(A, f, g);\n    rep (Q) {\n        int t; scan >> t;\n        if (t == 0)\
    \ {\n            int l, r, b, c; scan >> l >> r >> b >> c;\n            seg.apply(l,\
    \ r, PMM{b, c});\n        }\n        else {\n            int l, r; scan >> l >>\
    \ r;\n            auto g = [&](const mint& x) -> mint {\n                return\
    \ x;\n            };\n            auto h = [&](const pair<mint, int>& p) -> mint\
    \ {\n                return p.first;\n            };\n            print << seg.prod<Monoid::Sum<mint>>(l,\
    \ r, g, h) << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n#include \"../../../other/template.hpp\"\n#include \"../../../other/monoid2.hpp\"\
    \n#include \"../../../math/ModInt.hpp\"\n#include \"../../../data-struct/segment/SqrtDecomposition.hpp\"\
    \nusing namespace std;\nusing mint = modint998244353;\nusing PMM = pair<mint,\
    \ mint>;\nstruct CompositeAction {\n    using M = Monoid::Sum<mint>;\n    using\
    \ E = Monoid::Composite<mint>;\n    static mint op(const PMM& a, const mint& b)\
    \ {\n        return a.first * b + a.second;\n    }\n};\nint main() {\n    int\
    \ N, Q; scan >> N >> Q;\n    vector<mint> A(N); scan >> A;\n    auto f = [&](vector<mint>&&\
    \ v) -> pair<mint, int> {\n        mint ans = 0;\n        each_const (i : v) ans\
    \ += i;\n        return {ans, v.size()};\n    };\n    auto g = [&](const PMM&\
    \ x, pair<mint, int>& p) -> void {\n        p.first = p.first * x.first + p.second\
    \ * x.second;\n    };\n    SqrtDecomposition<mint, decltype(f), decltype(g), CompositeAction>\
    \ seg(A, f, g);\n    rep (Q) {\n        int t; scan >> t;\n        if (t == 0)\
    \ {\n            int l, r, b, c; scan >> l >> r >> b >> c;\n            seg.apply(l,\
    \ r, PMM{b, c});\n        }\n        else {\n            int l, r; scan >> l >>\
    \ r;\n            auto g = [&](const mint& x) -> mint {\n                return\
    \ x;\n            };\n            auto h = [&](const pair<mint, int>& p) -> mint\
    \ {\n                return p.first;\n            };\n            print << seg.prod<Monoid::Sum<mint>>(l,\
    \ r, g, h) << endl;\n        }\n    }\n}\n"
  dependsOn:
  - other/template.hpp
  - template/macros.hpp
  - template/alias.hpp
  - template/type_traits.hpp
  - template/in.hpp
  - template/out.hpp
  - template/bitop.hpp
  - other/monoid2.hpp
  - other/monoid.hpp
  - math/ModInt.hpp
  - data-struct/segment/SqrtDecomposition.hpp
  isVerificationFile: true
  path: test/yosupo/data_structure/range_affine_range_sum-sqrt.test.cpp
  requiredBy: []
  timestamp: '2022-09-11 12:55:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/data_structure/range_affine_range_sum-sqrt.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/data_structure/range_affine_range_sum-sqrt.test.cpp
- /verify/test/yosupo/data_structure/range_affine_range_sum-sqrt.test.cpp.html
title: test/yosupo/data_structure/range_affine_range_sum-sqrt.test.cpp
---