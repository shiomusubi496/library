#pragma once

#include "../../other/template.hpp"

template<class T, std::size_t sz = 2>
class PersistentArray {
private:
    struct node;
    using node_ptr = std::shared_ptr<node>;
    struct node {
        T val;
        std::array<node_ptr, sz> ch;
        node() : val(T()) { ch.fill(nullptr); }
        node(const T& val) : val(val) { ch.fill(nullptr); }
        node(const std::array<node_ptr, sz>& ch) : ch(ch) {}
        node(const T& val, const std::array<node_ptr, sz>& ch) : val(val), ch(ch) {}
    };
    int n;
    std::vector<node_ptr> root;
    std::vector<int> len;
    int last_time;
    void build_dfs(node_ptr& nd, const std::vector<T>& a, int k, int t) {
        if (k >= n) return;
        if (nd == nullptr) nd = std::make_shared<node>(a[k]);
        rep (i, sz) {
            build_dfs(nd->ch[i], a, k + (i + 1) * t, t * sz);
        }
    }
    void set_dfs(node_ptr& nd, int k, const T& x) {
        nd = std::make_shared<node>(*nd);
        if (k == 0) nd->val = x;
        else set_dfs(nd->ch[(k - 1) % sz], (k - 1) / sz, x);
    }
    void push_back_dfs(node_ptr& nd, int k, const T& x) {
        if (k == 0) nd = std::make_shared<node>(x);
        else {
            nd = std::make_shared<node>(*nd);
            push_back_dfs(nd->ch[(k - 1) % sz], (k - 1) / sz, x);
        }
    }
    T get_dfs(const node_ptr& nd, int k) const {
        if (k == 0) return nd->val;
        return get_dfs(nd->ch[(k - 1) % sz], (k - 1) / sz);
    }

public:
    PersistentArray(int n) : PersistentArray(std::vector<T>(n)) {}
    PersistentArray(const std::vector<T>& a) { init(a); }
    void init(const std::vector<T>& a) {
        n = a.size();
        if (n == 0) {
            root.assign(1, std::make_shared<node>());
            len.assign(1, 0);
        }
        else {
            root.resize(1);
            build_dfs(root[0], a, 0, 1);
            len.assign(1, n);
        }
        last_time = 0;
    }
    int now() const { return last_time - 1; }
    int set(int k, const T& x, int t) {
        assert(-1 <= t && t < last_time);
        assert(0 <= k && k < len[t + 1]);
        root.push_back((node_ptr)root[t + 1]);
        set_dfs(root.back(), k, x);
        len.push_back(len[t + 1]);
        return last_time++;
    }
    int set_last(int k, const T& x) {
        return set(k, x, last_time - 1);
    }
    int push_back(const T& x, int t) {
        assert(-1 <= t && t < last_time);
        root.push_back(std::make_shared<node>(*root[t + 1]));
        push_back_dfs(root.back(), len[t + 1], x);
        len.push_back(len[t + 1] + 1);
        return last_time++;
    }
    int push_back_last(const T& x) {
        return push_back(last_time - 1, x);
    }
    T get(int k, int t) const {
        assert(-1 <= t && t < last_time);
        assert(0 <= k && k < len[t + 1]);
        return get_dfs(root[t + 1], k);
    }
    T get_last(int k) const {
        return get(k, last_time - 1);
    }
    int size(int t) const {
        assert(-1 <= t && t < last_time);
        return len[t + 1];
    }
    int size_last() const {
        return size(last_time - 1);
    }
};

/**
 * @brief PersistentArray(完全永続配列)
 * @docs docs/data-struct/other/PersistentArray.md
 */
