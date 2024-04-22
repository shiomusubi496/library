## 概要

区間をソートできるセグ木。動的セグ木のマージを用いる。重め。

キーは distinct であるとする。

- `RangeSortQuery()` : コンストラクタ。
- `RangeSortQuery(ll n, ll mx = inf)` : キーの値の最大値を指定する。
- `RangeSortQuery(vector<T> v, vector<int> key, ll mx = inf)` : 初期値を指定する。
- `void set(int k, ll key, T val)` : セットする。 $\Theta(\log mx)$ 。
- `void sort(int l, int r, bool reverse = false)` : ソートする。逆順ソートもできる。償却 $\Theta(\log mx)$ ？
- `T get(int k)` : 値を得る。 $\Theta(\log mx)$ 。
- `T prod(int l, int r)` : 区間和を得る。 $\Theta(\log mx)$ 。
