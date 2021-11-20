#pragma once

#include "template.hpp"

namespace bitop {

#define KTH_BIT(b, k) (((b) >> (k)) & 1)
#define POW2(k) (1ull << (k))

    inline ull next_combination(int n, ull x) {
        if (n == 0) return 1;
        ull a = x & -x;
        ull b = x + a;
        return (x & ~b) / a >> 1 | b;
    }

#define rep_comb(i, n, k) for (ull i = (1ull << (k)) - 1; i < (1ull << (n)); i = bitop::next_combination((n), i))

    inline constexpr int msb(ull x) {
        return ((x & 0xFFFFFFFF00000000) ? 32 : 0)
            + ((x & 0xFFFF0000FFFF0000) ? 16 : 0)
            + ((x & 0xFF00FF00FF00FF00) ?  8 : 0)
            + ((x & 0xF0F0F0F0F0F0F0F0) ?  4 : 0)
            + ((x & 0xCCCCCCCCCCCCCCCC) ?  2 : 0)
            + ((x & 0xAAAAAAAAAAAAAAAA) ?  1 : 0) + (x ? 0 : -1);
    }

    inline constexpr int ceil_log2(ull x) {
        return x ? msb(x - 1) + 1 : 0;
    }
}
