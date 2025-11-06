#pragma once

#include"../template/template.hpp"

namespace max_flow {
    template<typename Cap>
    struct Arc {
        int id, source, target;
        Cap cap, flow;
        bool direction;
        Arc* rev;

        Arc(int id, int source, int target, Cap cap, Cap flow, bool direction):
            id(id), source(source), target(target), cap(cap), flow(flow), direction(direction), rev(nullptr) {}

        inline bool is_flowable() const { return flow < cap; }
        inline Cap remain() const { return cap - flow; }

        void push(Cap d) {
            flow += d;
            rev->flow -= d;
        }
    };

    template<typename Cap>
    struct Max_Flow {
        private:
        using V = int;
        vector<vector<Arc<Cap>*>> adj_out;
        vector<Arc<Cap>*> arcs;
        vector<int> level, iter;

        bool bfs(const V s, const V t) {
            level.assign(order(), -1);
            queue<V> Q;

            Q.push(s);
            level[s] = 0;

            while (!Q.empty()) {
                V v = Q.front(); Q.pop();

                for (Arc<Cap>* arc: adj_out[v]) {
                    unless(arc->is_flowable() && level[arc->target] == -1) { continue; }

                    level[arc->target] = level[v] + 1;
                    if (arc->target == t) { return true; }

                    Q.push(arc->target);
                }
            }

            return false;
        }

        Cap dfs(const V v, const V t, const Cap f) {
            if (v == t) { return f; }

            for (int i = iter[v]; i < adj_out[v].size(); ++i) {
                Arc<Cap>* arc = adj_out[v][i];

                unless(arc->is_flowable() && level[v] < level[arc->target]) { continue; }

                Cap d = (f == -1) ? dfs(arc->target, t, arc->remain()) : dfs(arc->target, t, min(f, arc->remain()));

                unless(d > 0) { continue; }

                arc->push(d);
                return d;
            }

            return 0;
        }

        public:
        Max_Flow(int N = 0) {
            adj_out.resize(N);
            level.resize(N);
            iter.resize(N);
        }

        ~Max_Flow() {
            for (Arc<Cap>* arc : arcs) {
                if (arc->rev) { delete arc->rev; }
                delete arc;
            }
        }

        inline int order() const { return adj_out.size(); }
        inline int size() const { return arcs.size(); }

        int add_arc(const V u, const V v, const Cap cap) {
            int m = size();

            Arc<Cap>* arc = new Arc<Cap>(m, u, v, cap, 0, true);
            Arc<Cap>* rev_arc = new Arc<Cap>(m, v, u, 0, 0, false);

            arc->rev = rev_arc;
            rev_arc->rev = arc;

            adj_out[u].emplace_back(arc);
            adj_out[v].emplace_back(rev_arc);
            arcs.emplace_back(arc);

            return m;
        }

        int add_vertex() {
            adj_out.emplace_back({});
            level.emplace_back(-1);
            iter.emplace_back(0);

            return order() - 1;
        }

        Cap max_flow(const V source, const V target) {
            Cap flow = 0;
            while (bfs(source, target)) {
                iter.assign(order(), 0);
                Cap f;
                while ((f = dfs(source, target, -1)) > 0) {
                    flow += f;
                }
            }

            return flow;
        }

        Cap max_flow(const V source, const V target, Cap flow_limit) {
            Cap flow = 0;
            while (flow < flow_limit && bfs(source, target)) {
                iter.assign(order(), 0);
                Cap f;
                while ((f = dfs(source, target, -1)) > 0) {
                    flow += f;
                }
            }

            return flow;
        }

        vector<vector<tuple<int, V, Cap>>> get_flow() const {
            vector<vector<tuple<int, V, Cap>>> flow(order());

            for (Arc<Cap>* arc: arcs) {
                flow[arc->source].emplace_back(
                    arc->id,
                    arc->target,
                    arc->flow
                );
            }

            return flow;
        }

        vector<bool> min_cut(const int s) {
            vector<bool> group(order(), false); group[s] = true;

            deque<V> Q{s};

            while (!Q.empty()) {
                V x = Q.front(); Q.pop_front();

                for (Arc<Cap>* arc: adj_out[x]) {
                    V y = arc->target;
                    unless(arc->is_flowable() && !group[y]) { continue; }

                    group[y] = true;
                    Q.emplace_back(y);
                }
            }

            return group;
        }
    };
}
