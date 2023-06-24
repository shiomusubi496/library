## 概要

絶対値の和の形をした関数などを効率よく扱うことができる。

- `SlopeTrick(T a = 0)` : 関数を定数関数 $f(x) = a$ で初期化する。 $\Theta(1)$ 。
- `void add(T a)` : 関数を $g(x) = f(x) + a$ にする。 $\Theta(1)$ 。
- `void a_x(T a)` : 関数を $g(x) = f(x) + \max(a-x, 0)$ にする。 $\Theta(\log N)$ 。
- `void x_a(T a)` : 関数を $g(x) = f(x) + \max(x-a, 0)$ にする。 $\Theta(\log N)$ 。
- `void abs(T a)` : 関数を $g(x) = f(x) + \lvert x-a \rvert$ にする。 $\Theta(\log N)$ 。
- `void prefix_min(T a)` : 関数を $g(x) = \min_{y \leq x} f(y)$ にする。償却 $\Theta(1)$ 。
- `void suffix_min(T a)` : 関数を $g(x) = \min_{y \geq x} f(y)$ にする。償却 $\Theta(1)$ 。
- `void slide(T a)` : 関数を $g(x) = f(x-a)$ にする。 $\Theta(1)$ 。
- `void slide_min(T a, T b)` : 関数を $g(x) = \min_{x-b \leq y \leq x-a} f(y)$ にする。 $\Theta(1)$ 。
- `T min()` : $\min_x f(x)$ を返す。 $\Theta(1)$ 。
- `pair<T, T> argmin()` : $\argmin_x f(x) = \{x \mid l \leq x \leq r\}$ なる $l, r$ を返す。 $\Theta(1)$ 。
