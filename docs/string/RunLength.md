## 概要

文字列を圧縮する。同じ文字が続く場所を、その文字と続く個数のペアで表す。例えば `aaabcca` は `{(a, 3), (b, 1), (c, 2), (a, 1)}` のようになる。

`string` でなくても、ランダムアクセス可能なコンテナ型なら動く。

- `vector<pair<char, int>> RunLength(string str)` : `str` を圧縮した配列を返す。 $\Theta(N)$ 。
