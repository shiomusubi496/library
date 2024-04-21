## 概要

二次元平面上の $N$ 点 $(x_1, y_1), \ldots, (x_N, y_N)$ について、頂点 $i$ と頂点 $j$ の距離がマンハッタン距離 ($\lvert x_i - x_j \rvert + \lvert y_i - y_j \rvert$) で与えられるときの最小全域木を求める。

- `ManhattanMST(vector<pair<T, T>> ps)` : 計算する。 $\Theta(N \log N)$ 。
- `T cost()` : 全域木の辺のコストの合計を返す。 $\Theta(1)$ 。
- `Edges<T> edges()` : 全域木の辺を返す。 $\Theta(N)$ 。
