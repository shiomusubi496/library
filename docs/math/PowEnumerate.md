## 概要

$a_0, a_1, \ldots, a_{n-1}$ について、 $\prod_i a_i$ の逆数を一度計算するだけで、適当な累積積をかけて全ての逆元を得られる。

- `vector<T> inv_enumerate(vector<T> a)` : $a_0^{-1}, a_1^{-1}, \ldots$ を返す。 $\Theta(n + \log p)$

$i=0, 1, \ldots, n$ について $i^m$ を列挙したいとき、愚直にやると $\Theta(n \log m)$ だが、篩を用いて素数の $i$ のみ $i^m$ を計算し、合成数はそれらの積で上手く計算できる。

- `vector<T> pow_enumerate(int n, ll m = n)` : $\Theta\left(n+\cfrac{n \log m}{\log n}\right)$ (素数定理より)。特に $n=m$ や $n>m$ のとき線形時間になる。
