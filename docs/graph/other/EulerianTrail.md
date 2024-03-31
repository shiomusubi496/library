## 概要

オイラー路、つまり全ての辺をちょうど一度用いる路を求める。有向/無向で若干条件が変わる。

- `EulerianTrail(Graph<T> G, bool directed)` : $\Theta(\lvert V \rvert + \lvert E \rvert)$ 。
- `bool has_trail()` : 存在するかを返す。
- `Edges<T> get_trail()` : オイラー路を返す。
