## 概要

エラトステネスの篩を使った $\Theta(\log N)$ の素因数分解。ただし、前処理は $\Theta(N)$ 。

- `PrimeFactor(int N)` : `N` 以下の値に対してエラトステネスの篩のテーブルを作成する。$\Theta(N)$。
- `bool is_prime(int x)` : `x` が素数かどうか判定する。 $\Theta(1)$ 。
- `vector<int> factor(int x)` : `x` を素因数分解する。返る値は昇順。 $\Theta(\log N)$ 。
- `vector<int> get_primes(int x)` : `x` 以下の素数の列を返す。 $\Theta(x)$ 。

素数判定のみしたい場合は `IsPrime` を使う。オーダーは `PrimeFactor` と同様。
