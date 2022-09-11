#pragma once

#include "template.hpp"
#include "Point.hpp"
#include "Line.hpp"

class Segment {
public:
    Point p1, p2;
    Segment() = default;
    Segment(const Point& p1, const Point& p2) : p1(p1), p2(p2) {}
    friend bool operator==(const Segment& s1, const Segment& s2) {
        return s1.p1 == s2.p1 && s1.p2 == s2.p2;
    }
    friend bool operator!=(const Segment& s1, const Segment& s2) {
        return !(s1 == s2);
    }
    friend bool operator<(const Segment& s1, const Segment& s2) {
        return s1.p1 < s2.p1 || (s1.p1 == s2.p1 && s1.p2 < s2.p2);
    }
    friend bool operator>(const Segment& s1, const Segment& s2) {
        return s2 < s1;
    }
    friend bool operator<=(const Segment& s1, const Segment& s2) {
        return !(s2 < s1);
    }
    friend bool operator>=(const Segment& s1, const Segment& s2) {
        return !(s1 < s2);
    }
    bool is_on(const Point& p) const {
        return p == p1 || p == p2 || ccw(p1, p2, p) == CCW::ON_SEGMENT;
    }
    explicit operator Line() const { return Line(p1, p2); }
    template<class Pr> void debug(Pr& print) const {
        print << p1;
        print.print_char("->");
        print << p2;
    }
    template<class Sc> void scan(Sc& scan) { scan >> p1 >> p2; }
};

bool is_parallel(const Segment& s1, const Segment& s2) {
    return is_parallel(Line(s1), Line(s2));
}
bool is_orthogonal(const Segment& s1, const Segment& s2) {
    return is_orthogonal(Line(s1), Line(s2));
}
Line perpendicular_bisector(const Segment& s) {
    return perpendicular_bisector(s.p1, s.p2);
}

bool is_intersect(const Segment& s1, const Segment& s2) {
    if (is_parallel(s1, s2)) {
        return s1.is_on(s2.p1) || s1.is_on(s2.p2) || s2.is_on(s1.p1) ||
               s2.is_on(s1.p2);
    }
    Point p = intersection(Line(s1), Line(s2));
    return s1.is_on(p) && s2.is_on(p);
}
bool is_intersect(const Segment& s1, const Line& l) {
    if (!is_intersect(Line(s1), l)) return false;
    Point p = intersection(Line(s1), l);
    return s1.is_on(p);
}
bool is_intersect(const Line& l, const Segment& s1) {
    return is_intersect(s1, l);
}

Real distance(const Point& p, const Segment& s) {
    if (s.p1 == s.p2) return distance(p, s.p1);
    if (dot(s.p2 - s.p1, p - s.p1) < 0) return distance(p, s.p1);
    if (dot(s.p1 - s.p2, p - s.p2) < 0) return distance(p, s.p2);
    return distance(p, Line(s));
}
Real distance(const Segment& s, const Point& p) { return distance(p, s); }
Real distance(const Segment& s1, const Segment& s2) {
    if (is_intersect(s1, s2)) return 0;
    return std::min({distance(s1.p1, s2), distance(s1.p2, s2),
                     distance(s2.p1, s1), distance(s2.p2, s1)});
}
Real distance(const Segment& s, const Line& l) {
    if (is_intersect(s, l)) return 0;
    return std::min(distance(s.p1, l), distance(s.p2, l));
}
Real distance(const Line& l, const Segment& s) { return distance(s, l); }
