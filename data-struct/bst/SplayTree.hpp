#pragma once

#include "../../other/template.hpp"
#include "../../other/monoid.hpp"

template<class A> class SplayTree {
private:
    using M = typename A::M;
    using E = typename A::E;
    using T = typename M::value_type;
    using U = typename E::value_type;
    struct node;
    using node_ptr = node*;
    struct node {
        T v, val, rval;
        U lazy;
        int cnt = 1;
        bool lazyflag = false, rev = false;
        node_ptr l = nullptr, r = nullptr, p = nullptr;
    };
    node_ptr root;

    template<bool AlwaysTrue = true,
             typename std::enable_if<!Monoid::has_mul_op<A>::value &&
                                     AlwaysTrue>::type* = nullptr>
    static inline T Aop(const U& a, const T& b, int) {
        return A::op(a, b);
    }
    template<bool AlwaysTrue = true,
             typename std::enable_if<Monoid::has_mul_op<A>::value &&
                                     AlwaysTrue>::type* = nullptr>
    static inline T Aop(const U& a, const T& b, int c) {
        return A::mul_op(a, c, b);
    }

    SplayTree(node_ptr ptr) : root(ptr) {}

    void all_apply(node_ptr& ptr, U x) {
        if (ptr == nullptr) return;
        ptr->v = Aop(x, ptr->v, 1);
        ptr->val = Aop(x, ptr->val, ptr->cnt);
        ptr->rval = Aop(x, ptr->rval, ptr->cnt);
        if (ptr->l || ptr->r) {
            if (ptr->lazyflag) {
                ptr->lazy = E::op(ptr->lazy, x);
            }
            else {
                ptr->lazy = x;
                ptr->lazyflag = true;
            }
        }
    }
    void all_reverse(node_ptr& ptr) {
        if (ptr == nullptr) return;
        std::swap(ptr->l, ptr->r);
        std::swap(ptr->val, ptr->rval);
        ptr->rev = !ptr->rev;
    }
    void eval(node_ptr& ptr) {
        if (ptr->rev) {
            all_reverse(ptr->l);
            all_reverse(ptr->r);
            ptr->rev = false;
        }
        if (ptr->lazyflag) {
            all_apply(ptr->l, ptr->lazy);
            all_apply(ptr->r, ptr->lazy);
            ptr->lazyflag = false;
        }
    }
    void calc(node_ptr& ptr) {
        ptr->val = M::op(ptr->l ? ptr->l->val : M::id(),
                         M::op(ptr->v, ptr->r ? ptr->r->val : M::id()));
        ptr->rval = M::op(ptr->r ? ptr->r->rval : M::id(),
                          M::op(ptr->v, ptr->l ? ptr->l->rval : M::id()));
        ptr->cnt = (ptr->l ? ptr->l->cnt : 0) + (ptr->r ? ptr->r->cnt : 0) + 1;
    }
    node_ptr& parentchild(node_ptr& ptr) {
        if (ptr == root) return root;
        return ptr->p->l == ptr ? ptr->p->l : ptr->p->r;
    }

    void rotateL(node_ptr& p) {
        node_ptr c = p->r;
        assert(c != nullptr);
        parentchild(p) = c;
        c->p = p->p;
        p->p = c;
        p->r = c->l;
        c->l = p;
        if (p->r) p->r->p = p;
    }
    void rotateR(node_ptr& p) {
        node_ptr c = p->l;
        assert(c != nullptr);
        parentchild(p) = c;
        c->p = p->p;
        p->p = c;
        p->l = c->r;
        c->r = p;
        if (p->l) p->l->p = p;
    }
    void splay(node_ptr& ptr) {
        eval(ptr);
        while (ptr != root) {
            node_ptr p = ptr->p;
            if (p == root) {
                if (p->l == ptr) rotateR(p);
                else rotateL(p);
                calc(p);
                calc(ptr);
            }
            else {
                node_ptr gp = p->p;
                if (gp->l == p) {
                    if (p->l == ptr) {
                        rotateR(gp);
                        rotateR(p);
                    }
                    else {
                        rotateL(p);
                        rotateR(gp);
                    }
                }
                else {
                    if (p->l == ptr) {
                        rotateR(p);
                        rotateL(gp);
                    }
                    else {
                        rotateL(gp);
                        rotateL(p);
                    }
                }
                calc(gp);
                calc(p);
                calc(ptr);
            }
        }
        calc(ptr);
    }

public:
    SplayTree() : root(nullptr) {}
    SplayTree(const std::vector<T>& v) : root(nullptr) {
        for (auto x : v) insert(size(), x);
    }

    int size() const { return root ? root->cnt : 0; }

    node_ptr kth_element(int k) {
        assert(0 <= k && k < size());
        node_ptr ptr = root;
        while (ptr) {
            eval(ptr);
            if (ptr->l) {
                if (ptr->l->cnt > k) {
                    ptr = ptr->l;
                    continue;
                }
                k -= ptr->l->cnt;
            }
            if (k == 0) break;
            --k;
            ptr = ptr->r;
        }
        splay(ptr);
        return ptr;
    }
    T operator[](int k) { return kth_element(k)->v; }
    void insert(int k, T x) {
        assert(0 <= k && k <= size());
        node_ptr nd = new node;
        nd->v = nd->val = nd->rval = x;
        if (root == nullptr) {
            root = nd;
            return;
        }
        if (k == size()) {
            nd->l = root;
            root->p = nd;
            root = nd;
            calc(root);
            return;
        }
        node_ptr ptr = kth_element(k);
        nd->l = ptr->l;
        if (ptr->l) ptr->l->p = nd;
        nd->r = ptr;
        ptr->p = nd;
        ptr->l = nullptr;
        calc(ptr);
        calc(nd);
        root = nd;
    }
    void erase(int k) {
        assert(0 <= k && k < size());
        node_ptr ptr = kth_element(k);
        if (ptr->l == nullptr) {
            root = ptr->r;
            if (ptr->r) ptr->r->p = nullptr;
            delete ptr;
            return;
        }
        if (ptr->r == nullptr) {
            root = ptr->l;
            ptr->l->p = nullptr;
            delete ptr;
            return;
        }
        node_ptr l = ptr->l;
        root = ptr->r;
        node_ptr nd = kth_element(0);
        nd->l = l;
        l->p = nd;
        delete ptr;
        nd->p = nullptr;
        calc(nd);
    }
    node_ptr get_range(int l, int r) {
        assert(0 <= l && l < r && r <= size());
        if (l == 0) {
            if (r == size()) return root;
            node_ptr ptr = kth_element(r);
            return ptr->l;
        }
        else if (r == size()) {
            node_ptr ptr = kth_element(l - 1);
            return ptr->r;
        }
        node_ptr pr = kth_element(r);
        root = pr->l;
        pr->l->p = nullptr;
        node_ptr pl = kth_element(l - 1);
        root = pr;
        pr->l = pl;
        pl->p = pr;
        calc(pr);
        return pl->r;
    }
    T prod(int l, int r) {
        assert(0 <= l && l <= r && r <= size());
        if (l == r) return M::id();
        node_ptr ptr = get_range(l, r);
        return ptr->val;
    }
    T get(int k) { return (*this)[k]; }
    T all_prod() { return root ? root->val : M::id(); }
    void apply(int l, int r, U x) {
        assert(0 <= l && l <= r && r <= size());
        if (l == r) return;
        node_ptr ptr = get_range(l, r);
        all_apply(ptr, x);
        splay(ptr);
    }
    void apply(int k, U x) {
        assert(0 <= k && k < size());
        node_ptr ptr = kth_element(k);
        ptr->v = Aop(x, ptr->v, 1);
        calc(ptr);
    }
    void set(int k, T x) {
        assert(0 <= k && k < size());
        node_ptr ptr = kth_element(k);
        ptr->v = x;
        calc(ptr);
    }
    template<class Upd> void update(int k, const Upd& upd) {
        assert(0 <= k && k < size());
        node_ptr ptr = kth_element(k);
        ptr->v = upd(ptr->v);
        calc(ptr);
    }
    void reverse(int l, int r) {
        assert(0 <= l && l <= r && r <= size());
        if (l + 1 >= r) return;
        node_ptr ptr = get_range(l, r);
        all_reverse(ptr);
        splay(ptr);
    }
    SplayTree& merge(SplayTree&& other) {
        if (root == nullptr) {
            root = other.root;
            other.root = nullptr;
            return *this;
        }
        if (other.root == nullptr) return *this;
        kth_element(size() - 1);
        root->r = other.root;
        if (other.root) other.root->p = root;
        calc(root);
        return *this;
    }
    friend SplayTree merge(SplayTree&& a, SplayTree&& b) {
        return std::move(a.merge(std::move(b)));
    }
    std::pair<SplayTree, SplayTree> split(int k) && {
        assert(0 <= k && k <= size());
        if (k == 0) return {SplayTree(), std::move(*this)};
        if (k == size()) return {std::move(*this), SplayTree()};
        node_ptr ptr = kth_element(k);
        node_ptr l = ptr->l;
        ptr->l = nullptr;
        if (l) l->p = nullptr;
        calc(ptr);
        return {SplayTree(l), SplayTree(ptr)};
    }
};
