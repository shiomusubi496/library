## 概要

${}_nC_r$ などを計算する。

- `Combinatorics<T>` : mod を取らない場合に使う。
- `ModCombinatorics<T>` : mod を取る場合に使う。

以下の計算ができる。

- `void init(ll n)` : `n` 以下の値を計算できるようにする。
- `T fact(ll x)` : $x!$ を計算する。
- `T perm(ll n, ll r)` : ${}_nP_r$ を計算する。
- `T comb(ll n, ll r)` : ${}_nC_r$ を計算する。
- `T homo(ll n, ll r)` : ${}_nH_r$ を計算する。
