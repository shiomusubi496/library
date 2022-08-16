## 概要

有理数を持つ型。オーバーフローには十分注意する。

以下のメンバを持つ。

- `T get_num()` : 分子を返す。 $\Theta(1)$ 。
- `T get_den()` : 分母を返す。 $\Theta(1)$ 。
- `ld get_ld()` : 小数の値を返す。

さらに、以下の演算が動く。

```
+Rational
-Rational

++Rational
Rational++
--Rational
Rational--

Rational += Rational
Rational -= Rational
Rational *= Rational
Rational /= Rational

Rational + Rational
Rational - Rational
Rational * Rational
Rational / Rational

Rational == Rational
Rational != Rational
Rational < Rational
Rational <= Rational
Rational > Rational
Rational >= Rational

cin >> Rational
cout << Rational
```

すべて $\Theta(1)$ 。
