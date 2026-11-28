---
title: 剰余環を係数体とする多項式環
documentation_of: //Modulo_Polynomial/Modulo_Polynomial.hpp
---

## Outline

係数が剰余環 (`modint` など) で, 精度 (何次未満までを保持するか) が付いた形式的ベキ級数の基底クラス. 保持, 線形演算, 添字, 入出力を担う. 積・除算は派生クラス ([Fast_Power_Series](Fast_Power_Series.md)) で定義する.

CRTP (`Derived` に派生クラスを渡す) を用いており, 演算の戻り値の型は `Derived` になる.

精度 $d$ の形式的ベキ級数 $P$ は $P \bmod{X^d}$ を表す. 係数は `poly` に保持し, その長さは $d$ 以下である. 保持していない次数の係数は $0$ とみなす. 2 つの級数に対する加減算の精度は, 小さい方とする.

## Contents

```cpp
template<typename mint, typename Derived>
class Modulo_Polynomial
```

* `mint` : 係数の型. `Derived` : CRTP の派生クラス.

### コンストラクタ

```cpp
Modulo_Polynomial(vector<mint> poly, int precision)
Modulo_Polynomial(vector<mint> poly)
Modulo_Polynomial(int precision)
Modulo_Polynomial()
```

* 係数列と精度から構築する. `poly` の長さが精度を超えるときは切り詰める. 精度を省略すると `poly.size()` になる.

### 線形演算

```cpp
Derived operator-() const
Derived& operator+=(const Derived &P),  operator+=(const mint &a)
Derived& operator-=(const Derived &P),  operator-=(const mint &a)
Derived& operator*=(const mint &a)
Derived& operator/=(const mint &a)
```

* 符号反転, 加算, 減算, スカラー倍, スカラー除算と, それに対応する二項演算子 `+`, `-`, `*`, `/` を提供する.
* 級数同士の演算の精度は小さい方に合わせる. 結果は高次の $0$ を取り除く (`reduce`).
* **制約** : `/=` では $a \neq 0$.
* **計算量** : 係数列の長さを $n$ として, $O(n)$ 時間.

### 添字・入出力

```cpp
mint operator[](int k) const
friend istream &operator>>(istream &is, Modulo_Polynomial &P)
friend ostream &operator<<(ostream &os, const Modulo_Polynomial &P)
```

* `P[k]` は $k$ 次の係数を返す. 保持していない次数のときは $0$ を返す.
* `>>` は精度個の係数を読み込む. `<<` は保持している係数を空白区切りで出力する.

### 大きさの調整

```cpp
void resize(int size = -1)
void weak_resize(int size = -1)
void reduce()
```

* `resize` は `poly` の長さを $\min(\text{size}, \text{precision})$ にする. $\text{size} = -1$ のときは精度にする.
* `weak_resize` は `poly` の長さが `size` より大きいときのみ切り詰める.
* `reduce` は高次の $0$ を取り除く.

### 性質

```cpp
bool is_zero() const
int size() const
int degree() const
int order() const
```

* `is_zero` : 零級数か.
* `size` : `poly` の長さ.
* `degree` : 次数. 零のときは $-1$.
* `order` : 係数が $0$ でない最小の次数. 零のときは $-1$.

## History

|日付|内容|
|---|---|
|2026-11-28|CRTP 化し, 線形演算を基底クラスに一本化した.|
