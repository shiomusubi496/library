#pragma once

#include "../../other/template.hpp"

template<class T, class Comp = std::less<T>> class ErasableHeap {
    std::priority_queue<T, std::vector<T>, Comp> pq, er;

public:
    void push(T x) { pq.push(x); }
    void erase(T x) { er.push(x); }
    T top() {
        while (!er.empty() && pq.top() == er.top()) {
            pq.pop();
            er.pop();
        }
        return pq.top();
    }
    void pop() {
        top();
        pq.pop();
    }
    int size() const { return pq.size() - er.size(); }
    bool empty() const { return size() == 0; }
};

template<class T, class Comp = std::less<T>, class Comp2 = std::greater<T>>
class KthMaxSum {
    const int K;
    ErasableHeap<T, Comp2> used;
    ErasableHeap<T, Comp> unused;
    T sm = 0;

public:
    KthMaxSum(ll K) : K(K) {}
    void insert(T x) {
        used.push(x);
        sm += x;
        if (used.size() > K) {
            unused.push(used.top());
            sm -= used.top();
            used.pop();
        }
    }
    void erase(T x) {
        if (!unused.empty() && unused.top() >= x) unused.erase(x);
        else {
            used.erase(x);
            sm -= x;
            if (!unused.empty()) {
                used.push(unused.top());
                sm += unused.top();
                unused.pop();
            }
        }
    }
    T sum() const { return sm; }
};
