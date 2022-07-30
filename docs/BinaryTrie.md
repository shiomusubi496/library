## 概要

0/1 の trie 木で整数の多重集合 $s$ を管理する。以下 bit 数を $B$ とする。

- `BinaryTrie()` : $s := \emptyset$ で初期化する。 $\Theta(1)$ 。
- `int size()` :  $|s|$ を返す。 $\Theta(1)$ 。
- `bool empty()` : $s = \emptyset$ であるかを返す。 $\Theta(1)$ 。
- `void insert(ull x)` : `x` を追加する。 $\Theta(B)$ 。
- `void erase(ull x)` : `x` を一つ削除する。 $\Theta(B)$ 。
- `int count(ull x)` : `x` の個数を返す。 $\Theta(B)$ 。
- `void xor_all(ull x)` : $s := \{i \oplus x | i \in s\}$ とする。 $\Theta(1)$ 。
- `void kth_element(ll k)` : `k` 番目に小さい値を返す。 $\Theta(B)$ 。
- `void get_index(ull x)` : `x` 未満の値の個数を返す。 $\Theta(B)$ 。
