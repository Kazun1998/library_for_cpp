#pragma once

#include"../../template/template.hpp"

namespace digraph {
    struct Arc {
        int id, source, target;

        Arc() = default;
        Arc(int id, int source, int target): id(id), source(source), target(target) {}
    };

    class Digraph {
        private:
        int arc_id_offset;
        vector<vector<Arc*>> adjacent_out, adjacent_in;
        vector<Arc> arcs;

        public:
        Digraph(int n, int arc_id_offset = 0): arc_id_offset(arc_id_offset) {
            adjacent_out.assign(n, {});
            adjacent_in.assign(n, {});
            arcs.resize(arc_id_offset);
        }
        
        inline int order() const { return int(adjacent_in.size()); }

        inline int size() const { return int(arcs.size()) - arc_id_offset; }

        // 頂点 u から頂点 v への重み w の弧を追加する.
        Arc* add_arc(int u, int v) {
            int id = int(arcs.size());

            Arc* arc_ptr = new Arc(id, u, v);
            arcs.emplace_back(*arc_ptr);
            
            adjacent_out[u].emplace_back(arc_ptr);
            adjacent_in[v].emplace_back(arc_ptr);

            return arc_ptr;
        }

        // 頂点 u から出る弧の ID のリストを取得
        inline const vector<Arc*>& successors(int u) const { return adjacent_out[u]; }

        // 頂点 u に入る弧の ID のリストを取得
        inline const vector<Arc*>& predecessors(int u) const { return adjacent_in[u]; }

        // 弧 ID が id である弧を取得する.
        inline const Arc get_arc(int id) const { return arcs[id]; }
        inline Arc get_arc(int id) { return arcs[id]; }

        // 頂点 v の出次数
        inline int out_degree(const int v) const { return adjacent_out[v].size(); }

        // 頂点 v の入次数
        inline int in_degree(const int v) const { return adjacent_in[v].size(); }

        // sources から到達可能な頂点一覧
        vector<int> forward_reachable(const vector<int> &sources) const {
            const int n = order();
            vector<bool> visited(n, false);
            vector<int> reachable;

            for (const int s : sources) {
                if (s < 0 || s >= n || visited[s]) continue;
                visited[s] = true;
                reachable.emplace_back(s);
            }

            for (int head = 0; head < reachable.size(); ++head) {
                const int u = reachable[head];
                for (const auto *arc : adjacent_out[u]) {
                    const int v = arc->target;
                    if (visited[v]) continue;

                    visited[v] = true;
                    reachable.emplace_back(v);
                }
            }

            return reachable;
        }
    };
}
