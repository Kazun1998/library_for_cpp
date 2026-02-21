---
title: 整数の桁
documentation_of: //Integer/Digit.hpp
---

## Outline

整数の表示や桁に関する計算を行う.

## Definition

$b$ を $2$ 以上の整数とする. このとき, 任意の正の整数 $N$ に対して, 以下をみたす整数の列 $a = (a_0, a_1, \dots, a_{d-1})$ がただ一つ存在する.
* $0 \leq i < d$ に対して, $0 \leq a_i < b$ である.
* $a_{d-1} \neq 0$.
* $N = a_{d-1} b^{d-1} + \dots + a_1 b + a_0$.

このとき, 以下を定義する.

* $b$ を底や基数という.
* $a$ を $N$ の $b$ 進表記という.
* $d$ を $N$ の $b$ 進表記における桁数という.
* $a_i$ を $N$ の $b$ 進表記における $b^i$ の位という.
  * 特に, $N$ の $b^{d-1}$ の位のことを $N$ の $b$ 進表記における最高位という.
* 和 $\displaystyle \sum_{i=0}^{d-1} a_i$ を $N$ の $b$ 進表記における桁和という.

## Remark

このライブラリにおいて, $b$ 進表記は $(a_{d-1}, a_{d-2}, \dots, a_1, a_0)$ のように, 逆順で扱うことに注意せよ.

## Contents

### Integer_Digits

```cpp
vector<ll> Integer_Digits(ll n, ll b = 10, int l = -1)
```

* $N$ の $b$ 進表記における表示を求める.
* **入力**
  * $b$ : 基数. デフォルトは $b = 10$.
  * $l$ : 出力される長さ付いて制御する.
    * $l = -1$ のときは, 厳密な意味での $b$ 進表記が返される.
    * $l \geq 0$ のときは, 長さが $l$ になるように調整される. 具体的には, $N$ の $b$ 進表記での表示を $a = (a_{d-1}, \dots, a_1, a_0)$ とするとき, それぞれ以下のようになる.
      * $l \gt d$ のとき: 返り値は $(\underbrace{0, \dots, 0}\_{l-d}, a_{d-1}, \dots, a_1, a_0)$ となる.
      * $l \leq d$ のとき: 返り値は $(a_{l-1}, \dots, a_1, a_0)$ となる.
* **計算量** : $O \left( \log_b N \right)$ 時間.

### Integer_Digits

```cpp
int Integer_Length(ll n, ll b = 10)
```

* $N$ の $b$ 進表記における桁数を求める.
* **入力**
  * $b$ : 基数. デフォルトは $b = 10$.
* **注意** : $0$ の桁数は $0$ とする.
* **計算量** : $O \left( \log_b N \right)$ 時間.

### Digit_Sum

```cpp
ll Digit_Sum(ll n, ll b = 10)
```

* $N$ の $b$ 進表記における桁和を求める.
* **入力**
  * $b$ : 基数. デフォルトは $b = 10$.
* **計算量** : $O \left( \log_b N \right)$ 時間.

### Digit_Count

```cpp
vector<ll> Digit_Count(ll n, ll b = 10)
```

* 整数 $N$ の $b$ 進表記における各数の出現回数を求める
* **入力**
  * $b$ : 基数. デフォルトは $b = 10$.
* **出力**
  * 長さ $b$ のリスト. 第 $j$ 要素では, $N$ の $b$ 進む表記における $j$ の登場回数が格納されている.
* **計算量** : $O \left( b + \log_b N \right)$ 時間.

### From_Digits

```cpp
ll From_Digits(const vector<ll> &digits, ll b = 10)
```

* $b$ 進表記が `digits` となる整数を求める.
* **入力**
  * $b$ : 基数. デフォルトは $b = 10$.
* **注意**
  * オーバーフローに注意.
* **計算量** : $O \left( \log_b N \right)$ 時間.

## History

|日付|内容|
|:---:|:---|
|2025/11/24|引数の変更 & ドキュメントの追加|