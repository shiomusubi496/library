## 概要

高々 $n-1$ 次の多項式 $f$ について $f(0), f(1), \ldots, f(n-1)$ が与えられたとき、 $i=0, 1, \ldots, M$ について $f(T+i)$ を計算する。多項式補完と多点評価でも同様のことができるが、それでは $\Theta(n \log^2 n)$ かかるのに対しこちらは $\Theta(n \log n)$ 。

$$\begin{align*}
f(x) &= \sum_{i=0}^{n-1} f(i) \prod_{0 \leq j < n, i\neq j} \frac{x-j}{i-j} \\
     &= \sum_{i=0}^{n-1}\left(\sum_{j=0}^{i} \frac{(-1)^{i-j}f(j)}{(i-j)!j!}\right)x^{\underline{i}}
\end{align*}$$

より、適当に畳み込むことで $f(x) = \sum_{i=0}^{n-1} a_i x^{\underline{i}}$ の形で表せる。

下降冪においても二項定理もどきが成り立つので、 Taylor Shift もどきで $f(T+x) = \sum_{i=0}^{n-1} b_i x^{\underline{i}}$ の形になる。

これに $k=0, 1, \ldots, n-1$ について $x=k$ を代入することを考えると、 $f(T+k) = \sum_{i=0}^{\min(n-1,k)}b_i\frac{k!}{(k-i)!}$ と表せる。適当に畳み込むことで求めたいものが得られる。

- `vector<T> sampling_points_shift(vector<T> a, int m, T t)` : 上記の通り。 $\Theta((n+m) \log (n+m))$ 。
