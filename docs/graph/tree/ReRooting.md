## 概要

全方位木 DP をする。

- `ReRooting(Graph<T> G, F f)` : グラフ `g` と関数 `f` で初期化する。 $\Theta(V)$ 。
- `ReRooting(Graph<T> G, F f, vector<U> it)` : 各葉の初期値を設定する。 $\Theta(V)$ 。
- `vector<U> get_res()` : 各頂点を根としたときの結果を返す。 $\Theta(V)$ 。
- `U operator[](int k)` : 各頂点を根としたときの結果を返す。 $\Theta(V)$ 。
- `U get_dp(int v, int p_id)` : `v` を根とし、 `G[v][p_id]` を親としたときの部分木の結果を返す。 $\Theta(1)$ 。
- `vector<vector<U>> get_dp()` : 各 `v`, `p_id` に対し上の値を返す。 $\Theta(V)$ 。
