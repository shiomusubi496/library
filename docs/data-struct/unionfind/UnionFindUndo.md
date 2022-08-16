## 概要

経路圧縮をしない場合、 merge 一回で変化する配列の値はたかだか $2$ つであるため、これを保存しておくことで undo 可能にした UnionFind 。

- `UnionFind(int N)` : サイズ `N` の UnionFind を作成する。 $\Theta(N)$ 。
- `pair<int, int> merge(int x, int y)` : 要素 `x` の属する集合と要素 `y` の属する集合を併合する。併合後の根とそうでない方の pair を返す。ただし、もともと同じ集合に属する場合は根と -1 の pair を返す。ならし $\Theta(\log N)$ 。
- `int find(int x)` : 要素 `x` の属する集合の代表元を返す。ならし $\Theta(\log N)$ 。
- `bool same(int x, int y)` : 要素 `x` と要素 `y` が同じ集合に属するかを判定する。ならし $\Theta(\log N)$ 。
- `int size(int x)` : 要素 `x` の属する集合の要素数を返す。ならし $\Theta(\log N)$ 。
- `bool is_root(int x)` : 要素 `x` が属する集合の代表元が `x` であるかを返す。 $\Theta(1)$ 。
- `vector<vector<int>> groups()` : 「「集合に属する要素のリスト」のリスト」を返す。ならし $\Theta(N\log N)$ 。
- `void undo()` : 直前の `unite` 操作を取り消す。 $\Theta(1)$ 。
- `void snapshot()` : 現在の状態を保存する。これ以前に `undo` することはできなくなるので注意。全体の合計での計算量は `merge` した回数に比例。
- `void rollback()` : 最初の状態、または最後に `snapshot` をした状態に戻す。計算量は `snapshot` と同様。
