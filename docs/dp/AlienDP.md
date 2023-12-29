## 概要

下に凸な関数 $f : [L, R] \cap \mathbb{Z} \to \mathbb{Z}$ があり、与えられた $x$ に対し $f(x)$ を計算したいとき、任意の $p$ に対し $g(p) = \min_t f(t)-pt$ を効率よく求められるなら $f(x)$ をうまく求められる。 noshi91 さんの解説が分かりやすい。

$f: T \to U, g: U \to U$ としている。

- `U alien_dp_convex(U low, U high, T x, U g(U))` : 上記の通り。

- `U alien_dp_concave(U low, U high, T x, U g(U))` : 上に凸な関数で $g(p) = \max_t f(t)-pt$ としたとき。

- `T k_edge_shortest_path(int n, int k, T f(int, int))` : $i \to j$ にコスト $f(i, j)$ の辺が張られていて、 $f$ が Monge のとき、 $1-n$ パスの $k$ 辺最短距離は下に凸になる。
