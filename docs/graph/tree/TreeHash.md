## 概要

根付き木のハッシュを求める。各頂点を根にしたときの値を全て求めるときは全方位木DPをすると良い。

`mint` は `modint61` で、ロリハを参照。

- `vector<mint> get_hash(Graph<T> G, int root = 0)` : `root` を根とする木 `G` の各部分木のハッシュを返す。 $\Theta(N)$ 。
- `pair<vector<vector<mint>>, vector<mint>> get_hash_rerooting(Graph<T> G)` : 全方位木DPの結果を返す。 $\Theta(N)$ 。
