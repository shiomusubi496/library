## 概要

$2N+o(N)$ bits の空間で 01 配列の累積和を求める。

- `FullyIndexableDictionary()` : コンストラクタ。
- `FullyIndexableDictionary(int n)` : $\Theta(n)$ 。
- `void set(int i)` : `a[i]` を 1 にする。 $\Theta(1)$ 。
- `void build()` : 計算する。 $\Theta(1)$ 。
- `int rank(int i)` : `a[0, i)` のうち $1$ の個数を返す。 $\Theta(1)$ 。
- `int rank(bool x, int i)` : `a[0, i)` のうち $x$ の個数を返す。 $\Theta(1)$ 。
