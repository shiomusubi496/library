## 概要

二次元平面上の一点加算矩形取得クエリを扱える。ただし加算する点はあらかじめ決めとかないと動かない。

- `WaveletMatrixPointAddRectangleSum()` : コンストラクタ。 $\Theta(1)$
- `void add_point(T x, T y)` : 点 $(x, y)$ を追加する。 $\Theta(1)$
- `void build()` : 構築する。以降 `add_point` を呼び出してはいけない。 $\Theta(n \log n)$
- `void apply(T x, T y, U z)` : 点 $(x, y)$ に $z$ を加算する。 $\Theta(\log n \log m)$
- `U prod(T xl, T xr, T yl, T yr)` : $\sum_{xl \leq x < xr \land yl \leq y < yr} (x, y)$ を求める。 $\Theta(\log n \log m)$
