## 概要

与えられた行列の行列式を求める。

- `T determinant(Matrix<T> mat)` : $n$ 次正方行列 `mat` の行列式を返す。 `T` は素数 mod の modint を想定。 $\Theta(n^3)$ 。
- `T determinant_arbitrary_mod(Matrix<T> mat)` : $n$ 次正方行列 `mat` の行列式を返す。割り算を用いていないため任意 mod に対応している。 $\Theta(n^2(n + \log m))$ 。
