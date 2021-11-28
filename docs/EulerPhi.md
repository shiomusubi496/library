## 概要

オイラーの $\phi$ 関数。読み方はトーシェント、ファイなど。

- `ll euler_phi(ll N)` : $\phi(N)$ を返す。 $\Theta(\sqrt N)$ 。

また、エラトステネスの篩を応用して、多くのクエリに効率よく答えることもできる。

- `EulerPhi(ll N)` : `N` 以下の $\phi$ 関数のテーブルを作る。 $\Theta(N\log\log N)$ 。
- `ll phi(ll x)` : $\phi(x)$ を返す。 $\Theta(1)$ 。
