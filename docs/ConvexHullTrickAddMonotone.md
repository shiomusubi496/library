## 概要

Convex Hull Trick のうち、追加クエリで与えられる直線の傾きが単調増加あるいは単調減少であるような場合に使える。

通常の Convex Hull Trick は `std::set` などを使う必要があるのに対して、単調増加あるいは単調減少の場合は `std::deque` を用いればよいため、二分探索をしない追加クエリの計算量が落ちる。

さらに、取得クエリの `x` が単調増加あるいは単調減少のときは二分探索をせず要らなくなった直線を消していけばいいので、取得クエリの計算量も落ちる。当然、 `get_min` `inc_get_min` `dec_get_min` を同時に使ってはいけない。

- `ConvexHullTrickAddMonotone()` : `ConvexHullTrick` を作成する。ここで、関数集合を $s$ と表す。 $\Theta(1)$ 。
- `void add_line(T a, T b)` : $s$ に `f(x) = ax + b` を追加する。 $\Theta(1)$ 。
- `T get_min(T x)` : $\min_{f \in s} f(x)$ を返す。 $\Theta(\log N)$ 。
- `T inc_get_min(T x)` : `x` が単調増加であるときに使う。機能は `get_min` と同等。ならし $\Theta(1)$ 。
- `T dec_get_min(T x)` : `x` が単調減少であるときに使う。機能は `get_min` と同等。ならし $\Theta(1)$ 。
- `bool empty()` : $s = \emptyset$ であるかを返す。 $\Theta(1)$ 。
