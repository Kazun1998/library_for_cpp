---
title: Bucket_List
documentation_of: //Data_Structure/Bucket_List.hpp
---

## Outline
平方分割 (sqrt decomposition) による, 挿入・削除が高速な列 (順序付きの多重集合的なリスト).

列を要素数 $O(\sqrt N)$ 個の **バケット** に分割して保持し, 各バケットは通常の `std::vector` として実装される. 添字アクセス・挿入・削除はいずれも「対象の要素がどのバケットの何番目にあるか」を求めたのち, そのバケット内で `std::vector` の操作を行うことで実現する. バケット数を $O(\sqrt N)$ 程度に保つことで, 各操作が $O(\sqrt N)$ で行える.

`std::vector` の `insert` / `erase` は平均 $O(N)$ かかるのに対し, 本データ構造では要素数 $N$ に対して $O(\sqrt N)$ で任意位置への挿入・削除が可能になる.

## Theory

### バケットの分割数

長さ $n$ の列を, 定数 `BUCKET_RATIO` を用いて $\left\lceil \sqrt{n / \mathrm{BUCKET\_RATIO}} \right\rceil$ 個のバケットに (可能な限り均等に) 分割する. `BUCKET_RATIO` はバケット1個あたりの目標サイズを調整するための定数であり, 実装では $16$ に設定されている.

以降, バケット数を $B$, 各バケットの平均サイズを $O(N / B) = O(\sqrt N)$ に保つことで, 全体の計算量を管理する.

### 第 $k$ 要素の位置特定 (position)

第 $k$ 要素がどのバケットの何番目に属するかを求める操作. 先頭からバケットを順に見ていき, 累積サイズが $k$ を超えたバケットに絞り込む.

このとき, $k$ が列の**後半寄り**にある場合は末尾のバケットから逆順に辿った方が探索するバケット数が少なくて済む. そのため, $k$ と $N - 1 - k$ の小さい方を基準に, 先頭または末尾のどちらから走査するかを選択する. これにより, 探索するバケット数の期待値・最悪値がおよそ半分になる.

この操作自体はバケット数 $O(\sqrt N)$ 個を線形に走査するため $O(\sqrt N)$ である.

### 挿入とバケットの分割 (split)

第 $k$ 要素の位置に値を挿入する際は, 該当バケットに対して `std::vector::insert` を行う. これによりバケットのサイズが偏っていくため, 挿入後のバケットサイズが `バケット数 × SPLIT_RATIO` を超えた場合, そのバケットを半分に分割して2つのバケットにする (`SPLIT_RATIO` は実装では $24$).

これにより, 1つのバケットに要素が集中して $O(N)$ サイズまで肥大化することを防ぎ, 各バケットのサイズを $O(\sqrt N)$ 程度に保つ.

### 削除とバケットの再構築 (rebuild)

要素を削除して空になったバケットはその都度取り除く. さらに, 削除を繰り返すとバケット数 $B$ に対して総要素数 $N$ が減っていき, 理想的なバケット数 $B^* = O(\sqrt N)$ よりもバケット数が過剰になることがある.

そこで, バケット数が理想値 $B^*$ の $2$ 倍を超えた時点で, 全バケットを一列に展開し直し, 改めて $B^*$ 個のバケットに均等分割する「再構築 (rebuild)」を行う. これにより, 挿入・削除を繰り返してもバケット数が $O(\sqrt N)$ に保たれる.

再構築は $O(N)$ かかるが, これを引き起こすには $\Omega(B^*)$ 回の削除が必要であるため, ならし計算量には $O(\sqrt N)$ しか寄与しない.

### 計算量まとめ

要素数を $N$ として, `insert` / `erase` (削除) / `pop` / `operator[]` などの位置に関する操作はいずれも $O(\sqrt N)$ で行える.

## Contents

### Constructor

