## 概要

完全永続 UF。

- `PersistentUnionFind(int n)` : サイズ `n` の UF を作成し、 $a_{-1}$ とする。 $\Theta(n)$ 。
- `pair<pair<int, int>, int> merge(int x, int y, int t)` : これが $i$ 回目(0-indexed)の `merge` 操作のとき、 $a_{t}$ において $x$ と $y$ をつなげた UF を $a_{i}$ とする。返り値は通常の UF の返り値と $i$ のペア。 $\Theta(\frac{\log^2 n}{\log\log n})$ 。
- `int find(int x, int t)` : $t$ 回目の `merge` 操作の直後の $x$ の属する集合の代表元を返す。 $\Theta(\frac{\log^2 n}{\log\log n})$ 。
- `bool same(int x, int y, int t)` : $t$ 回目の `merge` 操作の直後の要素 $x$ と要素 $y$ が同じ集合に属するかを判定する。 $\Theta(\frac{\log^2 n}{\log\log n})$ 。
- `int size(int x, int t)` : $t$ 回目の `merge` 操作の直後の要素 $x$ の属する集合の要素数を返す。ならし $\Theta(\frac{\log^2 n}{\log\log n})$ 。
- `bool is_root(int x)` : $t$ 回目の `merge` 操作の直後の要素 $x$ が属する集合の代表元が $x$ であるかを返す。 $\Theta(\frac{\log n}{\log\log n})$ 。
- `vector<vector<int>> groups()` : 「「集合に属する要素のリスト」のリスト」を返す。 $\Theta(n \frac{\log^2 n}{\log\log n})$ 。

