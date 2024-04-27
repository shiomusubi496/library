#pragma once

#include "../../other/template.hpp"
#include "../../other/monoid.hpp"

template<class A> class DynamicLazySegmentTree {
private:
    using M = typename A::M;
    using E = typename A::E;
    using T = typename M::value_type;
    using U = typename E::value_type;
    struct node;
    using node_ptr = std::unique_ptr<node>;
    struct node {
        T val;
        U lazy;
        bool lazyflag;
        node_ptr l, r;
        node(const T& v) : val(v), lazyflag(false), l(nullptr), r(nullptr) {}
        node(const T& v, const U& x)
            : val(v), lazy(x), lazyflag(true), l(nullptr), r(nullptr) {}
    };
    node_ptr& get_l(const node_ptr& nd) const {
        if (nd->l == nullptr) nd->l = std::make_unique<node>(M::id());
        return nd->l;
    }
    node_ptr& get_r(const node_ptr& nd) const {
        if (nd->r == nullptr) nd->r = std::make_unique<node>(M::id());
        return nd->r;
    }

    template<bool AlwaysTrue = true,
             typename std::enable_if<!Monoid::has_mul_op<A>::value &&
                                     AlwaysTrue>::type* = nullptr>
    static inline T Aop(const U& a, const T& b, ll) {
        return A::op(a, b);
    }
    template<bool AlwaysTrue = true,
             typename std::enable_if<Monoid::has_mul_op<A>::value &&
                                     AlwaysTrue>::type* = nullptr>
    static inline T Aop(const U& a, const T& b, ll c) {
        return A::mul_op(a, c, b);
    }

    void all_apply(node_ptr& nd, int t, const U& x, ll d) {
        nd->val = Aop(x, nd->val, d);
        if (t != 0) {
            if (nd->lazyflag) {
                nd->lazy = E::op(nd->lazy, x);
            }
            else {
                nd->lazy = x;
                nd->lazyflag = true;
            }
        }
    }
    void eval(node_ptr& nd, ll a, ll b, int t) {
        if (nd->lazyflag) {
            ll m = (a + b) >> 1;
            all_apply(get_l(nd), t - 1, nd->lazy, m - a);
            all_apply(get_r(nd), t - 1, nd->lazy, b - m);
            nd->lazyflag = false;
        }
    }
    ll ori, h, n;
    std::vector<T> iv, iv2;
    node_ptr root;
    template<class Upd>
    void update(node_ptr& nd, ll a, ll b, int t, ll k, const Upd& upd) {
        if (a + 1 == b) {
            nd->val = upd(nd->val);
            return;
        }
        eval(nd, a, b, t);
        ll m = (a + b) >> 1;
        if (k < m) update(get_l(nd), a, m, t - 1, k, upd);
        else update(get_r(nd), m, b, t - 1, k, upd);
        nd->val =
            M::op(nd->l ? nd->l->val : M::id(), nd->r ? nd->r->val : M::id());
    }
    T prod(node_ptr& nd, ll a, ll b, int t, ll l, ll r) {
        if (nd == nullptr) return M::id();
        if (r <= a || b <= l) return M::id();
        if (l <= a && b <= r) return nd->val;
        eval(nd, a, b, t);
        ll m = (a + b) >> 1;
        return M::op(prod(nd->l, a, m, t - 1, l, r),
                     prod(nd->r, m, b, t - 1, l, r));
    }
    void apply(node_ptr& nd, ll a, ll b, int t, ll l, ll r, const U& x) {
        if (r <= a || b <= l) return;
        if (l <= a && b <= r) {
            all_apply(nd, t, x, b - a);
            return;
        }
        eval(nd, a, b, t);
        ll m = (a + b) >> 1;
        apply(get_l(nd), a, m, t - 1, l, r, x);
        apply(get_r(nd), m, b, t - 1, l, r, x);
        nd->val =
            M::op(nd->l ? nd->l->val : M::id(), nd->r ? nd->r->val : M::id());
    }
    template<class Cond>
    ll max_right(node_ptr& nd, ll a, ll b, int t, ll l, const Cond& cond,
                 T& sm) {
        if (b <= l || nd == nullptr) return n;
        if (l <= a && cond(M::op(sm, nd->val))) {
            sm = M::op(sm, nd->val);
            return n;
        }
        if (a + 1 == b) return a;
        eval(nd, a, b, t);
        ll m = (a + b) >> 1;
        ll res = max_right(nd->l, a, m, t - 1, l, cond, sm);
        if (res != n) return res;
        return max_right(nd->r, m, b, t - 1, l, cond, sm);
    }
    template<class Cond>
    ll min_left(node_ptr& nd, ll a, ll b, int t, ll r, const Cond& cond,
                T& sm) {
        if (r <= a || nd == nullptr) return 0;
        if (b <= r && cond(M::op(nd->val, sm))) {
            sm = M::op(nd->val, sm);
            return 0;
        }
        if (a + 1 == b) return b;
        eval(nd, a, b, t);
        ll m = (a + b) >> 1;
        ll res = min_left(nd->r, m, b, t - 1, r, cond, sm);
        if (res != 0) return res;
        return min_left(nd->l, a, m, t - 1, r, cond, sm);
    }
    void reset(node_ptr& nd, ll a, ll b, int t, ll l, ll r) {
        if (nd == nullptr) return;
        if (r <= a || b <= l) return;
        if (l <= a && b <= r) {
            if (nd == root) nd = std::make_unique<node>(M::id());
            else nd.reset();
            return;
        }
        ll m = (a + b) >> 1;
        reset(nd->l, a, m, t - 1, l, r);
        reset(nd->r, m, b, t - 1, l, r);
        nd->val =
            M::op(nd->l ? nd->l->val : M::id(), nd->r ? nd->r->val : M::id());
    }
    void merge(node_ptr& nd, ll a, ll b, int t, node_ptr& other) {
        if (nd == nullptr) {
            nd = std::move(other);
            return;
        }
        if (other == nullptr) return;
        if (nd->l == nullptr && nd->r == nullptr) {
            nd->val = M::op(nd->val, other->val);
            return;
        }
        eval(nd, a, b, t);
        eval(other, a, b, t);
        ll m = (a + b) >> 1;
        merge(nd->l, a, m, t - 1, other->l);
        merge(nd->r, m, b, t - 1, other->r);
        nd->val =
            M::op(nd->l ? nd->l->val : M::id(), nd->r ? nd->r->val : M::id());
    }
    void split(node_ptr& nd, ll a, ll b, int t, node_ptr& other, ll k) {
        if (nd == nullptr) return;
        if (a >= k) {
            other = std::move(nd);
            nd = nullptr;
            return;
        }
        if (b <= k) return;
        other = std::make_unique<node>(M::id());
        eval(nd, a, b, t);
        eval(other, a, b, t);
        ll m = (a + b) >> 1;
        split(nd->l, a, m, t - 1, other->l, k);
        split(nd->r, m, b, t - 1, other->r, k);
        if (nd->l == nullptr && nd->r == nullptr) nd = nullptr;
        else {
            nd->val = M::op(nd->l ? nd->l->val : M::id(),
                            nd->r ? nd->r->val : M::id());
        }
        if (other->l == nullptr && other->r == nullptr) other = nullptr;
        else {
            other->val = M::op(other->l ? other->l->val : M::id(),
                               other->r ? other->r->val : M::id());
        }
    }
    void init_copy(node_ptr& nd, const node_ptr& src) {
        if (src == nullptr) return;
        if (src->lazyflag) nd = std::make_unique<node>(src->val, src->lazy);
        else nd = std::make_unique<node>(src->val);
        init_copy(nd->l, src->l);
        init_copy(nd->r, src->r);
    }

public:
    DynamicLazySegmentTree() : DynamicLazySegmentTree(inf) {}
    DynamicLazySegmentTree(ll n_) { init(n_); }
    DynamicLazySegmentTree(ll n_, const T& v) { init(n_); }
    DynamicLazySegmentTree(const DynamicLazySegmentTree& other)
        : n(other.n), h(other.h), ori(other.ori), iv(other.iv), iv2(other.iv2),
          root(std::make_unique<node>(other.root->val)) {
        init_copy(root, other.root);
    }
    DynamicLazySegmentTree(DynamicLazySegmentTree&& other) = default;
    DynamicLazySegmentTree& operator=(const DynamicLazySegmentTree& other) {
        if (this == &other) return *this;
        return (*this) = DynamicLazySegmentTree(other);
    }
    DynamicLazySegmentTree& operator=(DynamicLazySegmentTree&& other) = default;
    void init(ll n_) {
        ori = n_;
        h = bitop::ceil_log2(ori);
        n = 1ull << h;
        root = std::make_unique<node>(M::id());
    }
    template<class Upd> void update(ll k, const Upd& upd) {
        assert(0 <= k && k < ori);
        update(root, 0, n, h, k, upd);
    }
    void set(ll k, T x) {
        update(k, [&](const T&) -> T { return x; });
    }
    void apply(ll k, const U& x) {
        update(k, [&](const T& a) -> T { return A::op(x, a); });
    }
    void apply(ll l, ll r, const U& x) {
        assert(0 <= l && l <= r && r <= ori);
        apply(root, 0, n, h, l, r, x);
    }
    void all_apply(const U& x) { apply(root, 0, n, h, 0, n, x); }
    T prod(ll l, ll r) {
        assert(0 <= l && l <= r && r <= ori);
        return prod(root, 0, n, h, l, r);
    }
    T all_prod() const { return root->val; }
    T get(ll k) { return prod(k, k + 1); }
    template<class Cond> ll max_right(ll l, const Cond& cond) {
        assert(0 <= l && l <= ori);
        if (l == n) return n;
        T sm = M::id();
        assert(cond(sm));
        return std::min(max_right(root, 0, n, h, l, cond, sm), ori);
    }
    template<class Cond> ll min_left(ll r, const Cond& cond) {
        assert(0 <= r && r <= ori);
        if (0 == r) return 0;
        T sm = M::id();
        assert(cond(sm));
        return min_left(root, 0, n, h, r, cond, sm);
    }
    void reset(ll l, ll r) { reset(root, 0, n, h, l, r); }
    void reset(ll k) { reset(root, 0, n, h, k, k + 1); }
    DynamicLazySegmentTree& merge(DynamicLazySegmentTree&& other) {
        assert(ori == other.ori);
        merge(root, 0, n, h, other.root);
        other.root = std::make_unique<node>(M::id());
        return *this;
    }
    friend DynamicLazySegmentTree merge(DynamicLazySegmentTree&& a,
                                        DynamicLazySegmentTree&& b) {
        return std::move(a.merge(std::move(b)));
    }
    friend std::pair<DynamicLazySegmentTree, DynamicLazySegmentTree>
    split(DynamicLazySegmentTree&& a, ll k) {
        assert(0 <= k && k <= a.ori);
        DynamicLazySegmentTree b(a.ori);
        a.split(a.root, 0, a.n, a.h, b.root, k);
        return {std::move(a), std::move(b)};
    }
};

/**
 * @brief DynamicLazySegmentTree(動的遅延セグメント木)
 * @docs docs/data-struct/segment/DynamicLazySegmentTree.md
 */
