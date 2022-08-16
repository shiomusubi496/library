## 概要

`queue` の要素全てに順に演算を適当した値を $\Theta(1)$ で求めることができるデータ構造。 `stack` 2 つで `queue` を作るテクニックを使っている。

- `SlidingWindowAggregation()` : SWAG を作る。 $\Theta(1)$ 。
- `int size()` : 要素数を返す。 $\Theta(1)$ 。
- `bool empty()` : 空であるかを返す。 $\Theta(1)$ 。
- `void push(T x)` : `x` を追加する。 $\Theta(1)$ 。
- `void emplace(Args...)` : 要素を直接構築で追加する。 $\Theta(1)$ 。
- `void pop()` : 要素を削除する。ならし $\Theta(1)$ 。
- `T all_prod()` : queue の要素全てで順に演算をした値を返す。 $\Theta(1)$ 。
