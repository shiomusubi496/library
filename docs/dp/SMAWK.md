## 概要

totally monotone な行列について各行の最小値を取る列のうち最も左にあるものを求める。

- `vector<int> smawk(int H, int W, F f)` : $0 \leq i \leq H-1$ について $\arg \min_{j=0}^{W-1} f(i,j)$ を求める。 $\Theta(H+W)$ 。
