---
title: Interval Query
documentation_of: //Interval_Query/Interval_Query.hpp
---

## Outline

[Range_Decomposer](Range_Decomposer.hpp) による区間分解を用いて, 要素の列 $A = (A_0, A_1, \dots, A_{N-1})$ ( $A_i \in T$ ) に対する一点更新・区間クエリを行う汎用クラス.

`Range_Decomposer` の各ノードは, `State` 型の内部状態を1つ持つ. 状態は以下の2つの関数から構築される.

* `build_state`: 葉ノード (担当する要素が1個) の状態を, その要素から作る.
* `merge_children`: 内部ノードの状態を, その子ノードの状態のリストから作る.

セグメント木のように「全ノードで単一のモノイド $M$ に統一する」のではなく, ノードごとに任意の型 `State` (例えば `map` のような, モノイド積に落とし込みづらい構造) を持てる点が特徴である. その代わり, クエリの結果 `R` の取り出し方 (`representative`) と集約方法 (`merge`) は, `query` の呼び出しごとに指定する.

## Contents

以下, $N$ を要素数とする. 最大の深さ $D$, および `update`/`query` で参照するノード数 $\alpha$ のオーダーは, 用いる `Range_Decomposer` によって次のように変わる.

| | [平方分割](Sqrt_Decomposer.hpp) | [二分木分割](Binary_Decomposer.hpp) |
|---|---|---|
| 最大の深さ $D$ | $1$ | $O(\log N)$ |
| `update` の $\alpha$ (`ancestors(i)`) | $O(1)$ | $O(\log N)$ |
| `query` の $\alpha$ (`decompose(l, r)`) | $O(\sqrt{N})$ | $O(\log N)$ |

### Constructer

```cpp
Interval_Query(
    const vector<T> &data,
    unique_ptr<Range_Decomposer> decomposer,
    function<State(const vector<T> &)> build_state,
    function<State(vector<State> &)> merge_children,
    function<void(State &, int, const T &, const T &)> on_update
)
```

- 初期値 `data` ( 列 $A$ ), 区間分解器 `decomposer`, および以下の関数から構築する.
  - `build_state(sub)`: 葉ノードが担当する要素列 `sub` ( 要素数 $1$ ) から, そのノードの状態を作る.
  - `merge_children(children)`: 内部ノードの子ノードたちの状態 `children` から, そのノードの状態を作る.
  - `on_update(state, i, before, after)`: 要素 $i$ が `before` から `after` に変化したときに, あるノードの状態 `state` をどう書き換えるかを指定する ( `update` から, $i$ を含む全ノードに対して呼ばれる ).
- **計算量** : `decomposer` の最大の深さを $D$, `build_state` / `merge_children` が要素 $1$ 個分を処理するのにかかる計算量を $O(M)$ として, $O(D N M)$ Time. (各深さ $d$ について, 高々 $N$ 要素分の処理が発生しうるため.)

### size

```cpp
int size() const
```

- 要素数 $N$ を返す.
- **計算量** : $O(1)$ Time.

### get

```cpp
const T &get(int i) const
```

- 第 $i$ 要素 $A_i$ を取得する.
- **制約**
  - $0 \leq i \lt N$.
- **計算量** : $O(1)$ Time.

### update

```cpp
void update(int i, const T &x)
```

- 第 $i$ 要素を $x$ に更新する ( $A_i \leftarrow x$ ).
- 内部では, `decomposer->ancestors(i)` で列挙される, $i$ を含む全てのノードに対して, `on_update(state, i, A_i, x)` を呼び出す.
- **制約**
  - $0 \leq i \lt N$.
- **計算量** : 参照するノードの数を $\alpha$ (`decomposer->ancestors(i)` の要素数), `on_update` 1回あたりの計算量を $O(M)$ として, $O(\alpha M)$ Time.

### query

```cpp
template <typename R>
R query(
    int l, int r,
    function<R(const State &)> representative,
    function<R(R, R)> merge,
    R identity
) const
```

- 半開区間 $[l, r)$ に対するクエリの結果を求める.
- 内部では, `decomposer->decompose(l, r)` で得られる各ノードについて `representative(state)` を呼び, その結果を `merge` で `identity` を単位元として集約する.
- 引数
  - `representative`: ノードの状態 `State` から, クエリの結果 `R` を取り出す関数.
  - `merge`: 複数のノードの結果 `R` を集約する関数. `decompose(l, r)` が返す順序で左畳み込みされるため, 厳密には結合的である必要はなく, `merge(identity, x) = x` ( 左単位元であること ) だけを満たせばよい ( 通常は結合的な演算を想定する ).
  - `identity`: `merge` に対する単位元.
- **制約**
  - $0 \leq l \leq r \leq N$.
- **計算量** : 参照するノードの数を $\alpha$ (`decomposer->decompose(l, r)` の要素数), `representative` と `merge` 1回あたりの計算量の和を $O(M)$ として, $O(\alpha M)$ Time.
