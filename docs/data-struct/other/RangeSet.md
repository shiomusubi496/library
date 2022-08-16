## 概要

区間を `std::set` で管理するやつ。

- `RangeSet()` : コンストラクタ。 $\Theta(1)$ 。
- `bool empty()` : 空であるかを返す。 $\Theta(1)$ 。
- `int size()` : 区間の個数を返す。 $\Theta(1)$ 。
- `ll length()` : 区間内の整数の数を返す。 $\Theta(1)$ 。
- `set<PLL> get_data()` : `set` を返す。 $\Theta(N)$ 。
- `pair<iterator, bool> insert(ll l, ll r)` : 区間 `[l, r)` を追加する。償却 $\Theta(\log N)$ 。
- `void erase(ll l, ll r)` : 区間 `[l, r)` を全て削除する。償却 $\Theta(\log N)$ 。
- `bool include(ll k)` : 整数 `k` が含まれているかを返す。 $\Theta(\log N)$ 。
- `PLL find(ll k)` : 整数 `k` を含む区間を返す。ない場合は `(-1, -1)` を返す。 $\Theta(\log N)$ 。
- `RangeSet operator&&(Range a, Range b)` : 共通集合を返す。 $\Theta(N \log N)$ 。
- `RangeSet operator||(Range a, Range b)` : 和集合を返す。 $\Theta(N \log N)$ 。
