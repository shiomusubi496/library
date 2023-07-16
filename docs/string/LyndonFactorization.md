## 概要

文字列 $S$ が Lyndon 文字列であるとは、 $N = \lvert S \rvert$ として、任意の $1 \leq i < N$ について $S < S[i:]$ を満たすことを指す。

Lyndon 分解は $S[0 = a_0, a_1), S[a_1, a_2), \ldots, S[a_{k-1}, a_k = N)$ が全て Lyndon 文字列であり、かつこれらが単調非増加であるものである。

これを用いることで、例えば任意の prefix について最小の suffix を求めることができる。

- `vector<int> lyndon_factorization(string str)` : str の Lyndon 分解を返す。 $\Theta(N)$ 。
