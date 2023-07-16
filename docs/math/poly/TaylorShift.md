## 概要

多項式 $f(x)$ と定数 $c$ が与えられたとき、 $f(x+c)$ を計算する。

$$\begin{align*}
f(x+c) &= \sum_{i=0}^{n-1} a_i \sum_{j=0}^i \binom{i}{j}c^{i-j}x^j \\
&= \sum_{i=0}^{n-1} \left(\sum_{j=i}^{n-1} a_jj!\frac{c^{j-i}}{(j-i)!}\right)\frac{x^i}{i!}
\end{align*}$$

より、 $\displaystyle\left(\sum_{i=0}^{n-1}a_ii!x^i\right)$ と $\displaystyle\left(\sum_{i=0}^{n-1}\frac{c^i}{i!}x^{-i}\right)$ を畳み込めば良い。

- `FormalPowerSeries<T> taylor_shift(FormalPowerSeries<T> f, T c)` : $f(x+c)$ を返す。展開すると畳み込み $1$ つで簡潔に表せる。 $\Theta(n \log n)$ 。
