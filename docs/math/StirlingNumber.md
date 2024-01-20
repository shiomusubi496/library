## 概要

スターリング数、ベル数、ベルヌーイ数のライブラリ。

これに関連して写像 12 相をまとめる。これらは $n$ のボールを $k$ 個の箱に入れる問題として考えられる。参考： [Combinatorics](https://shiomusubi496.github.io/library/math/Combinatorics.hpp)

| Ball | Box | 1個以内 | 1個以上 | 制限なし |
| --- | --- | --- | --- | --- |
| 区別あり | 区別あり | ${}_kP_n$ | $\sum_{i=0}^k (-1)^{k-i} {}_kC_i i^n$ | $k^n$ |
| 区別なし | 区別あり | ${}_kC_n$ | ${}_{n-1}C_{k-1}$ | ${}_{k}H_{n} = {}_{n+k-1}C_{n}$ |
| 区別あり | 区別なし | $(n \leq k)$ | $S(n, k)$ | $B(n, k)$ |
| 区別なし | 区別なし | $(n \leq k)$ | $P(n-k, k)$ | $P(n, k)$ |

ただし $S(n, k)$ は第二種スターリング数、 $B(n, k)$ はベル数、 $P(n, k)$ は分割数を表す。

- `vector<T> stirling_number_1st(int n)` : 符号付き第一種スターリング数 $S(n, 0), S(n, 1), \ldots, S(n, n)$ を返す。符号なしの $S(n, k) \times (-1)^{n-k}$ は $n$ 次の置換のうち $k$ 個の巡回に分解されるものの個数と意味付けられる。 $\Theta(n \log n)$ 。
- `vector<T> stirling_number_1st_fixed_k(int k, int n)` : 符号付き第一種スターリング数 $S(k, k), S(k+1, k), \ldots, S(n, k)$ を返す。 $\Theta(n + (n-k) \log (n-k))$ 。
- `vector<T> stirling_number_2nd(int n)` : 第二種スターリング数 $S(n, 0), S(n, 1), \ldots, S(n, n)$ を返す。 $\Theta(n \log n)$ 。
- `vector<T> stirling_number_2nd_fixed_k(int k, int n)` : 第二種スターリング数 $S(k, k), S(k+1, k), \ldots, S(n, k)$ を返す。 $\Theta(n + (n-k) \log (n-k))$ 。
- `vector<T> bell_number(int n)` : ベル数 $B(0, 0), B(1, 1), \ldots, B(n, n)$ を返す。つまり $n$ 個の区別できるボールをグループ分けする個数。 $\displaystyle e^{e^x-1} = \sum_{i=0}^{\infty} \frac{B(i, i)}{i!}x^i$ 。 $\Theta(n \log n)$ 。
- `vector<T> bell_number_fixed_n(int n)` : ベル数 $B(0, n), B(1, n), \ldots, B(n, n)$ を返す。写像 12 相の一つ。 $\Theta(n \log n)$ 。
- `vector<T> bernoulli_number(int n)` : ベルヌーイ数 $B_0, B_1, \ldots, B_n$ を返す。 $\displaystyle\frac{x}{e^x-1} = \sum_{i=0}^{\infty} \frac{B_i}{i!}x^i$ を満たす数。全て有理数になり、 $n$ 乗和の公式中に現れる。 $\Theta(n \log n)$ 。
- `vector<T> partition_number(int n)` : 分割数 $P_0, P_1, \ldots, P_n$ を返す。オイラーの五角数定理から簡単に計算できる。 $\Theta(n \log n)$ 。
