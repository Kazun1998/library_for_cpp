---
title: 順序付き多重集合
documentation_of: //Data_Structure/Ordered_Multiset.hpp
---

## Outline
Policy-Based Data Structures の `tree` を利用した順序付き多重集合 (マルチセット).

通常の `std::multiset` の機能に加え, 「小さい方から $k$ 番目の要素の取得」や「ある値未満の要素数」といった順位に関する操作を $O(\log N)$ で行うことができる.
内部的には, 要素と追加順などの識別子 (ID) のペア `std::pair<T, I>` を管理することで重複要素を保持している.

## Contents

### Constructer

```cpp
template<class T, class I = int>
Ordered_Multiset()

template<class T, class I = int>
Ordered_Multiset(std::initializer_list<T> init_list)

template<class T, class I = int>
Ordered_Multiset(Iterator first, Iterator last)

template<class T, class I = int>
Ordered_Multiset(const Container& container)
```

* 順序付き多重集合を生成する.

### insert

```cpp
bool insert(const T& x)
```

* $x$ を挿入する. 多重集合であるため, すでに同じ値が存在しても追加される.
* **返り値**
  * 常に `true`.
* **計算量**: $O(\log N)$ 時間

### erase

```cpp
bool erase(const T& x)
```

* $x$ が存在するならば, $x$ を **1個だけ** 削除する.
* **返り値**
  * 削除に成功した (要素が存在した) 場合は `true`, 存在しなかったら `false`.
* **計算量**: $O(\log N)$ 時間

### discard

```cpp
int discard(const T& x)
```

* $x$ を消せるだけ (すべて) 削除する.
* **返り値**
  * 削除した $x$ の個数.
* **計算量**: $O(\log N)$ 時間 (赤黒木の分裂・結合 `split`, `join` を用いるため, 重複度に関わらず高速に動作する)

### contains

```cpp
bool contains(const T& x) const
```

* $x$ が多重集合に含まれているか (1個以上存在するか) 判定する.
* **計算量**: $O(\log N)$ 時間

### size / empty / clear

```cpp
size_t size() const
bool empty() const
void clear()
```

* 多重集合の要素数取得 (重複を含めた総数), 空判定, 全要素の削除を行う.

### count_less / count_more / count / count_range

```cpp
int count_less(const T& x, bool equal = false) const
int count_more(const T& x, bool equal = false) const
int count(const T& x) const
int count_range(const T& l, const T& r, bool l_equal = true, bool r_equal = false) const
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
* `count`: $x$ の個数 (重複度) を求める.
* `count_range`: 範囲内の要素数. デフォルトでは左閉右開 $[l, r)$.
* **計算量**: $O(\log N)$ 時間

### kth / safe_kth / operator[]

```cpp
T kth(int k) const
std::optional<T> safe_kth(int k) const
T operator[](int k) const
```

* $k$ 番目に小さい要素を取得する (0-indexed).
* $k < 0$ の場合, 末尾からの位置として扱われる（$-1$ は最大値）.
* `safe_kth` はインデックスが範囲外の場合に `std::nullopt` を返す.
* **計算量**: $O(\log N)$ 時間

### kth_min / kth_max

```cpp
T kth_min(int k) const
T kth_max(int k) const
```

* `kth_min(k)`: $k$ 番目に小さい要素を取得する.`kth(k)` と同等.
* **引数**
  * `k`: 順位 (0-indexed).
* `kth_max(k)`: $k$ 番目に大きい要素を取得する.
* **計算量**: $O(\log N)$ 時間

### min / max

```cpp
T min() const
T max() const
```

* 最小値, および最大値を取得する. 
* **計算量**: $O(\log N)$ 時間

### next / previous

```cpp
std::optional<T> next(const T& x, bool equal = false) const
std::optional<T> previous(const T& x, bool equal = false) const
```

* `next`: $x$ の次にある要素を取得する. `equal` が `true` なら $x$ 以上, `false` なら $x$ より大きい最小の要素.
* `previous`: $x$ の前にある要素を取得する. `equal` が `true` なら $x$ 以下, `false` なら $x$ 未満の最大の要素.
* 該当する要素がない場合は `std::nullopt` を返す.
* **引数**
  * `x`: 基準となる値.
  * `equal`: 境界値 `x` を探索対象に含めるかどうか.
* **計算量**: $O(\log N)$ 時間
