#pragma once

#include "../../other/template.hpp"
#include "../../other/monoid.hpp"

template<class M> class DisjointSparseTable {
private:
    using T = typename M::value_type;
    int h, ori;
    std::vector<int> logtable;
    std::vector<T> v_;
    std::vector<std::vector<T>> data;
    T internal_prod(int l, int r) const {
        assert(0 <= l && l < r && r <= ori);
        --r;
        if (l == r) return v_[l];
        int d = logtable[l ^ r];
        return M::op(data[d][l], data[d][r]);
    }

public:
    DisjointSparseTable() = default;
    DisjointSparseTable(const std::vector<T>& v) { init(v); }
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
                rep (k, 1, len)
                    data[i][j - k - 1] = M::op(v[j - k - 1], data[i][j - k]);
                data[i][j] = v[j];
                rep (k, 1, len) {
                    if (j + k >= ori) break;
                    data[i][j + k] = M::op(data[i][j + k - 1], v[j + k]);
                }
            }
        }
    }
    template<bool AlwaysTrue = true,
             typename std::enable_if<Monoid::has_id<M>::value &&
                                     AlwaysTrue>::type* = nullptr>
    T prod(int l, int r) const {
        if (l == r) return M::id();
        return internal_prod(l, r);
    }
    template<bool AlwaysTrue = true,
             typename std::enable_if<!Monoid::has_id<M>::value &&
                                     AlwaysTrue>::type* = nullptr>
    T prod(int l, int r) const {
        return internal_prod(l, r);
    }
};

/**
 * @brief DisjointSparseTable
 * @docs docs/data-struct/segment/DisjointSparseTable.md
 */
