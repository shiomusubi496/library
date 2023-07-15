#pragma once

#include "../../other/template.hpp"

template<class T, class MaxQueue = std::priority_queue<T>,
         class MinQueue = prique<T>>
class SlopeTrick {
    T minval;
    T addL, addR;
    MaxQueue L;
    MinQueue R;

public:
    SlopeTrick(T a = 0) {
        addL = addR = 0;
        minval = a;
        L.push(-inf);
        R.push(inf);
    }
    void add(T a) { minval += a; }
    void a_x(T a) {
        minval += std::max<T>(a - (R.top() + addR), 0);
        R.push(a - addR);
        L.push((R.top() + addR) - addL);
        R.pop();
    }
    void x_a(T a) {
        minval += std::max<T>((L.top() + addL) - a, 0);
        L.push(a - addL);
        R.push((L.top() + addL) - addR);
        L.pop();
    }
    void abs(T a) {
        a_x(a);
        x_a(a);
    }
    void prefix_min() {
        R = {};
        R.push(inf);
    }
    void suffix_min() {
        L = {};
        L.push(-inf);
    }
    void slide(T a) {
        addL += a;
        addR += a;
    }
    void slide_min(T a, T b) {
        assert(a <= b);
        addL += a;
        addR += b;
    }
    T min() const { return minval; }
    std::pair<T, T> argmin() const { return {L.top() + addL, R.top() + addR}; }
};

/**
 * @brief SlopeTrick
 * @docs docs/data-struct/other/SlopeTrick.md
 */
