## 概要

最小全域木を求める。辺をコストの昇順に見てUnionFindでマージしていく。

- `T Prim(int V, Edges<T> Ed)` : 頂点数 `V` 、辺の集合が `Ed` のグラフに対する最小全域木を求める。
- `Edges<T> Prim_vec(int V, Edges<T> Ed)` : 最小全域木の辺の集合を返す。
