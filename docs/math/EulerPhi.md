## 概要

オイラーの $\phi$ 関数。読み方はトーシェント、ファイなど。

- `ll euler_phi(ll N)` : $\phi(N)$ を返す。 $\Theta(\sqrt N)$ 。
- `ll euler_phi_pollardrho(ll N)` : $\phi(N)$ を返す。素因数分解に Pollard の Rho 法を用いている。計算量は PollardRho 参照。

また、エラトステネスの篩を応用して、多くのクエリに効率よく答えることもできる。

- `EulerPhi(ll N)` : `N` 以下の $\phi$ 関数のテーブルを作る。 $\Theta(N\log\log N)$ 。
- `ll phi(ll x)` : $\phi(x)$ を返す。 $\Theta(1)$ 。
