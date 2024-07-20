#pragma once

#include "template.hpp"
#include "Point.hpp"
#include "Line.hpp"

class Triangle {
public:
    Point p1, p2, p3;
    Triangle() = default;
    Triangle(const Point& p1, const Point& p2, const Point& p3)
        : p1(p1), p2(p2), p3(p3) {}

    Real area() const { return std::abs(cross(p2 - p1, p3 - p1)) / 2; }
    Point centroid() const { return (p1 + p2 + p3) / 3; }
    Point circumcenter() const {
        Line l1 = perpendicular_bisector(p1, p2);
        Line l2 = perpendicular_bisector(p2, p3);
        return intersection(l1, l2);
    }
#ifndef GEOMETRY_REAL_TYPE
    Real circumradius() const { return distance(p1, circumcenter()); }
    Point incenter() const {
        Real a = distance(p2, p3);
        Real b = distance(p3, p1);
        Real c = distance(p1, p2);
        return (a * p1 + b * p2 + c * p3) / (a + b + c);
    }
    Real inradius() const {
        return 2 * area() /
               (distance(p1, p2) + distance(p2, p3) + distance(p3, p1));
    }
#endif
    Point orthocenter() const {
        return intersection(perpendicular(Line(p1, p2), p3),
                            perpendicular(Line(p2, p3), p1));
    }
#ifndef GEOMETRY_REAL_TYPE
    std::array<Point, 3> excenter() const {
        Real a = distance(p2, p3);
        Real b = distance(p3, p1);
        Real c = distance(p1, p2);
        return {(-a * p1 + b * p2 + c * p3) / (-a + b + c),
                (a * p1 - b * p2 + c * p3) / (a - b + c),
                (a * p1 + b * p2 - c * p3) / (a + b - c)};
    }
    std::array<Real, 3> exradius() const {
        auto a = excenter();
        Line l(p1, p2);
        return {distance(a[0], l), distance(a[1], l), distance(a[2], l)};
    }
#endif
    Point nine_point_center() const {
        return (orthocenter() + circumcenter()) / 2;
    }
#ifndef GEOMETRY_REAL_TYPE
    Real nine_point_radius() const { return circumradius() / 2; }
#endif

    template<class Sc> void scan(Sc& scan) { scan >> p1 >> p2 >> p3; }
    template<class Pr> void debug(Pr& print) const {
        print.print_char('{');
        print << p1;
        print.print_char(' ');
        print << p2;
        print.print_char(' ');
        print << p3;
        print.print_char('}');
    }
};
