## 概要

乱数を生成するクラス。テンプレート引数にとった型 `T` を使って乱数を生成する。 `operator()` の返り値の型である `result_type` をメンバ型に持つ。

- `Random()` : seed を `std::random_device` で生成する。 $\Theta(1)$ 。
- `Random(result_type seed)` : seed を与えられた値にする。 $\Theta(1)$ 。
- `result_type operator()` : 乱数を生成して返す。 $\Theta(1)$ 。
- `IntType uniform(IntType l, IntType r)` : `[l, r]` から整数を $1$ つ返す。全ての値は同様に確からしく出る。 $\Theta(1)$ 。
- `RealType uniform_real(RealType l, RealType r)` : `[l, r]` から実数を $1$ つ返す。全ての値は同様に確からしく出る。 $\Theta(1)$ 。
- `bool uniform_bool()` : `true` と `false` を一様に確からしく返す。 $\Theta(1)$ 。
- `pair<T, T> uniform_pair(T l, T r)` : `[l, r]` から整数を $2$ 個返す。全てのペアは同様に確からしく出る。期待 $\Theta(1)$ 。
- `vector<T> choice(int n, T l, T r)` : `[l, r]` から整数を $n$ 個返す。全ての整数組が同様に確からしく出る。期待 $\Theta(n \log n)$ 。
- `vector<T> choice_shuffle(int n, T l, T r)` : `[l, r]` から整数を $n$ 個返す。全ての整数組が同様に確からしく出る。内部で `shuffle` を使用している。 $\Theta(r - l)$ 。
- `void shuffle(Iter first, Iter last)` : `[first, last)` をシャッフルする。 $\Theta(n)$ 。
- `vector<T> permutation(int n)` : 長さ `n` の順列を返す。全ての順列が同様に確からしく出る。 $\Theta(n)$ 。
