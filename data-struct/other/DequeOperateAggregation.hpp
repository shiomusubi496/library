#pragma once

#include "../../other/template.hpp"
#include "../../other/monoid.hpp"

template<class M> class DequeOperateAggregation {
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
    DequeOperateAggregation() = default;
    int size() const { return lst.size() + rst.size(); }
    bool empty() const { return lst.empty() && rst.empty(); }
    void push_front(const T& x) {
        lst.push(x);
        if (lsm.empty()) lsm.push(lst.top());
        else lsm.push(M::op(lst.top(), lsm.top()));
    }
    template<class... Args> void emplace_front(Args&&... args) {
        lst.emplace(std::forward<Args>(args)...);
        if (lsm.empty()) lsm.push(lst.top());
        else lsm.push(M::op(lst.top(), lsm.top()));
    }
    void push_back(const T& x) {
        rst.push(x);
        if (rsm.empty()) rsm.push(rst.top());
        else rsm.push(M::op(rsm.top(), rst.top()));
    }
    template<class... Args> void emplace_back(Args&&... args) {
        rst.emplace(std::forward<Args>(args)...);
        if (rsm.empty()) rsm.push(rst.top());
        else rsm.push(M::op(rsm.top(), rst.top()));
    }
    void pop_front() {
        assert(!empty());
        if (lst.empty()) {
            const int rn = rst.size() / 2;
            const int ln = rst.size() - rn;
            std::vector<T> rv;
            rv.reserve(rn);
            while (!rsm.empty()) rsm.pop();
            rep (rn) {
                rv.push_back(rst.top());
                rst.pop();
            }
            rep (ln) {
                lst.push(rst.top());
                rst.pop();
                if (lsm.empty()) lsm.push(lst.top());
                else lsm.push(M::op(lst.top(), lsm.top()));
            }
            rep (rn) {
                rst.push(rv.back());
                rv.pop_back();
                if (rsm.empty()) rsm.push(rst.top());
                else rsm.push(M::op(rsm.top(), rst.top()));
            }
        }
        lst.pop();
        lsm.pop();
    }
    void pop_back() {
        assert(!empty());
        if (rst.empty()) {
            const int ln = lst.size() / 2;
            const int rn = lst.size() - ln;
            std::vector<T> lv;
            lv.reserve(ln);
            while (!lsm.empty()) lsm.pop();
            rep (ln) {
                lv.push_back(lst.top());
                lst.pop();
            }
            rep (rn) {
                rst.push(lst.top());
                lst.pop();
                if (rsm.empty()) rsm.push(rst.top());
                else rsm.push(M::op(rsm.top(), rst.top()));
            }
            rep (ln) {
                lst.push(lv.back());
                lv.pop_back();
                if (lsm.empty()) lsm.push(lst.top());
                else lsm.push(M::op(lst.top(), lsm.top()));
            }
        }
        rst.pop();
        rsm.pop();
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
 * @brief DequeOperateAggregation
 * @docs docs/data-struct/other/DequeOperateAggregation.md
 */
