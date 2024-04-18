#pragma once

#include "../../other/template.hpp"
#include "../../other/monoid.hpp"
#include "LazySegmentTree.hpp"

template<class M_> class RangeAssignSegmentTree {
    static_assert(Monoid::is_monoid<M_>::value, "M must be monoid");

private:
    using T = typename M_::value_type;
    struct Act {
        using M = M_;
        using E = Monoid::Assign<T*>;
        static T mul_op(T* const& a, int b, const T&) {
            return *(a + bitop::ceil_log2(b));
        }
    };
    int n;
    LazySegmentTree<Act> seg;
    std::vector<T> memo;
    int cnt = 0;

public:
    RangeAssignSegmentTree() : RangeAssignSegmentTree(0) {}
    RangeAssignSegmentTree(int n)
        : RangeAssignSegmentTree(std::vector<T>(n, M_::id())) {}
    RangeAssignSegmentTree(int n, const T& v)
        : RangeAssignSegmentTree(std::vector<T>(n, v)) {}
    RangeAssignSegmentTree(const std::vector<T>& v)
        : n(v.size()), seg(v), memo(n) {}
    template<class Upd> void update(int k, const Upd& upd) {
        seg.update(k, upd);
    }
    void set(int l, int r, const T& x) {
        assert(0 <= l && l <= r && r <= n);
        int s = r - l;
        if (s == 0) return;
        int p = bitop::msb(s) + 1;
        if (cnt + p > n) {
            cnt = 0;
            seg.eval_all();
        }
        memo[cnt] = x;
        rep (i, p - 1) memo[cnt + i + 1] = M_::op(memo[cnt + i], memo[cnt + i]);
        seg.apply(l, r, memo.data() + cnt);
        cnt += p;
    }
    void set(int k, const T& x) { seg.set(k, x); }
    T prod(int l, int r) { return seg.prod(l, r); }
    T get(int k) { return seg.get(k); }
    T all_prod() { return seg.all_prod(); }
    template<class F> int max_right(int l, F f) { return seg.max_right(l, f); }
    template<class F> int min_left(int r, F f) { return seg.min_left(r, f); }
};

/**
 * @brief RangeAssignSegmentTree
 * @docs docs/data-struct/segment/RangeAssignSegmentTree.
 * @see https://noshi91.hatenablog.com/entry/2019/10/05/203704
 */
