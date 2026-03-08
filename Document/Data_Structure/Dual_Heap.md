---
title: Dual Heap
documentation_of: //Data_Structure/Dual_Heap.hpp
---

## Outline

全順序集合 $O$ に関する多重集合 $H$ に対して, 以下の処理を高速に行う.

* $H$ への要素の挿入
* $H$ から要素を削除
* $H$ における最小値, 最大値の取得
* $H$ から最小値, 最大値を取得し, 削除する.

## Contents

### Constructer

```cpp
template<typename O>
Dual_Heap H(const std::vector<O> &data)
```

* `data` で初期化する.
* **計算量**:
  * `data` のサイズを $N$ として, $O(N \log N)$ 時間.


### push

```cpp
void H.push(const O &x)
```

* $H$ に $x$ を追加する.
* **計算量** : $O(\log N)$ 時間

### discard

```cpp
bool H.discard(const O &x)
```

* $H$ から $x$ を (存在すれば) 削除する.
* **返り値**
  * もともと $H$ に $x$ が存在するならば `true`, 存在しないならば `false`.
* **計算量** : $O(\log N)$ 時間.

### get_min

```cpp
O H.get_min()
```

* $H$ における最小値を取得する.
* **制約**
  * $H$ は空であってはならない.
* **計算量** : $O(1)$ 時間.

### get_max

```cpp
O H.get_max()
```

* $H$ における最大値を取得する.
* **制約**
  * $H$ は空であってはならない.
* **計算量** : $O(1)$ 時間.

### pop_min

```cpp
O H.pop_min()
```

* $H$ における最小値を取得し, その最小値を削除する.
* **制約**
  * $H$ は空であってはならない.
* **計算量** : $O(1)$ 時間.

### pop_max

```cpp
O H.pop_max()
```

* $H$ における最大値を取得する.
* **制約**
  * $H$ は空であってはならない.
* **計算量** : $O(1)$ 時間.

### contains

```cpp
bool H.contains(const O &x)
```

* $H$ に $x$ が存在するかどうかを判定する.
* **計算量** : $O(1)$ 時間.

### count

```cpp
int H.count(const O &x)
```

* $H$ における $x$ の数を求める.
* **計算量** : $O(1)$ 時間.

### size

```cpp
int H.size()
```

* $H$ における要素数を求める.
* **計算量** : $O(1)$ 時間.


### empty

```cpp
bool H.size()
```

* $H$ が空かどうかを判定する.
* **計算量** : $O(1)$ 時間.

