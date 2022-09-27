## 概要

- `vector<T> bitwise_xor_convolution(vector<T> a, vector<T> b)` :  
    次の条件を満たす $c$ を計算して返す。
    ただし $\oplus$ は bitwise xor とする。
    - $\displaystyle c_k = \sum_{i\ \oplus\ j = k} a_ib_j$
