#pragma once

#include "../../other/template.hpp"

template<class T> class PersistentStack {
private:
    struct node;
    using node_ptr = node*;
    struct node {
        T val;
        node_ptr nxt;
        int sz;
        node(T val, node_ptr nxt, int sz = 1) : val(val), nxt(nxt), sz(sz) {}
    };
    std::vector<node_ptr> root;

public:
    PersistentStack() : root(1, nullptr) {}

    int now() const { return (int)root.size() - 2; }

    int size(int t) const {
        assert(-1 <= t && t <= now());
        return root[t + 1] ? root[t + 1]->sz : 0;
    }
    bool empty(int t) const {
        assert(-1 <= t && t <= now());
        return root[t + 1] == nullptr;
    }
    T top(int t) const {
        assert(-1 <= t && t <= now());
        assert(!empty(t));
        return root[t + 1]->val;
    }
    int pop(int t) {
        assert(-1 <= t && t <= now());
        assert(!empty(t));
        root.push_back(root[t + 1]->nxt);
        return now();
    }
    int push(int t, T val) {
        assert(-1 <= t && t <= now());
        root.push_back(new node(val, root[t + 1]));
        if (root[t + 1]) root.back()->sz = root[t + 1]->sz + 1;
        return now();
    }
    int clear(int t) {
        assert(-1 <= t && t <= now());
        root.push_back(nullptr);
        return now();
    }
};

template<class T> class PersistentQueue {
private:
    PersistentStack<T> stk;
    std::vector<std::array<int, 7>> root;

    void pass(int& a, int& b) {
        b = stk.push(b, stk.top(a));
        a = stk.pop(a);
    }

    void step() {
        auto& r = root.back();
        if (r[6] != stk.size(r[0])) {
            if (!stk.empty(r[1])) {
                pass(r[1], r[2]);
                pass(r[4], r[3]);
            }
            else if (stk.size(r[3]) < r[6]) {
                pass(r[2], r[3]);
            }
            if (stk.size(r[3]) == r[6]) {
                r[0] = r[3];
                r[2] = r[3] = -1;
            }
        }
        if (r[6] == stk.size(r[5])) {
            std::swap(r[4], r[5]);
            r[1] = r[0];
            r[6] *= 2;
        }
    }

public:
    PersistentQueue() : root(1, {-1, -1, -1, -1, -1, -1, 0}) {}

    int now() const { return (int)root.size() - 2; }

    int size(int t) const {
        assert(-1 <= t && t <= now());
        return root[t + 1][6] + stk.size(root[t + 1][5]);
    }
    bool empty(int t) const { return size(t) == 0; }
    T front(int t) const {
        assert(-1 <= t && t <= now());
        assert(!empty(t));
        return stk.top(root[t + 1][0]);
    }
    int pop(int t) {
        assert(-1 <= t && t <= now());
        assert(!empty(t));
        if (size(t) == 1) {
            root.push_back({-1, -1, -1, -1, -1, -1, 0});
            return now();
        }
        auto r = root[t + 1];
        r[0] = stk.pop(r[0]);
        --r[6];
        root.push_back(r);
        step();
        return now();
    }
    int push(int t, T val) {
        assert(-1 <= t && t <= now());
        if (empty(t)) {
            int s = stk.push(-1, val);
            root.push_back({s, s, -1, -1, -1, -1, 1});
            return now();
        }
        auto r = root[t + 1];
        r[5] = stk.push(r[5], val);
        root.push_back(r);
        step();
        return now();
    }
};

/**
 * @brief PersistentQueue(永続Queue)
 * @see https://www.mathenachia.blog/persistent-queue/
 */