#pragma once

#include "macros.hpp"
#include "type_traits.hpp"
#include <bits/stdc++.h>
#include <unistd.h>

template<std::size_t buf_size = IO_BUFFER_SIZE> class Writer {
private:
    int fd, idx;
    std::array<char, buf_size> buffer;
    inline void write_buf() {
        int num = write(fd, buffer.begin(), idx);
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
            if (writer->idx == buf_size) {
                writer->write_buf();
                writer->idx = 0;
            }
            return *this;
        }
        iterator operator++(int) {
            iterator res = *this;
            ++(*this);
            return res;
        }
        char& operator*() const { return writer->buffer[writer->idx]; }
        void flush() const {
            writer->write_buf();
            writer->idx = 0;
        }
    };

    iterator begin() noexcept { return iterator(this); }
};

Writer<> writer(1), ewriter(2);

template<class Iterator, std::size_t decimal_precision = 16, bool debug = false>
class Printer {
public:
    using iterator_type = Iterator;

private:
    template<class, class = void> struct has_print : std::false_type {};
    template<class T>
    struct has_print<
        T, decltype(std::declval<T>().print(std::declval<Printer&>()), (void)0)>
        : std::true_type {};
    Iterator itr;

public:
    void print_char(char c) {
        *itr = c;
        ++itr;
    }

    void flush() { itr.flush(); }

    Printer() noexcept = default;
    Printer(const Iterator& itr) noexcept : itr(itr) {}

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
             typename std::enable_if<std::is_integral<T>::value &&
                                     !has_print<T>::value>::type* = nullptr>
    void print(T a) {
        if (!a) {
            print_char('0');
            return;
        }
        if IF_CONSTEXPR (std::is_signed<T>::value) {
            if (a < 0) {
                print_char('-');
                a = -a;
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
            print_char((char)('0' + (int)std::fmod(b, 10.0)));
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
        for (auto i = a.begin(); i != a.end(); ++i) {
            if (i != a.begin()) {
                if IF_CONSTEXPR (debug) print_char(',');
                print_char(' ');
            }
            print(*i);
        }
        if IF_CONSTEXPR (debug) print_char('}');
    }
    template<class T,
             typename std::enable_if<has_print<T>::value>::type* = nullptr>
    void print(const T& a) {
        a.print(*this);
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

template<class Iterator, std::size_t decimal_precision, bool debug>
Printer<Iterator, decimal_precision, debug>&
endl(Printer<Iterator, decimal_precision, debug>& pr) {
    pr.print_char('\n');
    pr.flush();
    return pr;
}
template<class Iterator, std::size_t decimal_precision, bool debug>
Printer<Iterator, decimal_precision, debug>&
flush(Printer<Iterator, decimal_precision, debug>& pr) {
    pr.flush();
    return pr;
}

Printer<Writer<>::iterator> print(writer.begin()), eprint(writer.begin());

#ifdef SHIO_LOCAL
Printer<Writer<>::iterator, 16, true> debug(writer.begin()),
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
