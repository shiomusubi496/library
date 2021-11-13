#pragma once

#include "../template.hpp"

class ModIntBase {};
class StaticModIntBase : ModIntBase {};
class DynamicModIntBase : ModIntBase {};

template<class T> using is_ModInt = std::is_base_of<ModIntBase, T>;
template<class T> using is_StaticModInt = std::is_base_of<StaticModIntBase, T>;
template<class T> using is_DynamicModInt = std::is_base_of<DynamicModIntBase, T>;

template<ll mod> class StaticModInt : StaticModIntBase {
  protected:
    ll val;
    static constexpr ll inv1000000007[] = {-1, 1, 500000004, 333333336, 250000002,
            400000003, 166666668, 142857144, 125000001, 111111112, 700000005};
    static constexpr ll inv998244353 [] = {-1, 1, 499122177, 332748118, 748683265,
            598946612, 166374059, 855638017, 873463809, 443664157, 299473306};
  public:
    StaticModInt() : StaticModInt(0) {}
    template<class T, std::enable_if_t<std::is_integral<T>::value>* = nullptr> StaticModInt(T v) : val(v) {
        val %= mod;
        if (val < 0) val += mod;
    }
    ll get() const { return val; }
    static ll get_mod() { return mod; }
    static StaticModInt raw(ll v) {
        StaticModInt res;
        res.val = v;
        return res;
    }
    StaticModInt inv() const {
#if __cplusplus >= 201703L
        if constexpr (mod == 1000000007) {
            if (val <= 10) return inv1000000007[val];
        }
        else if constexpr (mod == 998244353) {
            if (val <= 10) return inv998244353[val];
        }
#else
        if (mod == 1000000007) {
            if (val <= 10) return inv1000000007[val];
        }
        else if (mod == 998244353) {
            if (val <= 10) return inv998244353[val];
        }
#endif
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
        val -= other.val;
        if (val < 0) val += mod;
        return *this;
    }
    StaticModInt& operator*=(const StaticModInt& other) {
        (val *= other.val) %= mod;
        return *this;
    }
    StaticModInt& operator/=(const StaticModInt& other) {
        (val *= other.inv()) %= mod;
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
        return StaticModInt(0) - *this;
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
        return ist >> sm.val;
    }
};

#if __cplusplus < 201703L
template<ll mod> constexpr ll StaticModInt<mod>::inv1000000007[];
template<ll mod> constexpr ll StaticModInt<mod>::inv998244353 [];
#endif

using modint1000000007 = StaticModInt<1000000007>;
using modint998244353  = StaticModInt<998244353>;

template<int id> class DynamicModInt : DynamicModIntBase {
  protected:
    ll val;
    static ll mod;
  public:
    DynamicModInt() : DynamicModInt(0) {}
    template<class T, std::enable_if_t<std::is_integral<T>::value>* = nullptr> DynamicModInt(T v) : val(v) {
        val %= mod;
        if (val < 0) val += mod;
    }
    ll get() const { return val; }
    static ll get_mod() { return mod; }
    static void set_mod(ll v) { mod = v; }
    static DynamicModInt raw(ll v) {
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
        val -= other.val;
        if (val < 0) val += mod;
        return *this;
    }
    DynamicModInt& operator*=(const DynamicModInt& other) {
        (val *= other.val) %= mod;
        return *this;
    }
    DynamicModInt& operator/=(const DynamicModInt& other) {
        (val *= other.inv()) %= mod;
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
        return DynamicModInt(0) - *this;
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
    friend std::ostream& operator<<(std::ostream& ost, const DynamicModInt& sm) {
        return ost << sm.val;
    }
    friend std::istream& operator>>(std::istream& ist, DynamicModInt& sm) {
        return ist >> sm.val;
    }
};

template<int id> ll DynamicModInt<id>::mod = 1000000007;

using modint = DynamicModInt<-1>;

/**
 * @brief ModInt
 * @docs docs/ModInt.md
 */
