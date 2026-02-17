---
title: 有向 Graph における Eulerian Trail
documentation_of: //Graph/Digraph/Eulerian_Trail.hpp
---

## Outline

有向 Graph $D = (V, A)$ における Eulerian Trail を求める.

## Definition

* 同じ弧を通らない歩道を路という.
* 全ての弧を通る路を Eulerian Trail という.

## Theory

以下は同値になる.

* (a) $D$ は Eulerian Trail を持つ.
* (b) 以下が全て従う.
  * (1) $D$ における孤立点以外の任意の頂点は連結である.
  * (2) $v \in V$ の出次数と入次数を $d_{\text{out}}(v), d_{\text{in}}(v)$ として, 以下のうちのどちらか一方が成り立つ.
    * (イ) 任意の頂点において, $d_{\text{out}}(v) = d_{\text{in}}(v)$ である.
    * (ロ) 以下が全て成り立つ.
      * (A) $d_{\text{out}}(s) = d_{\text{in}}(s) + 1$ となる $s \in V$ がただ一つ存在する.
      * (B) $d_{\text{out}}(t) = d_{\text{in}}(t) - 1$ となる $t \in V$ がただ一つ存在する.
      * (C) (A), (B) 以外の残りの頂点 $v \in V$ は全て $d_{\text{out}}(t) = d_{\text{in}}(t)$ である.

## History

|日付|内容|
|:---:|:---|
|2026/02/17| 有向グラフにおける Eulerian_Trail の実装|
