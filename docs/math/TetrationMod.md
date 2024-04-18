## 概要

$a \uparrow \uparrow b = a^{a^{a^{\cdots}}}$ $(b\ \text{個})$ を $\mod m$ で求める。ただし $0^0=1$ としている。

内部で Euler の phi 関数を用いており、前計算なしだと $\Theta(\sqrt m)$ 時間かかる。

- `ll tetration_mod(ll a, ll b, ll m)` : $\Theta(\sqrt m)$ 。
