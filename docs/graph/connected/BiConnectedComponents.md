## 概要

グラフの二重連結成分分解をする。一つ頂点を消してもなお連結であるような極大な頂点集合を二重連結成分と呼ぶ。二重頂点連結成分などとも。

孤立点を成分として認めるかは場合によって嬉しさが変わりそうなので bool 値で指定するようにしている。

- `BiConnectedComponents(Graph G, bool allow_isolated = false)` : グラフを与える。孤立点を許すかを第二引数で与える。 $\Theta(n)$
- `int size()` : 二重連結成分数。
- `int operator[](int k)` : 辺 k が属する二重連結成分の番号を返す。
- `vector<vector<int>> groups()` : 各二重連結成分の頂点集合を返す。
- `UnweightedGraph bct()` : Block-Cut Tree を返す。 $[0, n)$ がもとの頂点に対応し、 $[n, n+size())$ が二重連結成分に対応する。
