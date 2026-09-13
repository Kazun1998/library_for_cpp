---
title: 順序付き Trie 木
documentation_of: //Sequence/Ordered_Trie.hpp
---

## Outline

列の接頭辞に関する検索に加えて, 辞書順に関する計算を高速に行うことができる Trie 木を提供する.

内部で各ノードの子を `std::map` で管理しており, キーの型 $T$ が全順序 (`totally_ordered<T>`) を持つ必要がある.

## Define

$\mathcal{A}$ を全順序の入ったアルファベットとする.

$W_1, W_2, \dots, W_n$ に関する Trie 木とは, 以下で定義される根付き木 $(T, r)~(T = (V, E))$ である.

* $V$ は $W_1, \dots, W_n$ の接頭辞全体 (空文字列も含む) である. つまり,

$$ V = \{ \emptyset \} ~\cup~ \bigcup_{i=1}^n \{ v_{i,j} := w_{i,1} \dots w_{i,j} \mid 1 \leq j \leq \lvert w_i \rvert \} $$

である.

* 根 $r$ は空文字列 $\emptyset$ である.
* $T$ における辺は, 長さがちょうど $1$ だけ異なり, 一方が他方の接頭辞になっているとき, そしてそのときに限って結ばれる. つまり,

$$ E := \bigcup_{i=1}^n \{ v_{i,j-1} v_{i,j} \mid 1 \leq j \leq \lvert w_i \rvert \} $$

である.

各ノードの子は $\mathcal{A}$ の順序に従って並んでいるため, 木を深さ優先で辿ると登録されている列を辞書順に列挙できる. これを利用して,辞書式順序に関するクエリを高速に計算するメソッドを提供する.

## Contents

以下, $L$ を挿入・削除・検索の対象となる列の長さ, $D$ をノードの子の数 (アルファベットサイズ以下) とする.

### Constructor

```cpp
Ordered_Trie()
```

- 空の Trie 木を作成する.
- **計算量**
  * $O(1)$ Time.

### insert

```cpp
(1) void insert(const vector<T> &vec, Node *node)
(2) void insert(const vector<T> &vec)
```

- Trie 木に `vec` を挿入する.
  * (1) 挿入の開始位置を `node` にする.
  * (2) 挿入の開始位置を根にする.
- **計算量**
  * $O(L \log D)$ Time.

### erase

```cpp
(1) bool erase(const vector<T> &vec, Node *node)
(2) bool erase(const vector<T> &vec)
```

- Trie 木から `vec` を $1$ 個削除する.
  * (1) 削除の開始位置を `node` にする.
  * (2) 削除の開始位置を根にする.
- **返り値**
  * `vec` が登録されていなければ何もせず `false` を返す. 削除できれば `true` を返す.
- **計算量**
  * $O(L \log D)$ Time.

### discard

```cpp
(1) size_t discard(const vector<T> &vec, Node *node)
(2) size_t discard(const vector<T> &vec)
```

- Trie 木に登録されている `vec` をすべて削除する.
  * (1) 削除の開始位置を `node` にする.
  * (2) 削除の開始位置を根にする.
- **返り値**
  * 削除した個数.
- **計算量**
  * $O(L \log D)$ Time.

### count

```cpp
(1) size_t count(const vector<T> &vec, Node *node)
(2) size_t count(const vector<T> &vec)
```

- Trie 木に登録されている `vec` の個数を求める.
  * (1) 検索の開始位置を `node` にする.
  * (2) 検索の開始位置を根にする.
- **計算量**
  * $O(L \log D)$ Time.

### count_prefixing

```cpp
(1) size_t count_prefixing(const vector<T> &vec, Node *node, bool equal = true)
(2) size_t count_prefixing(const vector<T> &vec, bool equal = true)
```

- 登録されている列のうち, `vec` の接頭辞になっているものの個数を求める.
  * `equal = false` のとき, `vec` 自身は除いて数える.
- **計算量**
  * $O(L \log D)$ Time.

### count_prefixed

```cpp
(1) size_t count_prefixed(const vector<T> &vec, Node *node, bool equal = true)
(2) size_t count_prefixed(const vector<T> &vec, bool equal = true)
```

