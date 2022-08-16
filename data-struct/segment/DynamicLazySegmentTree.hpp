#pragma once

#include "../../other/template.hpp"
#include "../../other/bitop.hpp"
#include "../../other/monoid.hpp"

template<class A, bool = Monoid::has_mul_op<A>::value>
class DynamicLazySegmentTree {
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
    node_ptr& get_l(const node_ptr& nd, ll l, ll r, int t) const {
        if (nd->l == nullptr) nd->l = std::make_unique<node>(get_init(l, r, t));
        return nd->l;
    }
    node_ptr& get_r(const node_ptr& nd, ll l, ll r, int t) const {
        if (nd->r == nullptr) nd->r = std::make_unique<node>(get_init(l, r, t));
        return nd->r;
    }
    void all_apply(node_ptr& nd, int t, const U& x) {
        nd->val = A::op(x, nd->val);
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
            all_apply(get_l(nd, a, m, t - 1), t - 1, nd->lazy);
            all_apply(get_r(nd, m, b, t - 1), t - 1, nd->lazy);
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
        if (k < m) update(get_l(nd, a, m, t - 1), a, m, t - 1, k, upd);
        else update(get_r(nd, m, b, t - 1), m, b, t - 1, k, upd);
        nd->val = M::op(nd->l ? nd->l->val : get_init(a, m, t - 1),
                        nd->r ? nd->r->val : get_init(m, b, t - 1));
    }
    T prod(node_ptr& nd, ll a, ll b, int t, ll l, ll r) {
        if (r <= a || b <= l) return M::id();
        if (l <= a && b <= r) return nd->val;
        eval(nd, a, b, t);
        ll m = (a + b) >> 1;
        return M::op(
            r > a && m > l ? prod(get_l(nd, a, m, t - 1), a, m, t - 1, l, r)
                           : M::id(),
            r > m && b > l ? prod(get_r(nd, m, b, t - 1), m, b, t - 1, l, r)
                           : M::id());
    }
    void apply(node_ptr& nd, ll a, ll b, int t, ll l, ll r, const U& x) {
        if (r <= a || b <= l) return;
        if (l <= a && b <= r) {
            all_apply(nd, t, x);
            return;
        }
        eval(nd, a, b, t);
        ll m = (a + b) >> 1;
        apply(get_l(nd, a, m, t - 1), a, m, t - 1, l, r, x);
        apply(get_r(nd, m, b, t - 1), m, b, t - 1, l, r, x);
        nd->val = M::op(nd->l ? nd->l->val : get_init(a, m, t - 1),
                        nd->r ? nd->r->val : get_init(m, b, t - 1));
    }
    template<class Cond>
    ll max_right(node_ptr& nd, ll a, ll b, int t, ll l, const Cond& cond,
                 T& sm) {
        if (b <= l) return n;
        if (l <= a && cond(M::op(sm, nd->val))) {
            sm = M::op(sm, nd->val);
            return n;
        }
        if (a + 1 == b) return a;
        eval(nd, a, b, t);
        ll m = (a + b) >> 1;
        ll res = max_right(get_l(nd, a, m, t - 1), a, m, t - 1, l, cond, sm);
        if (res != n) return res;
        return max_right(get_r(nd, m, b, t - 1), m, b, t - 1, l, cond, sm);
    }
    template<class Cond>
    ll min_left(node_ptr& nd, ll a, ll b, int t, ll r, const Cond& cond,
                T& sm) {
        if (r <= a) return 0;
        if (b <= r && cond(M::op(nd->val, sm))) {
            sm = M::op(nd->val, sm);
            return 0;
        }
        if (a + 1 == b) return b;
        eval(nd, a, b, t);
        ll m = (a + b) >> 1;
        ll res = min_left(get_r(nd, m, b, t - 1), m, b, t - 1, r, cond, sm);
        if (res != 0) return res;
        return min_left(get_l(nd, a, m, t - 1), a, m, t - 1, r, cond, sm);
    }
    void reset(node_ptr& nd, ll a, ll b, int t, ll l, ll r) {
        if (nd == nullptr) return;
        if (r <= a || b <= l) return;
        if (l <= a && b <= r) {
            if (nd == root) nd = std::make_unique<node>(get_init(0, n, h));
            else nd.reset();
            return;
        }
        ll m = (a + b) >> 1;
        reset(nd->l, a, m, t - 1, l, r);
        reset(nd->r, m, b, t - 1, l, r);
        nd->val = M::op(nd->l ? nd->l->val : get_init(a, m, t - 1),
                        nd->r ? nd->r->val : get_init(m, b, t - 1));
    }
    void init_copy(node_ptr& nd, const node_ptr& src) {
        if (src == nullptr) return;
        if (src->lazyflag) nd = std::make_unique<node>(src->val, src->lazy);
        else nd = std::make_unique<node>(src->val);
        init_copy(nd->l, src->l);
        init_copy(nd->r, src->r);
    }
    template<bool AlwaysTrue = true,
             typename std::enable_if<!Monoid::has_init<M>::value &&
                                     AlwaysTrue>::type* = nullptr>
    void init_iv(const T& v) {
        iv.reserve(this->h + 1);
        iv.push_back(v);
        rep (this->h) iv.push_back(M::op(iv.back(), iv.back()));
        iv2.assign(this->h + 1, M::id());
        rep (i, this->h) {
            if ((this->ori >> i) & 1) iv2[i + 1] = M::op(iv2[i], iv[i]);
            else iv2[i + 1] = iv2[i];
        }
    }
    template<bool AlwaysTrue = true,
             typename std::enable_if<!Monoid::has_init<M>::value &&
                                     AlwaysTrue>::type* = nullptr>
    T get_init(ll, ll r, int t) const {
        return r <= this->ori ? iv[t] : iv2[t];
    }
    template<bool AlwaysTrue = true,
             typename std::enable_if<Monoid::has_init<M>::value &&
                                     AlwaysTrue>::type* = nullptr>
    void init_iv(const T&) {}
    template<bool AlwaysTrue = true,
             typename std::enable_if<Monoid::has_init<M>::value &&
                                     AlwaysTrue>::type* = nullptr>
    T get_init(ll l, ll r, int) const {
        return M::init(l, std::min(r, this->ori));
    }

public:
    DynamicLazySegmentTree() : DynamicLazySegmentTree(inf) {}
    DynamicLazySegmentTree(ll n_) { init(n_); }
    DynamicLazySegmentTree(ll n_, const T& v) { init(n_, v); }
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
    void init(ll n_, const T& v = M::id()) {
        ori = n_;
        h = bitop::ceil_log2(ori);
        n = 1ull << h;
        init_iv(v);
        root = std::make_unique<node>(get_init(0, n, h));
    }
    template<class Upd> void update(ll k, const Upd& upd) {
        assert(0 <= k && k < ori);
        update(root, 0, n, h, k, upd);
    }
    void set(ll k, T x) {
        update(k, [&](const T&) -> T { return x; });
    }
    void apply(ll k, const U& x) {
        update(k, [&](const T& a) -> T { return A::op(a, x); });
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
};


template<class A> class DynamicLazySegmentTree<A, true> {
protected:
    using M_ = typename A::M;
    using E_ = typename A::E;
    using T_ = typename M_::value_type;
    using U_ = typename E_::value_type;
    using elm = typename Monoid::MultiAction<A>::M::value_type;
    DynamicLazySegmentTree<Monoid::MultiAction<A>> seg;

public:
    DynamicLazySegmentTree() : DynamicLazySegmentTree(inf) {}
    DynamicLazySegmentTree(ll n_) : seg(n_, {M_::id(), 1}) {}
    DynamicLazySegmentTree(ll n_, const T_& v) : seg(n_, {v, 1}) {}
    void init(ll n_, const T_& v = M_::id()) { seg.init(n_, {v, 1}); }
    T_ prod(ll l, ll r) { return seg.prod(l, r).val; }
    T_ get(ll k) { return seg.get(k).val; }
    T_ all_prod() const { return seg.all_prod().val; }
    template<class Upd> void update(ll k, const Upd& upd) {
        seg.update(k, [&](const elm& a) -> elm { return {upd(a.val), a.len}; });
    }
    void set(ll k, T_ x) { seg.set(k, elm{x, 1}); }
    void apply(ll k, U_ x) { seg.apply(k, x); }
    void apply(ll l, ll r, U_ x) { seg.apply(l, r, x); }
    template<class C> ll max_right(ll l, const C& cond) {
        return seg.max_right(l,
                             [&](const elm& a) -> bool { return cond(a.val); });
    }
    template<class C> ll min_left(ll r, const C& cond) {
        return seg.min_left(r,
                            [&](const elm& a) -> bool { return cond(a.val); });
    }
    void reset(ll l, ll r) { seg.reset(l, r); }
    void reset(ll k) { seg.reset(k); }
};

/**
 * @brief DynamicLazySegmentTree(動的遅延セグメント木)
 * @docs docs/data-struct/segment/DynamicLazySegmentTree.md
 */
