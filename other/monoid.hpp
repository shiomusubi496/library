#pragma once

#include "template.hpp"

namespace Monoid {

template<class M, class = void>
class has_value_type : public std::false_type {};
template<class M>
class has_value_type<M, decltype((void)std::declval<typename M::value_type>())>
    : public std::true_type {};

template<class M, class = void> class has_op : public std::false_type {};
template<class M>
class has_op<M, decltype((void)M::op)> : public std::true_type {};

template<class M, class = void> class has_id : public std::false_type {};
template<class M>
class has_id<M, decltype((void)M::id)> : public std::true_type {};

template<class M, class = void> class has_inv : public std::false_type {};
template<class M>
class has_inv<M, decltype((void)M::inv)> : public std::true_type {};

template<class M, class = void> class has_get_inv : public std::false_type {};
template<class M>
class has_get_inv<M, decltype((void)M::get_inv)> : public std::true_type {};

template<class M, class = void> class has_init : public std::false_type {};
template<class M>
class has_init<M, decltype((void)M::init(0, 0))> : public std::true_type {};

template<class A, class = void> class has_mul_op : public std::false_type {};
template<class A>
class has_mul_op<A, decltype((void)A::mul_op)> : public std::true_type {};

template<class T, class = void> class is_semigroup : public std::false_type {};
template<class T>
class is_semigroup<T, decltype(std::declval<typename T::value_type>(),
                               (void)T::op)> : public std::true_type {};

template<class T, class = void> class is_monoid : public std::false_type {};

template<class T>
class is_monoid<T, decltype(std::declval<typename T::value_type>(), (void)T::op,
                            (void)T::id)> : public std::true_type {};

template<class T, class = void> class is_group : public std::false_type {};

template<class T>
class is_group<T, decltype(std::declval<typename T::value_type>(), (void)T::op,
                           (void)T::id, (void)T::get_inv)>
    : public std::true_type {};

template<class T, class = void> class is_action : public std::false_type {};
template<class T>
class is_action<T, typename std::enable_if<is_monoid<typename T::M>::value &&
                                           is_semigroup<typename T::E>::value &&
                                           (has_op<T>::value ||
                                            has_mul_op<T>::value)>::type>
    : public std::true_type {};

template<class T, class = void>
class is_distributable_action : public std::false_type {};
template<class T>
class is_distributable_action<
    T,
    typename std::enable_if<is_action<T>::value && !has_mul_op<T>::value>::type>
    : public std::true_type {};

template<class T> struct Sum {
    using value_type = T;
    static constexpr T op(const T& a, const T& b) { return a + b; }
    static constexpr T id() { return T{0}; }
    static constexpr T inv(const T& a, const T& b) { return a - b; }
    static constexpr T get_inv(const T& a) { return -a; }
};

template<class T, int i = -2> struct Min {
    using value_type = T;
    static T max_value;
    static T op(const T& a, const T& b) { return a < b ? a : b; }
    static T id() { return max_value; }
};
template<class T> struct Min<T, -1> {
    using value_type = T;
    static constexpr T op(const T& a, const T& b) { return a < b ? a : b; }
    static constexpr T id() { return infinity<T>::max; }
};
template<class T> struct Min<T, -2> {
    using value_type = T;
    static constexpr T op(const T& a, const T& b) { return a < b ? a : b; }
    static constexpr T id() { return infinity<T>::value; }
};
template<class T, int id> T Min<T, id>::max_value;

template<class T, int i = -2> struct Max {
    using value_type = T;
    static T min_value;
    static T op(const T& a, const T& b) { return a > b ? a : b; }
    static T id() { return min_value; }
};
template<class T> struct Max<T, -1> {
    using value_type = T;
    static constexpr T op(const T& a, const T& b) { return a > b ? a : b; }
    static constexpr T id() { return infinity<T>::min; }
};
template<class T> struct Max<T, -2> {
    using value_type = T;
    static constexpr T op(const T& a, const T& b) { return a > b ? a : b; }
    static constexpr T id() { return infinity<T>::mvalue; }
};

template<class T> struct Assign {
    using value_type = T;
    static constexpr T op(const T&, const T& b) { return b; }
};


template<class T, int id = -1> struct AssignMin {
    using M = Min<T, id>;
    using E = Assign<T>;
    static constexpr T op(const T& a, const T&) { return a; }
};

template<class T, int id = -1> struct AssignMax {
    using M = Max<T, id>;
    using E = Assign<T>;
    static constexpr T op(const T& a, const T&) { return a; }
};

template<class T> struct AssignSum {
    using M = Sum<T>;
    using E = Assign<T>;
    static constexpr T mul_op(const T& a, int b, const T&) { return a * b; }
};

template<class T, int id = -1> struct AddMin {
    using M = Min<T, id>;
    using E = Sum<T>;
    static constexpr T op(const T& a, const T& b) { return b + a; }
};

template<class T, int id = -1> struct AddMax {
    using M = Max<T, id>;
    using E = Sum<T>;
    static constexpr T op(const T& a, const T& b) { return b + a; }
};

template<class T> struct AddSum {
    using M = Sum<T>;
    using E = Sum<T>;
    static constexpr T mul_op(const T& a, int b, const T& c) {
        return c + a * b;
    }
};

template<class T, int id = -1> struct ChminMin {
    using M = Min<T, id>;
    using E = Min<T>;
    static constexpr T op(const T& a, const T& b) { return std::min(b, a); }
};

template<class T, int id = -1> struct ChminMax {
    using M = Max<T, id>;
    using E = Min<T>;
    static constexpr T op(const T& a, const T& b) { return std::min(b, a); }
};

template<class T, int id = -1> struct ChmaxMin {
    using M = Min<T, id>;
    using E = Max<T>;
    static constexpr T op(const T& a, const T& b) { return std::max(b, a); }
};

template<class T, int id = -1> struct ChmaxMax {
    using M = Max<T, id>;
    using E = Max<T>;
    static constexpr T op(const T& a, const T& b) { return std::max(b, a); }
};


template<class M> struct ReverseMonoid {
    using value_type = typename M::value_type;
    static value_type op(const value_type& a, const value_type& b) {
        return M::op(b, a);
    }
    static value_type id() {
        static_assert(has_id<M>::value, "id is not defined");
        return M::id();
    }
    static value_type inv(const value_type& a, const value_type& b) {
        static_assert(has_inv<M>::value, "inv is not defined");
        return M::inv(b, a);
    }
    static value_type get_inv(const value_type& a) {
        static_assert(has_get_inv<M>::value, "get_inv is not defined");
        return M::get_inv(a);
    }
};

template<class E_> struct MakeAction {
    using M = E_;
    using E = E_;
    using T = typename E_::value_type;
    static T op(const T& a, const T& b) { return E_::op(b, a); }
};

} // namespace Monoid
