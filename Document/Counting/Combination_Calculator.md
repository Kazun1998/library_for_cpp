---
title: 組み合わせ論に関する基本的な計算
documentation_of: //Counting/Combination_Calculator.hpp
---

## Outline

組み合わせ論に関する基本的な計算を行う.

## Theory

### 組み合わせを表す関数

(人は互いに区別がつき, ものは互いに区別がつかないとする.)

||意味合い|計算方法|
|:--:|:--:|:--:|
|$N!$|$N$ 人を1列に並べる方法|$N!=1 \times 2 \times \dots \times N$|
|$\dbinom{N}{r}$|$N$ 人から $r$ 人を選び出す方法 |$\dbinom{N}{r}=\dfrac{N!}{r!(N-r)!}$|
|${}_N \mathrm{P}_r$|$N$ 人から $r$ 人を選び出し, その $r$ 人を一列に並べる方法|${}_N \mathrm{P}_r=\dfrac{N!}{(N-r)!}$|
|${}_N \mathrm{H}_r$|$N$ 個のものを $r$ 人に配る方法|${}_N \mathrm{H}_r=\dbinom{N+r-1}{r}$ <br> (ただし, $_0\mathrm{H}_0=1$ とする.)|
|$\dbinom{N}{r_1, r_2, \dots, r_m}$ <br> $(N=r_1+\dots+r_m)$|$N$ 人を $r_1$ 人の $1$ 班, $\cdots$, $r_m$ 人の $m$ 班に分ける方法|$\dbinom{N}{r_1,r_2, \dots, r_m}=\dfrac{N!}{r_1!r_2! \dots r_m!}$|
|$C_n$<br>(カタラン数)|$N$ 個の `(` と $N$ 個の `)` からなる文字列が正しい文字列になる文字列の数 (など) |$C_N=\dfrac{(2N)!}{(N+1)!N!}$|

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

