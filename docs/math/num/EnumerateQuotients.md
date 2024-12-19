## 概要

正整数 $n$ に対して、 $1 \leq i \leq n$ について $\lfloor \frac{n}{i} \rfloor$ の値はたかだか $2\lceil \sqrt{n} \rceil$ で抑えられる。これを列挙する。

- `vector<ll> enumerate_quotients(ll N)` : 返り値を $Q=(Q_1,Q_2,\ldots,Q_K)$ とすると、 $Q_1 = 1, Q_K = N+1$ で、 $\lfloor \frac{N}{Q_i} \rfloor = \lfloor \frac{N}{Q_{i+1}-1} \rfloor$ かつ $\lfloor \frac{N}{Q_i-1} \rfloor \neq \lfloor \frac{N}{Q_i} \rfloor$ を満たす。 $\{\lfloor \frac{N}{Q_i} \rfloor\}$ があり得る商の集合となる。 $\Theta(K)$ 。
