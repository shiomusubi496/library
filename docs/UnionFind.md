## 概要

集合を併合する操作や、ある要素が属する集合の代表元を問い合わせる操作を行える。

- `bool merge(int x, int y)` :  
要素 `x` の属する集合と要素 `y` の属する集合を併合する。もともと同じ集合に属していたなら `false` を、そうでないなら `true` を返す。ならし $O(\alpha(N))$ 。

- `int find(int x)` :  
要素 `x` の属する集合の代表元を返す。ならし $O(\alpha(N))$ 。

- `bool same(int x, int y)`  
要素 `x` と要素 `y` が同じ集合に属するかを判定する。ならし $O(\alpha(N))$ 。

- `int size(int x)`  
要素 `x` の属する集合の要素数を返す。ならし $O(\alpha(N))$ 。

- `bool is_root(int x)`  
要素 `x` が属する集合の代表元が `x` であるかを返す。 $O(1)$ 。

- `vector<vector<int>> groups()`  
「「集合に属する要素のリスト」のリスト」を返す。ならし $O(N\alpha(N))$ 。
