## 概要

無向グラフ G に対して、 (a, b), (b, c), (c, a) の全てに辺があるような 3 頂点 a, b, c の組を全て返す。これは最大で $O(M \sqrt{M})$ 個存在する。

- `vector<array<int, 3>> enumerate_triangles(Graph<T> G)` : triangle を全て返す。 $\Theta(M \sqrt{M})$ 。
