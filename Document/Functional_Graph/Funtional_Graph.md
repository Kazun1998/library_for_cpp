---
title: Functional Graph
documentation_of: //Functional_Graph/Functional_Graph.hpp
---

## Outline

Funtional Graph に関する構造の決定及び, 計算を高速に行う.


## Definition

有向グラフ $D = (V, A)$ において, 任意の頂点 $v \in V$ における出次数が $1$ であるとき, この $D$ は Functional Graph であるという.

## Theory

### 写像との対応
$V$ を有限集合とする. このとき, 以下は一対一対応する.

* $V$ を頂点集合とする Functional Graph $D = (V, A)$ .
* 写像 $f: V \to V$.

これらは, それぞれ以下のように対する.

#### Functional Graph から写像

Functional Graph $D = (V, A)$ において, 各頂点 $v \in V$ における唯一ので近傍を $f(v) \in V$ として得られる写像 $f: V \to V$ が対応する.

#### 写像から Functional Graph

写像 $f: V \to V$ に対して, $A$ を

$$A := \left\{ \overrightarrow{v f(v)} ~\middle|~ v \in V \right\}$$

としたときに得られる Functional Graph $D = (V, A)$ が対応する.

### 構造の決定
$D$ におけるそれぞれの弱連結成分 $\Gamma_i$ は次のようにして構成される.

* $\Gamma_i$ にはただ一つのサイクル $v_{i,1}, v_{i,2}, \dots, v_{i,m_i}$ を持つ.
* 各 $v_{i,j}$ について, $v_{i,j}$ を根とする有向根付き木を成す. 有向辺の向きは, 根へ向かう向き.

## Contents

### Constructer

```cpp
Functional_Graph(const vector<int> &f)
```
