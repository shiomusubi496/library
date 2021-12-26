#pragma once

#include "template.hpp"

namespace Monoid {

template<class T> struct Sum {
    using value_type = T;
    static constexpr T op(T a, T b) { return a + b; }
    static constexpr T id() { return T{0}; }
    static constexpr T inv(T a, T b) { return a - b; }
    static constexpr T get_inv(T a) { return -a; }
};

template<class T, T max_value = infinity<T>::max> struct Min {
    using value_type = T;
    static constexpr T op(T a, T b) { return a > b ? b : a; }
    static constexpr T id() { return max_value; }
};

template<class T, T min_value = infinity<T>::min> struct Max {
    using value_type = T;
    static constexpr T op(T a, T b) { return a < b ? b : a;}
    static constexpr T id() { return min_value; }
};

template<class T> struct Assign {
    using value_type = T;
    static constexpr T op(T a, T b) { return b; }
};


template<class T, T max_value = infinity<T>::max> struct AssignMin {
    using M = Min<T, max_value>;
    using E = Assign<T>;
    static constexpr T op(T a, T b) { return a; }
};

template<class T, T min_value = infinity<T>::min> struct AssignMax {
    using M = Max<T, min_value>;
    using E = Assign<T>;
    static constexpr T op(T a, T b) { return a; }
};

template<class T> struct AssignSum {
    using M = Sum<T>;
    using E = Assign<T>;
    static constexpr T op(T a, T b) { return a; }
    static constexpr T mul(T a, int b) { return a * b; }
};

template<class T, T max_value = infinity<T>::max> struct AddMin {
    using M = Min<T, max_value>;
    using E = Sum<T>;
    static constexpr T op(T a, T b) { return b + a; }
};

template<class T, T min_value = infinity<T>::min> struct AddMax {
    using M = Max<T, min_value>;
    using E = Sum<T>;
    static constexpr T op(T a, T b) { return b + a; }
};

template<class T> struct AddSum {
    using M = Sum<T>;
    using E = Sum<T>;
    static constexpr T op(T a, T b) { return b + a; }
    static constexpr T mul(T a, int b) { return a * b; }
};

template<class T, T max_value = infinity<T>::max> struct ChminMin {
    using M = Min<T, max_value>;
    using E = Min<T>;
    static constexpr T op(T a, T b) { return std::min(b, a); }
};

template<class T, T min_value = infinity<T>::min> struct ChminMax {
    using M = Max<T, min_value>;
    using E = Min<T>;
    static constexpr T op(T a, T b) { return std::min(b, a); }
};

template<class T, T max_value = infinity<T>::max> struct ChmaxMin {
    using M = Min<T, max_value>;
    using E = Max<T>;
    static constexpr T op(T a, T b) { return std::max(b, a); }
};

template<class T, T min_value = infinity<T>::min> struct ChmaxMax {
    using M = Max<T, min_value>;
    using E = Max<T>;
    static constexpr T op(T a, T b) { return std::max(b, a); }
};


template<class M_> struct AttachEffector {
    using M = M_;
    using E = M_;
    using T = typename M_::value_type;
    static T op(const T& a, const T& b) { return M_::op(b, a); }
};

template<class E_> struct AttachMonoid {
    using M = E_;
    using E = E_;
    using T = typename E_::value_type;
    static T op(const T& a, const T& b) { return E_::op(b, a); }
};


template<class M, class = void> struct has_id : public std::false_type {};
template<class M> struct has_id<M, typename std::conditional<false, decltype(M::id), void>::type> : public std::true_type {};

template<class M, class = void> struct has_inv : public std::false_type {};
template<class M> struct has_inv<M, typename std::conditional<false, decltype(M::inv), void>::type> : public std::true_type {};

template<class M, class = void> struct has_get_inv : public std::false_type {};
template<class M> struct has_get_inv<M, typename std::conditional<false, decltype(M::get_inv), void>::type> : public std::true_type {};

} // namespace Monoid
