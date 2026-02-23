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
        Min_Cost_Flow(int n): Min_Cost_Flow(n, 1) {}

        ~Min_Cost_Flow() {
            for (auto* arc : arcs) {
                delete arc->rev;
                delete arc;
            }
        }

        inline int order() const { return n; }
        inline int size() const { return arcs.size(); }

        Arc<Cap, Cost>* add_arc(int u, int v, Cap cap, Cost cost) {
            int m = size();

            Arc<Cap, Cost>* arc = new Arc<Cap, Cost>(m, u, v, cap, Cap(0), objective * cost, true);
            Arc<Cap, Cost>* rev_arc = new Arc<Cap, Cost>(m, v, u, Cap(0), Cap(0), -objective * cost, false);

            arc->rev = rev_arc;
            rev_arc->rev = arc;

            adjacent_out[u].emplace_back(arc);
            adjacent_out[v].emplace_back(rev_arc);
            arcs.emplace_back(arc);

            return arc;
        }

        // 流量 f を流したときの最小コストを返す
        // 流量 f を流せない場合は nullopt
        optional<Cost> flow(int source, int target, Cap flow_amount) {
            vector<Cost> g = slope(source, target, flow_amount);
            // 実際に流せた流量が要求された流量に満たない場合は不可能
            if (g.size() - 1 < flow_amount) {
                return nullopt;
            }
            // g[k] は k 単位のフローを流したときの最小コスト
            return g[flow_amount];
        }

        // 流量とコストの関係を表す傾きを計算する (Primal-Dual法)
        vector<Cost> slope(int source, int target, Cap flow_limit) {
            potential.assign(n, Cost(0));
            vector<Cost> g{Cost(0)};

            while (flow_limit != 0) {
                calculate_potential(source);
                if (!reachable[target]) {
                    // これ以上フローを流せる経路がない
                    break;
                }

                // ポテンシャルの更新
                for (int v = 0; v < n; ++v) {
                    if (reachable[v]) { // 到達可能な頂点のみ更新
                        potential[v] += dist[v];
                    }
                }

                // 今回流す流量を計算
                Cap push_flow = flow_limit;
                for (int u = target; u != source; u = pre_v[u]) {
                    if (flow_limit < 0 && u == target) {
                        push_flow = pre_a[u]->remain();
                    } else {
                        chmin(push_flow, pre_a[u]->remain());
                    }
                }

                if (flow_limit >= 0) flow_limit -= push_flow;

                // コスト履歴を更新
                for (int k = 0; k < push_flow; ++k) {
                    g.emplace_back(g.back() + objective * potential[target]);
                }

                // 実際にフローを流す
                for (int u = target; u != source; u = pre_v[u]) {
                    pre_a[u]->push(push_flow);
                }
            }

            return g;
        }

        vector<Arc<Cap, Cost>> get_flow() const {
            vector<Arc<Cap, Cost>> res;
            for (const auto* arc : arcs) {
                res.push_back(*arc);
            }
            return res;
        }

        private:
        int n;
        vector<vector<Arc<Cap, Cost>*>> adjacent_out;
        vector<Arc<Cap, Cost>*> arcs;
        vector<Cost> potential;
        vector<int> pre_v;
        vector<Arc<Cap, Cost>*> pre_a;
        vector<Cost> dist;
        vector<bool> reachable;
        int objective;

        Min_Cost_Flow(int n, int objective): n(n), adjacent_out(n), objective(objective) {}

        // ポテンシャルを用いたDijkstra法で最短路を計算
        void calculate_potential(int s) {
            pre_v.assign(n, -1);
            pre_a.assign(n, nullptr);
            dist.assign(n, Cost(0));
            reachable.assign(n, false);
            dist[s] = Cost(0);
            reachable[s] = true;

            priority_queue<pair<Cost, int>, vector<pair<Cost, int>>, greater<pair<Cost, int>>> Q;
            Q.emplace(dist[s], s);

            while(!Q.empty()) {
                auto [d, v] = Q.top();
                Q.pop();

                if (d > dist[v]) continue;

                for (Arc<Cap, Cost>* arc: adjacent_out[v]) {
                    int w = arc->target;
                    // 縮約コスト (reduced cost)
                    Cost reduced_cost = arc->cost + potential[v] - potential[w];
                    Cost new_cost = d + reduced_cost;
                    if (!(arc->remain() > 0 && (!reachable[w] || dist[w] > new_cost))) continue;

                    dist[w] = new_cost;
                    reachable[w] = true;
                    pre_v[w] = v;
                    pre_a[w] = arc;
                    Q.emplace(dist[w], w);
                }
            }
        }
    };

    template <class Cap, class Cost>
    class Max_Gain_Flow : public Min_Cost_Flow<Cap, Cost> {
        public:
        Max_Gain_Flow(int n): Min_Cost_Flow<Cap, Cost>(n, -1) {}
    };
}
