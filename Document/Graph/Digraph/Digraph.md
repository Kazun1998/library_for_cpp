---
title: 有向 Graph
documentation_of: //Graph/Digraph/Digraph.hpp
---

## Outline

有向 Graph $D$ を保存するクラス `Digraph<W>` を提供する.

- `W` は弧の重みの型. 省略時 (`Digraph<>`) は重みなし (`Empty`) で, 弧は `add_arc(u, v)` で追加する.
- 重みあり (`Digraph<long long>` など) では `add_arc(u, v, w)` で追加する.
- 弧は値で保持し, 隣接リスト (`successors`, `predecessors`) は弧 ID のリストを返す. 弧本体は `get_arc(id)` で取得する.
- `add_arc` を呼ぶと, それ以前に `get_arc` で得た参照は無効になる可能性がある.

## History

|日付|内容|
|:---:|:---|
|2026/10/04| 重みをテンプレート引数化し, 弧を値 + ID で保持するように変更 |
|2026/02/21| forward_reachable, backward_reachable の実装 |
|2026/02/16| out_degree, in_degree 実装 |
|2026/01/01| 接続している弧をポインタで持つように |
|2025/08/17| 有向 Graph のクラスの構築 |
