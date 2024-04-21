## 概要

- `T bostan_mori(FormalPowerSeries<T> P, FormalPowerSeries<T> Q, ll n)` : $[x^n] \frac{P(x)}{Q(x)}$ を求める。 $\Theta(d \log d \log n)$ 。
- `T kth_term(FormalPowerSeries<T> C, FormalPowerSeries<T> A, ll n)` : $d = \lvert A \rvert = \lvert Q \rvert - 1$ として $a_i = A_i (0 \leq i < d), \sum_{k=0}^{d}C_{d-k}a_{i+k} = 0$ なる数列 $a$ について $a_n$ を返す。 $\Theta(d \log d \log n)$ 。
