## 概要

隣り合う要素の差が 1 であるような数列に対して Range Minimum Query を行う。 Sparse Table や Segment Tree よりもオーダーが良い。

- `PlusMinusOneRMQ(vector<T> v)` : リスト `v` で初期化する。 $\Theta(N)$ 。
- `T prod(int l, int r)` : `min(v[l], v[l+1], ..., v[r-1])` を返す。 $\Theta(1)$ 。
