---
title: 離散フーリエ変換, 数論変換
documentation_of: //Modulo_Polynomial/Numeric_Theory_Translation.hpp
---

## Outline

畳み込みに関する計算及び, 応用例として, 形式的ベキ級数に関する演算を高速に行う.

## Theory

$F$ を体とする. $F$ には原始 $n$ 乗根 $\zeta_n \in F$ が存在するとする.

このとき, $F$ における長さ $n$ の離散フーリエ変換 $\mathcal{F}_n: F^n \to F^n$ を

$$ \mathcal{F}_n \boldsymbol{a} := W_n \boldsymbol{a}$$

で定義する. ただし, $W_n$ とは, 以下で定義される $F$ 係数の $n$ 次正方行列である.

$$ W_n := \dfrac{1}{n} (\zeta_n^{ij})_{\substack{0 \leq i \lt n \\ 0 \leq j \lt n}} $$

また, 長さ $n$ の逆離散フーリエ変換 $\mathcal{F}^{-1}_n: F^n \to F^n$ を

$$ \mathcal{F}^{-1}_n \boldsymbol{b} := W'_n \boldsymbol{b}$$

で定義する. ただし, $W'_n$ とは, 以下で定義される $F$ 係数の $n$ 次正方行列である.

$$ W'_n := (\zeta_n^{-st})_{\substack{0 \leq s \lt n \\ 0 \leq t \lt n}} $$


