## 概要

- `void divisor_zeta_transform(vector<T>& a)` :  
    次の条件を満たす $b$ を計算し、 $a$ に代入する。
    - $\displaystyle b_i = \sum_{j \mid i} a_j$
    
- `void divisor_moebius_transform(vector<T>& a)` :  
    次の条件を満たす $b$ を計算し、 $a$ に代入する。
    - $\displaystyle a_i = \sum_{j \mid i} b_j$
