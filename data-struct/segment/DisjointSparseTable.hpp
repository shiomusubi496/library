#pragma once

#include "../../other/template.hpp"
#include "../../other/bitop.hpp"

template<class T> class DisjointSparseTable {
  protected:
    using F = std::function<T(T, T)>;
    F op;
    int h, ori;
    std::vector<int> logtable;
    std::vector<T> v_;
    std::vector<std::vector<T>> data;
  public:
    DisjointSparseTable() = default;
    DisjointSparseTable(const std::vector<T>& v, const F& op) : op(op) { init(v); }
    void init(const std::vector<T>& v) {
        v_ = v;
        ori = v.size();
        h = bitop::ceil_log2(ori);
        logtable.assign(1 << h, 0);
        rep (i, 2, 1 << h) logtable[i] = logtable[i >> 1] + 1;
        data.assign(h, std::vector<T>(ori));
        rep (i, 0, h) {
            int len = 1 << i;
            rep (j, len, ori, len << 1) {
                data[i][j - 1] = v[j - 1];
                rep (k, 1, len) data[i][j - k - 1] = op(v[j - k - 1], data[i][j - k]);
                data[i][j] = v[j];
                rep (k, 1, len) {
                    if (j + k >= ori) break;
                    data[i][j + k] = op(data[i][j + k - 1], v[j + k]);
                }
            }
        }
    }
    T query(int l, int r) {
        assert(0 <= l && l < r && r <= ori);
        --r;
        if (l == r) return v_[l];
        int d = logtable[l ^ r];
        return op(data[d][l], data[d][r]);
    }
};

/**
 * @brief DisjointSparseTable
 * @docs docs/DisjointSparseTable.md
 */
