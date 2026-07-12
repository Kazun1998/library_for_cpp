---
title: 組み合わせ論に関する基本的な計算
documentation_of: //Counting/Combination_Calculator.hpp
---

## Outline

組み合わせ論に関する基本的な計算を行う.

## Theory

### 組み合わせを表す関数

### 階乗

* 記法: $n!$
* 組み合わせ論的意味合い
  * $n$ 個の区別できるものを一列に並べる方法の数.
* 主な性質
  * 再帰関係: $n! = n \times (n-1)!$ (ただし, $0! = 1$).
  * スターリングの公式 (Stirling's approximation): $n! \approx \sqrt{2 \pi n} \left( \dfrac{n}{e} \right)^n$.
* 計算方法
  * $n! = 1 \times 2 \times \dots \times n$.

### 二項係数

* 記法: $\dbinom{n}{r}, {}_n \mathrm{C}_r$.
* 組み合わせ論的意味合い
  * $n$ 個の区別できるものから $r$ 個を選び出す方法の数 (組合せの数).
* 主な性質
  * 対称性: $\dbinom{n}{r} = \dbinom{n}{n-r}$.
  * 加法公式 (パスカルの三角形の漸化式): $\dbinom{n}{r} = \dbinom{n-1}{r-1} + \dbinom{n-1}{r}$.
  * 総和公式: $\sum_{r=0}^{n} \dbinom{n}{r} = 2^n$.
* 計算方法
  * $\dbinom{n}{r} = \dfrac{n!}{r!(n-r)!}$.

### 順列

* 記法: ${}_n \mathrm{P}_r$.
* 組み合わせ論的意味合い
  * $n$ 個の区別できるものから $r$ 個を選び出し, 一列に並べる方法の数 (順列の数).
* 主な性質
  * 組合せとの関係: ${}_n \mathrm{P}_r = r! \times \dbinom{n}{r}$.
  * 特殊な値: ${}_n \mathrm{P}_n = n!$, ${}_n \mathrm{P}_0 = 1$.
* 計算方法
  * ${}_n \mathrm{P}_r = \dfrac{n!}{(n-r)!}$.

### 重複組合せ

* 記法: ${}_n \mathrm{H}_r$.
* 組み合わせ論的意味合い
  * $n$ 種類の区別できるものから, 重複を許して $r$ 個を選ぶ方法の数.
  * 区別できない $r$ 個のものを区別できる $n$ 人に配る方法の数 (各人が受け取る個数は 0 個以上).
* 主な性質
  * 二項係数への帰着: ${}_n \mathrm{H}_r = \dbinom{n+r-1}{r}$.
  * 非負整数解の個数: 方程式 $x_1 + x_2 + \dots + x_n = r$ を満たす非負整数解 $(x_1, x_2, \dots, x_n)$ の数は ${}_n \mathrm{H}_r$ である.
  * 正の整数への分配関係: $r$ 個の区別できないものを $n$ 人に少なくとも 1 個ずつ配る方法の数は ${}_n \mathrm{H}_{r-n} = \dbinom{r-1}{n-1}$ 通り (ただし, $r \ge n$).
* 計算方法
  * ${}_n \mathrm{H}_r = \dbinom{n+r-1}{r}$ (ただし, ${}_0 \mathrm{H}_0 = 1$ とする).

### 多項係数

* 記法: $\dbinom{n}{r_1, r_2, \dots, r_m}$ (ただし, $n = r_1 + r_2 + \dots + r_m$).
* 組み合わせ論的意味合い
  * $n$ 個の区別できるものを, それぞれサイズが $r_1, r_2, \dots, r_m$ である $m$ 個の区別できるグループに分ける方法の数.
* 主な性質
  * 多項定理: $(x_1 + x_2 + \dots + x_m)^n = \sum_{r_1+\dots+r_m=n} \dbinom{n}{r_1, r_2, \dots, r_m} x_1^{r_1} x_2^{r_2} \dots x_m^{r_m}$.
  * 二項係数による累積的表現: $\dbinom{n}{r_1, r_2, \dots, r_m} = \dbinom{n}{r_1} \dbinom{n-r_1}{r_2} \dots \dbinom{r_m}{r_m}$.
* 計算方法
  * $\dbinom{n}{r_1, r_2, \dots, r_m} = \dfrac{n!}{r_1! r_2! \dots r_m!}$.

### カタラン数

* 記法: $C_n$.
* 組み合わせ論的意味合い
  * $n$ 個の `(` と $n$ 個の `)` からなる正しいカッコ列 (Dyck path) の数.
  * グリッド上の最短経路において, 対角線 $y = x$ を超えずに $(0, 0)$ から $(n, n)$ まで移動する方法の数.
  * $(n+1)$ 葉の二分木の数.
  * $(n+2)$ 角形を三角形に分割する方法の数.
* 主な性質
  * 再帰的関係式 (積の和): $C_0 = 1$ および $C_{n+1} = \sum_{i=0}^{n} C_i C_{n-i}$.
  * 二項係数の差としての表現: $C_n = \dbinom{2n}{n} - \dbinom{2n}{n-1}$.
* 計算方法
  * $C_n = \dfrac{(2n)!}{(n+1)! n!}$.

## Contents

### Constructer

```cpp
Combination_Calculator(const int n)
```

* サイズが $n$ の組み合わせ論に関する基本的な計算を行う計算機を作成する.
* **計算量** : $O(n)$ 時間.

### fact

```cpp
calc.fact(const int k)
```

* $k!$ を計算する.
* **計算量** : ならし $O(1)$ 時間.

### fact_inv

```cpp
calc.fact_inv(const int k)
```

* $(k!)^{-1}$ を計算する.
* **計算量** : ならし $O(1)$ 時間.

### inv

```cpp
calc.inv(const int k)
```

* $k^{-1}$ を計算する.
* **計算量** : ならし $O(1)$ 時間.

### nCr

```cpp
calc.nCr(const int n, const int r)
```

* 二項係数 $_n\mathrm{C}_r$ を計算する.
* **計算量** : ならし $O(1)$ 時間.

### nPr

```cpp
calc.nPr(const int n, const int r)
```

* 順列の数 $_n\mathrm{P}_r$ を計算する.
* **計算量** : ならし $O(1)$ 時間.

### nHr

```cpp
calc.nHr(const int n, const int r)
```

* 重複組合せ $_n\mathrm{H}_r$ を計算する.
* **計算量** : ならし $O(1)$ 時間.

### multinomial_coefficient

```cpp
calc.multinomial_coefficient(const vector<int> &ks)
```

* 多項係数 $\dbinom{k_1+\dots+k_m}{k_1, \dots, k_m}$ を計算する.
* **計算量** : ならし $O(m)$ 時間.

### catalan

```cpp
calc.catalan(const int n)
```

* Catalan 数 $C_n := \dfrac{1}{n+1} \dbinom{2n}{n}$ を計算する.
* **計算量** : ならし $O(1)$ 時間.
