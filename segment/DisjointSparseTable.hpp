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
    DisjointSparseTable(const std::vector<T>& v, const F& _op) : op(_op) {
        h = 1;
        while ((1 << h) < (int)v.size()) ++h;
        logtable.resize(1 << h, 0);
        for (int i = 2; i < (1 << h); ++i) logtable[i] = logtable[i >> 1] + 1;
        data.resize(h, std::vector<T>(1 << h));
        rep (i, h) {
            int len = 1 << i;
            for (int j = len; j < v.size(); j += (len << 1)) {
                data[i][j - 1] = v[j - 1];
                for (int k = 1; k < len; ++k) data[i][j - k - 1] = op(v[j - k - 1], data[i][j - k]);
                data[i][j] = v[j];
                for (int k = 1; k < len; ++k) {
                    if (j + k >= v.size()) break;
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
