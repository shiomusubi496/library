#pragma once

#include "../../other/template.hpp"

template<class T = ll> class ConvexHullTrick {
  protected:
    struct Line {
        T a, b;
        bool is_query;
        mutable const Line* nxt;
        T get(T x) const { return a * x + b; }
        Line() = default;
        Line(T a, T b, bool i = false) : a(a), b(b), is_query(i), nxt(nullptr) {}
        friend bool operator<(const Line& lhs, const Line& rhs) {
            assert(!lhs.is_query || !rhs.is_query);
            if (lhs.is_query) {
                if (rhs.nxt == nullptr) return true;
                return rhs.get(lhs.a) < rhs.nxt->get(lhs.a);
            }
            if (rhs.is_query) {
                if (lhs.nxt == nullptr) return false;
                return lhs.get(rhs.a) > lhs.nxt->get(rhs.a);
            }
            return lhs.a == rhs.a ? lhs.b < rhs.b : lhs.a < rhs.a;
        }
    };
    std::set<Line> st;
    bool is_necessary(const typename std::set<Line>::iterator& itr) {
        if (itr == st.begin() || itr == prev(st.end())) return true;
        if (itr->a == prev(itr)->a) return itr->b < prev(itr)->b;
        if (itr->a == next(itr)->a) return itr->b < next(itr)->b;
        return (__int128_t)(itr->b - prev(itr)->b) * (next(itr)->a - itr->a)
            <  (__int128_t)(itr->b - next(itr)->b) * (prev(itr)->a - itr->a);
    }
  public:
    ConvexHullTrick() = default;
    void add_line(T a, T b) {
        typename std::set<Line>::iterator itr = st.insert(Line(a, b)).first;
        if (!is_necessary(itr)) {
            st.erase(itr);
            return;
        }
        while (itr != st.begin()     && !is_necessary(prev(itr))) st.erase(prev(itr));
        while (itr != prev(st.end()) && !is_necessary(next(itr))) st.erase(next(itr));
        if (itr != st.begin()) prev(itr)->nxt = &*itr;
        if (itr != prev(st.end())) itr->nxt = &*next(itr);
        else itr->nxt = nullptr;
    }
    Line get_min_line(T x) const {
        auto itr = st.lower_bound(Line{x, 0, true});
        return *itr;
    }
    T get_min(T x) const {
        auto itr = st.lower_bound(Line{x, 0, true});
        return itr->get(x);
    }
    bool empty() const {
        return st.empty();
    }
};

/**
 * @brief ConvexHullTrick
 * @docs docs/ConvexHullTrick.md
 */
