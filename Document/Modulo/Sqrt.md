---
title: 平方根 mod
documentation_of: //Modulo/Sqrt.hpp
---

## Outline

$P$ を素数とする.

$A \in \mathbb{Z}/P \mathbb{Z}$ に対して, $X$ に関する 二次方程式 $X^2 = A$ の解の存在判定と, 解の発見を行うアルゴリズムを提供する.

## Contents

### Legendre

```cpp
int Legendre(const Modulo &A)
```

* $A = a + P \mathbb{Z}$ としたとき, Legendre 記号 $\left(\frac{a}{P}\right)$ を求める.
* **返り値**
    * $A = 0$ のときは $\left(\frac{a}{P}\right) = 0$.
    * $A \neq 0$ かつ, $A$ が平方剰余のときは $\left(\frac{a}{P}\right) = 1$.
    * $A$ が平方非剰余のときは $\left(\frac{a}{P}\right) = -1$.

## History

|日付|内容|
|:---:|:---:|
|2026/01/01|Sqrt 関連メソッド実装|
