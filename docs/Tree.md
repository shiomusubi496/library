## 概要

木に対する基本的なクエリを詰め合わせた構造体。ダブリングを使っているので、空間計算量は $\Theta(E + V \log V)$ であるため注意。

- `Tree(Graph<T> G, int r = 0)` : 頂点 `r` を根としてグラフ `G` で初期化する。ここで、 `G` は木である必要がある。 $\Theta(V \log V)$ 。
- `int depth(int v)` : 頂点 `v` の深さ(根からの距離)を返す。 $\Theta(1)$ 。
- `int parent(int v)` : 頂点 `v` の親を返す。ただし頂点 `v` が根である場合 $-1$ が返る。 $\Theta(1)$ 。
- `int kth_parent(int v, int k)` : 頂点 `v` の `k` 番目に近い祖先を返す。存在しない場合 $-1$ が返る。 $\Theta(\log V)$ 。
- `int lca(int s, int t)` : 頂点 `s` と頂点 `t` の最小共通祖先(Lowest Common Ancestor)を返す。 $\Theta(\log V)$ 。
- `int nxt(int s, int t)` : 頂点 `s` から頂点 `t` へのパスにおいて、 `s` の次の頂点を返す。 $\Theta(\log V)$ 。
- `Edges<T> path(int s, int t)` : 頂点 `s` から頂点 `t` へのパスに含まれる辺を返す。パスの長さを $P$ として $\Theta(P)$ 。
- `Graph<T> rooted()` : 根付き木を返す。
