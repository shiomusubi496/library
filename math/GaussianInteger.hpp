#pragma once

#include "../other/template.hpp"

template<class T>
class GaussianInteger {
public:
    T real, imag;

    GaussianInteger() : real(0), imag(0) {}
    GaussianInteger(T real) : real(real), imag(0) {}
    GaussianInteger(T real, T imag) : real(real), imag(imag) {}

    GaussianInteger conj() const { return GaussianInteger(real, -imag); }
    T norm() const { return real * real + imag * imag; }
    GaussianInteger operator+() { return *this; }
    GaussianInteger operator-() const { return GaussianInteger(-real, -imag); }
    GaussianInteger operator+=(const GaussianInteger& rhs) {
        real += rhs.real;
        imag += rhs.imag;
        return *this;
    }
    GaussianInteger operator-=(const GaussianInteger& rhs) {
        real -= rhs.real;
        imag -= rhs.imag;
        return *this;
    }
    GaussianInteger operator*=(const GaussianInteger& rhs) {
        T tmp = real * rhs.real - imag * rhs.imag;
        imag = real * rhs.imag + imag * rhs.real;
        real = tmp;
        return *this;
    }
    friend GaussianInteger operator+(const GaussianInteger& lhs, const GaussianInteger& rhs) {
        return GaussianInteger(lhs) += rhs;
    }
    friend GaussianInteger operator-(const GaussianInteger& lhs, const GaussianInteger& rhs) {
        return GaussianInteger(lhs) -= rhs;
    }
    friend GaussianInteger operator*(const GaussianInteger& lhs, const GaussianInteger& rhs) {
        return GaussianInteger(lhs) *= rhs;
    }
    friend bool operator==(const GaussianInteger& lhs, const GaussianInteger& rhs) {
        return lhs.real == rhs.real && lhs.imag == rhs.imag;
    }
    friend bool operator!=(const GaussianInteger& lhs, const GaussianInteger& rhs) {
        return !(lhs == rhs);
    }
    template<class Pr> void print(Pr& pr) const {
        pr.print(real);
        pr.print(' ');
        pr.print(imag);
    }
    template<class Pr> void debug(Pr& pr) const {
        pr.print(real);
        pr.print_char('+');
        pr.print(imag);
        pr.print_char('i');
    }
    template<class Sc> void scan(Sc& sc) {
        sc.scan(real);
        sc.scan(imag);
    }
};

template<class T>
GaussianInteger<T> gcd(GaussianInteger<T> a, GaussianInteger<T> b) {
    while (b != GaussianInteger<T>()) {
        GaussianInteger<T> q = a * b.conj();
        T n = b.norm();
        {
            T tmp = q.real;
            q.real /= n;
            tmp = tmp - q.real * n;
            if (tmp * 2 > n) ++q.real;
            if (tmp * 2 < -n) --q.real;
        }
        {
            T tmp = q.imag;
            q.imag /= n;
            tmp = tmp - q.imag * n;
            if (tmp * 2 > n) ++q.imag;
            if (tmp * 2 < -n) --q.imag;
        }
        a -= b * q;
        std::swap(a, b);
    }
    return a;
}

/**
 * @brief GaussianInteger
 * @see https://maspypy.com/library-checker-gcd-of-gaussian-integers
 */
