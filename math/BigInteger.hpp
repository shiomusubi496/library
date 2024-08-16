#pragma once

#include "../other/template.hpp"
#include "convolution/Convolution.hpp"

class BigUnsignedInteger {
private:
    static constexpr unsigned int MAX_DIGIT = 0xFFFFFFFF;
    std::vector<unsigned int> digits;

    void normalize() {
        while (!digits.empty() && digits.back() == 0) {
            digits.pop_back();
        }
    }

    int ctoi(char c) {
        if ('0' <= c && c <= '9') {
            return c - '0';
        }
        return c - 'A' + 10;
    }

public:
    BigUnsignedInteger() : digits{} {}
    BigUnsignedInteger(ull a)
        : digits{(unsigned int)(a & MAX_DIGIT), (unsigned int)(a >> 32)} {
        normalize();
    }
    BigUnsignedInteger(const std::vector<unsigned int>& a) : digits{a} {
        normalize();
    }
    BigUnsignedInteger(const std::string& s) { set_hex(s); }

    bool is_zero() const { return digits.empty(); }

    void set_hex(std::string s) {
        std::reverse(all(s));
        s.reserve((s.size() + 7) / 8);
        digits.clear();
        rep (i, 0, s.size(), 8) {
            unsigned int d = 0;
            rrep (j, 8) {
                if (i + j < (int)s.size()) {
                    d = d * 16 + ctoi(s[i + j]);
                }
            }
            digits.push_back(d);
        }
        normalize();
    }
    std::string to_hex() const {
        std::string s;
        for (auto d : digits) {
            rep (i, 8) {
                s += (char)(d % 16 + (d % 16 < 10 ? '0' : 'A' - 10));
                d /= 16;
            }
        }
        while (!s.empty() && s.back() == '0') s.pop_back();
        std::reverse(all(s));
        if (s.empty()) s = "0";
        return s;
    }

    friend bool operator<(const BigUnsignedInteger& a,
                          const BigUnsignedInteger& b) {
        if (a.digits.size() != b.digits.size()) {
            return a.digits.size() < b.digits.size();
        }
        rrep (i, a.digits.size()) {
            if (a.digits[i] != b.digits[i]) {
                return a.digits[i] < b.digits[i];
            }
        }
        return false;
    }
    friend bool operator>(const BigUnsignedInteger& a,
                          const BigUnsignedInteger& b) {
        return b < a;
    }
    friend bool operator<=(const BigUnsignedInteger& a,
                           const BigUnsignedInteger& b) {
        return !(b < a);
    }
    friend bool operator>=(const BigUnsignedInteger& a,
                           const BigUnsignedInteger& b) {
        return !(a < b);
    }
    friend bool operator==(const BigUnsignedInteger& a,
                           const BigUnsignedInteger& b) {
        return a.digits == b.digits;
    }
    friend bool operator!=(const BigUnsignedInteger& a,
                           const BigUnsignedInteger& b) {
        return !(a == b);
    }

    BigUnsignedInteger& operator<<=(int a) {
        int b = a / 32;
        a %= 32;
        if (a) {
            unsigned int carry = 0;
            rep (i, digits.size()) {
                unsigned int next_carry = digits[i] >> (32 - a);
                digits[i] = (digits[i] << a) | carry;
                carry = next_carry;
            }
            if (carry) digits.push_back(carry);
        }
        digits.insert(digits.begin(), b, 0);
        normalize();
        return *this;
    }
    BigUnsignedInteger& operator>>=(int a) {
        if (a == 0) return *this;
        int b = a / 32;
        a %= 32;
        if (a) {
            unsigned int carry = 0;
            rrep (i, digits.size()) {
                unsigned int next_carry = digits[i] << (32 - a);
                digits[i] = (digits[i] >> a) | carry;
                carry = next_carry;
            }
        }
        digits.erase(digits.begin(),
                     digits.begin() + std::min<int>(b, digits.size()));
        normalize();
        return *this;
    }
    BigUnsignedInteger& operator&=(const BigUnsignedInteger& a) {
        if (digits.size() > a.digits.size()) {
            digits.resize(a.digits.size());
        }
        rep (i, digits.size()) digits[i] &= a.digits[i];
        normalize();
        return *this;
    }
    BigUnsignedInteger& operator|=(const BigUnsignedInteger& a) {
        if (digits.size() < a.digits.size()) {
            digits.resize(a.digits.size());
        }
        rep (i, a.digits.size()) digits[i] |= a.digits[i];
        return *this;
    }
    BigUnsignedInteger& operator^=(const BigUnsignedInteger& a) {
        if (digits.size() < a.digits.size()) {
            digits.resize(a.digits.size());
        }
        rep (i, a.digits.size()) digits[i] ^= a.digits[i];
        normalize();
        return *this;
    }

