## 概要

様々な演算で自動で mod を取ってくれる構造体。

- `StaticModInt` : mod が問題で与えられる等の場合に使う
- `DynamicModInt` : mod が入力で与えられる等の場合に使う

以下のメンバを持つ。

- `ll get()` : modint の持つ値を返す。 $\Theta(1)$ 。
- `ll get_mod()` : 現在の mod を返す。 $\Theta(1)$ 。
- `void set_mod(ll m)` : (`DynamicModInt` のみ) mod を `m` にセットする。 $\Theta(1)$ 。
- `modint inv()` : 逆数を返す。 $\Theta(\log mod)$ 。
- `modint pow(ll x)` : `x` 乗を返す。 $\Theta(\log x)$ 。

### 演算

以下の演算が動く。

```
+modint
-modint

modint++
modint--
++modint
--modint

modint += modint
modint -= modint
modint *= modint
modint /= modint

modint + modint
modint - modint
modint * modint
modint / modint

modint == modint
modint != modint

cin >> modint
cout << modint
```

割り算は $\Theta(\log mod)$ 、それ以外は $\Theta(1)$ 。
