## 概要

与えられた数列 v に対しての Cartesian Tree (デカルト木) を求める。これは、頂点 $i$ の親が頂点 $p$ であるとき $v_i > v_p$ であり、かつ in-order 順に頂点を並べたものが $1, 2, \cdots, N$ となるような二分木である。

性質として、数列 v における区間の最小値は、 Cartesian Tree における LCA となることなどがある。

また、マージテクと同様に考えると、各頂点について左右の部分木のうち小さい方のサイズの総和は $O(N \log N)$ に抑えられる。よって、数列の区間の最小値について扱う際、最小値を固定し、区間の左右どちらかを固定することができる場合、これを用いると $O(N \log N)$ で計算できる。

- `CartesianTree(std::vector<T> v)` : Cartesian Tree を構築する。 $\Theta(N)$ 。
- `vector<int> get_vec()` : $i$ 番目の要素が頂点 $i$ の親であるような数列を返す。ただし、根に対しては $-1$ となる。 $\Theta(N)$ 。
- `pair<Graph<U>, int> get_graph()` : Cartesian Tree とその根のペアを返す。 $\Theta(N)$ 。