    friend BigUnsignedInteger operator<<(const BigUnsignedInteger& a, int b) {
        return BigUnsignedInteger(a) <<= b;
    }
    friend BigUnsignedInteger operator>>(const BigUnsignedInteger& a, int b) {
        return BigUnsignedInteger(a) >>= b;
    }
    friend BigUnsignedInteger operator&(const BigUnsignedInteger& a,
                                        const BigUnsignedInteger& b) {
        return BigUnsignedInteger(a) &= b;
    }
    friend BigUnsignedInteger operator|(const BigUnsignedInteger& a,
                                        const BigUnsignedInteger& b) {
        return BigUnsignedInteger(a) |= b;
    }
    friend BigUnsignedInteger operator^(const BigUnsignedInteger& a,
                                        const BigUnsignedInteger& b) {
        return BigUnsignedInteger(a) ^= b;
    }

    BigUnsignedInteger& operator++() {
        if (digits.empty()) digits.push_back(1);
        else {
            rep (i, digits.size()) {
                if (digits[i] != MAX_DIGIT) {
                    ++digits[i];
                    break;
                }
                digits[i] = 0;
                if (i + 1 == (int)digits.size()) digits.push_back(0);
            }
        }
        return *this;
    }
    BigUnsignedInteger& operator--() {
        rep (i, digits.size()) {
            if (digits[i] != 0) {
                --digits[i];
                break;
            }
            digits[i] = MAX_DIGIT;
        }
        normalize();
        return *this;
    }
    BigUnsignedInteger operator++(int) {
        BigUnsignedInteger res = *this;
        ++*this;
        return res;
    }
    BigUnsignedInteger operator--(int) {
        BigUnsignedInteger res = *this;
        --*this;
        return res;
    }

