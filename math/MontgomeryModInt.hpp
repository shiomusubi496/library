#pragma once

#include "../other/template.hpp"

template<class T, int id> class MontgomeryModInt {
    static_assert(std::is_integral<T>::value, "T must be integral");
    static_assert(std::is_unsigned<T>::value, "T must be unsigned");

private:
    using large_t = typename double_size_uint<T>::type;
    using signed_t = typename std::make_signed<T>::type;
    T val;

    static constexpr int lg = std::numeric_limits<T>::digits; // r = 2^lg
    static T mod;
    static T r2; // r^2 mod m

    static T calc_minv() {
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

    static T minv; // mod * minv = -1 (mod r)

    // x / R (mod mod)
    static T reduce(large_t x) {
        large_t tmp =
            (x + static_cast<large_t>(static_cast<T>(x) * minv) * mod) >> lg;
        return tmp >= mod ? tmp - mod : tmp;
    }
    static T transrate(large_t x) { return reduce(x * r2); }

public:
    MontgomeryModInt() : val(0) {}
    template<class U, typename std::enable_if<
                          std::is_integral<U>::value &&
                          std::is_unsigned<U>::value>::type* = nullptr>
    MontgomeryModInt(U x)
        : val(transrate(x < (static_cast<large_t>(mod) << lg) ? x : x % mod)) {}
    template<class U,
             typename std::enable_if<std::is_integral<U>::value &&
                                     std::is_signed<U>::value>::type* = nullptr>
    MontgomeryModInt(U x)
        : MontgomeryModInt(static_cast<typename std::make_unsigned<U>::type>(
              x < 0 ? -x : x)) {
        if (x < 0 && val) val = mod - val;
    }

    T get() const { return reduce(val); }
    static T get_mod() { return mod; }

    static void set_mod(T v) {
        assert(v > 0);
        assert(v & 1);
        assert(v <= std::numeric_limits<T>::max() / 2);
        mod = v;
        r2 = (-static_cast<large_t>(mod)) % mod;
        minv = calc_minv();
    }

    MontgomeryModInt operator+() const { return *this; }
    MontgomeryModInt operator-() const {
        MontgomeryModInt res;
        if (val) res.val = mod - val;
        return res;
    }
    MontgomeryModInt& operator++() {
        val = val + 1 < mod ? val + 1 : 0;
        return *this;
    }
    MontgomeryModInt& operator--() {
        val = val ? val - 1 : mod - 1;
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
        if (val >= mod) val -= mod;
        return *this;
    }
    MontgomeryModInt& operator-=(const MontgomeryModInt& rhs) {
        if (val < rhs.val) val += mod;
        val -= rhs.val;
        return *this;
    }
    MontgomeryModInt& operator*=(const MontgomeryModInt& rhs) {
        val = reduce(static_cast<large_t>(val) * rhs.val);
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
    MontgomeryModInt inv() const { return pow(mod - 2); }

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

    template<class Pr> void print(Pr& a) const { a.print(reduce(val)); }
    template<class Pr> void debug(Pr& a) const { a.print(reduce(val)); }
    template<class Sc> void scan(Sc& a) {
        ll v;
        a.scan(v);
        *this = v;
    }
};

template<class T, int id> T MontgomeryModInt<T, id>::mod = 998244353;
template<class T, int id>
T MontgomeryModInt<T, id>::r2 = (-static_cast<large_t>(mod)) % mod;
template<class T, int id> T MontgomeryModInt<T, id>::minv = calc_minv();

using mmodint = MontgomeryModInt<unsigned int, -1>;

/**
 * @brief MontgomeryModInt(モンゴメリ乗算)
 * @docs docs/math/MontgomeryModInt.md
 */
