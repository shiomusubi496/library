## 概要

行列のライブラリ。 `vector<vector<T>>` を継承している。

- `Matrix(int h, int w)` : `h` 行 `w` 列の行列を作成する。 $\Theta(hw)$ 。
- `Matrix(int h, int w, T v)` : 初期値 `v` で行列を作成する。 $\Theta(hw)$ 。
- `int height()` : 行数を返す。 $\Theta(1)$ 。
- `int width()` : 列数を返す。 $\Theta(1)$ 。
- `bool is_square()` : 正方行列かを返す。 $hw=0$ の場合に注意。 $\Theta(1)$ 。
- `Matrix pow(int b)` : べき乗を返す。行列積を $\Theta(\log b)$ 回行う。
- `Matrix transpose()` : 転置を返す。 $\Theta(hw)$ 。
- `Matrix& gauss()` : ガウスの消去法を行う。 $\Theta(hw^2)$ 。
- `int rank()` : 階数を返す。 $\Theta(hw\min(h,w))$ 。
- `Matrix get_identity(int n)` : `n` 行 `n` 列の単位行列を返す。 $\Theta(n^2)$ 。

さらに以下の演算が動く。

```
Matrix += Matrix
Matrix -= Matrix
Matrix *= Matrix
Matrix *= T

Matrix + Matrix
Matrix - Matrix
Matrix * Matrix
Matrix * T
```

行列同士の和差はそれぞれ $H \times W$ 行列と $H \times W$ 行列に対して $\Theta(HW)$ 。  
行列同士の積は $H \times W$ 行列と $W \times K$ 行列に対して $\Theta(HWK)$ 。  
行列とスカラー倍は $H \times W$ 行列に対して $\Theta(HW)$ 。
