## 概要

ワイルドカードを持つ文字列でパターンマッチングを行う。アルファベットなら MOD 2 つで畳み込めば決定的に可能。

IFFT はまとめていいので FFT 6 回 + IFFT 1 回、また middle product でパターンの長さに計算量が依らない。

Schwartz-Zippel Lemma により、文字をランダムに取れば MOD 1 つでもそれぞれ 3/MOD とかの確率で正しくなる。 TL が厳しいときは試してみると良さそう。

- `vector<bool> wildcard_pattern_matching(vector<int> a, vector<int> b, bool deterministic = true)` : 長さ $n$ の文字列 $a$ と長さ $m$ のパターン $b$ に対して、 $c_i := $ 全ての $0 \leq j \leq m-1$ に対し $a_{i+j} = b_j$ もしくはどちらかが $0$ に等しいか、の長さ $n-m+1$ の文字列を返す。 $\Theta(n \log n)$ 。

- `vector<bool> wildcard_pattern_matching(string a, string b, char wildcard = '*', bool deterministic = true)` : 同上。ワイルドカードを指定できる。
