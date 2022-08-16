## 概要

最小全域木を求める。コストが小さい辺を取って連結成分を広げていくイメージ。

- `T Prim(Graph<T> G)` : グラフ `G` に対する最小全域木を求める。 $\Theta(E \log V)$ 。
- `Edges<T> Prim_vec(Graph<T> G)` : 最小全域木の辺の集合を返す。 $\Theta(E \log V)$ 。
