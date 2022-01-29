## 概要

${}_nC_r$ などを計算する。

- `IntCombinatorics<T>` : mod を取らない場合に使う。
- `Combinatorics<T>` : mod を取る場合に使う。 `T` は modint にする。

以下の計算ができる。

- `void init(ll n)` : `n` 以下の値を計算できるようにする。全体で $\Theta(\max(n) + \log mod)$ 。
- `T fact(ll x)` : $x!$ を計算する。 $\Theta(1)$ 。
- `T perm(ll n, ll r)` : ${}_nP_r$ を計算する。 $\Theta(1)$ 。
- `T comb(ll n, ll r)` : ${}_nC_r$ を計算する。 $\Theta(1)$ 。
- `T homo(ll n, ll r)` : ${}_nH_r$ を計算する。 $\Theta(1)$ 。
- `T small_perm(ll n, ll r)` : ${}_nP_r$ を計算する。 `init` を呼び出さないので $n$ が大きく $r$ が小さい場合に有効。 $\Theta(r)$ 。
- `T small_comb(ll n, ll r)` : ${}_nC_r$ を計算する。 $\Theta(r)$ 。
- `T small_homo(ll n, ll r)` : ${}_nH_r$ を計算する。 $\Theta(r)$ 。
