## 概要

数列が与えられたとき、区間に対して色々できる。以下値の種類数を $m$ とする。

- `WaveletMatrix(vector<T> a)` : 列 `a` で初期化する。 $\Theta(n \log n)$ 。空間は $\Theta(n \log m)$ bit 。
- `T access(int k)` : `a[k]` を返す。 $\Theta(\log m)$ 。
- `T operator[](int k)` : 上に同じ。
- `int rank(int r, T x)` : `a[0:r)` の `x` の個数を返す。 $\Theta(\log m)$ 。
- `int rank(int l, int r, T x)` : `a[l:r)` の `x` の個数を返す。 $\Theta(\log m)$ 。
- `int select(T x, int k)` : `x` のうち `k` 個目にある値の index を返す。 $\Theta(\log n \log m)$ 。
- `T quantile(int l, int r, int k)` : `a[l:r)` をソートしたとき `k` 番目の値を返す。 $\Theta(\log n \log m)$ 。
- `int count(int l, int r, T x, T y)` : `a[l:r)` のうち `[x:y)` に収まる値の個数を返す。 $\Theta(\log m)$ 。
