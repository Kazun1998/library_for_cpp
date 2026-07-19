---
title: Treap
documentation_of: //Data_Structure/Treap.hpp
---

## Outline
平衡二分探索木の $1$ つである Treap (Tree + Heap) を用いた順序付き集合.

各ノードにランダムな優先度 (priority) を割り当て, キーに関しては二分探索木, 優先度に関してはヒープの性質を同時に満たすことで, 期待 $O(\log N)$ の高さを保つ. `split` / `merge` による分割統合型の実装を採用している.

通常の `std::set` の機能に加え, 「小さい方から $k$ 番目の要素の取得」や「ある値未満の要素数」といった順位に関する操作を期待 $O(\log N)$ で行うことができる.

## Theory

### 定義

Treap とは, 各ノードが **キー (key)** と **優先度 (priority)** の2つの値を持つ二分木であり, 以下の2つの性質を同時に満たすものである.

1. **二分探索木性質 (BST property)**: キーについて, 通常の二分探索木の順序関係を満たす. すなわち, 任意のノード $v$ に対して, $v$ の左部分木のすべてのキーは $v$ のキーより小さく, 右部分木のすべてのキーは $v$ のキーより大きい.
2. **ヒープ性質 (Heap property)**: 優先度について, (最大) ヒープの順序関係を満たす. すなわち, 任意のノード $v$ に対して, $v$ の優先度はその子ノードの優先度以上である.

キーが相異なり, 優先度も相異なるとき, これら2つの性質を同時に満たす木の形状は**一意**に定まる. これは, 最も優先度の高いノードが根となり, そのキーを基準にキーが小さいものが左部分木, 大きいものが右部分木を再帰的に構成することから従う.

### ランダム化と期待計算量

Treap では, 各ノードの優先度を**一様ランダム**に生成する. このとき, Treap の構造は「キーをランダムな順序で挿入して構築した二分探索木」と分布が等しくなることが知られている. ランダムな順序で $N$ 個の要素を挿入して構築した二分探索木の期待高さは $O(\log N)$ であるため, Treap の期待高さも $O(\log N)$ となる.

より正確には, ノード $x$ の深さの期待値は $O(\log N)$ であり, 任意の探索・挿入・削除操作の期待計算量は $O(\log N)$ となる.

### split 操作

$\mathrm{split}(T, k)$ は, 木 $T$ をキー $k$ を基準にして, キーが $k$ 未満のノードからなる木 $L$ とキーが $k$ 以上のノードからなる木 $R$ に分割する操作である.

根のキーと $k$ の大小を比較して再帰的に分割を行う.

* 根のキーが $k$ 未満のとき: 根と左部分木はすべて $L$ に属する. 右部分木を再帰的に分割し, 得られた「$k$ 未満の部分」を根の右の子として接続したものが $L$, 残りが $R$ となる.
* 根のキーが $k$ 以上のとき: 根と右部分木はすべて $R$ に属する. 左部分木を再帰的に分割し, 得られた「$k$ 以上の部分」を根の左の子として接続したものが $R$, 残りが $L$ となる.

再帰の深さは木の高さに等しいため, **期待計算量は $O(\log N)$** である.

### merge 操作

$\mathrm{merge}(L, R)$ は, $L$ のすべてのキーが $R$ のすべてのキーより小さいという前提のもとで, 2つの木 $L, R$ を1つの Treap に統合する操作である.

両方の根の優先度を比較し, 優先度が高い方を統合後の根とする.

* $L$ の根の優先度が高いとき: $L$ の根が統合後の根となる. $L$ の右部分木と $R$ を再帰的にマージし, その結果を $L$ の根の右の子とする.
* $R$ の根の優先度が高いとき: $R$ の根が統合後の根となる. $L$ と $R$ の左部分木を再帰的にマージし, その結果を $R$ の根の左の子とする.

この操作は, 統合後の木がヒープ性質を維持することを保証する. **期待計算量は $O(\log N)$** である.

### insert / erase の実現

split と merge を組み合わせることで, 挿入と削除を簡潔に実現できる.

* **insert($x$)**: 木を $x$ を基準に split し, 新たなノード $x$ を単独の木として, $L$, $\\{x\\}$, $R$ の順に merge する.
* **erase($x$)**: 木を $x$ と $x+1$ でそれぞれ split して $x$ のみを含む部分木 $M$ を切り出し, $M$ を破棄した後, 残りの $L$ と $R$ を merge する.

