## 概要

数列 `a` に対して区間最小値など区間に関するクエリを扱える。ただし、二項演算子 $\cdot$ は以下の条件を満たす必要がある。

- 結合則 : 任意の $A, B, C$ に対して $(A \cdot B) \cdot C = A \cdot (B \cdot C)$
- 単位元の存在 : ある $e$ が存在して、任意の $A$ に対して $A \cdot e = e \cdot A = A$

min/max や、加算や乗算、 gcd/lcm など、これを満たすものは多い。

- `SegmentTree(int n, T op(T, T), T e())` : 長さ `n` の SegmentTree を作成する。初期値は `e()` 。 $O(N)$ 。
- `SegmentTree(vector<T> v, T op(T, T), T e())` : 数列 `v` で SegmentTree を作成する。 $O(N)$ 。
- `void set(int k, T x)` : `a[k]` に `x` を代入する。 $O(\log N)$ 。
- `void apply(int k, T x)` : `a[k]` に `op(a[k], x)` を代入する。 $O(\log N)$ 。
- `void update(int k, T upd(T))` : `a[k]` に `upd(a[k])` を代入する。 $O(\log N)$ 。
- `T prod(int l, int r)` : `op(a[l], a[l+1], ..., a[r-1])` を返す。 $O(\log (r - l))$ 。
- `T get(int k)` : `a[k]` を返す。 $O(1)$ 。
- `int max_right(int l, bool f(T))` :  
`[l, r)` に対して `f` が `true` を返すような最大の `r` を返す。  
厳密には、以下の条件を共に満たす `r` (のうち1つ)を返す。  
  - `r = l` または `f(op(a[l], a[l+1], ..., a[r-1])) = true`
  - `r = n` または `f(op(a[l], a[l+1], ..., a[r])) = false`
- `int min_left(int r, bool f(T))` :  
`[l, r)` に対して `f` が `true` を返すような最小の `l` を返す。  
厳密には、以下の条件を共に満たす `l` (のうち1つ)を返す。  
  - `l = r` または `f(op(a[l], a[l+1], ..., a[r-1])) = true`
  - `l = 0` または `f(op(a[l-1], a[l], ..., a[r-1])) = false`
