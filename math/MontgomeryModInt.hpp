#pragma once

#include "../other/template.hpp"

template<class T> class MontgomeryReduction {
    static_assert(std::is_integral<T>::value, "T must be integral");
    static_assert(std::is_unsigned<T>::value, "T must be unsigned");

private:
    using large_t = typename double_size_uint<T>::type;
    static constexpr int lg = std::numeric_limits<T>::digits;
    T mod;
    T r2; // r^2 mod m
    T calc_minv() {
        T t = 0, res = 0;
        rep (i, lg) {
            if (~t & 1) {
                t += mod;
                res += static_cast<T>(1) << i;
            }
            t >>= 1;
        }
        return res;
    }
    T minv;

public:
    MontgomeryReduction(T v) { set_mod(v); }
    static constexpr int get_lg() { return lg; }
    void set_mod(T v) {
        assert(v > 0);
        assert(v & 1);
        assert(v <= std::numeric_limits<T>::max() / 2);
        mod = v;
        r2 = (-static_cast<large_t>(mod)) % mod;
        minv = calc_minv();
    }
    inline T get_mod() const { return mod; }
    T reduce(large_t x) const {
        large_t tmp =
            (x + static_cast<large_t>(static_cast<T>(x) * minv) * mod) >> lg;
        return tmp >= mod ? tmp - mod : tmp;
    }
    T transform(large_t x) const { return reduce(x * r2); }
};

template<class T, int id> class MontgomeryModInt {
private:
    using large_t = typename double_size_uint<T>::type;
    using signed_t = typename std::make_signed<T>::type;
    T val;

    static MontgomeryReduction<T> mont;

public:
    MontgomeryModInt() : val(0) {}
    template<class U, typename std::enable_if<
                          std::is_integral<U>::value &&
                          std::is_unsigned<U>::value>::type* = nullptr>
    MontgomeryModInt(U x)
        : val(mont.transform(
              x < (static_cast<large_t>(mont.get_mod()) << mont.get_lg())
                  ? x
                  : x % mont.get_mod())) {}
    template<class U,
             typename std::enable_if<std::is_integral<U>::value &&
                                     std::is_signed<U>::value>::type* = nullptr>
    MontgomeryModInt(U x)
        : MontgomeryModInt(static_cast<typename std::make_unsigned<U>::type>(
              x < 0 ? -x : x)) {
        if (x < 0 && val) val = mont.get_mod() - val;
    }

    T get() const { return mont.reduce(val); }
    static T get_mod() { return mont.get_mod(); }

    static void set_mod(T v) { mont.set_mod(v); }

    MontgomeryModInt operator+() const { return *this; }
    MontgomeryModInt operator-() const {
        MontgomeryModInt res;
        if (val) res.val = mont.get_mod() - val;
        return res;
    }
    MontgomeryModInt& operator++() {
        val = val + 1 < mont.get_mod() ? val + 1 : 0;
        return *this;
    }
    MontgomeryModInt& operator--() {
        val = val ? val - 1 : mont.get_mod() - 1;
        return *this;
    }
    MontgomeryModInt operator++(int) {
        MontgomeryModInt res = *this;
        ++*this;
        return res;
    }
    MontgomeryModInt operator--(int) {
        MontgomeryModInt res = *this;
        --*this;
        return res;
    }

    MontgomeryModInt& operator+=(const MontgomeryModInt& rhs) {
        val += rhs.val;
        if (val >= mont.get_mod()) val -= mont.get_mod();
        return *this;
    }
    MontgomeryModInt& operator-=(const MontgomeryModInt& rhs) {
        if (val < rhs.val) val += mont.get_mod();
        val -= rhs.val;
        return *this;
    }
    MontgomeryModInt& operator*=(const MontgomeryModInt& rhs) {
        val = mont.reduce(static_cast<large_t>(val) * rhs.val);
        return *this;
    }

    MontgomeryModInt pow(ull n) const {
        MontgomeryModInt res = 1, x = *this;
        while (n) {
            if (n & 1) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }
    MontgomeryModInt inv() const { return pow(mont.get_mod() - 2); }

    MontgomeryModInt& operator/=(const MontgomeryModInt& rhs) {
        return *this *= rhs.inv();
    }

    friend MontgomeryModInt operator+(const MontgomeryModInt& lhs,
                                      const MontgomeryModInt& rhs) {
        return MontgomeryModInt(lhs) += rhs;
    }
    friend MontgomeryModInt operator-(const MontgomeryModInt& lhs,
                                      const MontgomeryModInt& rhs) {
        return MontgomeryModInt(lhs) -= rhs;
    }
    friend MontgomeryModInt operator*(const MontgomeryModInt& lhs,
                                      const MontgomeryModInt& rhs) {
        return MontgomeryModInt(lhs) *= rhs;
    }
    friend MontgomeryModInt operator/(const MontgomeryModInt& lhs,
                                      const MontgomeryModInt& rhs) {
        return MontgomeryModInt(lhs) /= rhs;
    }

    friend bool operator==(const MontgomeryModInt& lhs,
                           const MontgomeryModInt& rhs) {
        return lhs.val == rhs.val;
    }
    friend bool operator!=(const MontgomeryModInt& lhs,
                           const MontgomeryModInt& rhs) {
        return lhs.val != rhs.val;
    }

    template<class Pr> void print(Pr& a) const { a.print(mont.reduce(val)); }
    template<class Pr> void debug(Pr& a) const { a.print(mont.reduce(val)); }
    template<class Sc> void scan(Sc& a) {
        ll v;
        a.scan(v);
        *this = v;
    }
};

template<class T, int id>
MontgomeryReduction<T>
    MontgomeryModInt<T, id>::mont = MontgomeryReduction<T>(998244353);

using mmodint = MontgomeryModInt<unsigned int, -1>;

/**
 * @brief MontgomeryModInt(モンゴメリ乗算)
 * @docs docs/math/MontgomeryModInt.md
 */
