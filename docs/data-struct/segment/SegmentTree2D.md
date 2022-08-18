## 概要

二次元セグ木。

- `SegmentTree2D()` : コンストラクタ。 $\Theta(1)$ 。
- `void add_point(ll x, ll y)` : 点 `(x, y)` を追加する。 $\Theta(1)$ 。
- `void build()` : 二次元セグ木を構築する。たぶん $\Theta(N \log N)$ 。
- `void update(ll x, ll y, Upd upd)` : `upd` を使ってアップデートする。 $\Theta(\log^2 N)$ 。
- `void apply(ll x, ll y, T a)` : `a[x][y] = M::op(a[x][y], a)` とする。 $\Theta(\log^2 N)$ 。
- `void set(ll x, ll y, T a)` : `a[x][y] = a` とする。 $\Theta(\log^2 N)$ 。
- `T prod(ll l, ll r, ll u, ll d)` : $\displaystyle\sum_{l \leq x < r}\sum_{u \leq y < y}a[x][y]$ とする(演算はM::op)。 $\Theta(\log^2 N)$ 。
- `T get(ll x, ll y)` : `a[x][y]` を返す。 $\Theta(\log N)$ 。
- `T all_prod()` : 全部の和を返す。 $\Theta(1)$ 。
