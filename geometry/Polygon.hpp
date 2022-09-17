#pragma once

#include "template.hpp"
#include "Point.hpp"
#include "Line.hpp"

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

std::pair<Point, Point> diameter(const Polygon& p) {
    const int n = p.size();
    int i = 0, j = 0;
    rep (k, n) {
        if (cmp(p[k].x, p[i].x) > 0) i = k;
        if (cmp(p[k].x, p[j].x) < 0) j = k;
    }
    Real res = abs(p[i] - p[j]);
    int ri = i, rj = j;
    int si = i, sj = j;
    do {
        if (cross(p[(i + 1) % n] - p[i], p[(j + 1) % n] - p[j]) < 0) {
            i = (i + 1) % n;
        }
        else {
            j = (j + 1) % n;
        }
        if (chmax(res, abs(p[i] - p[j]))) {
            ri = i;
            rj = j;
        }
    } while (i != si || j != sj);
    return {p[ri], p[rj]};
}

std::pair<Point, Point> farthest_pair(const std::vector<Point>& p) {
    auto poly = convex_hull(p);
    return diameter(poly);
}

std::pair<Point, Point> closest_pair(std::vector<Point> p) {
    assert(p.size() >= 2);
    const int n = p.size();
    std::sort(all(p));
    Real res = infinity<Real>::value;
    int ri = -1, rj = -1;
    rec_lambda([&](auto&& self, int l, int r) -> void {
        const int m = (l + r) / 2;
        if (r - l <= 1) return;
        self(l, m); self(m, r);
        std::inplace_merge(p.begin() + l, p.begin() + m, p.begin() + r,
                           [](const Point& a, const Point& b) {
                               return cmp(a.y, b.y) < 0;
                           });
        std::vector<int> B;
        rep (i, l, r) {
            if (cmp(p[i].x - p[m].x, res) >= 0) continue;
            rrep (j, B.size()) {
                if (cmp(p[i].y - p[B[j]].y, res) >= 0) break;
                if (chmin(res, abs(p[i] - p[B[j]]))) {
                    ri = i;
                    rj = B[j];
                }
            }
            B.push_back(i);
        }
    })(0, n);
    return {p[ri], p[rj]};
}

// cut with line p0-p1 and return left side
Polygon polygon_cut(const Polygon& p, const Point& p0, const Point& p1) {
    const int n = p.size();
    Polygon res;
    rep (i, n) {
        Point a = p[i], b = p[(i + 1) % n];
        Real ca = cross(p0 - a, p1 - a);
        Real cb = cross(p0 - b, p1 - b);
        if (cmp(ca, 0) >= 0) res.push_back(a);
        if (cmp(ca, 0) * cmp(cb, 0) < 0) {
            res.push_back(intersection(Line(a, b), Line(p0, p1)));
        }
    }
    return res;
}
