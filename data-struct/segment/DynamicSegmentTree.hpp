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
    node_ptr& get_l(const node_ptr& nd) const {
        if (nd->l == nullptr) nd->l = std::make_unique<node>(M::id());
        return nd->l;
    }
    node_ptr& get_r(const node_ptr& nd) const {
        if (nd->r == nullptr) nd->r = std::make_unique<node>(M::id());
        return nd->r;
    }
    ll ori, n;
    node_ptr root;
    template<class Upd>
    void update(node_ptr& nd, ll a, ll b, ll k, const Upd& upd) {
        if (a + 1 == b) {
            nd->val = upd(nd->val);
            return;
        }
        ll m = (a + b) >> 1;
        if (k < m) update(get_l(nd), a, m, k, upd);
        else update(get_r(nd), m, b, k, upd);
        nd->val =
            M::op(nd->l ? nd->l->val : M::id(), nd->r ? nd->r->val : M::id());
    }
    T prod(const node_ptr& nd, ll a, ll b, ll l, ll r) const {
        if (nd == nullptr) return M::id();
        if (l <= a && b <= r) return nd->val;
        if (r <= a || b <= l) return M::id();
        ll m = (a + b) >> 1;
        return M::op(prod(nd->l, a, m, l, r), prod(nd->r, m, b, l, r));
    }
    template<class Cond>
    ll max_right(const node_ptr& nd, ll a, ll b, ll l, const Cond& cond,
                 T& sm) const {
        if (b <= l || nd == nullptr) return n;
        if (l <= a && cond(M::op(sm, nd->val))) {
            sm = M::op(sm, nd->val);
            return n;
        }
        if (a + 1 == b) return a;
        ll m = (a + b) >> 1;
        ll res = max_right(nd->l, a, m, l, cond, sm);
        if (res != n) return res;
        return max_right(nd->r, m, b, l, cond, sm);
    }
    template<class Cond>
    ll min_left(const node_ptr& nd, ll a, ll b, ll r, const Cond& cond,
                T& sm) const {
        if (r <= a || nd == nullptr) return 0;
        if (b <= r && cond(M::op(nd->val, sm))) {
            sm = M::op(nd->val, sm);
            return 0;
        }
        if (a + 1 == b) return b;
        ll m = (a + b) >> 1;
        ll res = min_left(nd->r, m, b, r, cond, sm);
        if (res != 0) return res;
        return min_left(nd->l, a, m, r, cond, sm);
    }
    void reset(node_ptr& nd, ll a, ll b, ll l, ll r) {
        if (nd == nullptr) return;
        if (r <= a || b <= l) return;
        if (l <= a && b <= r) {
            if (nd == root) nd = std::make_unique<node>(M::id());
            else nd.reset();
            return;
        }
        ll m = (a + b) >> 1;
        reset(nd->l, a, m, l, r);
        reset(nd->r, m, b, l, r);
        nd->val =
            M::op(nd->l ? nd->l->val : M::id(), nd->r ? nd->r->val : M::id());
    }
    void merge(node_ptr& nd, ll a, ll b, node_ptr& other) {
        if (other == nullptr) return;
        if (nd == nullptr) {
            nd = std::move(other);
            return;
        }
        if (a + 1 == b) {
            nd->val = M::op(nd->val, other->val);
            return;
        }
        ll m = (a + b) >> 1;
        merge(nd->l, a, m, other->l);
        merge(nd->r, m, b, other->r);
        nd->val =
            M::op(nd->l ? nd->l->val : M::id(), nd->r ? nd->r->val : M::id());
    }
    void split(node_ptr& nd, ll a, ll b, node_ptr& other, ll k) {
        if (nd == nullptr) return;
        if (a >= k) {
            other = std::move(nd);
            nd = nullptr;
            return;
        }
        if (b <= k) return;
        other = std::make_unique<node>(M::id());
        ll m = (a + b) >> 1;
        split(nd->l, a, m, other->l, k);
        split(nd->r, m, b, other->r, k);
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
        nd = std::make_unique<node>(src->val);
        init_copy(nd->l, src->l);
        init_copy(nd->r, src->r);
    }

public:
    DynamicSegmentTree() : DynamicSegmentTree(inf) {}
    DynamicSegmentTree(ll n_) { init(n_); }
    DynamicSegmentTree(const DynamicSegmentTree& other)
        : ori(other.ori), n(other.n),
          root(std::make_unique<node>(other.root->val)) {
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
        n = 1ull << bitop::ceil_log2(ori);
        root = std::make_unique<node>(M::id());
    }
    template<class Upd> void update(ll k, const Upd& upd) {
        assert(0 <= k && k < ori);
        update(root, 0, n, k, upd);
    }
    void set(ll k, T x) {
        update(k, [&](T) -> T { return x; });
    }
    void apply(ll k, T x) {
        update(k, [&](T a) -> T { return M::op(a, x); });
    }
    T prod(ll l, ll r) const {
        assert(0 <= l && l <= r && r <= ori);
        return prod(root, 0, n, l, r);
    }
    T all_prod() const { return root->val; }
    T get(ll k) const { return prod(k, k + 1); }
    template<class Cond> ll max_right(ll l, const Cond& cond) const {
        assert(0 <= l && l <= ori);
        if (l == n) return n;
        T sm = M::id();
        assert(cond(sm));
        return std::min(max_right(root, 0, n, l, cond, sm), ori);
    }
    template<class Cond> ll min_left(ll r, const Cond& cond) const {
        assert(0 <= r && r <= ori);
        if (0 == r) return 0;
        T sm = M::id();
        assert(cond(sm));
        return min_left(root, 0, n, r, cond, sm);
    }
    void reset(ll l, ll r) { reset(root, 0, n, l, r); }
    void reset(ll k) { reset(root, 0, n, k, k + 1); }
    void reset() { root = std::make_unique<node>(M::id()); }
    DynamicSegmentTree& merge(DynamicSegmentTree&& other) {
        assert(ori == other.ori);
        merge(root, 0, n, other.root);
        other.root = std::make_unique<node>(M::id());
        return *this;
    }
    friend DynamicSegmentTree merge(DynamicSegmentTree&& a,
                                    DynamicSegmentTree&& b) {
        return std::move(a.merge(std::move(b)));
    }
    friend std::pair<DynamicSegmentTree, DynamicSegmentTree>
    split(DynamicSegmentTree&& a, ll k) {
        assert(0 <= k && k <= a.ori);
        DynamicSegmentTree b(a.ori);
        if (k == 0) return {std::move(b), std::move(a)};
        if (k == a.ori) return {std::move(a), std::move(b)};
        a.split(a.root, 0, a.n, b.root, k);
        return {std::move(a), std::move(b)};
    }
};

/**
 * @brief DynamicSegmentTree(動的セグメント木)
 * @docs docs/data-struct/segment/DynamicSegmentTree.md
 */
