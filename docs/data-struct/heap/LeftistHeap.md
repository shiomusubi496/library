## 概要

meldable heap の一種で、最悪計算量が保証されているため永続化可能。

また、全体に値を加算する操作も可能。

`std::priority_queue` と色々合わせている。

- `LeftistHeap()` : コンストラクタ。
- `bool empty()` : 空か否かを返す。 $\Theta(1)$ 。
- `int size()` : 大きさを返す。 $\Theta(1)$ 。
- `void insert(T x)` : `x` を挿入する。 $\Theta(\log n)$ 。
- `void pop()` : 最大値を削除する。 $\Theta(\log n)$ 。
- `T top()` : 最大値を返す。 $\Theta(1)$ 。
- `void clear()` : 空にする。 $\Theta(n)$ 。
- `void apply(U x)` : 全体に x を適用する。順序関係を維持する必要がある。 $\Theta(1)$ 。
- `LeftistHeap& meld(LeftistHeap&& other)` : マージする。 $\Theta(\log n)$ 。