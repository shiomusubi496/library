#pragma once

#include "../other/template.hpp"

namespace internal {

constexpr int NIM_PROD_TABLE_SIZE = 1 << 8;

ull nim_prod_table[NIM_PROD_TABLE_SIZE][NIM_PROD_TABLE_SIZE];

bool nim_prod_inited = false;

void nim_prod_init() {
    if (nim_prod_inited) return;
    nim_prod_inited = true;

    nim_prod_table[1][1] = 1;
    for (int sz = 2; sz <= 8; sz <<= 1) {
        const ull A = 1ull << sz;
        const int sz2 = sz >> 1;
        const ull B = 1ull << sz2;
        const ull mask = B - 1;
        for (ull a = 0; a < A; ++a) {
            for (ull b = 0; b < A; ++b) {
                if (a < B && b < B) continue;
                ull a0 = a & mask, a1 = a >> sz2;
                ull b0 = b & mask, b1 = b >> sz2;
                ull a0b0 = nim_prod_table[a0][b0];
                ull a0b1 = nim_prod_table[a0][b1];
                ull a1b0 = nim_prod_table[a1][b0];
                ull a1b1 = nim_prod_table[a1][b1];
                nim_prod_table[a][b] = ((a1b1 ^ a0b1 ^ a1b0) << sz2) ^
                                       nim_prod_table[a1b1][1ull << (sz2 - 1)] ^
                                       a0b0;
            }
        }
    }
}

} // namespace internal

ull nim_product(ull a, ull b, int sz = 64) {
    if (a == 0 || b == 0) return 0;
    if (a == 1) return b;
    if (b == 1) return a;
    internal::nim_prod_init();
    if (a < 256 && b < 256) return internal::nim_prod_table[a][b];
    int sz2 = sz >> 1;
    if (a < (1ull << sz2) && b < (1ull << sz2)) {
        return nim_product(a, b, sz2);
    }
    ull mask = (1ull << sz2) - 1;
    ull a0 = a & mask, a1 = a >> sz2;
    ull b0 = b & mask, b1 = b >> sz2;
    ull x = nim_product(a0, b0, sz2);
    ull y = nim_product(a1, b1, sz2);
    ull z = nim_product(a0 ^ a1, b0 ^ b1, sz2);
    return ((z ^ x) << sz2) ^ nim_product(y, 1ull << (sz2 - 1), sz2) ^ x;
}
