## 概要

完全永続配列。単に永続配列とも。 $m$ 分木を使っている。(デフォルトは $m=2$ 。)

- `PersistentArray(vector<T> a)` : $a_{-1} := a$ とする。 $\Theta(mN)$ 。
- `int set(int t, int k, T x)` : これが $i$ 回目(0-indexed)の呼び出しのとき、 $a_{t}[k]$ を $x$ に更新した配列を $a_i$ とする。返り値は $i$ 。 $\Theta(m \log_m N)$ 。
- `int push_back(int t, T x)` : これが $i$ 回目の呼び出しのとき、 $a_{t}$ に $x$ を末尾に追加した配列を $a_i$ とする。返り値は $i$ 。 $\Theta(m \log_m N)$ 。
- `int pop_back(int t)` : これが $i$ 回目の呼び出しのとき、 $a_{t}$ の末尾を削除した配列を $a_i$ とする。返り値は $i$ 。 $\Theta(m \log_m N)$ 。
- `T get(int t, int k)` : $a_{t}[k]$ を返す。 $\Theta(\log_m N)$ 。
