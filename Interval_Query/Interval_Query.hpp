#pragma once

#include "Range_Decomposer.hpp"

/// @brief Range_Decomposer による区間分解を用いて, 一点更新・区間クエリを行う汎用クラス.
/// @tparam T 要素の型.
/// @tparam State 各ノードが持つ内部状態の型 (例: map, 集計値など).
template <typename T, typename State>
class Interval_Query {
    private:
    int n;
    vector<T> data;
    unique_ptr<Range_Decomposer> decomposer;

    vector<State> state;

    function<State(const vector<T> &)> build_state;
    function<State(vector<State> &)> merge_children;
    function<void(State &, int, const T &, const T &)> on_update;

    /// @brief ノード (depth, start, end) の状態を, 子ノードから再帰的に構築する.
    State build(int depth, int l, int r) {
        auto ch = decomposer->children(depth, l);

        State s;
        if (ch.empty()) {
            vector<T> sub(data.begin() + l, data.begin() + r);
            s = build_state(sub);
        } else {
            vector<State> child_states;
            child_states.reserve(ch.size());
            for (auto [cd, cl, cr] : ch) { child_states.push_back(build(cd, cl, cr)); }
            s = merge_children(child_states);
        }

        state[decomposer->node_index(depth, l)] = s;
        return s;
    }

    public:
    /// @brief コンストラクタ.
    /// @param data 初期値.
    /// @param decomposer 区間分解を担当するオブジェクト.
    /// @param build_state 葉ノード (子を持たないノード) の状態を, 担当する要素列から作る関数.
    /// @param merge_children 子ノードの状態のリストから, 親ノードの状態を作る関数.
    /// @param on_update 要素 i が before から after に変化したときに, ノードの状態を更新する関数.
    Interval_Query(
        const vector<T> &data,
        unique_ptr<Range_Decomposer> decomposer,
        function<State(const vector<T> &)> build_state,
        function<State(vector<State> &)> merge_children,
        function<void(State &, int, const T &, const T &)> on_update
    ):
        n(data.size()), data(data), decomposer(move(decomposer)),
        state(this->decomposer->node_count()),
        build_state(move(build_state)), merge_children(move(merge_children)), on_update(move(on_update)) {
        for (auto [depth, l, r] : this->decomposer->all_nodes()) {
            if (depth == 0) { build(depth, l, r); }
        }
    }

    /// @brief 要素数を返す.
    int size() const { return n; }

    /// @brief i 番目の要素を取得する.
    const T &get(int i) const { return data[i]; }

    /// @brief 第 i 要素を x に更新する.
    /// @param i 更新場所.
    /// @param x 更新後の要素.
    void update(int i, const T &x) {
        const T before = data[i];

        for (auto [depth, l, r] : decomposer->ancestors(i)) { on_update(state[decomposer->node_index(depth, l)], i, before, x); }

        data[i] = x;
    }

    /// @brief 半開区間 [l, r) におけるクエリの結果を求める.
    /// @tparam R クエリの返り値の型.
    /// @param l 区間の左端.
    /// @param r 区間の右端.
    /// @param representative ノードの状態から, クエリの結果 R を取り出す関数.
    /// @param merge 複数のノードの結果 R を集約する関数.
    /// @param identity merge に対する単位元.
    template <typename R>
    R query(
        int l, int r,
        function<R(const State &)> representative,
        function<R(R, R)> merge,
        R identity
    ) const {
        R res = identity;
        for (auto [depth, lo, hi] : decomposer->decompose(l, r)) { res = merge(res, representative(state[decomposer->node_index(depth, lo)])); }
        return res;
    }
};
