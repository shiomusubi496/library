#pragma once

#include "../../other/template.hpp"
#include "../../other/monoid.hpp"

template<class M> class CumulativeSumAnyOperation {
private:
    using T = typename M::value_type;
    int n;
    std::vector<T> data;

public:
    CumulativeSumAnyOperation() = default;
    CumulativeSumAnyOperation(const std::vector<T>& v) { init(v); }
    void init(const std::vector<T>& v) {
        n = v.size();
        data.assign(n + 1, M::id());
        rep (i, n) data[i + 1] = M::op(data[i], v[i]);
    }
    template<bool AlwaysTrue = true,
             typename std::enable_if<Monoid::has_inv<M>::value &&
                                     AlwaysTrue>::type* = nullptr>
    T prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= n);
        return M::inv(data[r], data[l]);
    }
    const std::vector<T>& get_data() const& { return data; }
    std::vector<T> get_data() && { return std::move(data); }
};

template<class T>
using CumulativeSum = CumulativeSumAnyOperation<Monoid::Sum<T>>;

/**
 * @brief CumulativeSum(累積和)
 * @docs docs/CumulativeSum.md
 */
