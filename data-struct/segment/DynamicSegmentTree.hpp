#pragma once

#include "../../other/template.hpp"
#include "../../other/bitop.hpp"
#include "../../other/monoid.hpp"

template<class M> class DynamicSegmentTree {
  protected:
    using T = typename M::value_type;
    struct Node {
        T val;
        Node *l, *r;
        Node* get_l() {
            if (l == nullptr) l = new Node;
            return l;
        }
        Node* get_r() {
            if (r == nullptr) r = new Node;
            return r;
        }
        void update() {
            val = M::id();
            if (l != nullptr) val = M::op(val, l->val);
            if (r != nullptr) val = M::op(val, r->val);
        }
        Node() : val(M::id()), l(nullptr), r(nullptr) {}
    };
    ll ori, h, n;
    Node* root;
    template<class Upd> void update(Node* nd, ll a, ll b, ll k, const Upd& upd) {
        if (a + 1 == b) {
            nd->val = upd(nd->val);
            return;
        }
        ll m = (a + b) >> 1;
        if (k < m) update(nd->get_l(), a, m, k, upd);
        else update(nd->get_r(), m, b, k, upd);
        nd->update();
    }
    T prod(Node* nd, ll a, ll b, ll l, ll r) const {
        if (nd == nullptr) return M::id();
        if (l <= a && b <= r) return nd->val;
        if (r <= a || b <= l) return M::id();
        ll m = (a + b) >> 1;
        return M::op(prod(nd->l, a, m, l, r), prod(nd->r, m, b, l, r));
    }
    template<class Cond> ll max_right(Node* nd, ll a, ll b, ll l, const Cond& cond, T& sm) const {
        if (nd == nullptr || b <= l) return n;
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
    template<class Cond> ll min_left(Node* nd, ll a, ll b, ll r, const Cond& cond, T& sm) const {
        if (nd == nullptr || r <= a) return 0;
        if (b <= r && cond(M::op(nd->val, sm))) {
            sm = M::op(nd->val, sm);
            return 0;
        }
        if (a + 1 == b) return b;
        ll m = (a + b) >> 1;
        ll res = min_left(nd->l, m, b, r, cond, sm);
        if (res != 0) return res;
        return min_left(nd->r, a, m, r, cond, sm);
    }
    void del(Node* nd) {
        if (nd == nullptr) return;
        del(nd->l);
        del(nd->r);
        delete nd;
    }
  public:
    DynamicSegmentTree() : DynamicSegmentTree(inf) {}
    DynamicSegmentTree(ll n_) { init(n_); }
    ~DynamicSegmentTree() { del(root); }
    void init(ll n_) {
        ori = n_;
        h = bitop::ceil_log2(ori);
        n = 1ull << h;
        root = new Node;
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
};

/**
 * @brief DynamicSegmentTree(動的セグメント木)
 * @docs docs/DynamicSegmentTree.md
 */