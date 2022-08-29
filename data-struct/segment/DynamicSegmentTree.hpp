#pragma once

#include "../../other/template.hpp"
#include "../../other/monoid.hpp"

template<class M> class DynamicSegmentTree {
private:
    using T = typename M::value_type;
    struct node;
    using node_ptr = std::unique_ptr<node>;
    struct node {
        T val;
        node_ptr l, r;
        node(const T& v) : val(v), l(nullptr), r(nullptr) {}
    };
    node_ptr& get_l(const node_ptr& nd, ll a, ll b, int t) const {
        if (nd->l == nullptr) nd->l = std::make_unique<node>(get_init(a, b, t));
        return nd->l;
    }
    node_ptr& get_r(const node_ptr& nd, ll a, ll b, int t) const {
        if (nd->r == nullptr) nd->r = std::make_unique<node>(get_init(a, b, t));
        return nd->r;
    }
    ll ori, h, n;
    node_ptr root;
    bool is_id;
    std::vector<T> iv, iv2;
    template<class Upd>
    void update(node_ptr& nd, ll a, ll b, int t, ll k, const Upd& upd) {
        if (nd == nullptr) nd = std::make_unique<node>(get_init(a, b, t));
        if (a + 1 == b) {
            nd->val = upd(nd->val);
            return;
        }
        ll m = (a + b) >> 1;
        if (k < m) update(nd->l, a, m, t - 1, k, upd);
        else update(nd->r, m, b, t - 1, k, upd);
        nd->val = M::op(nd->l ? nd->l->val : get_init(a, m, t - 1),
                        nd->r ? nd->r->val : get_init(m, b, t - 1));
    }
    T prod(const node_ptr& nd, ll a, ll b, int t, ll l, ll r) const {
        if (l <= a && b <= r) return nd->val;
        if (r <= a || b <= l) return M::id();
        ll m = (a + b) >> 1;
        return M::op(prod(get_l(nd, a, m, t - 1), a, m, t - 1, l, r),
                     prod(get_r(nd, m, b, t - 1), m, b, t - 1, l, r));
    }
    template<class Cond>
    ll max_right(const node_ptr& nd, ll a, ll b, int t, ll l, const Cond& cond,
                 T& sm) const {
        if (b <= l) return n;
        if (l <= a && cond(M::op(sm, nd->val))) {
            sm = M::op(sm, nd->val);
            return n;
        }
        if (a + 1 == b) return a;
        ll m = (a + b) >> 1;
        ll res = max_right(get_l(nd, a, m, t - 1), a, m, t - 1, l, cond, sm);
        if (res != n) return res;
        return max_right(get_r(nd, m, b, t - 1), m, b, t - 1, l, cond, sm);
    }
    template<class Cond>
    ll min_left(const node_ptr& nd, ll a, ll b, int t, ll r, const Cond& cond,
                T& sm) const {
        if (r <= a) return 0;
        if (b <= r && cond(M::op(nd->val, sm))) {
            sm = M::op(nd->val, sm);
            return 0;
        }
        if (a + 1 == b) return b;
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
        nd = std::make_unique<node>(src->val);
        init_copy(nd->l, src->l);
        init_copy(nd->r, src->r);
    }
    template<bool AlwaysTrue = true,
             typename std::enable_if<!Monoid::has_init<M>::value &&
                                     AlwaysTrue>::type* = nullptr>
    void init_iv(const T& v) {
        iv.reserve(h + 1);
        iv.push_back(v);
        rep (h) iv.push_back(M::op(iv.back(), iv.back()));
        iv2.assign(h + 1, M::id());
        rep (i, h) {
            if ((ori >> i) & 1) iv2[i + 1] = M::op(iv2[i], iv[i]);
            else iv2[i + 1] = iv2[i];
        }
    }
    template<bool AlwaysTrue = true,
             typename std::enable_if<!Monoid::has_init<M>::value &&
                                     AlwaysTrue>::type* = nullptr>
    T get_init(ll, ll r, int t) const {
        return is_id ? M::id() : (r <= ori ? iv[t] : iv2[t]);
    }
    template<bool AlwaysTrue = true,
             typename std::enable_if<Monoid::has_init<M>::value &&
                                     AlwaysTrue>::type* = nullptr>
    void init_iv(const T&) {}
    template<bool AlwaysTrue = true,
             typename std::enable_if<Monoid::has_init<M>::value &&
                                     AlwaysTrue>::type* = nullptr>
    T get_init(ll l, ll r, int) const {
        return M::init(l, std::min(r, ori));
    }

public:
    DynamicSegmentTree() : DynamicSegmentTree(inf) {}
    DynamicSegmentTree(ll n_) { init(n_); }
    DynamicSegmentTree(ll n_, const T& v) { init(n_, v); }
    DynamicSegmentTree(const DynamicSegmentTree& other)
        : ori(other.ori), h(other.h), n(other.n),
          root(std::make_unique<node>(other.root->val)), is_id(other.is_id),
          iv(other.iv), iv2(other.iv2) {
        init_copy(root, other.root);
    }
    DynamicSegmentTree(DynamicSegmentTree&& other) = default;
    DynamicSegmentTree& operator=(const DynamicSegmentTree& other) {
        if (this == &other) return *this;
        return (*this) = DynamicSegmentTree(other);
    }
    DynamicSegmentTree& operator=(DynamicSegmentTree&& other) = default;
    void init(ll n_) {
        ori = n_;
        h = bitop::ceil_log2(ori);
        n = 1ull << h;
        is_id = true;
        root = std::make_unique<node>(get_init(0, n, h));
    }
    void init(ll n_, const T& v) {
        ori = n_;
        h = bitop::ceil_log2(ori);
        n = 1ull << h;
        is_id = false;
        init_iv(v);
        root = std::make_unique<node>(get_init(0, n, h));
    }
    template<class Upd> void update(ll k, const Upd& upd) {
        assert(0 <= k && k < ori);
        update(root, 0, n, h, k, upd);
    }
    void set(ll k, T x) {
        update(k, [&](T) -> T { return x; });
    }
    void apply(ll k, T x) {
        update(k, [&](T a) -> T { return M::op(a, x); });
    }
    T prod(ll l, ll r) const {
        assert(0 <= l && l <= r && r <= ori);
        return prod(root, 0, n, h, l, r);
    }
    T all_prod() const { return root->val; }
    T get(ll k) const { return prod(k, k + 1); }
    template<class Cond> ll max_right(ll l, const Cond& cond) const {
        assert(0 <= l && l <= ori);
        if (l == n) return n;
        T sm = M::id();
        assert(cond(sm));
        return std::min(max_right(root, 0, n, h, l, cond, sm), ori);
    }
    template<class Cond> ll min_left(ll r, const Cond& cond) const {
        assert(0 <= r && r <= ori);
        if (0 == r) return 0;
        T sm = M::id();
        assert(cond(sm));
        return min_left(root, 0, n, h, r, cond, sm);
    }
    void reset(ll l, ll r) { reset(root, 0, n, h, l, r); }
    void reset(ll k) { reset(root, 0, n, h, k, k + 1); }
};

/**
 * @brief DynamicSegmentTree(動的セグメント木)
 * @docs docs/data-struct/segment/DynamicSegmentTree.md
 */
