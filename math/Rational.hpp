#pragma once

#include "../other/template.hpp"

template<class T, bool allow_div_zero = false> class Rational {
private:
    using LargeT =
        typename std::conditional<std::is_integral<T>::value,
                                  typename double_size<T>::type, ld>::type;
    T num, den;

public:
    static void norm(T& a, T& b) {
        if IF_CONSTEXPR (!allow_div_zero) {
            assert(b != 0);
        }
        T g = gcd(abs(a), abs(b));
        a /= g;
        b /= g;
        if (b < 0) {
            a = -a;
            b = -b;
        }
    }
    void normalize() { norm(num, den); }
    Rational() : num(0), den(1) {}
    Rational(T a) : num(a), den(1) {}
    Rational(T a, T b) : num(a), den(b) { normalize(); }
    T get_num() const { return num; }
    T get_den() const { return den; }
    ld get_ld() const { return (ld)num / den; }
    std::pair<T, T> get_pair() const { return {num, den}; }
    Rational& operator++() {
        num += den;
        return *this;
    }
    Rational operator++(int) {
        Rational res = *this;
        ++*this;
        return res;
    }
    Rational& operator--() {
        num -= den;
        return *this;
    }
    Rational operator--(int) {
        Rational res = *this;
        --*this;
        return res;
    }
    Rational& operator+=(const Rational& other) {
        T g = gcd(den, other.den);
        num = num * (other.den / g) + other.num * (den / g);
        den = den / g * other.den;
        normalize();
        return *this;
    }
    Rational& operator-=(const Rational& other) {
        T g = gcd(den, other.den);
        num = num * (other.den / g) - other.num * (den / g);
        den = den / g * other.den;
        normalize();
        return *this;
    }
    Rational& operator*=(const Rational& other) {
        T g1 = gcd(num, other.den);
        T g2 = gcd(den, other.num);
        num = (num / g1) * (other.num / g2);
        den = (den / g2) * (other.den / g1);
        return *this;
    }
    Rational& operator/=(const Rational& other) {
        return (*this) *= Rational(other.den, other.num);
    }
    friend Rational operator+(const Rational& lhs, const Rational& rhs) {
        return Rational(lhs) += rhs;
    }
    friend Rational operator-(const Rational& lhs, const Rational& rhs) {
        return Rational(lhs) -= rhs;
    }
    friend Rational operator*(const Rational& lhs, const Rational& rhs) {
        return Rational(lhs) *= rhs;
    }
    friend Rational operator/(const Rational& lhs, const Rational& rhs) {
        return Rational(lhs) /= rhs;
    }
    Rational operator+() const { return Rational(*this); }
    Rational operator-() const { return Rational(-num, den); }
    friend bool operator==(const Rational& lhs, const Rational& rhs) {
        return lhs.num == rhs.num && lhs.den == rhs.den;
    }
    friend bool operator!=(const Rational& lhs, const Rational& rhs) {
        return lhs.num != rhs.num || lhs.den != rhs.den;
    }
    friend bool operator<(const Rational& lhs, const Rational& rhs) {
        return (LargeT)lhs.num * rhs.den < (LargeT)rhs.num * lhs.den;
    }
    friend bool operator>(const Rational& lhs, const Rational& rhs) {
        return rhs < lhs;
    }
    friend bool operator<=(const Rational& lhs, const Rational& rhs) {
        return !(rhs < lhs);
    }
    friend bool operator>=(const Rational& lhs, const Rational& rhs) {
        return !(lhs < rhs);
    }
    template<class Pr> void print(Pr& a) const { a.print(get_ld()); }
    template<class Pr> void debug(Pr& a) const {
        a.print(num);
        a.print_char('/');
        a.print(den);
    }
    template<class Sc> void scan(Sc& a) {
        a.scan(num);
        a.scan(den);
    }
};

namespace std {

template<class T> Rational<T> abs(const Rational<T>& x) {
    return Rational<T>(abs(x.get_num()), x.get_den());
}

} // namespace std

using Fraction = Rational<ll>;

/**
 * @brief Rational(有理数型)
 * @docs docs/math/Rational.md
 */
