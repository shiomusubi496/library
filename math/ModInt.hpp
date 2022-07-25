#pragma once

#include "../other/template.hpp"

class ModIntBase {};
class StaticModIntBase : ModIntBase {};
class DynamicModIntBase : ModIntBase {};

template<class T> using is_ModInt = std::is_base_of<ModIntBase, T>;
template<class T> using is_StaticModInt = std::is_base_of<StaticModIntBase, T>;
template<class T> using is_DynamicModInt = std::is_base_of<DynamicModIntBase, T>;

template<unsigned int mod> class StaticModInt : StaticModIntBase {
    static_assert(mod > 0, "mod must be greater than 0");
  protected:
    unsigned int val;
    static constexpr unsigned int inv1000000007[] = {0, 1, 500000004, 333333336, 250000002,
            400000003, 166666668, 142857144, 125000001, 111111112, 700000005};
    static constexpr unsigned int inv998244353 [] = {0, 1, 499122177, 332748118, 748683265,
            598946612, 166374059, 855638017, 873463809, 443664157, 299473306};
  public:
    StaticModInt() : StaticModInt(0) {}
    template<class T, typename std::enable_if<std::is_integral<T>::value>::type* = nullptr> StaticModInt(T v) {
        v %= mod;
        if (v < 0) v += mod;
        val = v;
    }
    unsigned int get() const { return val; }
    static unsigned int get_mod() { return mod; }
    static StaticModInt raw(unsigned int v) {
        StaticModInt res;
        res.val = v;
        return res;
    }
    StaticModInt inv() const {
        if IF_CONSTEXPR (mod == 1000000007) {
            if (val <= 10) return inv1000000007[val];
        }
        else if IF_CONSTEXPR (mod == 998244353) {
            if (val <= 10) return inv998244353[val];
        }
        return mod_inv(val, mod);
    }
    StaticModInt& operator++() {
        ++val;
        if (val == mod) val = 0;
        return *this;
    }
    StaticModInt operator++(int) {
        StaticModInt res = *this;
        ++ *this;
        return res;
    }
    StaticModInt& operator--() {
        if (val == 0) val = mod;
        --val;
        return *this;
    }
    StaticModInt operator--(int) {
        StaticModInt res = *this;
        -- *this;
        return res;
    }
    StaticModInt& operator+=(const StaticModInt& other) {
        val += other.val;
        if (val >= mod) val -= mod;
        return *this;
    }
    StaticModInt& operator-=(const StaticModInt& other) {
        if (val < other.val) val += mod;
        val -= other.val;
        return *this;
    }
    StaticModInt& operator*=(const StaticModInt& other) {
        unsigned long long a = val;
        a *= other.val;
        a %= mod;
        val = a;
        return *this;
    }
    StaticModInt& operator/=(const StaticModInt& other) {
        *this *= other.inv();
        return *this;
    }
    friend StaticModInt operator+(const StaticModInt& lhs, const StaticModInt& rhs) {
        return StaticModInt(lhs) += rhs;
    }
    friend StaticModInt operator-(const StaticModInt& lhs, const StaticModInt& rhs) {
        return StaticModInt(lhs) -= rhs;
    }
    friend StaticModInt operator*(const StaticModInt& lhs, const StaticModInt& rhs) {
        return StaticModInt(lhs) *= rhs;
    }
    friend StaticModInt operator/(const StaticModInt& lhs, const StaticModInt& rhs) {
        return StaticModInt(lhs) /= rhs;
    }
    StaticModInt operator+() const {
        return StaticModInt(*this);
    }
    StaticModInt operator-() const {
        return StaticModInt::raw(0) - *this;
    }
    friend bool operator==(const StaticModInt& lhs, const StaticModInt& rhs) {
        return lhs.val == rhs.val;
    }
    friend bool operator!=(const StaticModInt& lhs, const StaticModInt& rhs) {
        return lhs.val != rhs.val;
    }
    StaticModInt pow(ll a) const {
        StaticModInt v = *this, res = 1;
        while (a) {
            if (a & 1) res *= v;
            a >>= 1;
            v *= v;
        }
        return res;
    }
    friend std::ostream& operator<<(std::ostream& ost, const StaticModInt& sm) {
        return ost << sm.val;
    }
    friend std::istream& operator>>(std::istream& ist, StaticModInt& sm) {
        ll v; ist >> v;
        sm = v;
        return ist;
    }
};

#if __cplusplus < 201703L
template<unsigned int mod> constexpr unsigned int StaticModInt<mod>::inv1000000007[];
template<unsigned int mod> constexpr unsigned int StaticModInt<mod>::inv998244353 [];
#endif

using modint1000000007 = StaticModInt<1000000007>;
using modint998244353  = StaticModInt<998244353>;

template<int id> class DynamicModInt : DynamicModIntBase {
  protected:
    unsigned int val;
    static unsigned int mod;
  public:
    DynamicModInt() : DynamicModInt(0) {}
    template<class T, typename std::enable_if<std::is_integral<T>::value>::type* = nullptr> DynamicModInt(T v) {
        v %= mod;
        if (v < 0) v += mod;
        val = v;
    }
    unsigned int get() const { return val; }
    static unsigned int get_mod() { return mod; }
    static void set_mod(unsigned int v) { mod = v; }
    static DynamicModInt raw(unsigned int v) {
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
        ++ *this;
        return res;
    }
    DynamicModInt& operator--() {
        if (val == 0) val = mod;
        --val;
        return *this;
    }
    DynamicModInt operator--(int) {
        DynamicModInt res = *this;
        -- *this;
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
        unsigned long long a = val;
        a *= other.val;
        a %= mod;
        val = a;
        return *this;
    }
    DynamicModInt& operator/=(const DynamicModInt& other) {
        *this *= other.inv();
        return *this;
    }
    friend DynamicModInt operator+(const DynamicModInt& lhs, const DynamicModInt& rhs) {
        return DynamicModInt(lhs) += rhs;
    }
    friend DynamicModInt operator-(const DynamicModInt& lhs, const DynamicModInt& rhs) {
        return DynamicModInt(lhs) -= rhs;
    }
    friend DynamicModInt operator*(const DynamicModInt& lhs, const DynamicModInt& rhs) {
        return DynamicModInt(lhs) *= rhs;
    }
    friend DynamicModInt operator/(const DynamicModInt& lhs, const DynamicModInt& rhs) {
        return DynamicModInt(lhs) /= rhs;
    }
    DynamicModInt operator+() const {
        return DynamicModInt(*this);
    }
    DynamicModInt operator-() const {
        return DynamicModInt::raw(0) - *this;
    }
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
    friend std::ostream& operator<<(std::ostream& ost, const DynamicModInt& dm) {
        return ost << dm.val;
    }
    friend std::istream& operator>>(std::istream& ist, DynamicModInt& dm) {
        ll v; ist >> v;
        dm = v;
        return ist;
    }
};

template<int id> unsigned int DynamicModInt<id>::mod = 1000000007;

using modint = DynamicModInt<-1>;

/**
 * @brief ModInt
 * @docs docs/ModInt.md
 */
