## 概要

`EulerTour` の機能を減らしたもの。部分木クエリのみ扱うことで、空間計算量を削減する。

- `EulerTourSubtree(Graph<T> G, int r = 0)` : 木 `G` に対して、頂点 `r` を根としてオイラーツアーを作成する。 $\Theta(N)$ 。
- `EulerTour(Graph<T> G, vector<int> r)` : 森 `G` に対して、頂点列 `r` の頂点を根としてオイラーツアーを作成する。 $\Theta(N)$ 。
- `pair<int, int> get_idx(int v)` : 頂点 `v` に入る index と出る index のペアを返す。 $\Theta(1)$ 。
- `void each_vertex_subtree(int v, void f(int, int))` : 頂点 `v` の部分木の頂点の区間に `f` を適用する。頂点に入る index に値が記録され、残りはは単位元である必要がある。計算量は `f` のそれに比例。
- `void each_edge_subtree(int v, void f(int, int))` : 頂点 `v` の部分木の辺。
