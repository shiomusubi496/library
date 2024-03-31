#pragma once

#include "../other/template.hpp"
#include "../random/Random.hpp"
#include "../data-struct/segment/BinaryIndexedTree.hpp"

class modint61 {
private:
    ull val;
    static constexpr ull MOD = (1ull << 61) - 1;
    static constexpr ull MASK30 = (1ull << 30) - 1;
    static constexpr ull MASK31 = (1ull << 31) - 1;
    static constexpr ull MASK61 = MOD;

    static ull calc_mod(ull a) {
        ull res = (a & MASK61) + (a >> 61);
        if (res >= MOD) res -= MOD;
        return res;
    }
    static ull calc_multi(ull a, ull b) {
        ull au = a >> 31, ad = a & MASK31;
        ull bu = b >> 31, bd = b & MASK31;
        ull mid = au * bd + ad * bu;
        return calc_mod(((au * bu) << 1) + ((mid & MASK30) << 31) +
                        (mid >> 30) + ad * bd);
    }
    static ull calc_add(ull a, ull b) {
        ull res = a + b;
        if (res >= MOD) res -= MOD;
        return res;
    }

public:
    constexpr modint61() : val(0) {}
    template<class U, typename std::enable_if<is_signed_int<U>::value &&
                                              std::numeric_limits<U>::digits <=
                                                  64>::type* = nullptr>
    constexpr modint61(U v) {
        if (v >= 0) val = calc_mod(v);
        else {
            v %= static_cast<ll>(MOD);
            if (v < 0) v += static_cast<ll>(MOD);
            val = v;
        }
    }
    template<class U, typename std::enable_if<
                          is_signed_int<U>::value &&
                          64 < std::numeric_limits<U>::digits>::type* = nullptr>
    constexpr modint61(U v) {
        v %= static_cast<ll>(MOD);
        if (v < 0) v += static_cast<ll>(MOD);
        val = v;
    }
    template<class U, typename std::enable_if<is_unsigned_int<U>::value &&
                                              std::numeric_limits<U>::digits <=
                                                  64>::type* = nullptr>
    constexpr modint61(U v) : val(calc_mod(v)) {}
    template<class U, typename std::enable_if<
                          is_unsigned_int<U>::value &&
                          64 < std::numeric_limits<U>::digits>::type* = nullptr>
    constexpr modint61(U v) : val(v % MOD) {}
    ull get() const { return val; }
    static constexpr ull get_mod() { return MOD; }
    static modint61 raw(ull x) {
        modint61 res;
        res.val = x;
        return res;
    }
    modint61& operator++() {
        ++val;
        if (val == MOD) val = 0;
        return *this;
    }
    modint61 operator++(int) {
        modint61 res = *this;
        ++*this;
        return res;
    }
    modint61& operator--() {
        if (val == 0) val = MOD;
        --val;
        return *this;
    }
    modint61 operator--(int) {
        modint61 res = *this;
        --*this;
        return res;
    }
    modint61& operator+=(const modint61& other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    modint61& operator-=(const modint61& other) {
        if (val < other.val) val += MOD;
        val -= other.val;
        return *this;
    }
    modint61& operator*=(const modint61& other) {
        val = calc_multi(val, other.val);
        return *this;
    }
    modint61 pow(ll n) const {
        modint61 res = raw(1), x = *this;
        while (n > 0) {
            if (n & 1) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }
    modint61 inv() const { return pow(MOD - 2); }
    modint61& operator/=(const modint61& other) {
        *this *= other.inv();
        return *this;
    }
    friend modint61 operator+(const modint61& lhs, const modint61& rhs) {
        return modint61(lhs) += rhs;
    }
    friend modint61 operator-(const modint61& lhs, const modint61& rhs) {
        return modint61(lhs) -= rhs;
    }
    friend modint61 operator*(const modint61& lhs, const modint61& rhs) {
        return modint61(lhs) *= rhs;
    }
    friend modint61 operator/(const modint61& lhs, const modint61& rhs) {
        return modint61(lhs) /= rhs;
    }
    modint61 operator+() const { return *this; }
    modint61 operator-() const { return modint61() - *this; }
    friend bool operator==(const modint61& lhs, const modint61& rhs) {
        return lhs.val == rhs.val;
    }
    friend bool operator!=(const modint61& lhs, const modint61& rhs) {
        return lhs.val != rhs.val;
    }
    template<class Pr> void debug(Pr& a) const { a.print(val); }
};

class RollingHash {
private:
    static constexpr ull MASK31 = (1ull << 31) - 1;
    using mint = modint61;
    std::vector<mint> pows, rpows;

public:
    void init(int n) {
        const int sz = pows.size();
        if (sz <= n) {
            pows.resize(n + 1);
            rpows.resize(n + 1);
            rep (i, sz, n + 1) pows[i] = pows[i - 1] * BASE;
            rep (i, sz, n + 1) rpows[i] = rpows[i - 1] * RBASE;
        }
    }
    mint BASE, RBASE;
    void set_base() {
        BASE = mint::raw((1ull << 31) + (rand32() & MASK31));
        RBASE = BASE.inv();
    }

    mint join(mint a, mint b, ll blen) const { return a * pows[blen] + b; }

    class Hash {
    private:
        int n;
        mint BASE;
        std::vector<mint> hash, pows;

    public:
        Hash() = default;
        template<class Cont>
        Hash(mint b, const std::vector<mint>& p, const Cont& str)
            : n(str.size()), BASE(b), pows(p.begin(), p.begin() + n + 1) {
            hash.assign(n + 1, mint{});
            rep (i, n) hash[i + 1] = hash[i] * BASE + str[i];
        }
        mint prod(int l, int r) const {
            assert(0 <= l && l <= r && r <= n);
            return hash[r] - hash[l] * pows[r - l];
        }
        mint all_prod() const { return hash[n]; }
    };
    class RangeHashQuery {
    private:
        int n;
        mint BASE;
        std::vector<mint> pows, rpows;
        BinaryIndexedTree<mint> bit;

    public:
        RangeHashQuery() = default;
        template<class Cont>
        RangeHashQuery(mint b, const std::vector<mint>& p,
                       const std::vector<mint>& rp, const Cont& str)
            : n(str.size()), BASE(b), pows(p.begin(), p.begin() + n + 1),
              rpows(rp.begin(), rp.begin() + n + 1), bit(n) {
            rep (i, n) bit.add(i, str[i] * pows[i]);
        }
        mint prod(int l, int r) const { return bit.sum(l, r) * rpows[l]; }
        mint all_prod() const { return bit.sum(0, n); }
        template<class T> void set(int k, const T& x) {
            bit.set(k, x * pows[k]);
        }
    };
    RollingHash() {
        set_base();
        pows.assign(1, mint::raw(1));
        rpows.assign(1, mint::raw(1));
    }
    template<class Cont> Hash get_hash(const Cont& str) {
        init(str.size() + 1);
        return Hash(BASE, pows, str);
    }
    template<class Cont> RangeHashQuery get_range_hash(const Cont& str) {
        init(str.size() + 1);
        return RangeHashQuery(BASE, pows, rpows, str);
    }
};

/**
 * @brief RollingHash(ロリハ)
 * @docs docs/string/RollingHash.md
 */
