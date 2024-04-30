## 概要

三重辺連結成分にグラフを分解する。

- `ThreeEdgeConnectedComponents(Graph<T> G)` : グラフ `G` で初期化する。 $\Theta(V + E)$ 。
- `int size()` : 二辺連結成分の個数を返す。 $\Theta(1)$ 。
- `int operator[](int k)` : 頂点 `k` の属する二辺連結成分の番号を返す。 $\Theta(1)$ 。
- `vector<vector<int>> groups()` : 二辺連結成分のリストを返す。 $\Theta(V)$ 。
