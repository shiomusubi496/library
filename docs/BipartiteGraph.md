## 概要

二部グラフ判定をする。

- `BipartiteGraph(Graph<T> G)` : グラフ `G` で初期化する。 $\Theta(V + E)$ 。
- `bool is_bipartite()` : グラフ `G` が二部グラフであるかを返す。 $\Theta(1)$ 。
- `vector<bool> get_label()` : 各頂点がどちらに割り当てられたかを返す。二部グラフでない場合は未定義。 $\Theta(V)$ 。
