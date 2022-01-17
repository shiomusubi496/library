## 概要

bit 演算を活用して前計算 $\Theta(N)$ 各クエリ $\Theta(1)$ を実現した Range Minimum Query。 LCA に帰着させた RMQ よりも定数倍がいい。また、 Range Maximum Query にも対応している(はず)。

- `LinearRMQ(vector<T> v)` : 列 `v` で初期化する。 $\Theta(N)$ 。
- `T prod(int l, int r)` : `op(v[l], v[l+1], ..., v[r-1])` を返す。 $\Theta(1)$ 。
