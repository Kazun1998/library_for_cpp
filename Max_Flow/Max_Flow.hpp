#pragma once

// Source: https://github.com/Kazun1998/library_for_cpp/blob/main/Max_Flow/Max_Flow.hpp

#include"../template/template.hpp"

namespace max_flow {
    template<typename Cap>
    struct Arc {
        /// @brief 弧の id (順辺と逆辺で共通)
        int id;

        /// @brief 弧の始点と終点
        int source, target;

        /// @brief 容量と現在の流量 (逆辺では cap = 0, flow = -(順辺の流量))
        Cap cap, flow;

        /// @brief true → add_arc で追加した弧 (順辺), false → 残余グラフ用の逆辺
        bool direction;

        /// @brief 対になる弧 (source と target を入れ替えた弧) へのポインタ.
        /// 順辺なら逆辺を, 逆辺なら順辺を指す.
        Arc* rev;

        Arc(int id, int source, int target, Cap cap, Cap flow, bool direction):
            id(id), source(source), target(target), cap(cap), flow(flow), direction(direction), rev(nullptr) {}

        /// @brief 残余容量が正 (まだ流せる) かどうかを判定する
        /// @return 残余容量が正ならば true
        inline bool is_flowable() const { return flow < cap; }

        /// @brief 残余容量を求める
        /// @return 残余容量 cap - flow
        inline Cap remain() const { return cap - flow; }

        /// @brief この弧に流量 d を流す. 対になる弧の流量も -d だけ更新する.
        /// @param d 流す量
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

        /// @brief 残余グラフ上で s からの BFS を行い, level (s からの距離) を計算する.
        /// t に到達した時点で打ち切る.
        /// @param s 始点
        /// @param t 終点
        /// @return 残余グラフで s から t に到達可能ならば true
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

        /// @brief レベルグラフ上で v から t への増加パスを 1 本探し, そこに流す.
        /// iter[v] を進めることで, 1 回のフェーズ内で同じ弧を再探索しない.
        /// @param v 現在の頂点
        /// @param t 終点
        /// @param f 流量の上限 (unlimited = true のときは無視される)
        /// @param unlimited true のとき, 流量の上限は無いものとして扱う
        /// @return 流した量 (増加パスが無ければ 0)
        Cap dfs(const V v, const V t, const Cap f, const bool unlimited) {
            if (v == t) { return f; }

            for (int &i = iter[v]; i < (int)adj_out[v].size(); ++i) {
                Arc<Cap>* arc = adj_out[v][i];

                unless(arc->is_flowable() && level[v] < level[arc->target]) { continue; }

                Cap next_f = unlimited ? arc->remain() : min(f, arc->remain());
                Cap d = dfs(arc->target, t, next_f, false);

                unless(d > 0) { continue; }

                arc->push(d);
                return d;
            }

            return 0;
        }

        public:
        /// @brief N 頂点のフロー場を生成する
        /// @param N 位数
        Max_Flow(int N = 0) {
            adj_out.resize(N);
            level.resize(N);
            iter.resize(N);
        }

        /// @brief 確保した弧 (順辺と逆辺) を解放する
        ~Max_Flow() {
            for (Arc<Cap>* arc : arcs) {
                if (arc->rev) { delete arc->rev; }
                delete arc;
            }
        }

        /// @brief フロー場の位数を返す
        /// @return 位数
        inline int order() const { return adj_out.size(); }

        /// @brief フロー場のサイズを求める
        /// @return サイズ
        inline int size() const { return arcs.size(); }

        /// @brief 頂点 u から頂点 v への容量 cap の弧を追加する
        /// @param u 始点
        /// @param v 終点
        /// @param cap 容量
        /// @return 追加した弧の id
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

        /// @brief 1 頂点を追加する.
        /// @return 追加した頂点の番号
        int add_vertex() {
            adj_out.emplace_back();
            level.emplace_back(-1);
            iter.emplace_back(0);

            return order() - 1;
        }

        /// @brief source から target への最大流の大きさを求める
        /// @param source 始点
        /// @param target 終点
        /// @return 最大流の大きさ
        Cap max_flow(const V source, const V target) {
            Cap flow = 0;
            while (bfs(source, target)) {
                iter.assign(order(), 0);
                Cap f;
                while ((f = dfs(source, target, Cap(0), true)) > 0) {
                    flow += f;
                }
            }

            return flow;
        }

        /// @brief source から target への高々 flow_limit までの最大流の大きさを求める
        /// @param source 始点
        /// @param target 終点
        /// @param flow_limit 流す容量の上限
        /// @return 最大流の大きさ
        Cap max_flow(const V source, const V target, Cap flow_limit) {
            Cap flow = 0;
            while (flow < flow_limit && bfs(source, target)) {
                iter.assign(order(), 0);
                Cap f;
                while (flow < flow_limit && (f = dfs(source, target, flow_limit - flow, false)) > 0) {
                    flow += f;
                }
            }

            return flow;
        }

        /// @brief max_flow で求めた流れを取得する.
        /// @return 第 u 要素は, u を始点とする各弧について (弧の id, 終点, 流量) を並べたもの
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

        /// @brief 最小カットを求める. max_flow(s, t) を呼んだ後に使うこと.
        /// @param s 始点
        /// @return 長さ N の配列 group. 残余グラフで s から到達可能な頂点 (s 側) が false, それ以外 (t 側) が true
        vector<bool> min_cut(const int s) {
            vector<bool> group(order(), true); group[s] = false;

            deque<V> Q{s};

            while (!Q.empty()) {
                V x = Q.front(); Q.pop_front();

                for (Arc<Cap>* arc: adj_out[x]) {
                    V y = arc->target;
                    unless(arc->is_flowable() && group[y]) { continue; }

                    group[y] = false;
                    Q.emplace_back(y);
                }
            }

            return group;
        }
    };
}
