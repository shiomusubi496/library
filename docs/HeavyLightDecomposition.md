## 概要

木に対する様々なクエリを扱える。計算量はオイラーツアーより悪いが、パスに対するクエリや部分木に対するクエリを同時に扱える。

うまく木をいくつかの列に分解することで、パスを $O(\log N)$ 個の列に分割する。

- `HeavyLightDecomposition(Graph<T> G)` : グラフ `G` に大して HL 分解をする。 $\Theta(N)$ 。
- `pair<int, int> get_idx(int v)` : 頂点 `v` に入る index と出る index のペアを返す。 $\Theta(1)$ 。
- `int lca(int v, int u)` : 頂点 `v` と `u` の最小共通祖先(Lowest Common Ancestor)を返す。 StaticRMQ::prod が $\Theta(f(N))$ で動くとき、 $\Theta(f(N))$ 。
- `void each_vertex_subtree(int v, void f(int, int))` : `v` の部分木の頂点に対して `f` を適用する。計算量は `f` のそれに比例。
- `void each_edge_subtree(int v, void f(int, int))` : 同様に辺に対して適用する。
- `void each_vertex(int l, int r, void f(int, int), void g(int, int))` : `l` から `r` までのパスの頂点に対して `f` を適用する。可換でない演算を使う場合、 `g` は逆向きに演算をした場合の結果を返すべき。 `Monoid::ReverseMonoid` を活用する。 `f` が $\Theta(t)$ で動く場合、計算量 $\Theta(t \log N)$ 。
- `void each_edge(int l, int r, void f(int, int), void g(int, int))` : 同様に辺に対して適用する。
