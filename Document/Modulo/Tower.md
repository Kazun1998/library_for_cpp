---
title: 指数タワー
documentation_of: //Modulo/Tower.hpp
---

## Outline

指数タワーの計算結果を $M$ で割った余りに関するメソッドを提供する.

## Contents

### Power_Tower

```cpp
Modulo Power_Tower(vector<ll> tower, ll m)
```

* `tower` を $(a_0, a_1, \dots, a_{n-1})$ とする. このとき, ${a_0}^{a_1^{\dots^{a_{k-1}}}}$ を $m$ で割った余りを求める.
* **計算量**: $O(\sqrt{M} + \min(k, \log m) \log m)$ 時間.

### Tetoration

```cpp
Modulo Tetoration(ll a, ll k, ll m)
```

* Tetoration $a \uparrow\uparrow k$ を $m$ で割った余りを求める. ただし, $a \uparrow\uparrow k = \underbrace{a^{a^{\dots^{a}}}}_{k} $ である.
* **計算量**: $O(\sqrt{M} + \min(k, \log m) \log m)$ 時間.

## History

|日付|内容|
|:---:|:---:|
|2026/03/01| Power_Tower, Tetoration の実装 |
