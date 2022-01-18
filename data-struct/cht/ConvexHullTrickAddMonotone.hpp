#pragma once

#include "../../other/template.hpp"

template<class T = ll, bool is_max = false> class ConvexHullTrickAddMonotone {
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
    std::deque<Line> que;
    bool is_necessary(const typename std::deque<Line>::iterator& itr) {
        if (itr == que.begin() || itr == prev(que.end())) return true;
        if (itr->a == prev(itr)->a) return itr->b < prev(itr)->b;
        if (itr->a == next(itr)->a) return itr->b < next(itr)->b;
        return (__int128_t)(itr->b - prev(itr)->b) * (next(itr)->a - itr->a)
            <  (__int128_t)(itr->b - next(itr)->b) * (prev(itr)->a - itr->a);
    }
  public:
    ConvexHullTrickAddMonotone() = default;
    void add_line(T a, T b) {
        if IF_CONSTEXPR (is_max) a = - a, b = - b;
        typename std::deque<Line>::iterator itr;
        if (que.empty() || que.back().a <= a) {
            que.push_back(Line{a, b});
            itr = prev(que.end());
        }
        else {
            assert(a <= que.front().a);
            que.push_front(Line{a, b});
            itr = que.begin();
        }
        if (!is_necessary(itr)) {
            que.erase(itr);
            return;
        }
        while (itr != que.begin() && !is_necessary(prev(itr))) {
            que.pop_back(); que.pop_back();
            que.push_back(Line{a, b});
            itr = prev(que.end());
        }
        while (itr != prev(que.end()) && !is_necessary(next(itr))) {
            que.pop_front(); que.pop_front();
            que.push_front(Line{a, b});
            itr = que.begin();
        }
        if (itr != que.begin()) prev(itr)->nxt = &*itr;
        if (itr != prev(que.end())) itr->nxt = &*next(itr);
        else itr->nxt = nullptr;
    }
    T get_min(T x) const {
        auto itr = lower_bound(que.begin(), que.end(), Line{x, 0, true});
        if IF_CONSTEXPR (is_max) return - itr->get(x);
        return itr->get(x);
    }
    T inc_get_min(T x) {
        while (que.size() > 1 && que.begin()->get(x) > next(que.begin())->get(x)) que.pop_front();
        if IF_CONSTEXPR (is_max) return - que.front().get(x);
        return que.front().get(x);
    }
    T dec_get_min(T x) {
        while (que.size() > 1 && prev(que.end())->get(x) > prev(que.end(), 2)->get(x)) que.pop_back();
        if IF_CONSTEXPR (is_max) return - que.back().get(x);
        return que.back().get(x);
    }
    bool empty() const {
        return que.empty();
    }
};

/**
 * @brief ConvexHullTrickAddMonotone
 * @docs docs/ConvexHullTrickAddMonotone.md
 */
