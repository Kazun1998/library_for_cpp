#pragma once

#include "../Lazy_Segment_Tree.hpp"

/**
 * @brief 区間アフィン変換・区間和取得を行う遅延セグメント木
 * @tparam T 値の型
 * @note 作用素 (a, b) は x |-> a + bx を表します。
 */
template<typename T>
class Range_Composite_Range_Sum_Lazy_Segment_Tree : public Lazy_Segment_Tree<pair<T, int>, pair<T, T>> {
    using M = pair<T, int>;
    using F = pair<T, T>;

    static M op(M x, M y) { return { x.first + y.first, x.second + y.second }; }
    static M act(F f, M x) { return { f.first * T(x.second) + f.second * x.first, x.second }; }
    static F comp(F f, F g) { return { f.first + f.second * g.first, f.second * g.second }; }

    static vector<M> convert(const vector<T> &vec) {
        vector<M> res(vec.size());
        for (int i = 0; i < (int)vec.size(); ++i) {
            res[i] = {vec[i], 1};
        }
        return res;
    }

    public:
    /**
     * @brief コンストラクタ
     * @param n 要素数
     * @note 初期値は全て 0 になる
     */
    Range_Composite_Range_Sum_Lazy_Segment_Tree(int n) : Lazy_Segment_Tree<M, F>(
        vector<M>(n, {0, 1}), op, {0, 0}, act, comp, {0, 1}
    ) {}

    /**
     * @brief コンストラクタ
     * @param vec 初期値の配列
     */
    Range_Composite_Range_Sum_Lazy_Segment_Tree(const vector<T> &vec) : Lazy_Segment_Tree<M, F>(
        convert(vec), op, {0, 0}, act, comp, {0, 1}
    ) {}

    /**
     * @brief 一点更新
     * @param k インデックス
     * @param x 更新する値
     */
    void update(int k, T x) { Lazy_Segment_Tree<M, F>::update(k, {x, 1}); }

    /**
     * @brief 一点取得
     * @param k インデックス
     * @return T 値
     */
    T operator[](int k) { return Lazy_Segment_Tree<M, F>::operator[](k).first; }

    /**
     * @brief 区間アフィン変換
     * @param l 区間の左端
     * @param r 区間の右端
     * @param a 足される数
     * @param b 以前の値に掛ける数
     * @note 区間 [l, r) の値 x に対して, x <- a + b * x を適用します。
     */
    void composite(int l, int r, T a, T b) { this->action(l, r, {a, b}); }

    /**
     * @brief 区間和取得
     * @param l 区間の左端
     * @param r 区間の右端
     * @return T 区間和
     */
    T sum(int l, int r) { return this->product(l, r).first; }
};
