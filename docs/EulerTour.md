## 概要

木を dfs 順に並べて列にする。 SegmentTree など列に対するデータ構造を使うことで様々なクエリを扱える。テンプレートに Static Range Minimum Query を扱える構造 StaticRMQ(デフォルトは SparseTable)をとる。

森にも対応している。

- `EulerTour(Graph<T> G, int r = 0)` : 木 `G` に対して、頂点 `r` を根としてオイラーツアーを作成する。 StaticRMQ::init が $\Theta(f(N))$ で動くとき、 $\Theta(N + f(N))$ 。
- `EulerTour(Graph<T> G, vector<int> r)` : 森 `G` に対して、頂点列 `r` の頂点を根としてオイラーツアーを作成する。 `r` に同じ連結成分に属する頂点がある場合は未定義。 StaticRMQ::init が $\Theta(f(N))$ で動くとき、 $\Theta(N + f(N))$ 。
- `pair<int, int> get_idx(int v)` : 頂点 `v` に入る index と出る index のペアを返す。 $\Theta(1)$ 。
- `int lca(int v, int u)` : 頂点 `v` と `u` の最小共通祖先(Lowest Common Ancestor)を返す。 StaticRMQ::prod が $\Theta(f(N))$ で動くとき、 $\Theta(f(N))$ 。
- `void each_vertex_subtree(int v, void f(int, int))` : 頂点 `v` の部分木の頂点の区間に `f` を適用する。頂点に入る index に値が記録され、残りはは単位元である必要がある。計算量は `f` のそれに比例。
- `void each_edge_subtree(int v, void f(int, int))` : 頂点 `v` の部分木の辺。
- `void each_vertex(int u, int v, void f(int, int), void g(int, int))` : `u` - `v` パスの頂点の区間に `f` を適用する。 `f` は親->子の順に計算した値、 `g` は子->親の値を返す。頂点に入る index には元の値が、頂点から出る index にはその逆元が入っている必要がある。計算量は `f` と `g` のそれに比例。
- `void each_edge(int u, int v, void f(int, int), void g(int, int))` : `u` - `v` パスの辺。
