## 概要

多項式 $f, g$ の積を計算する。ただし、 $f, g$ はオンラインに与えられる。つまり、

1. $[x^i] f, [x^i] g$ が与えられる
2. $[x^i] (fg)$ を返す

を $i=0, 1, \ldots$ について行う。計算量は全体で $\Theta(n \log^2 n)$ 。

ただしこのライブラリはいわゆる NTT friendly な MOD で使用されることを想定している。

- `RelaxedConvolution()` : コンストラクタ。
- `RelaxedConvolution(int n)` : reserve をしているだけなのでほとんど速度は変わらない。
- `T next(T a, T b)` : 計算する。
