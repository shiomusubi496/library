## 概要

数直線上に頂点が並んでいると考えて、 2 頂点の位置関係がいくつか与えられたとき、他の 2 頂点の位置関係を特定する操作が行える。

- `WeightedUnionFind(int N)` : サイズ `N` の重み付き UnionFind を作成する。 $\Theta(N)$ 。
- `pair<int, int> merge(int x, int y, T w)` : `(x の位置) + w = (y の位置)` とする。併合後の根とそうでない方の pair を返す。ただし、もともと同じ連結成分に属する場合、矛盾が無ければ根と -1 の pair 、矛盾があれば根と -2 の pair を返す。ならし $\Theta(\alpha(N))$ 。
- `int find(int x)` : 要素 `x` の連結成分の根を返す。ならし $\Theta(\alpha(N))$ 。
- `T weight(int x)` : 要素 `x` と根の位置関係を返す。ならし $\Theta(\alpha(N))$ 。
- `T diff(int x, int y)` : 要素 `x` と要素 `y` の位置関係を返す。ならし $\Theta(\alpha(N))$ 。
- `bool same(int x, int y)` : 要素 `x` と要素 `y` が同じ集合に属するかを判定する。ならし $\Theta(\alpha(N))$ 。
- `int size(int x)` : 要素 `x` の属する集合の要素数を返す。ならし $\Theta(\alpha(N))$ 。
- `bool is_root(int x)` : 要素 `x` が属する集合の代表元が `x` であるかを返す。 $\Theta(1)$ 。
- `vector<vector<int>> groups()` : 「「集合に属する要素のリスト」のリスト」を返す。ならし $\Theta(N\alpha(N))$ 。
