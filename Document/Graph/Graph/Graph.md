---
title: 無向 Graph
documentation_of: //Graph/Graph/Graph.hpp
---

## Outline

無向 Graph $G$ を保存するクラス `Graph<W>` を提供する. 多重辺と自己ループを許す.

* `W` は辺の重みの型である. 省略時 (`Graph<>`) は重みなしであり, 重みの型は空の型 `Empty` になる.
* 辺は ID を持ち, 辺そのものは `vector` に **値で保持** する. 隣接リストは辺 ID と向きの情報だけを持つ.
* 旧 `weighted_graph::Weighted_Graph<W>` は本クラスに統合された.

```cpp
Graph<> G(n);              // 重みなし
Graph<long long> H(n);     // 重みあり
Graph G2(n);               // CTAD により Graph<Empty> と同じ
```

## Types

### Empty

```cpp
namespace graph_common { struct Empty {}; }
```

* 重みなしを表す空の型. `graph::Empty` として参照できる.
* `Edge<Empty>` は `[[no_unique_address]]` により重みの領域を取らない (`sizeof(Edge<>) == 12`).

### Edge

```cpp
template<typename W = Empty>
struct Edge {
    int id, source, target;
    W weight;
};
```

* 無向辺. `add_edge(u, v, ...)` で追加した場合, `source = u`, `target = v` である (無向なので向きに意味はない).
* 既定構築した `Edge` は `id = source = target = -1` である (ID オフセットのダミー用).

### Oriented_Edge

```cpp
struct Oriented_Edge {
    int id, source, target;
};
```

* 向きを付けた辺. 「頂点 `source` から `target` へ, 辺 `id` をたどる」ことを表す.
* 重みは持たない. 必要な場合は `G.get_edge(id).weight` で取得する.

## Contents

### constructor

```cpp
Graph(int n, int edge_id_offset = 0)
```

* 位数が $n$ である辺のない無向 Graph を構築する.
* 辺の ID は `edge_id_offset` から始まる. たとえば `edge_id_offset = 1` なら, 辺の ID は $1, 2, \dots$ になる.
* 計算量: $O(n + \text{edge\_id\_offset})$

### order

```cpp
int order() const
```

* 位数 (頂点数) を求める.

### size

```cpp
int size() const
```

* サイズ (辺の数) を求める. ID オフセットのダミーは数えない.

### add_edge

```cpp
int add_edge(int u, int v)                // W が Empty の場合のみ
int add_edge(int u, int v, W w)
```

* 重み $w$ の無向辺 $uv$ を追加する. 重みなしの場合は `w` を省略する.
* 戻り値は追加した辺の ID である. ID は追加した順に `edge_id_offset`, `edge_id_offset + 1`, ... になる.
* $u = v$ (自己ループ) や, 同じ頂点対への複数回の追加 (多重辺) も可能である.
* 計算量: 償却 $O(1)$

### incidence

```cpp
const vector<Oriented_Edge>& incidence(int u) const
```

* 頂点 $u$ に接続する辺を, **$u$ から出る向きにして** 返す. 各要素は `source = u` であり, `target` が反対側の端点である.
* 辺を追加した順に並ぶ.
* 自己ループ $uu$ は, 向きの違う 2 つの要素として **2 回** 現れる.

```cpp
for (const auto &edge: G.incidence(v)) {
    int u = edge.target;
    auto w = G.get_edge(edge.id).weight;
}
```

### get_edge

```cpp
const Edge<W>& get_edge(int id) const
Edge<W>& get_edge(int id)
```

* ID が `id` である辺を返す.
* ID が `edge_id_offset` 未満のものは, 既定構築されたダミーの辺である.

### degree

```cpp
int degree(int v) const
```

* 頂点 $v$ の次数を求める. 自己ループは 2 として数える.

### adjacency_matrix

```cpp
vector<vector<int>> adjacency_matrix() const
```

* 隣接行列を求める. $(i, j)$ 成分は, $i$ と $j$ を結ぶ辺の本数である. 自己ループ $ii$ は $(i, i)$ 成分に 2 加わる.
* 計算量: $O(n^2 + m)$

### degree_matrix

```cpp
vector<vector<int>> degree_matrix() const
```

* 次数行列 (対角成分が次数) を求める. 計算量: $O(n^2)$

### laplacian_matrix

```cpp
vector<vector<int>> laplacian_matrix() const
```

* ラプラシアン行列 (次数行列 $-$ 隣接行列) を求める. 計算量: $O(n^2 + m)$

## Notes

* **参照の無効化**: `add_edge` を呼ぶと, それ以前に `get_edge` で得た参照は無効になる可能性がある. 参照を保持したまま辺を追加しない.
* **コピー**: ポインタを使わないため, 通常の値と同様にコピー・ムーブできる. 解放処理は不要である.
* **重みの型**: `W` は既定構築可能で, コピー可能であること.

## Path

```cpp
// Graph/Graph/Path.hpp
struct Path {
    vector<int> vertices;
    vector<Oriented_Edge> edges;
};
```

* 頂点列と, たどった辺 (向き付き) の列. `Eulerian_Trail` などの戻り値に使う. `vertices.size() == edges.size() + 1` である.

## 旧 API からの移行

| 旧 | 新 |
|:---|:---|
| `graph::Graph` | `graph::Graph<>` (`Graph G(n)` も可) |
| `weighted_graph::Weighted_Graph<W>` | `graph::Graph<W>` (旧名は互換の別名として残る) |
| `weighted_graph::Weighted_Edge<W>` | `graph::Edge<W>` |
| `for (auto edge: G.incidence(v))` の `edge->target` | `edge.target` (`edge` は `Oriented_Edge`) |
| `edge->weight` (`incidence` の要素から) | `G.get_edge(edge.id).weight` |
| `G.get_edge(id)` がポインタ (`Weighted_Graph`) | `const Edge<W>&` |
| `G.edges` (`Weighted_Graph` の公開メンバ) | `edge_id_offset` から `size()` 個の ID を `get_edge` で走査 |
| `Minimum_Spanning_Tree::edges[k]->id` | `Minimum_Spanning_Tree::edges[k].id` (`Edge<W>` の値) |

## History

|日付|内容|
|:---:|:---|
|2026/10/04|重みをテンプレート引数化し, 辺を値 + ID で保持するように変更 (Weighted_Graph を統合), 仕様書の作成|
|2025/12/06|無向 Graph のドキュメントの作成|
