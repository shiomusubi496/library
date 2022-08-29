## 概要

可換モノイドを扱う。 min/max などが扱える。

- `BinaryIndexedTree(int n)` : サイズ `n` の BIT を作成する。 $\Theta(n)$ 。
- `void add(int k, T x)` : `a[k]` に `op(a[k], x)` を代入する。 $\Theta(\log n)$ 。
- `T sum(int k)` : `op(a[0], a[1], ..., a[k-1])` を返す。 $\Theta(\log n)$ 。

また、逆演算が存在する場合、以下も使える。足し算や bitwise xor などはこれを満たす。

- `BinaryIndexedTree(int n)` : サイズ `n` の BIT を作成する。 $\Theta(n)$ 。
- `T sum(int l, int r)` : `op(a[l], a[l+1], ..., a[r-1])` を返す。 $\Theta(\log n)$ 。
- `T get(int k)` : `a[k]` を返す。 $\Theta(\log n)$ 。
- `void set(int k, T x)` : `a[k]` に `x` を代入する。 $\Theta(\log n)$ 。
