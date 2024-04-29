## 概要

木の重心を求めるアルゴリズム。

重心とは、ある頂点とその頂点に接続する辺を全て削除したとき、各連結成分の頂点数が元の木の頂点数の半分以下になる頂点を言う。多くの場合重心は 1 つだが、ある辺を削除するとちょうど元の木の半分の頂点数の連結成分が 2 つできる場合、その辺の端点 2 つが重心となる。その場合は辺(の中点)を重心とする流儀もあるらしい？

- `TreeCentroids(Graph<T> G)` : 木の重心を求める。 $\Theta(N)$ 。
- `vector<int> get()` : 重心を返す。 $\Theta(1)$ 。
- `bool has_one_centroid()` : 重心が 1 つであるか否かを返す。 $\Theta(1)$ 。

また、木の重心とそれに接続する辺を全て削除し、各連結成分に対し同じように重心を求めていくと、その再帰の深さはたかだか $\lceil\log N\rceil$ となる。一度の再帰で連結成分の頂点数の最大値が半分以下になることによる。

よって、各再帰の深さで各連結成分の頂点数に対し線形や準線形の時間計算量の操作を行うとき、全体での時間計算量はそれが $\log N$ 倍になるだけである。これがいわゆる重心分解。 [Frequency Table of Tree Distance](https://shiomusubi496.github.io/library/graph/tree/FrequencyTableofTreeDistance.hpp) や [Contour Query](https://shiomusubi496.github.io/library/graph/tree/ContourQuery.hpp) など。

- `TreeDecomposition(Graph<T> G)` : 木を重心分解する。 $\Theta(N \log N)$ 。
- `int get_root()` : 最初の重心を返す。 $\Theta(1)$ 。
- `UnweightedGraph get()` : 有向木を返す。この木は、各重心について、それを削除した後にできた各連結成分の重心が子となっている。 $\Theta(N)$ 。
