## 概要

木の直径を計算するクラス。最短経路問題を $2$ 回解けば良いことで知られている。

- `TreeDiameter(Tree<T> T)` : 木 `T` で初期化する。
- `T diameter()` : 直径の重みの総和を返す。
- `pair<int, int> get_pair()` : 直径の両端を返す。
- `Edges<T> get_path()` : 直径の辺のリストを返す。
