## Overview

$y = ax + b$ の形の $x$ の一次関数($x$ の定義域つき)に関するクエリを扱える。

一次関数の集合 $s$ が与えられたとき、 $s$ に一次関数を追加するクエリと、 $x=k$ における最小値を求めるクエリに答えられる。

内部的には木構造を利用してうまく見る必要のある線分を減らしている。

## Usage

### Template Arguments

- `T` : 一次関数 $y = ax + b$ を扱うときの、 $a, b$ の型。デフォルトは `ll` 。
- `is_max` : 最小値クエリではなく最大値クエリを扱うか。デフォルトは `false` 。

### Member Function

- `LiChaoTree(vector<T> x)` : コンストラクタ。 `get_min` などで与えられる `x` の列を渡す。 $\Theta(N)$ 。
- `int add_segment(int l, int r, T a, T b)` : $s$ に $f(x) = ax + b (x[l] \leq x < x[r])$ を追加する。返り値は追加された関数の番号。 $\Theta(\log^2 N)$ 。
- `int add_line(T a, T b)` : $s$ に $f(x) = ax + b$ を追加する。返り値は追加された関数の番号。 $\Theta(\log N)$ 。
- `T get_min(T k)` : $\min_{f \in s} f(k)$ を返す。そのようなものがないときは `infinity<T>::max` を返す。 $\Theta(\log N)$ 。
- `Line get_min_line(T k)` : $\arg \min_{f \in s} f(k)$ を返す。 $\Theta(\log N)$ 。
- `bool empty()` : $s = \emptyset$ であるかを返す。 $\Theta(1)$ 。
