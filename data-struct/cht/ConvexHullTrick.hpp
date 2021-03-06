#pragma once

#include "../../other/template.hpp"

template<class T = ll, bool is_max = false, class LargeT = __int128_t> class ConvexHullTrick {
  protected:
    struct Line {
        T a, b;
        bool is_query;
        int idx;
        mutable ll nxt_a, nxt_b;
        mutable bool has_nxt;
        T get(T x) const { return a * x + b; }
        T get_nxt(T x) const { return nxt_a * x + nxt_b; }
        Line() = default;
        Line(T a, T b, int id, bool i = false) : a(a), b(b), idx(id), is_query(i), has_nxt(false) {}
        friend bool operator<(const Line& lhs, const Line& rhs) {
            assert(!lhs.is_query || !rhs.is_query);
            if (lhs.is_query) {
                if (!rhs.has_nxt) return true;
                return rhs.get(lhs.a) < rhs.get_nxt(lhs.a);
            }
            if (rhs.is_query) {
                if (!lhs.has_nxt) return false;
                return lhs.get(rhs.a) > lhs.get_nxt(rhs.a);
            }
            return lhs.a == rhs.a ? lhs.b < rhs.b : lhs.a < rhs.a;
        }
    };
    int line_count = 0;
    std::set<Line> st;
    bool is_necessary(const typename std::set<Line>::iterator& itr) {
        if (itr != st.begin()     && itr->a == prev(itr)->a) return itr->b < prev(itr)->b;
        if (itr != prev(st.end()) && itr->a == next(itr)->a) return itr->b < next(itr)->b;
        if (itr == st.begin() || itr == prev(st.end())) return true;
        return (LargeT)(itr->b - prev(itr)->b) * (next(itr)->a - itr->a)
            <  (LargeT)(itr->b - next(itr)->b) * (prev(itr)->a - itr->a);
    }
  public:
    ConvexHullTrick() = default;
    int add_line(T a, T b) {
        if IF_CONSTEXPR (is_max) a = - a, b = - b;
        auto itr = st.emplace(a, b, line_count).first;
        if (!is_necessary(itr)) {
            st.erase(itr);
            return line_count++;
        }
        while (itr != st.begin()     && !is_necessary(prev(itr))) st.erase(prev(itr));
        while (itr != prev(st.end()) && !is_necessary(next(itr))) st.erase(next(itr));
        if (itr != st.begin()) {
            prev(itr)->has_nxt = true;
            prev(itr)->nxt_a = itr->a; prev(itr)->nxt_b = itr->b;
        }
        if (itr != prev(st.end())) {
            itr->has_nxt = true;
            itr->nxt_a = next(itr)->a; itr->nxt_b = next(itr)->b;
        }
        else itr->has_nxt = false;
        return line_count++;
    }
    Line get_min_line(T x) const {
        auto itr = st.lower_bound(Line{x, 0, -1, true});
        Line res{*itr};
        if IF_CONSTEXPR (is_max) res.a = - res.a, res.b = - res.b;
        return res;
    }
    T get_min(T x) const { return get_min_line(x).get(x); }
    bool empty() const { return st.empty(); }
};

/**
 * @brief ConvexHullTrick
 * @docs docs/ConvexHullTrick.md
 */
