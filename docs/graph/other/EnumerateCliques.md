## 概要

全頂点組について間に辺があるような頂点集合(クリーク)を列挙する。辺数 $M$ に対して $O(2^\sqrt{2M})$ 個あるらしい。 [参考(15p)](https://www.slideshare.net/wata_orz/ss-12131479)

- `vector<vector<int>> enumerate_cliques(Graph<T> G)` : 列挙して返す。 $O(2^\sqrt{2M} N)$ の計算量になる。
