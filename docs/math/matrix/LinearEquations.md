## 概要

線形連立方程式を解く。解が存在する場合は解の一つと、解空間の基底を返す。

- `LinearEquations(Matrix A, vector b)` : 行列 `A` とベクトル `b` で初期化する。 $\Theta(n^2)$ 。
- `void add_equation(vector<int> a, int b)` : 線形方程式を一つ追加する。 $\Theta(n)$ 。
- `bool solve()` : $Ax = b$ なるベクトル $x$ を求める。 $\Theta(n^3)$ 。
- `Matrix get_solution()` : 解の一つを返す。 $\Theta(n)$ 。
- `Matrix get_solution_space()` : 解空間の基底を返す。 $\Theta(n^2)$ 。
