#pragma once

#include "template.hpp"
#include "Point.hpp"

class Polygon : public std::vector<Point> {
public:
    using std::vector<Point>::vector;
};

Real area(const Polygon& p) {
    Real res = 0;
    rep (i, p.size()) {
        res += cross(p[i], p[(i + 1) % p.size()]);
    }
    return res / 2;
}
