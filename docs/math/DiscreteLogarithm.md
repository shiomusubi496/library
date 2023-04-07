## 概要

$x, b, m$ が与えられたとき、 $x^k \equiv b \pmod m$ なる最小の非負整数 $k$ を求める。

- `ll baby_step_giant_step(T a, T b, U f, ll MAX)` : $f$ がたかだか $MAX$ の周期を持つとき、 $f^k(a)=b$ なる最小の非負整数 $k$ を返す。存在しない場合は $-1$ 。 $\Theta(\sqrt{MAX})$ 。
- `ll discrete_logarithm(ll a, ll x, ll b, ll m)` : $a \times x^k \equiv b \pmod m$ なる最小の非負整数 $k$ を返す。存在しない場合は $-1$ 。 $\Theta(\sqrt{m})$ 。
- `ll discrete_logarithm(ll x, ll b, ll m)` : $a=1$ の場合。離散対数。 $\Theta(\sqrt{m})$ 。
