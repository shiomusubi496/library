#pragma once

#include "template.hpp"
#include "Point.hpp"
#include "Line.hpp"

class Circle {
public:
    Point c;
    Real r;
    Circle() : c(Point()), r(0) {}
    Circle(Point c, Real r) : c(c), r(r) {}
    friend bool operator==(const Circle& c1, const Circle& c2) {
        return c1.c == c2.c && cmp(c1.r, c2.r) == 0;
    }
    friend bool operator!=(const Circle& c1, const Circle& c2) {
        return !(c1 == c2);
    }
    friend bool operator<(const Circle& c1, const Circle& c2) {
        return c1.c < c2.c || (c1.c == c2.c && cmp(c1.r, c2.r) < 0);
    }
    friend bool operator>(const Circle& c1, const Circle& c2) {
        return c2 < c1;
    }
    friend bool operator<=(const Circle& c1, const Circle& c2) {
        return !(c2 < c1);
    }
    friend bool operator>=(const Circle& c1, const Circle& c2) {
        return !(c1 < c2);
    }
};

enum class circle_relation {
    IN = 0,           // 内包
    INSCRIBE = 1,     // 内接
    INTERSECT = 2,    // 交わる
    CIRCUMSCRIBE = 3, // 外接
    SEPARATE = 4,     // 離れている
    SAME = 5,         // 等しい
};

circle_relation relation(const Circle& c1, const Circle& c2) {
    if (c1 == c2) return circle_relation::SAME;
    const Real d = norm(c1.c - c2.c);
    const Real r1 = c1.r + c2.r, r2 = c1.r - c2.r;
    if (cmp(d, r1 * r1) > 0) return circle_relation::SEPARATE;
    if (cmp(d, r1 * r1) == 0) return circle_relation::CIRCUMSCRIBE;
    if (cmp(d, r2 * r2) > 0) return circle_relation::INTERSECT;
    if (cmp(d, r2 * r2) == 0) return circle_relation::INSCRIBE;
    return circle_relation::IN;
}

std::vector<Point> intersections(const Circle& c, const Line& l) {
    const Point h = projection(l, c.c);
    const Real d = norm(h - c.c);
    if (cmp(d, c.r * c.r) > 0) return {};
    if (cmp(d, c.r * c.r) == 0) return {h};
    const Point v = Point(l.b, -l.a) * std::sqrt(std::max<Real>((c.r * c.r - d) / (l.a * l.a + l.b * l.b), 0));
    return {h - v, h + v};
}
