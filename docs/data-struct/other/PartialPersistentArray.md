## 概要

部分永続配列。

- `PartialPersistentArray(vector<T> a)` : $a_{-1} := a$ とする。 $\Theta(N)$ 。
- `int set(int k, T x)` : これが $i$ 回目(0-indexed)の `set` 呼び出しのとき、 $a_{i-1}[k]$ を $x$ に更新した配列を $a_i$ とする。返り値は $i$ 。 $\Theta(1)$ 。
- `T get(int t, int k)` : $a_{t}[k]$ を返す。 $\Theta(\log Q)$ 。
