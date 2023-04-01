## 概要

分割統治をしながら計算をすることで $\log$ がつく代わりにオンラインの問題をオフラインに変換できる(オンライン・オフライン変換)。

$\displaystyle\mathrm{dp}[j] = \min_{0 \leq k \leq j} (\mathrm{dp}[k]+A_{k,j})$ の形の DP を行う。 $A$ が totally monotone なら SMAWK を、 monotone なら Monotone Minima を用いると良い。

- `vector<int> online_offline_dp(int n, F A)` : 上記の DP を行う。 $\Theta(n \log n)$ 。
