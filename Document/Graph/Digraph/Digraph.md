---
title: 有向 Graph
documentation_of: //Graph/Digraph/Digraph.hpp
---

## Outline

有向 Graph $D$ を保存するクラス `Digraph<W>` を提供する. 多重弧と自己ループを許す.

* `W` は弧の重みの型である. 省略時 (`Digraph<>`) は重みなしであり, 重みの型は空の型 `Empty` になる.
* 弧は ID を持ち, 弧そのものは `vector` に **値で保持** する. 隣接リストは弧 ID だけを持つ.
* 旧 `weighted_digraph::Weighted_Digraph<W>` は本クラスに統合された.

```cpp
Digraph<> D(n);            // 重みなし
Digraph<long long> E(n);   // 重みあり
Digraph D2(n);             // CTAD により Digraph<Empty> と同じ
```

## Types

### Empty

```cpp
namespace graph_common { struct Empty {}; }
```

* 重みなしを表す空の型. `digraph::Empty` として参照できる.
* `Arc<Empty>` は `[[no_unique_address]]` により重みの領域を取らない (`sizeof(Arc<>) == 12`).

### Arc

```cpp
template<typename W = Empty>
struct Arc {
    int id, source, target;
    W weight;
};
```

* 弧 `source` → `target`.
* 既定構築した `Arc` は `id = source = target = -1` である (ID オフセットのダミー用).

## Contents

### constructor

```cpp
Digraph(int n, int arc_id_offset = 0)
```

* 位数が $n$ である弧のない有向 Graph を構築する.
* 弧の ID は `arc_id_offset` から始まる.
* 計算量: $O(n + \text{arc\_id\_offset})$

### order

```cpp
int order() const
```

* 位数 (頂点数) を求める.

### size

```cpp
int size() const
```

* サイズ (弧の数) を求める. ID オフセットのダミーは数えない.

### add_arc

```cpp
int add_arc(int u, int v)                // W が Empty の場合のみ
int add_arc(int u, int v, W w)
```

* 重み $w$ の弧 $u \to v$ を追加する. 重みなしの場合は `w` を省略する.
* 戻り値は追加した弧の ID である. ID は追加した順に `arc_id_offset`, `arc_id_offset + 1`, ... になる.
* 計算量: 償却 $O(1)$

### successors

```cpp
const vector<int>& successors(int u) const
```

* 頂点 $u$ から出る弧の **ID** のリストを返す (追加した順).

### predecessors

```cpp
const vector<int>& predecessors(int u) const
```

* 頂点 $u$ に入る弧の **ID** のリストを返す (追加した順).

```cpp
for (int id: D.successors(v)) {
    const auto &arc = D.get_arc(id);
    int u = arc.target;
    auto w = arc.weight;
}
```

### get_arc

```cpp
const Arc<W>& get_arc(int id) const
Arc<W>& get_arc(int id)
```

* ID が `id` である弧を返す.
* ID が `arc_id_offset` 未満のものは, 既定構築されたダミーの弧である.

### out_degree / in_degree

```cpp
int out_degree(int v) const
int in_degree(int v) const
```

* 頂点 $v$ の出次数 / 入次数を求める. 自己ループは, 出次数・入次数の両方に 1 として数える.

### forward_reachable

```cpp
vector<int> forward_reachable(const vector<int>& sources) const
vector<int> forward_reachable(int source) const
```

* 頂点集合 `sources` (または頂点 `source`) から, 弧をたどって到達可能な頂点のリストを返す. 始点自身を含み, 幅優先探索の訪問順に並ぶ.
* 範囲外の頂点は無視する.
* 計算量: $O(n + m)$

### backward_reachable

```cpp
vector<int> backward_reachable(const vector<int>& targets) const
vector<int> backward_reachable(int target) const
```

* 頂点集合 `targets` (または頂点 `target`) へ, 弧をたどって到達可能な頂点のリストを返す. 終点自身を含む.
* 計算量: $O(n + m)$

## Notes

* **参照の無効化**: `add_arc` を呼ぶと, それ以前に `get_arc` で得た参照は無効になる可能性がある. 参照を保持したまま弧を追加しない.
* **コピー**: ポインタを使わないため, 通常の値と同様にコピー・ムーブできる. 解放処理は不要である.
* **重みの型**: `W` は既定構築可能で, コピー可能であること.

## Path

```cpp
// Graph/Digraph/Path.hpp
template<typename W = Empty>
struct Path {
    vector<int> vertices;
    vector<Arc<W>> arcs;
};
```

* 頂点列と, たどった弧の列. `Eulerian_Trail` などの戻り値に使う. `vertices.size() == arcs.size() + 1` である.
* 重みなしの場合は `Path<>` と書く.

## 旧 API からの移行

| 旧 | 新 |
|:---|:---|
| `digraph::Digraph` | `digraph::Digraph<>` (`Digraph D(n)` も可) |
| `weighted_digraph::Weighted_Digraph<W>` | `digraph::Digraph<W>` (旧名は互換の別名として残る) |
| `weighted_digraph::Weighted_Arc<W>` | `digraph::Arc<W>` |
| `Arc* add_arc(u, v)` (`Digraph`) | 弧 ID (`int`) を返す |
| `for (auto arc: D.successors(v))` の `arc->target` | `for (int id: D.successors(v))` の `D.get_arc(id).target` |
| `Arc get_arc(id)` (値渡し, `Digraph`) | `const Arc<W>&` |
| `digraph::Path` | `digraph::Path<>` |
| `Eulerian_Trail(const Digraph&)` が `optional<Path>` | `Eulerian_Trail(const Digraph<W>&)` が `optional<Path<W>>` |
| `Dijkstra(Weighted_Digraph<W>&, ...)` | `Dijkstra(const Digraph<W>&, ...)` |

## History

|日付|内容|
|:---:|:---|
|2026/10/04|重みをテンプレート引数化し, 弧を値 + ID で保持するように変更 (Weighted_Digraph を統合), 仕様書の作成|
|2026/02/21| forward_reachable, backward_reachable の実装 |
|2026/02/16| out_degree, in_degree 実装 |
|2026/01/01| 接続している弧をポインタで持つように |
|2025/08/17| 有向 Graph のクラスの構築 |
