---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/Line.hpp
    title: geometry/Line.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/Point.hpp
    title: geometry/Point.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/template.hpp
    title: geometry/template.hpp
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
  _extendedRequiredBy:
  - icon: ':warning:'
    path: geometry/All.hpp
    title: geometry/All.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL/CGL_7_A-intersect.test.cpp
    title: test/aoj/CGL/CGL_7_A-intersect.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL/CGL_7_D-intersection.test.cpp
    title: test/aoj/CGL/CGL_7_D-intersection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL/CGL_7_E-intersection.test.cpp
    title: test/aoj/CGL/CGL_7_E-intersection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL/CGL_7_F-tangent.test.cpp
    title: test/aoj/CGL/CGL_7_F-tangent.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL/CGL_7_G-common-tangent.test.cpp
    title: test/aoj/CGL/CGL_7_G-common-tangent.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/Circle.hpp\"\n\n#line 2 \"geometry/template.hpp\"\
    \n\n#line 2 \"other/template.hpp\"\n\n#include <bits/stdc++.h>\n#line 2 \"template/macros.hpp\"\
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
    \ {\n    return a < b ? a = b, true : false;\n}\ntemplate<class T, class U, class\
    \ Comp>\ninline constexpr bool chmin(T& a, const U& b, Comp cmp) noexcept {\n\
    \    return cmp(b, a) ? a = b, true : false;\n}\ntemplate<class T, class U, class\
    \ Comp>\ninline constexpr bool chmax(T& a, const U& b, Comp cmp) noexcept {\n\
    \    return cmp(a, b) ? a = b, true : false;\n}\n\ninline CONSTEXPR ll gcd(ll\
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
    \ data() && { return std::move(dat); }\n};\n#line 4 \"geometry/template.hpp\"\n\
    \n#ifdef GEOMETRY_EPS\nconstexpr ld geom_eps = GEOMETRY_EPS;\n#else\nconstexpr\
    \ ld geom_eps = EPS;\n#endif\n\n#ifdef GEOMETRY_REAL_TYPE\nusing Real = GEOMETRY_REAL_TYPE;\n\
    // a <=> b  :  cmp(a, b) <=> 0\ninline int cmp(Real a, Real b) {\n    if (a >\
    \ b) return 1;\n    if (a < b) return -1;\n    return 0;\n}\n#else\nusing Real\
    \ = ld;\n// a <=> b  :  cmp(a, b) <=> 0\ninline int cmp(ld a, ld b) {\n    if\
    \ (a > b + geom_eps) return 1;\n    if (a < b - geom_eps) return -1;\n    return\
    \ 0;\n}\n#endif\n#line 2 \"geometry/Point.hpp\"\n\n#line 4 \"geometry/Point.hpp\"\
    \n\nclass Point {\npublic:\n    Real x, y;\n    Point() : x(0), y(0) {}\n    Point(Real\
    \ x, Real y) : x(x), y(y) {}\n    Point& operator+=(const Point& p) {\n      \
    \  x += p.x;\n        y += p.y;\n        return *this;\n    }\n    Point& operator-=(const\
    \ Point& p) {\n        x -= p.x;\n        y -= p.y;\n        return *this;\n \
    \   }\n    Point& operator*=(Real a) {\n        x *= a;\n        y *= a;\n   \
    \     return *this;\n    }\n    Point& operator/=(Real a) {\n        x /= a;\n\
    \        y /= a;\n        return *this;\n    }\n    Point operator+() const {\
    \ return *this; }\n    Point operator-() const { return Point(-x, -y); }\n   \
    \ friend Point operator+(const Point& p1, const Point& p2) {\n        return Point(p1)\
    \ += p2;\n    }\n    friend Point operator-(const Point& p1, const Point& p2)\
    \ {\n        return Point(p1) -= p2;\n    }\n    friend Point operator*(const\
    \ Point& p, Real a) { return Point(p) *= a; }\n    friend Point operator*(Real\
    \ a, const Point& p) { return Point(p) *= a; }\n    friend Point operator/(const\
    \ Point& p, Real a) { return Point(p) /= a; }\n    friend bool operator==(const\
    \ Point& p1, const Point& p2) {\n        return cmp(p1.x, p2.x) == 0 && cmp(p1.y,\
    \ p2.y) == 0;\n    }\n    friend bool operator!=(const Point& p1, const Point&\
    \ p2) {\n        return !(p1 == p2);\n    }\n    friend bool operator<(const Point&\
    \ p1, const Point& p2) {\n        return cmp(p1.x, p2.x) < 0 ||\n            \
    \   (cmp(p1.x, p2.x) == 0 && cmp(p1.y, p2.y) < 0);\n    }\n    friend bool operator>(const\
    \ Point& p1, const Point& p2) { return p2 < p1; }\n    friend bool operator<=(const\
    \ Point& p1, const Point& p2) {\n        return !(p2 < p1);\n    }\n    friend\
    \ bool operator>=(const Point& p1, const Point& p2) {\n        return !(p1 < p2);\n\
    \    }\n    Real norm() const { return x * x + y * y; }\n    friend Real norm(const\
    \ Point& p) { return p.norm(); }\n    Real abs() const { return sqrt(norm());\
    \ }\n    friend Real abs(const Point& p) { return p.abs(); }\n    Real arg() const\
    \ { return atan2(y, x); }\n    friend Real arg(const Point& p) { return p.arg();\
    \ }\n    Point& rotate(Real theta) {\n        Real c = cos(theta), s = sin(theta);\n\
    \        Real nx = x * c - y * s, ny = x * s + y * c;\n        x = nx;\n     \
    \   y = ny;\n        return *this;\n    }\n    friend Point rotate(const Point&\
    \ p, Real theta) {\n        return Point(p).rotate(theta);\n    }\n    Point&\
    \ rotate90() {\n        Real nx = -y, ny = x;\n        x = nx;\n        y = ny;\n\
    \        return *this;\n    }\n    friend Point rotate90(const Point& p) { return\
    \ Point(p).rotate90(); }\n    // inner product(\u5185\u7A4D), p1 * p2 = |p1| *\
    \ |p2| * cos(theta)\n    friend Real dot(const Point& p1, const Point& p2) {\n\
    \        return p1.x * p2.x + p1.y * p2.y;\n    }\n    // outer product(\u5916\
    \u7A4D), p1 ^ p2 = |p1| * |p2| * sin(theta)\n    friend Real cross(const Point&\
    \ p1, const Point& p2) {\n        return p1.x * p2.y - p1.y * p2.x;\n    }\n \
    \   template<class Sc> void scan(Sc& scan) { scan >> x >> y; }\n    template<class\
    \ Pr> void print(Pr& print) const { print << x << ' ' << y; }\n    template<class\
    \ Pr> void debug(Pr& print) const {\n        print.print_char('(');\n        print\
    \ << x;\n        print.print_char(',');\n        print << y;\n        print.print_char(')');\n\
    \    }\n};\n\nReal distance(const Point& p1, const Point& p2) { return abs(p1\
    \ - p2); }\n\nenum class CCW {\n    COUNTER_CLOCKWISE = 1,\n    CLOCKWISE = -1,\n\
    \    ONLINE_BACK = 2,\n    ONLINE_FRONT = -2,\n    ON_SEGMENT = 0,\n};\n\nCCW\
    \ ccw(const Point& p0, const Point& p1, const Point& p2) {\n    Point a = p1 -\
    \ p0, b = p2 - p0;\n    if (cmp(cross(a, b), 0) > 0) return CCW::COUNTER_CLOCKWISE;\n\
    \    if (cmp(cross(a, b), 0) < 0) return CCW::CLOCKWISE;\n    if (cmp(dot(a, b),\
    \ 0) < 0) return CCW::ONLINE_BACK;\n    if (a.norm() < b.norm()) return CCW::ONLINE_FRONT;\n\
    \    return CCW::ON_SEGMENT;\n}\n#line 2 \"geometry/Line.hpp\"\n\n#line 5 \"geometry/Line.hpp\"\
    \n\nclass Line {\npublic:\n    Real a, b, c; // ax + by + c = 0\n    Line() :\
    \ a(0), b(1), c(0) {}\n    Line(Real a, Real b, Real c) : a(a), b(b), c(c) {}\n\
    \    Line(const Point& p1, const Point& p2) {\n        a = p2.y - p1.y;\n    \
    \    b = p1.x - p2.x;\n        c = p2.x * p1.y - p1.x * p2.y;\n    }\n    friend\
    \ bool operator==(const Line& l1, const Line& l2) {\n        return cmp(l1.a *\
    \ l2.b, l2.a * l1.b) == 0 &&\n               cmp(l1.b * l2.c, l2.b * l1.c) ==\
    \ 0;\n    }\n    friend bool operator!=(const Line& l1, const Line& l2) {\n  \
    \      return !(l1 == l2);\n    }\n    friend bool operator<(const Line& l1, const\
    \ Line& l2) {\n        return cmp(l1.a * l2.b, l2.a * l1.b) < 0 ||\n         \
    \      (cmp(l1.a * l2.b, l2.a * l1.b) == 0 &&\n                cmp(l1.b * l2.c,\
    \ l2.b * l1.c) < 0);\n    }\n    friend bool operator>(const Line& l1, const Line&\
    \ l2) { return l2 < l1; }\n    friend bool operator<=(const Line& l1, const Line&\
    \ l2) {\n        return !(l2 < l1);\n    }\n    friend bool operator>=(const Line&\
    \ l1, const Line& l2) {\n        return !(l1 < l2);\n    }\n    bool is_on(const\
    \ Point& p) const {\n        return cmp(a * p.x + b * p.y + c, 0) == 0;\n    }\n\
    \    template<class Pr> void debug(Pr& print) const {\n        print << a;\n \
    \       print.print_char('x');\n        print.print_char('+');\n        print\
    \ << b;\n        print.print_char('y');\n        print.print_char('+');\n    \
    \    print << c;\n        print.print_char('=');\n        print.print_char('0');\n\
    \    }\n};\n\nReal distance(const Point& p, const Line& l) {\n    return std::abs(l.a\
    \ * p.x + l.b * p.y + l.c) /\n           std::sqrt(l.a * l.a + l.b * l.b);\n}\n\
    Real distance(const Line& l, const Point& p) { return distance(p, l); }\n\n//\
    \ \u5782\u76F4\u4E8C\u7B49\u5206\u7DDA\nLine perpendicular_bisector(const Point&\
    \ p1, const Point& p2) {\n    return Line((p1 + p2) / 2, (p1 + p2) / 2 + (p2 -\
    \ p1).rotate90());\n}\n\n// \u5E73\u884C\u5224\u5B9A\nbool is_parallel(const Line&\
    \ l1, const Line& l2) {\n    return cmp(l1.a * l2.b, l2.a * l1.b) == 0;\n}\n//\
    \ \u76F4\u4EA4\u5224\u5B9A\nbool is_orthogonal(const Line& l1, const Line& l2)\
    \ {\n    return cmp(l1.a * l2.a + l1.b * l2.b, 0) == 0;\n}\n// \u5E73\u884C\u7DDA\
    \nLine parallel(const Line& l, const Point& p) {\n    return Line(l.a, l.b, -l.a\
    \ * p.x - l.b * p.y);\n}\n// \u5782\u76F4\u7DDA\nLine perpendicular(const Line&\
    \ l, const Point& p) {\n    return Line(l.b, -l.a, -l.b * p.x + l.a * p.y);\n\
    }\n\n// \u4EA4\u53C9\u5224\u5B9A\nbool is_intersect(const Line& l1, const Line&\
    \ l2) {\n    return l1 == l2 || !is_parallel(l1, l2);\n}\n// \u4EA4\u70B9\nPoint\
    \ intersection(const Line& l1, const Line& l2) {\n    assert(!is_parallel(l1,\
    \ l2));\n    Real d = l1.a * l2.b - l2.a * l1.b;\n    return Point((l1.b * l2.c\
    \ - l2.b * l1.c) / d,\n                 (l1.c * l2.a - l2.c * l1.a) / d);\n}\n\
    // \u5C04\u5F71\nPoint projection(const Line& l, const Point& p) {\n    return\
    \ intersection(l, perpendicular(l, p));\n}\n// \u53CD\u5C04\nPoint reflection(const\
    \ Line& l, const Point& p) {\n    return projection(l, p) * 2 - p;\n}\n#line 6\
    \ \"geometry/Circle.hpp\"\n\nclass Circle {\npublic:\n    Point c;\n    Real r;\n\
    \    Circle() : c(Point()), r(0) {}\n    Circle(Point c, Real r) : c(c), r(r)\
    \ {}\n    friend bool operator==(const Circle& c1, const Circle& c2) {\n     \
    \   return c1.c == c2.c && cmp(c1.r, c2.r) == 0;\n    }\n    friend bool operator!=(const\
    \ Circle& c1, const Circle& c2) {\n        return !(c1 == c2);\n    }\n    friend\
    \ bool operator<(const Circle& c1, const Circle& c2) {\n        return c1.c <\
    \ c2.c || (c1.c == c2.c && cmp(c1.r, c2.r) < 0);\n    }\n    friend bool operator>(const\
    \ Circle& c1, const Circle& c2) {\n        return c2 < c1;\n    }\n    friend\
    \ bool operator<=(const Circle& c1, const Circle& c2) {\n        return !(c2 <\
    \ c1);\n    }\n    friend bool operator>=(const Circle& c1, const Circle& c2)\
    \ {\n        return !(c1 < c2);\n    }\n    template<class Sc> void scan(Sc& scan)\
    \ { scan >> c >> r; }\n    template<class Pr> void print(Pr& print) { print <<\
    \ c << ' ' << r; }\n    template<class Pr> void debug(Pr& print) {\n        print.print_char('{');\n\
    \        print << c;\n        print.print_char(':');\n        print << r;\n  \
    \      print.print_char('}');\n    }\n};\n\nenum class circle_relation {\n   \
    \ IN = 0,           // \u5185\u5305\n    INSCRIBE = 1,     // \u5185\u63A5\n \
    \   INTERSECT = 2,    // \u4EA4\u308F\u308B\n    CIRCUMSCRIBE = 3, // \u5916\u63A5\
    \n    SEPARATE = 4,     // \u96E2\u308C\u3066\u3044\u308B\n    SAME = 5,     \
    \    // \u7B49\u3057\u3044\n};\n\ncircle_relation relation(const Circle& c1, const\
    \ Circle& c2) {\n    if (c1 == c2) return circle_relation::SAME;\n    const Real\
    \ d = norm(c1.c - c2.c);\n    const Real r1 = c1.r + c2.r, r2 = c1.r - c2.r;\n\
    \    if (cmp(d, r1 * r1) > 0) return circle_relation::SEPARATE;\n    if (cmp(d,\
    \ r1 * r1) == 0) return circle_relation::CIRCUMSCRIBE;\n    if (cmp(d, r2 * r2)\
    \ > 0) return circle_relation::INTERSECT;\n    if (cmp(d, r2 * r2) == 0) return\
    \ circle_relation::INSCRIBE;\n    return circle_relation::IN;\n}\n\nstd::vector<Point>\
    \ intersections(const Circle& c, const Line& l) {\n    const Point h = projection(l,\
    \ c.c);\n    const Real d = norm(h - c.c);\n    if (cmp(d, c.r * c.r) > 0) return\
    \ {};\n    if (cmp(d, c.r * c.r) == 0) return {h};\n    const Point v =\n    \
    \    Point(l.b, -l.a) *\n        std::sqrt(std::max<Real>((c.r * c.r - d) / (l.a\
    \ * l.a + l.b * l.b), 0));\n    return {h - v, h + v};\n}\n\nLine radical_axis(const\
    \ Circle& c1, const Circle& c2) {\n    const Real a = c1.c.x, b = c1.c.y, r =\
    \ c1.r;\n    const Real c = c2.c.x, d = c2.c.y, s = c2.r;\n    const Real p =\
    \ -2 * a + 2 * c, q = -2 * b + 2 * d;\n    const Real r2 = a * a + b * b - c *\
    \ c - d * d - r * r + s * s;\n    return Line(p, q, r2);\n}\n\nstd::vector<Point>\
    \ intersections(const Circle& c1, const Circle& c2) {\n    const Line l = radical_axis(c1,\
    \ c2);\n    return intersections(c1, l);\n}\n\nLine tangent_at_point(const Circle&\
    \ c, const Point& p) {\n    assert(cmp(norm(c.c - p), c.r * c.r) == 0);\n    const\
    \ Real a = c.c.x, b = c.c.y;\n    const Real px = p.x, py = p.y;\n    return Line(px\
    \ - a, py - b, (a - px) * a + (b - py) * b - c.r * c.r);\n}\n\nstd::vector<Point>\
    \ tangent_points(const Circle& c, const Point& p) {\n    const Real d = norm(c.c\
    \ - p);\n    const Real r2 = c.r * c.r;\n    if (cmp(d, r2) < 0) return {};\n\
    \    if (cmp(d, r2) == 0) return {p};\n    const Circle c2(p, std::sqrt(std::max<Real>(d\
    \ - r2, 0)));\n    return intersections(c, c2);\n}\n\nstd::vector<Point> common_tangents(const\
    \ Circle& c1, const Circle& c2) {\n    assert(c1 != c2);\n    const Real d = norm(c1.c\
    \ - c2.c);\n    const Real r1 = c1.r, r2 = c2.r;\n    std::vector<Point> res;\n\
    \    if (cmp(d, (r1 - r2) * (r1 - r2)) == 0) {\n        const Point v = (c2.c\
    \ - c1.c) * (r1 / std::sqrt(d));\n        res.push_back(c1.c + (cmp(r1, r2) <\
    \ 0 ? -v : v));\n    }\n    else if (cmp(d, (r1 - r2) * (r1 - r2)) > 0) {\n  \
    \      if (cmp(r1, r2) == 0) {\n            const Point v = (c2.c - c1.c).rotate90()\
    \ * (r1 / std::sqrt(d));\n            res.push_back(c1.c + v);\n            res.push_back(c1.c\
    \ - v);\n        }\n        else {\n            const Point v = (c1.c * r2 - c2.c\
    \ * r1) / (-r1 + r2);\n            auto ps = tangent_points(c1, v);\n        \
    \    std::copy(all(ps), std::back_inserter(res));\n        }\n        if (cmp(d,\
    \ (r1 + r2) * (r1 + r2)) == 0) {\n            const Point v = (c2.c - c1.c) *\
    \ (r1 / std::sqrt(d));\n            res.push_back(c1.c + v);\n        }\n    \
    \    else if (cmp(d, (r1 + r2) * (r1 + r2)) > 0) {\n            const Point v\
    \ = (c1.c * r2 + c2.c * r1) / (r1 + r2);\n            auto ps = tangent_points(c1,\
    \ v);\n            std::copy(all(ps), std::back_inserter(res));\n        }\n \
    \   }\n    return res;\n}\n"
  code: "#pragma once\n\n#include \"template.hpp\"\n#include \"Point.hpp\"\n#include\
    \ \"Line.hpp\"\n\nclass Circle {\npublic:\n    Point c;\n    Real r;\n    Circle()\
    \ : c(Point()), r(0) {}\n    Circle(Point c, Real r) : c(c), r(r) {}\n    friend\
    \ bool operator==(const Circle& c1, const Circle& c2) {\n        return c1.c ==\
    \ c2.c && cmp(c1.r, c2.r) == 0;\n    }\n    friend bool operator!=(const Circle&\
    \ c1, const Circle& c2) {\n        return !(c1 == c2);\n    }\n    friend bool\
    \ operator<(const Circle& c1, const Circle& c2) {\n        return c1.c < c2.c\
    \ || (c1.c == c2.c && cmp(c1.r, c2.r) < 0);\n    }\n    friend bool operator>(const\
    \ Circle& c1, const Circle& c2) {\n        return c2 < c1;\n    }\n    friend\
    \ bool operator<=(const Circle& c1, const Circle& c2) {\n        return !(c2 <\
    \ c1);\n    }\n    friend bool operator>=(const Circle& c1, const Circle& c2)\
    \ {\n        return !(c1 < c2);\n    }\n    template<class Sc> void scan(Sc& scan)\
    \ { scan >> c >> r; }\n    template<class Pr> void print(Pr& print) { print <<\
    \ c << ' ' << r; }\n    template<class Pr> void debug(Pr& print) {\n        print.print_char('{');\n\
    \        print << c;\n        print.print_char(':');\n        print << r;\n  \
    \      print.print_char('}');\n    }\n};\n\nenum class circle_relation {\n   \
    \ IN = 0,           // \u5185\u5305\n    INSCRIBE = 1,     // \u5185\u63A5\n \
    \   INTERSECT = 2,    // \u4EA4\u308F\u308B\n    CIRCUMSCRIBE = 3, // \u5916\u63A5\
    \n    SEPARATE = 4,     // \u96E2\u308C\u3066\u3044\u308B\n    SAME = 5,     \
    \    // \u7B49\u3057\u3044\n};\n\ncircle_relation relation(const Circle& c1, const\
    \ Circle& c2) {\n    if (c1 == c2) return circle_relation::SAME;\n    const Real\
    \ d = norm(c1.c - c2.c);\n    const Real r1 = c1.r + c2.r, r2 = c1.r - c2.r;\n\
    \    if (cmp(d, r1 * r1) > 0) return circle_relation::SEPARATE;\n    if (cmp(d,\
    \ r1 * r1) == 0) return circle_relation::CIRCUMSCRIBE;\n    if (cmp(d, r2 * r2)\
    \ > 0) return circle_relation::INTERSECT;\n    if (cmp(d, r2 * r2) == 0) return\
    \ circle_relation::INSCRIBE;\n    return circle_relation::IN;\n}\n\nstd::vector<Point>\
    \ intersections(const Circle& c, const Line& l) {\n    const Point h = projection(l,\
    \ c.c);\n    const Real d = norm(h - c.c);\n    if (cmp(d, c.r * c.r) > 0) return\
    \ {};\n    if (cmp(d, c.r * c.r) == 0) return {h};\n    const Point v =\n    \
    \    Point(l.b, -l.a) *\n        std::sqrt(std::max<Real>((c.r * c.r - d) / (l.a\
    \ * l.a + l.b * l.b), 0));\n    return {h - v, h + v};\n}\n\nLine radical_axis(const\
    \ Circle& c1, const Circle& c2) {\n    const Real a = c1.c.x, b = c1.c.y, r =\
    \ c1.r;\n    const Real c = c2.c.x, d = c2.c.y, s = c2.r;\n    const Real p =\
    \ -2 * a + 2 * c, q = -2 * b + 2 * d;\n    const Real r2 = a * a + b * b - c *\
    \ c - d * d - r * r + s * s;\n    return Line(p, q, r2);\n}\n\nstd::vector<Point>\
    \ intersections(const Circle& c1, const Circle& c2) {\n    const Line l = radical_axis(c1,\
    \ c2);\n    return intersections(c1, l);\n}\n\nLine tangent_at_point(const Circle&\
    \ c, const Point& p) {\n    assert(cmp(norm(c.c - p), c.r * c.r) == 0);\n    const\
    \ Real a = c.c.x, b = c.c.y;\n    const Real px = p.x, py = p.y;\n    return Line(px\
    \ - a, py - b, (a - px) * a + (b - py) * b - c.r * c.r);\n}\n\nstd::vector<Point>\
    \ tangent_points(const Circle& c, const Point& p) {\n    const Real d = norm(c.c\
    \ - p);\n    const Real r2 = c.r * c.r;\n    if (cmp(d, r2) < 0) return {};\n\
    \    if (cmp(d, r2) == 0) return {p};\n    const Circle c2(p, std::sqrt(std::max<Real>(d\
    \ - r2, 0)));\n    return intersections(c, c2);\n}\n\nstd::vector<Point> common_tangents(const\
    \ Circle& c1, const Circle& c2) {\n    assert(c1 != c2);\n    const Real d = norm(c1.c\
    \ - c2.c);\n    const Real r1 = c1.r, r2 = c2.r;\n    std::vector<Point> res;\n\
    \    if (cmp(d, (r1 - r2) * (r1 - r2)) == 0) {\n        const Point v = (c2.c\
    \ - c1.c) * (r1 / std::sqrt(d));\n        res.push_back(c1.c + (cmp(r1, r2) <\
    \ 0 ? -v : v));\n    }\n    else if (cmp(d, (r1 - r2) * (r1 - r2)) > 0) {\n  \
    \      if (cmp(r1, r2) == 0) {\n            const Point v = (c2.c - c1.c).rotate90()\
    \ * (r1 / std::sqrt(d));\n            res.push_back(c1.c + v);\n            res.push_back(c1.c\
    \ - v);\n        }\n        else {\n            const Point v = (c1.c * r2 - c2.c\
    \ * r1) / (-r1 + r2);\n            auto ps = tangent_points(c1, v);\n        \
    \    std::copy(all(ps), std::back_inserter(res));\n        }\n        if (cmp(d,\
    \ (r1 + r2) * (r1 + r2)) == 0) {\n            const Point v = (c2.c - c1.c) *\
    \ (r1 / std::sqrt(d));\n            res.push_back(c1.c + v);\n        }\n    \
    \    else if (cmp(d, (r1 + r2) * (r1 + r2)) > 0) {\n            const Point v\
    \ = (c1.c * r2 + c2.c * r1) / (r1 + r2);\n            auto ps = tangent_points(c1,\
    \ v);\n            std::copy(all(ps), std::back_inserter(res));\n        }\n \
    \   }\n    return res;\n}\n"
  dependsOn:
  - geometry/template.hpp
  - other/template.hpp
  - template/macros.hpp
  - template/alias.hpp
  - template/type_traits.hpp
  - template/in.hpp
  - template/out.hpp
  - template/bitop.hpp
  - geometry/Point.hpp
  - geometry/Line.hpp
  isVerificationFile: false
  path: geometry/Circle.hpp
  requiredBy:
  - geometry/All.hpp
  timestamp: '2022-09-23 16:45:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/CGL/CGL_7_G-common-tangent.test.cpp
  - test/aoj/CGL/CGL_7_F-tangent.test.cpp
  - test/aoj/CGL/CGL_7_A-intersect.test.cpp
  - test/aoj/CGL/CGL_7_E-intersection.test.cpp
  - test/aoj/CGL/CGL_7_D-intersection.test.cpp
documentation_of: geometry/Circle.hpp
layout: document
redirect_from:
- /library/geometry/Circle.hpp
- /library/geometry/Circle.hpp.html
title: geometry/Circle.hpp
---