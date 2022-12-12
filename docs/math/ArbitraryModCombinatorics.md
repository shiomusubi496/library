## 概要

任意 mod で二項係数を計算する。前計算部分に $\Theta(\min(m, n))$ かかるため注意。

- `void set_mod(int m)` : mod を設定する。 $m$ は `int` に収まる程度を想定。 $O(\log^2 m)$ くらいかかる。
- `int comb(ll n, ll r)` : ${}_nC_r \bmod m$ を計算する。 $O(\log^2 m)$ くらいかかる。

