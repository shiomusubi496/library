## 概要

区間に含まれるある値の個数を求める。静的なので、普通に各値ごとに vector を持って二分探索しているだけ。

デフォルトでは `map` を使っているが、 `unordered_map` とかの hashmap を使うことで、オーダーはよくなる。 (コンストラクタと `count(T)` が線形時間/定数時間になる)

- `StaticRangeFrequency(vector<T> v)` : `v` で初期化。 $\Theta(n \log n)$ 。
- `int count(T x)` : `v` に含まれる `x` の個数を返す。 $\Theta(\log n)$ 。
- `int count(int l, int r, T x)` : `v` に含まれる `x` の個数を返す。 $\Theta(\log n)$ 。
