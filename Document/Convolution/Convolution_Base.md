---
title: 畳み込み
documentation_of: //Convolution/Convolution_Base.hpp
---

## Outline

$R$ を環, $(I, \circ)$ を (有限) モノイドとする. このとき, $\operatorname{Map}(I, R)$ は各点毎の和とスカラー倍によって, 加群を成す.

ここで, $f, g \in \operatorname{Map}(I, R)$ に対して, $f, g$ の畳み込み $f*g$ を

$$ (f * g)(k) := \sum_{\substack{i, j \in I \\ i \circ j = k }} f(i) g(j) $$

で定めると, $\operatorname{Map}(I, R)$ はこの畳み込みを積として環になる.

一般的に, $I$ が $n$ 要素であるとき, $f, g$ の畳み込み $(f * g)$ の計算には愚直だと時間計算量で $\Theta(n^2)$ 時間かかる. しかし, 特別な $I$ の場合には, この時間計算量を $o(n^2)$ 時間に落とすことができる.

このディレクトリには, 色々な $I$ における畳み込みが実装されているが, このクラスでは基底クラスとして基本的な演算が実装されている.

## Theory

$I$ の特徴によって, 実装などの方針が変わる.

### $I$ が冪等可換モノイドのとき

モノイド $I$ について, 任意の $x \in X$ に対して, $x \circ x = x$ を満たすとき, $I$ は冪等であるという;.

$I$ が冪等可換であるとき, ゼータ変換, メビウス変換を考えることにより, 計算量が $O(n)$ や $O(n \log \log n)$ 時間になる.

$I := \mathbb{N}$ や $I := \mathbb{N}_1$ としたときに, 可換冪等モノイドになる演算の例は以下である.

* $\max$: [Max_Convolution](Max_Convolution.hpp)
* $\min$: [Min_Convolution](Min_Convolution.hpp)
* $\gcd$: [Gcd_Convolution](Gcd_Convolution.hpp)
* $\operatorname{lcm}$: [Lcm_Convolution](Lcm_Convolution.hpp)
* $\cap, \land$: [Bitwise_And_Convolution](Bitwise_And_Convolution.hpp)
* $\cup, \lor$: [Bitwise_Or_Convolution](Bitwise_Or_Convolution.hpp)
