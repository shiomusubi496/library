## 概要

$s_0, s_1, \ldots, s_{n-1}$ と $T$ が与えられたとき、 $t = 0, 1, \ldots, T$ について $I \subseteq \{0, 1, \ldots, n-1\}$ のうち $\sum_{i \in I} s_i = t$ なるものの個数を $998244353$ で割った余りを返す。 $\prod_{i=0}^{N-1} (1+x^{s_i}) = \exp(\sum_{i=0}^{N-1} \log (1+x^{s_i}))$ を求めれば良いので、 $\log (1+x^{s_i})$ は次数が $s_i$ の倍数である項のみ非零であることより調和級数で抑えられる。

- `vector<T> subset_sum(vector<int> a, int n)` : $\Theta(n \log n)$ 。
