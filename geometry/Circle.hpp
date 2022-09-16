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
    template<class Sc> void scan(Sc& scan) { scan >> c >> r; }
    template<class Pr> void print(Pr& print) { print << c << ' ' << r; }
    template<class Pr> void debug(Pr& print) {
        print.print_char('{');
        print << c;
        print.print_char(':');
        print << r;
        print.print_char('}');
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

Line radical_axis(const Circle& c1, const Circle& c2) {
    const Real a = c1.c.x, b = c1.c.y, r = c1.r;
    const Real c = c2.c.x, d = c2.c.y, s = c2.r;
    const Real p = -2 * a + 2 * c, q = -2 * b + 2 * d;
    const Real r2 = a * a + b * b - c * c - d * d - r * r + s * s;
    return Line(p, q, r2);
}

std::vector<Point> intersections(const Circle& c1, const Circle& c2) {
    const Line l = radical_axis(c1, c2);
    return intersections(c1, l);
}

Line tangent_at_point(const Circle& c, const Point& p) {
    assert(cmp(norm(c.c - p), c.r * c.r) == 0);
    const Real a = c.c.x, b = c.c.y;
    const Real px = p.x, py = p.y;
    return Line(px - a, py - b, (a - px) * a + (b - py) * b - c.r * c.r);
}

std::vector<Point> tangent_points(const Circle& c, const Point& p) {
    const Real d = norm(c.c - p);
    const Real r2 = c.r * c.r;
    if (cmp(d, r2) < 0) return {};
    if (cmp(d, r2) == 0) return {p};
    const Circle c2(p, std::sqrt(std::max<Real>(d - r2, 0)));
    return intersections(c, c2);
}

std::vector<Point> common_tangents(const Circle& c1, const Circle& c2) {
    assert(c1 != c2);
    const Real d = norm(c1.c - c2.c);
    const Real r1 = c1.r, r2 = c2.r;
    std::vector<Point> res;
    if (cmp(d, (r1 - r2) * (r1 - r2)) == 0) {
        const Point v = (c2.c - c1.c) * (r1 / std::sqrt(d));
        res.push_back(c1.c + (cmp(r1, r2) < 0 ? -v : v));
    } else if (cmp(d, (r1 - r2) * (r1 - r2)) > 0) {
        if (cmp(r1, r2) == 0) {
            const Point v = (c2.c - c1.c).rotate90() * (r1 / std::sqrt(d));
            res.push_back(c1.c + v);
            res.push_back(c1.c - v);
        } else {
            const Point v = (c1.c * r2 - c2.c * r1) / (-r1 + r2);
            auto ps = tangent_points(c1, v);
            std::copy(all(ps), std::back_inserter(res));
        }
        if (cmp(d, (r1 + r2) * (r1 + r2)) == 0) {
            const Point v = (c2.c - c1.c) * (r1 / std::sqrt(d));
            res.push_back(c1.c + v);
        } else if (cmp(d, (r1 + r2) * (r1 + r2)) > 0) {
            const Point v = (c1.c * r2 + c2.c * r1) / (r1 + r2);
            auto ps = tangent_points(c1, v);
            std::copy(all(ps), std::back_inserter(res));
        }
    }
    return res;
}
