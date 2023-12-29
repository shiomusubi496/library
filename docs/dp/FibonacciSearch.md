## 概要

$f : [L, R] \to \mathbb{R}$ について、ある $L \leq k \leq R$ が存在し、 $[L, k]$ で狭義単調減少かつ $[k, R]$ で狭義単調増加なときにそのような $k$ を求めることを考える。

- $x \lesseqgtr k$ ならば $f'(x) \lesseqgtr 0$ であることを利用して二分探索する方法。十分速いが、直接微分できない場合は $x, x+\epsilon$ で $2$ 回値を求める必要がある。

- 三分探索する方法。 $[L, R]$ を $1:2$ と $2:1$ に内分することを考えると、 $f\left(\frac{2L+R}{3}\right) < f\left(\frac{L+2R}{3}\right)$ ならば $\left[L, \frac{L+2R}{3}\right]$ に範囲を絞れるため、毎回区間幅が $\frac{2}{3}$ 倍になっていく。上記の二分探索では $\frac{1}{2}$ になるので下位互換みがある。

- 黄金分割探索する方法。この中では最速。黄金数 $\varphi = \frac{1+\sqrt{5}}{2}$ として、 $[L, R]$ を $(\varphi-1):1$ と $1:(\varphi-1)$ に内分する。三分探索と同様に区間幅を $\frac{1}{\varphi}$ 倍にすることができるが、その次の回で内分した点の片方が、必ずこの回で内分した点の片方と一致する。よって値を再利用することができ、計算回数が減る。

この黄金分割探索を $f:[L, R] \cap \mathbb{Z} \to \mathbb{R}$ で行ったのがフィボナッチ探索。開区間で持つとindexが綺麗になる。

例： $(0, 8)$ から初めて $f(3) < f(5)$ より $(0, 5)$ となる。 $f(2) < f(3)$ より $(0, 3)$ となる。 $f(1) < f(2)$ より $(0, 2)$ となり $f(1)$ が最小と求まった。

- `pair<ll, T> FibonacciSearch::minimize(ll l, ll r, T f(ll))` : $l \leq i \leq r$ なる整数 $i$ のうち $f(i)$ が最小値を取る $i$ と $f(i)$ のペアを返す。 $F_n \geq r-l+2$ なる最小の $n$ をとってくると、 $n-2$ 回以下の $f$ の呼び出しが行われる。

- `pair<ll, T> FibonacciSearch::maximize(ll l, ll r, T f(ll))` : 最大化する。

- `pair<ll, T> FibonacciSearch::minimize(ll l, ll r, T f(ll), Comp cmp)` : 比較関数を渡せる。
