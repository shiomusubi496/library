## 概要

冪等半群 $(T, \cdot : T \times T \to T)$ 、つまり

- 結合則 : 任意の $A, B, C \in T$ に対して $(A \cdot B) \cdot C = A \cdot (B \cdot C)$
- 冪等性 : 任意の $A \in T$ に対して $A \cdot A = A$

を満たす構造の列を扱うデータ構造。例えば、 `max, min, gcd, lcm` などがこの条件を満たす。

以下の計算量は `op` が定数時間で動くと仮定したもの。 `op` 内部の計算量が $\Theta(f(n))$ の時、以下の計算量は全て $\Theta(f(n))$ 倍になる。

- `SparseTable(vector<int> v)` : リスト `v` で初期化する。 $N=\mathrm{len}(v)$ として $\Theta(N \log N)$ 。
- `T prod(int l, int r)` : `op(a[l], a[l+1], ..., a[r-1])` を返す。 $\Theta(1)$ 。