- 登録されている列のうち, `vec` を接頭辞に持つものの個数を求める.
  * `equal = false` のとき, `vec` 自身は除いて数える.
- **計算量**
  * $O(L \log D)$ Time.

### contains / search

```cpp
(1) bool contains(const vector<T> &vec, Node *node)
(2) bool contains(const vector<T> &vec)
(3) bool search(const vector<T> &vec, Node *node)
(4) bool search(const vector<T> &vec)
```

- `vec` が登録されているかどうかを判定する. `search` は `contains` のシノニム.
- **計算量**
  * $O(L \log D)$ Time.

### search_prefixing / search_prefixed

```cpp
(1) bool search_prefixing(const vector<T> &vec, Node *node)
(2) bool search_prefixing(const vector<T> &vec)
(3) bool search_prefixed(const vector<T> &vec, Node *node)
(4) bool search_prefixed(const vector<T> &vec)
```

- `search_prefixing` は `vec` の接頭辞になっている列が $1$ つでも登録されているか, `search_prefixed` は `vec` を接頭辞に持つ列が $1$ つでも登録されているかを判定する.
- **計算量**
  * $O(L \log D)$ Time.

### get / get_root

```cpp
(1) Node* get(const vector<T> &vec, Node *node)
(2) Node* get(const vector<T> &vec)
(3) Node* get_root()
```

- `vec` に対応するノードを求める. 途中で辿れなくなった場合は `nullptr` を返す.
  * (3) 根のノードを返す.
- **計算量**
  * $O(L \log D)$ Time.

### size

```cpp
size_t size() const
```

- Trie 木に登録されている列の総数を求める.
- **計算量**
  * $O(1)$ Time.

### find_by_order

```cpp
(1) vector<T> find_by_order(size_t k, Node *node)
(2) vector<T> find_by_order(size_t k)
```

- 辞書順で $k$ 番目 ($0$-indexed) に小さい列を求める.
  * (1) `node` 以下における相対的な順位で数える.
- **制約**
  * $0 \leq k <$ (対象の部分木に登録されている列の総数).
- **計算量**
  * $O(L \log D)$ Time.

### order_of_key

```cpp
(1) size_t order_of_key(const vector<T> &vec, Node *node)
(2) size_t order_of_key(const vector<T> &vec)
```

- `vec` より真に辞書順で小さい列の個数を求める.
  * (1) `node` 以下における相対的な個数で数える.
- **計算量**
  * $O(L D)$ Time.

### count_less / count_more

```cpp
(1) size_t count_less(const vector<T> &vec, Node *node, bool equal = false)
(2) size_t count_less(const vector<T> &vec, bool equal = false)
(3) size_t count_more(const vector<T> &vec, Node *node, bool equal = false)
(4) size_t count_more(const vector<T> &vec, bool equal = false)
```

- `vec` より辞書順で小さい (大きい) 列の個数を求める.
  * `equal = true` のとき, `vec` 自身と等しい列も個数に含める.
- **計算量**
  * $O(L D)$ Time.

### min / max

```cpp
(1) optional<vector<T>> min()
(2) optional<vector<T>> max()
```

- 登録されている列の中で辞書順最小 / 最大の列を求める.
- **返り値**
  * $1$ つも登録されていなければ `nullopt` を返す.
- **計算量**
  * $O(L)$ Time.

### next / prev

```cpp
(1) optional<vector<T>> next(const vector<T> &vec, bool equal = false)
(2) optional<vector<T>> prev(const vector<T> &vec, bool equal = false)
```

- 登録されている列の中で `vec` の successor (`next`) / predecessor (`prev`) を求める.
  * `equal = true` のとき, `vec` 自身も候補に含める.
- **返り値**
  * 該当する列が存在しなければ `nullopt` を返す.
- **計算量**
  * $O(L D)$ Time.

## Note

`string` を対象とする場合は, `vector<char>` の代わりに `string` を直接渡すオーバーロードが用意されている.

## History

|日付|内容|
|:---:|:---|
|2026/09/13| Ordered_Trie 実装 |
