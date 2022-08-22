## 概要

完全永続 UF。

計算量に関して、経路圧縮を行った場合の計算量は償却なので、

- `PersistentUnionFind(int n)` : サイズ `n` の UF を作成し、 $a_{-1}$ とする。
- `pair<pair<int, int>, int> merge(int x, int y, int t)` : これが $i$ 回目(0-indexed)の `merge` 操作のとき、 $a_{t}$ において $x$ と $y$ をつなげた UF を $a_{i}$ とする。返り値は通常の UF の返り値と $i$ のペア。 $\Theta(\frac{\log^2 n}{\log\log n})$
- `int find(int x, int t)` : $t$ 回目の `merge` 操作の直後の $x$ の属する集合の代表元を返す。 $\Theta(\frac{\log^2 n}{\log\log n})$ 。

