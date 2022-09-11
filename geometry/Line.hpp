#pragma once

#include "template.hpp"
#include "Point.hpp"

class Line {
public:
    Real a, b, c; // ax + by + c = 0
    Line() : a(0), b(1), c(0) {}
    Line(Real a, Real b, Real c) : a(a), b(b), c(c) {}
    Line(const Point& p1, const Point& p2) {
        a = p2.y - p1.y;
        b = p1.x - p2.x;
        c = p2.x * p1.y - p1.x * p2.y;
    }
    friend bool operator==(const Line& l1, const Line& l2) {
        return cmp(l1.a * l2.b, l2.a * l1.b) == 0 &&
               cmp(l1.b * l2.c, l2.b * l1.c) == 0;
    }
    friend bool operator!=(const Line& l1, const Line& l2) {
        return !(l1 == l2);
    }
    friend bool operator<(const Line& l1, const Line& l2) {
        return cmp(l1.a * l2.b, l2.a * l1.b) < 0 ||
               (cmp(l1.a * l2.b, l2.a * l1.b) == 0 &&
                cmp(l1.b * l2.c, l2.b * l1.c) < 0);
    }
    friend bool operator>(const Line& l1, const Line& l2) { return l2 < l1; }
    friend bool operator<=(const Line& l1, const Line& l2) {
        return !(l2 < l1);
    }
    friend bool operator>=(const Line& l1, const Line& l2) {
        return !(l1 < l2);
    }
    bool is_on(const Point& p) const {
        return cmp(a * p.x + b * p.y + c, 0) == 0;
    }
    template<class Pr> void debug(Pr& print) const {
        print << a;
        print.print_char("x+");
        print << b;
        print.print_char("y+");
        print << c;
        print.print_char("=0");
    }
};

Real distance(const Point& p, const Line& l) {
    return std::abs(l.a * p.x + l.b * p.y + l.c) /
           std::sqrt(l.a * l.a + l.b * l.b);
}
Real distance(const Line& l, const Point& p) { return distance(p, l); }

// 垂直二等分線
Line perpendicular_bisector(const Point& p1, const Point& p2) {
    return Line((p1 + p2) / 2, (p1 + p2) / 2 + (p2 - p1).rotate90());
}

// 平行判定
bool is_parallel(const Line& l1, const Line& l2) {
    return cmp(l1.a * l2.b, l2.a * l1.b) == 0;
}
// 直交判定
bool is_orthogonal(const Line& l1, const Line& l2) {
    return cmp(l1.a * l2.a + l1.b * l2.b, 0) == 0;
}
// 平行線
Line parallel(const Line& l, const Point& p) {
    return Line(l.a, l.b, -l.a * p.x - l.b * p.y);
}
// 垂直線
Line perpendicular(const Line& l, const Point& p) {
    return Line(l.b, -l.a, -l.b * p.x + l.a * p.y);
}

// 交叉判定
bool is_intersect(const Line& l1, const Line& l2) {
    return l1 == l2 || !is_parallel(l1, l2);
}
// 交点
Point intersection(const Line& l1, const Line& l2) {
    assert(!is_parallel(l1, l2));
    Real d = l1.a * l2.b - l2.a * l1.b;
    return Point((l1.b * l2.c - l2.b * l1.c) / d,
                 (l1.c * l2.a - l2.c * l1.a) / d);
}
// 射影
Point projection(const Line& l, const Point& p) {
    return intersection(l, perpendicular(l, p));
}
// 反射
Point reflection(const Line& l, const Point& p) {
    return projection(l, p) * 2 - p;
}
