## 概要

長さ $2^n$ の列 $a, b$ に対し、 $c_k = \sum_{i\|j=k, i\&j=0} a_ib_j$ で定義される列 $c$ を返す。

Library Checker で試したら pragma 書くと結構速くなったので、 TLE したら試してみても良いかも

- `vector<T> subset_convolution(vector<T> a, vector<T> b)` : $\Theta(n^22^n)$ 。
