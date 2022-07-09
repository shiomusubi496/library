#pragma once

#include "../../other/template.hpp"
#include "../../other/bitop.hpp"
#include "../../other/monoid.hpp"

template<class A, bool = Monoid::has_mul_op<A>::value>
class DynamicLazySegmentTree {
protected:
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
        node_ptr& get_l(const T& v) {
            if (l == nullptr) l = std::make_unique<node>(v);
            return l;
        }
        node_ptr& get_r(const T& v) {
            if (r == nullptr) r = std::make_unique<node>(v);
            return r;
        }
        void update() {
            val = M::id();
            if (l != nullptr) val = M::op(val, l->val);
            if (r != nullptr) val = M::op(val, r->val);
        }
        node(const T& v) : val(v), lazyflag(false), l(nullptr), r(nullptr) {}
        node(const T& v, const U& x)
            : val(v), lazy(x), lazyflag(true), l(nullptr), r(nullptr) {}
    };
    void all_apply(node_ptr& p, int t, const U& x) {
        p->val = A::op(x, p->val);
        if (t != 0) {
            if (p->lazyflag) {
                p->lazy = E::op(p->lazy, x);
            }
            else {
                p->lazy = x;
                p->lazyflag = true;
            }
        }
    }
    void eval(node_ptr& p, ll a, ll b, int t) {
        if (p->lazyflag) {
            ll m = (a + b) >> 1;
            all_apply(p->get_l(m <= ori ? iv[t - 1] : iv2[t - 1]), t - 1,
                      p->lazy);
            all_apply(p->get_r(b <= ori ? iv[t - 1] : iv2[t - 1]), t - 1,
                      p->lazy);
            p->lazyflag = false;
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
        if (k < m) {
            update(nd->get_l(m <= ori ? iv[t - 1] : iv2[t - 1]), a, m, t - 1, k,
                   upd);
        } else {
            update(nd->get_r(b <= ori ? iv[t - 1] : iv2[t - 1]), m, b, t - 1, k,
                   upd);
        }
        nd->update();
    }
    T prod(node_ptr& nd, ll a, ll b, int t, ll l, ll r) {
        if (nd == nullptr) return M::id();
        if (l <= a && b <= r) return nd->val;
        if (r <= a || b <= l) return M::id();
        eval(nd, a, b, t);
        ll m = (a + b) >> 1;
        return M::op(prod(nd->l, a, m, t - 1, l, r),
                     prod(nd->r, m, b, t - 1, l, r));
    }
    void apply(node_ptr& nd, ll a, ll b, int t, ll l, ll r, const U& x) {
        if (l <= a && b <= r) {
            all_apply(nd, t, x);
            return;
        }
        if (r <= a || b <= l) return;
        eval(nd, a, b, t);
        ll m = (a + b) >> 1;
        apply(nd->get_l(m <= ori ? iv[t - 1] : iv2[t - 1]), a, m, t - 1, l, r,
              x);
        apply(nd->get_r(b <= ori ? iv[t - 1] : iv2[t - 1]), m, b, t - 1, l, r,
              x);
        nd->update();
    }
    template<class Cond>
    ll max_right(node_ptr& nd, ll a, ll b, int t, ll l, const Cond& cond,
                 T& sm) {
        if (nd == nullptr || b <= l) return n;
        if (l <= a && cond(M::op(sm, nd->val))) {
            sm = M::op(sm, nd->val);
            return n;
        }
        eval(nd, a, b, t);
        if (a + 1 == b) return a;
        ll m = (a + b) >> 1;
        ll res = max_right(nd->l, a, m, t - 1, l, cond, sm);
        if (res != n) return res;
        return max_right(nd->r, m, b, t - 1, l, cond, sm);
    }
    template<class Cond>
    ll min_left(node_ptr& nd, ll a, ll b, int t, ll r, const Cond& cond,
                T& sm) {
        if (nd == nullptr || r <= a) return 0;
        if (b <= r && cond(M::op(nd->val, sm))) {
            sm = M::op(nd->val, sm);
            return 0;
        }
        eval(nd, a, b, t);
        if (a + 1 == b) return b;
        ll m = (a + b) >> 1;
        ll res = min_left(nd->r, m, b, t - 1, r, cond, sm);
        if (res != 0) return res;
        return min_left(nd->l, a, m, t - 1, r, cond, sm);
    }
    void reset(node_ptr& nd, ll a, ll b, ll l, ll r) {
        if (nd == nullptr) return;
        if (r <= a || b <= l) return;
        if (l <= a && b <= r) {
            if (nd == root) nd = std::make_unique<node>(iv2[h]);
            else nd.reset();
            return;
        }
        ll m = (a + b) >> 1;
        reset(nd->l, a, m, l, r);
        reset(nd->r, m, b, l, r);
        nd->update();
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
    DynamicLazySegmentTree(ll n_, const T& v) { init(n_, v); }
    DynamicLazySegmentTree(const DynamicLazySegmentTree& other)
        : n(other.n), h(other.h), ori(other.ori), iv(other.iv), iv2(other.iv2),
          root(std::make_unique<node>(other.root->val)) {
        init_copy(root, other.root);
    }
    DynamicLazySegmentTree(DynamicLazySegmentTree&&) = default;
    DynamicLazySegmentTree& operator=(const DynamicLazySegmentTree& other) {
        if (this == &other) return *this;
        n = other.n;
        h = other.h;
        ori = other.ori;
        iv = other.iv;
        iv2 = other.iv2;
        root = std::make_unique<node>(other.root->val);
        init_copy(root, other.root);
        return *this;
    }
    DynamicLazySegmentTree& operator=(DynamicLazySegmentTree&&) = default;
    void init(ll n_, const T& v = M::id()) {
        ori = n_;
        h = bitop::ceil_log2(ori);
        n = 1ull << h;
        iv.reserve(h + 1);
        iv.push_back(v);
        rep (h) iv.push_back(M::op(iv.back(), iv.back()));
        iv2.assign(h + 1, M::id());
        rep (i, h) {
            if ((ori >> i) & 1) iv2[i + 1] = M::op(iv2[i], iv[i]);
            else iv2[i + 1] = iv2[i];
        }
        if (ori == n) iv2[h] = M::op(iv2[h], iv[h]);
        root = std::make_unique<node>(iv2[h]);
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
    void reset(ll l, ll r) { reset(root, 0, n, l, r); }
    void reset(ll k) { reset(root, 0, n, k, k + 1); }
};


template<class A> class DynamicLazySegmentTree<A, true> {
protected:
    using M_ = typename A::M;
    using E_ = typename A::E;
    using T_ = typename M_::value_type;
    using U_ = typename E_::value_type;
    struct MultiA {
        struct M {
            struct value_type {
                T_ val;
                ll len;
                value_type() = default;
                value_type(T_ v, ll l) : val(v), len(l) {}
                friend std::ostream& operator<<(std::ostream& ost,
                                                const value_type& e) {
                    return ost << e.val << '*' << e.len;
                }
            };
            static value_type op(const value_type& a, const value_type& b) {
                return {M_::op(a.val, b.val), a.len + b.len};
            }
            static value_type id() { return {M_::id(), 0}; }
        };
        using E = E_;
        using T = typename M::value_type;
        using U = typename E::value_type;
        static T op(const U& a, const T& b) {
            return {A::mul_op(a, b.len, b.val), b.len};
        }
    };
    using elm = typename MultiA::M::value_type;
    DynamicLazySegmentTree<MultiA> seg;

public:
    DynamicLazySegmentTree() : DynamicLazySegmentTree(inf) {}
    DynamicLazySegmentTree(ll n_) : seg(n_, {M_::id(), 1}) {}
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
};

/**
 * @brief DynamicLazySegmentTree(動的遅延セグメント木)
 * @docs docs/DynamicLazySegmentTree.md
 */
