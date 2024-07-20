## 概要

$i=0,1,\ldots,w-1$ について $l+i, r+i$ のマージを同時に行う。

- `UnionFind static_range_parallel_union_find(int n, vector<array<int, 3>> qs)` : クエリが static な場合。 $(l_i, r_i, w_i)$ 受け取りマージ後の uf を返す。 $\Theta((N+Q)\alpha(N))$ 。

また、 dynamic にも処理できる。こちらは $\log$ が付く。

- `RangeParallelUnionFind(int n)` : 初期化。 $\Theta(n \log n)$ 。
- `vector<pair<int, int>> merge(int x, int y, int w)` : 返り値はこのクエリで $p$ を根とする木が $q$ の木にマージされたような $(p, q)$ の一覧。全体で $\Theta(N\log\alpha(N))$ 。
- `UnionFind get_uf()` : uf として返す。 $\Theta(n)$ 。

他は通常の uf と同等の計算量・機能。
