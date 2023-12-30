#pragma once

#include "../other/template.hpp"

class BarrettReduction {
private:
    unsigned int m;
    unsigned long long im;

public:
    BarrettReduction(unsigned int m_)
        : m(m_), im((unsigned long long)(-1) / m + 1) {}

    inline void set_mod(unsigned int m_) {
        m = m_;
        im = (unsigned long long)(-1) / m + 1;
    }

    inline unsigned int get_mod() const { return m; }

    unsigned int reduce(ull a) const {
        ull x = static_cast<ull>((static_cast<u128>(a) * im) >> 64);
        unsigned int v = static_cast<unsigned int>(a - x * static_cast<ull>(m));
        return v >= m ? v + m : v;
    }

    unsigned int rem(ull a) const { return reduce(a); }

    ull quo(ull a) const {
        ull x = static_cast<ull>((static_cast<u128>(a) * im) >> 64);
        unsigned int v = static_cast<unsigned int>(a - x * static_cast<ull>(m));
        return v >= m ? x - 1 : x;
    }

    unsigned int mul(unsigned int a, unsigned int b) const {
        return reduce(static_cast<ull>(a) * b);
    }
};


template<int id> class BarrettModInt {
private:
    unsigned int val;

    static BarrettReduction bar;

public:
    BarrettModInt() : val(0) {}
    template<class U, typename std::enable_if<
                          std::is_integral<U>::value>::type* = nullptr>
    BarrettModInt(U x) {
        long long v = (long long)(x % (long long)bar.get_mod());
        if (v < 0) v += bar.get_mod();
        val = (unsigned int)v;
    }

    unsigned int get() const { return val; }
    static unsigned int get_mod() { return bar.get_mod(); }

    static void set_mod(unsigned int v) { bar.set_mod(v); }

    BarrettModInt operator+() const { return *this; }
    BarrettModInt operator-() const {
        BarrettModInt res;
        if (val) res.val = bar.get_mod() - val;
        return res;
    }
    BarrettModInt& operator++() {
        ++val;
        if (val == bar.get_mod()) val = 0;
        return *this;
    }
    BarrettModInt& operator--() {
        if (val == 0) val = bar.get_mod();
        --val;
        return *this;
    }
    BarrettModInt operator++(int) {
        BarrettModInt res = *this;
        ++*this;
        return res;
    }
    BarrettModInt operator--(int) {
        BarrettModInt res = *this;
        --*this;
        return res;
    }

    BarrettModInt& operator+=(const BarrettModInt& rhs) {
        val += rhs.val;
        if (val >= bar.get_mod()) val -= bar.get_mod();
        return *this;
    }
    BarrettModInt& operator-=(const BarrettModInt& rhs) {
        if (val < rhs.val) val += bar.get_mod();
        val -= rhs.val;
        return *this;
    }
    BarrettModInt& operator*=(const BarrettModInt& rhs) {
        val = bar.mul(val, rhs.val);
        return *this;
    }

    BarrettModInt pow(ull n) const {
        BarrettModInt res = 1, x = *this;
        while (n) {
            if (n & 1) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }

    BarrettModInt inv() const { return mod_inv(val, bar.get_mod()); }

    BarrettModInt& operator/=(const BarrettModInt& rhs) {
        return *this *= rhs.inv();
    }

    friend BarrettModInt operator+(const BarrettModInt& lhs,
                                   const BarrettModInt& rhs) {
        return BarrettModInt(lhs) += rhs;
    }
    friend BarrettModInt operator-(const BarrettModInt& lhs,
                                   const BarrettModInt& rhs) {
        return BarrettModInt(lhs) -= rhs;
    }
    friend BarrettModInt operator*(const BarrettModInt& lhs,
                                   const BarrettModInt& rhs) {
        return BarrettModInt(lhs) *= rhs;
    }
    friend BarrettModInt operator/(const BarrettModInt& lhs,
                                   const BarrettModInt& rhs) {
        return BarrettModInt(lhs) /= rhs;
    }

    friend bool operator==(const BarrettModInt& lhs, const BarrettModInt& rhs) {
        return lhs.val == rhs.val;
    }
    friend bool operator!=(const BarrettModInt& lhs, const BarrettModInt& rhs) {
        return lhs.val != rhs.val;
    }

    template<class Pr> void print(Pr& a) const { a.print(bar.reduce(val)); }
    template<class Pr> void debug(Pr& a) const { a.print(bar.reduce(val)); }
    template<class Sc> void scan(Sc& a) {
        ll v;
        a.scan(v);
        *this = v;
    }
};

template<int id>
BarrettReduction BarrettModInt<id>::bar = BarrettReduction(998244353);

using bmodint = BarrettModInt<-1>;
