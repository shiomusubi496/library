#pragma once

#include "../../other/template.hpp"
#include "../../other/bitop.hpp"

template<class T = ll, bool is_max = false> class LiChaoTree {
private:
    struct Line {
        T a, b;
        int idx;
        T get(T x) const { return a * x + b; }
        Line() = default;
        Line(T a, T b, int id) : a(a), b(b), idx(id) {}
    };
    int line_count = 0;
    int ori, n;
    std::vector<T> xs;
    std::vector<Line> lns;
    void add_line(int k, int a, int b, const Line& line) {
        if (a + 1 == b) {
            if (line.get(xs[a]) < lns[k].get(xs[a])) lns[k] = line;
            return;
        }
        int m = (a + b) >> 1;
        T x1 = lns[k].get(xs[a]), x2 = line.get(xs[a]);
        T y1 = lns[k].get(xs[b - 1]), y2 = line.get(xs[b - 1]);
        if (x1 <= x2 && y1 <= y2) return;
        if (x2 <= x1 && y2 <= y1) {
            lns[k] = line;
            return;
        }
        if (lns[k].get(xs[m]) <= line.get(xs[m])) {
            if (y1 < y2) add_line(k << 1, a, m, line);
            else add_line(k << 1 | 1, m, b, line);
        }
        else {
            if (y1 < y2) add_line(k << 1 | 1, m, b, lns[k]);
            else add_line(k << 1, a, m, lns[k]);
            lns[k] = line;
        }
    }
    void add_segment(int k, int a, int b, int l, int r, const Line& line) {
        if (l <= a && b <= r) {
            add_line(k, a, b, line);
            return;
        }
        if (r <= a || b <= l) return;
        int m = (a + b) >> 1;
        add_segment(k << 1, a, m, l, r, line);
        add_segment(k << 1 | 1, m, b, l, r, line);
    }

public:
    LiChaoTree() : LiChaoTree({0}) {}
    LiChaoTree(const std::vector<T>& xs_) { init(xs_); }
    void init(const std::vector<T>& xs_) {
        xs = xs_.empty() ? std::vector<T>{0} : xs_;
        ori = xs.size();
        n = 1 << bitop::ceil_log2(ori);
        xs.reserve(n);
        rep (i, xs_.size(), n) xs.push_back(xs_[i] + 1);
        lns.assign(n << 1,
                   Line{0, is_max ? infinity<T>::min : infinity<T>::max, -1});
    }
    int add_segment(int l, int r, T x, T y) {
        assert(0 <= l && l <= r && r <= ori);
        add_segment(1, 0, n, l, r,
                    Line{is_max ? -x : x, is_max ? -y : y, line_count});
        return line_count++;
    }
    int add_line(T x, T y) {
        add_line(1, 0, n, Line{is_max ? -x : x, is_max ? -y : y, line_count});
        return line_count++;
    }
    T get_min(int k) const {
        int x = k + n;
        T res = lns[x].get(xs[k]);
        while (x >>= 1) {
            const T y = lns[x].get(xs[k]);
            chmin(res, is_max ? -y : y);
        }
        return res;
    }
    struct line {
        T a, b;
        int idx;
    };
    line get_min_line(int k) const {
        int x = k + n;
        T mn = lns[x].get(xs[k]);
        Line res = lns[x];
        while (x >>= 1) {
            const T y = lns[x].get(xs[k]);
            if (chmin(mn, is_max ? -y : y)) res = lns[x];
        }
        return line{is_max ? -res.a : res.a, is_max ? -res.b : res.b, res.idx};
    }
};

/**
 * @brief LiChaoTree
 * @docs docs/data-struct/cht/LiChaoTree.md
 */
