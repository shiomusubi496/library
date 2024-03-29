## 概要

準同型な作用付きモノイドを扱える。

分配則は成り立たないが、任意の $f \in U$ と $k \in \mathbb N$ に対して、ある $g_{f, k} \in U$ が存在して、どのような $x_1, x_2, \ldots, x_k \in T$ に対しても $g_{f, k}(x_1 \cdot x_2 \cdot \cdots \cdot x_k) = f(x_1) \cdot f(x_2) \cdot \cdots \cdot f(x_k)$ となり、かつ $f, k$ から $g_{f, k}$ を効率よく計算できるときは、 `mul_op` を定義することで使える。

- コンストラクタ
  - `LazySegmentTree()` : 長さ $0$ に初期化する。 $\Theta(N)$ 。
  - `LazySegmentTree(int n)` : 長さ `n` で初期化する。初期値は `e` 。 $\Theta(N)$ 。
  - `LazySegmentTree(vector<T> v)` : 列 `v` で初期化する。 $\Theta(N)$ 。
  - `void init(vector<T> v)` : 列 `v` で初期化する。 $\Theta(N)$ 。
- 取得クエリ
  - `T prod(int l, int r)` : `op(a[l], a[l+1], ..., a[r-1])` を返す。 $\Theta(\log N)$ 。
  - `T get(int k)` : `a[k]` を返す。 $\Theta(\log N)$ 。
  - `T all_prod()` : `op(a[0], a[1], ..., a[N-1])` を返す。 $\Theta(1)$ 。
- 更新クエリ
  - `void set(int k, T x)` : `a[k]` に `x` を代入する。 $\Theta(\log N)$ 。
  - `void apply(int k, U f)` : `a[k]` に `mp(f, a[k])` を代入する。 $\Theta(\log N)$ 。
  - `void update(int k, T upd(T))` : `a[k]` に `upd(a[k])` を代入する。 $\Theta(\log N)$ 。
  - `void apply(int l, int r, U f)` : `a[l], a[l+1], ..., a[r-1]` に `mp(f, a[l]), mp(f, a[l+1]), ..., mp(f, a[r-1])` を代入する。 $\Theta(\log N)$ 。
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

また、以下のクエリに対する遅延セグメント木が `LazySegmentTree` のエイリアスとして作られている。

- `RangeUpdateQueryRangeSumQuery` : 区間代入クエリと区間和クエリを扱える。
- `RangeUpdateQueryRangeMinimumQuery` : 区間代入クエリと区間最小値クエリを扱える。
- `RangeUpdateQueryRangeMaximumQuery` : 区間代入クエリと区間最大値クエリを扱える。
- `RangeAddQueryRangeSumQuery` : 区間加算クエリと区間和クエリを扱える。
- `RangeAddQueryRangeMinimumQuery` : 区間加算クエリと区間最小値クエリを扱える。
- `RangeAddQueryRangeMaximumQuery` : 区間加算クエリと区間最大値クエリを扱える。
- `RangeChminQueryRangeMinimumQuery` : 区間chminクエリと区間最小値クエリを扱える。
- `RangeChminQueryRangeMaximumQuery` : 区間chminクエリと区間最大値クエリを扱える。
- `RangeChmaxQueryRangeMinimumQuery` : 区間chmaxクエリと区間最小値クエリを扱える。
- `RangeChmaxQueryRangeMaximumQuery` : 区間chmaxクエリと区間最大値クエリを扱える。
