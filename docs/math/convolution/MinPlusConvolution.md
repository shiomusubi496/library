## 概要

長さ $n$ の列 $a$ 、長さ $m$ の列 $b$ で $b$ が下に凸なものについて、 $c_k \displaystyle\min_{i+j=k} a_i b_j$ で定められる長さ $n+m-1$ の列 $c$ を求める。

$X_{i,j}=A_j+B_{i-j}$ で定めると $X$ が monge になることより SMAWK により求まる。

- `vector<T> max_plus_convolution(vector<T> a, vector<T> b)` : 上記の計算をする。 $\Theta(n+m)$ 。
