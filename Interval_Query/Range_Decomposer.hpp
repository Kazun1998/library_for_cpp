#pragma once

#include "../template/template.hpp"

/// @brief 区間 [0, N) に対するクエリ区間分解の抽象基底クラス.
class Range_Decomposer {
    protected:
    int n;

    public:
    /// @brief コンストラクタ.
    /// @param n 全体の要素数.
    explicit Range_Decomposer(int n): n(n) {}

    virtual ~Range_Decomposer() = default;

    /// @brief 全体の要素数を返す.
    int size() const { return n; }

    /// @brief 半開区間 [l, r) を計算に必要な部分区間へ分解する.
    /// @param l 区間の左端.
    /// @param r 区間の右端.
    /// @return (depth, start, end) のリスト. depth の意味は派生クラスに依存する.
    virtual vector<tuple<int, int, int>> decompose(int l, int r) const = 0;

    /// @brief 構造全体に存在する全ノードを列挙する.
    /// @return (depth, start, end) のリスト.
    virtual vector<tuple<int, int, int>> all_nodes() const = 0;

    /// @brief 要素 i を含む全てのノードを列挙する.
    /// @param i 要素の位置.
    /// @return (depth, start, end) のリスト.
    virtual vector<tuple<int, int, int>> ancestors(int i) const = 0;
};
