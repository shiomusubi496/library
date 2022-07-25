## 概要

セグ木の各区切り目の高さをルーラー関数ではなくランダムにした感じのデータ構造。なので insert や erase ができる。

- コンストラクタ
  - `SkipList()` : 長さ $0$ に初期化する。 $\Theta(1)$ 。
  - `SkipList(Rand rnd)` : 乱数生成器を `rnd` で初期化する。 $\Theta(1)$ 。
  - `SkipList(vector<T> , Rand rnd = Rand())` : 列 `v` で初期化する。期待 $\Theta(N)$ 。
  - `void init(vector<T> v)` : 列 `v` で初期化する。期待 $\Theta(N)$ 。
- 取得クエリ
  - `T prod(int l, int r)` : `op(a[l], a[l+1], ..., a[r-1])` を返す。期待 $\Theta(\log N)$ 。
  - `T get(int k)` : `a[k]` を返す。期待 $\Theta(\log N)$ 。
  - `T all_prod()` : `op(a[0], a[1], ..., a[N-1])` を返す。 $\Theta(1)$ 
  - `int size()` : 列の長さを返す。 $\Theta(1)$ 。
  - `bool empty()` : 列が空であるかを返す。 $\Theta(1)$ 。
- 追加/削除クエリ
  - `void insert(int k, T x)` : `k` 番目に `x` を挿入する。期待 $\Theta(\log N)$ 。
  - `void erase(int k)` : `k` 番目の要素を削除する。期待 $\Theta(\log N)$ 。
- 更新クエリ
  - `void set(int k, T x)` : `a[k]` に `x` を代入する。期待 $\Theta(\log N)$ 。
  - `void apply(int k, U f)` : `a[k]` に `mp(f, a[k])` を代入する。期待 $\Theta(\log N)$ 。
  - `void update(int k, T upd(T))` : `a[k]` に `upd(a[k])` を代入する。期待 $\Theta(\log N)$ 。
  - `void apply(int l, int r, U f)` : `a[l], a[l+1], ..., a[r-1]` に `mp(f, a[l]), mp(f, a[l+1]), ..., mp(f, a[r-1])` を代入する。期待 $\Theta(\log N)$ 。
- セグメント木上の二分探索
  - `int max_right(int l, bool f(T))` :  
`[l, r)` に対して `f` が `true` を返すような最大の `r` を返す。`f(e) = true` である必要がある。期待 $\Theta(\log N)$ 。  
厳密には、以下の条件を共に満たす `r` (のうち1つ)を返す。  
    - `r = l` または `f(op(a[l], a[l+1], ..., a[r-1])) = true`
    - `r = n` または `f(op(a[l], a[l+1], ..., a[r])) = false`
  - `int min_left(int r, bool f(T))` :  
`[l, r)` に対して `f` が `true` を返すような最小の `l` を返す。`f(e) = true` である必要がある。期待 $\Theta(\log N)$ 。  
厳密には、以下の条件を共に満たす `l` (のうち1つ)を返す。  
    - `l = r` または `f(op(a[l], a[l+1], ..., a[r-1])) = true`
    - `l = 0` または `f(op(a[l-1], a[l], ..., a[r-1])) = false`
