#pragma once

#include "template.hpp"
#include "monoid.hpp"

namespace Monoid {

template<class T> struct Product {
    using value_type = T;
    static T op(const T& a, const T& b) { return a * b; }
    static T id() { return T{1}; }
    static T inv(const T& a, const T& b) { return a / b; }
    static T get_inv(const T& a) { return T{1} / a; }
};

template<class T> struct Composite {
    using value_type = std::pair<T, T>;
    static value_type op(const value_type& a, const value_type& b) {
        return {b.first * a.first, b.first * a.second + b.second};
    }
    static value_type id() { return {T{1}, T{0}}; }
    static value_type get_inv(const value_type& a) {
        return {T{1} / a.first, -a.second / a.first};
    }
    static value_type inv(const value_type& a, const value_type& b) {
        return op(a, get_inv(b));
    }
};

template<class T> struct GCD {
    using value_type = T;
    static T op(T a, T b) { return gcd(a, b); }
    static T id() { return 0; }
};
template<class T> struct LCM {
    using value_type = T;
    static T op(T a, T b) { return lcm(a, b); }
    static T id() { return 1; }
};

template<class T> struct AddAssign {
    using value_type = std::pair<bool, T>; // false: add, true: assign
    static value_type op(const value_type& a, const value_type& b) {
        if (b.first) return b;
        return {a.first, a.second + b.second};
    }
    static value_type id() { return {false, T{0}}; }
};

template<class T, T max_value = infinity<T>::max> struct MinCount {
    using value_type = std::pair<T, ll>;
    static value_type op(const value_type& a, const value_type& b) {
        if (a.first < b.first) return a;
        if (a.first > b.first) return b;
        return {a.first, a.second + b.second};
    }
    static value_type id() { return {max_value, 0}; }
};


template<class T> struct AffineSum {
    using M = Sum<T>;
    using E = Composite<T>;
    using U = typename E::value_type;
    static T mul_op(const U& a, int b, const T& c) {
        return a.first * c + a.second * b;
    }
};

template<class T> struct AddAssignSum {
    using M = Sum<T>;
    using E = AddAssign<T>;
    using U = typename E::value_type;
    static T mul_op(const U& a, int b, const T& c) {
        if (a.first) return a.second * b;
        return c + a.second * b;
    }
};

template<class T> struct AddMinCount {
    using M = MinCount<T>;
    using E = Sum<T>;
    using U = typename M::value_type;
    static U op(const T& a, const U& b) { return {a + b.first, b.second}; }
};

} // namespace Monoid
