## 概要

Stern-Brocot Tree では全ての正の有理数を二分探索木の形で表すことができる。

- `pair<Rat, Rat> max_right(bool f(Rat), T n)` : 分子・分母が $n$ 以下の分数で表せる正の有理数で、 $f(l) = true$ かつ $f(r) = false$ を満たし、かつ $l < x < r$ の範囲にそのような有理数が存在しない $(l, r)$ を返す。ただし $f(0) = false$ のときは $(-1, 0)$ を返すこともある。特に $f$ に単調性がある場合は $f(x) = true$ を満たす最大の $x$ を返す。 $\Theta(\log n)$ 。
