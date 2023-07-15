## 概要

多項式補完。

- `FormalPowerSeries<T> polynomial_interpolation(vector<T> x, vector<T> y)` : $n = \lvert x \rvert$ としたとき、 $1 \leq i \leq n$ について $f(x_i) = y_i$ なる $n$ 次未満の多項式は一つに定まるので、それを返す。 $\Theta(n \log^2 n)$ 。
