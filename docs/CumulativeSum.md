## 概要

群 $(T, \cdot : T \times T \to T)$ 、つまり

- 結合則 : 任意の $A, B, C \in T$ に対して $(A \cdot B) \cdot C = A \cdot (B \cdot C)$
- 単位元の存在 : ある $e \in T$ が存在して、任意の $A \in T$ に対して $A \cdot e = e \cdot A = A$ が成り立つ。
- 逆元の存在 : 任意の $A \in T$ に対して、ある $B \in T$ が存在して、 $A \cdot B = e$

例えば、足し算や bitwise xor などがこの条件を満たす。

以下の計算量は `op` が定数時間で動くと仮定したもの。 `op` 内部の計算量が $O(f(n))$ の時、以下の計算量は全て $O(f(n))$ 倍になる。

- `SparseTable(vector<int> a, T op(T, T), T e, T inv(T))` : リスト `a` と二項演算 `op` 、単位元 `e` 、及び逆元を返す `inv` で初期化する。 $N=\mathrm{len}(a)$ として $O(N)$ 。
- `T query(int l, int r)` : `op(a[l], a[l+1], ..., a[r-1])` を返す。 $O(1)$ 。
