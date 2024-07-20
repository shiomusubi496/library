## 概要

オイラー路(全辺を一度ずつ通る路)を数え上げる。 BEST Theorem により、頂点 $1$ を根とする有向全域木の個数を $c$ (根によらず同じ値になる)、 $v$ の出次数を $\deg(v)$ として $c \times \prod_{v} (\deg(v)-1)!$ になる。

- `T count_eulerian_trail(Graph<U> G)` : $\Theta(N^3)$ 。