```cpp
template<class T>
Bucket_List()

template<class T>
Bucket_List(const vector<T> &data)
```

* 空の列, もしくは `data` の内容で初期化された列を生成する.
* **計算量**: $O(N)$ 時間 ($N$ は `data` のサイズ)

### insert

```cpp
void insert(int k, const T a)
```

* 第 $k$ 要素となる位置に `a` を挿入する.
* **引数**
  * `k`: 挿入する場所. 負の場合は末尾からの位置として扱われる. `k == size()` のときは末尾への追加 (`append`) として扱われる.
* **計算量**: $O(\sqrt N)$ 時間

### append / push_back / push_front

```cpp
void append(const T a)
void push_back(const T a)
void push_front(const T a)
```

* `append` / `push_back`: 末尾に `a` を追加する (両者は同じ操作).
* `push_front`: 先頭に `a` を追加する (`insert(0, a)` と同等).
* **計算量**: ならし $O(\sqrt N)$ 時間

### extend

```cpp
void extend(const vector<T> &data)
```

* 末尾に `data` の要素をすべて順に追加する.
* **計算量**: $O(M \sqrt N)$ 時間 ($M$ は `data` のサイズ)

### pop / pop_back / pop_front

```cpp
T pop(int k = -1)
T pop_back()
T pop_front()
```

* `pop`: 第 $k$ 要素を削除し, その値を返す.
* **引数**
  * `k`: 削除する場所. 負の場合は末尾からの位置として扱われる. 省略時は末尾の要素を削除する.
* `pop_back`: 末尾の要素を削除し, その値を返す (`pop()` と同等).
* `pop_front`: 先頭の要素を削除し, その値を返す (`pop(0)` と同等).
* **計算量**: ならし $O(\sqrt N)$ 時間

### operator[]

```cpp
T operator[](int k) const
```

* 第 $k$ 要素を取得する.
* **引数**
  * `k`: 取得する場所. 負の場合は末尾からの位置として扱われる.
* **計算量**: $O(\sqrt N)$ 時間

### first / last

```cpp
T first() const
T last() const
```

* 先頭 / 末尾の要素を取得する.
* **制約**
  * 列は空であってはならない (空の場合 `std::out_of_range` を送出する).
* **計算量**: $O(1)$ 時間

### count

```cpp
int count(const T a) const
```

* `a` と一致する要素の個数を数える.
* **計算量**: $O(N)$ 時間

### contains

```cpp
bool contains(const T a) const
```

* `a` が列に含まれるかどうかを判定する.
* **計算量**: $O(N)$ 時間

### erase

```cpp
bool erase(const T a)
```

* `a` が初めて現れる要素を1つ削除する.
* **返り値**
  * 削除できたら `true`, `a` が存在しなかったら `false`.
* **計算量**: $O(N)$ 時間

### index

```cpp
int index(const T a) const
```

* `a` が初めて現れる位置を返す.
* **制約**
  * `a` が列に含まれていなければならない (含まれない場合 `std::invalid_argument` を送出する).
* **計算量**: $O(N)$ 時間

### size / empty / clear

```cpp
int size() const
bool empty() const
void clear()
```

* 列の要素数取得, 空判定, 全要素の削除を行う.
* **計算量**: `size` / `empty` は $O(1)$ 時間, `clear` は $O(1)$ 時間

### reverse

```cpp
void reverse()
```

* 列の要素の順序を反転する.
* **計算量**: $O(N)$ 時間

### begin / end

```cpp
iterator begin()
iterator end()
const_iterator begin() const
const_iterator end() const
```

* 先頭 / 番兵の位置を指すイテレータを取得する. `for (auto x : bucket_list)` のような範囲 `for` 文で利用できる.
* **計算量**: `begin` は $O(1)$ 時間, 各要素への `++` はならし $O(1)$ 時間

## History

|日付|内容|
|:---:|:---:|
|2026/07/25| Bucket_List 実装 |
