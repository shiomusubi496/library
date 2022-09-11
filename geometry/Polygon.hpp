#pragma once

#include "template.hpp"
#include "Point.hpp"

class Polygon : public std::vector<Point> {
public:
    using std::vector<Point>::vector;
    explicit Polygon(const std::vector<Point>& v) : std::vector<Point>(v) {}
    explicit Polygon(std::vector<Point>&& v)
        : std::vector<Point>(std::move(v)) {}
};

Real area(const Polygon& p) {
    const int n = p.size();
    Real res = 0;
    rep (i, n) {
        res += cross(p[i], p[(i + 1) % n]);
    }
    return res / 2;
}

bool is_convex(const Polygon& p, bool allow_straight = false) {
    const int n = p.size();
    rep (i, n) {
        CCW c = ccw(p[(i + 1) % n], p[i], p[(i + 2) % n]);
        if (c == CCW::COUNTER_CLOCKWISE ||
            (!allow_straight && c == CCW::ONLINE_BACK)) {
            return false;
        }
    }
    return true;
}

bool contains(const Polygon& p, const Point& q, bool true_when_on_edge = true) {
    const int n = p.size();
    rep (i, n) {
        if (p[i] == q) return true_when_on_edge;
        Point a = p[i] - q;
        Point b = p[(i + 1) % n] - q;
        if (cmp(cross(a, b), 0) == 0 && cmp(dot(a, b), 0) <= 0) {
            return true_when_on_edge;
        }
    }
    bool res = false;
    rep (i, n) {
        Point a = p[i] - q;
        Point b = p[(i + 1) % n] - q;
        if (cmp(a.y, b.y) > 0) std::swap(a, b);
        if (cmp(a.y, 0) <= 0 && cmp(b.y, 0) > 0 && cmp(cross(a, b), 0) < 0) {
            res = !res;
        }
    }
    return res;
}

Polygon convex_hull(std::vector<Point> A, bool allow_straight = false) {
    const int n = A.size();
    if (n <= 2) return Polygon{A};
    std::sort(A.begin(), A.end(), [](const Point& a, const Point& b) {
        return cmp(a.x, b.x) != 0 ? cmp(a.x, b.x) < 0 : cmp(a.y, b.y) < 0;
    });
    Polygon res;
    rep (i, n) {
        while ((int)res.size() >= 2) {
            CCW c = ccw(res[res.size() - 2], res.back(), A[i]);
            if (c == CCW::CLOCKWISE ||
                (!allow_straight && c == CCW::ONLINE_FRONT)) {
                res.pop_back();
            }
            else break;
        }
        res.push_back(A[i]);
    }
    int t = res.size();
    rrep (i, n - 1) {
        while ((int)res.size() >= t + 1) {
            CCW c = ccw(res[res.size() - 2], res.back(), A[i]);
            if (c == CCW::CLOCKWISE ||
                (!allow_straight && c == CCW::ONLINE_FRONT)) {
                res.pop_back();
            }
            else break;
        }
        res.push_back(A[i]);
    }
    res.pop_back();
    return res;
}

Real diameter(const Polygon& p) {
    const int n = p.size();
    int i = 0, j = 0;
    rep (k, n) {
        if (cmp(p[k].x, p[i].x) > 0) i = k;
        if (cmp(p[k].x, p[j].x) < 0) j = k;
    }
    Real res = abs(p[i] - p[j]);
    int si = i, sj = j;
    do {
        if (cross(p[(i + 1) % n] - p[i], p[(j + 1) % n] - p[j]) < 0) {
            i = (i + 1) % n;
        }
        else {
            j = (j + 1) % n;
        }
        chmax(res, abs(p[i] - p[j]));
    } while (i != si || j != sj);
    return res;
}
