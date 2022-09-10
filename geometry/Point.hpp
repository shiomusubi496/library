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
    Real norm() const { return x * x + y * y; }
    friend Real norm(const Point& p) { return p.norm(); }
    Real abs() const { return sqrt(norm()); }
    friend Real abs(const Point& p) { return p.abs(); }
    Real arg() const { return atan2(y, x); }
    friend Real arg(const Point& p) { return p.arg(); }
    Point& rotate(Real theta) {
        Real c = cos(theta), s = sin(theta);
        Real nx = x * c - y * s, ny = x * s + y * c;
        x = nx;
        y = ny;
        return *this;
    }
    friend Point rotate(const Point& p, Real theta) {
        return Point(p).rotate(theta);
    }
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
    template<class Scanner> void scan(Scanner& scan) { scan >> x >> y; }
    template<class Printer> void print(Printer& print) const {
        print << x << ' ' << y;
    }
    template<class Printer> void debug(Printer& print) const {
        print.print_char('(');
        print << x;
        print.print_char(',');
        print << y;
        print.print_char(')');
    }
};

Real distance(const Point& p1, const Point& p2) {
    return abs(p1 - p2);
}

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
