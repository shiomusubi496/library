## 概要

LIS(最長増加部分列) を求める。もちろん `string` 以外のコンテナ型でも動く。

- `LongestIncreasingSubsequence(string str, bool strict = true)` : `str` に対して LIS を求める。 `strict` が `true` なら狭義、 `false` なら広義。 $\Theta(N \log N)$ 。
- `int size()` : LIS の長さを返す。 $\Theta(1)$ 。
- `vector<int> get()` : LIS の index の列を返す。 $\Theta(N)$ 。
- `vector<T> get_str()` : LIS を返す。 $\Theta(N)$ 。
