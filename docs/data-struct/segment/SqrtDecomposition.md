## 概要

いわゆるバケット法の平方分割。

- `SqrtDecomposition(vector<T> a, F f)` : 列 `a` と各バケットに持たせるデータを返す `f(vector<T>)` で初期化。バケットサイズは $\sqrt{n}$ 。 $\Theta(n)$ 。
- `SqrtDecomposition(vector<T> a, int b, F f)` : バケットの大きさ `b` を指定して初期化。 $\Theta(n)$ 。
- `S prod(int l, int r, G g, H h)` : `T` から値を得る `S g(T)` 、各バケットのデータから値を得る `S h(U)` を使って `M::op(a[l], a[l+1], ..., a[r-1])` を返す。
- `void apply(int l, int r, G g, H h)` : `T` を変更する `void g(T&)` 、各バケットのデータを更新する `void h(U&)` を使って `M::op(a[l], a[l+1], ..., a[r-1])` を返す。
