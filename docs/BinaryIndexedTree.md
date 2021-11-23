## 概要

数列 `a` に対して、一点加算区間和クエリを高速に扱えるデータ構造。必要なところのみ見るため、セグ木より高速。二項演算 $\cdot$ は以下の条件を満たす必要がある。

- 結合則 : 任意の $A, B, C$ に対して $(A \cdot B) \cdot C = A \cdot (B \cdot C)$
- 単位元の存在 : ある $e$ が存在して、任意の $A$ に対して $A \cdot e = e \cdot A = A$

min/max などが扱える。

- `BinaryIndexedTree(int n, T op(T, T), T e())` : サイズ `n` の BIT を作成する。 $O(n)$ 。
- `void add(int k, T x)` : `a[k]` に `op(a[k], x)` を代入する。 $O(\log n)$ 。
- `T sum(int k)` : `op(a[0], a[1], ..., a[k-1])` を返す。 $O(\log n)$ 。

また、以下の条件を満たすと、さらに多くのことができる。

- 逆元の存在 : 任意の $A$ に対して、 $A \cdot B = e$ なる $B$ が存在する

足し算や bitwise xor などはこれを満たす。

- `BinaryIndexedTree(int n, T op(T, T), T e(), T inv(T))` : サイズ `n` の BIT を作成する。 $O(n)$ 。
- `T sum(int l, int r)` : `op(a[l], a[l+1], ..., a[r-1])` を返す。 $O(\log n)$ 。
- `T get(int k)` : `a[k]` を返す。 $O(\log n)$ 。
- `void set(int k, T x)` : `a[k]` に `x` を代入する。 $O(\log n)$ 。
