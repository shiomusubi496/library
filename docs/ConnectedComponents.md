## 概要

グラフの連結成分分解をする。無向グラフで使われることを想定している。

- `ConnectedComponennts(Graph<T> G)` : グラフ `G` で初期化する。 $N=G.size()$ として $\Theta(N)$ 。
- `int size()` : 連結成分の個数を返す。 $\Theta(1)$ 。
- `int operator[](int k)` : 頂点 `k` の所属する連結成分の番号を返す。 $\Theta(1)$ 。
- `vector<vector<int>> groups()` : 連結成分のリストを返す。 $\Theta(N)$ 。
