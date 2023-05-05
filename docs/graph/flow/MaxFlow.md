## 概要

最大流を求める。 Dinic 法を用いている。

内部に構造体 `edge` があり、以下のようになっている。

```
struct edge {
    int from, to;
    T cap, flow;
};
```

- `MaxFlow(int n)` : $n$ 頂点のグラフを作る。
- `int add_edge(int from, int to, T cap)` : 頂点 `from` から頂点 `to` へと容量 `cap` の辺を張る。返り値は何番目の辺か。 $O(1)$ 。
- `edge get_edge(int i)` : $i$ 番目の辺を返す。 $O(1)$ 。
- `vector<edge> edges()` : 辺を全て返す。順番は追加された順と同じ。 $O(m)$ 。
- `T flow(int s, int t)` : 頂点 `s` から頂点 `t` へフローを流す。 $O(n^2m)$ だが、実用上かなり速く動く。特に容量が全て $1$ の場合、 $O(\min(n^\frac{2}{3}, m^\frac{1}{2}) m)$ となることが知られている。
- `T flow(int s, int t, T flow_limit)` : 流量制限付きでフローを流す。計算量は同様。
