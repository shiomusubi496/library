## 概要

ヒストグラムの最大長方形を求める。

- `void max_rectangle_of_histogram(vector<int> A, F f)` : $(l, r, n)$ のうち、 $\min_{l \leq i < r} A_i = n \land \left(l=0 \lor A_{l-1} < n\right) \land \left(r=\lvert A\rvert - 1 \lor A_{r+1} < n\right)$ を満たす全てについて $f(l, r, n)$ を呼び出す。 $\Theta(\lvert A\rvert)$ 。

これを用いてグリッドについても解ける。

- `void max_rectangle(vector<vector<bool>> A, F f)` : $(u, l, d, r)$ のうち、 $u \leq i < d, l \leq j < r$ について $A_{i,j} = false$ であるような極大なもの全てについて $f(u, l, d, r)$ を呼び出す。 $\Theta(HW)$ 。
