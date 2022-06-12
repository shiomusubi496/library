## 概要

初期値以外の値を持っているか、作用素がかかっている要素だけ持つセグメント木。座標圧縮して通常の遅延セグメント木を使うのでもいいが、オンラインでもできることに利点がある。あと楽。

- コンストラクタ
  - `DynamicLazySegmentTree()` : 長さ $inf$ に初期化する。 $\Theta(\log n)$ 。
  - `DynamicLazySegmentTree(ll n)` : 長さ `n` で初期化する。初期値は `e` 。 $\Theta(\log n)$ 。
  - `DynamicLazySegmentTree(ll n, T v)` : 長さ `n` で初期化する。初期値は `v` 。 $\Theta(\log n)$ 。
  - `void init(ll n, T v)` : 長さ `n` で初期化する。初期値は `v` 。 $\Theta(N)$ 。
- 取得クエリ
  - `T prod(ll l, ll r)` : `op(a[l], a[l+1], ..., a[r-1])` を返す。 $\Theta(\log N)$ 。
  - `T get(ll k)` : `a[k]` を返す。 $\Theta(\log N)$ 。
  - `T all_prod()` : `op(a[0], a[1], ..., a[N-1])` を返す。 $\Theta(1)$ 。
- 更新クエリ
  - `void set(ll k, T x)` : `a[k]` に `x` を代入する。 $\Theta(\log N)$ 。
  - `void apply(ll k, U f)` : `a[k]` に `mp(f, a[k])` を代入する。 $\Theta(\log N)$ 。
  - `void update(ll k, T upd(T))` : `a[k]` に `upd(a[k])` を代入する。 $\Theta(\log N)$ 。
  - `void apply(ll l, ll r, U f)` : `a[l], a[l+1], ..., a[r-1]` に `mp(f, a[l]), mp(f, a[l+1]), ..., mp(f, a[r-1])` を代入する。 $\Theta(\log N)$ 。
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

同様に `DynamicMultiLazySegmentTree` がある。
