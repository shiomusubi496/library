## 概要

`y = ax + b` の形の `x` の一次関数に関するクエリを扱える。具体的には、一次関数を追加するクエリと、ある `x` に対して最小値を取る一次関数を求めるクエリ。

- `ConvexHullTrick()` : `ConvexHullTrick` を作成する。ここで、関数集合を $s$ と表す。 $\Theta(1)$ 。
- `void add_line(T a, T b)` : $s$ に `f(x) = ax + b` を追加する。 $\Theta(\log N)$ 。
- `T get_min(T x)` : $\min_{f \in s} f(x)$ を返す。 $\Theta(\log N)$ 。
- `Line get_min_line(T x)` : $\arg \min_{f \in s} f(x)$ に属する直線のうち 1 つを返す。 $\Theta(\log N)$ 。
