## 概要

大体 SegmentTree と同じ。 2D セグ木を作る時などに使えるように計算量上の工夫がちょっとある。

- `void init(int n)` : 長さ `n` の列で初期化。 `M::op` を呼び出したくないときに使える。
- `template<class M2, class F> M2::value_type prod(int l, int r, F f)` : `f` を使って `T` から `M2::value_type` に変換して計算する。
- ``
