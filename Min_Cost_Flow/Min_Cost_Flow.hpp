#pragma once

#include "../template/template.hpp"

namespace min_cost_flow {
    template<class Cap, class Cost>
    struct Arc {
        int id, source, target;
        Cap cap, flow;
        Cost cost;
        bool direction;
        Arc* rev;

        Arc(int id, int source, int target, Cap cap, Cap flow, Cost cost, bool direction):
            id(id), source(source), target(target), cap(cap), flow(flow), cost(cost), direction(direction), rev(nullptr) {}

        inline bool is_flowable() const { return flow < cap; }
        inline Cap remain() const { return cap - flow; }

        void push(Cap d) {
            flow += d;
            rev->flow -= d;
        }
    };

    template<class Cap, class Cost>
    class Min_Cost_Flow {
        public:
        Min_Cost_Flow(int n): n(n), adjacent_out(n, vector<Arc<Cap, Cost>*>{}) {}

        inline int order() const { return adjacent_out.size(); }
        inline int size() const { return arcs.size(); }

        Arc<Cap, Cost>* add_arc(int u, int v, Cap cap, Cost cost) {
            int m = size();

            Arc<Cap, Cost>* arc = new Arc<Cap, Cost>(m, u, v, cap, Cap(0), cost, true);
            Arc<Cap, Cost>* rev_arc = new Arc<Cap, Cost>(m, v, u, Cap(0), Cap(0), -cost, false);

            arc->rev = rev_arc;
            rev_arc->rev = arc;

            adjacent_out[u].emplace_back(arc);
            adjacent_out[v].emplace_back(rev_arc);
            arcs.emplace_back(arc);

            return arc;
        }

        vector<Cost> slope(int source, int target, Cap flow_limit) {
            int n = order();
            Cost inf = numeric_limits<Cost>::max() / 3;

            potential.assign(n, Cost(0));
            vector<Cost> g{Cost(0)};

            while (flow_limit > 0) {
                calculate_potential(source, inf);
                if (dist[target] == inf) break;

                for (int v = 0; v < n; ++v) potential[v] += dist[v];

                Cap push_flow = flow_limit;

                int u;
                u = target;
                while (u != source) {
                    chmin(push_flow, pre_a[u]->remain());
                    u = pre_v[u];
                }

                flow_limit -= push_flow;
                for (int k = 1; k <= push_flow; ++k) {
                    g.emplace_back(g.back() + potential[target]);
                }

                u = target;
                while (u != source) {
                    pre_a[u] -> push(push_flow);
                    u = pre_v[u];
                }
            }

            return g;
        }

        optional<Cost> flow(int source, int target, int flow) {
            vector<Cost> g = slope(source, target, flow);
            if (g.size() == flow + 1) return g.back();
            else return nullopt;
        }

        private:
        int n;
        vector<vector<Arc<Cap, Cost>*>> adjacent_out;
        vector<Arc<Cap, Cost>*> arcs;
        vector<Cost> potential;
        vector<int> pre_v;
        vector<Arc<Cap, Cost>*> pre_a;
        vector<Cost> dist;

        void calculate_potential(int s, const Cost inf) {
            pre_v.assign(n, -1);
            pre_a.assign(n, nullptr);
            dist.assign(n, inf); dist[s] = Cost(0);

            priority_queue<pair<Cost, int>, vector<pair<Cost, int>>, greater<pair<Cost, int>>> Q;
            Q.emplace(dist[s], s);
            while(!Q.empty()) {
                auto top = Q.top();
                Q.pop();
                Cost d = top.first;
                int v = top.second;

                if (d > dist[v]) continue;

                for (Arc<Cap, Cost>* arc: adjacent_out[v]) {
                    int w = arc->target;
                    unless (arc->remain() > 0 && dist[w] > d + potential[v] - potential[w] + arc->cost) continue;

                    dist[w] = d + potential[v] - potential[w] + arc->cost;
                    pre_v[w] = v;
                    pre_a[w] = arc;
                    Q.emplace(dist[w], w);
                }
            }
        }
    };
}