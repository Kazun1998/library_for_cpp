---
title: Clique に関する計算
documentation_of: //Graph/Graph/Cliques.hpp
---

## Outline

無向グラフ $G$ の Clique に関する計算を行う.

$X$ を $\mathrm{unit}$ を単位元とするモノイドとする.

無向グラフ $G = (V, E)$ における頂点の部分集合に定義される関数 $\mathrm{calc}: \mathcal{P}(V) \to X$ が与えられている.

このとき, $G$ における Clique の集合を $\mathcal{C}$ としたとき,

$$ \prod_{C \in \mathcal{C}} \mathrm{calc}(C) $$

を求める.

## Definition

無向グラフ $G = (V, E)$ における頂点の部分集合 $C \subset V$ が Clique であるとは, 任意の $u, v \in V$ に対して, $uv \in E$ となることである. つまり, 誘導グラフ $G[C]$ が完全グラフになることと同値である.

## Theory

単純グラフ $G$ の位数とサイズを $N, M$ とする. このとき, 以下が成り立つ.

* (a) Clique の大きさ (頂点数) は $\sqrt{2M}$ 以下である.
* (b) 次数が $\sqrt{2M}$ 以上の頂点は $\sqrt{2M}$ 個以下である.

以下の手順をできるだけ繰り返す.

* $G$ から次数が $\sqrt{2M}$ 以下の頂点 $u$ を $1$ 個見つける.
  * もし, 見つからなかったら繰り返しを終了する.
* $u$ と隣接している頂点を $v_1, \dots, v_k$ とする.
* $\{v_1, \dots, v_k\}$ の部分集合 $A$ 全てに対して, 以下を行う.
  * $\{v_1, \dots, v_k\}$ の部分集合 $A$ に対して,
    * $A$ は Clique になる.
    * $A \cup \{ v \}$ は Clique になる.
  * $\{v_1, \dots, v_k\}$ の部分集合で Clique になる $A$ に対して, $\mathrm{calc}(A \cup \{v\})$ を計算して, 結果に加算する.
* これにより, $v$ を含む Clique の列挙が完了した. そのため, $G$ から頂点 $v$ と $v$ に接続する辺を除く.

この繰り返しが終了した時点で, 残っている頂点の数は $\sqrt{2M}$ 個以下である. そのため, 残りの頂点達に対して, 全列挙で可能性を試すことよって, Clique の列挙を行うことができる.

計算量はそれぞれの全列挙パートに対して, 対象となる頂点数が $\sqrt{2M}$ 個以下
である. この全列挙パートが高々 $(N+1)$ 回起こる.

そのため, 合計で $O \left(2^{\sqrt{2M}} N \right)$ 時間になる.


## Contents


```cpp
template<typename X>
X Cliques(const Graph &G, const function<X(const vector<int>)> &calc, const function<X(X, X)> &merge, const X unit, bool empty = false)
```

* 無向グラフ $G = (V, E)$ における頂点の部分集合に定義される関数 $\mathrm{calc}: \mathcal{P}(V) \to X$ がある. Clique の集合を $\mathcal{C}$ としたとき, $\displaystyle \prod_{C \in \mathcal{C}} \mathrm{calc}(C) $ を求める.
* **引数**
  * $G$ : 無向グラフ
  * $\mathrm{calc}: \mathrm{calc}: \mathcal{P}(V) \to X$ : 頂点の部分集合に定義される関数 .
  * $\mathrm{merge} : X \times X \to X$ : 結果を統合する方法.
  * $\mathrm{unit}$ : $X$ の単位元.
  * $\mathrm{empty}$ : `true` にすると, Clique の定義に $C = \emptyset$ を含む.
* **計算量** : $G$ の位数とサイズを $N, M$ とすると, $O \left(2^{\sqrt{2M}} N \right)$ 時間.

## History

|日付|内容|
|:---:|:---:|
|2025/12/06|Clieques メソッド実装|
