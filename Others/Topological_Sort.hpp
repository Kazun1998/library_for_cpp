#pragma once

// Source: https://github.com/Kazun1998/library_for_cpp/blob/main/Others/Topological_Sort.hpp

#include "../template/template.hpp"

/**
 * @brief トポロジカルソートを行うクラス
 */
class Topological_Sort {
    vector<vector<int>> arcs;
    bool ignore_self_loop;
    bool _is_DAG;

    public:
    /**
     * @brief コンストラクタ
     * @param n 頂点数
     * @param ignore_self_loop 自己ループを無視するかどうか (false の場合, 自己ループは閉路として扱われる)
     */
    Topological_Sort(int n, bool ignore_self_loop = true): arcs(n), ignore_self_loop(ignore_self_loop), _is_DAG(false) {}

    /**
     * @brief 有向辺を追加する
     * @param source 始点
     * @param target 終点
     */
    void add_arc(const int source, const int target) {
        if (source == target && ignore_self_loop) return;

        arcs[source].emplace_back(target);
    }

    /**
     * @brief 指定された始点群からの辺と、指定された終点群への辺を持つ新しい頂点を追加する
     * @param sources 新しい頂点への始点のリスト
     * @param targets 新しい頂点からの終点のリスト
     * @return int 追加された頂点のインデックス
     */
    int add_arc_multiple(const vector<int> &sources, const vector<int> &targets) {
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
        vector<int> in_degree(n, 0);
        for (const auto &targets: arcs) {
            for (const int y: targets) ++in_degree[y];
        }

        vector<int> order;
        order.reserve(n);
        for (int x = 0; x < n; ++x) {
            if (in_degree[x] == 0) order.push_back(x);
        }

        // order[i] を取り除いたとき, 新たに入次数が 0 になる頂点は order[i] の出近傍のみ
        for (int i = 0; i < (int)order.size(); ++i) {
            for (const int y: arcs[order[i]]) {
                if (--in_degree[y] == 0) order.push_back(y);
            }
        }

        if ((int)order.size() < n) return nullopt;
        return order;
    }

    /**
     * @brief グラフがDAG (有向非巡回グラフ) かどうかを判定する
     * @return true DAGである
     * @return false DAGでない (閉路が存在する)
     */
    bool is_DAG() const { return sort() != nullopt; }
};
