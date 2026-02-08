#pragma once

#include "../template/template.hpp"

/**
 * @brief トポロジカルソートを行うクラス
 */
class Topological_Sort {
    vector<vector<int>> arcs;
    bool self_loop;
    bool _is_DAG;

    public:
    /**
     * @brief コンストラクタ
     * @param n 頂点数
     * @param self_loop 自己ループを許容するかどうか
     */
    Topological_Sort(int n, bool self_loop = false): arcs(n), self_loop(self_loop), _is_DAG(false) {}

    /**
     * @brief 有向辺を追加する
     * @param source 始点
     * @param target 終点
     */
    void add_arc(const int source, const int target) {
        if (source == target && !self_loop) return;

        arcs[source].emplace_back(target);
    }

    /**
     * @brief 指定された始点群からの辺と、指定された終点群への辺を持つ新しい頂点を追加する
     * @param sources 新しい頂点への始点のリスト
     * @param targets 新しい頂点からの終点のリスト
     * @return int 追加された頂点のインデックス
     */
    int add_arc_multiple(const vector<int> sources, const vector<int> targets) {
        const int x = add_vertex();

        for (const int s: sources) add_arc(s, x);
        for (const int t: targets) add_arc(x, t);

        return x;
    }

    /**
     * @brief 頂点を追加する
     * @return int 追加された頂点のインデックス
     */
    int add_vertex() {
        arcs.emplace_back(vector<int>{});

        return arcs.size() - 1;
    }

    /**
     * @brief トポロジカルソートを実行する
     * @return optional<vector<int>> ソートされた頂点のリスト。閉路が存在する場合は nullopt
     */
    optional<vector<int>> sort() const {
        const int n = arcs.size();
        vector<bool> marked(n, false), use(n, false);
        vector<int> order;

        auto visit = [&](auto func, const int x) -> bool {
            if (use[x]) return false;
            if (marked[x]) return true;

            use[x] = true;
            for (const int &y : arcs[x]) {
                if (!func(func, y)) return false;
            }

            marked[x] = true;
            order.push_back(x);
            use[x] = false;
            return true;
        };

        for (int x = 0; x < n; ++x) {
            if (!visit(visit, x)) return nullopt;
        }

        reverse(order.begin(), order.end());
        return order;
    }

    /**
     * @brief グラフがDAG (有向非巡回グラフ) かどうかを判定する
     * @return true DAGである
     * @return false DAGでない (閉路が存在する)
     */
    bool is_DAG() const { return sort() != nullopt; }
};