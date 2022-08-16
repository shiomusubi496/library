## 概要

Cartesian Tree を用いて RMQ を LCA に帰着して解く。 $\pm 1$ RMQ に帰着することで LCA は前処理 $\Theta(N)$ 、各クエリ $\Theta(1)$ で解けるため、 Cartesian Tree を求めるのは $\Theta(N)$ であることと合わせて、前処理 $\Theta(N)$ 各クエリ $\Theta(1)$ が達成される。

- `LCARMQ(std::vector<T> v)` : リスト `v` で初期化する。 $\Theta(N)$ 。
- `T prod(int l, int r)` : `min(v[l], v[l+1], ..., v[r-1])` を返す。 $\Theta(1)$ 。
