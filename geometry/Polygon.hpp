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
        if (c != CCW::CLOCKWISE && (!allow_straight || c != CCW::ONLINE_BACK)) {
            return false;
        }
    }
    return true;
}
