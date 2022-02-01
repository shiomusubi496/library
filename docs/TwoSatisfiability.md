## 概要

SAT(Satisfiability) とは、論理式が与えられたとき、それを真にするような変数の割り当てが存在するかを判定する問題。

$(a \lor b) \land (c \lor d) \land \cdots$ というように、高々 2 個のリテラルが $\lor$ で結ばれた形のクロージャを $\land$ で結んだ形の論理式に対する SAT は 2-SAT と呼ばれる。

一般の SAT は多項式時間の解法が知られていないが、 2-SAT はグラフを使うことでクロージャの数に対し線形時間で解ける。

- `TwoSatisfiability(int n)` : `n` 変数 $x_0, x_1, \ldots, x_{n-1}$ からなる 2-SAT を作成する。 $\Theta(n)$ 。
- `int neg(int k)` : 変数 `k` の否定の変数の index を返す。 $\Theta(1)$ 。
- `void add_clause(int i, bool f, int j, bool g)` : $(x_i = j) \lor (x_j = g)$ の形のクロージャを作成する。 $\Theta(1)$ 。
- `void add_if(int a, int b)` : $a \Rightarrow b$ 、つまり $\lnot a \lor b$ の形のクロージャを作成する。 $\Theta(1)$ 。
- `void add_or(int a, int b)` : $a \lor b$ の形のクロージャを作成する。 $\Theta(1)$ 。
- `void add_nand(int a, int b)` : $\lnot (a \land b)$ 、つまり $\lnot a \lor \lnot b$ の形のクロージャを作成する。 $\Theta(1)$ 。
- `void add_eq(int a, int b)` : $a \Leftrightarrow b$ 、つまり $(\lnot a \lor b) \land (\lnot b \lor a)$ の形のクロージャを作成する。 $\Theta(1)$ 。
- `void add_neq(int a, int b)` : $a \not\Leftrightarrow b$ 、つまり $(a \lor b) \land (\lnot b \lor \lnot a)$ の形のクロージャを作成する。 $\Theta(1)$ 。
- `void add_true(int a)` : $a$ の形のクロージャを作成する。 $\Theta(1)$ 。
- `void add_false(int a)` : $\lnot a$ の形のクロージャを作成する。 $\Theta(1)$ 。
- `vector<bool> sat()` : 現在の論理式が充足可能ならその割り当ての一例を、充足不可能なら空のリストを返す。
