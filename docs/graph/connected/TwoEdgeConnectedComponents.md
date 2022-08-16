## 概要

二辺(あるいは二重辺)連結成分にグラフを分解する。二辺連結成分とは、任意の $1$ 辺を取り除いても連結である、つまり橋のない連結成分のこと。 `LowLink` を継承している。

- `TwoEdgeConnectedComponents(Graph<T> G)` : グラフ `G` で初期化する。 $\Theta(V + E)$ 。
- `int size()` : 二辺連結成分の個数を返す。 $\Theta(1)$ 。
- `int operator[](int k)` : 頂点 `k` の属する二辺連結成分の番号を返す。 $\Theta(1)$ 。
- `vector<vector<int>> groups()` : 二辺連結成分のリストを返す。 $\Theta(V)$ 。
- `Graph<T> tree()` : 二辺連結成分を縮約した後のグラフは森になる(元のグラフが連結な場合は木になる)ことが知られているので、それを返す。 $\Theta(V + E)$ 。
