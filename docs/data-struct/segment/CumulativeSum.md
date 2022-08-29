## 概要

群に対して以下のようなことができる。例えば、足し算や bitwise xor などがこの条件を満たす。

- `CumulativeSum(vector<int> v)` : リスト `v` で初期化する。 $N=\mathrm{len}(a)$ として $\Theta(N)$ 。
- `T prod(int l, int r)` : `op(a[l], a[l+1], ..., a[r-1])` を返す。 $\Theta(1)$ 。
