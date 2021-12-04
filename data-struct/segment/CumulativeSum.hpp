#pragma once

#include "../../other/template.hpp"

template<class T, class F = std::function<T(T, T)>, class G = std::function<T(T, T)>> class CumulativeSum {
  protected:
    F op;
    T e;
    G inv;
    int n;
    std::vector<T> data;
  public:
    CumulativeSum() = default;
    CumulativeSum(const std::vector<T>& v)
        : CumulativeSum(v, [](T a, T b) -> T { return a + b; },
                        T(0), [](T a, T b) -> T { return a - b; }) {}
    CumulativeSum(const std::vector<T>& v, const F& op, const T& e, const G& inv) : op(op), e(e), inv(inv) { init(v); }
    void init(const std::vector<T>& v) {
        n = v.size();
        data.assign(n + 1, e);
        rep (i, n) data[i + 1] = op(data[i], v[i]);
    }
    T query(int l, int r) const {
        assert(0 <= l && l <= r && r <= n);
        return inv(data[r], data[l]);
    }
    std::vector<T> get_data() const { return data; }
};

/**
 * @brief CumulativeSum(累積和)
 * @docs docs/CumulativeSum.md
 */
