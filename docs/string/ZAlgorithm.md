## 概要

`S` と `S[i:]` の LCP(Longest Common Prefix, 最長共通接頭辞) を $\Theta(n)$ で求める。

なお、 `string` 型でなくてもランダムアクセス可能なコンテナ型なら動く。

- `vector<int> ZAlgorithm(string str)` : 長さ `n` の配列 `a` を返す。このとき、 `a[i]` は `S` と `S[i:]` の LCP の長さである。 $\Theta(n)$ 。