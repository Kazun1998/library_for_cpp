---
title: 冪乗の列挙
documentation_of: //Math/Enumerate_Powers.hpp
---

## Outline

$0^k, 1^k, \dots, n^k$ を求める.

## Theory

これ以降の説明では, $k \geq 0$ とする.

$0 \leq x \leq n$ であるそれぞれの $x$ に対して $x^k$ を繰り返し二乗法を使って求める場合, 合計で $O(n \log k)$ 時間で求められる.

このメソッドでは, 更に高速に求めることができる.

$0^k, 1^k$ はそれぞれ

$$ 0^k = \begin{cases} 0 & (k \neq 0) \\ \ 1 & (k = 0) \end{cases}, \quad 1^k = 1$$

で求められる.

$2$ 以上の整数 $x$ に対して, $x$ の昇順に $x^k$ をそれぞれ次のようにして求める.

* $x$ が素数のとき: 繰り返し二乗法で直接 $x^k$ を求める.
* $x$ が合成数のとき: $x$ の $2$ 以上 $x$ 未満の正の約数 $d$ が存在する. このとき, $x^k = d^k \cdot (x/d)^k$ が成り立つ. $d, x/d < x$ であり, $x$ の昇順に求めているため, $d^k, (x/d)^k$ は計算済みである. そのため, $x^k$ を乗算 $1$ 回で求められる.

以上から, 以下のようなアルゴリズムで更に高速に求めることができる.

* $x$ 以下の正の整数に対して, 篩を使って $x$ の最小素因数 $s_x$ を求める.
* $x = 2, 3, \dots$ の順に以下を計算する.
  * $x$ が素数である. つまり, $s_x = x$ であるとき, $x^k$ を繰り返し二乗法で直接求める.
  * $x$ が合成数である. つまり, $s_x < x$ であるとき, $x^k = s_x^k \cdot (x/s_x)^k$ で求める.

計算量は, 篩のアルゴリズムによって異なるが $\pi(n)$ を $n$ 以下の素数の個数として,

* Eratosthenes の篩: $O(n \log log n + \pi(n) \log k)$ 時間.
* 線形篩: $O(n + \pi(n) \log k)$ 時間.

になる. ただし, 定数倍は Eratosthenes の篩の方が軽い.

## Contents

```cpp
template<typename F>
vector<F> Enumerate_Powers(const int n, const ll k)
```

* $0^k, 1^k, ..., n^k$ を求める.
* **返り値**
  * 長さ $(n+1)$ の配列. 第 $i$ 要素は $i^k$ を表す.
* **計算量**: Eratosthenes の篩を採用しているため, $O(n \log \log n + \pi(n) \log k)$ 時間.

## History 

|日付|内容|
|:---:|:---:|
|2026/04/16| Enumerate_Powers 実装 |
