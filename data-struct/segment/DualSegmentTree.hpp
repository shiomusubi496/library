#pragma once

#include "../../other/template.hpp"
#include "../../other/bitop.hpp"

template<class T, class U, class F = std::function<T(U, T)>, class G = std::function<U(U, U)>> class DualSegmentTree {
  protected:
    F mapping;
    G composition;
    int n, h, ori;
    std::vector<T> data;
    std::vector<U> lazy;
    std::vector<bool> lazyflag;
    void all_apply(int k, U x) {
        if (k < n) {
            if (lazyflag[k]) {
                lazy[k] = composition(lazy[k], x);
            }
            else {
                lazy[k] = x;
                lazyflag[k] = true;
            }
        }
        else if (k < n + ori) {
            data[k - n] = mapping(x, data[k - n]);
        }
    }
    void eval(int k) {
        if (lazyflag[k]) {
            all_apply(k << 1, lazy[k]);
            all_apply(k << 1 ^ 1, lazy[k]);
            lazyflag[k] = false;
        }
    }
  public:
    DualSegmentTree() = default;
    DualSegmentTree(const F& mapping, const G& composition)
        : DualSegmentTree(0, mapping, composition) {}
    DualSegmentTree(int n_, const F& mapping, const G& composition)
        : DualSegmentTree(std::vector<T>(n_), mapping, composition) {}
    DualSegmentTree(const std::vector<T>& v, const F& mapping, const G& composition)
        : mapping(mapping), composition(composition) { init(v); }
    void init(const std::vector<T>& v) {
        ori = v.size();
        h = bitop::ceil_log2(ori);
        n = 1 << h;
        data = v;
        lazy.resize(n);
        lazyflag.assign(n, false);
    }
    T get(int k) {
        assert(0 <= k && k < ori);

        k += n;
        rreps (i, h) eval(k >> i);
        return data[k - n];
    }
    template<class Upd> void update(int k, const Upd& upd) {
        assert(0 <= k && k < ori);

        k += n;
        rreps (i, h) eval(k >> i);
        data[k - n] = upd(data[k - n]);
    }
    void set(int k, T x) {
        update(k, [&](T) -> T { return x; });
    }
    void apply(int k, U x) {
        update(k, [&](T a) -> T { return mapping(x, a); });
    }
    void apply(int l, int r, U x) {
        assert(0 <= l && l <= r && r <= ori);

        l += n; r += n;
        rreps (i, h) {
            bool seen = false;
            if (((l >> i) << i) != l) eval(l >> i), seen = true;
            if (((r >> i) << i) != r) eval((r - 1) >> i), seen = true;
            if (!seen) break;
        }

        while (l != r) {
            if (l & 1) all_apply(l++, x);
            if (r & 1) all_apply(--r, x);
            l >>= 1; r >>= 1;
        }
    }
};

template<class T> class RangeUpdateQuery : public DualSegmentTree<T, T> {
  protected:
    using Base = DualSegmentTree<T, T>;
  public:
    template<class... Args> RangeUpdateQuery(Args&&... args)
        : Base(
            std::forward<Args>(args)...,
            [](T a, T) -> T { return a; },
            [](T, T a) -> T { return a; }
        ) {}
};

template<class T> class RangeAddQuery : public DualSegmentTree<T, T> {
  protected:
    using Base = DualSegmentTree<T, T>;
  public:
    template<class... Args> RangeAddQuery(Args&&... args)
        : Base(
            std::forward<Args>(args)...,
            [](T a, T b) -> T { return a + b; },
            [](T a, T b) -> T { return a + b; }
        ) {}
};

template<class T> class RangeChminQuery : public DualSegmentTree<T, T> {
  protected:
    using Base = DualSegmentTree<T, T>;
  public:
    template<class... Args> RangeChminQuery(Args&&... args)
        : Base(
            std::forward<Args>(args)...,
            [](T a, T b) -> T { return std::min(a, b); },
            [](T a, T b) -> T { return std::min(a, b); }
        ) {}
};

template<class T> class RangeChmaxQuery : public DualSegmentTree<T, T> {
  protected:
    using Base = DualSegmentTree<T, T>;
  public:
    template<class... Args> RangeChmaxQuery(Args&&... args)
        : Base(
            std::forward<Args>(args)...,
            [](T a, T b) -> T { return std::max(a, b); },
            [](T a, T b) -> T { return std::max(a, b); }
        ) {}
};

/**
 * @brief DualSegmentTree(双対セグメント木)
 * @docs docs/DualSegmentTree.md
 */
