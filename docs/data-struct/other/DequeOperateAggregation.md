## 概要

deque は 2 つの stack で作れる。空の stack にもう片方から移すとき、 $\frac{n}{2}$ 要素を移すことでならし $\Theta(1)$ が達成される。

- `DequeOperateAggregation()` : コンストラクタ。 $\Theta(1)$ 。
- `int size()` : サイズを返す。 $\Theta(1)$ 。
- `bool empty()` : 空かどうかを返す。 $\Theta(1)$ 。
- `void push_front(T x)` : $x$ を先頭に追加する。 $\Theta(1)$ 。
- `void push_back(T x)` : $x$ を末尾に追加する。 $\Theta(1)$ 。
- `void pop_front()` : 先頭の要素を削除する。ならし $\Theta(1)$ 。
- `void pop_back()` : 末尾の要素を削除する。ならし $\Theta(1)$ 。
- `T all_prod()` : 全体を `M::op` で演算した結果を返す。 $\Theta(1)$ 。
