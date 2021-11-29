## 概要

モノイド $(T, \cdot : T \times T \to T)$ 、つまり

- 結合則 : 任意の $A, B, C \in T$ に対して $(A \cdot B) \cdot C = A \cdot (B \cdot C)$
- 単位元の存在 : ある $e \in T$ が存在して、任意の $A \in T$ に対して $A \cdot e = e \cdot A = A$

を満たす構造の列 `a` を扱うデータ構造。 min/max や、加算や乗算、 gcd/lcm など、これを満たすものは多い。

- コンストラクタ
  - `SegmentTree<T>(T op(T, T), T e)` : 二項演算 `op` と単位元 `e` で長さ $0$ に SegmentTree を初期化する。 $\Theta(N)$ 。
  - `SegmentTree<T>(int n, T op(T, T), T e)` : 長さ `n` の SegmentTree を作成する。初期値は `e` 。 $\Theta(N)$ 。
  - `SegmentTree<T>(vector<T> v, T op(T, T), T e)` : 列 `v` で SegmentTree を作成する。 $\Theta(N)$ 。
  - `void init(vector<T> v)` : 列 `v` で SegmentTree を作成する。 $\Theta(N)$ 。
- 変更クエリ
  - `void set(int k, T x)` : `a[k]` に `x` を代入する。 $\Theta(\log N)$ 。
  - `void apply(int k, T x)` : `a[k]` に `op(a[k], x)` を代入する。 $\Theta(\log N)$ 。
  - `void update(int k, T upd(T))` : `a[k]` に `upd(a[k])` を代入する。 $\Theta(\log N)$ 。
- 取得クエリ
  - `T prod(int l, int r)` : `op(a[l], a[l+1], ..., a[r-1])` を返す。 $\Theta(\log (r - l))$ 。
  - `T get(int k)` : `a[k]` を返す。 $\Theta(1)$ 。
  - `T all_prod()` : `op(a[0], a[1], ..., a[N-1])` を返す。 $\Theta(1)$ 。
- セグメント木上の二分探索
  - `int max_right(int l, bool f(T))` :  
`[l, r)` に対して `f` が `true` を返すような最大の `r` を返す。`f(e) = true` である必要がある。 $\Theta(\log N)$ 。  
厳密には、以下の条件を共に満たす `r` (のうち1つ)を返す。  
    - `r = l` または `f(op(a[l], a[l+1], ..., a[r-1])) = true`
    - `r = n` または `f(op(a[l], a[l+1], ..., a[r])) = false`
  - `int min_left(int r, bool f(T))` :  
`[l, r)` に対して `f` が `true` を返すような最小の `l` を返す。`f(e) = true` である必要がある。 $\Theta(\log N)$ 。  
厳密には、以下の条件を共に満たす `l` (のうち1つ)を返す。  
    - `l = r` または `f(op(a[l], a[l+1], ..., a[r-1])) = true`
    - `l = 0` または `f(op(a[l-1], a[l], ..., a[r-1])) = false`

また、次の $3$ つのセグメント木が `SegmentTree` を継承して作られている。

- `RSQ` : `Range Sum Query` 用のセグ木。
- `RMiQ` : `Range Minimum Query` 用のセグ木。
- `RMaQ` : `Range Maximum Query` 用のセグ木。
