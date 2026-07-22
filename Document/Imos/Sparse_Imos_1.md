---
title: 疎な場合のいもす法 (1 次元 0 次)
documentation_of: //Imos/Sparse_Imos_1.hpp
---

## Outline

1 次元 0 次のいもす法について, 変化の点が疎である場合に対応したクラス.
座標を `std::map` で管理することで, 座標圧縮を行わずとも, 大きい座標や負の座標を扱うことができる.

## Contents

### Constructor

```cpp
template <typename T, typename I = long long>
Sparse_Imos_1()
```

* 空の 1 次元いもす法オブジェクトを生成する.
* **テンプレート引数**
  * $T$: 加算値・累積和の値の型
  * $I$: 座標 (添字) の型 (省略時は `long long`)
* **計算量** : $O(1)$ 時間.

### add

```cpp
void add(const I l, const I r, const T x = 1)
```

* 閉区間 $[l, r]$ の各要素に $x$ を加算する.
* $l > r$ の場合は何も行わない.
* **引数**
  * $l$: 閉区間の左端
  * $r$: 閉区間の右端
  * $x$: 加算値 (省略時は $1$)
* **計算量** : $O(\log Q)$ 時間. ($Q$ はこれまでに追加された変化点の数)

### cumulative

```cpp
std::vector<std::tuple<T, I, I>> cumulative(const I since, const I until)
```

* 閉区間 $[\mathrm{since}, \mathrm{until}]$ における累積和を, 値が一定となる区間ごとに分けて求める.
* 戻り値は $(y, l, r)$ の形の組のリストであり, これは閉区間 $[l, r]$ において累積和が $y$ であることを意味する.
* **引数**
  * $\mathrm{since}$: 始点
  * $\mathrm{until}$: 終点
* **計算量** : $O(Q)$ 時間. ($Q$ はこれまでに追加された変化点の数)

### clear

```cpp
void clear()
```

* 内部の差分情報をすべて削除し, 再度 `add` を行えるようにクリアする.
* **計算量** : $O(Q)$ 時間. ($Q$ はこれまでに追加された変化点の数)

|日付|内容|
|:---:|:---|
|2026/07/23| いもす法 (1 次元 0 次, 疎な場合) の実装 |
