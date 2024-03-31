## 概要

多点評価をする。

- `vector<T> multipoint_evaluation(FormalPowerSeries<T> f, vector<T> p)` : 各 $n = \deg(f), m = \lvert p \rvert$ として、 $0 \leq i < m$ について $f(p_i)$ を計算する。 $\Theta(n \log n + m \log^2 m)$ 。

特に評価する点が等比数列 $p_i = ar^i$ になっているときに Chirp-Z Transform を用いるとより高速に計算できる。 $t_i = \frac{i(i-1)}{2}$ とおくと $ki = t_{k+i}-t_{k}-t_{i}$ であることより、 $b_i = [x^i] f$ とすると、

$f(ar^i) = \sum_{k=0}^{n-1} b_k(ar^i)^k = \sum_{k=0}^{n-1} b_ka^kr^{ki} = r^{-t_i} \sum_{k=0}^{n-1} b_ka^kr^{-t_k}r^{t_{k+i}}$

より畳み込める。長さ $n, n+m-1$ の列を畳み込んだ $2n+m-2$ 個の値のうち、 $[n-1, n+m-1)$ のみ用いるので $n+m-1$ の巡回畳み込みで良い。

- `vector<T> multipoint_evaluation_geometric(FormalPowerSeries<T> f, T a, T r, ll m)` : 各 $n = \deg(f)$ として、 $0 \leq i < m$ について $f(ar^i)$ を計算する。 $\Theta((n+m)\log(n+m))$ 。
