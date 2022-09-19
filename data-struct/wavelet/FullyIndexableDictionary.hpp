#pragma once

#include "../../other/template.hpp"

class FullyIndexableDictionary {
private:
    int n, b;
    std::vector<unsigned int> bit, sm;

public:
    FullyIndexableDictionary() = default;
    FullyIndexableDictionary(int n) : n(n), b((n >> 5) + 1), bit(b), sm(b) {}
    void set(int i) { bit[i >> 5] |= 1U << (i & 31); }
    bool get(int i) const { return (bool)((bit[i >> 5] >> (i & 31)) & 1); }
    bool operator[](int i) const { return get(i); }
    void build() {
        rep (i, b - 1) sm[i + 1] = sm[i] + popcnt(bit[i]);
    }
    int rank(int i) const {
        return sm[i >> 5] + popcnt(bit[i >> 5] & ((1U << (i & 31)) - 1));
    }
    int rank(bool x, int i) const { return x ? rank(i) : i - rank(i); }
    int select(bool x, int i) const {
        int l = -1, r = n;
        while (r - l > 1) {
            int m = (l + r) >> 1;
            if (rank(x, m) < i) l = m;
            else r = m;
        }
        return l + 1;
    }
};

/**
 * @brief FullyIndexableDictionary(完備辞書)
 * @docs docs/data-struct/wavelet/FullyIndexableDictionary.md
 */
