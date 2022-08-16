## 概要

モノイド $(T, \cdot : T \times T \to T)$ 、つまり

- 結合則 : 任意の $A, B, C \in T$ に対して $(A \cdot B) \cdot C = A \cdot (B \cdot C)$
- 単位元の存在 : ある $e \in T$ が存在して、任意の $A \in T$ に対して $A \cdot e = e \cdot A = A$

を満たす構造のうち、

- 任意の $A, B, C \in T$ に対して $B \neq C$ ならば $A \cdot B \neq A \cdot C$

を満たす構造の列を扱えるデータ構造。例えば、足し算や bitwise xor などがこの条件を満たす。

- `CumulativeSum(vector<int> v)` : リスト `v` で初期化する。 $N=\mathrm{len}(a)$ として $\Theta(N)$ 。
- `T prod(int l, int r)` : `op(a[l], a[l+1], ..., a[r-1])` を返す。 $\Theta(1)$ 。
