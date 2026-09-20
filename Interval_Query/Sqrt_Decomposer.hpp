#pragma once

#include "Interval_Decomposer.hpp"

/// @brief 平方分割による区間分解. ブロック全体を depth=0, 端の単独要素を depth=1 として列挙する.
class Sqrt_Decomposer : public Interval_Decomposer {
    private:
    int block_size;

    /// @brief ブロック b が担当する区間 [l, r) を求める.
    pair<int, int> block_range(int b) const {
        int l = b * block_size;
        int r = min(n, l + block_size);
        return {l, r};
    }

    public:
    /// @brief コンストラクタ.
    /// @param n 全体の要素数.
    explicit Sqrt_Decomposer(int n): Interval_Decomposer(n), block_size(max<int>(1, isqrt(n))) {}

    /// @brief 半開区間 [l, r) を計算に必要な部分区間へ分解する.
    /// @param l 区間の左端.
    /// @param r 区間の右端.
    /// @return (depth, start, end) のリスト. ブロック全体は depth=0, 端の単独要素は depth=1.
    vector<tuple<int, int, int>> decompose(int l, int r) const override {
        vector<tuple<int, int, int>> res;
        if (l >= r) { return res; }

        int bl = l / block_size;
        int br = (r - 1) / block_size;

        if (bl == br) {
            for (int i = l; i < r; i++) { res.emplace_back(1, i, i + 1); }
            return res;
        }

        auto [bl_start, bl_end] = block_range(bl);
        for (int i = l; i < bl_end; i++) { res.emplace_back(1, i, i + 1); }

        for (int b = bl + 1; b < br; b++) {
            auto [bs, be] = block_range(b);
            res.emplace_back(0, bs, be);
        }

        auto [br_start, br_end] = block_range(br);
        for (int i = br_start; i < r; i++) { res.emplace_back(1, i, i + 1); }

        return res;
    }

    /// @brief 構造全体に存在する全ノード (各ブロックと各単独要素) を列挙する.
    vector<tuple<int, int, int>> all_nodes() const override {
        vector<tuple<int, int, int>> res;

        int block_count = (n + block_size - 1) / block_size;
        for (int b = 0; b < block_count; b++) {
            auto [bs, be] = block_range(b);
            res.emplace_back(0, bs, be);
        }

        for (int i = 0; i < n; i++) { res.emplace_back(1, i, i + 1); }

        return res;
    }

    /// @brief 要素 i を含む全てのノード (単独要素とその属するブロック) を列挙する.
    vector<tuple<int, int, int>> ancestors(int i) const override {
        auto [bs, be] = block_range(i / block_size);
        return {{1, i, i + 1}, {0, bs, be}};
    }

    /// @brief ノードの総数 (ブロック数 + 単独要素数) を返す.
    int node_count() const override {
        int block_count = (n + block_size - 1) / block_size;
        return block_count + n;
    }

    /// @brief ノード (depth, start) を一意な添字に変換する.
    /// depth=0 (ブロック) は [0, block_count), depth=1 (単独要素) は [block_count, block_count + n) に割り当てる.
    int node_index(int depth, int start) const override {
        int block_count = (n + block_size - 1) / block_size;
        return (depth == 0) ? (start / block_size) : (block_count + start);
    }

    /// @brief ノード (depth, start) の子ノードを列挙する. ブロックの子は各単独要素, 単独要素は葉 (子なし).
    vector<tuple<int, int, int>> children(int depth, int start) const override {
        vector<tuple<int, int, int>> res;
        if (depth != 0) { return res; }

        auto [bs, be] = block_range(start / block_size);
        for (int i = bs; i < be; i++) { res.emplace_back(1, i, i + 1); }
        return res;
    }
};
