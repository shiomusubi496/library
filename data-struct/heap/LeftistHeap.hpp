#pragma once

#include "../../other/template.hpp"

template<class T, class Comp = std::less<T>>
class LeftistHeap {
public:
    struct node;
    using node_ptr = std::shared_ptr<node>;
    struct node {
        T val;
        int s = 0;
        node_ptr l = nullptr, r = nullptr;
        template<class... Args>
        node(Args&&... args)
            : val(std::forward<Args>(args)...) {}
    };

private:
    static node_ptr meld(node_ptr a, node_ptr b) {
        if (!a) return b;
        if (!b) return a;
        if (Comp()(a->val, b->val)) std::swap(a, b);
        node_ptr c = std::make_shared<node>(a->val);
        c->l = a->l;
        c->r = meld(a->r, b);
        if (!c->l || c->l->s < c->r->s) std::swap(c->l, c->r);
        c->s = (c->r ? c->r->s : 0) + 1;
        return c;
    }

    static node_ptr push(node_ptr x, T val) { return meld(x, new node{val}); }
    template<class... Args>
    static node_ptr emplace(node_ptr x, Args&&... args) {
        return meld(x, std::make_shared<node>(std::forward<Args>(args)...));
    }
    static node_ptr pop(node_ptr x) {
        auto p = meld(x->l, x->r);
        return p;
    }
    static T top(node_ptr x) { return x->val; }
    static node_ptr copy(node_ptr x) {
        if (!x) return nullptr;
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
    LeftistHeap& meld(const LeftistHeap& other) {
        root = meld(root, other.root);
        sz += other.sz;
        return *this;
    }
    friend LeftistHeap meld(const LeftistHeap& a, const LeftistHeap& b) {
        LeftistHeap h;
        h.root = meld(a.root, b.root);
        h.sz = a.sz + b.sz;
        return h;
    }
    node_ptr get_root() const { return root; }
};

/**
 * @brief LeftistHeap
 * @docs docs/data-struct/heap/LeftistHeap.md
 */
