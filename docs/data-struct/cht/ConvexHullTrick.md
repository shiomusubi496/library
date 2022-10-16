## Overview

$y = ax + b$ の形の $x$ の一次関数に関するクエリを扱える。

一次関数の集合 $s$ が与えられたとき、 $s$ に一次関数を追加するクエリと、 $x=k$ における最小値を求めるクエリに答えられる。

## Usage

### Template Arguments

- `T` : 一次関数 $y = ax + b$ を扱うときの、 $a, b$ の型。デフォルトは `ll` 。
- `is_max` : 最小値クエリではなく最大値クエリを扱うか。デフォルトは `false` 。
- `LargeT` : オーバーフロー防止のために使われる、 `T` よりサイズの大きい型。デフォルトは `T` の 2 倍の桁を持つ型。

### Member Function

- `ConvexHullTrick()` : コンストラクタ。 $\Theta(1)$ 。
- `int add_line(T a, T b)` : $s$ に $f(x) = ax + b$ を追加する。返り値は追加された関数の番号。 $\Theta(\log N)$ 。
- `T get_min(T k)` : $\min_{f \in s} f(k)$ を返す。 $\Theta(\log N)$ 。
- `Line get_min_line(T k)` : $\arg \min_{f \in s} f(k)$ を返す。 $\Theta(\log N)$ 。
- `bool empty()` : $s = \emptyset$ であるかを返す。 $\Theta(1)$ 。
