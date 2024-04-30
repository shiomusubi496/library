## 概要

多項式補完。

- `FormalPowerSeries<T> polynomial_interpolation(vector<T> x, vector<T> y)` : $n = \lvert x \rvert$ としたとき、 $0 \leq i < n$ について $f(x_i) = y_i$ なる $n$ 次未満の多項式は一つに定まるので、それを返す。 $x$ は distinct でなければならない。 $\Theta(n \log^2 n)$ 。

- `FormalPowerSeries<T> polynomial_interpolation_geometric(T a, T r, vector<T> y)` : $n = \lvert y \rvert$ としたとき、 $0 \leq i < n$ について $f(ar^i) = y_i$ なる $n$ 次未満の多項式は一つに定まるので、それを返す。 $ar^i$ は distinct でなければならない。 $\Theta(n \log n)$ 。
