#pragma once

#include <bits/stdc++.h>
#include <unistd.h>
#include "macros.hpp"
#include "alias.hpp"
#include "type_traits.hpp"

template<std::size_t buf_size = IO_BUFFER_SIZE> class Reader {
private:
    int fd, idx, sz;
    bool state;
    std::array<char, buf_size> buffer;
    inline void read_buf() {
        sz = read(fd, buffer.begin(), buf_size);
        idx = 0;
        if (sz < 0) throw std::runtime_error("input failed");
    }

public:
    static constexpr int get_buf_size() { return buf_size; }
    Reader() noexcept : fd(0), idx(0), sz(0), state(true) {}
    Reader(int fd) noexcept : fd(fd), idx(0), sz(0), state(true) {}
    Reader(FILE* fp) noexcept : fd(fileno(fp)), idx(0), sz(0), state(true) {}

    class iterator {
    private:
        Reader* reader;

    public:
        using difference_type = void;
        using value_type = void;
        using pointer = void;
        using reference = void;
        using iterator_category = std::input_iterator_tag;

        iterator() : reader(nullptr) {}
        explicit iterator(Reader& reader) : reader(&reader) {}
        explicit iterator(Reader* reader) : reader(reader) {}

        iterator& operator++() {
            if (reader->idx == reader->sz) reader->read_buf();
            ++reader->idx;
            return *this;
        }
        iterator operator++(int) {
            iterator res = *this;
            ++(*this);
            return res;
        }
        char operator*() const {
            if (reader->idx == reader->sz) reader->read_buf();
            if (reader->idx < reader->sz) return reader->buffer[reader->idx];
            reader->state = false;
            return '\0';
        }
        bool rdstate() const { return reader->state; }
    };

    iterator begin() noexcept { return iterator(this); }
};

Reader<> reader(0);

template<class Iterator, std::size_t decimal_precision = 16> class Scanner {
public:
    using iterator_type = Iterator;

private:
    template<class, class = void> struct has_scan : std::false_type {};
    template<class T>
    struct has_scan<
        T, decltype(std::declval<T>().scan(std::declval<Scanner&>()), (void)0)>
        : std::true_type {};
    Iterator itr;

public:
    Scanner() = default;
    Scanner(const Iterator& itr) : itr(itr) {}

    char scan_char() {
        char c = *itr;
        ++itr;
        return c;
    }

    Scanner ignore(int n = 1) {
        rep (n) ++itr;
        return *this;
    }

    inline void discard_space() {
        while (('\t' <= *itr && *itr <= '\r') || *itr == ' ') ++itr;
    }
    void scan(char& a) {
        discard_space();
        a = *itr;
        ++itr;
    }
    void scan(bool& a) {
        discard_space();
        a = *itr != '0';
        ++itr;
    }
    void scan(std::string& a) {
        discard_space();
        a.clear();
        while ((*itr < '\t' || '\r' < *itr) && *itr != ' ' && *itr != '\0') {
            a += *itr;
            ++itr;
        }
    }
    template<std::size_t len> void scan(std::bitset<len>& a) {
        discard_space();
        rrep (i, len) {
            a[i] = *itr != '0';
            ++itr;
        }
    }
    template<class T,
             typename std::enable_if<is_signed_int<T>::value &&
                                     !has_scan<T>::value>::type* = nullptr>
    void scan(T& a) {
        discard_space();
        if (*itr == '-') {
            ++itr;
            a = 0;
            while ('0' <= *itr && *itr <= '9') {
                a = a * 10 - (*itr - '0');
                ++itr;
            }
        }
        else {
            a = 0;
            while ('0' <= *itr && *itr <= '9') {
                a = a * 10 + (*itr - '0');
                ++itr;
            }
        }
    }
    template<class T,
             typename std::enable_if<is_unsigned_int<T>::value &&
                                     !has_scan<T>::value>::type* = nullptr>
    void scan(T& a) {
        discard_space();
        a = 0;
        while ('0' <= *itr && *itr <= '9') {
            a = a * 10 + *itr - '0';
            ++itr;
        }
    }
    template<class T,
             typename std::enable_if<std::is_floating_point<T>::value &&
                                     !has_scan<T>::value>::type* = nullptr>
    void scan(T& a) {
        discard_space();
        bool sgn = false;
        if (*itr == '-') {
            sgn = true;
            ++itr;
        }
        a = 0;
        while ('0' <= *itr && *itr <= '9') {
            a = a * 10 + *itr - '0';
            ++itr;
        }
        if (*itr == '.') {
            ++itr;
            T n = 0, d = 1;
            for (int i = 0;
                 '0' <= *itr && *itr <= '9' && i < (int)decimal_precision;
                 ++i) {
                n = n * 10 + *itr - '0';
                d *= 10;
                ++itr;
            }
            while ('0' <= *itr && *itr <= '9') ++itr;
            a += n / d;
        }
        if (sgn) a = -a;
    }

private:
    template<std::size_t i, class... Args> void scan(std::tuple<Args...>& a) {
        if IF_CONSTEXPR (i < sizeof...(Args)) {
            scan(std::get<i>(a));
            scan<i + 1, Args...>(a);
        }
    }

public:
    template<class... Args> void scan(std::tuple<Args...>& a) {
        scan<0, Args...>(a);
    }
    template<class T, class U> void scan(std::pair<T, U>& a) {
        scan(a.first);
        scan(a.second);
    }
    template<class T,
             typename std::enable_if<is_range<T>::value &&
                                     !has_scan<T>::value>::type* = nullptr>
    void scan(T& a) {
        each_for (i : a) scan(i);
    }
    template<class T,
             typename std::enable_if<has_scan<T>::value>::type* = nullptr>
    void scan(T& a) {
        a.scan(*this);
    }

    void operator()() {}
    template<class Head, class... Args>
    void operator()(Head& head, Args&... args) {
        scan(head);
        operator()(args...);
    }

    template<class T> Scanner& operator>>(T& a) {
        scan(a);
        return *this;
    }

    explicit operator bool() const { return itr.rdstate(); }
};

Scanner<Reader<>::iterator> scan(reader.begin());

template<class Iterator, std::size_t decimal_precision>
Scanner<Iterator, decimal_precision>&
getline(Scanner<Iterator, decimal_precision>& scan, std::string& a) {
    a.clear();
    char c;
    while ((c = scan.scan_char()) != '\n') {
        a += c;
    }
    return scan;
}
