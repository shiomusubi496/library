#pragma once

#include "../../other/template.hpp"
#include "../../other/bitop.hpp"
#include "../../other/monoid.hpp"

namespace lib_shiomusubi {

template<class M> class DynamicSegmentTreeBase {
  protected:
    using T = typename M::value_type;
    struct node;
    using node_ptr = std::unique_ptr<node>;
    struct node {
        T val;
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
        node(const T& v) : val(v), l(nullptr), r(nullptr) {}
    };
    ll ori, h, n;
    node_ptr root;
    template<class Upd> void update(node_ptr& nd, ll a, ll b, int t, ll k, const Upd& upd) {
        if (a + 1 == b) {
            nd->val = upd(nd->val);
            return;
        }
        ll m = (a + b) >> 1;
        if (k < m) update(nd->get_l(get_init(a, m, t - 1)), a, m, t - 1, k, upd);
        else update(nd->get_r(get_init(m, b, t - 1)), m, b, t - 1, k, upd);
        nd->update();
    }
    T prod(const node_ptr& nd, ll a, ll b, int t, ll l, ll r) const {
        if (l <= a && b <= r) return nd->val;
        if (r <= a || b <= l) return M::id();
        ll m = (a + b) >> 1;
        return M::op(prod(nd->get_l(get_init(a, m, t - 1)), a, m, t - 1, l, r),
                    prod(nd->get_r(get_init(m, b, t - 1)), m, b, t - 1, l, r));
    }
    template<class Cond> ll max_right(const node_ptr& nd, ll a, ll b, int t, ll l, const Cond& cond, T& sm) const {
        if (b <= l) return n;
        if (l <= a && cond(M::op(sm, nd->val))) {
            sm = M::op(sm, nd->val);
            return n;
        }
        if (a + 1 == b) return a;
        ll m = (a + b) >> 1;
        ll res = max_right(nd->get_l(get_init(a, m, t - 1)), a, m, t - 1, l, cond, sm);
        if (res != n) return res;
        return max_right(nd->get_r(get_init(m, b, t - 1)), m, b, t - 1, l, cond, sm);
    }
    template<class Cond> ll min_left(const node_ptr& nd, ll a, ll b, int t, ll r, const Cond& cond, T& sm) const {
        if (r <= a) return 0;
        if (b <= r && cond(M::op(nd->val, sm))) {
            sm = M::op(nd->val, sm);
            return 0;
        }
        if (a + 1 == b) return b;
        ll m = (a + b) >> 1;
        ll res = min_left(nd->get_r(get_init(m, b, t - 1)), m, b, t - 1, r, cond, sm);
        if (res != 0) return res;
        return min_left(nd->get_l(get_init(a, b, t - 1)), a, m, t - 1, r, cond, sm);
    }
    void reset(node_ptr& nd, ll a, ll b, ll l, ll r) {
        if (nd == nullptr) return;
        if (r <= a || b <= l) return;
        if (l <= a && b <= r) {
            if (nd == root) nd = std::make_unique<node>(get_init(0, n, h));
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
        nd = std::make_unique<node>(src->val);
        init_copy(nd->l, src->l);
        init_copy(nd->r, src->r);
    }
    virtual void init_iv(const T& v) = 0;
    virtual T get_init(ll l, ll r, int t) const = 0;
  public:
    DynamicSegmentTreeBase() = default;
    DynamicSegmentTreeBase(const DynamicSegmentTreeBase& other)
            : n(other.n), h(other.h), ori(other.ori),
            root(std::make_unique<node>(other.root->val)) {
        init_copy(root, other.root);
    }
    DynamicSegmentTreeBase(DynamicSegmentTreeBase&&) = default;
    DynamicSegmentTreeBase& operator=(const DynamicSegmentTreeBase& other) {
        if (this == &other) return *this;
        return (*this) = DynamicSegmentTreeBase(other);
    }
    DynamicSegmentTreeBase& operator=(DynamicSegmentTreeBase&&) = default;
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
    void reset(ll l, ll r) { reset(root, 0, n, l, r); }
    void reset(ll k) { reset(root, 0, n, k, k + 1); }
};

} // namespace lib_shiomusubi


template<class M, class F = void> class DynamicSegmentTree : public lib_shiomusubi::DynamicSegmentTreeBase<M> {
  protected:
    using Base = lib_shiomusubi::DynamicSegmentTreeBase<M>;
    using T = typename Base::T;
    F f;
    void init_iv(const T& v) override {}
    T get_init(ll l, ll r, int t) const override {
        return f(l, std::min(r, this->ori));
    }
  public:
    DynamicSegmentTree() = delete;
    DynamicSegmentTree(const F& f) : DynamicSegmentTree(inf, f) {}
    DynamicSegmentTree(ll n_, const F& f) : f(f) { this->init(n_); }
    DynamicSegmentTree(const DynamicSegmentTree& other)
            : f(other.iv2), Base(other) {}
    DynamicSegmentTree(DynamicSegmentTree&&) = default;
    DynamicSegmentTree& operator=(const DynamicSegmentTree& other) {
        if (this == &other) return *this;
        return (*this) = DynamicSegmentTree(other);
    }
    DynamicSegmentTree& operator=(DynamicSegmentTree&&) = default;
};

template<class M> class DynamicSegmentTree<M, void> : public lib_shiomusubi::DynamicSegmentTreeBase<M> {
  protected:
    using Base = lib_shiomusubi::DynamicSegmentTreeBase<M>;
    using T = typename Base::T;
    std::vector<T> iv, iv2;
    void init_iv(const T& v) override {
        iv.reserve(this->h + 1); iv.push_back(v);
        rep (this->h) iv.push_back(M::op(iv.back(), iv.back()));
        iv2.assign(this->h + 1, M::id());
        rep (i, this->h) {
            if ((this->ori >> i) & 1) iv2[i + 1] = M::op(iv2[i], iv[i]);
            else iv2[i + 1] = iv2[i];
        }
    }
    T get_init(ll l, ll r, int t) const override {
        return r <= this->ori ? iv[t] : iv2[t];
    }
  public:
    DynamicSegmentTree() : DynamicSegmentTree(inf) {}
    DynamicSegmentTree(ll n_) { this->init(n_); }
    DynamicSegmentTree(ll n_, const T& v) { this->init(n_, v); }
    DynamicSegmentTree(const DynamicSegmentTree& other)
            : iv(other.iv), iv2(other.iv2), Base(other) {}
    DynamicSegmentTree(DynamicSegmentTree&&) = default;
    DynamicSegmentTree& operator=(const DynamicSegmentTree& other) {
        if (this == &other) return *this;
        return (*this) = DynamicSegmentTree(other);
    }
    DynamicSegmentTree& operator=(DynamicSegmentTree&&) = default;
};

/**
 * @brief DynamicSegmentTree(動的セグメント木)
 * @docs docs/DynamicSegmentTree.md
 */
