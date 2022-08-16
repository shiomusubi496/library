## 概要

Euler Tour と $\pm 1$ RMQ を使うことによって、前処理 $\Theta(N)$ 、クエリ毎 $\Theta(1)$ で LCA を求める。 Sparse Table を使うと前処理 $\Theta(N \log N)$ 、各クエリ $\Theta(1)$ となるため、こちらの方がオーダーが良い。

機能は `EulerTour` と同じなので、そちらを参照。
