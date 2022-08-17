## 概要

クエリを上手くソートすることで、左端/右端の移動を $\Theta((N+Q)\sqrt{N})$ 回くらいに抑えるアルゴリズム。

Nyaan's library によると、ブロックサイズを $\frac{\sqrt{3}n}{\sqrt{2q}}$ にすると定数倍がいいらしい。

- `Mo(int n, vector<pair<int, int>> a)` : 長さ `n` と、クエリ列 `a` で初期化。 $\Theta(q)$ 。
- `void push(int l, int r)` : クエリ `[l, r)` を追加。 $\Theta(1)$ 。
- `void build(AL al, AR ar, DL dl, DR dr, REM rem)` : クエリを処理。各端点の移動が $\Theta(\alpha)$ のとき、 $\Theta(\alpha n\sqrt{q})$ 。
