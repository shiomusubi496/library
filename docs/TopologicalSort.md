## 概要

トポロジカルソートをする。 DAG に対して使われることを想定している。

- `TopologicalSort(Graph<T> G)` : `G` のグラフに対してトポロジカルソートをする。 $\Theta(N)$ 。
- `vector<int> get()` : トポロジカルソートした後の頂点の並びを返す。 $\Theta(N)$ 。
