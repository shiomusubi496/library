#pragma once

#include "../../other/template.hpp"
#include "../../other/monoid.hpp"

template<class A> class StarrySkyTree {
private:
    using M = typename A::M;
    using E = typename A::E;
    using T = typename M::value_type;
    static_assert(std::is_same<T, typename E::value_type>::value,
                  "monoid and effector must have same value_type");
    int n;
    std::vector<T> dat;

    void apply_(int k, int a, int b, int l, int r, T x) {
        if (l <= a && b <= r) {
            dat[k] = E::op(dat[k], x);
            return;
        }
        if (r <= a || b <= l) return;
        int m = (a + b) / 2;
        apply_(k * 2 + 0, a, m, l, r, x);
        apply_(k * 2 + 1, m, b, l, r, x);
        T mn = M::op(dat[k * 2 + 0], dat[k * 2 + 1]);
        dat[k * 2 + 0] = E::inv(dat[k * 2 + 0], mn);
        dat[k * 2 + 1] = E::inv(dat[k * 2 + 1], mn);
        dat[k] = E::op(dat[k], mn);
    }

    T prod_(int k, int a, int b, int l, int r, T x) const {
        if (l <= a && b <= r) return x;
        if (r <= a || b <= l) return M::id();
        int m = (a + b) / 2;
        return M::op(prod_(k * 2 + 0, a, m, l, r, x + dat[k * 2 + 0]),
                     prod_(k * 2 + 1, m, b, l, r, x + dat[k * 2 + 1]));
    }

public:
    StarrySkyTree() = default;
    StarrySkyTree(int n_, T x = E::id()) {
        n = 1;
        while (n < n_) n *= 2;
        dat.assign(2 * n, E::id());
        dat[1] = x;
    }
    void apply(int l, int r, T x) { apply_(1, 0, n, l, r, x); }
    T prod(int l, int r) const { return prod_(1, 0, n, l, r, dat[1]); }
};
