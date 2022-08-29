## 概要

半群に対して以下のことができる。

- `DisjointSparseTable(vector<int> v)` : 数列 `v` で初期化する。 $N=\mathrm{len}(a)$ として $\Theta(N \log N)$ 。
- `T prod(int l, int r)` : `op(a[l], a[l+1], ..., a[r-1])` を返す。 $\Theta(1)$ 。
