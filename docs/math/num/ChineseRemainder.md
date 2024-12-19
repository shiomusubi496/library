## 概要

$b_0, b_1, m_0, m_1$ が与えられたとき、 $M = \mathrm{lcm}(m_0, m_1)$ として、 $\left\{\begin{array}{l} x \equiv b_0 \pmod{m_0} \\ x \equiv b_1 \pmod{m_1} \\ \end{array} \right.$ を満たす $0 \leq x < M$ を見つけ $(x, M)$ の組を返す。

ただし、 $b_0 \not\equiv b_1 \pmod{\gcd(m_0, m_1)}$ のときこのような $x$ は存在しないため、 $(-1, -1)$ を返す。

$m_0, m_1$ が互いに素 (つまり $m_0 m_1 = M$) であるときこのような $x$ は必ず存在し、また一意であることで知られている。

- `PLL ChineseRemainder(ll b0, ll m0, ll b1, ll m1)` : 上記の通り。拡張ユークリッドの互除法を用いている。 $O(\log(m0 + m1))$ 。
- `PLL ChineseRemainder(vector<ll> b, vector<ll> m)` : 同様。 $O(n \log\max(m))$ 。
- `PLL Garner(vector<ll> b, vector<ll> m, ll MOD)` : 同様に $\mod MOD$ で求める。 $O(n^2 \log\max(m))$ 。
