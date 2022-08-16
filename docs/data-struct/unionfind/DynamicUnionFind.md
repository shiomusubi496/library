## 概要

連想配列によって動的にした UnionFind 。最初に要素数を指定する必要はないが、その分計算量は UnionFind に劣る。

- `DynamicUnionFind()` : 動的 UnionFind を作成する。 $\Theta(1)$ 。
- `pair<ll, ll> merge(ll x, ll y)` : 要素 `x` の属する集合と要素 `y` の属する集合を併合する。併合後の根とそうでない方の pair を返す。ただし、もともと同じ集合に属する場合は根と -1 の pair を返す。ならし $\Theta(\alpha(N)\log N)$ 。
- `int find(ll x)` : 要素 `x` の属する集合の代表元を返す。ならし $\Theta(\alpha(N) \log N)$ 。
- `bool same(ll x, ll y)` : 要素 `x` と要素 `y` が同じ集合に属するかを判定する。ならし $\Theta(\alpha(N) \log N)$ 。
- `int size(ll x)` : 要素 `x` の属する集合の要素数を返す。ならし $\Theta(\alpha(N) \log N)$ 。
- `bool is_root(ll x)` : 要素 `x` が属する集合の代表元が `x` であるかを返す。 $\Theta(\log N)$ 。
