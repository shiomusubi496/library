#pragma once

#include "../../other/template.hpp"
#include "Convolution.hpp"

template<class T>
class RelaxedConvolution {
private:
    std::vector<T> a, b;
    std::vector<std::vector<T>> a2, b2;
    std::vector<T> c;

public:
    RelaxedConvolution() = default;
    RelaxedConvolution(int n) {
        a.reserve(n);
        b.reserve(n);
        c.reserve(2 * n);
    }

    T next(T x, T y) {
        const int n = a.size();
        a.push_back(x);
        b.push_back(y);
        int m = n + 1;
        int t = m & -m;
        if (t < 32) {
            if (m < 32) {
                c.push_back(0);
                rep (i, n + 1) c[n] += a[i] * b[n - i];
            }
            else {
                rep (i, m & 31) c[n] += a[i] * b[n - i];
                rep (i, m & 31) c[n] += a[n - i] * b[i];
            }
        }
        else if (t == m) {
            std::vector<T> x(t), y(t);
            rep (i, t) {
                x[i] = a[i];
                y[i] = b[i];
            }
            c = convolution(x, y);
        }
        else {
            int k = popcnt(t - 1);
            std::vector<T> z(t * 2);
            {
                std::vector<T> x(t * 2), y(t * 2);
                if ((int)a2.size() <= k) {
                    rep (i, t * 2 - 1) x[i] = a[i];
                    number_theoretic_transform(x);
                    a2.resize(k + 1);
                    a2[k] = x;
                }
                else {
                    x = a2[k];
                }
                rep (i, t) y[i] = b[n + 1 - t + i];
                number_theoretic_transform(y);
                rep (i, t * 2) z[i] += x[i] * y[i];
            }
            {
                std::vector<T> x(t * 2), y(t * 2);
                rep (i, t) x[i] = a[n + 1 - t + i];
                number_theoretic_transform(x);
                if ((int)b2.size() <= k) {
                    rep (i, t * 2 - 1) y[i] = b[i];
                    number_theoretic_transform(y);
                    b2.resize(k + 1);
                    b2[k] = y;
                }
                else {
                    y = b2[k];
                }
                rep (i, t * 2) z[i] += x[i] * y[i];
            }
            inverse_number_theoretic_transform(z);
            rep (i, t) c[n + i] += z[t - 1 + i];
        }
        return c[n];
    }
};

/**
 * @brief Relaxed Convolution(オンライン畳み込み)
 * @docs docs/math/convolution/RelaxedConvolution.md
 * @see https://qiita.com/Kiri8128/items/1738d5403764a0e26b4c
 */
