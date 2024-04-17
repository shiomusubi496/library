## 概要

最小全域木を求める。辺をコストの昇順に見てUnionFindでマージしていく。

- `pair<T, Edges<T>> Kruskal(int V, Edges<T> E)` : 頂点数 `V` 、辺の集合が `E` のグラフに対する最小全域木を求める。 $\Theta(E \log E)$ 。
