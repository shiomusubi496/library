#pragma once

#include "template.hpp"

class Point {
public:
    Real x, y;
    Point() : x(0), y(0) {}
    Point(Real x, Real y) : x(x), y(y) {}
    Point& operator+=(const Point& p) {
        x += p.x;
        y += p.y;
        return *this;
    }
    Point& operator-=(const Point& p) {
        x -= p.x;
        y -= p.y;
        return *this;
    }
    Point& operator*=(Real a) {
        x *= a;
        y *= a;
        return *this;
    }
    Point& operator/=(Real a) {
        x /= a;
        y /= a;
        return *this;
    }
    Point operator+() const { return *this; }
    Point operator-() const { return Point(-x, -y); }
    friend Point operator+(const Point& p1, const Point& p2) {
        return Point(p1) += p2;
    }
    friend Point operator-(const Point& p1, const Point& p2) {
        return Point(p1) -= p2;
    }
    friend Point operator*(const Point& p, Real a) { return Point(p) *= a; }
    friend Point operator*(Real a, const Point& p) { return Point(p) *= a; }
    friend Point operator/(const Point& p, Real a) { return Point(p) /= a; }
    friend bool operator==(const Point& p1, const Point& p2) {
        return cmp(p1.x, p2.x) == 0 && cmp(p1.y, p2.y) == 0;
    }
    friend bool operator!=(const Point& p1, const Point& p2) {
        return !(p1 == p2);
    }
    friend bool operator<(const Point& p1, const Point& p2) {
        return cmp(p1.x, p2.x) < 0 ||
               (cmp(p1.x, p2.x) == 0 && cmp(p1.y, p2.y) < 0);
    }
    friend bool operator>(const Point& p1, const Point& p2) { return p2 < p1; }
    friend bool operator<=(const Point& p1, const Point& p2) {
        return !(p2 < p1);
    }
    friend bool operator>=(const Point& p1, const Point& p2) {
        return !(p1 < p2);
    }
    friend bool comp_arg(const Point& p1, const Point& p2) {
        // -pi < theta <= pi
        int a1 = p1.y < 0 ? 0 : p1.y > 0 ? 2 : p1.x >= 0 ? 1 : 3;
        int a2 = p2.y < 0 ? 0 : p2.y > 0 ? 2 : p2.x >= 0 ? 1 : 3;
        if (a1 != a2) return a1 < a2;
        return cross(p1, p2) > 0;
    }
    Real norm() const { return x * x + y * y; }
    friend Real norm(const Point& p) { return p.norm(); }
#ifndef GEOMETRY_REAL_TYPE
    Real abs() const { return sqrt(norm()); }
    friend Real abs(const Point& p) { return p.abs(); }
    inline angle_t arg() const { return atan2((ld)y, (ld)x); }
    friend angle_t arg(const Point& p) { return p.arg(); }
    Point& rotate(angle_t theta) {
        Real c = cos(theta), s = sin(theta);
        Real nx = x * c - y * s, ny = x * s + y * c;
        x = nx;
        y = ny;
        return *this;
    }
    friend Point rotate(const Point& p, angle_t theta) {
        return Point(p).rotate(theta);
    }
#endif
    Point& rotate90() {
        Real nx = -y, ny = x;
        x = nx;
        y = ny;
        return *this;
    }
    friend Point rotate90(const Point& p) { return Point(p).rotate90(); }
    // inner product(内積), p1 * p2 = |p1| * |p2| * cos(theta)
    friend Real dot(const Point& p1, const Point& p2) {
        return p1.x * p2.x + p1.y * p2.y;
    }
    // outer product(外積), p1 ^ p2 = |p1| * |p2| * sin(theta)
    friend Real cross(const Point& p1, const Point& p2) {
        return p1.x * p2.y - p1.y * p2.x;
    }
    template<class Sc> void scan(Sc& scan) { scan >> x >> y; }
    template<class Pr> void print(Pr& print) const { print << x << ' ' << y; }
    template<class Pr> void debug(Pr& print) const {
        print.print_char('(');
        print << x;
        print.print_char(',');
        print << y;
        print.print_char(')');
    }
};

#ifndef GEOMETRY_REAL_TYPE
Real distance(const Point& p1, const Point& p2) { return abs(p1 - p2); }
#endif

enum class CCW {
    COUNTER_CLOCKWISE = 1,
    CLOCKWISE = -1,
    ONLINE_BACK = 2,
    ONLINE_FRONT = -2,
    ON_SEGMENT = 0,
};

CCW ccw(const Point& p0, const Point& p1, const Point& p2) {
    Point a = p1 - p0, b = p2 - p0;
    if (cmp(cross(a, b), 0) > 0) return CCW::COUNTER_CLOCKWISE;
    if (cmp(cross(a, b), 0) < 0) return CCW::CLOCKWISE;
    if (cmp(dot(a, b), 0) < 0) return CCW::ONLINE_BACK;
    if (a.norm() < b.norm()) return CCW::ONLINE_FRONT;
    return CCW::ON_SEGMENT;
}
