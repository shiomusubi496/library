#pragma once

#include "../../other/template.hpp"

template<unsigned int height = 64> class BinaryTrie {
protected:
    struct node;
    using node_ptr = std::unique_ptr<node>;
    struct node {
        std::array<node_ptr, 2> ch;
        ll sz;
        node() : ch{nullptr, nullptr}, sz(0) {}
    };
    static const node_ptr& get(const node_ptr& nd, int i) {
        if (nd->ch[i]) return nd->ch[i];
        return nd->ch[i] = std::make_unique<node>();
    }
    node_ptr root;
    ull xall;
    static void insert(const node_ptr& nd, ull k, int h, ll x) {
        nd->sz += x;
        if (h == 0) return;
        insert(get(nd, (k >> (h - 1)) & 1), k, h - 1, x);
    }
    static const node_ptr& get_ptr(const node_ptr& nd, ull k, int h) {
        if (h == 0) return nd;
        return get_ptr(get(nd, (k >> (h - 1)) & 1), k, h - 1);
    }
    static ull kth_element(const node_ptr& nd, ll k, int h, ull x) {
        if (h == 0) return 0;
        int t = (x >> (h - 1)) & 1;
        ll sz = nd->ch[t] ? nd->ch[t]->sz : 0;
        if (sz > k) return kth_element(nd->ch[t], k, h - 1, x);
        return kth_element(nd->ch[t ^ 1], k - sz, h - 1, x) | (1 << (h - 1));
    }
    static ll get_index(const node_ptr& nd, ull k, int h, ull x) {
        if (h == 0) return 0;
        int t = (k >> (h - 1)) & 1;
        int u = (x >> (h - 1)) & 1;
        ll sz = nd->ch[t] ? get_index(nd->ch[t], k, h - 1, x) : 0;
        if (t ^ u) return sz + (nd->ch[u] ? nd->ch[u]->sz : 0);
        return sz;
    }
    static void copy(const node_ptr& nd, const node_ptr& nd2) {
        nd->sz = nd2->sz;
        if (nd2->ch[0]) copy(get(nd, 0), nd2->ch[0]);
        if (nd2->ch[1]) copy(get(nd, 1), nd2->ch[1]);
    }

public:
    BinaryTrie() : root(std::make_unique<node>()), xall(0) {}
    BinaryTrie(const BinaryTrie& other) : xall(other.xall), root(std::make_unique<node>()) {
        copy(root, other.root);
    }
    BinaryTrie(BinaryTrie&& other) = default;
    BinaryTrie& operator=(const BinaryTrie& other) {
        if (this == &other) return *this;
        xall = other.xall;
        copy(root, other.root);
        return *this;
    }
    BinaryTrie& operator=(BinaryTrie&& other) = default;
    ll size() const { return root->sz; }
    bool empty() const { return size() == 0; }
    void insert(ull k) { insert(k, 1); }
    void insert(ull k, ll x) { insert(root, k ^ xall, height, x); }
    void erase(ull k) { insert(k, -1); }
    void xor_all(ull x) { xall ^= x; }
    ll count(ull k) const { return get_ptr(root, k ^ xall, height)->sz; }
    ull kth_element(ll k) const {
        assert(0 <= k && k < root->sz);
        return kth_element(root, k, height, xall);
    }
    ll get_index(ull k) const {
        return get_index(root, k ^ xall, height, xall);
    }
};

/**
 * @brief BinaryTrie
 * @docs docs/BinaryTrie.md
 */