## Contents

### Constructer

```cpp
template<class T>
Treap()

template<class T>
Treap(std::initializer_list<T> init_list)

template<class T>
Treap(Iterator first, Iterator last)

template<class T>
Treap(const Container& container)
```

* 順序付き集合を生成する.

### insert

```cpp
bool insert(const T key)
```

* $x$ を挿入する. 集合であるため, すでに同じ値が存在する場合は何もしない.
* **返り値**
  * 集合に変化があったら `true`, なければ `false`.
* **計算量**: 期待 $O(\log N)$ 時間

### erase

```cpp
bool erase(const T key)
```

* $x$ を削除する.
* **返り値**
  * 要素が削除されたら `true`, 存在しなかったら `false`.
* **計算量**: 期待 $O(\log N)$ 時間

### contains

```cpp
bool contains(const T key) const
```

* $x$ が集合に含まれているか判定する.
* **計算量**: 期待 $O(\log N)$ 時間

### size / empty / clear

```cpp
size_t size() const
bool empty() const
void clear()
```

* 集合の要素数取得, 空判定, 全要素の削除を行う.

### count_less / count_more / count_range

```cpp
int count_less(const T x, bool equal = false) const
int count_more(const T x, bool equal = false) const
int count_range(const T l, const T r, bool l_equal = true, bool r_equal = false) const
```

* 指定された条件を満たす要素の数を数える.
* **引数**
  * `x`: 基準となる値.
  * `l`, `r`: 範囲の左端および右端.
  * `equal`: 境界値 `x` を含めるかどうか.
  * `l_equal`: 左端 `l` を含めるかどうか.
  * `r_equal`: 右端 `r` を含めるかどうか.
* `count_less`: `equal` が `false` なら $x$ 未満, `true` なら $x$ 以下の個数.
* `count_more`: `equal` が `false` なら $x$ より大きい, `true` なら $x$ 以上の個数.
* `count_range`: 範囲内の要素数.デフォルトでは左閉右開 $[l, r)$.
* **計算量**: 期待 $O(\log N)$ 時間

### kth / safe_kth / operator[]

```cpp
T kth(int k) const
std::optional<T> safe_kth(int k) const
T operator[](int k) const
```

* $k$ 番目に小さい要素を取得する (0-indexed).
* $k < 0$ の場合, 末尾からの位置として扱われる（$-1$ は最大値）.
* `safe_kth` はインデックスが範囲外の場合に `std::nullopt` を返す.
* `kth` はインデックスが範囲外の場合に `std::out_of_range` 例外を送出する.
* **計算量**: 期待 $O(\log N)$ 時間

### kth_min / kth_max

```cpp
T kth_min(int k) const
T kth_max(int k) const
```

* `kth_min(k)`: $k$ 番目に小さい要素を取得する.`kth(k)` と同等.
* **引数**
  * `k`: 順位 (0-indexed).
* `kth_max(k)`: $k$ 番目に大きい要素を取得する.
* **計算量**: 期待 $O(\log N)$ 時間

### min / max

```cpp
T min() const
T max() const
```

* 最小値, および最大値を取得する.
* **計算量**: 期待 $O(\log N)$ 時間

### pop_min / pop_max

```cpp
T pop_min()
T pop_max()
```

* `pop_min()`: 最小値を取得し, その要素を集合から削除する.
* `pop_max()`: 最大値を取得し, その要素を集合から削除する.
* **制約**
  * 集合は空であってはならない.
* **計算量**: 期待 $O(\log N)$ 時間

### next / previous

```cpp
std::optional<T> next(const T x, bool equal = false) const
std::optional<T> previous(const T x, bool equal = false) const
```

* `next`: $x$ の次にある要素を取得する. `equal` が `true` なら $x$ 以上, `false` なら $x$ より大きい最小の要素.
* `previous`: $x$ の前にある要素を取得する. `equal` が `true` なら $x$ 以下, `false` なら $x$ 未満の最大の要素.
* 該当する要素がない場合は `std::nullopt` を返す.
* **引数**
  * `x`: 基準となる値.
  * `equal`: 境界値 `x` を探索対象に含めるかどうか.
* **計算量**: 期待 $O(\log N)$ 時間

## History

|日付|内容|
|:---:|:---:|
|2026/07/19| Treap 実装 |
