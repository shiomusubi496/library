## 概要

単位元以外の値を持っている要素だけ持つセグメント木。座標圧縮して通常のセグメント木を使うのでもいいが、オンラインでもできることに利点がある。 ~~あと何も考えずにできるのも利点。~~

- コンストラクタ
  - `SegmentTree()` : 長さ $0$ に SegmentTree を初期化する。 $\Theta(1)$ 。
  - `SegmentTree(int n)` : 長さ `n` の SegmentTree を作成する。初期値は `e` 。 $\Theta(\log \log n)$ 。
  - `void init(int n)` : 列 `v` で SegmentTree を作成する。 $\Theta(\log \log n)$ 。
- 変更クエリ
  - `void set(int k, T x)` : `a[k]` に `x` を代入する。 $\Theta(\log N)$ 。
  - `void apply(int k, T x)` : `a[k]` に `op(a[k], x)` を代入する。 $\Theta(\log N)$ 。
  - `void update(int k, T upd(T))` : `a[k]` に `upd(a[k])` を代入する。 $\Theta(\log N)$ 。
- 取得クエリ
  - `T prod(int l, int r)` : `op(a[l], a[l+1], ..., a[r-1])` を返す。 $\Theta(\log n)$ 。
  - `T get(int k)` : `a[k]` を返す。 $\Theta(\log n)$ 。
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
