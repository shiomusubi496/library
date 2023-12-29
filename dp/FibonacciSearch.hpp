#pragma once

#include "../other/template.hpp"

template<class T> class FibonacciSearch {
    static std::vector<T> fib;
    static void extend(T n) {
        while (fib.back() < n)
            fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
    }

public:
    template<class F, class Comp>
    static std::pair<T, function_result_type<F>> minimize(T low, T high, F&& f,
                                                          Comp cmp) {
        extend(high - low + 2);
        int k = 0;
        while (fib[k] < high - low + 2) ++k;
        T l = low - 1, r = low - 1 + fib[k];
        auto res = f(r - fib[--k]);
        bool flag = true;
        for (; k > 2; --k) {
            T m1 = r - fib[k], m2 = l + fib[k];
            if (m2 > high) {
                r = m2;
                res = flag ? res : f(m1);
                flag = false;
                continue;
            }
            auto v1 = flag ? res : f(m1);
            auto v2 = flag ? f(m2) : res;
            if (cmp(v1, v2)) {
                r = m2;
                res = v1;
                flag = false;
            }
            else {
                l = m1;
                res = v2;
                flag = true;
            }
        }
        return {l + 1, res};
    }
    template<class F>
    static std::pair<T, function_result_type<F>> minimize(T low, T high,
                                                          F&& f) {
        return minimize(low, high, std::forward<F>(f),
                        std::less<function_result_type<F>>());
    }
    template<class F>
    static std::pair<T, function_result_type<F>> maximize(T low, T high,
                                                          F&& f) {
        return minimize(low, high, std::forward<F>(f),
                        std::greater<function_result_type<F>>());
    }
};

template<class T> std::vector<T> FibonacciSearch<T>::fib = {0, 1, 1};

/**
 * @brief FibonacciSearch
 * @docs docs/FibonacciSearch.md
 */
