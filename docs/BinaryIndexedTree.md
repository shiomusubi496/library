## 概要

モノイド $(T, \cdot : T \times T \to T)$ 、つまり

- 結合則 : 任意の $A, B, C \in T$ に対して $(A \cdot B) \cdot C = A \cdot (B \cdot C)$
- 単位元の存在 : ある $e \in T$ が存在して、任意の $A \in T$ に対して $A \cdot e = e \cdot A = A$

を満たす構造の列を扱えるデータ構造。 min/max などが扱える。

- `BinaryIndexedTree(int n, T op(T, T), T e)` : サイズ `n` の BIT を作成する。 $O(n)$ 。
- `void add(int k, T x)` : `a[k]` に `op(a[k], x)` を代入する。 $O(\log n)$ 。
- `T sum(int k)` : `op(a[0], a[1], ..., a[k-1])` を返す。 $O(\log n)$ 。

また、以下の条件を満たすと、さらに多くのことができる。

- 逆元の存在 : 任意の $A \in T$ に対して、ある $B \in T$ が存在して、 $A \cdot B = e$

足し算や bitwise xor などはこれを満たす。

- `BinaryIndexedTree(int n, T op(T, T), T e, T inv(T))` : サイズ `n` の BIT を作成する。 $O(n)$ 。
- `T sum(int l, int r)` : `op(a[l], a[l+1], ..., a[r-1])` を返す。 $O(\log n)$ 。
- `T get(int k)` : `a[k]` を返す。 $O(\log n)$ 。
- `void set(int k, T x)` : `a[k]` に `x` を代入する。 $O(\log n)$ 。
