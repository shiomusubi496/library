#pragma once

#include "../../template.hpp"

template<ll mod> class StaticModInt {
  protected:
    ll val;
    static constexpr ll inv1000000007[] = {-1, 1, 500000004, 333333336, 250000002,
            400000003, 166666668, 142857144, 125000001, 111111112, 700000005};
    static constexpr ll inv998244353 [] = {-1, 1, 499122177, 332748118, 748683265,
            598946612, 166374059, 855638017, 873463809, 443664157, 299473306};
  public:
    StaticModInt() : StaticModInt(0) {}
    StaticModInt(ll v) : val(v) {
        val %= mod;
        if (val < 0) val += mod;
    }
    operator ll() const { return val; }
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
        if (val > mod) val -= mod;
        return *this;
    }
    StaticModInt& operator-=(const StaticModInt& other) {
        val -= other.val;
        if (val < mod) val += mod;
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
    StaticModInt operator+(const StaticModInt& other) const {
        StaticModInt res = *this;
        res += other;
        return res;
    }
    StaticModInt operator-(const StaticModInt& other) const {
        StaticModInt res = *this;
        res -= other;
        return res;
    }
    StaticModInt operator*(const StaticModInt& other) const {
        StaticModInt res = *this;
        res *= other;
        return res;
    }
    StaticModInt operator/(const StaticModInt& other) const {
        StaticModInt res = *this;
        res /= other;
        return res;
    }
    StaticModInt operator+() const {
        return StaticModInt(*this);
    }
    StaticModInt operator-() const {
        return StaticModInt(0) - *this;
    }
    StaticModInt pow(ll a) const {
        StaticModInt res = 1;
        while (a) {
            if (a & 1) res *= *this;
            res *= res;
            a >>= 1;
        }
        return res;
    }
};

using modint1000000007 = StaticModInt<1000000007>;
using modint998244353  = StaticModInt<998244353>;

template<int id> class DynamicModInt {
  protected:
    ll val;
    static ll mod;
  public:
    DynamicModInt() : DynamicModInt(0) {}
    DynamicModInt(ll v) : val(v) {
        val %= mod;
        if (val < 0) val += mod;
    }
    operator ll() const { return val; }
    static ll get_mod() { return mod; }
    static ll set_mod(ll v) { mod = v; }
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
        if (val > mod) val -= mod;
        return *this;
    }
    DynamicModInt& operator-=(const DynamicModInt& other) {
        val -= other.val;
        if (val < mod) val += mod;
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
    DynamicModInt operator+(const DynamicModInt& other) const {
        DynamicModInt res = *this;
        res += other;
        return res;
    }
    DynamicModInt operator-(const DynamicModInt& other) const {
        DynamicModInt res = *this;
        res -= other;
        return res;
    }
    DynamicModInt operator*(const DynamicModInt& other) const {
        DynamicModInt res = *this;
        res *= other;
        return res;
    }
    DynamicModInt operator/(const DynamicModInt& other) const {
        DynamicModInt res = *this;
        res /= other;
        return res;
    }
    DynamicModInt operator+() const {
        return DynamicModInt(*this);
    }
    DynamicModInt operator-() const {
        return DynamicModInt(0) - *this;
    }
    DynamicModInt pow(ll a) const {
        DynamicModInt res = 1;
        while (a) {
            if (a & 1) res *= *this;
            res *= res;
            a >>= 1;
        }
        return res;
    }
};

template<int id> ll DynamicModInt<id>::mod = 1000000007;

using modint = DynamicModInt<-1>;