このとき,　$\mathcal{F}, \mathcal{F'}$ は有限次元の線形空間間の線形写像であり,

$$\begin{align*}
    \left(\mathcal{F}^{-1}_n \left(\mathcal{F}_n \boldsymbol{a} \right) \right)_i
    &= \sum_{t=0}^{n-1} \dfrac{1}{n} \zeta_n^{-it} \left(\mathcal{F}_n \boldsymbol{a} \right)_t \\
    &= \dfrac{1}{n} \sum_{t=0}^{n-1} \zeta_n^{-it} \sum_{j=0}^{n-1} \zeta_n^{jt} a_j \\
    &= \dfrac{1}{n} \sum_{j=0}^{n-1} a_j \left( \sum_{t=0}^{n-1} \zeta_n^{(j-i)t} \right) \\
    &= \dfrac{1}{n} \sum_{j=0}^{n-1} a_j n \cdot \left[ i \equiv j \pmod{n} \right] \\
    &= a_i
\end{align*}$$

である. よって, $\mathcal{F}^{-1}$ は $\mathcal{F}$ の逆写像である. これは $W'_n$ が $W_n$ の逆写像であることを意味する.


### 畳み込み積との関係

$\boldsymbol{a}, \boldsymbol{b} \in F^n$ とする. $\boldsymbol{a}, \boldsymbol{b}$ の $\mathbb{Z}/n\mathbb{Z}$ に関する畳み込み演算を $a*b$ と定義する.

また, $\boldsymbol{a}, \boldsymbol{b} \in F^n$ における各点ごとの積を $\boldsymbol{a} \odot \boldsymbol{b}$ と書く.

ここで, フーリエ変換と畳み込み演算について, 以下の重大な式が成り立つ.

> $\mathcal{F}_n(\boldsymbol{a} * \boldsymbol{b}) = \mathcal{F}_n \boldsymbol{a} \odot \mathcal{F}_n \boldsymbol{b}$

#### 証明

$\boldsymbol{c} := \mathcal{F}_n\boldsymbol{a} \odot \mathcal{F}_n\boldsymbol{b}$ とおくことにする. このとき,

$$\begin{align*}
    c_t
    &= \left(\mathcal{F}_n\boldsymbol{a} \right)_t \left(\mathcal{F}_n\boldsymbol{b} \right)_t \\
    &= \left(\sum_{i=0}^{n-1} \zeta_n^{it} a_i \right) \left(\sum_{j=0}^{n-1} \zeta_n^{it} b_j \right) \\
    &= \sum_{i,j=0}^{n-1} \zeta_n^{(i+j)t} a_i b_j \\
    &= \sum_{k=0}^{n-1} \zeta_n^{kt} \left(\sum_{\substack{0 \leq i \lt n \\ 0 \leq j \lt n \\ i+j \equiv k \pmod{n}}} a_i b_j \right) \\
    &= \sum_{k=0}^{n-1} \zeta_n^{kt} (\boldsymbol{a} * \boldsymbol{b})_k
\end{align*}$$

である.

すると,

$$\begin{align*}
    \left[\mathcal{F}_n^{-1} \left( \left(\mathcal{F}_n\boldsymbol{a} \right) \odot \left(\mathcal{F}_n \boldsymbol{b} \right)  \right) \right]_i
    &= \mathcal{F}_n^{-1} \boldsymbol{c} \\
    &= \dfrac{1}{n} \sum_{t=0}^{n-1} \zeta_n^{-it} c_t \\
    &= \dfrac{1}{n} \sum_{t=0}^{n-1} \zeta_n^{-it} \left(\sum_{k=0}^{n-1} \zeta_n^{kt} (\boldsymbol{a} * \boldsymbol{b})_k \right) \\
    &= \dfrac{1}{n} \sum_{t=0}^{n-1} \zeta_n^{(k-i)t} d_k \\
    &= \dfrac{1}{n} \sum_{k=0}^{n-1} (\boldsymbol{a} * \boldsymbol{b})_k \left(\sum_{t=0}^{n-1} \zeta_n^{(k-i)t} \right) \\
    &= \dfrac{1}{n} \sum_{k=0}^{n-1}(\boldsymbol{a} * \boldsymbol{b})_k \left[k \equiv i \pmod{n} \right] \\
    &= d_i
\end{align*}$$

である. よって,

$$ \mathcal{F}_n^{-1} \left( \left(\mathcal{F}_n\boldsymbol{a} \right) \odot \left(\mathcal{F}_n \boldsymbol{b} \right)  \right)  = \boldsymbol{a} * \boldsymbol{b} $$

となる. $\mathcal{F}_n, \mathcal{F}^{-1}_n$ は逆写像の関係であるため,

$$ \mathcal{F}_n(\boldsymbol{a} * \boldsymbol{b}) = \mathcal{F}_n \boldsymbol{a} \odot \mathcal{F}_n \boldsymbol{b} $$

が成り立つ.

$\square$

### 畳み込みの応用

離散フーリエ変換の有用な応用例として, 多項式の積を高速にことを可能にする.

多項式 $f,g \in F[x]$ をそれぞれ $n,m$ 次の多項式とする. このとき,

$$ \boldsymbol{a} := \left([x^k] f \right)_{0 \leq k \lt n+m-1}, \quad \boldsymbol{b} := \left([x^k] g \right)_{0 \leq k \lt n+m-1}, \quad \boldsymbol{c} := \left([x^k] (fg) \right)_{0 \leq k \lt n+m-1}$$

とすると, $\boldsymbol{c} = \boldsymbol{a} * \boldsymbol{b}$ が成り立つ.



### 逆元

定数項が $0$ でない形式的ベキ級数 $f$ に対して, $fg=1$ となる形式的ベキ級数 $g$ がただ一つ存在する. この $g$ を $f$ の逆元といい, $g = f^{-1}$ とかく.

$g$ の $n$ 次までの係数を求めたい.

$g^{(n)}$ を以下を満たす多項式とする.

* $fg^{(n)} \equiv 1 \pmod{x^n}$.
* $g$ は $n$ 次未満の多項式.

なお, $g$ の一意性から, $g^{(n)} = g \mod{x^n}$ である.

まず, $n = 1$ のときは $g^{(0)}$ は定数多項式である. これは

$$ g^{(0)} = (f_0)^{-1} $$

である.

$g^{(n)}$ が求まっている時, $g^{(2n)}$ を求めたい.

$g$ と $g^{(n)}$ の関係性から, $g \equiv g^{(n)} \pmod{x^n}$ である. このとき,

$$ 0 = \left(g - g^{(n)} \right)^2 \equiv g^2 - 2 g g^{(n)} + \left(g^{(n)} \right)^2 \pmod{x^{2n}} $$

が成り立つ.

両辺に $f$ を掛けると, $fg=1$ であることに注意して, 整理すると,

$$ g \equiv 2g^{(n)} - f \left(g^{(n)} \right)^2 \pmod{x^{2n}} \quad \cdots (*) $$

となる. よって,

$$ g^{(2n)} = \left(2g^{(n)} - f \left(g^{(n)} \right)^2 \right) \mod{x^{2n}} $$

となる.

$g^{(N)}$ を求める計算量は, $T(2n) = T(n) + O(n \log n)$ を解くことにおよって, $T(N) = O(N \log N)$ 時間とわかる.

これでも求めれるが, 更に定数倍の高速化を行うことができる.

$fg^{(n)} \equiv 1 \pmod{x^n}$  であるため, ある形式的ベキ級数 $h^{(n)}$ が存在して,

$$ fg^{(n)} = 1 + x^n h^{(n)} $$

と書ける. $(*)$ に代入すると,

$$ g \equiv 2 g^{(n)} - \left(1 + x^n h^{(n)} \right) g^{(n)} = g^{(n)} - x^n g^{(n)} h^{(n)} \pmod{x^{2n}}$$

となる.

この式から, $g$ の $2n$ 未満の係数について, 以下が従う.

* $g$ の $n$ 次未満の係数は $g^{(n)}$ と一致する.
* $g$ の $n$ 次から $2n$ 次未満の係数は $-g^{(n)} h^{(n)}$ の $n$ 次未満の係数と一致する.
