## 概要

文字列などのコンテナは比較に線形時間がかかってしまうため、それを比較が定数時間でできる整数値に変換する。

ローリングハッシュなので、略してロリハ。

- `RollingHash()` : ローリングハッシュを作成する。 $\Theta(1)$ 。
- `RollingHash::Hash get_hash(string str)` : ハッシュ値を計算するための型を返す。 $\Theta(N)$ 。

`RollingHash::Hash` には次のメンバ関数がある。

- `ull get_hash(int l, int r)` : 文字列の `l` 文字目から `r-1` 文字目までの部分文字列のハッシュ値を返す。 $\Theta(1)$ 。
- `ull get_all()` : 文字列全体のハッシュ値を返す。 $\Theta(1)$ 。
