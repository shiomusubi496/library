## 概要

燃やす埋める。 $n$ 個の $01$ 変数 $x_0, x_1, \ldots, x_{n-1}$ に対し、 $x_i$ が $0$ かつ $x_j$ が $1$ のときコスト $k$ 、のような条件を最小カットに落とす。

- `KProjectSelectionProblem(int n, int m)` : $n$ 変数 $m$ 値で初期化する。
- `KProjectSelectionProblem(vector<int> xs)` : 各変数 $xs[i]$ 値で初期化する。

色々な条件を扱えるので下のコードを参照。
