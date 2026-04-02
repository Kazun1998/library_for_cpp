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

このとき, $F(L_1, R_1), \dots, F(L_Q, R_Q)$ を全て合計でで $O(\alpha N \sqrt{Q})$ Time で求めることが出来る.

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

* **閉区間** $[l, r]$ に対するクエリを追加する.

### run

```cpp
template<typename ADD, typename DEL, typename REM>
void run(const ADD &add, const DEL &del, const REM &rem)
```

* 予約された閉区間に対する Mo アルゴリズムを実行する.
* **引数**
    * `add`: 要素が追加される時の処理 (引数は数列のインデックス).
    * `del`: 要素が削除される時の処理 (引数は数列のインデックス).
    * `rem`: 結果を保存するときの処理 (引数はクエリのインデックス).
* **計算量**: クエリの数を $Q$ 個, `add`, `del` の計算量を $O(\alpha)$ 時間として, 合計 $O(\alpha N \sqrt{Q})$ 時間.

## History

|日付|内容|
|:---:|:---:|
|2026/01/25| Mo クラスの実装 |
