## 概要

素因数分解を高速に行う。フロイドの循環検出法に基づいている。

- `vector<ull> factorize(ull n)` : `n` を素因数分解し、昇順に素因数を返す。期待 $O(\sqrt[4]{n} \log n)$ であると言われている。
- `vector<ll> divisors_pr(ll n)` : `n` の約数を昇順に返す。 $n$ の約数の個数に比例する計算量がかかる。