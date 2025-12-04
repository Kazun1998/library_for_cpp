---
title: $q$ -数による組み合わせ論に関する基本的な計算
documentation_of: //Counting/Q_Analog_Combination_Calculator.hpp
---

## Outline

$q$ -数における組み合わせに関する基本的な計算を行う.

## Definition

理論対して $q \to 1$ の極限によって元の理論に一致するようなパラメータ $q$ を導入して拡張することを $q$ -類似という.

### 整数の $q$ -類似

#### $q$ -数

$q$ -数 ($q$ -整数, $q$ -ブラケット) $[n]_q$ を

$$ [n]_q := \sum_{k=0}^{n-1} q^k = \dfrac{1-q^n}{1-q} $$

で定義する.

#### $q$ -階乗

$q$ -階乗 $[n]_q!$ を

$$ [n]_q ! := \prod_{k=1}^n [k]_q! $$

で定義する.

#### $q$ -二項係数, $q$ -多項係数

$0 \leq r \leq n$ とする. $q$ -二項係数 $\dbinom{n}{r}_q$ を

$$ \dbinom{n}{r}_q := \dfrac{[n]_q!}{[r]_q! [n-r]_q!} $$

で定義する.

同様にして, 非負整数 $r_1, r_2, \dots, r_m$ に対して,

$$ \dbinom{k_1 + k_2 + \dots + k_m}{k_1, \dots, k_m}_q := \dfrac{[k_1 + k_2 + \dots + k_m]_q!}{[k_1]_q! [k_2]_q! \dots [k_m]_q!} $$

と定義する.

## Theory

## Contents

### Constructer

```cpp
Q_Analog_Combination_Calculator(const mint q, const int n)
```

* 固定されるパラメータ $q$ に関するサイズが $n$ の組み合わせ論に関する基本的な計算を行う計算機を作成する.
* **計算量** : $O(n)$ 時間.

### q_power

```cpp
power(const int k)
```

* $q^k$ を求める.
* **計算量** : ならし $O(1)$ 時間.

### q_bracket

```cpp
q_bracket(const int n)
```

* $q$ -数 $[n]_q$ を求める.
* **計算量** : ならし $O(1)$ 時間.

### q_fact

```cpp
q_fact(const int n)
```

* $q$ -階乗 $[n]_q!$ を計算する.
* **計算量** : ならし $O(1)$ 時間.

### q_fact_inv

```cpp
q_fact_inv(const int n)
```

* $q$ -階乗 $[n]_q!$ の逆数 $([n]_q!)^{-1}$ を求める.
* **計算量** : ならし $O(1)$ 時間.

### q_inv

```cpp
q_inv(const int n)
```

* $q$ -数 $[n]_q$ の逆数 $[n]_q^{-1}$ を求める.
* **計算量** : ならし $O(1)$ 時間.

### q_nCr

```cpp
q_nCr(const int n, const int r)
```

* $q$ -二項係数 $\left(_n\mathrm{C}_r\right)_q$ を計算する.
* **計算量** : ならし $O(1)$ 時間.

### q_nPr

```cpp
q_nPr(const int n, const int r)
```

* $q$ -順列の数 $\left(_n\mathrm{P}_r\right)_q$ を計算する.
* **計算量** : ならし $O(1)$ 時間.

### q_nHr

```cpp
q_nHr(const int n, const int r)
```

* $q$ -重複組合せ $\left(_n\mathrm{H}_r\right)_q$ を計算する.
* **計算量** : ならし $O(1)$ 時間.

### q_multinomial_coefficient

```cpp
q_multinomial_coefficient(const vector<int> &ks)
```

* $q$ -多項係数 $\dbinom{k_1+\dots+k_m}{k_1, \dots, k_m}_q$ を計算する.
* **計算量** : ならし $O(m)$ 時間.
