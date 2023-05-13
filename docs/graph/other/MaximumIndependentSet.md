## 概要

最小頂点被覆と最大独立集合を求めることができる。

- `MinimumVertexCover(Graph<T> G)` : 最小頂点被覆を計算する。 NP 困難で多項式時間の解法は知られていないが、指数時間の解法が存在し、指数の底を小さくすることで $N \leq 40$ 程度であれば高速に計算できる。
- `int size()` : 大きさを返す。
- `vector<int> get()` : 最小頂点被覆の一つを返す。
- `MaximumIndependentSet(Graph<T> G)` : 最大独立集合を計算する。頂点集合 $S$ が独立集合であることは $V \setminus S$ が頂点被覆であることと同値なので、最小頂点被覆を計算することで計算できる。
- `int size()` : 大きさを返す。
- `vector<int> get()` : 最大独立集合の一つを返す。