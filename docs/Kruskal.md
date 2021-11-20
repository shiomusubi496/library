## 概要

最小全域木を求める。辺をコストの昇順に見てUnionFindでマージしていく。

- `T Kruskal(int V, Edges<T> E)` : 頂点数 `V` 、辺の集合が `E` のグラフに対する最小全域木を求める。 $O(E \log E)$ 。
- `Edges<T> Kruskal_vec(int V, Edges<T> E)` : 最小全域木の辺の集合を返す。 $O(E \log E)$ 。
