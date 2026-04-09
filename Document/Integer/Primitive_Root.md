---
title: 原始根
documentation_of: //Integer/Primitive_Root.hpp
---

## Outline

$\mathbb{Z}/n \mathbb{Z}$ における原始根を求める.

## Definition

$g \in \mathbb{Z} / n \mathbb{Z}$ について, $\operatorname{ord} g = \varphi(n)$ が成り立つ時, $g$ は $\mathbb{Z} / n \mathbb{Z}$ における原始根という.

## Theory 

### 原始根の存在性

原始根の存在性について, 以下の特徴づけがある.

* (a) $\mathbb{Z}/n \mathbb{Z}$ における原始根が存在する.
* (b) $n$ はいずれかのうちのどれかである.
  * $n = 1, 2, 4$.
  * 奇素数 $p$ と正の整数 $k$ を用いて, $n = p^k$ である.
  * 奇素数 $p$ と正の整数 $k$ を用いて, $n = 2p^k$ である.

### 判定条件

$g \in \mathbb{Z}/n \mathbb{Z}$ が原始根かどうかを判定する. そのためには, 以下の特徴づけを用いる.

* (a) $g$ は $\mathbb{Z}/n \mathbb{Z}$ における原始根である.
* (b) 任意の $\varphi(n)$ の素因数 $q$ に対して, $g^{\frac{\varphi(n)}{q}} \neq 1$ である.

**証明**

#### (a) ならば (b)

対偶を示す.

ある $\varphi(n)$ の素因数 $q$ に対して, $g^{\frac{\varphi(n)}{q}} = 1$ だったとする.

このとき, $q > 1$ であるので, $\frac{\varphi(n)}{q} < \varphi(n)$ である. 故に, $g$ は原始根にならない.

#### (b) ならば (a)

対偶を示す.

$g$ は $\mathbb{Z}/n \mathbb{Z}$ における原始根でないとする. $g^r = 1, 1 \leq r < \varphi(n)$ となる整数 $r$ が存在する. Lagrange の定理により, $r$ は $\varphi(n)$ の真の約数である. 故に, $\frac{\varphi(n)}{r}$ の素因数 $q$ をとることができる.

このとき, $\frac{\varphi(n)}{q}$ は $r$ の倍数である. 故に, $\frac{\varphi(n)}{q} = ra$ となる整数 $a$ が存在する.

すると,

$$ g^{\frac{\varphi(n)}{q}} = g^{ra} = (g^r)^a = 1^a = 1 $$

となり, (b) が成り立たなくなる.


## Contents

### has_Primitive_Root

```cpp
bool has_Primitive_Root(const uint64_t n)
```

* $\mathbb{Z}/n\mathbb{Z}$ に原始根が存在するかどうかを判定する.
* **計算量** : $O(n^{1/4})$ 時間

### Find_Primitive_Root

```cpp
uint64_t Find_Primitive_Root(const uint64_t n)
```

* $\mathbb{Z}/n\mathbb{Z}$ に原始根を $1$ つ求める.
* **返り値**
  * 原始根が存在しない場合の返り値は $0$ になる.
  * $n = 1$ のときの返り値も $0$ になるため, 混同に注意.
* **計算量** : $O(n^{1/4})$ 時間

## History

|日付|内容|
|:---:|:---|
|2026/04/10| has_Primitive_Root, Find_Primitive_Root の実装 |
