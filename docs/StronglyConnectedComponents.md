## 概要

グラフの強連結成分分解をする。有向グラフで使われることを想定している。

- `StronglyConnectedComponennts(Graph<T> G)` : グラフ `G` で初期化する。 $N=G.size()$ として $O(N)$ 。
- `int size()` : 強連結成分の個数を返す。 $O(1)$ 。
- `int operator[](int k)` : 頂点 `k` の所属する強連結成分の番号を返す。 $O(1)$ 。
- `vector<vector<int>> groups()` : 強連結成分のリストを返す。 $O(N)$ 。
- `Graph<T> dag()` : 強連結成分を圧縮した後のグラフは DAG になることが知られているので、それを返す。 $O(N)$ 。
