## 概要

エラトステネスの篩を使った$O(\log N)$の素因数分解。ただし、前処理は$O(N\log\log N)$となる。

- `PrimeFactor(ll N)` : `N`以下の値に対してエラトステネスの篩のテーブルを作成する。$O(N\log\log N)$。
- `bool is_prime(ll x)` : `x`が素数かどうか判定する。$O(1)$。
- `vector<ll> factor(ll x)` : `x`を素因数分解する。返る値は昇順。$O(\log N)$。
