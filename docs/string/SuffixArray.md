## 概要

`s[a[0]:] < s[a[1]:] < ... < s[a[n-1]:]` なる `a` を suffix array と呼ぶ。SA-IS という手法により線形時間で求めることができる。ダブリングが準線形で実装が楽なので JOI はそれが良いかも。(蟻本参照)

- `vector<int> suffix_array(Container cont)` : suffix array を求める。座圧をするので $\Theta(n \log n)$ 。
- `vector<int> suffix_array(Container cont, int m)` : 全ての要素が $m$ 以下であるときに用いる。 $\Theta(n + m)$ 。
- `vector<int> suffix_array(string str)` : $m=256$ として呼び出す。
