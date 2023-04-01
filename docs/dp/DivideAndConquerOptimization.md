## 概要

$\displaystyle\mathrm{dp}[i][j] = \min_{0 \leq k \leq j} (\mathrm{dp}[i-1][k]+A_{k,j})$ の形の DP を行う。 $A$ が totally monotone なら SMAWK を、 monotone なら Monotone Minima を用いる。

- `vector<vector<T>> divide_and_conquer_optimization(int m, int n, F A)` : totally monotone な A に対して 上記の dp を行う。 $\Theta(nm)$ 。
- `vector<vector<T>> divide_and_conquer_optimization_monotone(int m, int n, F A)` : monotone な A に対して上記の dp を行う。 $\Theta(nm \log n)$ 。
