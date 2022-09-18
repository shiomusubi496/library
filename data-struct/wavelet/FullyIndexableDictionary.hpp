#pragma once

#include "../../other/template.hpp"

class FullyIndexableDictionary {
private:
    int n, b;
    std::vector<unsigned int> bit, sm;
public:
    FullyIndexableDictionary() = default;
    FullyIndexableDictionary(int n) : n(n), b((n >> 5) + 1), bit(b), sm(b) {}
    void set(int i) {
        bit[i >> 5] |= 1U << (i & 31);
    }
    void build() {
        rep (i, b - 1) sm[i + 1] = sm[i] + popcnt(bit[i]);
    }
    int rank(int i) const {
        return sm[i >> 5] + popcnt(bit[i >> 5] & ((1U << (i & 31)) - 1));
    }
    int rank(bool x, int i) const {
        return x ? rank(i) : i - rank(i);
    }
};

/**
 * @brief FullyIndexableDictionary(完備辞書)
 * @docs docs/data-struct/wavelet/FullyIndexableDictionary.md
 */
