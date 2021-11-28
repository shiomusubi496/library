## 概要

半群 $(T, \cdot : T \times T \to T)$ 、つまり

- 結合則 : 任意の $A, B, C \in T$ に対して $(A \cdot B) \cdot C = A \cdot (B \cdot C)$

を満たす構造の列を扱えるデータ構造。 `SparseTable` より制約が弱く、足し算など多くの演算が使える。

以下の計算量は `op` が定数時間で動くと仮定したもの。 `op` 内部の計算量が $O(f(n))$ の時、以下の計算量は全て $O(f(n))$ 倍になる。

- `DisjointSparseTable(vector<int> v, T op(T, T))` : 数列 `v` と二項演算 `op` で初期化する。 $N=\mathrm{len}(a)$ として $O(N \log N)$ 。
- `T query(int l, int r)` : `op(a[l], a[l+1], ..., a[r-1])` を返す。 $O(1)$ 。
