## 概要

与えられた静的な数列の区間最頻値クエリに答える。

- `StaticRangeMode(vector<T> v)` : 構築。空間 $\Theta(N)$ 時間 $\Theta(N \sqrt{N})$ 。
- `void init(vector<T> v)` : 同上。
- `pair<T, int> prod(int l, int r)` : $v[l, r)$ の最頻値とその出現回数を返す。 $\Theta(\sqrt{N})$ 。
