## 概要

木の構造体。 `Graph` を継承している。

- `Tree(int N)` : 頂点数 `N` のグラフを作成する。
- `void build(int root = 0)` : 頂点 `root` を根とする根付き木を構築する。 `root` は根に、 `par[v]` は `v` の親になる。
- `Graph<T> child()` は根付き木を返す。
