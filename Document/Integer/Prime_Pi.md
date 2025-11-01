---
title: 素数の個数計上 $\pi(x)$
documentation_of: //Integer/Prime_Pi.hpp
---

## Outline

正の整数 $N$ に対して, $N$ 以下の素数の数 $\pi(N)$ を $O\left( \dfrac{N^{3/4}}{\log N} \right)$ 時間で求める.

## Contents

```cpp
ll Prime_Pi(const ll N)
```

* $N$ 以下の素数の数 $\pi(N)$ を求める.
* **計算量** : $O \left(\dfrac{N^{3/4}}{\log N} \right)$ 時間