## 概要

初期値以外の値を持っている要素だけ持つセグメント木。座標圧縮して通常のセグメント木を使うのでもいいが、オンラインでもできることに利点がある。あと楽。

- コンストラクタ
  - `DynamicSegmentTree()` : 長さ $inf$ に SegmentTree を初期化する。 $\Theta(\log n)$ 。
  - `DynamicSegmentTree(ll n)` : 長さ `n` の SegmentTree を作成する。初期値は `e` 。 $\Theta(\log n)$ 。
  - `DynamicSegmentTree(ll n, T v)` : 長さ `n` の SegmentTree を作成する。初期値は `v` 。 $\Theta(\log n)$ 。
  - `void init(ll n, T v)` : 長さ `n` で SegmentTree を作成する。初期値は `v` 。 $\Theta(\log n)$ 。
- 変更クエリ
  - `void set(ll k, T x)` : `a[k]` に `x` を代入する。 $\Theta(\log N)$ 。
  - `void apply(ll k, T x)` : `a[k]` に `op(a[k], x)` を代入する。 $\Theta(\log N)$ 。
  - `void update(ll k, T upd(T))` : `a[k]` に `upd(a[k])` を代入する。 $\Theta(\log N)$ 。
  - `void reset(ll k)` : `a[k]` に初期値を代入する。 $\Theta(\log N)$ 。
  - `void reset(ll l, ll r)` : `a[l], a[l+1], ..., a[r-1]` に初期値を代入する。 $\Theta(\log N)$ 。
- 取得クエリ
  - `T prod(ll l, ll r)` : `op(a[l], a[l+1], ..., a[r-1])` を返す。 $\Theta(\log n)$ 。
  - `T get(ll k)` : `a[k]` を返す。 $\Theta(\log n)$ 。
  - `T all_prod()` : `op(a[0], a[1], ..., a[N-1])` を返す。 $\Theta(1)$ 。
- セグメント木上の二分探索
  - `ll max_right(ll l, bool f(T))` :  
`[l, r)` に対して `f` が `true` を返すような最大の `r` を返す。`f(e) = true` である必要がある。 $\Theta(\log N)$ 。  
厳密には、以下の条件を共に満たす `r` (のうち1つ)を返す。  
    - `r = l` または `f(op(a[l], a[l+1], ..., a[r-1])) = true`
    - `r = n` または `f(op(a[l], a[l+1], ..., a[r])) = false`
  - `ll min_left(ll r, bool f(T))` :  
`[l, r)` に対して `f` が `true` を返すような最小の `l` を返す。`f(e) = true` である必要がある。 $\Theta(\log N)$ 。  
厳密には、以下の条件を共に満たす `l` (のうち1つ)を返す。  
    - `l = r` または `f(op(a[l], a[l+1], ..., a[r-1])) = true`
    - `l = 0` または `f(op(a[l-1], a[l], ..., a[r-1])) = false`
