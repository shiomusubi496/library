## 概要

多変数での畳み込みを行う。 $i = i_1 + i_2 N_1 + \cdots + i_K N_1 N_2 \dotsm N_{K-1}$ 番目の要素が $(x_1^{i_1}, x_2^{i_2}, \dotsc, x_K^{i_K})$ の係数を表すとして、与えられた $f, g$ の積を $\mod {(x_1^{N_1}, x_2^{N_2}, \dotsc, x_K^{N_K})}$ で求める。

NTT-friendly な素数を用いる前提の実装をしている。

- `vector<T> multidimensional_convolution(vector<T> f, vector<T> g, vector<int> base)` : 積を求める。 $\Theta(KN \log N)$ 。
