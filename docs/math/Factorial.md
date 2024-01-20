## 概要

$N!$ を計算する。

定数 $B$ を定める。 $f(x) = (x+1)(x+2)\cdots(x+B)$ とすると、 $f(0), f(B), f(2B), \ldots, f((\lfloor N/B \rfloor - 1) \times B)$ と $\lfloor N/B \rfloor \times B + 1, \ldots, N$ の積が $N!$ に等しくなる。  
展開および多点評価がボトルネックで、 $B=\sqrt{N}$ とすることで計算量 $\Theta(\sqrt{N} \log^2 \sqrt{N})$ を達成できる。

ただし、実用的には埋め込んだ方が圧倒的に速い。

- `T factorial(ll n)` : $n!$ を計算する。 $\Theta(\sqrt{N} \log^2 \sqrt{N})$ 。
