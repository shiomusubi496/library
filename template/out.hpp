#pragma once

#include <bits/stdc++.h>
#include <unistd.h>
#include "macros.hpp"
#include "alias.hpp"
#include "type_traits.hpp"

template<std::size_t buf_size = IO_BUFFER_SIZE> class Writer {
private:
    int fd, idx;
    std::array<char, buf_size> buffer;
    inline void write_buf() {
        int num = write(fd, buffer.begin(), idx);
        idx = 0;
        if (num < 0) throw std::runtime_error("output failed");
    }

public:
    Writer() noexcept : fd(1), idx(0) {}
    Writer(int fd) noexcept : fd(fd), idx(0) {}
    Writer(FILE* fp) noexcept : fd(fileno(fp)), idx(0) {}

    ~Writer() { write_buf(); }

    class iterator {
    private:
        Writer* writer;

    public:
        using difference_type = void;
        using value_type = void;
        using pointer = void;
        using reference = void;
        using iterator_category = std::output_iterator_tag;

        iterator() noexcept : writer(nullptr) {}
        explicit iterator(Writer& writer) noexcept : writer(&writer) {}
        explicit iterator(Writer* writer) noexcept : writer(writer) {}

        iterator& operator++() {
            ++writer->idx;
            if (writer->idx == buf_size) writer->write_buf();
            return *this;
        }
        iterator operator++(int) {
            iterator res = *this;
            ++(*this);
            return res;
        }
        char& operator*() const { return writer->buffer[writer->idx]; }
        void flush() const { writer->write_buf(); }
    };

    iterator begin() noexcept { return iterator(this); }
};

Writer<> writer(1), ewriter(2);

template<class Iterator, bool debug = false> class Printer {
public:
    using iterator_type = Iterator;

private:
    template<class, bool = debug, class = void>
    struct has_print : std::false_type {};
    template<class T>
    struct has_print<T, false,
                     decltype(std::declval<T>().print(std::declval<Printer&>()),
                              (void)0)> : std::true_type {};
    template<class T>
    struct has_print<T, true,
                     decltype(std::declval<T>().debug(std::declval<Printer&>()),
                              (void)0)> : std::true_type {};
    Iterator itr;
    std::size_t decimal_precision;

public:
    void print_char(char c) {
        *itr = c;
        ++itr;
    }

    void flush() { itr.flush(); }

    Printer() noexcept = default;
    explicit Printer(const Iterator& itr) noexcept
        : itr(itr), decimal_precision(16) {}

    void set_decimal_precision(std::size_t decimal_precision) {
        this->decimal_precision = decimal_precision;
    }

    void print(char c) {
        if IF_CONSTEXPR (debug) print_char('\'');
        print_char(c);
        if IF_CONSTEXPR (debug) print_char('\'');
    }
    void print(bool b) { print_char((char)(b + '0')); }
    void print(const char* a) {
        if IF_CONSTEXPR (debug) print_char('"');
        for (; *a != '\0'; ++a) print_char(*a);
        if IF_CONSTEXPR (debug) print_char('"');
    }
    template<std::size_t len> void print(const char (&a)[len]) {
        if IF_CONSTEXPR (debug) print_char('"');
        for (auto i : a) print_char(i);
        if IF_CONSTEXPR (debug) print_char('"');
    }
    void print(const std::string& a) {
        if IF_CONSTEXPR (debug) print_char('"');
        for (auto i : a) print_char(i);
        if IF_CONSTEXPR (debug) print_char('"');
    }
    template<std::size_t len> void print(const std::bitset<len>& a) {
        rrep (i, len) print_char((char)(a[i] + '0'));
    }
    template<class T,
             typename std::enable_if<is_int<T>::value &&
                                     !has_print<T>::value>::type* = nullptr>
    void print(T a) {
        if (!a) {
            print_char('0');
            return;
        }
        if IF_CONSTEXPR (is_signed_int<T>::value) {
            if (a < 0) {
                print_char('-');
                using U = typename make_unsigned_int<T>::type;
                print(static_cast<U>(-static_cast<U>(a)));
                return;
            }
        }
        std::string s;
        while (a) {
            s += (char)(a % 10 + '0');
            a /= 10;
        }
        for (auto i = s.rbegin(); i != s.rend(); ++i) print_char(*i);
    }
    template<class T,
             typename std::enable_if<std::is_floating_point<T>::value &&
                                     !has_print<T>::value>::type* = nullptr>
    void print(T a) {
        if (a == std::numeric_limits<T>::infinity()) {
            print("inf");
            return;
        }
        if (a == -std::numeric_limits<T>::infinity()) {
            print("-inf");
            return;
        }
        if (std::isnan(a)) {
            print("nan");
            return;
        }
        if (a < 0) {
            print_char('-');
            a = -a;
        }
        T b = a;
        if (b < 1) {
            print_char('0');
        }
        else {
            std::string s;
            while (b >= 1) {
                s += (char)('0' + (int)std::fmod(b, 10.0));
                b /= 10;
            }
            for (auto i = s.rbegin(); i != s.rend(); ++i) print_char(*i);
        }
        print_char('.');
        rep (decimal_precision) {
            a *= 10;
            print_char((char)('0' + (int)std::fmod(a, 10.0)));
        }
    }

private:
    template<std::size_t i, class... Args>
    void print(const std::tuple<Args...>& a) {
        if IF_CONSTEXPR (i < sizeof...(Args)) {
            if IF_CONSTEXPR (debug) print_char(',');
            print_char(' ');
            print(std::get<i>(a));
            print<i + 1, Args...>(a);
        }
    }

public:
    template<class... Args> void print(const std::tuple<Args...>& a) {
        if IF_CONSTEXPR (debug) print_char('(');
        if IF_CONSTEXPR (sizeof...(Args) != 0) print(std::get<0>(a));
        print<1, Args...>(a);
        if IF_CONSTEXPR (debug) print_char(')');
    }
    template<class T, class U> void print(const std::pair<T, U>& a) {
        if IF_CONSTEXPR (debug) print_char('(');
        print(a.first);
        if IF_CONSTEXPR (debug) print_char(',');
        print_char(' ');
        print(a.second);
        if IF_CONSTEXPR (debug) print_char(')');
    }
    template<class T,
             typename std::enable_if<is_range<T>::value &&
                                     !has_print<T>::value>::type* = nullptr>
    void print(const T& a) {
        if IF_CONSTEXPR (debug) print_char('{');
        for (auto i = std::begin(a); i != std::end(a); ++i) {
            if (i != std::begin(a)) {
                if IF_CONSTEXPR (debug) print_char(',');
                print_char(' ');
            }
            print(*i);
        }
        if IF_CONSTEXPR (debug) print_char('}');
    }
    template<class T, typename std::enable_if<has_print<T>::value &&
                                              !debug>::type* = nullptr>
    void print(const T& a) {
        a.print(*this);
    }
    template<class T, typename std::enable_if<has_print<T>::value &&
                                              debug>::type* = nullptr>
    void print(const T& a) {
        a.debug(*this);
    }

    void operator()() {}
    template<class Head, class... Args>
    void operator()(const Head& head, const Args&... args) {
        print(head);
        operator()(args...);
    }

    template<class T> Printer& operator<<(const T& a) {
        print(a);
        return *this;
    }

    Printer& operator<<(Printer& (*pf)(Printer&)) { return pf(*this); }
};

