## 概要

二分木の各ノードに 2 つの値を持たせることで、最小値と最大値を両方取り出せるようにした二分ヒープ。

`multiset` でも同様のことができるが、定数倍はこちらの方が速い。

- `IntervalHeap()` : デフォルトコンストラクタ。
- `IntervalHeap(vector<T> a)` : `a` でヒープを初期化する。 $\Theta(N)$ 。
- `int size()` : 要素数を取得する。 $\Theta(1)$ 。
- `bool empty()` : 空かどうかを返す。 $\Theta(1)$ 。
- `void push(T x)` : `x` を挿入する。 $\Theta(\log N)$ 。
- `T max()` : 最大値を取得する。 $\Theta(1)$ 。
- `T min()` : 最小値を取得する。 $\Theta(1)$ 。
- `void pop_max()` : 最大値を削除する。 $\Theta(\log N)$ 。
- `void pop_min()` : 最小値を削除する。 $\Theta(\log N)$ 。
