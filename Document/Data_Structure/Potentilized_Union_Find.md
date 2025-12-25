---
title: ポテンシャル付き Union Find
documentation_of: //Union_Find/Potentilized_Union_Find.hpp
---

## Outline

Union Find にポテンシャルの概念を付け加え, $2$ 頂点間のポテンシャルの差を取得する.

## Define

$G$ を群とする.

各弧に $G$ の重みが付いた有向グラフ $D = (V, A, W: V \to G)$ において, 以下をみたす時, この $D$ は対称的であるという.

* 任意の $a \in A$ に対して, 以下をみたす逆弧 $\operatorname{rev}: A \to A$ が定まっている.
  * $\operatorname{rev}(a)$ は $a$ の逆向きである. つまり, 以下を満たす.
    * $s(a) = t(\operatorname{rev}(a))$.
    * $t(a) = s(\operatorname{rev}(a))$.
  * $\operatorname{rev}$ は対合である. つまり, 任意の $a \in A$ に対して, $\operatorname{rev}(\operatorname{rev}(a)) = a$ となる.
* 任意の $a \in A$ に対して, $W(\operatorname{rev}(a)) = W(a)^{-1}$ である.

---

各弧に $G$ の重みが付いた有向グラフ $D = (V, A, W: V \to G)$ 上のパス $p = (v_0, v_1, v_2, \dots, v_m)$ に対して, $p$ のポテンシャルエネルギー $E(p)$ を

$$ E(p) := \sum_{j=1}^m W\left(\overrightarrow{v_{j-1} v_j} \right)$$

で定義する.

---

対称的な各弧に $G$ の重みが付いた有向グラフ $D = (V, A, W: V \to G)$ について, 以下の条件をみたす時, $D$ はポテンシャルを持つという.

* 任意の $u, v\in V$ に対して, $u$ を始点, $v$ を終点とするパスにおけるポテンシャルエネルギーはパスに依らない.
* つまり, $p, q$ を $u$ を始点, $v$ を終点とするパスとしたとき, $E(p) = E(q)$ が成り立つ.

---

$D$ はポテンシャルを持つとする.

$$ R := \{(u, v) \in V^2 \mid v \text{ is reachable from } u \text{ on } D. \}$$

とする. このとき, $D$ におけるポテンシャル $P: R \to G$ を $u$ を始点, $v$ を終点とするパスを $p$ としたとき, $P(u, v) := E(p)$ とする. $D$ がポテンシャルを持つことから, Well-Defined 性が従う.

## Theory

対称的な各弧に $G$ の重みが付いた有向グラフ $D = (V, A, W: V \to G)$ について, 以下は同値になる.

* (a) $D$ はポテンシャルを持つ.
* (b) 任意の $D$ 上のサイクルに対するポテンシャルエネルギーは単位元である.

## Remark

このライブラリで対応しているのは $P(x) = a P(y)$ の形である, 左作用である. もし, 右作用「のみ」を要求されている場合は, 次のようにして対応させることができる.

* $P(x) = P(y) a$ を変形させると, $P(x)^{-1} = a^{-1} P(y)^{-1}$ となる. $P$ がポテンシャルであるとき, $P(\bullet)^{-1}$ もポテンシャルになる. よって, $P(\bullet)^{-1}$ の問題に帰着させることができる. なお, 関係式を定義する際に, 全て逆元を取ることを忘れないこと.

## Contents

### Constructor

```cpp
template<typename Pot>
Potentilized_Union_Find(int n, function<Pot(const Pot&, const Pot&)> add, const Pot &zero, const function<Pot(const Pot &)> neg)
```

* $n$ 頂点からなる, 各弧に重みづけられる群 $G$ が以下のようにして表される対称的な有向グラフの場を生成する.
  * $G$ の集合は `Pot`, 演算は `add`, 単位元は `unit`, 逆元関数は `neg`

### find

```cpp
int find(int x)
```

* 頂点 $x$ が属する連結成分の代表元を求める.
* **計算量** : ならし $O(\alpha(N))$ 時間.

### same

```cpp
bool same(int x, int y)
```

* 頂点 $x, y$ は連結かどうかを求める.
* **計算量** : ならし $O(\alpha(N))$ 時間.

### size

```cpp
int size(int x)
```

* 頂点 $x$ が属する連結成分の頂点数を求める.
* **計算量** : ならし $O(\alpha(N))$ 時間.

### unite

```cpp
bool unite(int x, int y, Pot a)
```

* Potential について,$P(x) = a P(y)$ という関係性を加え, 矛盾性を返す.
* **返り値** : $P(x), P(y)$ の間について, 矛盾がなければ `true`, 矛盾があれば (元々矛盾していた場合も含む) `false`.
* **計算量** : ならし $O(\alpha(N))$ 時間.

### potential

```cpp
Pot potential(int x)
```

* $r$ を $x$ が属する連結成分の代表元 (つまり, $\textrm{find}(x)$) とする.  このとき, $r$ を基準とする $x$ のポテンシャル $P(r)^{-1}P(x)$ を求める.
* **計算量** : ならし $O(\alpha(N))$ 時間.

```cpp
Pot potential(int x, int y)
```

* $y$ を基準とする $x$ のポテンシャル $P(x)P(y)^{-1}$ を求める.
* **計算量** : ならし $O(\alpha(N))$ 時間.

### is_valid

```cpp
bool is_valid(int x)
```

* $x$ を含む連結成分におけるポテンシャルが整合性を持つかどうかを判定する.
* **計算量** : $O(1)$ 時間.

### is_well_defined

```cpp
bool is_well_defined(int x, int y)
```

* $y$ を基準とする $x$ のポテンシャルが「矛盾なく」「一意的」に定義できるかどうかを判定する.
* **計算量** : ならし $O(\alpha(N))$ 時間.

### is_possible

```cpp
bool is_possible(int x, int y, Pot a)
```

* $y$ を基準とする $x$ のポテンシャルについて, $P(x)P(y)^{-1}=a$ となる可能性はあるか?
* **計算量** : ならし $O(\alpha(N))$ 時間.

### group_count

```cpp
int group_count()
```

* 有向グラフにおける連結成分の数を求める.
* **計算量** : $O(1)$ 時間

## History 

|日付|内容|
|:---:|:---:|
|2025/11/24| ポテンシャルの群が非可換群である場合にも対応|
|2025/11/23| ポテンシャル付き Union Find を実装|
