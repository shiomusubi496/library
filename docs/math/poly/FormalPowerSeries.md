## 概要

形式的冪級数を扱う。以下 `FPS` は `FormalPowerSeries<T>` の意。 `vector<T>` を継承している。

- `FPS()` : サイズ $0$ で初期化。
- `FPS(int n)` : サイズ $n$ で初期化。
- `FPS(int n, T a)` : サイズ $n$ 、係数は全て $a$ で初期化。
- `FPS prefix(int n)` : 最初の $n$ 項を返す。ただし $n$ 項に満たない部分は $0$ で埋める。
- `FPS eval(T a)` : $f(a)$ を返す。本来 FPS には定義されないが、多項式として扱うことがある都合から。

また演算は以下が可能。計算量は FPS 同士の乗算・除算・剰余が $\Theta(n \log n)$ 、それ以外は $\Theta(n)$ 。

```
+FPS
-FPS

FPS <<= n
FPS >>= n

FPS << n
FPS >> n

FPS += FPS
FPS -= FPS
FPS *= FPS
FPS *= n
FPS /= n

FPS + FPS
FPS - FPS
FPS * FPS
FPS * n
n * FPS
FPS / n

div(FPS, FPS) (多項式除算、切り捨て)
FPS % FPS
```

また以下も可能。 `deg` は省略すると `size()` になる。

- `FPS diff()` : $\frac{d}{dx}f$ を返す。 $\Theta(n)$ 。
- `FPS integral()` : $\int f\ dx$ を返す。 $\Theta(n)$ 。
- `FPS inv(int deg)` : $1/f \bmod x^{deg}$ を返す。 $\Theta(n \log n)$ 。
- `FPS log(int deg)` : $\log f \bmod x^{deg}$ を返す。 $\Theta(n \log n)$ 。
- `FPS exp(int deg)` : $\exp(f) \bmod x^{deg}$ を返す。 $\Theta(n \log n)$ 。
- `FPS pow(ll k, int deg)` : $f^k \bmod x^{deg}$ を返す。 $\Theta(n \log n)$ 。
- `FPS sqrt(int deg)` : $g^2 \equiv f \pmod {x^{deg}}$ なる $g$ を返す。 $\Theta(n \log n)$ 。
- `FPS compse(int g, int deg)` : $f(g) \bmod x^{deg}$ を返す。 $\Theta((n \log n)^{1.5})$ 。 `deg != -1` に対しては未 verify 。
- `FPS compinv(int deg)` : $f(g) \equiv g(f) \equiv x \pmod x^{deg}$ なる $g$ を返す。 $\Theta((n \log n)^{1.5})$ 。 `deg != -1` に対しては未 verify 。
