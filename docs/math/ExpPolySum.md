## 概要

$\displaystyle \sum_{i=0}^{\infty} r^ii^d = \sum_{i=0}^d(-r)^i\binom{d+1}{i}\sum_{j=0}^{d-i}r^jj^d$ なので、線形時間で計算できる。

- `T exp_poly_sum(T r, int d, int n = -1)` : $n=-1$ のとき上記の値を返す。 $r \neq 1$ でなければならない。 $\Theta(n)$ 。

$$\begin{align*}
\displaystyle \sum_{i=0}^{n-1} r^ii^d &= \sum_{i=0}^{\infty} r^ii^d - \sum_{i=n}^{\infty} r^ii^d \\
 &= \sum_{i=0}^{\infty} r^ii^d - r^n \sum_{i=0}^{\infty} r^i(i+n)^d
\end{align*}$$

で、第一項は前述の通り計算でき、第二項$/ r^n$ は $(i+n)^d$ を展開すると $n$ の $d$ 次多項式になることが分かるため、 $0$ から $d$ についての値を求めれば標本点シフトできる。

$r=1$ のときはうまくいかないので普通にやる。

- `T exp_poly_sum(T r, int d, int n = -1)` : $n\neq-1$ のとき上記の値を返す。 $\Theta(n)$ 。
