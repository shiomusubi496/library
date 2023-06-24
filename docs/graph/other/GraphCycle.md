## 概要

有向グラフに対して閉路を検出する。

- `GraphCycle(Graph<T> G)` : グラフ `G` で初期化する。 $\Theta(V + E)$ 。
- `bool has_cycle()` : 閉路を持つかを返す。 $\Theta(1)$ 。
- `Edges<T> get_cycle()` : 閉路 $p$ を $1$ つ返す。存在しない場合は空のリストが返る。 $\Theta(\lvert p \rvert)$ 。
