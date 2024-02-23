# 概要

与えられた $a, b, m, n$ について、  $\min_{i=0}^{n-1} ((ai+b) \bmod m)$ を計算する。

この $\min$ を更新する $i$ は $\log m$ 個の等差数列になることを利用している。

- `vector<tuple<ll, ll, ll>> linear_mod_min_arithmetic_progressions(ll a, ll b, ll m)` : $(p_i, q_i, n_i)$ を返し、 $0 \leq j < n_i$ について $p_i + q_i \times j$ は最小値を更新し、 $p_i + q_i \times n = p_{i+1}$ を満たす。 $ab=0$ のとき空配列を返すことに注意。 $\Theta(\log m)$ 。
- `PLL linear_mod_min(ll a, ll b, ll m, ll n)` : $\min_{i=0}^{n-1} ((ai+b) \bmod m)$ を返す。
