#pragma once

#include "../../other/template.hpp"
#include "../../other/monoid.hpp"

template<class T, class Comp = std::less<T>, class A = Monoid::AddMin<T>>
class LeftistHeap {
private:
    using M = typename A::M;
    using E = typename A::E;
    using U = typename E::value_type;

    static_assert(std::is_same<typename M::value_type, T>::value,
                  "Monoid and LeftistHeap value_type mismatch");

    struct node;
    using node_ptr = node*;
    struct node {
        T val;
        U lazy;
        int s = 0;
        node_ptr l = nullptr, r = nullptr;
        template<class... Args>
        node(Args&&... args)
            : val(std::forward<Args>(args)...), lazy(E::id()) {}
    };

    static void apply_all(node_ptr ptr, U x) {
        if (!ptr) return;
        ptr->val = A::op(x, ptr->val);
        ptr->lazy = E::op(ptr->lazy, x);
    }
    static void eval(node_ptr x) {
        if (x->lazy == E::id()) return;
        apply_all(x->l, x->lazy);
        apply_all(x->r, x->lazy);
        x->lazy = E::id();
    }

    static node_ptr meld(node_ptr a, node_ptr b) {
        if (!a) return b;
        if (!b) return a;
        if (Comp()(a->val, b->val)) std::swap(a, b);
        eval(a);
        a->r = meld(a->r, b);
        if (!a->l || a->l->s < a->r->s) std::swap(a->l, a->r);
        a->s = (a->r ? a->r->s : 0) + 1;
        return a;
    }

    static node_ptr push(node_ptr x, T val) { return meld(x, new node{val}); }
    template<class... Args>
    static node_ptr emplace(node_ptr x, Args&&... args) {
        return meld(x, new node{std::forward<Args>(args)...});
    }
    static node_ptr pop(node_ptr x) {
        eval(x);
        auto p = meld(x->l, x->r);
        delete x;
        return p;
    }
    static T top(node_ptr x) { return x->val; }
    static void clear(node_ptr x) {
        if (!x) return;
        clear(x->l);
        clear(x->r);
        delete x;
    }
    static node_ptr copy(node_ptr x) {
        if (!x) return nullptr;
        eval(x);
        node_ptr y = new node{x->val};
        y->l = copy(x->l);
        y->r = copy(x->r);
        return y;
    }

    node_ptr root;
    int sz;

public:
    LeftistHeap() : root(nullptr), sz(0) {}
    LeftistHeap(const LeftistHeap& other)
        : root(copy(other.root)), sz(other.sz) {}
    LeftistHeap& operator=(const LeftistHeap& other) {
        if (this != &other) {
            clear();
            root = copy(other.root);
            sz = other.sz;
        }
        return *this;
    }
    LeftistHeap(LeftistHeap&& other) noexcept : root(other.root), sz(other.sz) {
        other.root = nullptr;
        other.sz = 0;
    }
    LeftistHeap& operator=(LeftistHeap&& other) noexcept {
        if (this != &other) {
            root = other.root;
            sz = other.sz;
            other.root = nullptr;
            other.sz = 0;
        }
        return *this;
    }
    ~LeftistHeap() { clear(); }

    bool empty() const { return !root; }
    int size() const { return sz; }
    void clear() {
        clear(root);
        root = nullptr;
        sz = 0;
    }
    void push(T val) {
        root = push(root, val);
        ++sz;
    }
    template<class... Args> void emplace(Args&&... args) {
        root = emplace(root, std::forward<Args>(args)...);
        ++sz;
    }
    void pop() {
        assert(!empty());
        root = pop(root);
        --sz;
    }
    T top() {
        assert(!empty());
        return top(root);
    }
    void apply(U x) { apply_all(root, x); }
    LeftistHeap& meld(LeftistHeap&& other) {
        root = meld(root, other.root);
        sz += other.sz;
        other.root = nullptr;
        other.sz = 0;
        return *this;
    }
    friend LeftistHeap meld(LeftistHeap&& a, LeftisHeap&& b) {
        return std::move(a.meld(std::move(b)));
    }
};

/**
 * @brief LeftistHeap
 * @docs docs/data-struct/heap/LeftistHeap.md
 */
