---
title: Longest Common Substring (最長共通部分文字列)
documentation_of: //String/Longest_Common_Substring.hpp
---

## Outline

列 $A, B$ における最長共通連続部分列を求める.

## Definition

列 $A, B$ に対して, $\operatorname{LCS}(A, B)$ を $A, B$ における最長共通部分文字列の長さと定義する.

## Theory

以下のように記号を定義する.

* 列 $A$ の長さを $N$, 列 $B$ の長さを $M$ とする.
* $A, B$ に含まれない要素を $\$$ として, $C := A \oplus \$ \oplus B$ とする.
* 接尾辞について, 以下のようにする.
  * $A$ における第 $i$ 接尾辞を $X_i$ とする.
  * $B$ における第 $j$ 接尾辞を $Y_j$ とする.
  * $C$ における第 $k$ 接尾辞を $Z_k$ とする.
* $C$ における接尾辞配列を $(C_1, \dots, C_{N+M+1})$ とする.
* $Z_{S_k}$ と $Z_{S_{k+1}}$ の最長共通接頭辞の長さを $L_k$ とする.

$1 \leq i \leq N, 1 \leq j \leq M$ に対して, $\operatorname{LCS}(X_i, Y_j)$ を求める.

$p, q$ を次のように定める.

$$ p \lt q, \quad \{ S_p, S_q \} = \{ i, j + N + 1 \}$$

このとき,

$$ \operatorname{LCS}(X_i, Y_j) = \operatorname{LCS}(Z_{S_p}, Z_{S_q}) = \min(L_p, \dots, L_{q-1}) $$

である.

ここで, $S_p, \dots, S_q$ の間には, 「$N$ 以下」と 「$(N+1)$ より大きい」が少なくとも $1$ つは含まれている. 特に, $p \leq k < q$ で $Z_{S_k}, Z_{S_{k+1}}$ のうち, 一方が $A$ 由来, 他方が $B$ 由来となるものがある. このとき,

$$ \operatorname{LCS}(X_i, Y_j) \leq L_k $$

である.

以上から, 以下を満たすもの $k$ についての総和を考えれば良いことになる.

* $Z_{S_k}, Z_{S_{k+1}}$ のうち, 一方が $A$ 由来, 他方が $B$ 由来となる $k$ における $L_k$.

計算量は最長共通接頭辞の計算量になるため, $O(N \log N)$ 時間である.

## Contents

### Longest_Common_Continuous_Subsequence
```cpp
template<totally_ordered T>
tuple<int, int, int, int> Longest_Common_Continuous_Subsequence(const vector<T> &A, const vector<T> &B)
```

* 全順序 $T$ 上の列 $A, B$ に対する最長共通連続部分列となる部分を求める.
* **返り値**
  * $(a, b, c, d)$ の形のタプル.
  * 以下を意味する.
    * $(A_a, \dots, A_b) = (B_c, \dots, B_d)$.
    * $(A_a, \dots, A_b)$ が最長共通部分列である.
* **計算量**: $N := \lvert A \rvert, M := \lvert B \rvert$ として, $O((N + M) \log (N + M))$ 時間.

### Longest_Common_Substring

```cpp
tuple<int, int, int, int> Longest_Common_Substring(const string &S, const string &T)
```

* 文字列 $S, T$ に対する最長共通部分文字列となる部分を求める.
* **返り値**
  * $(a, b, c, d)$ の形のタプル.
  * 以下を意味する.
    * $(S_a, \dots, S_b) = (T_c, \dots, T_d)$.
    * $(S_a, \dots, S_b)$ が最長共通部分文字列である.
* **計算量**: $N := \lvert S \rvert, M := \lvert T \rvert$ として, $O((N + M) \log (N + M))$ 時間.


## History

|日付|内容|
|:---:|:---|
|2026/04/05| Longest_Common_Continuous_Subsequence, Longest_Common_Substring 実装 |
