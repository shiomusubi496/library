#pragma once

#include "../template.hpp"

template<class T> class SparseTable {
  protected:
    using F = std::function<T(T, T)>;
    using G = std::function<T()>;
    int h;
    const F& op;
    const G& e;
    std::vector<int> logtable;
    std::vector<std::vector<T>> data;
  public:
    SparseTable(const std::vector<T>& v, const F& _op, const G& _e) : op(_op), e(_e) {
        h = 1;
        while ((1 << h) < (int)v.size()) ++h;
        logtable.resize((1 << h) + 1, 0);
        for (int i = 2; i <= (1 << h); i++) logtable[i] = logtable[i >> 1] + 1;
        data.resize(h + 1, std::vector<T>(1 << h, e()));
        rep (i, v.size()) data[0][i] = v[i];
        rep (i, h) {
            rep (j, (1 << h) - (1 << i)) {
                data[i + 1][j] = op(data[i][j], data[i][j + (1 << i)]);
            }
        }
    }
    T query(int l, int r) {
        assert(0 <= l && l <= r && r <= (1 << h));
        if (l == r) return e();
        int d = logtable[r - l];
        return op(data[d][l], data[d][r - (1 << d)]);
    }
};
