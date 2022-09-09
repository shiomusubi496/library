## 概要

Range Chmin Chmax Add Assign Query と Range Min Max Sum Query を $\Theta(\log^2 N)$ で行えるすごい遅延セグ木。

基本的に使い方は遅延セグ木と同じだが、与える作用付きモノイドにおいて静的メンバ `break_cond` と `tag_cond` が必要。

抽象化されたのは `SegmentTreeBeats` から、 Range Chmin Chmax Add Assign Query Range Min Max Sum Query は `SegTreeBeats` から使う。

`add` クエリがない場合 $\Theta(\log N)$ になるらしい。
