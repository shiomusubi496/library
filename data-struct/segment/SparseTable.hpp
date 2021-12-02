#pragma once

#include "../../other/template.hpp"
#include "../../other/bitop.hpp"

template<class T, class F = std::function<T(T, T)>> class SparseTable {
  protected:
    F op;
    int h, ori;
    std::vector<int> logtable;
    std::vector<std::vector<T>> data;
  public:
    SparseTable() = default;
    SparseTable(const std::vector<T>& v, const F& op) : op(op) { init(v); }
    void init(const std::vector<T>& v) {
        ori = v.size();
        h = bitop::ceil_log2(ori);
        logtable.assign((1 << h) + 1, 0);
        reps (i, 1, 1 << h) logtable[i] = logtable[i >> 1] + 1;
        data.assign(h + 1, std::vector<T>(1 << h));
        rep (i, ori) data[0][i] = v[i];
        rep (i, h) {
            rep (j, (1 << h) - (1 << i)) {
                data[i + 1][j] = op(data[i][j], data[i][j + (1 << i)]);
            }
        }
    }
    T query(int l, int r) {
        assert(0 <= l && l < r && r <= ori);
        int d = logtable[r - l];
        return op(data[d][l], data[d][r - (1 << d)]);
    }
};

/**
 * @brief SparseTable
 * @docs docs/SparseTable.md
 */
