## 概要

要素のマージに時間がかかる場合に使う。要素の更新や区間クエリにおいて `M::op` を呼び出さないようにできる。 Range Kth Smallest などが可能。

- `void init(int n)` : 長さ `n` の列で初期化。 `M::op` を呼び出したくないときに使える。
- `template<class M2, class F> M2::value_type prod(int l, int r, F f)` : `f` を使って `T` から `M2::value_type` に変換して計算する。