    BigUnsignedInteger& operator+=(const BigUnsignedInteger& a) {
        if (digits.size() < a.digits.size()) {
            digits.resize(a.digits.size());
        }
        rep (i, a.digits.size()) {
            digits[i] += a.digits[i];
            if (digits[i] < a.digits[i]) {
                rep (j, i + 1, digits.size()) {
                    if (digits[j] != MAX_DIGIT) {
                        ++digits[j];
                        break;
                    }
                    digits[j] = 0;
                    if (j + 1 == (int)digits.size()) digits.push_back(0);
                }
            }
        }
        normalize();
        return *this;
    }
    BigUnsignedInteger& operator-=(const BigUnsignedInteger& a) {
        if (digits.size() < a.digits.size()) {
            digits.resize(a.digits.size());
        }
        rep (i, a.digits.size()) {
            if (digits[i] < a.digits[i]) {
                rep (j, i + 1, digits.size()) {
                    if (digits[j] > 0) {
                        --digits[j];
                        break;
                    }
                    digits[j] = MAX_DIGIT;
                }
            }
            digits[i] -= a.digits[i];
        }
        normalize();
        return *this;
    }
    BigUnsignedInteger& operator*=(const BigUnsignedInteger& a) {
        std::vector<ll> a1(digits.size() * 2), a2(a.digits.size() * 2);
        rep (i, digits.size()) {
            a1[i * 2] = digits[i] & 0xFFFF;
            a1[i * 2 + 1] = digits[i] >> 16;
        }
        rep (i, a.digits.size()) {
            a2[i * 2] = a.digits[i] & 0xFFFF;
            a2[i * 2 + 1] = a.digits[i] >> 16;
        }
        static constexpr unsigned int MOD1 = 1811939329, MOD2 = 2013265921;
        static constexpr unsigned int INV1_2 = mod_pow(MOD1, MOD2 - 2, MOD2);
        auto c1 = convolution<MOD1>(a1, a2);
        auto c2 = convolution<MOD2>(a1, a2);
        std::vector<ull> c(c1.size());
        rep (i, c1.size()) {
            ll t1 = c1[i];
            ll t2 = (c2[i] - t1 + MOD2) * INV1_2 % MOD2;
            c[i] = t1 + t2 * MOD1;
        }
        rep (i, c.size()) {
            if (c[i] >= 0x10000) {
                if (i + 1 == (int)c.size()) c.push_back(0);
                c[i + 1] += c[i] >> 16;
                c[i] &= 0xFFFF;
            }
        }
        digits.resize((c.size() + 1) / 2);
        rep (i, digits.size()) {
            digits[i] =
                c[i * 2] + (i * 2 + 1 < (int)c.size() ? c[i * 2 + 1] << 16 : 0);
        }
        normalize();
        return *this;
    }

private:
    static std::pair<BigUnsignedInteger, int> inv(const BigUnsignedInteger& a,
                                                  int deg = -1) {
        assert(!a.is_zero());
        int n = a.digits.size();
        if (deg == -1) deg = n;
        BigUnsignedInteger x;
        {
            unsigned int tmp = MAX_DIGIT / a.digits.back();
            if ((tmp + 1) * a.digits.back() == 0) ++tmp;
            x = tmp;
        }
        int e = n;
        BigUnsignedInteger two = 2;
        while (1) {
            int m = x.digits.size();
            BigUnsignedInteger a2;
            int e2 = n - m;
            if (m <= n) {
                a2.digits = std::vector<unsigned int>(a.digits.end() - m,
                                                      a.digits.end());
            }
            else {
                a2 = a << (32 * (m - n));
            }
            BigUnsignedInteger y = ((two << (32 * (e - e2))) - a2 * x) * x;
            y >>= 32 * (y.digits.size() - 2 * m);
            x <<= 32 * m;
            e += m;
            assert(x.digits.size() == y.digits.size());
            int d = -1;
            rrep (i, y.digits.size()) {
                if (x.digits[i] != y.digits[i]) {
                    d = i;
                    break;
                }
            }
            if (d < e - deg) break;
            if (d * 2 > (int)y.digits.size()) {
                e -= d * 2 - y.digits.size();
                y >>= 32 * (d * 2 - y.digits.size());
            }
            x = std::move(y);
            // print << ":" << x.digits << ":" << e << ":" << (x * a) >> (32 *
            // (e - 1))).digits << endl;
        }
        x = x >> (32 * (x.digits.size() - deg));
        e = n + deg - 1;
        return {std::move(x), e};
    }

public:
    friend std::pair<BigUnsignedInteger, BigUnsignedInteger>
    divmod(const BigUnsignedInteger& a, const BigUnsignedInteger& b) {
        assert(!b.is_zero());
        auto [inv_b, e] = inv(b, a.digits.size() + 1);
        // print << inv_b.digits << endl;
        // print << (inv_b * b).digits << endl;
        BigUnsignedInteger q = (a * inv_b) >> (32 * e), r = a - q * b;
        if (r >= b) {
            ++q;
            r -= b;
        }
        return {std::move(q), std::move(r)};
    }
    BigUnsignedInteger& operator/=(const BigUnsignedInteger& a) {
        return *this = divmod(*this, a).first;
    }
    BigUnsignedInteger& operator%=(const BigUnsignedInteger& a) {
        return *this = divmod(*this, a).second;
    }

