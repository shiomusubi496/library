## 概要

meldable heap の一種で、償却で計算量が保証されている。実装が楽。

また、全体に値を加算する操作が可能。もしくは、一つの値を変更する操作が償却 $\Theta(\log n)$ で行えるため Dijkstra のメモリ改善などにも使える。

`std::priority_queue` と色々合わせている。

- `SkewHeap()` : コンストラクタ。
- `bool empty()` : 空か否かを返す。 $\Theta(1)$ 。
- `int size()` : 大きさを返す。 $\Theta(1)$ 。
- `void insert(T x)` : `x` を挿入する。償却 $\Theta(\log n)$ 。
- `void pop()` : 最大値を削除する。償却 $\Theta(\log n)$ 。
- `T top()` : 最大値を返す。 $\Theta(1)$ 。
- `void clear()` : 空にする。 $\Theta(n)$ 。
- `void apply(U x)` : 全体に x を適用する。順序関係を維持する必要がある。 $\Theta(1)$ 。
- `SkewHeap& meld(SkewHeap&& other)` : マージする。償却 $\Theta(\log n)$ 。
