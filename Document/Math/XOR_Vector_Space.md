---
title: XOR ベクトル空間
documentation_of: //Math/XOR_Vector_Space.hpp
---

## Outline

XOR 演算によるベクトル空間に関する計算を行う.

## Definition

任意の非負整数 $x \in \mathbb{N}$ はただ一つの二進数表示

$$ x = \sum_{i=0}^\infty b_i 2^i \quad (b_i \in \{0, 1\}) $$

を持つ.

$\mathbb{F}_2$ 上の列で, 有限個の項を除いて $0$ であるような列全体の集合を $V$ とする.

このとき, $\varphi: \mathbb{N} \to V, \psi: V \to \mathbb{N}$ を

$$ \varphi(x) := (b_i), \quad \psi((b_i)) := \sum_{i=0}^\infty b_i 2^i $$

で定めると, これらは逆写像になる.

また, $V$ はベクトル空間であるため, $\varphi$ や $\psi$ による同一視によって, $\mathbb{N}$ を $\mathbb{F}_2$ 係数のベクトル空間とみなすことができる.

このとき, $\mathbb{N}$ におけるベクトルとしての和を XOR という.

## Theory

以下が従う.

* $\mathbb{N}$ は $\{ 2^i \mid i \in \mathbb{N}\}$ を基底とするベクトル空間である.
* $\mathbb{N}$ は無限次元の空間ではあるが, 実用的には, $V_n := \\{ i \mid 0 \leq i \lt 2^n \\}$ に制限して扱う. この $V_n$ は $\mathbb{N}$ の $n$ 次元部分空間になる.
* $\mathbb{N}$ の零ベクトルは $0$ である.
* $x \in \mathbb{N}$ の逆元 $-x$ は自分自身である. つまり, $-x=x$ である.

## Contents

### Constructor

```cpp
template<integral T>
Xor_Vector_Space()
```

* 型 `T` で扱える範囲に制限した $V_n$ の部分空間 $V$ 生成する.
  * 例
    * `T` = `int` のときは $V_{31} \quad (2^{31} \lt 2.2 \times 10^9 )$.
    * `T` = `long long` のときは $V_{63} \quad (2^{63} \lt 9.3 \times 10^{18})$.

```cpp
template<integral T>
Xor_Vector_Space(const vector<T> &vectors)
```

* `vectors` に含まれる `T` の要素でベクトル空間を生成する.

### add_vector

```cpp
bool add_vector(T x)
```

* ベクトル空間に $x$ を加えて更新する.
* **返り値**
  * $x$ を追加して, 次元が増えるならば `true`, そうでなければ `false`.

### projection

```cpp
bool projection(T x)
```

* 型 `T` の $x$ に対して, $x = a + b, b \in V$ となる型 `T` の $a$ が存在する. この $a$ を求める.
* **返り値** : $x - a \in V$ となる $a$.

### contains

```cpp
bool contains(T x)
```

* $x \in V$ かどうかを判定する.

### dimension

```cpp
bool dimension()
```

* $V$ のベクトル空間としての次元を求める.

### order operator

```cpp
bool operator<=(const Xor_Vector_Space &W)
```

* ベクトル空間として, $V \subset W$ かどうかを判定する.
