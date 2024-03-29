#pragma once

#include "../../other/template.hpp"
#include "../../other/monoid.hpp"

template<class M> class SparseTable {
private:
    using T = typename M::value_type;
    int h, ori;
    std::vector<int> logtable;
    std::vector<std::vector<T>> data;
    T internal_prod(int l, int r) const {
        assert(0 <= l && l < r && r <= ori);
        int d = logtable[r - l];
        return M::op(data[d][l], data[d][r - (1 << d)]);
    }

public:
    SparseTable() = default;
    SparseTable(const std::vector<T>& v) { init(v); }
    void init(const std::vector<T>& v) {
        ori = v.size();
        h = bitop::ceil_log2(ori);
        logtable.assign((1 << h) + 1, 0);
        reps (i, 1, 1 << h) logtable[i] = logtable[i >> 1] + 1;
        data.assign(h + 1, std::vector<T>(1 << h));
        rep (i, ori) data[0][i] = v[i];
        rep (i, h) {
            rep (j, (1 << h) - (1 << i)) {
                data[i + 1][j] = M::op(data[i][j], data[i][j + (1 << i)]);
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
 * @brief SparseTable
 * @docs docs/data-struct/segment/SparseTable.md
 */
