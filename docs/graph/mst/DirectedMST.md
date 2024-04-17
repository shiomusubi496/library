## 概要

有向グラフにおける最小全域木を求める。 Meldable Heap を用いる。

- `DirectedMST(int N, Edges<T> es, int root)` : `root` を根とする最小有向全域木を求める。 $\Theta(M \log N)$ 。
- `T cost()` : 全域木の辺のコストの合計を返す。 $\Theta(1)$ 。
- `Edges<T> edges()` : 全域木の辺を返す。 $\Theta(N)$ 。
