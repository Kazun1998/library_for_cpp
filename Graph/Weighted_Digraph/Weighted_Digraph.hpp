#pragma once

namespace weighted_digraph {
  template<typename W>
  struct Weighted_Arc {
    int id, source, target;
    W weight;

    Weighted_Arc (int id, int source, int target, W weight): id(id), source(source), target(target), weight(weight) {}
  };

  template<typename W>
  class Weighted_Digraph {
    using Arc = Weighted_Arc<W>;

    private:
    int arc_id_offset;
    vector<vector<int>> adjacent_out, adjacent_in;
    vector<Arc> arcs;

    public:
    Weighted_Digraph(int n, int arc_id_offset = 0): arc_id_offset(arc_id_offset) {
        adjacent_out.assign(n, {});
        adjacent_in.assign(n, {});
        arcs.resize(arc_id_offset, Weighted_Arc<W>(-1, -1, -1, W()));
      }
    
    inline int order() const { return int(adjacent_in.size()); }

    inline int size() const { return int(arcs.size()) - arc_id_offset; }

    // 頂点 u から頂点 v への重み w の弧を追加する.
    int add_arc(int u, int v, W w){
      int id = int(arcs.size());

      adjacent_out[u].emplace_back(id);
      adjacent_in[v].emplace_back(id);
      arcs.emplace_back(id, u, v, w);

      return id;
    }

    // 頂点 u から出る弧の ID のリストを取得
    inline const std::vector<int>& successors(int u) const { return adjacent_out[u]; }

    // 頂点 u に入る弧の ID のリストを取得
    inline const std::vector<int>& predecessors(int u) const { return adjacent_in[u]; }

    // 弧 ID が id である弧を取得する.
    inline const Arc& get_arc(int id) const { return arcs[id]; }
    inline Arc& get_arc(int id) { return arcs[id]; }
  };
}
