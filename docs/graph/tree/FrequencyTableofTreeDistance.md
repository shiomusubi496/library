## 概要

木が与えられたとき、各 $d=0,1,\ldots,N-1$ について、 $\mathrm{dist}(u,v)=d$ なる頂点 $u, v$ $(u \leq v)$ の個数を求める。

重心分解をしたうえで畳み込みを用いているうえ、答えが N^2 オーダーになることから MOD を 2 つ用いているため、定数倍に注意が必要。

- `FrequencyTableofTreeDistance(Graph<T> G)` : 構築する。 $\Theta(N \log^2 N)$ 。
- `vector<ll> get()` : 答えを返す。 $\Theta(N)$ 。
