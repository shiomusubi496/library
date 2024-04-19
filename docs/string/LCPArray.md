## 概要

SA 上で隣接する二つの suffix の Longest Common Prefix `lcp(s[sa[i]], s[sa[i + 1]])` をそれぞれ求める。

例えば Range Minimum Query に載せることで任意の二つの suffix の lcp を求めることができる。

- `vector<int> lcp_array(string s, vector<int> sa)` : `s` とその SA が与えられたときに lcp を求める。 $\Theta(\log n)$ 。
