## 概要

多項式 $f(x)$ と定数 $c$ が与えられたとき、 $f(x+c)$ を計算する。

- `FormalPowerSeries<T> taylor_shift(FormalPowerSeries<T> f, T a)` : $f(x+a)$ を返す。展開すると畳み込み $1$ つで簡潔に表せる。 $\Theta(n \log n)$ 。