    friend BigUnsignedInteger operator+(const BigUnsignedInteger& a,
                                        const BigUnsignedInteger& b) {
        return BigUnsignedInteger(a) += b;
    }
    friend BigUnsignedInteger operator-(const BigUnsignedInteger& a,
                                        const BigUnsignedInteger& b) {
        return BigUnsignedInteger(a) -= b;
    }
    friend BigUnsignedInteger operator*(const BigUnsignedInteger& a,
                                        const BigUnsignedInteger& b) {
        return BigUnsignedInteger(a) *= b;
    }
    friend BigUnsignedInteger operator/(const BigUnsignedInteger& a,
                                        const BigUnsignedInteger& b) {
        return BigUnsignedInteger(a) /= b;
    }
    friend BigUnsignedInteger operator%(const BigUnsignedInteger& a,
                                        const BigUnsignedInteger& b) {
        return BigUnsignedInteger(a) %= b;
    }
};

class BigInteger {
private:
    bool sgn;
    BigUnsignedInteger val;

public:
    BigInteger() : sgn(false), val{} {}
    BigInteger(ll a) : sgn(a < 0), val(std::abs(a)) {}
    BigInteger(const BigUnsignedInteger& a) : sgn(false), val(a) {}
    BigInteger(bool sg, const BigUnsignedInteger& a) : sgn(sg), val(a) {}
    BigInteger(const std::string& s) { set_hex(s); }
    void set_hex(const std::string& s) {
        if (!s.empty() && s[0] == '-') {
            sgn = true;
            val.set_hex(s.substr(1));
        }
        else {
            sgn = false;
            val.set_hex(s);
        }
    }
    std::string to_hex() const {
        if (val.is_zero()) return "0";
        return (sgn ? "-" : "") + val.to_hex();
    }

    BigInteger operator+() const { return *this; }
    BigInteger operator-() const {
        BigInteger res = *this;
        res.sgn = !res.sgn;
        return res;
    }

    BigInteger& operator+=(const BigInteger& a) {
        if (sgn == a.sgn) {
            val += a.val;
        }
        else {
            if (val < a.val) {
                sgn = a.sgn;
                val = a.val - val;
            }
            else {
                val -= a.val;
            }
        }
        return *this;
    }
    BigInteger& operator-=(const BigInteger& a) { return *this += -a; }
    BigInteger& operator*=(const BigInteger& a) {
        if (a.sgn) sgn = !sgn;
        val *= a.val;
        return *this;
    }
    BigInteger& operator/=(const BigInteger& a) {
        if (a.sgn) sgn = !sgn;
        val /= a.val;
        return *this;
    }
    BigInteger& operator%=(const BigInteger& a) {
        if (a.sgn) sgn = !sgn;
        val %= a.val;
        return *this;
    }

    friend BigInteger operator+(const BigInteger& a, const BigInteger& b) {
        return BigInteger(a) += b;
    }
    friend BigInteger operator-(const BigInteger& a, const BigInteger& b) {
        return BigInteger(a) -= b;
    }
    friend BigInteger operator*(const BigInteger& a, const BigInteger& b) {
        return BigInteger(a) *= b;
    }
    friend std::pair<BigInteger, BigInteger> divmod(const BigInteger& a,
                                                    const BigInteger& b) {
        auto [q, r] = divmod(a.val, b.val);
        return {BigInteger{a.sgn != b.sgn, q}, BigInteger{a.sgn, r}};
    }
    friend BigInteger operator/(const BigInteger& a, const BigInteger& b) {
        return BigInteger(a) /= b;
    }
    friend BigInteger operator%(const BigInteger& a, const BigInteger& b) {
        return BigInteger(a) %= b;
    }
};

template<class Iterator, std::size_t decimal_precision>
void scan_hex(Scanner<Iterator, decimal_precision>& sc, BigUnsignedInteger& a) {
    std::string s;
    sc >> s;
    a.set_hex(s);
}
template<class Iterator, std::size_t decimal_precision>
void scan_hex(Scanner<Iterator, decimal_precision>& sc, BigInteger& a) {
    std::string s;
    sc >> s;
    a.set_hex(s);
}

template<class Iterator, bool debug>
void print_hex(Printer<Iterator, debug>& pr, const BigUnsignedInteger& a) {
    pr.print(a.to_hex());
}
template<class Iterator, bool debug>
void print_hex(Printer<Iterator, debug>& pr, const BigInteger& a) {
    pr.print(a.to_hex());
}
