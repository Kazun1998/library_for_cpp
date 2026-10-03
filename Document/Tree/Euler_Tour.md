---
title: オイラーツアー (Euler Tour)
documentation_of: //Tree/Euler_Tour.hpp
---

## Outline

根付き木 $T = (V, E)$ に対してオイラーツアーを行い, 頂点・辺をオイラーツアー順に並べた列を計算する. これにより, 部分木に関するクエリを, 列上の区間クエリに帰着させることができる.

## Definition

根 $r$ を持つ根付き木 $T = (V, E)$ を考える. $T$ の各辺 $\{u, v\} \in E$ ($u$ は $v$ の親とする) を, 向きの異なる $2$ 本の有向辺 $u \to v$ (下り) と $v \to u$ (上り) に置き換えてできる有向グラフを $\vec{T}$ とする.

$\vec{T}$ において, 根 $r$ から出発し, 各頂点で子への辺を (未使用のものがあれば) 優先して選びながら, 全ての有向辺をちょうど $1$ 度ずつ通って $r$ に戻ってくる閉路 (Euler circuit) が一意に存在する. この巡回で頂点を訪れた順に並べた列

$$ r = v_0, v_1, v_2, \dots, v_{2(N - 1)} = r $$

を, 木 $T$ の頂点に関するオイラーツアーという (ただし $N = \lvert V \rvert$). 同様に, この巡回で通る有向辺を順に並べた列

$$ (v_0, v_1), (v_1, v_2), \dots, (v_{2(N-1) - 1}, v_{2(N-1)}) $$

を, 木 $T$ の辺に関するオイラーツアーという.

頂点 $v$ について, 列 $v_0, \dots, v_{2(N-1)}$ の中で $v$ が最初に現れる添字を $I_v$, 最後に現れる添字を $O_v$ とすると, 頂点 $v$ を根とする部分木の頂点全体は, ちょうど区間 $[I_v, O_v]$ に含まれる添字に対応する頂点の集合と一致する.

## Theory

### 部分木クエリ

頂点 $r$ を根としてオイラーツアーを行うと, 各頂点 $v$ を初めて訪れた時刻 $I_v$ と, $v$ を最後に離れる時刻 $O_v$ が定まる. このとき, 頂点 $v$ を根とする部分木は, オイラーツアー順に並べた頂点列上の区間 $[I_v, O_v]$ に一致する.

同様に, 各辺についても, オイラーツアーがその辺を通った際の向き (親から子へ下るか, 子から親へ戻るか) を記録することで, 部分木に関する辺の集計を列上の区間クエリに帰着できる.

### パスクエリ
$G$ を群とする. 各頂点 $v$ に対して, 根 $r$ から $v$ までのパスに沿って, 辺への重み付け $w: E \to G$ を根から $v$ に向かう順に $\odot$ で合成した値 $s_v \in G$ が計算できているとする (逆向き, すなわち子から親へ辿る場合は $w(e)^{-1}$ を用いる). このとき, $u$ から $v$ に向かうパスに沿って辺の重みを合成した値は, $l$ を $u, v$ の LCA (最近共通祖先) として,

$$ s_u^{-1} \odot s_l \odot s_l^{-1} \odot s_v \ (= s_u^{-1} \odot s_v) $$

により求まる. これは, 根からのパスを $r \to \dots \to l \to \dots \to u$ と $r \to \dots \to l \to \dots \to v$ に分解したとき, 共通部分である $r \to \dots \to l$ の寄与が $s_l \odot s_l^{-1}$ として打ち消し合うことによる.

このような $s_v$ 自体も, 辺の向き (`Euler_Tour_Edge_Direction`) を用いてオイラーツアー上の区間演算 (下りの辺は $+w(e)$, 上りの辺は $-w(e)$ として累積) に帰着させることができるため, 部分木クエリと同様にオイラーツアーの枠組みで扱うことができる.

## Examples

[[Library Checker] Vertex Add Subtree Sum](https://judge.yosupo.jp/problem/vertex_add_subtree_sum)

各頂点 $v$ に値 $a_v$ を割り当て, 「1 点更新」「部分木の総和取得」を処理する. 頂点 $v$ を根とする部分木が区間 $[I_v, O_v]$ に対応することを利用して, Segment Tree 上のクエリに帰着させる.

## Contents

### Constructor

```cpp
Euler_Tour(const Tree &T)
```

* `Tree` オブジェクトからオイラーツアーの準備を行う.
* **引数**
  * `T`: 対象となる `Tree` オブジェクト. 事前に `seal()` (`is_locked() == true`) している必要がある.

### calculate_euler_tour_vertex

```cpp
void calculate_euler_tour_vertex()
```

* 頂点に関するオイラーツアーを計算する. 計算済みの場合は何もしない.
* 計算結果は以下のメンバに格納される.
  * `vector<int> euler_tour_vertex`: オイラーツアー順に頂点を並べた列 (長さ $2N - 1$).
  * `vector<int> in_time`: 各頂点が `euler_tour_vertex` 上で最初に現れる時刻.
  * `vector<int> out_time`: 各頂点が `euler_tour_vertex` 上で最後に現れる時刻.
* **計算量**: $T$ の位数を $N$ として, $O(N)$ 時間.

### calculate_euler_tour_edge

```cpp
void calculate_euler_tour_edge()
```

* 辺に関するオイラーツアーを計算する (内部で `calculate_euler_tour_vertex()` を呼ぶ). 計算済みの場合は何もしない.
* 計算結果は以下のメンバに格納される.
  * `vector<tuple<int, int, Euler_Tour_Edge_Direction>> euler_tour_edge`: `(x, y, d)` の形で, オイラーツアーが辺 $(x, y)$ を通ったことを表す.
    * `d = Euler_Tour_Edge_Direction::Forward`: 親 $x$ から子 $y$ へ下る辺.
    * `d = Euler_Tour_Edge_Direction::Backward`: 子 $x$ から親 $y$ へ戻る辺.
* **計算量**: $O(N)$ 時間.

### subtree_range

```cpp
pair<int, int> subtree_range(const int &x)
```

* 頂点 $x$ を根とする部分木が, `euler_tour_vertex` 上で対応する閉区間を求める.
* **引数**
  * $x$: 頂点.
* **返り値**: 閉区間 $[I_x, O_x]$.
* **計算量**: 償却 $O(1)$ 時間 (未計算の場合ははじめに $O(N)$ 時間で計算する).

### edge_range

```cpp
pair<int, int> edge_range(const int &x)
```

* 頂点 $x$ を根とする部分木に含まれる辺が, `euler_tour_edge` 上で対応する半開区間を求める.
* **引数**
  * $x$: 頂点.
* **返り値**: 半開区間 $[I_x, O_x)$.
* **計算量**: 償却 $O(1)$ 時間 (未計算の場合ははじめに $O(N)$ 時間で計算する).

### is_ancestor

```cpp
bool is_ancestor(const int &x, const int &y)
```

* 頂点 $x$ が頂点 $y$ の祖先 (自分自身を含む) であるかどうかを判定する.
* **引数**
  * $x, y$: 頂点.
* **返り値**: $x$ が $y$ の祖先であれば `true`, そうでなければ `false`.
* **計算量**: 償却 $O(1)$ 時間 (未計算の場合ははじめに $O(N)$ 時間で計算する).

## History

|日付|内容|
|:---:|:---|
|2026/09/26| `Tree.hpp` からオイラーツアー関連機能を分離し, 独立したクラスとして実装 |
