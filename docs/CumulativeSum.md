## 概要

区間和など区間に対するクエリを扱える。ただし、二項演算子 $\cdot$ は以下の条件を満たす必要がある。

- 結合則 : 任意の $A, B, C$ に対して $(A \cdot B) \cdot C = A \cdot (B \cdot C)$
- 単位元の存在 : ある $e$ が存在して、任意の $A$ に対して $A \cdot e = e \cdot A = A$ が成り立つ。
- 逆元の存在 : 任意の $A$ に対して、 $A \cdot B = e$ となる $B$ が存在する

例えば、足し算、掛け算、 bitwise xor などがこの条件を満たす。

以下の計算量は `op` が定数時間で動くと仮定したもの。 `op` 内部の計算量が $O(f(n))$ の時、以下の計算量は全て $O(f(n))$ 倍になる。

- `SparseTable(vector<int> a, T op(T, T), T e(), T inv(T))` : リスト `a` と二項演算 `op` 、単位元を返す `e` 、及び逆元を返す `inv` で初期化する。 $N=\mathrm{len}(a)$ として $O(N)$ 。
- `T query(int l, int r)` : `op(a[l], a[l+1], ..., a[r-1])` を返す。 $O(1)$ 。
