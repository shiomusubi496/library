#pragma once

#include "../template.hpp"

template<class T> class CumulativeSum {
  protected:
    using F = std::function<T(T, T)>;
    using G = std::function<T()>;
    using H = std::function<T(T)>;
    F op;
    G e;
    H inv;
    int n;
    std::vector<T> data;
  public:
    CumulativeSum() = default;
    CumulativeSum(const std::vector<T>& v) : CumulativeSum(v, [](T a, T b) -> T { return a + b; }, []() -> T { return 0; }, [](T a) -> T { return -a; }) {}
    CumulativeSum(const std::vector<T>& v, const F& op, const G& e, const H& inv) : op(op), e(e), inv(inv) { init(v); }
    void init(const std::vector<T>& v) {
        n = v.size();
        data.assign(n + 1, e());
        rep (i, n) data[i + 1] = op(data[i], v[i]);
    }
    T query(int l, int r) {
        assert(0 <= l && l <= r && r <= n);
        return op(data[r], inv(data[l]));
    }
};

/**
 * @brief CumulativeSum(累積和)
 * @docs docs/CumulativeSum.md
 */
