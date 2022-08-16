## 概要

グラフの構造体。 `vector<vector<edge<T>>>` を継承している。

- `Graph(int N)` : 頂点数 `N` のグラフを作成する。
- `int add_edge(int a, int b, bool d = false)` : 頂点 `a` と頂点 `b` の間に辺をはる。 `d` が `true` ならば有向辺、 `d` が `false` なら無向辺。何本目の辺かを返す。
- `int add_edge(int a, int b, T c, bool d = false)` : 頂点 `a` と頂点 `b` の間にコスト `c` の辺をはる。 `d` が `true` ならば有向辺、 `d` が `false` なら無向辺。何本目の辺かを返す。
