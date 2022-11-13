## 概要

高速に素数判定を行う。本来確率的アルゴリズムだが、 $2^{63}$ 未満の値について決定的に判定できる。

- `bool is_prime_mr(ll n)` : `n` が素数であるか判定する。 $\Theta(\log n)$ 。
- `constexpr bool is_prime_v<ll n>` : `n` が素数であるかを判定するメタ関数。
