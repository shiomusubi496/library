## 概要

木に対する様々なクエリを扱える。計算量はオイラーツアーより悪いが、パスに対するクエリや部分木に対するクエリを同時に扱える。

うまく木をいくつかの列に分解することで、パスを $O(\log N)$ 個の列に分割する。

- `HeavyLightDecomposition(Graph<T> G)` : グラフ `G` に大して HL 分解をする。 $\Theta(N)$ 。
- `pair<int, int> get_idx(int v)` : 頂点 `v` に入る index と出る index のペアを返す。 $\Theta(1)$ 。
- `int lca(int v, int u)` : 頂点 `v` と `u` の最小共通祖先(Lowest Common Ancestor)を返す。$\Theta(\log N)$ 。
- `void each_vertex_subtree(int v, void f(int, int))` : `v` の部分木の頂点に対して `f` を適用する。 `f` が $1$ 回呼ばれる。
- `void each_edge_subtree(int v, void f(int, int))` : 同様に辺に対して適用する。
- `void each_vertex(int l, int r, void f(int, int), void g(int, int))` : `l` から `r` までのパスの頂点に対して `f` を適用する。可換でない演算を使う場合、 `g` には `Monoid::ReverseMonoid` を用いたセグ木などを使う。 `f` が $\Theta(\log N)$ 回呼ばれる。
- `void each_edge(int l, int r, void f(int, int), void g(int, int))` : 同様に辺に対して適用する。
