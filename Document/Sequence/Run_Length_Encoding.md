---
title: 連長圧縮 (Run Length Encoding)
documentation_of: //Sequence/Run_Length_Encoding.hpp
---

## Outline

アルファベット $\mathcal{A}$ 上の列 $S$ に関する連長圧縮を行う.

## Define

アルファベット $\mathcal{A}$ 上の列 $S$ に対して, 以下を満たす列 $\mathcal{A} \times \mathbb{Z}_{>0}$ 上の列 $R = ((\alpha_1, k_1), \dots, (\alpha_m, k_m))$ がただ一つ存在することが示せる.

* $j = 1, 2, \dots, m - 1$ に対して, $\alpha_j \neq \alpha_{j+1}$ である.
* $S = (\underbrace{\alpha_1, \dots, \alpha_1}\_{k_1}, \dots, \underbrace{\alpha_m, \dots, \alpha_m}\_{k_m})$.

この $R$ を $S$ の連長圧縮という.

## Contents

```cpp
template<typename S>
vector<pair<S, size_t>> Run_Length_Encoding(const vector<S> &x)
```

* $S$ 上の列 $x$ に対して, 連長圧縮を求める.
* **返り値**: $x$ の連長圧縮 $((\alpha_j, k_j))_j$
* **計算量**: $O(\lvert x \rvert)$ 時間.

```cpp
std::vector<std::pair<char, size_t>> Run_Length_Encoding(const std::string &S)
```

* 文字列 $S$ の連長圧縮を求める.
* **返り値**: $S$ の連長圧縮 $((\alpha_j, k_j))_j$
* **計算量**: $O(\lvert S \rvert)$ 時間.