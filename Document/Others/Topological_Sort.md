---
title: トポロジカルソート
documentation_of: //Others/Topological_Sort.hpp
---

## Outline

有向グラフについてのトポロジカルソートに関する計算を行う.

## Define

$D = (V, A)$ を有向グラフとする. $D$ のトポロジカルソートとは, 以下を満たす $V$ 上の順序関係 $\leq$ のことである.

* $\leq$ は全順序関係である.
* 任意の $\overrightarrow{uv} \in A$ に対して, $u < v ~(\Leftrightarrow u \leq v \land u \neq v)$ である.

なお, 以下は同値になる.

* $D$ はトポロジカルソートを持つ.
* $D$ はサイクルを持たない. つまり, DAG である.



## Contents

### Constructor

```cpp
Topological_Sort(int n, bool self_loop = false)
```

* $n$ 頂点の空有向グラフを生成する.
* **引数**
  * `self_loop`: 自己ループがあるときに, トポロジカルソートの存在を認めるか?
    * `self_loop` = `true` にすると, 自己ループがあったとしても, トポロジカルソートの存在を認める. つまり, トポロジカルソートにおける条件について, $u < v$ の部分が $u \leq v$ になる.

### add_arc

```cpp
void add_arc(const int source, const int target)
```

* 弧 $\overrightarrow{st}$ を追加する.

### add_arc_multiple

```cpp
int add_arc_multiple(const vector<int> sources, const vector<int> targets)
```

* `sources` の各頂点から `targets` への各頂点への弧を追加する.
* **返り値**
  * このメソッドを高速に実現するために, 頂点を $1$ 個追加する必要がある. その追加された頂点の番号が帰って来る.

### add_vertex

```cpp
int add_vertex()
```

* 頂点を $1$ 個追加する
* **返り値**
  * 追加された頂点の番号

### sort

```cpp
optional<vector<int>> sort()
```

* トポロジカルソートを求める.
* **返り値**
  * DAG の場合はトポロジカルソート (昇順).
  * DAG でない場合は `nullopt`.

## History 

|日付|内容|
|:---:|:---:|
|2026/01/31|トポロジカルソートの実装|
