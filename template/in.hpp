#pragma once

#include <bits/stdc++.h>
#include <unistd.h>
#include "macros.hpp"
#include "alias.hpp"
#include "type_traits.hpp"

template<std::size_t buf_size = IO_BUFFER_SIZE,
         std::size_t decimal_precision = 16>
class Scanner {
private:
    template<class, class = void> struct has_scan : std::false_type {};
    template<class T>
    struct has_scan<
        T, decltype(std::declval<T>().scan(std::declval<Scanner&>()), (void)0)>
        : std::true_type {};
    int fd;
    int idx, sz;
    bool state;
    std::array<char, IO_BUFFER_SIZE + 1> buffer;
    inline char cur() {
        if (idx == sz) load();
        if (idx == sz) {
            state = false;
            return '\0';
        }
        return buffer[idx];
    }
    inline void next() {
        if (idx == sz) load();
        if (idx == sz) return;
        ++idx;
    }

public:
    inline void load() {
        int len = sz - idx;
        if (idx < len) return;
        std::memcpy(buffer.begin(), buffer.begin() + idx, len);
        sz = len + read(fd, buffer.data() + len, buf_size - len);
        buffer[sz] = 0;
        idx = 0;
    }

    Scanner(int fd) : fd(fd), idx(0), sz(0) {}
    Scanner(FILE* fp) : fd(fileno(fp)), idx(0), sz(0) {}

    inline char scan_char() {
        if (idx == sz) load();
        return idx == sz ? '\0' : buffer[idx++];
    }

    Scanner ignore(int n = 1) {
        if (idx + n > sz) load();
        idx += n;
        return *this;
    }

    inline void discard_space() {
        if (idx == sz) load();
        while (('\t' <= buffer[idx] && buffer[idx] <= '\r') ||
               buffer[idx] == ' ') {
            if (++idx == sz) load();
        }
    }
    void scan(char& a) {
        discard_space();
        a = scan_char();
    }
    void scan(bool& a) {
        discard_space();
        a = scan_char() != '0';
    }
    void scan(std::string& a) {
        discard_space();
        a.clear();
        while (cur() != '\0' && (buffer[idx] < '\t' || '\r' < buffer[idx]) &&
               buffer[idx] != ' ') {
            a += scan_char();
        }
    }
    template<std::size_t len> void scan(std::bitset<len>& a) {
        discard_space();
        if (idx + len > sz) load();
        rrep (i, len) a[i] = buffer[idx++] != '0';
    }
    template<class T,
             typename std::enable_if<is_signed_int<T>::value &&
                                     !has_scan<T>::value>::type* = nullptr>
    void scan(T& a) {
        discard_space();
        if (buffer[idx] == '-') {
            ++idx;
            if (idx + 40 > sz &&
                (idx == sz || ('0' <= buffer[sz - 1] && buffer[sz - 1] <= '9')))
                load();
            a = 0;
            while ('0' <= buffer[idx] && buffer[idx] <= '9') {
                a = a * 10 - (buffer[idx++] - '0');
            }
        }
        else {
            if (idx + 40 > sz && '0' <= buffer[sz - 1] && buffer[sz - 1] <= '9')
                load();
            a = 0;
            while ('0' <= buffer[idx] && buffer[idx] <= '9') {
                a = a * 10 + (buffer[idx++] - '0');
            }
        }
    }
    template<class T,
             typename std::enable_if<is_unsigned_int<T>::value &&
                                     !has_scan<T>::value>::type* = nullptr>
    void scan(T& a) {
        discard_space();
        if (idx + 40 > sz && '0' <= buffer[sz - 1] && buffer[sz - 1] <= '9')
            load();
        a = 0;
        while ('0' <= buffer[idx] && buffer[idx] <= '9') {
            a = a * 10 + (buffer[idx++] - '0');
        }
    }
    template<class T,
             typename std::enable_if<std::is_floating_point<T>::value &&
                                     !has_scan<T>::value>::type* = nullptr>
    void scan(T& a) {
        discard_space();
        bool sgn = false;
        if (cur() == '-') {
            sgn = true;
            next();
        }
        a = 0;
        while ('0' <= cur() && cur() <= '9') {
            a = a * 10 + cur() - '0';
            next();
        }
        if (cur() == '.') {
            next();
            T n = 0, d = 1;
            for (int i = 0;
                 '0' <= cur() && cur() <= '9' && i < (int)decimal_precision;
                 ++i) {
                n = n * 10 + cur() - '0';
                d *= 10;
                next();
            }
            while ('0' <= cur() && cur() <= '9') next();
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
        for (auto&& i : a) scan(i);
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

    explicit operator bool() const { return state; }

    friend Scanner& getline(Scanner& scan, std::string& a) {
        a.erase();
        char c;
        if ((c = scan.scan_char()) == '\n' || c == '\0') return scan;
        a += c;
        while ((c = scan.scan_char()) != '\n' && c != '\0') a += c;
        scan.state = true;
        return scan;
    }
};

Scanner<> scan(0);
