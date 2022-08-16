#pragma once

#include "../../other/template.hpp"
#include "../../other/monoid.hpp"

template<class M> class SlidingWindowAggregation {
private:
    using T = typename M::value_type;
    std::stack<T> lst, rst;
    std::stack<T> lsm, rsm;
    T internal_all_prod() const {
        assert(!empty());
        if (lst.empty()) return rsm.top();
        if (rst.empty()) return lsm.top();
        return M::op(lsm.top(), rsm.top());
    }

public:
    SlidingWindowAggregation() = default;
    int size() const { return lst.size() + rst.size(); }
    bool empty() const { return lst.empty() && rst.empty(); }
    void push(const T& x) {
        rst.push(x);
        if (rsm.empty()) rsm.push(rst.top());
        else rsm.push(M::op(rsm.top(), rst.top()));
    }
    template<class... Args> void emplace(Args&&... args) {
        rst.emplace(std::forward<Args>(args)...);
        if (rsm.empty()) rsm.push(rst.top());
        else rsm.push(M::op(rsm.top(), rst.top()));
    }
    void pop() {
        assert(!empty());
        if (lst.empty()) {
            lst.push(rst.top());
            lsm.push(rst.top());
            rst.pop();
            rsm.pop();
            while (!rst.empty()) {
                lst.push(rst.top());
                lsm.push(M::op(rst.top(), lsm.top()));
                rst.pop();
                rsm.pop();
            }
        }
        lst.pop();
        lsm.pop();
    }
    template<bool AlwaysTrue = true,
             typename std::enable_if<Monoid::has_id<M>::value &&
                                     AlwaysTrue>::type* = nullptr>
    T all_prod() const {
        if (empty()) return M::id();
        return internal_all_prod();
    }
    template<bool AlwaysTrue = true,
             typename std::enable_if<!Monoid::has_id<M>::value &&
                                     AlwaysTrue>::type* = nullptr>
    T all_prod() const {
        return internal_all_prod();
    }
};

/**
 * @brief SlidingWindowAggregation(SWAG)
 * @docs docs/data-struct/other/SlidingWindowAggregation.md
 */
