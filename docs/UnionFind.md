## 概要

集合を併合する操作や、ある要素が属する集合の代表元を問い合わせる操作を行える。

- `UnionFind(int N)` : サイズ `N` の UnionFind を作成する。 $\Theta(N)$ 。
- `pair<int, int> merge(int x, int y)` : 要素 `x` の属する集合と要素 `y` の属する集合を併合する。併合後の根とそうでない方の pair を返す。ただし、もともと同じ集合に属する場合は根と -1 の pair を返す。ならし $\Theta(\alpha(N))$ 。
- `int find(int x)` : 要素 `x` の属する集合の代表元を返す。ならし $\Theta(\alpha(N))$ 。
- `bool same(int x, int y)` : 要素 `x` と要素 `y` が同じ集合に属するかを判定する。ならし $\Theta(\alpha(N))$ 。
- `int size(int x)` : 要素 `x` の属する集合の要素数を返す。ならし $\Theta(\alpha(N))$ 。
- `bool is_root(int x)` : 要素 `x` が属する集合の代表元が `x` であるかを返す。 $\Theta(1)$ 。
- `vector<vector<int>> groups()` : 「「集合に属する要素のリスト」のリスト」を返す。ならし $\Theta(N\alpha(N))$ 。
