---
title: Mo
documentation_of: //Queries/Mo.hpp
---

## Outline

Mo アルゴリズムに関する計算を行う.

## Theory

長さ $N$ の列 $A=(A_0, A_1, \dots, A_{N-1})$ と以下の形式の $Q$ 個のクエリがある.

> 部分列 $(A_L, A_{L+1}, \dots, A_{R-1})$ における, とある値を $F(L,R)$ と書くことにする.
>
> このとき, $Q$ 個の整数の組 $(L_1, R_1), \dots, (L_Q, R_Q)$ が与えられるので, $F(L_1, R_1), \dots, F(L_Q, R_Q)$ を求めよ.

ここで, 以下の条件をみたしているとする.

- $A$ は $Q$ 個のクエリにおいて固定である.
- $Q$ 個のクエリが先読みできる.
- $F(L, R)$ が求まっているとき, そこから $F(L \pm 1, R), F(L, R \pm 1)$ が高速に ($O(\alpha)$ 時間で) 求める.
- $F(L, R)$ の値の保存 (回答の記録) が $O(\beta)$ 時間で行える.

このとき, $F(L_1, R_1), \dots, F(L_Q, R_Q)$ を全て合計で $O(\alpha N \sqrt{Q} + \beta Q)$ Time で求めることが出来る.

## Contents

### constructor

```cpp
Mo(const int N)
```

* 数列のインデックスが $0, 1, \dots, N-1$ であるような場を作成する.

### add_query

```cpp
void add_query(const int l, const int r)
```

* **閉区間** $[l, r]$ に対するクエリを追加する ($0 \le l \le r < N$ を想定).

### add_range

```cpp
void add_range(const int l, const int r)
```

* **半開区間** $[l, r)$ に対するクエリを追加する ($0 \le l \le r \le N$ を想定).

### run (共通版)

```cpp
template<typename ADD, typename DEL, typename REM>
void run(const ADD &add, const DEL &del, const REM &rem)
```

* 予約されたクエリに対する Mo アルゴリズムを実行する.
* **引数**
    * `add`: 要素が追加される時の処理 (引数は追加する要素の列におけるインデックス).
    * `del`: 要素が削除される時の処理 (引数は削除する要素の列におけるインデックス).
    * `rem`: 結果を保存するときの処理 (引数はクエリのインデックス).
* **計算量**: クエリの数を $Q$ 個, `add`, `del` の計算量を $O(\alpha)$ 時間, `rem` の計算量を $O(\beta)$ 時間として, 合計 $O(\alpha N \sqrt{Q} + \beta Q)$ 時間.
* 内部的には, 下記の左右分離版に対して `run(add, add, del, del, rem)` を呼び出す.

### run (左右分離版)

```cpp
template<typename ADD_L, typename ADD_R, typename DEL_L, typename DEL_R, typename REM>
void run(const ADD_L &add_left, const ADD_R &add_right, const DEL_L &del_left, const DEL_R &del_right, const REM &rem)
```

* 予約されたクエリに対する Mo アルゴリズムを実行する. 左端・右端の追加/削除処理をそれぞれ別に指定できる.
* **引数**
    * `add_left`: 左端の要素が追加される時の処理 (引数は追加する要素の列におけるインデックス).
    * `add_right`: 右端の要素が追加される時の処理 (引数は追加する要素の列におけるインデックス).
    * `del_left`: 左端の要素が削除される時の処理 (引数は削除する要素の列におけるインデックス).
    * `del_right`: 右端の要素が削除される時の処理 (引数は削除する要素の列におけるインデックス).
    * `rem`: 結果を保存するときの処理 (引数はクエリのインデックス).
* **計算量**: クエリの数を $Q$ 個, `add_left`, `add_right`, `del_left`, `del_right` の計算量を $O(\alpha)$ 時間, `rem` の計算量を $O(\beta)$ 時間として, 合計 $O(\alpha N \sqrt{Q} + \beta Q)$ 時間.

## History

|日付|内容|
|:---:|:---:|
|2026/09/27| 左右で `add`/`del` を分けられる `run` を追加 |
|2026/01/25| Mo クラスの実装 |
