## 概要

畳み込み。長さ $N, M$ の数列 $a, b$ に対して、

$\displaystyle c_i = \sum_{j=0}^i a_j b_{i-j}$

で定義される長さ $N+M-1$ の数列 $c$ を返す。

高速フーリエ変換を用いている。

`998244353` など、 $p-1$ が大きい 2 冪の約数を持つ場合はそれ以外に対して 3 倍ほど高速。

- `template<unsigned int p> vector<ll> convolution(vector<ll> a, vector<ll> b)` : $\mod p$ で畳み込む。 $\Theta(N \log N)$ 。
- `vector<mint<p>> convolution(vector<mint<p>> a, vector<mint<p>> b)` : 同上。 $\Theta(N \log N)$ 。
