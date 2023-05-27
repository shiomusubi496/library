#pragma once

#include "../../other/template.hpp"

template<class T, class Comp = std::less<T>> class IntervalHeap {
private:
    std::vector<T> dat;
    Comp cmp;

    int par(int k) const { return (k - 2) / 4 * 2; }
    int up(int k, int root = 1) {
        int n = dat.size();
        if ((k | 1) < n && cmp(dat[k & ~1], dat[k | 1])) {
            std::swap(dat[k & ~1], dat[k | 1]);
            k ^= 1;
        }
        int p;
        while (root < k && cmp(dat[p = par(k)], dat[k])) {
            std::swap(dat[p], dat[k]);
            k = p;
        }
        while (root < k && cmp(dat[k], dat[p = (par(k) | 1)])) {
            std::swap(dat[p], dat[k]);
            k = p;
        }
        return k;
    }
    int down(int k, int root = 1) {
        int n = dat.size();
        if (k & 1) {
            while ((k & 1) && 2 * k < n) {
                int l = 2 * k + 1, r = 2 * k + 3;
                if (l == n) --l;
                if (r == n) --r;
                if (r < n && cmp(dat[r], dat[l])) l = r;
                if (cmp(dat[l], dat[k])) {
                    std::swap(dat[k], dat[l]);
                    k = l;
                }
                else break;
            }
        }
        else {
            while (2 * k + 2 < n) {
                int l = 2 * k + 2, r = 2 * k + 4;
                if (r < n && cmp(dat[l], dat[r])) l = r;
                if (cmp(dat[k], dat[l])) {
                    std::swap(dat[k], dat[l]);
                    k = l;
                }
                else break;
            }
        }
        return up(k, root);
    }

public:
    IntervalHeap() {}
    IntervalHeap(std::vector<T> v) : dat(v) {
        rrep (i, dat.size()) {
            if ((i & 1) && cmp(dat[i - 1], dat[i]))
                std::swap(dat[i - 1], dat[i]);
            down(i, i | 1);
        }
    }

    int size() const { return dat.size(); }
    bool empty() const { return dat.empty(); }
    void push(const T& x) {
        dat.push_back(x);
        up(dat.size() - 1);
    }
    void pop_max() {
        assert(!dat.empty());
        if (size() == 1) {
            dat.pop_back();
            return;
        }
        std::swap(dat[0], dat.back());
        dat.pop_back();
        down(0);
    }
    void pop_min() {
        assert(!dat.empty());
        if (size() <= 2) {
            dat.pop_back();
            return;
        }
        std::swap(dat[1], dat.back());
        dat.pop_back();
        down(1);
    }
    const T& max() const {
        assert(!dat.empty());
        return dat[0];
    }
    const T& min() const {
        assert(!dat.empty());
        return size() == 1 ? dat[0] : dat[1];
    }
};

/**
 * @brief IntervalHeap
 * @docs docs/data-struct/other/IntervalHeap.md
 */
