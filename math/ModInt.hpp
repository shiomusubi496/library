#pragma once

#include "../other/template.hpp"

template<class T, T mod> class StaticModInt {
    static_assert(std::is_integral<T>::value, "T must be integral");
    static_assert(std::is_unsigned<T>::value, "T must be unsigned");
    static_assert(mod > 0, "mod must be positive");
    static_assert(mod <= std::numeric_limits<T>::max() / 2,
                  "mod * 2 must be less than or equal to T::max()");

private:
    using large_t = typename double_size_uint<T>::type;
    using signed_t = typename std::make_signed<T>::type;
    T val;
    static constexpr unsigned int inv1000000007[] = {
        0,         1,         500000004, 333333336, 250000002, 400000003,
        166666668, 142857144, 125000001, 111111112, 700000005};
    static constexpr unsigned int inv998244353[] = {
        0,         1,         499122177, 332748118, 748683265, 598946612,
        166374059, 855638017, 873463809, 443664157, 299473306};

    static constexpr ll mod_inv(ll a) {
        ll b = mod;
        ll x = 1, u = 0;
        ll t = 0, tmp = 0;
        while (b) {
            t = a / b;
            tmp = (a - t * b);
            a = b;
            b = tmp;
            tmp = (x - t * u);
            x = u;
            u = tmp;
        }
        if (x < 0) x += mod;
        return x;
    }

public:
    constexpr StaticModInt() : val(0) {}
    template<class U,
             typename std::enable_if<std::is_integral<U>::value &&
                                     std::is_signed<U>::value>::type* = nullptr>
    constexpr StaticModInt(U v) : val{} {
        v %= static_cast<signed_t>(mod);
        if (v < 0) v += static_cast<signed_t>(mod);
        val = static_cast<T>(v);
    }
    template<class U, typename std::enable_if<
                          std::is_integral<U>::value &&
                          std::is_unsigned<U>::value>::type* = nullptr>
    constexpr StaticModInt(U v) : val(v % mod) {}
    constexpr T get() const { return val; }
    static constexpr T get_mod() { return mod; }
    static constexpr StaticModInt raw(T v) {
        StaticModInt res;
        res.val = v;
        return res;
    }
    constexpr StaticModInt inv() const {
        if IF_CONSTEXPR (mod == 1000000007) {
            if (val <= 10) return inv1000000007[val];
        }
        else if IF_CONSTEXPR (mod == 998244353) {
            if (val <= 10) return inv998244353[val];
        }
        return mod_inv(val);
    }
    constexpr StaticModInt& operator++() {
        ++val;
        if (val == mod) val = 0;
        return *this;
    }
    constexpr StaticModInt operator++(int) {
        StaticModInt res = *this;
        ++*this;
        return res;
    }
    constexpr StaticModInt& operator--() {
        if (val == 0) val = mod;
        --val;
        return *this;
    }
    constexpr StaticModInt operator--(int) {
        StaticModInt res = *this;
        --*this;
        return res;
    }
    constexpr StaticModInt& operator+=(const StaticModInt& other) {
        val += other.val;
        if (val >= mod) val -= mod;
        return *this;
    }
    constexpr StaticModInt& operator-=(const StaticModInt& other) {
        if (val < other.val) val += mod;
        val -= other.val;
        return *this;
    }
    constexpr StaticModInt& operator*=(const StaticModInt& other) {
        large_t a = val;
        a *= other.val;
        a %= mod;
        val = a;
        return *this;
    }
    constexpr StaticModInt& operator/=(const StaticModInt& other) {
        *this *= other.inv();
        return *this;
    }
    friend constexpr StaticModInt operator+(const StaticModInt& lhs,
                                  const StaticModInt& rhs) {
        return StaticModInt(lhs) += rhs;
    }
    friend constexpr StaticModInt operator-(const StaticModInt& lhs,
                                  const StaticModInt& rhs) {
        return StaticModInt(lhs) -= rhs;
    }
    friend constexpr StaticModInt operator*(const StaticModInt& lhs,
                                  const StaticModInt& rhs) {
        return StaticModInt(lhs) *= rhs;
    }
    friend constexpr StaticModInt operator/(const StaticModInt& lhs,
                                  const StaticModInt& rhs) {
        return StaticModInt(lhs) /= rhs;
    }
    constexpr StaticModInt operator+() const { return StaticModInt(*this); }
    constexpr StaticModInt operator-() const { return StaticModInt() - *this; }
    friend constexpr bool operator==(const StaticModInt& lhs, const StaticModInt& rhs) {
        return lhs.val == rhs.val;
    }
    friend constexpr bool operator!=(const StaticModInt& lhs, const StaticModInt& rhs) {
        return lhs.val != rhs.val;
    }
    constexpr StaticModInt pow(ll a) const {
        StaticModInt v = *this, res = 1;
        while (a) {
            if (a & 1) res *= v;
            a >>= 1;
            v *= v;
        }
        return res;
    }
    template<class Pr> void print(Pr& a) const { a.print(val); }
    template<class Pr> void debug(Pr& a) const { a.print(val); }
    template<class Sc> void scan(Sc& a) {
        ll v;
        a.scan(v);
        *this = v;
    }
};

