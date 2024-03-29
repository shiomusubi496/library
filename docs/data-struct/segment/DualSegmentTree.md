## 概要

ある集合 $T$ に対し、 $T$ から $T$ への写像 $U$ のうち、

- 写像は閉じている : 任意の $f, g \in U$ に対して、 $f \circ g \in U$

を満たすものを扱える。

- コンストラクタ
  - `DualSegmentTree()` : 長さ $0$ に初期化する。 $\Theta(N)$ 。
  - `DualSegmentTree(int n)` : 長さ `n` で初期化する。初期値は `e` 。 $\Theta(N)$ 。
  - `DualSegmentTree(vector<T> v)` : 列 `v` で初期化する。 $\Theta(N)$ 。
  - `void init(vector<T> v)` : 列 `v` で初期化する。 $\Theta(N)$ 。
- 取得クエリ
  - `T get(int k)` : `a[k]` を返す。 $\Theta(\log N)$ 。
- 更新クエリ
  - `void set(int k, T x)` : `a[k]` に `x` を代入する。 $\Theta(\log N)$ 。
  - `void apply(int k, U f)` : `a[k]` に `mp(f, a[k])` を代入する。 $\Theta(\log N)$ 。
  - `void update(int k, T upd(T))` : `a[k]` に `upd(a[k])` を代入する。 $\Theta(\log N)$ 。
  - `void apply(int l, int r, U f)` : `a[l], a[l+1], ..., a[r-1]` に `mp(f, a[l]), mp(f, a[l+1]), ..., mp(f, a[r-1])` を代入する。 $\Theta(\log N)$ 。

また、以下のクエリに対する双対セグメント木が `DualSegmentTree` のエイリアスとして作られている。

- `RangeUpdateQuery` : 区間代入クエリを扱える。
- `RangeAddQuery` : 区間加算クエリを扱える。
- `RangeChminQuery` : 区間chminクエリを扱える。
- `RangeChmaxQuery` : 区間chmaxクエリを扱える。
