#pragma once

#include "../other/template.hpp"
#include "../random/Random.hpp"

class RollingHash {
  protected:
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
        return calc_mod(((au * bu) << 1) + ((mid & MASK30) << 31) + (mid >> 30) + ad * bd);
    }
    static ull calc_add(ull a, ull b) {
        ull res = a + b;
        if (res >= MOD) res -= MOD;
        return res;
    }
    ull BASE;
    void init() {
        BASE = (1ull << 31) + (rand32() & MASK31);
    }
  public:
    class Hash {
      protected:
        int n;
        ull BASE;
        std::vector<ull> hash;
        std::vector<ull> pows;
      public:
        template<class Cont> Hash(ull b, const Cont& str) : BASE(b) {
            n = str.size();
            hash.resize(n + 1);
            rep (i, n) hash[i + 1] = calc_add(calc_multi(hash[i], BASE), str[i]);
            pows.resize(n + 1); pows[0] = 1;
            rep (i, n) pows[i + 1] = calc_multi(pows[i], BASE);
        }
        ull get_hash(int l, int r) const {
            assert(0 <= l && l <= r && r <= n);
            return calc_add(hash[r], MOD - calc_multi(hash[l], pows[r - l]));
        }
        ull get_all() const {
            return hash[n];
        }
    };
    RollingHash() { init(); }
    template<class Cont> Hash get_hash(const Cont& str) const {
        return Hash(BASE, str);
    }
    ull get_base() const {
        return BASE;
    }
};

/**
 * @brief RollingHash(ロリハ)
 * @docs docs/RollingHash.md
 */
