## 概要

群 $G$ に対し、 $n$ 個の値 $a_i \in G$ があり、それらの間の関係が与えられたときにそれらから関係を導ける。特に指定しなければ $G$ は加算による群。非可換群も可能。

- `WeightedUnionFind(int N)` : サイズ $N$ の重み付き UnionFind を作成する。 $\Theta(N)$ 。
- `pair<int, int> merge(int x, int y, T w)` : $a_y^{-1}a_x = w$ の条件を与える。併合後の根とそうでない方の組を返す。ただし、もともと同じ連結成分に属する場合、矛盾が無ければ根と -1 の組、矛盾があれば根と -2 の組を返す。ならし $\Theta(\alpha(N))$ 。
- `int find(int x)` : $x$ の連結成分の根を返す。ならし $\Theta(\alpha(N))$ 。
- `T weight(int x)` : $x$ の根を $r$ として $a_r^{-1}a_x$ を返す。ならし $\Theta(\alpha(N))$ 。
- `T diff(int x, int y)` : $a_y^{-1}a_x$ を返す。 `same(x, y)` でなければエラー。ならし $\Theta(\alpha(N))$ 。
- `bool same(int x, int y)` : $x$ と $y$ が同じ集合に属するかを判定する。ならし $\Theta(\alpha(N))$ 。
- `int size(int x)` : $x$ の属する集合の要素数を返す。ならし $\Theta(\alpha(N))$ 。
- `bool is_root(int x)` : $x$ が属する集合の代表元が $x$ であるかを返す。 $\Theta(1)$ 。
- `vector<vector<int>> groups()` : 「「集合に属する要素のリスト」のリスト」を返す。 $\Theta(N\alpha(N))$ 。
