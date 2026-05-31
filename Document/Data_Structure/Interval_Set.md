---
title: Interval Set
documentation_of: //Data_Structure/Interval_Set.hpp
---

## Outline

区間による一括の挿入や削除及び, それらに付随する処理を高速に行うことができるデータ構造

## Contents

### constructor

```cpp
(1) Interval_Set(): Interval_Set(V()) {}
(2) Interval_Set(const V &nil): nil(nil), set_size(0) {}
```

* デフォルト値を `nil` として, インスタンスを生成する.

### covered

```cpp
(1) constexpr bool covered(const T &p)
(2) constexpr bool covered(const T &l, const T &r)
```

* (1) $p$ を要素に持っているか?
* (2) $[l, r)$ を部分集合になるか?
  * $p = l, l + 1, \dots, r-1$ を全て要素に持っているか? と同値
* **引数**
  * (1)
    * $p$: 要素
  * (2)
    * $l$: 右半開区間の左端
    * $r$: 右半開区間の右端 

### begin / end

```cpp
constexpr typename set<Node>::iterator begin()
constexpr typename set<Node>::iterator end()
```

* 内部で管理している区間集合（`std::set<Node>`）のイテレータを返す.
* イテレータをデリファレンスすることで `Node` オブジェクトが得られ、`it->l` (左端), `it->r` (右端), `it->val` (値) にアクセスできる.

### get

```cpp
constexpr typename set<Node>::iterator get(const T &p) const
```

* 点 $p$ を含む区間のイテレータを求める.
* $p$ を含む区間が存在しない場合は `end()` を返す.

### lower_bound

```cpp
constexpr typename set<Node>::iterator lower_bound(const T &p)
```

* 点 $p$ を含む区間、または $p$ より右側にある最初の区間のイテレータを求める.
* 該当する区間が存在しない場合は `end()` を返す.

### get_value / operator[]

```cpp
constexpr V get_value(const T &p) const
V operator[](const T &p) const
```

* 点 $p$ を含む区間に紐づいている値を求める. $p$ を含む区間が存在しない場合は `nil` を返す.

### same

```cpp
constexpr bool same(const T &p, const T &q)
```

* 点 $p$ と $q$ が同じ区間に属しているかを判定する.

### get_mex

```cpp
constexpr T get_mex(const T &p = 0)
```

* $p$ 以上の値のうち、集合に含まれていない最小の値を求める.

### size

```cpp
constexpr size_t size() const
```

* 集合に含まれる要素の総数（管理されている各区間の長さの合計）を返す.

### update

```cpp
(1) template<class ADDFUNC, class DELFUNC>
    void update(T l, T r, const V &val, const ADDFUNC &add, const DELFUNC &del)
(2) void update(const T &l, const T &r, const V &val)
```

* 区間 $[l, r)$ の値を `val` で更新する.
* **引数**
  * `l`, `r`: 更新対象とする右半開区間 $[l, r)$.
  * `val`: 更新後の値.
  * `add`: 内部で新たに区間が生成・追加された際に呼び出される関数オブジェクト.
    * シグネチャ: `void(T left, T right, V value)`
    * 渡される引数: 追加された区間の左端、右端、およびその値.
  * `del`: 既存の区間が削除、あるいは上書きによって消滅・縮小する際に呼び出される関数オブジェクト.
    * シグネチャ: `void(T left, T right, V value)`
    * 渡される引数: 削除される直前の区間の左端、右端、およびその値.
* **計算量**: ならし $O(\log N)$ ($N$ は現在の区間数)

### insert

```cpp
(1) template<class ADDFUNC, class DELFUNC>
    void insert(T l, T r, const ADDFUNC &add, const DELFUNC &del)
(2) void insert(const T &l, const T &r)
```

* 区間 $[l, r)$ を集合に追加する. 値には `V()` が用いられる.
* 既存の区間と連続または重複する場合、それらは自動的にマージされる.
* **引数**
  * `l`, `r`: 挿入する右半開区間 $[l, r)$.
  * `add`: マージや新規作成によって新たな区間が生成された際に呼び出される関数オブジェクト.
    * シグネチャ: `void(T left, T right, V value)`
    * 渡される引数: 生成された区間の左端、右端、およびその値 (`V()`).
  * `del`: マージによって既存の区間が消滅する際に呼び出される関数オブジェクト.
    * シグネチャ: `void(T left, T right, V value)`
    * 渡される引数: 消滅する直前の区間の左端、右端、およびその値.

### erase

```cpp
(1) template<class ADDFUNC, class DELFUNC>
    void erase(T l, T r, const ADDFUNC &add, const DELFUNC &del)
(2) void erase(const T &l, const T &r)
```

* 区間 $[l, r)$ を集合から削除する.
* 指定範囲と重なる既存の区間は削除され、必要に応じて端の部分が分割されて残る.
* **引数**
  * `l`, `r`: 削除対象とする右半開区間 $[l, r)$.
  * `add`: 既存の区間が $[l, r)$ によって分割され、一部が残る場合に呼び出される関数オブジェクト.
    * シグネチャ: `void(T left, T right, V value)`
    * 渡される引数: 分割されて残った方の区間の左端、右端、およびその値.
  * `del`: 既存の区間（またはその一部）が削除される際に呼び出される関数オブジェクト.
    * シグネチャ: `void(T left, T right, V value)`
    * 渡される引数: 削除される直前の区間（または分割される前の元区間）の左端、右端、およびその値.
