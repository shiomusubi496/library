## 概要

数列が与えられたとき、区間に対して色々できる。以下値の種類数を $m$ とする。

- `WaveletMatrix(vector<T> a)` : 列 `a` で初期化する。 $\Theta(n \log n)$ 。空間は $\Theta(n \log m)$ bit 。
- `T access(int k)` : `a[k]` を返す。 $\Theta(\log m)$ 。
- `T operator[](int k)` : 上に同じ。
- `int rank(int r, T x)` : `a[0:r)` の `x` の個数を返す。 $\Theta(\log m)$ 。
- `int rank(int l, int r, T x)` : `a[l:r)` の `x` の個数を返す。 $\Theta(\log m)$ 。
- `int select(T x, int k)` : `x` のうち `k` 個目にある値の index を返す。 $\Theta(\log n \log m)$ 。
- `T kth_smallest(int l, int r, int k)` : `a[l:r)` を昇順ソートしたとき `k` 番目の値を返す。 $\Theta(\log m)$ 。
- `T kth_largest(int l, int r, int k)` : `a[l:r)` を降順ソートしたとき `k` 番目の値を返す。 $\Theta(\log m)$ 。
- `int range_freq(int l, int r, T lower, T upper)` : `a[l:r)` のうち `[lower:upper)` に収まる値の個数を返す。 $\Theta(\log m)$ 。
- `T prev_value(int l, int r, T upper)` : `a[l:r)` のうち `upper` より小さい最大の値を返す。存在しなければ -inf を返す。 $\Theta(\log m)$ 。
- `T next_value(int l, int r, T lower)` : `a[l:r)` のうち `lower` 以上の最小の値を返す。存在しなければ inf を返す。 $\Theta(\log m)$ 。