template<class Iterator, bool debug>
Printer<Iterator, debug>& endl(Printer<Iterator, debug>& pr) {
    pr.print_char('\n');
    pr.flush();
    return pr;
}
template<class Iterator, bool debug>
Printer<Iterator, debug>& flush(Printer<Iterator, debug>& pr) {
    pr.flush();
    return pr;
}

struct SetPrec {
    int n;
    template<class Pr> void print(Pr& pr) const { pr.set_decimal_precision(n); }
    template<class Pr> void debug(Pr& pr) const { pr.set_decimal_precision(n); }
};
SetPrec setprec(int n) { return SetPrec{n}; };

Printer<Writer<>::iterator> print(writer.begin()), eprint(ewriter.begin());

void prints() { print.print_char('\n'); }

template<class T> auto prints(const T& v) -> decltype(print << v, (void)0) {
    print << v;
    print.print_char('\n');
}

template<class Head, class... Tail>
auto prints(const Head& head, const Tail&... tail)
    -> decltype(print << head, (void)0) {
    print << head;
    print.print_char(' ');
    prints(tail...);
}

#ifdef SHIO_LOCAL
Printer<Writer<>::iterator, true> debug(writer.begin()),
    edebug(ewriter.begin());
#else
char debug_iterator_character;
class DebugIterator {
public:
    DebugIterator() noexcept = default;
    DebugIterator& operator++() { return *this; }
    DebugIterator& operator++(int) { return *this; }
    char& operator*() const { return debug_iterator_character; }
    void flush() const {}
};
Printer<DebugIterator> debug, edebug;
#endif

void debugs() { debug.print_char('\n'); }

template<class T> auto debugs(const T& v) -> decltype(debug << v, (void)0) {
    debug << v;
    debug.print_char('\n');
}

template<class Head, class... Tail>
auto debugs(const Head& head, const Tail&... tail)
    -> decltype(debug << head, (void)0) {
    debug << head;
    debug.print_char(' ');
    debugs(tail...);
}
