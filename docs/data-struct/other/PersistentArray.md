## 概要

完全永続配列。単に永続配列とも。 $k$ 分木を使っている。(デフォルトは $k=16$ 。)

- `PersistentArray(vector<T> a)` : $a_{-1} := a$ とする。 $\Theta(kN)$ 。
- `int set(int k, int t, T x)` : これが $i$ 回目(0-indexed)の `set`, `push_back` 呼び出しのとき、 $a_{t}[k]$ を $x$ に更新した配列を $a_i$ とする。返り値は $i$ 。 $\Theta(k \log_k N)$ 。
- `int push_back(int k, int t, T x)` : これが $i$ 回目の `set`, `push_back` 呼び出しのとき、 $a_{t}$ に $x$ を末尾に追加した配列を $a_i$ とする。返り値は $i$ 。 $\Theta(k \log_k N)$ 。
- `T get(int k, int t)` : $a_{t}[k]$ を返す。 $\Theta(\log_k N)$ 。
