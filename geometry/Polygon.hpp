#pragma once

#include "template.hpp"
#include "Point.hpp"

class Polygon : public std::vector<Point> {
public:
    using std::vector<Point>::vector;
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
        if (c == CCW::COUNTER_CLOCKWISE || (!allow_straight && c == CCW::ONLINE_BACK)) {
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
