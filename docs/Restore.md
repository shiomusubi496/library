## 概要

最短経路問題の経路を復元する。

- `vector<int> Restore(Graph<T> G, vector<T> dist, int s = 0)` :  
グラフ `G` において `s` を始点として最短経路問題を解いた答えが `dist` の時、各頂点についてその頂点の前に通った頂点を求める。  
`s` に対しては `-1` 、 `s` から到達不可能な頂点に対しては `-2` となる。  
$\Theta(V + E)$ 。