#if __cplusplus < 201703L
template<class T, T mod>
constexpr unsigned int StaticModInt<T, mod>::inv1000000007[];
template<class T, T mod>
constexpr unsigned int StaticModInt<T, mod>::inv998244353[];
#endif

template<unsigned int p> using static_modint = StaticModInt<unsigned int, p>;
using modint1000000007 = static_modint<1000000007>;
using modint998244353 = static_modint<998244353>;

template<class T, int id> class DynamicModInt {
    static_assert(std::is_integral<T>::value, "T must be integral");
    static_assert(std::is_unsigned<T>::value, "T must be unsigned");

private:
    using large_t = typename double_size_uint<T>::type;
    using signed_t = typename std::make_signed<T>::type;
    T val;
    static T mod;

public:
    constexpr DynamicModInt() : val(0) {}
    template<class U,
             typename std::enable_if<std::is_integral<U>::value &&
                                     std::is_signed<U>::value>::type* = nullptr>
    constexpr DynamicModInt(U v) : val{} {
        v %= static_cast<signed_t>(mod);
        if (v < 0) v += static_cast<signed_t>(mod);
        val = static_cast<T>(v);
    }
    template<class U, typename std::enable_if<
                          std::is_integral<U>::value &&
                          std::is_unsigned<U>::value>::type* = nullptr>
    constexpr DynamicModInt(U v) : val(v % mod) {}
    T get() const { return val; }
    static T get_mod() { return mod; }
    static void set_mod(T v) {
        assert(v > 0);
        assert(v <= std::numeric_limits<T>::max() / 2);
        mod = v;
    }
    static DynamicModInt raw(T v) {
        DynamicModInt res;
        res.val = v;
        return res;
    }
    DynamicModInt inv() const { return mod_inv(val, mod); }
    DynamicModInt& operator++() {
        ++val;
        if (val == mod) val = 0;
        return *this;
    }
    DynamicModInt operator++(int) {
        DynamicModInt res = *this;
        ++*this;
        return res;
    }
    DynamicModInt& operator--() {
        if (val == 0) val = mod;
        --val;
        return *this;
    }
    DynamicModInt operator--(int) {
        DynamicModInt res = *this;
        --*this;
        return res;
    }
    DynamicModInt& operator+=(const DynamicModInt& other) {
        val += other.val;
        if (val >= mod) val -= mod;
        return *this;
    }
    DynamicModInt& operator-=(const DynamicModInt& other) {
        if (val < other.val) val += mod;
        val -= other.val;
        return *this;
    }
    DynamicModInt& operator*=(const DynamicModInt& other) {
        large_t a = val;
        a *= other.val;
        a %= mod;
        val = a;
        return *this;
    }
    DynamicModInt& operator/=(const DynamicModInt& other) {
        *this *= other.inv();
        return *this;
    }
    friend DynamicModInt operator+(const DynamicModInt& lhs,
                                   const DynamicModInt& rhs) {
        return DynamicModInt(lhs) += rhs;
    }
    friend DynamicModInt operator-(const DynamicModInt& lhs,
                                   const DynamicModInt& rhs) {
        return DynamicModInt(lhs) -= rhs;
    }
    friend DynamicModInt operator*(const DynamicModInt& lhs,
                                   const DynamicModInt& rhs) {
        return DynamicModInt(lhs) *= rhs;
    }
    friend DynamicModInt operator/(const DynamicModInt& lhs,
                                   const DynamicModInt& rhs) {
        return DynamicModInt(lhs) /= rhs;
    }
    DynamicModInt operator+() const { return DynamicModInt(*this); }
    DynamicModInt operator-() const { return DynamicModInt() - *this; }
    friend bool operator==(const DynamicModInt& lhs, const DynamicModInt& rhs) {
        return lhs.val == rhs.val;
    }
    friend bool operator!=(const DynamicModInt& lhs, const DynamicModInt& rhs) {
        return lhs.val != rhs.val;
    }
    DynamicModInt pow(ll a) const {
        DynamicModInt v = *this, res = 1;
        while (a) {
            if (a & 1) res *= v;
            a >>= 1;
            v *= v;
        }
        return res;
    }
    template<class Pr> void print(Pr& a) const { a.print(val); }
    template<class Pr> void debug(Pr& a) const { a.print(val); }
    template<class Sc> void scan(Sc& a) {
        ll v;
        a.scan(v);
        *this = v;
    }
};

template<class T, int id> T DynamicModInt<T, id>::mod = 998244353;

template<int id> using dynamic_modint = DynamicModInt<unsigned int, id>;
using modint = dynamic_modint<-1>;

/**
 * @brief ModInt
 * @docs docs/math/ModInt.md
 */
