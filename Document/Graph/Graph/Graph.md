---
title: 無向 Graph
documentation_of: //Graph/Graph/Graph.hpp
---

## Outline

無向 Graph $G$ を保存するクラス `Graph<W>` を提供する.

- `W` は辺の重みの型. 省略時 (`Graph<>`) は重みなし (`Empty`) で, 辺は `add_edge(u, v)` で追加する.
- 重みあり (`Graph<long long>` など) では `add_edge(u, v, w)` で追加する. 戻り値は辺の ID.
- 辺は値で保持する. `get_edge(id)` で辺 (`Edge<W>`: `id`, `source`, `target`, `weight`) を取得する.
- `incidence(u)` は, 頂点 $u$ に接続する辺を $u$ から出る向きにした `Oriented_Edge` (`id`, `source`, `target`) のリストを返す. 重みは `get_edge(id).weight` で取得する. 自己ループは 2 回現れる.
- `add_edge` を呼ぶと, それ以前に `get_edge` で得た参照は無効になる可能性がある.
- 旧 `weighted_graph::Weighted_Graph<W>` は `Graph<W>` に統合された (互換のため別名は残している).

## History

|日付|内容|
|:---:|:---|
|2026/10/04|重みをテンプレート引数化し, 辺を値 + ID で保持するように変更 (Weighted_Graph を統合)|
|2025/12/06|無向 Graph のドキュメントの作成|
