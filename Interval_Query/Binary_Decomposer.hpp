#pragma once

#include "Interval_Decomposer.hpp"

/// @brief セグメント木型 (二分木) による区間分解. 根 [0, n) を depth=0 とし, mid = l + (r-l)/2 で再帰的に二分する.
class Binary_Decomposer : public Interval_Decomposer {
    private:
    vector<tuple<int, int, int>> nodes;
    unordered_map<long long, int> index_map;

    static long long key(int depth, int start) { return (static_cast<long long>(depth) << 32) | static_cast<unsigned int>(start); }

    /// @brief ノード [l, r) (深さ depth) を登録し, 子ノードを再帰的に構築する.
    void build(int l, int r, int depth) {
        index_map[key(depth, l)] = static_cast<int>(nodes.size());
        nodes.emplace_back(depth, l, r);

        if (r - l > 1) {
            int mid = l + (r - l) / 2;
            build(l, mid, depth + 1);
            build(mid, r, depth + 1);
        }
    }

    /// @brief 半開区間 [l, r) を, ノード [nl, nr) (深さ depth) 以下の部分木で分解する.
    void decompose_rec(int l, int r, int nl, int nr, int depth, vector<tuple<int, int, int>> &res) const {
        if (r <= nl || nr <= l) { return; }
        if (l <= nl && nr <= r) {
            res.emplace_back(depth, nl, nr);
            return;
        }

        int mid = nl + (nr - nl) / 2;
        decompose_rec(l, r, nl, mid, depth + 1, res);
        decompose_rec(l, r, mid, nr, depth + 1, res);
    }

    public:
    /// @brief コンストラクタ.
    /// @param n 全体の要素数.
    explicit Binary_Decomposer(int n): Interval_Decomposer(n) {
        if (n > 0) { build(0, n, 0); }
    }

    /// @brief 半開区間 [l, r) を計算に必要な部分区間へ分解する.
    /// @param l 区間の左端.
    /// @param r 区間の右端.
    /// @return (depth, start, end) のリスト.
    vector<tuple<int, int, int>> decompose(int l, int r) const override {
        vector<tuple<int, int, int>> res;
        if (l >= r) { return res; }

        decompose_rec(l, r, 0, n, 0, res);
        return res;
    }

    /// @brief 構造全体に存在する全ノードを列挙する.
    vector<tuple<int, int, int>> all_nodes() const override { return nodes; }

    /// @brief 要素 i を含む全てのノード (根から葉までの経路) を列挙する.
    vector<tuple<int, int, int>> ancestors(int i) const override {
        vector<tuple<int, int, int>> res;

        int l = 0, r = n, depth = 0;
        while (true) {
            res.emplace_back(depth, l, r);
            if (r - l <= 1) { break; }

            int mid = l + (r - l) / 2;
            if (i < mid) { r = mid; } else { l = mid; }
            depth++;
        }

        return res;
    }

    /// @brief ノードの総数を返す.
    int node_count() const override { return static_cast<int>(nodes.size()); }

    /// @brief ノード (depth, start) を一意な添字に変換する.
    int node_index(int depth, int start) const override { return index_map.at(key(depth, start)); }

    /// @brief ノード (depth, start) の子ノードを列挙する. 葉 (要素数1) の場合は空を返す.
    vector<tuple<int, int, int>> children(int depth, int start) const override {
        vector<tuple<int, int, int>> res;

        auto [d, l, r] = nodes[node_index(depth, start)];
        if (r - l <= 1) { return res; }

        int mid = l + (r - l) / 2;
        res.emplace_back(depth + 1, l, mid);
        res.emplace_back(depth + 1, mid, r);
        return res;
    }
};
