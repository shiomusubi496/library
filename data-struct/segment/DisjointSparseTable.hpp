#pragma once

#include "../template.hpp"

template<class T> class DisjointSparseTable {
  protected:
    using F = std::function<T(T, T)>;
    int h;
    F op;
    std::vector<int> logtable;
    std::vector<std::vector<T>> data;
  public:
    DisjointSparseTable() = default;
    DisjointSparseTable(const std::vector<T>& v, const F& op) : op(op) { init(v); }
    void init(const std::vector<T>& v) {
        h = 1;
        while ((1 << h) < (int)v.size()) ++h;
        logtable.assign(1 << h, 0);
        rep (i, 2, 1 << h) logtable[i] = logtable[i >> 1] + 1;
        data.assign(h, std::vector<T>(1 << h));
        rep (i, v.size()) data[0][i] = v[i];
        rep (i, 1, h) {
            int len = 1 << i;
            rep (j, len, v.size(), len << 1) {
                data[i][j - 1] = v[j - 1];
                rep (k, 1, len) data[i][j - k - 1] = op(v[j - k - 1], data[i][j - k]);
                data[i][j] = v[j];
                rep (k, 1, len) {
                    if (j + k >= (int)v.size()) break;
                    data[i][j + k] = op(data[i][j + k - 1], v[j + k]);
                }
            }
        }
    }
    T query(int l, int r) {
        assert(0 <= l && l < r && r <= (1 << h));
        --r;
        if (l == r) return data[0][l];
        int d = logtable[l ^ r];
        return op(data[d][l], data[d][r]);
    }
};

/**
 * @brief DisjointSparseTable
 * @docs docs/DisjointSparseTable.md
 */
